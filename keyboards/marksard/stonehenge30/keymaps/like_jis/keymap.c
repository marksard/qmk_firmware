#include QMK_KEYBOARD_H
#include "bootloader.h"
#ifdef PROTOCOL_LUFA
#include "lufa.h"
#endif
#ifdef SSD1306OLED
  #include "ssd1306.h"
#endif
#include "./common/oled_helper.h"

extern keymap_config_t keymap_config;

#ifdef RGBLIGHT_ENABLE
//Following line allows macro to read current RGB settings
extern rgblight_config_t rgblight_config;
#endif

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
  RGBRST = SAFE_RANGE,
  LOWER,
  RAISE,
  KANJI,
};

enum tapdances{
  TD_CODO = 0,
};

// Layer Mode aliases
// #define KC_LOWER LOWER
// #define KC_RAISE RAISE
// #define KC_MLLO  MO(_LOWER)
// #define KC_MLRA  MO(_RAISE)
#define KC_MLAD  MO(_ADJUST)

#define KC______ KC_TRNS
#define KC_XXXXX KC_NO
#define KC_KANJI KANJI

// Adjust layer keys
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

// Base layer mod tap
#define KC_A_SF  LSFT_T(KC_A)
#define KC_Z_CT  LCTL_T(KC_Z)
#define KC_X_AL  LALT_T(KC_X)
#define KC_C_GU  LGUI_T(KC_C)
#define KC_M_CT  LCTL_T(KC_M)
#define KC_ENSF  LSFT_T(KC_ENT)

// Lower layer mod tap
// #define KC_MNCT  LCTL_T(KC_MINS)

// Raise layer mod tap
#define KC_F6SF  LSFT_T(KC_F6)
#define KC_BSSF  LSFT_T(KC_BSLS)
#define KC_11CT  LCTL_T(KC_F11)
// #define KC_SSCT  LCTL_T(KC_SLSH)
#define KC_12AL  LALT_T(KC_F12)

// Layer tap
#define KC_SPLO  LT(_LOWER, KC_SPC)
#define KC_BSRA  LT(_RAISE, KC_BSPC)

// Tap dance
#define KC_CODO  TD(TD_CODO)

qk_tap_dance_action_t tap_dance_actions[] = {
  [TD_CODO] = ACTION_TAP_DANCE_DOUBLE(KC_COMM, KC_DOT),
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [_BASE] = LAYOUT_kc( \
  //,----------------------------------------------------------------------------.
          Q,     W,     E,     R,     T,  BSRA,     Y,     U,     I,     O,     P,\
  //|------+------+------+------+------|------|------+------+------+------+------|
       A_SF,     S,     D,     F,     G,            H,     J,     K,     L,  ENSF,\
  //|------+------+------+------+------|------|------+------+------+------+------|
       Z_CT,  X_AL,  C_GU,     V,     B,  SPLO,     N,  M_CT,  CODO \
  //|------+------+------+------+------|------|------+------+------|
  ),

  [_LOWER] = LAYOUT_kc( \
  //,----------------------------------------------------------------------------.
          1,     2,     3,     4,     5, _____,     6,     7,     8,     9,     0,\
  //|------+------+------+------+------|------|------+------+------+------+------|
       LSFT, XXXXX, XXXXX, XXXXX, XXXXX,         LEFT,  DOWN,    UP,  RGHT,  LSFT,\
  //|------+------+------+------+------|------|------+------+------+------+------|
       LCTL,  LALT,  LGUI, XXXXX, XXXXX, _____,  COMM,   DOT,  SLSH \
  //|------+------+------+------+------|------|------+------+------|
  ),

  [_RAISE] = LAYOUT_kc( \
  //,----------------------------------------------------------------------------.
         F1,    F2,    F3,    F4,    F5, _____,  MINS,   EQL,  JYEN,  LBRC,  RBRC,\
  //|------+------+------+------+------|------|------+------+------+------+------|
       F6SF,    F7,    F8,    F9,   F10,          DEL, XXXXX,  SCLN,  QUOT,  BSSF,\
  //|------+------+------+------+------|------|------+------+------+------+------|
       11CT,  12AL,   ESC,   TAB, KANJI,  MLAD, XXXXX,  SLSH,    RO \
  //|------+------+------+------+------|------|------+------+------|
  ),

  [_ADJUST] = LAYOUT_kc( \
  //,----------------------------------------------------------------------------.
        RST,  LRST,  KNRM,  KSWP, XXXXX, _____,  HOME,  PGDN,  PGUP,   END, XXXXX, \
  //|------+------+------+------+------|------|------+------+------+------+------|
       LTOG,  LHUI,  LSAI,  LVAI,  LVAD,         MS_L,  MS_D,  MS_U,  MS_R, XXXXX, \
  //|------+------+------+------+------|------|------+------+------+------+------|
       LMOD,  LHUD,  LSAD, _____, XXXXX, _____,  BTN1,  BTN2, XXXXX \
  //|------+------+------+------+------|------|------+------+------|
  )
};

