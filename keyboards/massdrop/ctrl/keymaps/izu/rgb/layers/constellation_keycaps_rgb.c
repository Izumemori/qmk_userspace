#include "util.h"
#include "stddef.h"

#include "constellation_keycaps_rgb.h"

#include "rgb/key_info.h"

const uint16_t white_keys[49]  = {KC_ESC, KC_GRV, KC_1, KC_2, KC_3, KC_4, KC_5, KC_6, KC_7, KC_8, KC_9, KC_0, KC_MINS, KC_EQL, KC_Q, KC_W, KC_E, KC_R, KC_T, KC_Y, KC_U, KC_I, KC_O, KC_P, KC_LBRC, KC_RBRC, KC_BSLS, KC_A, KC_S, KC_D, KC_F, KC_G, KC_H, KC_J, KC_K, KC_L, KC_SCLN, KC_QUOT, KC_Z, KC_X, KC_C, KC_V, KC_B, KC_N, KC_M, KC_COMM, KC_DOT, KC_SLSH, KC_SPC};
const uint16_t pink_keys[12]   = {KC_F5, KC_F6, KC_F7, KC_F8, KC_PSCR, KC_SCRL, KC_PAUS, KC_LGUI, KC_LALT, KC_RALT, MO(1), KC_APP};
const uint16_t purple_keys[19] = {KC_F1, KC_F2, KC_F3, KC_F4, KC_F9, KC_F10, KC_F11, KC_F12, KC_INS, KC_HOME, KC_PGUP, KC_TAB, KC_DEL, KC_END, KC_PGDN, MO(2), KC_ENT, KC_LSFT, KC_RSFT};
const uint16_t yellow_keys[7]  = {KC_BSPC, KC_LCTL, KC_RCTL, KC_UP, KC_DOWN, KC_LEFT, KC_RIGHT};

const KeyInfo white_key_info  = RGB_KEYINFO(255, 249, 229);
const KeyInfo pink_key_info   = RGB_KEYINFO(255, 99, 117);
const KeyInfo purple_key_info = RGB_KEYINFO(163, 79, 255);
const KeyInfo yellow_key_info = RGB_KEYINFO(255, 204, 63);

bool array_contains(uint16_t key, const uint16_t* arr, size_t arr_size) {
    for (int i = 0; i < arr_size; i++) {
        if (arr[i] == key) return true;
    }

    return false;
}

const KeyInfo* get_key_info_constellation(uint16_t keycode) {
    if (array_contains(keycode, white_keys, ARRAY_SIZE(white_keys))) {
        return &white_key_info;
    }

    if (array_contains(keycode, pink_keys, ARRAY_SIZE(pink_keys))) {
        return &pink_key_info;
    }

    if (array_contains(keycode, purple_keys, ARRAY_SIZE(purple_keys))) {
        return &purple_key_info;
    }

    if (array_contains(keycode, yellow_keys, ARRAY_SIZE(yellow_keys))) {
        return &yellow_key_info;
    }

    return NULL;
}

RGBLayer create_constellation_rgb_layer(void) {
    RGBLayer layer;
    layer.get_key_info = &get_key_info_constellation;

    return layer;
}
