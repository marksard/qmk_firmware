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
#include "keymap_japanese.h"

// Each layer gets a name for readability, which is then used in the keymap matrix below.
// The underscores don't mean anything - you can have a layer called STUFF or any other name.
// Layer names don't all need to be of the same length, obviously, and you can also skip them
// entirely and just use numbers.
enum layer_number {
  _BASE = 0,
  _LOWER,
  _RAISE,
  _ADJUST,
};

enum custom_keycodes {
  KANJI = SAFE_RANGE,
  RGBRST
};

// Layer tap
#define KC_BSLO  LT(_LOWER, KC_BSPC)
#define KC_SPRA  LT(_RAISE, KC_SPC)
#define KC_MLAD  MO(_ADJUST)

// Base layer mod tap
#define KC_TBCT  LCTL_T(KC_TAB)
#define KC_ENCT  RCTL_T(KC_ENT)
#define KC_ROSF  RSFT_T(JP_BSLS)

// Lower layer mod tap
#define KC_QUCT  RCTL_T(KC_QUOT)

// Other
#define KC_ALAP  RALT_T(KC_APP)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [_BASE] = LAYOUT_base( \
  //,--------------------------------------------------------------------------------------------------------------------.
       KC_ESC,    KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,          KC_BSPC,\
  //|--------+--------+--------+--------+--------+--------|--------+--------+--------+--------+--------+-----------------|
      KC_TBCT,    KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    KC_H,    KC_J,    KC_K,    KC_L, KC_SCLN,          KC_ENCT,\
  //|--------+--------+--------+--------+--------+--------|--------+--------+--------+--------+--------+--------+--------|
      KC_LSFT,    KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_N,    KC_M, KC_COMM,  KC_DOT, KC_SLSH,   KC_UP,         \
  //|--------+--------+--------+--------+--------+--------|--------+--------+--------+--------+--------+--------+--------|
      KC_LCTL, KC_LALT, KC_LGUI, XXXXXXX,          KC_BSLO,          KC_SPRA, KC_MLAD, KC_ALAP, KC_LEFT, KC_DOWN, KC_RGHT,\
  //`-------------------------------------------------------------------------------------------------------------------'
      KC_ROSF \
  // ExtraKey: This key is an extra key. REV1 is a split back space. REV2 is to the right of the arrow-up key.
  ),

  [_LOWER] = LAYOUT_base( \
  //,--------------------------------------------------------------------------------------------------------------------.
       KC_GRV,   KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5, KC_MINS,  KC_EQL,  JP_YEN, KC_LBRC, KC_RBRC,          KC_BSLS,\
  //|--------+--------+--------+--------+--------+--------|--------+--------+--------+--------+--------+-----------------|
      _______,   KC_F6,   KC_F7,   KC_F8,   KC_F9,  KC_F10, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,          KC_QUCT,\
  //|--------+--------+--------+--------+--------+--------|--------+--------+--------+--------+--------+--------+--------|
      _______,  KC_F11,  KC_F12, XXXXXXX, XXXXXXX,   KANJI,  KC_DEL, XXXXXXX, XXXXXXX, JP_BSLS,  KC_GRV, KC_PGUP,         \
  //|--------+--------+--------+--------+--------+--------|--------+--------+--------+--------+--------+--------+--------|
      _______, _______, _______, _______,          _______,          KC_MLAD, _______, XXXXXXX, KC_HOME, KC_PGDN,  KC_END,\
  //`-------------------------------------------------------------------------------------------------------------------'
      _______ \
  // ExtraKey: This key is an extra key. REV1 is a split back space. REV2 is to the right of the arrow-up key.
  ),

  [_RAISE] = LAYOUT_base( \
  //,--------------------------------------------------------------------------------------------------------------------.
      _______,    KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,          KC_MINS,\
  //|--------+--------+--------+--------+--------+--------|--------+--------+--------+--------+--------+-----------------|
      _______, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, KC_LEFT, KC_DOWN,   KC_UP, KC_RGHT, XXXXXXX,          _______,\
  //|--------+--------+--------+--------+--------+--------|--------+--------+--------+--------+--------+--------+--------|
      _______, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, KC_COMM,  KC_DOT, KC_BSLS, XXXXXXX,         \
  //|--------+--------+--------+--------+--------+--------|--------+--------+--------+--------+--------+--------+--------|
      _______, _______, _______, _______,          KC_MLAD,          _______, _______, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,\
  //`-------------------------------------------------------------------------------------------------------------------'
      _______ \
  // ExtraKey: This key is an extra key. REV1 is a split back space. REV2 is to the right of the arrow-up key.
  ),

  [_ADJUST] = LAYOUT_base( \
  //,--------------------------------------------------------------------------------------------------------------------.
      XXXXXXX, QK_BOOT,  RGBRST, AG_NORM, AG_SWAP, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,  KC_INS,          KC_PSCR,\
  //|--------+--------+--------+--------+--------+--------|--------+--------+--------+--------+--------+-----------------|
      KC_CAPS, RGB_TOG, RGB_HUI, RGB_SAI, RGB_VAI, XXXXXXX, KC_HOME, KC_PGDN, KC_PGUP,  KC_END, XXXXXXX,           KC_NUM,\
  //|--------+--------+--------+--------+--------+--------|--------+--------+--------+--------+--------+--------+--------|
      _______, RGB_MOD, RGB_HUD, RGB_SAD, RGB_VAD, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, KC_BTN1, KC_BTN2, KC_MS_U,         \
  //|--------+--------+--------+--------+--------+--------|--------+--------+--------+--------+--------+--------+--------|
      _______, _______, _______, _______,          XXXXXXX,          XXXXXXX, _______, XXXXXXX, KC_MS_L, KC_MS_D, KC_MS_R,\
  //`-------------------------------------------------------------------------------------------------------------------'
      _______ \
  // ExtraKey: This key is an extra key. REV1 is a split back space. REV2 is to the right of the arrow-up key.
  )
};

