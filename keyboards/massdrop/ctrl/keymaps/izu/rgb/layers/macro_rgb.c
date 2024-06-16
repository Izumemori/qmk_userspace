#include "keycodes.h"

#include "macro_rgb.h"

#include "../../rgb/key_info.h"
#include "print.h"
#include "util.h"

const KeyInfo macro_default_color = RGB_KEYINFO(0, 0, 0);

Macro* m_macros;

const KeyInfo* get_key_info_macro(uint16_t keycode) {
    if (keycode == _______) return &macro_default_color;

    for (int i = 0; m_macros[i].key_info; i++) {
        if (m_macros[i].keycode == keycode) return m_macros[i].key_info;
    }

    return &macro_default_color;
}

RGBLayer create_macro_rgb_layer(Macro* macros) {
    m_macros = macros;

    RGBLayer layer;
    layer.get_key_info = &get_key_info_macro;

    return layer;
}
