#include "macro_rgb.h"
#include "keycodes.h"

const IzuColor macro_default_color = {.r = 0, .g = 0, .b = 0, .take_from_layer = -1};

Macro* macros;
size_t macros_length;

const IzuColor* get_rgb_for_key_macro(uint16_t keycode) {
    if (keycode == _______) return &macro_default_color;

    for (int i = 0; i < macros_length; i++) {
        if (macros[i].keycode == keycode) return &macros[i].color;
    }

    return NULL;
}

RGBLayer create_macro_rgb_layer(Macro* macros, size_t macros_length) {
    macros = macros;
    macros_length = macros_length;

    RGBLayer layer;
    layer.get_rgb_for_key = &get_rgb_for_key_macro;

    return layer;
}
