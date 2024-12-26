// Adapted from https://github.com/Ga68/qmk_firmware/tree/my_layout/keyboards/sofle/keymaps/Ga68

#pragma once
#include QMK_KEYBOARD_H

typedef enum {
    CWMODE_NORMAL = 0,
    CWMODE_NUMBER
} caps_word_mode_t;

#define CAPS_WORD_MODE_DEFAULT CWMODE_NORMAL

caps_word_mode_t g_caps_word_mode;

bool toggle_caps_word_mode(caps_word_mode_t new_mode);

void cw_caps_word_set_user(bool active);
