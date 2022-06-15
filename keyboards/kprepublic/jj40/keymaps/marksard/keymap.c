/* Copyright 2019
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
#define KC_BSLO  LT(_LOWER, KC_BSPC)
#define KC_SPRA  LT(_RAISE, KC_SPC)
#define KC_MLAD  MO(_ADJUST)

// Base layer mod tap
#define KC_A_CT  LCTL_T(KC_A)
#define KC_Z_SF  LSFT_T(KC_Z)
#define KC_ENCT  RCTL_T(KC_ENT)
#define KC_SLSF  RSFT_T(KC_SLSH)

// Lower layer mod tap
#define KC_F6CT  LCTL_T(KC_F6)
#define KC_11SF  LSFT_T(KC_F11)
#define KC_QUCT  RCTL_T(KC_QUOT)
#define KC_ROSF  RSFT_T(KC_RO)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

[0] = LAYOUT_ortho_4x12(
     KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,   KC_NO,   KC_NO,    KC_Y,    KC_U,    KC_I,    KC_O,    KC_P, 
  KC_A_CT,    KC_S,    KC_D,    KC_F,    KC_G,   KC_NO,   KC_NO,    KC_H,    KC_J,    KC_K,    KC_L, KC_ENCT, 
  KC_Z_SF,    KC_X,    KC_C,    KC_V,    KC_B,   KC_NO,   KC_NO,    KC_N,    KC_M, KC_COMM,  KC_DOT, KC_SLSF, 
  KC_LCTL, KC_LGUI, KC_LALT, KC_BSLO, KC_BSLO, KC_BSLO, KC_SPRA, KC_SPRA, KC_SPRA, KC_RGUI,  KC_APP, KC_RCTL
),
[1] = LAYOUT_ortho_4x12(
    KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_NO,   KC_NO, KC_MINS,  KC_EQL, KC_LBRC, KC_RBRC, KC_BSLS, 
  KC_F6CT,   KC_F7,   KC_F8,   KC_F9,  KC_F10,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO, KC_SCLN, KC_QUCT, 
  KC_11SF,  KC_F12,  KC_ESC,  KC_TAB,   KANJI,  KC_DEL,   KC_NO,  KC_DEL,   KC_NO, KC_JYEN,  KC_GRV, KC_ROSF, 
  KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,   KC_NO, KC_MLAD, KC_MLAD, KC_MLAD, KC_TRNS, KC_TRNS, KC_TRNS
),
[2] = LAYOUT_ortho_4x12(
     KC_1,    KC_2,    KC_3,    KC_4,    KC_5,   KC_NO,   KC_NO,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0, 
  KC_LCTL,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO, KC_LEFT, KC_DOWN,   KC_UP, KC_RGHT, KC_LCTL, 
  KC_LSFT,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO, KC_COMM,  KC_DOT, KC_SLSF, 
  KC_TRNS, KC_TRNS, KC_TRNS, KC_MLAD, KC_MLAD, KC_MLAD,   KC_NO, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS
),
[3] = LAYOUT_ortho_4x12(
  RESET,    RGBRST, AG_NORM, AG_SWAP,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,  KC_INS, KC_PSCR, 
  RGB_TOG, RGB_HUI, RGB_SAI, RGB_VAI,   KC_NO,   KC_NO,   KC_NO, KC_HOME, KC_PGDN, KC_PGUP,  KC_END, KC_NLCK, 
  RGB_MOD, RGB_HUI, RGB_SAD, RGB_VAD,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO, KC_CAPS, 
  KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,   KC_NO,   KC_NO, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS
)

};

uint16_t get_tapping_term(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
    case KC_BSLO:
      return TAPPING_LAYER_TERM;
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
#ifdef RGBLIGHT_ENABLE
    case RGBRST:
        if (record->event.pressed) {
          eeconfig_update_rgblight_default();
          rgblight_enable();
        }
      break;
#endif
    default:
      result = true;
      break;
  }

  return result;
}
