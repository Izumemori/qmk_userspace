#include "izu_color.h"

IzuColor color_from_rgb(uint8_t r, uint8_t g, uint8_t b) {
    IzuColor c;
    c.r = r;
    c.g = g;
    c.b = b;
    c.take_from_layer = -1;
    return c;
}

IzuColor color_from_hex(const char* hex) {
    uint32_t iColor = (int)strtol(hex, NULL, 16);
    return color_from_rgb((iColor >> 16) & 0xff, (iColor >> 8) & 0xff, iColor & 0xff);
}
