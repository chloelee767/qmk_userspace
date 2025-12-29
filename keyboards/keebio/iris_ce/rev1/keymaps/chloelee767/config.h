#pragma once

#define TAPPING_TERM 150
#define PERMISSIVE_HOLD
#define CHORDAL_HOLD
#define FLOW_TAP_TERM 50

#define COMBO_ONLY_FROM_LAYER 0 // the combos' keys are always checked from layer 0, even if other layers are active.
#define COMBO_TERM 30
#define COMBO_STRICT_TIMER
#define COMBO_MUST_HOLD_PER_COMBO
#define COMBO_HOLD_TERM 30

// setting default to 0,0,0 meaning no LED
#define RGB_MATRIX_DEFAULT_MODE RGB_MATRIX_SOLID_COLOR
#define RGB_MATRIX_DEFAULT_HUE 0
#define RGB_MATRIX_DEFAULT_SAT 0
#define RGB_MATRIX_DEFAULT_VAL 0

// make sure RGB changes on both halves
// https://docs.qmk.fm/features/rgb_matrix#indicator-examples-2
// https://docs.qmk.fm/features/split_keyboard#data-sync-options
#define SPLIT_LAYER_STATE_ENABLE
