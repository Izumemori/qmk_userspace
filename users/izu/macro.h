#ifndef H_MACRO
#define H_MACRO

#include <stdint.h>
#include "action.h"
#include "utils/izu_color.h"

struct Macro {
    uint16_t keycode;
    IzuColor color;
    bool (*action)(uint16_t keycode, keyrecord_t *record);
} typedef Macro;

#endif