#define L_BASE _BASE
#define L_LOWER (1<<_LOWER)
#define L_RAISE (1<<_RAISE)
#define L_ADJUST (1<<_ADJUST)
#define L_ADJUST_TRI (L_ADJUST|L_RAISE|L_LOWER)

#ifdef SSD1306OLED
typedef struct {
  uint8_t state;
  char name[8];
}LAYER_DISPLAY_NAME;

#define LAYER_DISPLAY_MAX 5
const LAYER_DISPLAY_NAME layer_display_name[LAYER_DISPLAY_MAX] = {
  {L_BASE, "Base"},
  {L_BASE + 1, "Base"},
  {L_LOWER, "Lower"},
  {L_RAISE, "Raise"},
  {L_ADJUST_TRI, "Adjust"}
};

static inline const char* get_leyer_status(void) {

  for (uint8_t i = 0; i < LAYER_DISPLAY_MAX; ++i) {
    if (layer_state == 0 && layer_display_name[i].state == default_layer_state) {

      return layer_display_name[i].name;
    } else if (layer_state != 0 && layer_display_name[i].state == layer_state) {

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

static inline void render_keymap_status(struct CharacterMatrix *matrix) {

  matrix_write(matrix, layer_status_buf);
}

#define UPDATE_KEYMAP_STATUS() update_keymap_status()
#define RENDER_KEYMAP_STATUS(a) render_keymap_status(a)

#else

#define UPDATE_KEYMAP_STATUS()
#define RENDER_KEYMAP_STATUS(a)

#endif

// static inline void update_change_layer(bool pressed, uint8_t layer1, uint8_t layer2, uint8_t layer3) {
//   pressed ? layer_on(layer1) : layer_off(layer1);
//   IS_LAYER_ON(layer1) && IS_LAYER_ON(layer2) ? layer_on(layer3) : layer_off(layer3);
// }

#define TAPPING_LAYER_TERM 150 // Custom LT Tapping term
uint16_t get_tapping_term(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
    case KC_SPLO:
      return TAPPING_LAYER_TERM;
    case KC_BSRA:
      return TAPPING_LAYER_TERM;
    default:
      return TAPPING_TERM;
  }
}

int RGB_current_mode;
bool process_record_user(uint16_t keycode, keyrecord_t *record) {

  UPDATE_KEY_STATUS(keycode, record);

  bool result = false;
  switch (keycode) {
    // // case KC_LOWER:
    // case KC_V_LO:
    //   update_change_layer(record->event.pressed, _LOWER, _RAISE, _ADJUST);
    //   return true;
    // // case KC_RAISE:
    // case KC_M_RA:
    //   update_change_layer(record->event.pressed, _RAISE, _LOWER, _ADJUST);
    //   return true;
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
      //led operations - RGB mode change now updates the RGB_current_mode to allow the right RGB mode to be set after reactive keys are released
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

  UPDATE_KEYMAP_STATUS();
  return result;
}

void matrix_init_user(void) {
  #ifdef RGBLIGHT_ENABLE
    RGB_current_mode = rgblight_config.mode;
  #endif
  //SSD1306 OLED init, make sure to add #define SSD1306OLED in config.h
  #ifdef SSD1306OLED
    iota_gfx_init(false); // turns on the display
  #endif
}

//SSD1306 OLED update loop, make sure to add #define SSD1306OLED in config.h
#ifdef SSD1306OLED

void matrix_scan_user(void) {
  iota_gfx_task();  // this is what updates the display continuously
}

static inline void matrix_update(struct CharacterMatrix *dest,
                          const struct CharacterMatrix *source) {
  if (memcmp(dest->display, source->display, sizeof(dest->display))) {
    memcpy(dest->display, source->display, sizeof(dest->display));
    dest->dirty = true;
  }
}

static inline void render_status(struct CharacterMatrix *matrix) {

  UPDATE_LED_STATUS();
  RENDER_LED_STATUS(matrix);
  RENDER_KEYMAP_STATUS(matrix);
  UPDATE_LOCK_STATUS();
  RENDER_LOCK_STATUS(matrix);
  RENDER_KEY_STATUS(matrix);
}

void iota_gfx_task_user(void) {
  struct CharacterMatrix matrix;

  #if DEBUG_TO_SCREEN
    if (debug_enable) {
      return;
    }
  #endif

  matrix_clear(&matrix);
  render_status(&matrix);

  matrix_update(&display, &matrix);
}

#endif
