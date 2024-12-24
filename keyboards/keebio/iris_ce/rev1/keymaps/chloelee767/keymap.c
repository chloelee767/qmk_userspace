// Copyright 2023 Danny Nguyen (@nooges)
// SPDX-License-Identifier: GPL-2.0-or-later

#include QMK_KEYBOARD_H
#include "features/achordion.h"

enum custom_layers {
_QWERTY,
_SYMBOL,
_NUMNAV,
_FNKEY,
_MULTIMEDIA,
_NUM,
_NAV
};

// TODO make sure to add QK_BOOT to both sides so that we can flash the keyboard!

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

  [_QWERTY] =
LAYOUT(
/* Number Row */
KC_MS_BTN2, KC_MS_BTN3, KC_MS_WH_UP, KC_MS_WH_DOWN, KC_MS_BTN1, KC_GRV,
KC_0, KC_LBRC, KC_RBRC, KC_BSLS, KC_MINS, KC_EQL,
/* Qwerty Row */
QK_CAPS_WORD_TOGGLE, LSFT_T(KC_Q), LT(_NAV,KC_W), LGUI_T(KC_E), KC_R, KC_T,
KC_Y, KC_U, LGUI_T(KC_I), LT(_NUM,KC_O), LSFT_T(KC_P), QK_CAPS_WORD_TOGGLE,
/* Home Row */
KC_ESC, LSFT_T(KC_A), LGUI_T(KC_S), LALT_T(KC_D), LCTL_T(KC_F), KC_G,
KC_H, LCTL_T(KC_J), LALT_T(KC_K), LGUI_T(KC_L), LSFT_T(KC_SCLN), KC_QUOT,
/* Zxc Row (Left) */
KC_LSFT, LT(_NAV,KC_Z), LT(_NAV,KC_X), LT(_NAV,KC_C), LT(_NAV,KC_V), KC_B,
/* Top Thumb Keys */
KC_NO, KC_NO,
/* Zxc Row (Right) */
KC_N, LT(_NUM,KC_M), LT(_NUM,KC_COMM), LT(_NUM,KC_DOT), LT(_NUM,KC_SLSH), KC_RSFT,
/* Bottom Row */
LT(_FNKEY,KC_DEL), LT(_SYMBOL,KC_BSPC), LT(_NUMNAV,KC_TAB),
LT(_SYMBOL,KC_ENT), LT(_NUMNAV,KC_SPC), LT(_FNKEY,KC_BSPC)
),

[_SYMBOL] =
LAYOUT(
/* Number Row */
KC_TRNS, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO,
KC_NO, KC_TRNS, KC_TRNS, KC_TRNS, KC_NO, KC_NO,
/* Qwerty Row */
KC_TRNS, KC_NO, KC_PPLS, KC_EQL, KC_NO, KC_GRV, /* Don't use KC_PEQL (numpad equal) for compatiblity with windows */
KC_CIRC, KC_AMPR, KC_ASTR, KC_PIPE, KC_BSLS, KC_NO,
/* Home Row */
KC_TRNS, KC_EXLM, KC_PERC, KC_MINS, KC_COLN, KC_TILD,
KC_DLR, KC_LPRN, KC_RPRN, KC_LCBR, KC_RCBR, KC_DQUO,
/* Zxc Row (Left) */
KC_TRNS, KC_AT, KC_HASH, KC_UNDS, KC_NO, KC_NO,
/* Top Thumb Keys */
KC_TRNS, KC_TRNS,
/* Zxc Row (Right) */
KC_BSLS, KC_EQL, KC_LT, KC_GT, KC_QUES, KC_QUOT,
/* Bottom Row */
KC_LCTL, KC_TRNS, KC_TRNS,
KC_TRNS, KC_TRNS, KC_TRNS
),

