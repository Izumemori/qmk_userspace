#include "rgb_matrix_mode_macro.h"
#include "rgb_matrix.h"

const KeyInfo m_rgb_matrix_mode_key_info = RGB_KEYINFO(255, 204, 63);
uint8_t m_rgb_matrix_mode;

bool rgb_matrix_mode_macro_action(uint16_t keycode, keyrecord_t *record){
    rgb_matrix_mode(m_rgb_matrix_mode);

    return true;
}

Macro create_rgb_matrix_mode_macro(uint16_t keycode, uint8_t mode) {
    m_rgb_matrix_mode = mode;

    Macro m;
    m.key_info = &m_rgb_matrix_mode_key_info;
    m.keycode = keycode;
    m.action = &rgb_matrix_mode_macro_action;

    return m;
}
