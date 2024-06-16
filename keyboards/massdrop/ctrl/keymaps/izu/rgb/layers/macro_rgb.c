#include "keycodes.h"

#include "macro_rgb.h"

#include "../../rgb/key_info.h"

const KeyInfo macro_default_color = RGB_KEYINFO(0, 0, 0);

Macro* m_macros;
size_t macros_length;

const KeyInfo* get_key_info_macro(uint16_t keycode) {
    if (keycode == _______) return &macro_default_color;

    for (int i = 0; i < macros_length; i++) {
        if (m_macros[i].keycode == keycode) return m_macros[i].key_info;
    }

    return NULL;
}

RGBLayer create_macro_rgb_layer(Macro* macros, size_t macros_length) {
    m_macros = macros;
    macros_length = macros_length;

    RGBLayer layer;
    layer.get_key_info = &get_key_info_macro;

    return layer;
}
