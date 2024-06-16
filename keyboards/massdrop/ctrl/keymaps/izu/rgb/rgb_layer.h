#ifndef RGB_LAYER_H
#define RGB_LAYER_H

#include "key_info.h"

typedef struct {
    const KeyInfo* (*get_key_info)(uint16_t keycode);
} RGBLayer;

#endif
