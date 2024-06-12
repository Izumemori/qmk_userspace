#include "sussy_macro.h"
#include <stdint.h>
#include "../macro.h"
#include "quantum.h"
#include "../utils/izu_color.h"

bool sussy_macro_action(uint16_t keycode, keyrecord_t *record) {
    char* sussy_string = "Now let's say hypothetically I was the impostor. How would I get from reactor to medbay in that timespan, from which we saw each other, till you found yellow dead. Also if I were the impostor hypothetically speaking, how would I have finished all my tasks.";

    SEND_STRING(sussy_string);

    return true;
}

Macro create_sussy_macro(uint16_t keycode)  {
    Macro m;
    m.color = color_from_hex("D71E22");
    m.keycode = keycode;
    m.action = &sussy_macro_action;

    return m;
}
