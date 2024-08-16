/*
Copyright 2019 marksard

This program is free software: you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation, either version 2 of the License, or
(at your option) any later version.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/

#pragma once

/* USB Device descriptor parameter */
#define VENDOR_ID       0xFEED
#define PRODUCT_ID      0xDFA6
#define DEVICE_VER      0x0010
#define MANUFACTURER    marksard
#define PRODUCT         stoneaxe
#define DESCRIPTION     Japanese business card size ortholinear 30-Key Keyboard

/* key matrix size */
#define MATRIX_ROWS 6
#define MATRIX_COLS 5

/*
 * Keyboard Matrix Assignments
 *
 * Change this to how you wired your keyboard
 * COLS: AVR pins used for columns, left to right
 * ROWS: AVR pins used for rows, top to bottom
 * DIODE_DIRECTION: COL2ROW = COL = Anode (+), ROW = Cathode (-, marked on diode)
 *                  ROW2COL = ROW = Anode (+), COL = Cathode (-, marked on diode)
 *
*/
// #define MATRIX_ROW_PINS { D0, D5 }
// #define MATRIX_COL_PINS { F1, F0, B0 }
// #define UNUSED_PINS

/* COL2ROW, ROW2COL*/
// #define DIODE_DIRECTION COL2ROW

#define DIRECT_PINS { \
    { B5, B4, D7, D6, D4 }, \
    { F1, F4, D5, D1, D3 }, \
    { B0, B1, B2, B3, B7 }  \
}
#define UNUSED_PINS

/*
 * Split Keyboard specific options, make sure you have 'SPLIT_KEYBOARD = yes' in your rules.mk, and define SOFT_SERIAL_PIN.
 */
#define SOFT_SERIAL_PIN D0
#define SPLIT_HAND_PIN F7
#define SPLIT_USB_DETECT
#define SPLIT_USB_TIMEOUT 2000
#define SPLIT_USB_TIMEOUT_POLL 100

/* Debounce reduces chatter (unintended double-presses) - set 0 if debouncing is not needed */
#define DEBOUNCE 5
