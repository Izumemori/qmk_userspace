#ifndef H_RGB_MODE
#define H_RGB_MODE

#include <stdint.h>
#include "utils/izu_color.h"

struct RGBLayer {
    const IzuColor* (*get_rgb_for_key)(uint16_t keycode);
} typedef RGBLayer;

#endif