[_NUMNAV] =
LAYOUT(
/* Number Row */
KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO,
KC_NO, KC_TRNS, KC_TRNS, KC_TRNS, KC_NO, KC_NO,
/* Qwerty Row */
KC_PLUS, KC_MINS, KC_1, LGUI_T(KC_2), KC_3, KC_4,
KC_HOME, KC_PGUP, KC_UP, KC_PGDN, KC_NO, KC_NO,
/* Home Row */
KC_COMM, LSFT_T(KC_DOT), LGUI_T(KC_4), LALT_T(KC_5), LCTL_T(KC_6), KC_7,
KC_END, KC_LEFT, KC_DOWN, KC_RGHT, KC_LGUI, KC_NO,
/* Zxc Row (Left) */
KC_ASTR, KC_SLSH, KC_7, KC_8, KC_9, KC_BSLS,
/* Top Thumb Keys */
KC_TRNS, KC_TRNS,
/* Zxc Row (Right) */
KC_NO, KC_LCTL, KC_LALT, KC_LGUI, KC_LSFT, KC_NO,
/* Bottom Row */
KC_EQL, KC_0, KC_TRNS,
KC_TRNS, KC_TRNS, KC_TRNS
),

[_FNKEY] =
LAYOUT(
/* Number Row */
KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO,
KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO,
/* Qwerty Row */
KC_NO, KC_F1, KC_F2, KC_F3, KC_F4, KC_F5,
KC_NO, KC_NO, KC_LGUI, KC_NO, KC_NO, KC_NO,
/* Home Row */
KC_NO, KC_F6, KC_F7, KC_F8, KC_F9, KC_F10,
KC_NO, KC_LCTL, KC_LALT, KC_LGUI, KC_LSFT, KC_NO,
/* Zxc Row (Left) */
KC_NO, KC_F11, KC_F12, KC_NO, KC_NO, KC_NO,
/* Top Thumb Keys */
KC_TRNS, KC_TRNS,
/* Zxc Row (Right) */
KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO,
/* Bottom Row */
KC_TRNS, KC_TRNS, KC_TRNS,
KC_TRNS, KC_TRNS, KC_TRNS
),

[_MULTIMEDIA] =
LAYOUT(
/* Number Row */
KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO,
KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO,
/* Qwerty Row */
KC_NO, KC_NO, KC_MUTE, KC_VOLD, KC_VOLU, KC_NO,
KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO,
/* Home Row */
KC_NO, KC_NO, KC_MRWD, KC_MPLY, KC_MFFD, KC_NO,
KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO,
/* Zxc Row (Left) */
KC_NO, KC_NO, KC_NO, KC_BRID, KC_BRIU, KC_NO,
/* Top Thumb Keys */
KC_TRNS, KC_TRNS,
/* Zxc Row (Right) */
KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO,
/* Bottom Row */
KC_TRNS, KC_TRNS, KC_TRNS,
KC_TRNS, KC_TRNS, KC_TRNS
),

[_NUM] = LAYOUT(
/* Number Row */
KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO,
KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
/* Qwerty Row */
KC_PLUS, KC_MINS, KC_1, LGUI_T(KC_2), KC_3, KC_4,
KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
/* Home Row */
KC_COMM, LSFT_T(KC_DOT), LGUI_T(KC_4), LALT_T(KC_5), LCTL_T(KC_6), KC_7,
KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
/* Zxc Row (Left) */
KC_ASTR, KC_SLSH, KC_7, KC_8, KC_9, KC_BSLS,
/* Top Thumb Keys */
KC_TRNS, KC_TRNS,
/* Zxc Row (Right) */
KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
/* Bottom Row */
KC_EQL, KC_0, KC_TRNS,
KC_TRNS, KC_TRNS, KC_TRNS
),

[_NAV] = LAYOUT(
/* Number Row */
KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
KC_NO, KC_TRNS, KC_TRNS, KC_TRNS, KC_NO, KC_NO,
/* Qwerty Row */
KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
KC_HOME, KC_PGUP, KC_UP, KC_PGDN, KC_NO, KC_NO,
/* Home Row */
KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
KC_END, KC_LEFT, KC_DOWN, KC_RGHT, KC_LGUI, KC_NO,
/* Zxc Row (Left) */
KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
/* Top Thumb Keys */
KC_TRNS, KC_TRNS,
/* Zxc Row (Right) */
KC_NO, KC_LCTL, KC_LALT, KC_LGUI, KC_LSFT, KC_NO,
/* Bottom Row */
KC_TRNS, KC_TRNS, KC_TRNS,
KC_TRNS, KC_TRNS, KC_TRNS
)

};

bool process_record_user(uint16_t keycode, keyrecord_t* record) {
  if (!process_achordion(keycode, record)) { return false; }
  // Your macros ...

  return true;
}

void matrix_scan_user(void) {
  achordion_task();
}
