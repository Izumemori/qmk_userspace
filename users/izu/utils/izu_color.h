#ifndef H_COLOR
#define H_COLOR

#include <stdint.h>
#include <stdlib.h>
#include <sys/_intsup.h>

struct IzuColor {
    uint8_t r;
    uint8_t g;
    uint8_t b;
    int8_t take_from_layer;
} typedef IzuColor;

IzuColor color_from_rgb(uint8_t r, uint8_t g, uint8_t b);

IzuColor color_from_hex(const char* hex);

#endif
