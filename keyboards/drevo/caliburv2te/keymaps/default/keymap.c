#include QMK_KEYBOARD_H

enum layer_number {
  _BASE,
  _LOWER,
  _RAISE,
  _ADJUST,
};

enum custom_keycodes {
  KANJI = SAFE_RANGE,
  RGBRST
};

#define KC_ROSF  RSFT_T(KC_RO)

#define KC_SPLO  LT(_LOWER, KC_SPC)
#define KC_AJST  MO(_ADJUST)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

	[_BASE] = LAYOUT(
		 KC_ESC,    KC_1,   KC_2,     KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0, KC_MINS,  KC_EQL, KC_BSPC,  KC_INS, KC_HOME,
		 KC_TAB,    KC_Q,   KC_W,     KC_E,    KC_R,    KC_T,    KC_Y,    KC_U,    KC_I,    KC_O,    KC_P, KC_LBRC, KC_RBRC, KC_BSLS,  KC_DEL,  KC_END,
		KC_LCTL,    KC_A,   KC_S,     KC_D,    KC_F,    KC_G,    KC_H,    KC_J,    KC_K,    KC_L, KC_SCLN, KC_QUOT,  KC_ENT, KC_PAUS, KC_PGUP,
		KC_LSFT,    KC_Z,   KC_X,     KC_C,    KC_V,    KC_B,    KC_N,    KC_M, KC_COMM,  KC_DOT, KC_SLSH, KC_ROSF,   KC_UP, KC_PGDN,
		KC_LCTL, KC_LGUI, KC_LALT, KC_SPLO, KC_AJST, KC_MENU, KC_RCTL, KC_LEFT, KC_DOWN, KC_RGHT),

	[_LOWER] = LAYOUT(
		 KC_GRV,   KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
		KC_TRNS,   KC_F6,   KC_F7,   KC_F8,   KC_F9,  KC_F10, KC_HOME, KC_PGDN, KC_PGUP, KC_END,  KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
		KC_TRNS,  KC_F11,  KC_F12, KC_TRNS, KC_TRNS, KC_TRNS, KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
		KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,   KANJI,  KC_DEL, KC_TRNS, KC_TRNS, KC_GRV,  KC_JYEN, KC_TRNS, KC_TRNS, KC_TRNS,
		KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS),

	[_RAISE] = LAYOUT(
		KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
		KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
		KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
		KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
		KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS),

	[_ADJUST] = LAYOUT(
		KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,  KC_INS, KC_PSCR,
		KC_TRNS,   RESET, KC_TRNS, AG_NORM, AG_SWAP, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_NLCK,
		KC_CAPS, RGB_TOG, RGB_HUI, RGB_SAI, RGB_VAI, KC_TRNS, RGB_M_P, RGB_M_B, RGB_M_R, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
		KC_TRNS, RGB_MOD, RGB_HUD, RGB_SAD, RGB_VAD, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
		KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS),
};

bool process_record_user(uint16_t keycode, keyrecord_t *record) {

  bool result = false;
  switch (keycode) {
    case KANJI:
      if (record->event.pressed) {
        // if (keymap_config.swap_lalt_lgui) {
          SEND_STRING(SS_LALT("`"));
        // }
        // else {
        //   SEND_STRING(SS_LGUI(" "));
        // }
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

void matrix_init_user(void) {
    // keymap_config.swap_lalt_lgui = keymap_config.swap_ralt_rgui = true;
}
