/* Copyright 2015-2021 Jack Humbert
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

#include QMK_KEYBOARD_H
#include "keymap_uk.h"

// #ifdef AUDIO_ENABLE
// #    include "muse.h"
// #endif

// We define our keymap centrally so that multiple planck revisions can consume the basic keymap.
#include "../../peterdefaults/planck_1x2uC.c"

layer_state_t layer_state_set_user(layer_state_t state) {
  state = update_tri_layer_state(state, _TWO, _THREE, _FNKEYS);
  state = update_tri_layer_state(state, _ONE, _TWO, _ADMIN);
  switch (get_highest_layer(state)) {
    case _QWERTYPC:
        rgblight_setrgb (RGB_WHITE);
        break;
    case _QWERTYMAC:
        rgblight_setrgb (RGB_BLUE);
        break;
    case _SYMBOLS:
        rgblight_setrgb (RGB_ORANGE);
        break;
    case _NUMBERS:
        rgblight_setrgb (RGB_GREEN);
        break;
    case _ADMIN:
        rgblight_setrgb (RGB_RED);
        break;
    default: //  for any other layers, or the default layer
        rgblight_setrgb (RGB_OFF);
        break;
    }
  return state;
};

// Sets the RGB Underglow to WHITE, once the board has finished all of its initialisation steps

void keyboard_post_init_user(void) {
  rgblight_setrgb (255, 255, 255);
};

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
    case MY_PIPE:
          SEND_STRING("|"); // Change the character(s) to be sent on tap here
      return false; // We handled this keypress
  }
  return true; // We didn't handle other keypresses
}