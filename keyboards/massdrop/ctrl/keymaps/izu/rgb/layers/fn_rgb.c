#include "fn_rgb.h"

#include "rgb/key_info.h"

const KeyInfo black_key_info = RGB_KEYINFO(0, 0, 0);
const KeyInfo active_key_info = RGB_KEYINFO(0, 255, 0);
const KeyInfo inactive_key_info = RGB_KEYINFO(255, 0, 0);
const KeyInfo transparent_0_key_info = TRANSPARENT_KEYINFO(0);

keymap_config_t* keymap_conf;

const KeyInfo* get_key_info_fn(uint16_t keycode) {
    switch (keycode) {
        case _______:
            return &black_key_info;
        case NK_TOGG:
            if (keymap_conf->nkro) return &active_key_info;
            else return &inactive_key_info;
    }

    return &transparent_0_key_info;
}

RGBLayer create_fn_rgb_layer(keymap_config_t* keymap_config) {
    keymap_conf = keymap_config;

    RGBLayer layer;
    layer.get_key_info = get_key_info_fn;

    return layer;
}
