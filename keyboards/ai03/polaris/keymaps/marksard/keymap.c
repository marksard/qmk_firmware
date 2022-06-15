/* Copyright 2020 marksard
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
  _BASE = 0,
  _LOWER,
  _ADJUST,
};

enum custom_keycodes {
  KANJI = SAFE_RANGE,
  RGBRST,
};

// Layer tap
#define KC_BSLO  LT(_LOWER, KC_BSPC)
#define KC_SPLO  LT(_LOWER, KC_SPC)
#define KC_MLAD  MO(_ADJUST)

// Base layer mod tap
#define KC_ENCT  RCTL_T(KC_ENT)
#define KC_ROSF  RSFT_T(KC_RO)

// Other
#define KC_ALAP  RALT_T(KC_APP)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [_BASE] = LAYOUT_60_tsangan_hhkb(
  //,-----------------------------------------------------------------------------------------------------------------------------------------------------.
        KC_ESC,     KC_1,     KC_2,     KC_3,     KC_4,     KC_5,     KC_6,     KC_7,     KC_8,     KC_9,     KC_0,  KC_MINS,   KC_EQL,  KC_BSLS,   KC_GRV,
  //|---------+---------+---------+---------+---------+---------+---------+---------+---------+---------+---------+---------+---------+---------+---------|
        KC_TAB,     KC_Q,     KC_W,     KC_E,     KC_R,     KC_T,     KC_Y,     KC_U,     KC_I,     KC_O,     KC_P,  KC_LBRC,  KC_RBRC,            KC_BSPC,
  //|---------+---------+---------+---------+---------+---------+---------+---------+---------+---------+---------+---------+---------+---------+---------|
       KC_LCTL,     KC_A,     KC_S,     KC_D,     KC_F,     KC_G,     KC_H,     KC_J,     KC_K,     KC_L,  KC_SCLN,  KC_QUOT,                      KC_ENCT,
  //|---------+---------+---------+---------+---------+---------+---------+---------+---------+---------+---------+---------+---------+---------+---------|
       KC_LSFT,     KC_Z,     KC_X,     KC_C,     KC_V,     KC_B,     KC_N,     KC_M,  KC_COMM,   KC_DOT,  KC_SLSH,                      KC_ROSF,  KC_ROSF,
  //|---------+---------+---------+---------+---------+---------+---------+---------+---------+---------+---------+---------+---------+^2.75rsft+---------|
       KC_LCTL,  KC_LALT,  KC_LGUI,                                          KC_SPLO,                                          KC_MLAD,  KC_ALAP,  KC_RCTL
  //`-----------------------------------------------------------------------------------------------------------------------------------------------------'
  ),

  [_LOWER] = LAYOUT_60_tsangan_hhkb(
  //,-----------------------------------------------------------------------------------------------------------------------------------------------------.
        KC_GRV,    KC_F1,    KC_F2,    KC_F3,    KC_F4,    KC_F5,    KC_F6,    KC_F7,    KC_F8,    KC_F9,   KC_F10,   KC_F11,   KC_F12,  KC_JYEN,  _______,
  //|---------+---------+---------+---------+---------+---------+---------+---------+---------+---------+---------+---------+---------+---------+---------|
       _______,    KC_F6,    KC_F7,    KC_F8,    KC_F9,   KC_F10,  KC_HOME,  KC_PGDN,  KC_PGUP,   KC_END,  XXXXXXX,  _______,  _______,             KC_DEL,
  //|---------+---------+---------+---------+---------+---------+---------+---------+---------+---------+---------+---------+---------+---------+---------|
       _______,   KC_F11,   KC_F12,  XXXXXXX,  XXXXXXX,  XXXXXXX,  KC_LEFT,  KC_DOWN,    KC_UP,  KC_RGHT,  XXXXXXX,  _______,                      _______,
  //|---------+---------+---------+---------+---------+---------+---------+---------+---------+---------+---------+---------+---------+---------+---------|
       _______,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,    KANJI,   KC_DEL,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,                      _______,  _______,
  //|---------+---------+---------+---------+---------+---------+---------+---------+---------+---------+---------+---------+---------+---------+---------|
       _______,  _______,  _______,                                          _______,                                          _______,  _______,  _______
  //`-----------------------------------------------------------------------------------------------------------------------------------------------------'
  ),

  [_ADJUST] = LAYOUT_60_tsangan_hhkb(
  //,-----------------------------------------------------------------------------------------------------------------------------------------------------.
       _______,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,   KC_INS,  KC_PSCR,
  //|---------+---------+---------+---------+---------+---------+---------+---------+---------+---------+---------+---------+---------+---------+---------|
       _______,    RESET,   RGBRST,  AG_NORM,  AG_SWAP,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,            KC_NLCK,
  //|---------+---------+---------+---------+---------+---------+---------+---------+---------+---------+---------+---------+---------+---------+---------|
       KC_CAPS,  RGB_TOG,  RGB_HUI,  RGB_SAI,  RGB_VAI,  XXXXXXX,  KC_MS_L,  KC_MS_D,  KC_MS_U,  KC_MS_R,  XXXXXXX,  XXXXXXX,                      _______,
  //|---------+---------+---------+---------+---------+---------+---------+---------+---------+---------+---------+---------+---------+---------+---------|
       _______,  RGB_MOD,  RGB_HUD,  RGB_SAD,  RGB_VAD,  XXXXXXX,  KC_BTN1,  KC_BTN2,  XXXXXXX,  XXXXXXX,  XXXXXXX,                      _______,  _______,
  //|---------+---------+---------+---------+---------+---------+---------+---------+---------+---------+---------+---------+---------+---------+---------|
       _______,  _______,  _______,                                          _______,                                          _______,  _______,  _______
  //`-----------------------------------------------------------------------------------------------------------------------------------------------------'
  )
};

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
