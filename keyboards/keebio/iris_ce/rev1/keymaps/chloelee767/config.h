#pragma once

#define TAPPING_TERM 150
#define PERMISSIVE_HOLD
#define COMBO_ONLY_FROM_LAYER 0
#define COMBO_TERM 25

// default is no led
#define RGB_MATRIX_DEFAULT_MODE RGB_MATRIX_SOLID_COLOR
#define RGB_MATRIX_DEFAULT_HUE 0
#define RGB_MATRIX_DEFAULT_SAT 0
#define RGB_MATRIX_DEFAULT_VAL 0

// make sure RGB changes on both halves
// https://docs.qmk.fm/features/rgb_matrix#indicator-examples-2
// https://docs.qmk.fm/features/split_keyboard#data-sync-options
#define SPLIT_LAYER_STATE_ENABLE
