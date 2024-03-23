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
#include "../../peterdefaults/planck_2x2u.c"

// Sets the RGB Underglow to WHITE, once the board has finished all of its initialisation steps

void keyboard_post_init_user(void) {
  rgblight_setrgb (255, 255, 255);
};