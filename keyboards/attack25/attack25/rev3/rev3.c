#include "attack25.h"

void keyboard_pre_init_kb(void) {
  setPinOutput(LED_NLK);
}

#ifdef RGB_MATRIX_ENABLE
    #ifdef RGBLED_BOTH
        led_config_t g_led_config = { {
        // Key Matrix to LED Index
            { 0, 1, 2, 3, 4 },
            { 9, 8, 7, 6, 5 },
            { 10, 11, 12, 13, 14 },
            { 19, 18, 17, 16, 15 },
            { 20, 21, 22, 23, 24 },
        //    { NO_LED, NO_LED, NO_LED, NO_LED, NO_LED }
        }, {
        // LED Index to Physical Position
            {   0,   0 }, {  56,   0 }, { 112,   0 }, { 168,   0 }, { 224,   0 },
            { 224,  16 }, { 168,  16 }, { 112,  16 }, {  56,  16 }, {   0,  16 },
            {   0,  32 }, {  56,  32 }, { 112,  32 }, { 168,  32 }, { 224,  32 },
            { 224,  48 }, { 168,  48 }, { 112,  48 }, {  56,  48 }, {   0,  48 },
            {   0,  64 }, {  56,  64 }, { 112,  64 }, { 168,  64 }, { 224,  64 },
            {   0,   8 }, {   0,  60 }, { 112,  60 }, { 224,  60 }, { 224,   8 }
        }, {
        // LED Index to Flag
            4, 4, 4, 4, 4,
            4, 4, 4, 4, 4,
            4, 4, 4, 4, 4,
            4, 4, 4, 4, 4,
            4, 4, 4, 4, 4,
            2, 2, 2, 2, 2
        } };
    #else
        led_config_t g_led_config = { {
        // Key Matrix to LED Index
            { 0, 1, 2, 3, 4 },
            { 9, 8, 7, 6, 5 },
            { 10, 11, 12, 13, 14 },
            { 19, 18, 17, 16, 15 },
            { 20, 21, 22, 23, 24 }
        }, {
        // LED Index to Physical Position
            {   0,   0 }, {  56,   0 }, { 112,   0 }, { 168,   0 }, { 224,   0 },
            { 224,  16 }, { 168,  16 }, { 112,  16 }, {  56,  16 }, {   0,  16 },
            {   0,  32 }, {  56,  32 }, { 112,  32 }, { 168,  32 }, { 224,  32 },
            { 224,  48 }, { 168,  48 }, { 112,  48 }, {  56,  48 }, {   0,  48 },
            {   0,  64 }, {  56,  64 }, { 112,  64 }, { 168,  64 }, { 224,  64 }
        }, {
        // LED Index to Flag
            4, 4, 4, 4, 4,
            4, 4, 4, 4, 4,
            4, 4, 4, 4, 4,
            4, 4, 4, 4, 4,
            4, 4, 4, 4, 4
    } };
    #endif
#endif
