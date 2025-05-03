// Copyright 2023 ZSA Technology Labs, Inc <@zsa>
// Copyright 2023 Christopher Courtney, aka Drashna Jael're  (@drashna) <drashna@live.com>
// SPDX-License-Identifier: GPL-2.0-or-later

#include QMK_KEYBOARD_H

enum layer_names {
    _COLEMAK,
    _LOWER,
    _RAISE,
    _ADJUST,
};

#define KC_BACK LCTL(KC_Z)
#define KC_FWRD LCTL(KC_Y)
#define CALTDEL LCTL(LALT(KC_DEL))
#define TSKMGR LCTL(LSFT(KC_ESC))

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    // Colemak-DHm
    [_COLEMAK] = LAYOUT(
        KC_GRV,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,                         KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_BSPC,
        KC_TAB,  KC_Q,    KC_W,    KC_F,    KC_P,    KC_B,                         KC_J,    KC_L,    KC_U,    KC_Y,    KC_QUOT, KC_BSLS,
        KC_LCTL, KC_A,    KC_R,    KC_S,    KC_T,    KC_G,                         KC_M,    KC_N,    KC_E,    KC_I,    KC_O,    KC_SCLN,
        KC_LSFT, KC_Z,    KC_X,    KC_C,    KC_D,    KC_V,                         KC_K,    KC_H,    KC_COMM, KC_DOT,  KC_SLSH, KC_ESC,
                                          KC_LALT, LT(_LOWER,KC_ENT),          KC_SPC,  LT(_RAISE,KC_BSPC)
    ),
    // Sym
    [_LOWER] = LAYOUT(
        _______, _______, _______, _______, _______, _______,                      _______, _______, _______, _______, _______, _______,
        _______, KC_EXLM, KC_AT,   KC_HASH, KC_DLR,  KC_PERC,                      KC_CIRC, KC_AMPR, KC_ASTR,  KC_LPRN, KC_RPRN, KC_PIPE,
        _______, _______, _______, KC_PLUS, KC_EQL,  KC_COLN,                      KC_LBRC, KC_MINS, KC_EQL, KC_RBRC, KC_SCLN, KC_COLN,
        _______, _______, _______, _______, _______, KC_BSLS,                      KC_SLSH, KC_UNDS, KC_LT,   KC_GT,   KC_QUES, _______,
                                                    _______, _______,    _______, _______
    ),
    // Nav
    [_RAISE] = LAYOUT(
        _______, _______, _______, _______, _______, _______,                      _______, _______, _______, _______, _______, KC_DEL,
        LWIN(KC_TAB), _______, _______, LWIN(KC_E), _______, LWIN(KC_T),           KC_HOME, KC_PGDN, KC_PGUP, KC_END,  _______, _______,
        _______, _______, _______, LWIN(KC_D), LWIN(KC_F), LWIN(KC_G),             KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT, _______, _______,
        _______, _______, _______, _______, _______, _______,                      KC_BACK, KC_CUT,  KC_COPY, KC_PASTE, KC_FWRD, _______,
                                                     _______, _______,    _______, _______
    ),
    // Num
    [_ADJUST] = LAYOUT(
        RM_TOGG, RM_NEXT, RM_PREV, RM_VALU, RM_VALD, _______,                      _______, _______, _______, _______, _______, CALTDEL,
        TSKMGR,  _______, KC_7,    KC_8,    KC_9,    KC_MINS,                      _______, KC_F9,   KC_F10,  KC_F11,   KC_F12, _______,
        _______, _______, KC_4,    KC_5,    KC_6,    KC_PLUS,                      _______, KC_F5,   KC_F6,   KC_F7,    KC_F8,  _______,
        _______, _______, KC_1,    KC_2,    KC_3,    KC_0,                         _______, KC_F1,   KC_F2,   KC_F3,    KC_F4,  QK_BOOT,
                                                     _______, _______,    _______, _______
    ),
};

layer_state_t layer_state_set_user(layer_state_t state) {
    return update_tri_layer_state(state, _LOWER, _RAISE, _ADJUST);
}
