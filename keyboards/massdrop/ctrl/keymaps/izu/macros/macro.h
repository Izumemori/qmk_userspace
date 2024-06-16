#ifndef H_MACRO
#define H_MACRO

#include <stdint.h>
#include "action.h"
#include "../rgb/key_info.h"

struct Macro {
    uint16_t keycode;
    const KeyInfo* key_info;
    bool (*action)(uint16_t keycode, keyrecord_t *record);
} typedef Macro;

#endif
