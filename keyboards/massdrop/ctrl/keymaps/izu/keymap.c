#include "keymap.h"
#include <stdint.h>
#include "action_layer.h"
#include "bitwise.h"
#include "rgb_matrix.h"
#include "util.h"

static void init_keycode_to_led_map(void) {
    uint16_t LED_MAP[MATRIX_ROWS][MATRIX_COLS] = LAYOUT(
            0,1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,
            20,21,22,23,24,25,26,27,28,29,30,31,32,33,34,35,
            36,37,38,39,40,41,42,43,44,45,46,47,48,49,50,51,
            52,53,54,55,56,57,58,59,60,61,62,63,64,65,66,67,
            68,69,70,71,72,73,74,75,76,77,78,79,80,81,82,83,84,85,86
    );

    uint16_t key = 0;
    for(uint8_t y = 0; y < MATRIX_ROWS; y++){
        for(uint8_t x = 0; x < MATRIX_COLS; x++){
            key = keymaps[0][y][x];
            if(key < 256){
                KEYCODE_TO_LED_ID[key] = LED_MAP[y][x];
            }
        }
    }
}

bool rgb_matrix_indicators_user(void) {
    if (!rgb_matrix_config.enable) return true;

    uint8_t layer = biton32(layer_state);

    if (layer > ARRAY_SIZE(rgb_layers)-1) return true;

    for (int i = 0; i < MATRIX_ROWS; i++)
        for (int j = 0; j < MATRIX_COLS; j++) {
            uint16_t key = keymaps[layer][i][j];
            uint16_t led = KEYCODE_TO_LED_ID[keymaps[0][i][j]];
            const IzuColor* color = rgb_layers[layer].get_rgb_for_key(key);

            if (!color) continue;

            if (color && color->take_from_layer >= 0) {
                key = keymaps[color->take_from_layer][i][j];
                color = rgb_layers[color->take_from_layer].get_rgb_for_key(key);
            }

            if (color) rgb_matrix_set_color(led, color->r, color->g, color->b);
        }

    return true;
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    static uint32_t key_timer;

    // Macros
    for (int i = 0; i < sizeof(macros)/ sizeof(Macro); i++) {
        if (macros[i].keycode != keycode) continue;

        macros[i].action(keycode, record);
    }

    switch (keycode) {
        case U_T_AUTO:
            if (record->event.pressed && MODS_SHIFT && MODS_CTRL) {
                TOGGLE_FLAG_AND_PRINT(usb_extra_manual, "USB extra port manual mode");
            }
            return false;
        case U_T_AGCR:
            if (record->event.pressed && MODS_SHIFT && MODS_CTRL) {
                TOGGLE_FLAG_AND_PRINT(usb_gcr_auto, "USB GCR auto mode");
            }
            return false;
        case DBG_TOG:
            if (record->event.pressed) {
                TOGGLE_FLAG_AND_PRINT(debug_enable, "Debug mode");
            }
            return false;
        case DBG_MTRX:
            if (record->event.pressed) {
                TOGGLE_FLAG_AND_PRINT(debug_matrix, "Debug matrix");
            }
            return false;
        case DBG_KBD:
            if (record->event.pressed) {
                TOGGLE_FLAG_AND_PRINT(debug_keyboard, "Debug keyboard");
            }
            return false;
        case DBG_MOU:
            if (record->event.pressed) {
                TOGGLE_FLAG_AND_PRINT(debug_mouse, "Debug mouse");
            }
            return false;
        case MD_BOOT:
            if (record->event.pressed) {
                key_timer = timer_read32();
            } else {
                if (timer_elapsed32(key_timer) >= 500) {
                    reset_keyboard();
                }
            }
            return false;
        case RGB_TOG:
            if (record->event.pressed) {
              switch (rgb_matrix_get_flags()) {
                case LED_FLAG_ALL: {
                    rgb_matrix_set_flags(LED_FLAG_KEYLIGHT | LED_FLAG_MODIFIER | LED_FLAG_INDICATOR);
                    rgb_matrix_set_color_all(0, 0, 0);
                  }
                  break;
                case (LED_FLAG_KEYLIGHT | LED_FLAG_MODIFIER | LED_FLAG_INDICATOR): {
                    rgb_matrix_set_flags(LED_FLAG_UNDERGLOW);
                    rgb_matrix_set_color_all(0, 0, 0);
                  }
                  break;
                case LED_FLAG_UNDERGLOW: {
                    rgb_matrix_set_flags(LED_FLAG_NONE);
                    rgb_matrix_disable_noeeprom();
                  }
                  break;
                default: {
                    rgb_matrix_set_flags(LED_FLAG_ALL);
                    rgb_matrix_enable_noeeprom();
                  }
                  break;
              }
            }
            return false;
        default:
            return true; //Process all other keycodes normally
    }
}