#define L_BASE _BASE
#define L_LOWER ((layer_state_t)1<<_LOWER)
#define L_RAISE ((layer_state_t)1<<_RAISE)
#define L_ADJUST ((layer_state_t)1<<_ADJUST)
#define L_ADJUST_1 (L_ADJUST|L_LOWER)
#define L_ADJUST_2 (L_ADJUST|L_RAISE)

#ifdef OLED_ENABLE
#include <stdio.h>
#include <string.h>
#include "../common/oled_helper.h"

typedef struct {
  uint8_t state;
  char name[8];
}LAYER_DISPLAY_NAME;

#define LAYER_DISPLAY_MAX 6
const LAYER_DISPLAY_NAME layer_display_name[LAYER_DISPLAY_MAX] = {
  {L_BASE, "Base"},
  {L_LOWER, "Lower"},
  {L_RAISE, "Raise"},
  {L_ADJUST, "Adjust"},
  {L_ADJUST_1, "Adjust"},
  {L_ADJUST_2, "Adjust"}
};

static inline const char* get_leyer_status(void) {

  for (uint8_t i = 0; i < LAYER_DISPLAY_MAX; ++i) {
    if (layer_state == 0 && layer_display_name[i].state == default_layer_state) {

      return layer_display_name[i].name;
    } else if (layer_state != 0 && (layer_display_name[i].state == layer_state)) {

      return layer_display_name[i].name;
    }
  }

  return "?";
}

static char layer_status_buf[24] = "Layer state ready.\n";
static inline void update_keymap_status(void) {

  snprintf(layer_status_buf, sizeof(layer_status_buf) - 1, "OS:%s Layer:%s\n",
    keymap_config.swap_lalt_lgui? "win" : "mac", get_leyer_status());
}

static inline void render_keymap_status(void) {

  oled_write(layer_status_buf, false);
}

static inline void render_status(void) {

  UPDATE_LED_STATUS();
  RENDER_LED_STATUS();
  update_keymap_status();
  render_keymap_status();
  UPDATE_LOCK_STATUS();
  RENDER_LOCK_STATUS();
  RENDER_KEY_STATUS();
}

oled_rotation_t oled_init_user(oled_rotation_t rotation) {

//   if (is_keyboard_master())
//     return OLED_ROTATION_180;  // flips the display 180 degrees if offhand
  return rotation;
}

bool oled_task_user(void) {

  if (is_keyboard_master()) {
    render_status();
  } else {
    render_logo();
  }
  return false;
}

#endif

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

  UPDATE_KEY_STATUS(keycode, record);

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
