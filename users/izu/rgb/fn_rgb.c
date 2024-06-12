#include "fn_rgb.h"
#include <stdint.h>
#include "keycode_config.h"
#include "keycodes.h"

const IzuColor black = {.r = 0, .g = 0, .b = 0, .take_from_layer = -1};
const IzuColor active = {.r = 0, .g = 255, .b = 0, .take_from_layer = -1};
const IzuColor inactive = {.r = 255, .g = 0, .b = 0, .take_from_layer = -1};
const IzuColor take_from_layer_0 = {.r = 0, .g = 0, .b = 0, .take_from_layer = 0};
keymap_config_t* keymap_conf;

const IzuColor* get_rgb_for_key_fn(uint16_t keycode) {
    switch (keycode) {
        case _______:
            return &black;
        case NK_TOGG:
            if (keymap_conf->nkro) return &active;
            else return &inactive;
    }

    return &take_from_layer_0;
}

RGBLayer create_fn_rgb_layer(keymap_config_t* keymap_config) {
    keymap_conf = keymap_config;

    RGBLayer layer;
    layer.get_rgb_for_key = get_rgb_for_key_fn;

    return layer;
}
