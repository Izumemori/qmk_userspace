#include "quantum.h"

#include "sussy_macro.h"

#include "rgb/key_info.h"

const KeyInfo sussy_key_info = RGB_KEYINFO(0xD7, 0x1E, 0x22);

bool sussy_macro_action(uint16_t keycode, keyrecord_t *record) {
    char* sussy_string = "Now let's say hypothetically I was the impostor. How would I get from reactor to medbay in that timespan, from which we saw each other, till you found yellow dead. Also if I were the impostor hypothetically speaking, how would I have finished all my tasks.";

    SEND_STRING(sussy_string);

    return true;
}

Macro create_sussy_macro(uint16_t keycode)  {
    Macro m;
    m.key_info = &sussy_key_info;
    m.keycode = keycode;
    m.action = &sussy_macro_action;

    return m;
}
