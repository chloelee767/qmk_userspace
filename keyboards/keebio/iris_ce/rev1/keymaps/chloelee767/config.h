#pragma once

#define TAPPING_TERM 200
#define PERMISSIVE_HOLD
#define COMBO_ONLY_FROM_LAYER 0

// step size 17 * 3 = 51
#define RGB_MATRIX_DEFAULT_VAL 51

// make sure RGB changes on both halves
// https://docs.qmk.fm/features/rgb_matrix#indicator-examples-2
// https://docs.qmk.fm/features/split_keyboard#data-sync-options
#define SPLIT_LAYER_STATE_ENABLE
