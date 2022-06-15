/* Copyright 2019 Ryota Goto
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
/*
    K000, K001, K002, K003, K004, K005, K006, K007, K008, K009, K010, K011, \
    K100, K101, K102, K103, K104, K105, K106, K107, K108, K109, K110, K111, \
    K200, K201, K202, K203, K204, K205, K206, K207, K208, K209, K210, K211, \
    K300, K301, K302,     K304,       K306,       K308,   K309, K310, K311  \
*/

enum layer_number {
  _BASE,
  _LOWER,
  _RAISE,
  _ADJUST,
};

enum custom_keycodes {
  KANJI = SAFE_RANGE,
  RGBRST,
};

// Layer tap
#define KC_LOWR  MO(_LOWER)
#define KC_SPRA  LT(_RAISE, KC_SPC)
#define KC_MLAD  MO(_ADJUST)

// Base layer mod tap
#define KC_ENCT  RCTL_T(KC_ENT)
#define KC_SLSF  RSFT_T(KC_SLSH)

// Lower layer mod tap
#define KC_QUCT  RCTL_T(KC_QUOT)
#define KC_ROSF  RSFT_T(KC_RO)

// Other
#define KC_ALAP  RALT_T(KC_APP)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [_BASE] = LAYOUT_all(
  //,-----------------------------------------------------------------------------------------------------------.
       KC_TAB,    KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_Y,    KC_U,    KC_I,    KC_O,    KC_P, KC_BSPC,
  //|--------+--------+--------+--------+--------+--------|--------+--------+--------+--------+--------+--------|
      KC_LCTL,    KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    KC_H,    KC_J,    KC_K,    KC_L, KC_ENCT, KC_ENCT,
  //|--------+--------+--------+--------+--------+--------|--------+--------+--------+--------+--------+--------|
      KC_LSFT, KC_LSFT,    KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_N,    KC_M, KC_COMM,  KC_DOT, KC_SLSF,
  //|--------+--------+--------+--------+--------+--------|--------+--------+--------+--------+--------+--------|
      KC_LCTL, _______, KC_LGUI,          _______,          KC_SPRA,          _______, KC_LOWR, _______, KC_ALAP
  //`-----------------------------------------------------------------------------------------------------------'
  ),

  [_LOWER] = LAYOUT_all(
  //,-----------------------------------------------------------------------------------------------------------.
       KC_GRV,   KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5, KC_MINS,  KC_EQL, KC_JYEN, KC_LBRC, KC_RBRC, KC_BSLS,
  //|--------+--------+--------+--------+--------+--------|--------+--------+--------+--------+--------+--------|
      _______,   KC_F6,   KC_F7,   KC_F8,   KC_F9,  KC_F10, XXXXXXX, XXXXXXX, XXXXXXX, KC_SCLN, KC_QUCT, KC_QUCT,
  //|--------+--------+--------+--------+--------+--------|--------+--------+--------+--------+--------+--------|
      _______, _______,  KC_F11,  KC_F12, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, KC_JYEN,  KC_GRV, KC_ROSF,
  //|--------+--------+--------+--------+--------+--------|--------+--------+--------+--------+--------+--------|
      _______, _______, _______,          _______,          KC_MLAD,          _______, _______, _______, _______
  //`-----------------------------------------------------------------------------------------------------------'
  ),

  [_RAISE] = LAYOUT_all(
  //,-----------------------------------------------------------------------------------------------------------.
       KC_ESC,    KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0, KC_MINS,
  //|--------+--------+--------+--------+--------+--------|--------+--------+--------+--------+--------+--------|
      _______, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, KC_LEFT, KC_DOWN,   KC_UP, KC_RGHT, _______, _______,
  //|--------+--------+--------+--------+--------+--------|--------+--------+--------+--------+--------+--------|
      _______, _______, XXXXXXX, XXXXXXX,  KC_ESC,  KC_TAB,   KANJI,  KC_DEL, XXXXXXX, KC_COMM,  KC_DOT, KC_SLSF,
  //|--------+--------+--------+--------+--------+--------|--------+--------+--------+--------+--------+--------|
      _______, _______, _______,          _______,          _______,          _______, KC_MLAD, _______, _______
  //`-----------------------------------------------------------------------------------------------------------'
  ),

  [_ADJUST] = LAYOUT_all(
  //,-----------------------------------------------------------------------------------------------------------.
      _______,   RESET,  RGBRST, AG_NORM, AG_SWAP, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,  KC_INS, KC_PSCR,
  //|--------+--------+--------+--------+--------+--------|--------+--------+--------+--------+--------+--------|
      KC_CAPS, RGB_TOG, RGB_HUI, RGB_SAI, RGB_VAI, XXXXXXX, KC_HOME, KC_PGDN, KC_PGUP,  KC_END, XXXXXXX, KC_NLCK,
  //|--------+--------+--------+--------+--------+--------|--------+--------+--------+--------+--------+--------|
      _______, XXXXXXX, RGB_MOD, RGB_HUD, RGB_SAD, RGB_VAD, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, _______,
  //|--------+--------+--------+--------+--------+--------|--------+--------+--------+--------+--------+--------|
      _______, _______, _______,          _______,          _______,          _______, _______, _______, _______
  //`-----------------------------------------------------------------------------------------------------------'
  )
};

uint16_t get_tapping_term(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
    case KC_SPRA:
      return TAPPING_LAYER_TERM;
    default:
      return TAPPING_TERM;
  }
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {

  bool result = false;
  switch (keycode) {
    case KANJI:
      if (record->event.pressed) {
        if (keymap_config.swap_lalt_lgui) {
          SEND_STRING(SS_LALT("`"));
        }
        else {
          SEND_STRING(SS_LGUI(" "));
        }
      }
      break;
    default:
      result = true;
      break;
  }

  return result;
}
