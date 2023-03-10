#pragma once

// place overrides here
#define TAPPING_TERM 190
#define IGNORE_MOD_TAP_INTERRUPT

#define TAPPING_LAYER_TERM 140 // Custom LT Tapping term
#define TAPPING_TERM_PER_KEY

#ifdef MOUSEKEY_ENABLE
  #undef MOUSEKEY_INTERVAL
  #define MOUSEKEY_INTERVAL 1
  #undef MOUSEKEY_TIME_TO_MAX
  #define MOUSEKEY_TIME_TO_MAX 150

  #undef MOUSEKEY_MAX_SPEED
  #define MOUSEKEY_MAX_SPEED 3

  #undef MOUSEKEY_MOVE_DELTA
  #define MOUSEKEY_MOVE_DELTA 4

  #undef MOUSEKEY_DELAY
  #define MOUSEKEY_DELAY 0
#endif
