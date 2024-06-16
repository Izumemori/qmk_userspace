#ifndef RGB_MATRIX_MODE_MACRO_H
#define RGB_MATRIX_MODE_MACRO_H

#include "macro.h"

bool rgb_matrix_mode_macro_action(uint16_t keycode, keyrecord_t *record);

Macro create_rgb_matrix_mode_macro(uint16_t keycode, uint8_t mode);

#endif
