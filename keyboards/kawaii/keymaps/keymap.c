/* Copyright 2021 yohewi
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */
#include QMK_KEYBOARD_H
#include "keymap_jp.h"

// Defines names for use in layer keycodes and the keymap
enum layer_names {
    _Default,
    _LOWER,
    _RAISE,
    _ADJUST
};

// enum tapdances{
//   TD_CODO = 0,
//   TD_SLRO,
// };

// Layer Mode aliases
#define KC_MLAD  MO(_ADJUST)

// Base layer mod tap
#define KC_A_SF  LSFT_T(KC_A)
#define KC_A_CT  LCTL_T(KC_A)
#define KC_Z_SF  LSFT_T(KC_Z)
#define KC_Z_CT  LCTL_T(KC_Z)
#define KC_X_AL  LALT_T(KC_X)
#define KC_C_GU  LGUI_T(KC_C)
#define KC_SSCT  RCTL_T(KC_SLSH)
#define KC_ENSF  RSFT_T(KC_ENT)

// Raise layer mod tap
#define KC_F6SF  LSFT_T(KC_F6)
#define KC_QUSF  RSFT_T(KC_QUOT)
#define KC_11CT  LCTL_T(KC_F11)
#define KC_12AL  LALT_T(KC_F12)

// Layer tap
#define KC_BSLO  LT(_LOWER, KC_BSPC)
#define KC_SPRA  LT(_RAISE, KC_SPC)


// Defines the keycodes used by our macros in process_record_user
enum custom_keycodes {
    Default,
    LOWER,
    RAISE,
    ADJUST,
    KANJI
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    /* Base */
    [_Default] = LAYOUT(
      KC_Q,       KC_W,       KC_E,       KC_R,     KC_T,      KC_Y,     KC_U,    KC_I,    KC_O, \
      KC_A_CT,    KC_S,       KC_D,       KC_F,     KC_G,      KC_H,     KC_J,    KC_K,    KC_P, \
      KC_Z_SF,    KC_X_AL,    KC_C_GU,    KC_V,     KC_B,      KC_N,     KC_M,    KC_COMM, KC_L, \
    　_______,   KC_LALT,     LOWER,      KC_BSLO,  KC_SPRA,   RAISE,    KC_SSCT, _______,  _______ ),

    [_LOWER] = LAYOUT(
      KC_1,    KC_2,    KC_3,    KC_4,    KC_5,     KC_6,      KC_7,     KC_8,    KC_9, \
      KC_A,    KC_S,    KC_D,    KC_F,    KC_G,     KC_LEFT,   KC_UP,    KC_DOWN, KC_0, \
      KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,     KC_RO,     KC_GRV,   KC_COMM, KC_RIGHT, \
      _______, KC_LALT, KC_LGUI, ADJUST,  _______,   _______,  KC_SPC,   _______,   _______ ),
    
    [_RAISE] = LAYOUT(
      KC_F1,    KC_F2,    KC_F3,   KC_F4,  KC_F5,   KC_PMNS, KC_CIRC, KC_NUBS, KC_AT, \
      KC_F6SF,  KC_F7,    KC_F8,   KC_F9,  KC_F10,  KC_UNDS, KC_MINS, KC_SCLN, KC_LBRC, \
      KC_11CT,  KC_12AL,  KC_C,    KC_V,   KC_B,    KC_N,    KC_M,    KC_COMM, KC_RBRC, \
      _______, KC_LGUI,  KC_LALT, ADJUST,  _______,   _______,  KC_SPC,  _______,  _______  )
};
