/* Copyright 2019 Thomas Baart <thomas@splitkb.com>
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

#pragma once

#ifdef RGBLIGHT_ENABLE
#    define RGBLIGHT_EFFECT_BREATHING
#    define RGBLIGHT_EFFECT_RAINBOW_MOOD
#    define RGBLIGHT_EFFECT_RAINBOW_SWIRL
#    define RGBLIGHT_EFFECT_SNAKE
#    define RGBLIGHT_EFFECT_KNIGHT
#    define RGBLIGHT_EFFECT_STATIC_GRADIENT
#    define RGBLIGHT_HUE_STEP  8
#    define RGBLIGHT_SAT_STEP  8
#    define RGBLIGHT_VAL_STEP  8
#    define RGBLIGHT_LIMIT_VAL 150
#endif

// Configure the global tapping term (default: 200ms)
#define TAPPING_TERM 200

// Disables double tap hold auto-repeat on the keys selected in get_quick_tap_term.
#define QUICK_TAP_TERM_PER_KEY

#define PERMISSIVE_HOLD_PER_KEY

// This will make each halve know if it's left or right so you can connect any of the 2 halves
// For Compiling
// Elite-C: qmk flash -kb splitkb/kyria/rev1 -km nieldm -bl dfu-split-left
// ProMicro: qmk flash -kb splitkb/kyria/rev1 -km nieldm -bl avrdude-split-right
#define EE_HANDS

// VIA / Remappr: expose all 6 layers
#define DYNAMIC_KEYMAP_LAYER_COUNT 6

// If you are using an Elite C rev3 on the slave side, uncomment the lines below:
// #define SPLIT_USB_DETECT
// #define NO_USB_STARTUP_CHECK
