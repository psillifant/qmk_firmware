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

// We define our keymap centrally so that multiple planck revisions can consume the basic keymap.
#include "../../peterdefaults/planck_1x2uC.c"

layer_state_t layer_state_set_user(layer_state_t state) {
  state = update_tri_layer_state(state, _TWO, _THREE, _ADMIN);
  state = update_tri_layer_state(state, _ONE, _TWO, _FNKEYS);
  switch (get_highest_layer(state)) {
    case _QWERTYPC:
        rgb_matrix_mode(RGB_MATRIX_CUSTOM_all_keys_white);
        break;
    // case _QWERTYMAC:
    //     rgblight_setrgb (RGB_BLUE);
    //     break;
    // case _SYMBOLS:
    //     rgblight_setrgb (RGB_ORANGE);
    //     break;
    // case _NUMBERS:
    //     rgblight_setrgb (RGB_GREEN);
    //     break;
    case _GAMES:
        rgb_matrix_mode(RGB_MATRIX_CUSTOM_layer_games);
        break;
    case _THREE:
        rgb_matrix_mode(RGB_MATRIX_CUSTOM_layer_three);
        break;
    case _ADMIN:
        rgb_matrix_mode(RGB_MATRIX_CUSTOM_all_keys_red);
        break;
    default: //  for any other layers, or the default layer
        rgb_matrix_mode(RGB_MATRIX_CUSTOM_all_keys_white);
        break;
    }
  return state;

};

void keyboard_post_init_user(void) {
  rgb_matrix_mode(RGB_MATRIX_CUSTOM_all_keys_white); 
};

