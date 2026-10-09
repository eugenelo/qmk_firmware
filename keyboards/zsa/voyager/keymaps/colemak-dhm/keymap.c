// Copyright 2023 ZSA Technology Labs, Inc <@zsa>
// Copyright 2023 Christopher Courtney, aka Drashna Jael're  (@drashna) <drashna@live.com>
// SPDX-License-Identifier: GPL-2.0-or-later

// Mirrors zmk-config/config/corneish_zen.keymap (minus its NUMPAD layer). The
// Voyager has an extra top row and one fewer thumb key per side, so ZMK's outer
// thumbs are dropped: no GUI and no RCTRL. Super+Q sits on the top-right key.

#include QMK_KEYBOARD_H

enum layer_names {
    _COLEMAK,
    _LOWER,
    _RAISE,
    _ADJUST,
};

#define CALTDEL LCTL(LALT(KC_DEL))
#define TSKMGR LCTL(LSFT(KC_ESC))

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    // Colemak-DHm
    [_COLEMAK] = LAYOUT(
        KC_GRV,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,                         KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    LGUI(KC_Q),
        KC_TAB,  KC_Q,    KC_W,    KC_F,    KC_P,    KC_B,                         KC_J,    KC_L,    KC_U,    KC_Y,    KC_QUOT, KC_BSPC,
        KC_LCTL, KC_A,    KC_R,    KC_S,    KC_T,    KC_G,                         KC_M,    KC_N,    KC_E,    KC_I,    KC_O,    KC_SCLN,
        KC_LSFT, KC_Z,    KC_X,    KC_C,    KC_D,    KC_V,                         KC_K,    KC_H,    KC_COMM, KC_DOT,  KC_SLSH, KC_ESC,
                                          KC_LALT, LT(_LOWER,KC_ENT),          KC_SPC,  MO(_RAISE)
    ),
    // Symbol
    [_LOWER] = LAYOUT(
        _______, _______, _______, _______, _______, _______,                      _______, _______, _______, _______, _______, _______,
        KC_GRV,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,                         KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_BSLS,
        _______, _______, _______, KC_PLUS, KC_MINS, KC_COLN,                      KC_LBRC, KC_MINS, KC_EQL,  KC_RBRC, KC_SCLN, KC_COLN,
        _______, _______, _______, _______, _______, KC_BSLS,                      KC_SLSH, KC_UNDS, _______, _______, _______, _______,
                                                    _______, _______,    _______, _______
    ),
    // Navigation
    [_RAISE] = LAYOUT(
        _______, _______, _______, _______, _______, _______,                      _______, _______, _______, _______, _______, _______,
        _______, _______, _______, _______, _______, _______,                      KC_HOME, KC_PGDN, KC_PGUP, KC_END,  KC_RALT, KC_DEL,
        _______, _______, _______, _______, _______, _______,                      KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT, _______, _______,
        _______, _______, _______, _______, _______, _______,                      LWIN(KC_LEFT), LWIN(KC_DOWN), LWIN(KC_UP), LWIN(KC_RGHT), _______, _______,
                                                     _______, _______,    _______, _______
    ),
    // Function
    [_ADJUST] = LAYOUT(
        RM_TOGG, RM_NEXT, RM_PREV, RM_VALU, RM_VALD, TSKMGR,                       _______, _______, _______, _______, _______, CALTDEL,
        KC_F12,  KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,                        KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,
        _______, _______, _______, _______, _______, _______,                      _______, _______, _______, _______, _______, _______,
        _______, _______, _______, _______, _______, _______,                      _______, _______, _______, _______, _______, QK_BOOT,
                                                     _______, _______,    _______, _______
    ),
};

/**
 * @brief Derive _ADJUST from _LOWER + _RAISE, matching ZMK's tri_layer conditional layer.
 * @param state Layer state requested by QMK.
 * @return Layer state with _ADJUST set iff both _LOWER and _RAISE are active.
 */
layer_state_t layer_state_set_user(layer_state_t state) {
    return update_tri_layer_state(state, _LOWER, _RAISE, _ADJUST);
}
