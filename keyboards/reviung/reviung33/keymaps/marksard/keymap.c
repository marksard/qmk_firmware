#include QMK_KEYBOARD_H

// Each layer gets a name for readability, which is then used in the keymap matrix below.
// The underscores don't mean anything - you can have a layer called STUFF or any other name.
// Layer names don't all need to be of the same length, obviously, and you can also skip them
// entirely and just use numbers.
enum layer_number {
  _BASE,
  _LOWER,
  _RAISE,
  _ADJUST,
};

enum custom_keycodes {
  RGBRST = SAFE_RANGE,
  LOWER,
  RAISE,
  KANJI,
};

// Layer Mode aliases
#define KC_MLAD  MO(_ADJUST)

// Base layer mod tap
#define KC_Q_AL  LALT_T(KC_Q)
#define KC_A_CT  LCTL_T(KC_A)
#define KC_Z_SF  LSFT_T(KC_Z)
#define KC_X_AL  LALT_T(KC_X)
#define KC_C_GU  LGUI_T(KC_C)
#define KC_SSSF  RSFT_T(KC_SLSH)
#define KC_ENCT  RCTL_T(KC_ENT)

// Lower layer mod tap
#define KC_F1AL  LALT_T(KC_F1)
#define KC_F6CT  LCTL_T(KC_F6)
#define KC_QUCT  RCTL_T(KC_QUOT)
#define KC_11SF  LSFT_T(KC_F11)
#define KC_12AL  LALT_T(KC_F12)

// Layer tap
#define KC_BSLO  LT(_LOWER, KC_BSPC)
#define KC_SPRA  LT(_RAISE, KC_SPC)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [_BASE] = LAYOUT_reviung33(
  //,---------------------------------------------------------------------------------------------------.
       KC_Q_AL,     KC_W,     KC_E,     KC_R,     KC_T,     KC_Y,     KC_U,     KC_I,     KC_O,     KC_P,
  //|---------+---------+---------+---------+---------+---------+---------+---------+---------+---------|
       KC_A_CT,     KC_S,     KC_D,     KC_F,     KC_G,     KC_H,     KC_J,     KC_K,     KC_L,  KC_ENCT,
  //|---------+---------+---------+---------+---------+---------+---------+---------+---------+---------|
       KC_Z_SF,  KC_X_AL,  KC_C_GU,     KC_V,     KC_B,     KC_N,     KC_M,  KC_COMM,   KC_DOT,  KC_SSSF,
  //`---------+---------+---------+---------+---------+---------+---------+---------+---------+---------'
       KC_LCTL,                                    KC_SPRA,                                      KC_BSLO
  //`---------+---------+---------+---------+---------+---------+---------+---------+---------+---------'
  ),

  [_LOWER] = LAYOUT_reviung33(
  //,---------------------------------------------------------------------------------------------------.
       KC_F1AL,    KC_F2,    KC_F3,    KC_F4,    KC_F5,  KC_MINS,   KC_EQL,  KC_LBRC,  KC_RBRC,  KC_BSLS,
  //|---------+---------+---------+---------+---------+---------+---------+---------+---------+---------|
       KC_F6CT,    KC_F7,    KC_F8,    KC_F9,   KC_F10,  XXXXXXX,  XXXXXXX,  XXXXXXX,  KC_SCLN,  KC_QUCT,
  //|---------+---------+---------+---------+---------+---------+---------+---------+---------+---------|
       KC_11SF,  KC_12AL,   KC_ESC,   KC_TAB,    KANJI,   KC_DEL,  XXXXXXX,  KC_JYEN,    KC_RO,   KC_GRV,
  //`---------+---------+---------+---------+---------+---------+---------+---------+---------+---------'
       _______,                                    KC_MLAD,                                      KC_MLAD
  //`---------+---------+---------+---------+---------+---------+---------+---------+---------+---------'
  ),

  [_RAISE] = LAYOUT_reviung33(
  //,---------------------------------------------------------------------------------------------------.
          KC_1,     KC_2,     KC_3,     KC_4,     KC_5,     KC_6,     KC_7,     KC_8,     KC_9,     KC_0,
  //|---------+---------+---------+---------+---------+---------+---------+---------+---------+---------|
       KC_LCTL,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  KC_LEFT,  KC_DOWN,    KC_UP,  KC_RGHT,  KC_LSFT,
  //|---------+---------+---------+---------+---------+---------+---------+---------+---------+---------|
       KC_LSFT,  KC_LALT,   KC_ESC,   KC_TAB,    KANJI,   KC_DEL,    KC_RO,  KC_COMM,   KC_DOT,  KC_SSSF,
  //`---------+---------+---------+---------+---------+---------+---------+---------+---------+---------'
       _______,                                    _______,                                      KC_MLAD
  //`---------+---------+---------+---------+---------+---------+---------+---------+---------+---------'
  ),

  [_ADJUST] = LAYOUT_reviung33(
  //,---------------------------------------------------------------------------------------------------.
        RESET,    RGBRST,  AG_NORM,  AG_SWAP,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,   KC_INS,  KC_PSCR,
  //|---------+---------+---------+---------+---------+---------+---------+---------+---------+---------|
       RGB_TOG,  RGB_HUI,  RGB_SAI,  RGB_VAI,  XXXXXXX,  KC_MS_L,  KC_MS_D,  KC_MS_U,  KC_MS_R,  KC_NLCK,
  //|---------+---------+---------+---------+---------+---------+---------+---------+---------+---------|
       RGB_MOD,  RGB_HUD,  RGB_SAD,  RGB_VAD,  XXXXXXX,  KC_BTN1,  KC_BTN2,  XXXXXXX,  XXXXXXX,  XXXXXXX,
  //`---------+---------+---------+---------+---------+---------+---------+---------+---------+---------'
       _______,                                    _______,                                      _______
  //`---------+---------+---------+---------+---------+---------+---------+---------+---------+---------'
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
          register_code16(keymap_config.swap_lalt_lgui ? A(KC_GRV) : KC_LANG2);
      } else {
          unregister_code16(keymap_config.swap_lalt_lgui ? A(KC_GRV) : KC_LANG2);
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
