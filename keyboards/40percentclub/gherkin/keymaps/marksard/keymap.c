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

enum tapdances{
  TD_CODO,
};

// Layer Mode aliases
#define KC_MLAD  MO(_ADJUST)

// Base layer mod tap
#define KC_A_SF  LCTL_T(KC_A)
#define KC_Z_CT  LSFT_T(KC_Z)
#define KC_X_AL  LALT_T(KC_X)
#define KC_C_GU  LGUI_T(KC_C)
#define KC_ENSF  RCTL_T(KC_ENT)
#define KC_SSCT  RSFT_T(KC_SLSH)

// Lower layer mod tap
#define KC_F6SF  LCTL_T(KC_F6)
#define KC_11CT  LSFT_T(KC_F11)
#define KC_QUSF  RCTL_T(KC_QUOT)
#define KC_12AL  LALT_T(KC_F12)

// Layer tap
#define KC_B_LO  LT(_LOWER, KC_B)
#define KC_N_RA  LT(_RAISE, KC_N)

// Tap dance
#define KC_CODO  TD(TD_CODO)

qk_tap_dance_action_t tap_dance_actions[] = {
  [TD_CODO] = ACTION_TAP_DANCE_DOUBLE(KC_COMM, KC_DOT),
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [_BASE] = LAYOUT_ortho_3x10(
  //,---------------------------------------------------------------------------------------------------.
          KC_Q,     KC_W,     KC_E,     KC_R,     KC_T,     KC_Y,     KC_U,     KC_I,     KC_O,     KC_P,
  //|---------+---------+---------+---------+---------+---------+---------+---------+---------+---------|
       KC_A_SF,     KC_S,     KC_D,     KC_F,     KC_G,     KC_H,     KC_J,     KC_K,     KC_L,  KC_ENSF,
  //|---------+---------+---------+---------+---------+---------+---------+---------+---------+---------|
       KC_Z_CT,  KC_X_AL,  KC_C_GU,     KC_V,  KC_B_LO,  KC_N_RA,     KC_M,  KC_CODO,  KC_BSPC,   KC_SPC
  //`---------+---------+---------+---------+---------+---------+---------+---------+---------+---------'
  ),

  [_LOWER] = LAYOUT_ortho_3x10(
  //,---------------------------------------------------------------------------------------------------.
         KC_F1,    KC_F2,    KC_F3,    KC_F4,    KC_F5,  KC_MINS,   KC_EQL,  KC_LBRC,  KC_RBRC,  KC_BSLS,
  //|---------+---------+---------+---------+---------+---------+---------+---------+---------+---------|
       KC_F6SF,    KC_F7,    KC_F8,    KC_F9,   KC_F10,  XXXXXXX,  XXXXXXX,  XXXXXXX,  KC_SCLN,  KC_QUSF,
  //|---------+---------+---------+---------+---------+---------+---------+---------+---------+---------|
       KC_11CT,  KC_12AL,   KC_ESC,   KC_TAB,  _______,  KC_MLAD,    KANJI,   KC_DEL,    KC_RO,   KC_GRV
  //`---------+---------+---------+---------+---------+---------+---------+---------+---------+---------'
  ),

  [_RAISE] = LAYOUT_ortho_3x10(
  //,---------------------------------------------------------------------------------------------------.
          KC_1,     KC_2,     KC_3,     KC_4,     KC_5,     KC_6,     KC_7,     KC_8,     KC_9,     KC_0,
  //|---------+---------+---------+---------+---------+---------+---------+---------+---------+---------|
       KC_LSFT,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  KC_LEFT,  KC_DOWN,    KC_UP,  KC_RGHT,  KC_LSFT,
  //|---------+---------+---------+---------+---------+---------+---------+---------+---------+---------|
       KC_LCTL,  KC_LALT,  KC_LGUI,  XXXXXXX,  KC_MLAD,  _______,    KC_RO,  KC_COMM,   KC_DOT,  KC_SSCT
  //`---------+---------+---------+---------+---------+---------+---------+---------+---------+---------'
  ),

  [_ADJUST] = LAYOUT_ortho_3x10(
  //,---------------------------------------------------------------------------------------------------.
        RESET,    RGBRST,  AG_NORM,  AG_SWAP,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,   KC_INS,  KC_PSCR,
  //|---------+---------+---------+---------+---------+---------+---------+---------+---------+---------|
       RGB_TOG,  RGB_HUI,  RGB_SAI,  RGB_VAI,  XXXXXXX,  KC_MS_L,  KC_MS_D,  KC_MS_U,  KC_MS_R,  KC_NLCK,
  //|---------+---------+---------+---------+---------+---------+---------+---------+---------+---------|
       RGB_MOD,  RGB_HUD,  RGB_SAD,  RGB_VAD,  _______,  _______,  KC_BTN1,  KC_BTN2,  XXXXXXX,  XXXXXXX
  //`---------+---------+---------+---------+---------+---------+---------+---------+---------+---------'
  )
};

uint16_t get_tapping_term(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
    case KC_B_LO:
      return TAPPING_LAYER_TERM;
    case KC_N_RA:
      return TAPPING_LAYER_TERM;
    default:
      return TAPPING_TERM;
  }
}

int RGB_current_mode;
bool process_record_user(uint16_t keycode, keyrecord_t *record) {

  bool result = false;
  switch (keycode) {
    case KANJI:
      if (record->event.pressed) {
        if (keymap_config.swap_lalt_lgui == false) {
          register_code(KC_LANG2);
        } else {
          SEND_STRING(SS_LALT("`"));
        }
      } else {
        unregister_code(KC_LANG2);
      }
      break;
    default:
      result = true;
      break;
  }

  return result;
}
