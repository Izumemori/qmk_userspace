#include "config.h"
#include "rgb_matrix.h"
#include "util.h"

#include "../key_info.h"

#include "../layers/constellation_keycaps_rgb.h"
#include "../layers/fn_rgb.h"
#include "../layers/macro_rgb.h"

static RGBLayer rgb_layers[3];

static void constellation_effect_init(effect_params_t* params) {
    rgb_layers[0] = create_constellation_rgb_layer();
    rgb_layers[1] = create_fn_rgb_layer(g_keymap_config);
    rgb_layers[2] = create_macro_rgb_layer(g_macros);
}

static bool constellation_effect_run(effect_params_t *params) {
    RGB_MATRIX_USE_LIMITS(led_min, led_max);
    uint8_t layer = biton16(*g_layer_state);

    double brightness = rgb_matrix_get_val()/255.0;

    if (layer > ARRAY_SIZE(rgb_layers)-1) return true;

    for (int i = 0; i < MATRIX_ROWS; i++)
        for (int j = 0; j < MATRIX_COLS; j++) {
            uint16_t led = g_led_config.matrix_co[i][j];
            if (led < led_min || led >= led_max || led == NO_LED) continue;

            uint16_t key = g_keymaps[layer][i][j];
            const KeyInfo* key_info = rgb_layers[layer].get_key_info(key);

            if (!key_info) continue;

            if (key_info->is_transparent) {
                key = g_keymaps[key_info->color_layer][i][j];
                key_info = rgb_layers[key_info->color_layer].get_key_info(key);
            }

            if (!key_info) continue;

            rgb_matrix_set_color(led,
                                 key_info->key_color.r * brightness,
                                 key_info->key_color.g * brightness,
                                 key_info->key_color.b * brightness);
        }

    return rgb_matrix_check_finished_leds(led_max);
}

static bool constellation_effect(effect_params_t* params) {
    if (params->init) constellation_effect_init(params);
    return constellation_effect_run(params);
}
