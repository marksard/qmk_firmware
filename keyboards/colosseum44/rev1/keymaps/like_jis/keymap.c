#include QMK_KEYBOARD_H
#include "bootloader.h"
#ifdef PROTOCOL_LUFA
  #include "lufa.h"
  #include "split_util.h"
#endif

extern keymap_config_t keymap_config;

#ifdef RGBLIGHT_ENABLE
//Following line allows macro to read current RGB settings
extern rgblight_config_t rgblight_config;
#endif

extern uint8_t is_master;

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
  LOWER = SAFE_RANGE,
  RAISE,
  ADJUST,
  KANJI,
  RGBRST
};

enum tapdances{
  TD_SCCL = 0,
  TD_SLRO,
};

// Layer Mode aliases
#define KC_LOWER LOWER
#define KC_RAISE RAISE

#define KC______ KC_TRNS
#define KC_XXXXX KC_NO
#define KC_KANJI KANJI

#define KC_RST   RESET
#define KC_LRST  RGBRST
#define KC_LTOG  RGB_TOG
#define KC_LHUI  RGB_HUI
#define KC_LHUD  RGB_HUD
#define KC_LSAI  RGB_SAI
#define KC_LSAD  RGB_SAD
#define KC_LVAI  RGB_VAI
#define KC_LVAD  RGB_VAD
#define KC_LMOD  RGB_MOD
#define KC_KNRM  AG_NORM
#define KC_KSWP  AG_SWAP

#define KC_TBSF  LSFT_T(KC_TAB)
#define KC_ALAP  LALT_T(KC_APP)

#define KC_SCCL  TD(TD_SCCL)
#define KC_SLRO  TD(TD_SLRO)

qk_tap_dance_action_t tap_dance_actions[] = {
  [TD_SCCL] = ACTION_TAP_DANCE_DOUBLE(KC_SCLN, KC_QUOT),
  [TD_SLRO] = ACTION_TAP_DANCE_DOUBLE(KC_SLSH, KC_RO),
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [_BASE] = LAYOUT_kc( \
  //,-----------------------------------------.                ,-----------------------------------------.
        ESC,     Q,     W,     E,     R,     T,                      Y,     U,     I,     O,     P,  MINS,\
  //|------+------+------+------+------+------|                |------+------+------+------+------+------|
       TBSF,     A,     S,     D,     F,     G,                      H,     J,     K,     L,  SCCL,   ENT,\
  //|------+------+------+------+------+------|                |------+------+------+------+------+------|
      LCTRL,     Z,     X,     C,     V,     B,                      N,     M,  COMM,   DOT,  SLSH,    RO,\
  //|------+------+------+------+------+------+------|  |------+------+------+------+------+------+------|
                            LGUI, LOWER,  BSPC,   ENT,     TBSF,   SPC, RAISE,  ALAP \
                        //`--------------------------'  `---------------------------'
  ),

  [_LOWER] = LAYOUT_kc( \
  //,-----------------------------------------.                ,-----------------------------------------.
      _____,    F1,    F2,    F3,    F4,    F5,                  XXXXX,  MINS,   EQL,  JYEN,  LBRC,  RBRC,\
  //|------+------+------+------+------+------|                |------+------+------+------+------+------|
      _____,    F6,    F7,    F8,    F9,   F10,                   LEFT,  DOWN,    UP,  RGHT,  QUOT,  BSLS,\
  //|------+------+------+------+------+------|                |------+------+------+------+------+------|
      _____,   F11,   F12,   TAB, KANJI,   ENT,                  XXXXX, XXXXX,  COMM,   DOT,  SLSH,    RO,\
  //|------+------+------+------+------+------+------|  |------+------+------+------+------+------+------|
                           _____, _____,   DEL, _____,    _____, _____, _____, _____ \
                        //`--------------------------'  `---------------------------'
  ),

  [_RAISE] = LAYOUT_kc( \
  //,-----------------------------------------.                ,-----------------------------------------.
      _____,     1,     2,     3,     4,     5,                      6,     7,     8,     9,     0,  PSLS,\
  //|------+------+------+------+------+------|                |------+------+------+------+------+------|
      _____, XXXXX, XXXXX, XXXXX, XXXXX, XXXXX,                   QUOT,     4,     5,     6,  PPLS,  PAST,\
  //|------+------+------+------+------+------|                |------+------+------+------+------+------|
      _____, XXXXX, XXXXX, XXXXX, XXXXX, XXXXX,                      0,     1,     2,     3,   DOT,  PMNS,\
  //|------+------+------+------+------+------+------|  |------+------+------+------+------+------+------|
                           _____, _____, _____, _____,    _____, _____, _____, _____ \
                        //`--------------------------'  `---------------------------'
  ),

  [_ADJUST] = LAYOUT_kc( \
  //,-----------------------------------------.                ,-----------------------------------------.
      _____,    RST,  LRST,  KNRM, KSWP, XXXXX,                  XXXXX, XXXXX, XXXXX, XXXXX, XXXXX, XXXXX,\
  //|------+-------+------+------+------+-----|                |------+------+------+------+------+------|
      _____,   LTOG,  LHUI,  LSAI, LVAI, XXXXX,                   HOME,  PGDN,  PGUP,   END, XXXXX, XXXXX,\
  //|------+-------+------+------+------+-----|                |------+------+------+------+------+------|
      _____,   LMOD,  LHUD,  LSAD, LVAD, XXXXX,                  XXXXX, XXXXX, XXXXX, XXXXX, XXXXX, XXXXX,\
  //|------+------+------+------+------+------+------|  |------+------+------+------+------+------+------|
                           _____, _____, _____, _____,    _____, _____, _____, _____ \
                        //`--------------------------'  `---------------------------'
  )
};

static inline void update_change_layer(bool pressed, uint8_t layer1, uint8_t layer2, uint8_t layer3) {

  pressed ? layer_on(layer1) : layer_off(layer1);
  IS_LAYER_ON(layer1) && IS_LAYER_ON(layer2) ? layer_on(layer3) : layer_off(layer3);
}

int RGB_current_mode;
bool process_record_user(uint16_t keycode, keyrecord_t *record) {

  bool result = false;
  switch (keycode) {
    case LOWER:
      update_change_layer(record->event.pressed, _LOWER, _RAISE, _ADJUST);
      break;
    case RAISE:
      update_change_layer(record->event.pressed, _RAISE, _LOWER, _ADJUST);
        break;
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
    #ifdef RGBLIGHT_ENABLE
      case RGB_MOD:
          if (record->event.pressed) {
            rgblight_mode(RGB_current_mode);
            rgblight_step();
            RGB_current_mode = rgblight_config.mode;
          }
        break;
      case RGBRST:
          if (record->event.pressed) {
            eeconfig_update_rgblight_default();
            rgblight_enable();
            RGB_current_mode = rgblight_config.mode;
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
  #ifdef RGBLIGHT_ENABLE
    RGB_current_mode = rgblight_config.mode;
  #endif
}
