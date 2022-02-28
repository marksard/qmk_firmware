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

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [_BASE] = LAYOUT_ortho_3x10(
  //,---------------------------------------------------------------------------------------------------.
  MI_C_4,  MI_C_3,  MI_C_3,  MI_C_3,  MI_C_3,  MI_C_3,  MI_C_4,  MI_C_3,  MI_C_3,  MI_C_3,
  //|---------+---------+---------+---------+---------+---------+---------+---------+---------+---------|
  MI_C_3,  MI_C_3,  MI_C_4,  MI_C_3,  MI_C_3,  MI_C_3,  MI_C_3,  MI_C_3,  MI_C_4,  MI_C_3,
  //|---------+---------+---------+---------+---------+---------+---------+---------+---------+---------|
  MI_C_3,  MI_C_3,  MI_C_3,  MI_C_3,  MI_C_4,  MI_C_3,  MI_C_3,  MI_C_3,  MI_C_3,  MI_C_3
  //`---------+---------+---------+---------+---------+---------+---------+---------+---------+---------'
  ),

  [_LOWER] = LAYOUT_ortho_3x10(
  //,---------------------------------------------------------------------------------------------------.
  MI_C_3,  MI_C_3,  MI_C_3,  MI_C_3,  MI_C_3,  MI_C_3,  MI_C_3,  MI_C_3,  MI_C_3,  MI_C_3,
  //|---------+---------+---------+---------+---------+---------+---------+---------+---------+---------|
  MI_C_3,  MI_C_3,  MI_C_3,  MI_C_3,  MI_C_3,  MI_C_3,  MI_C_3,  MI_C_3,  MI_C_3,  MI_C_3,
  //|---------+---------+---------+---------+---------+---------+---------+---------+---------+---------|
  MI_C_3,  MI_C_3,  MI_C_3,  MI_C_3,  MI_C_3,  MI_C_3,  MI_C_3,  MI_C_3,  MI_C_3,  MI_C_3
  //`---------+---------+---------+---------+---------+---------+---------+---------+---------+---------'
  ),

  [_RAISE] = LAYOUT_ortho_3x10(
  //,---------------------------------------------------------------------------------------------------.
  MI_C_3,  MI_C_3,  MI_C_3,  MI_C_3,  MI_C_3,  MI_C_3,  MI_C_3,  MI_C_3,  MI_C_3,  MI_C_3,
  //|---------+---------+---------+---------+---------+---------+---------+---------+---------+---------|
  MI_C_3,  MI_C_3,  MI_C_3,  MI_C_3,  MI_C_3,  MI_C_3,  MI_C_3,  MI_C_3,  MI_C_3,  MI_C_3,
  //|---------+---------+---------+---------+---------+---------+---------+---------+---------+---------|
  MI_C_3,  MI_C_3,  MI_C_3,  MI_C_3,  MI_C_3,  MI_C_3,  MI_C_3,  MI_C_3,  MI_C_3,  MI_C_3
  //`---------+---------+---------+---------+---------+---------+---------+---------+---------+---------'
  ),

  [_ADJUST] = LAYOUT_ortho_3x10(
  //,---------------------------------------------------------------------------------------------------.
  MI_C_3,  MI_C_3,  MI_C_3,  MI_C_3,  MI_C_3,  MI_C_3,  MI_C_3,  MI_C_3,  MI_C_3,  MI_C_3,
  //|---------+---------+---------+---------+---------+---------+---------+---------+---------+---------|
  MI_C_3,  MI_C_3,  MI_C_3,  MI_C_3,  MI_C_3,  MI_C_3,  MI_C_3,  MI_C_3,  MI_C_3,  MI_C_3,
  //|---------+---------+---------+---------+---------+---------+---------+---------+---------+---------|
  MI_C_3,  MI_C_3,  MI_C_3,  MI_C_3,  MI_C_3,  MI_C_3,  MI_C_3,  MI_C_3,  MI_C_3,  MI_C_3
  //`---------+---------+---------+---------+---------+---------+---------+---------+---------+---------'
  )
};

// Initial velocity value (avoid using 127 since it is used as a special number in some sound sources.)
#define MIDI_INITIAL_VELOCITY 117

// Used to set octave to MI_OCT_0
extern midi_config_t midi_config;

void keyboard_post_init_user(void) {
    //  Set otave to MI_OCT_0
    midi_config.octave = MI_OCT_N1 - MIDI_OCTAVE_MIN;
}
