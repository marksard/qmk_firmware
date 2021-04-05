/* Copyright 2019 marksard
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
#include "treadstone60.h"

// Optional override functions below.
// You can leave any or all of these undefined.
// These are only required if you want to perform custom actions.

#ifdef RGB_MATRIX_ENABLE
#define NLE NO_LED
led_config_t g_led_config = { {
    {  12,  11,  10,   9,   8,   7,   6,   5,   4,   3,   2,   1,   0 },
    {  13,  14,  15,  16,  17,  18,  19,  20,  21,  22,  23,  24,  25 },
    {  38,  37,  36,  35,  34,  33,  32,  31,  30,  29,  28,  27,  26 },
    {  39,  40,  41,  42,  43,  44,  45,  46,  47,  48,  49,  50,  51 },
    {  60,  59,  58,  57,  56, NLE, NLE, NLE,  56,  55,  54,  53,  52 }
}, { //               ^spl ^long/split         ^split
    { 225,   0 }, { 205,   0 }, { 186,   0 }, { 168,   0 }, { 149,   0 }, { 130,   0 }, { 112,   0 }, {  93,   0 }, {  74,   0 }, {  56,   0 }, {  37,   0 }, {  18,   0 }, {   0,   0 }, 
    {   0,  16 }, {  18,  16 }, {  37,  16 }, {  56,  16 }, {  74,  16 }, {  93,  16 }, { 112,  16 }, { 130,  16 }, { 149,  16 }, { 168,  16 }, { 186,  16 }, { 205,  16 }, { 225,  16 }, 
    { 225,  32 }, { 205,  32 }, { 186,  32 }, { 168,  32 }, { 149,  32 }, { 130,  32 }, { 112,  32 }, {  93,  32 }, {  74,  32 }, {  56,  32 }, {  37,  32 }, {  18,  32 }, {   0,  32 }, 
    {   0,  48 }, {  18,  48 }, {  37,  48 }, {  56,  48 }, {  74,  48 }, {  93,  48 }, { 112,  48 }, { 130,  48 }, { 149,  48 }, { 168,  48 }, { 186,  48 }, { 205,  48 }, { 225,  48 }, 
    { 225,  64 }, { 205,  64 }, { 186,  64 }, { 168,  64 },               { 130,  64 },                             {  74,  64 },               {  37,  64 }, {  18,  64 }, {   0,  64 }, 
}, {
    1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 4,
    4, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 4,
    4, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 4,
    4, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 4,
    4, 4, 4, 4, 1, 1, 4, 4, 4
} };
#endif

__attribute__((weak))
void matrix_init_user(void) {}

void matrix_init_kb(void) {
    matrix_init_user();
}
