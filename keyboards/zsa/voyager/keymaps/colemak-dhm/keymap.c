// Copyright 2023 ZSA Technology Labs, Inc <@zsa>
// Copyright 2023 Christopher Courtney, aka Drashna Jael're  (@drashna) <drashna@live.com>
// SPDX-License-Identifier: GPL-2.0-or-later

#include QMK_KEYBOARD_H

#define KC_BACK LCTL(KC_Z)
#define KC_FWRD LCTL(KC_Y)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    // Colemak-DHm
    [0] = LAYOUT(
        KC_GRV,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,                         KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_BSPC,
        KC_TAB,  KC_Q,    KC_W,    KC_F,    KC_P,    KC_B,                         KC_J,    KC_L,    KC_U,    KC_Y,    KC_QUOT, KC_BSLS,
        KC_LCTL, KC_A, LT(3, KC_R),    KC_S,    KC_T,    KC_G,                     KC_M,    KC_N,    KC_E, LT(3, KC_I),    KC_O,    KC_SCLN,
        KC_LSFT, KC_Z,    KC_X,    KC_C,    KC_D,    KC_V,                         KC_K,    KC_H,    KC_COMM, KC_DOT,  KC_SLSH, KC_ESC,
                                     LALT_T(KC_TAB), LT(1, KC_ENT),                KC_SPC,  LT(2,KC_BSPC)
    ),
    // Num
    [1] = LAYOUT(
        KC_F12,  KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,                        KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,
        _______, KC_1,    KC_2,    KC_3,    KC_4,    KC_5,                         KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    _______,
        _______, _______, _______, _______, _______, _______,                      KC_LBRC, KC_MINS, KC_EQL,  KC_RBRC, _______, _______,
        _______, _______, _______, _______, _______, _______,                      _______, _______, _______, _______, _______, _______,
                                                     _______, _______,    _______, _______
    ),
    // Nav
    [2] = LAYOUT(
        RM_TOGG, RM_NEXT, RM_PREV, RM_VALU, RM_VALD, _______,                      _______, _______, _______, _______, _______, KC_DEL,
        LWIN(KC_TAB), _______, _______, LWIN(KC_E), _______, LWIN(KC_T),           KC_HOME, KC_PGDN, KC_PGUP, KC_END,  _______, _______,
        _______, _______, _______, LWIN(KC_D), LWIN(KC_F), LWIN(KC_G),             KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT, _______, _______,
        _______, KC_BACK, KC_CUT, KC_COPY, KC_FWRD, KC_PASTE,                      LWIN(KC_LEFT), LWIN(KC_DOWN), LWIN(KC_UP), LWIN(KC_RGHT), _______, QK_BOOT,
                                                     _______, _______,    _______, _______
    ),
    // Sym
    [3] = LAYOUT(
        _______, _______, _______, _______, _______, _______,                      _______, _______, _______, _______, _______, _______,
        _______, KC_GRV,  KC_AT,   KC_HASH, KC_DLR,  KC_PERC,                      KC_CIRC, KC_AMPR, KC_PIPE, KC_LCBR, KC_RCBR, _______,
        _______, KC_EXLM, KC_MINS, KC_UNDS, KC_EQL,  KC_COLN,                      KC_LBRC, KC_LPRN, KC_RPRN, KC_RBRC, KC_SCLN, _______,
        _______, _______, KC_ASTR, KC_PLUS, _______, KC_BSLS,                      KC_SLSH, _______, KC_LT,   KC_GT,   KC_QUES,  _______,
                                                     _______, _______,    _______, _______
    ),
};


bool get_hold_on_other_key_press(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case LT(1, KC_ENT):
            // Immediately select the hold action when another key is pressed.
            return true;
        case LT(2, KC_BSPC):
            // Immediately select the hold action when another key is pressed.
            return true;
        case LALT_T(KC_TAB):
            // Immediately select the hold action when another key is pressed.
            return true;
        default:
            // Do not select the hold action when another key is pressed.
            return false;
    }
}
