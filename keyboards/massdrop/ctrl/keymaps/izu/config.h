#ifndef H_CONFIG
#define H_CONFIG

#include "quantum_keycodes.h"
#include "keycode_config.h"

#include "macros/macro.h"

enum ctrl_keycodes {
    U_T_AUTO = SAFE_RANGE, //USB Extra Port Toggle Auto Detect / Always Active
    U_T_AGCR,              //USB Toggle Automatic GCR control
    DBG_TOG,               //DEBUG Toggle On / Off
    DBG_MTRX,              //DEBUG Toggle Matrix Prints
    DBG_KBD,               //DEBUG Toggle Keyboard Prints
    DBG_MOU,               //DEBUG Toggle Mouse Prints
    MD_BOOT,               //Restart into bootloader after hold timeout

    MC_SUSSY,
    MC_MTRX_CONSTELLATION
};

// Globals for rgb
Macro g_macros[2];
uint16_t g_keymaps[3][MATRIX_ROWS][MATRIX_COLS];
keymap_config_t* g_keymap_config;
uint16_t* g_layer_state;
// ---------------

#endif
