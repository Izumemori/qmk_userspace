#ifndef KEY_INFO_H
#define KEY_INFO_H

#include "color.h"

typedef struct {
    const RGB key_color;
    uint8_t color_layer;
    bool is_transparent;
} KeyInfo;

#define TRANSPARENT_KEYINFO(layer) {.key_color = (RGB){0,0,0}, .color_layer = layer, .is_transparent = true}
#define RGB_KEYINFO(in_r,in_g,in_b) {.key_color = (RGB){.r = in_r,.g = in_g,.b = in_b}, .color_layer = 0, .is_transparent = false}

#endif
