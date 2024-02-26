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

enum planck_layers {
  _QWERTYPC,
  _QWERTYMAC,
  _NUMBERS,
  _SYMBOLS,
  _ONE,
  _TWO,
  _THREE,
  _GAMES,
  _SCROLL,
  _ADMIN
};

enum custom_keycodes {
  MY_PIPE = SAFE_RANGE
};

// Toggles, turn a layer on permanently
#define TG_GAMS TO(_GAMES)
#define TG_PC TO(_QWERTYPC)
#define TG_MAC TO(_QWERTYMAC)
#define TG_SCRL TO(_THREE)
#define LT_2PIPE LT(_TWO, KC_EQUAL)
#define SFT_ENT RSFT_T(KC_ENTER)
#define LT_3HASH LT(_THREE, KC_BSLS)
#define LY_GAMS MO(_GAMES)
#define LT_SYMB LT(_SYMBOLS, KC_NUBS)
#define LY_NUMS MO(_NUMBERS)
#define LT_1DASH LT(_ONE, KC_MINS)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

[_QWERTYPC] = LAYOUT_planck_1x2uR(
    KC_TAB,     KC_Q,      KC_W,      KC_E,      KC_R,      KC_T,      KC_Y,      KC_U,      KC_I,      KC_O,      KC_P,      KC_BSPC,
    KC_GRAVE,   KC_A,      KC_S,      KC_D,      KC_F,      KC_G,      KC_H,      KC_J,      KC_K,      KC_L,      KC_SCLN,   KC_QUOT,
    KC_LSFT,    KC_Z,      KC_X,      KC_C,      KC_V,      KC_B,      KC_N,      KC_M,      KC_COMM,   KC_DOT,    KC_SLSH,   SFT_ENT,
    KC_LCTL,    KC_LGUI,   KC_LALT,   LT_SYMB,   KC_LBRC,   KC_RBRC,   KC_SPC,               LY_NUMS,   LT_1DASH,  LT_2PIPE,  LT_3HASH
),

[_QWERTYMAC] = LAYOUT_planck_1x2uR(
    KC_TAB,     KC_Q,      KC_W,      KC_E,      KC_R,      KC_T,      KC_Y,      KC_U,      KC_I,      KC_O,      KC_P,      KC_BSPC,
    KC_GRAVE,   KC_A,      KC_S,      KC_D,      KC_F,      KC_G,      KC_H,      KC_J,      KC_K,      KC_L,      KC_SCLN,   KC_QUOT,
    KC_LSFT,    KC_Z,      KC_X,      KC_C,      KC_V,      KC_B,      KC_N,      KC_M,      KC_COMM,   KC_DOT,    KC_SLSH,   SFT_ENT,
    KC_LCTL,    KC_LALT,   KC_LGUI,   LT_SYMB,   KC_LBRC,   KC_RBRC,   KC_SPC,               LY_NUMS,   LT_1DASH,  LT_2PIPE,  LT_3HASH
),

[_SYMBOLS] = LAYOUT_planck_1x2uR(
    KC_NO,      KC_NO,     KC_NO,     KC_NO,     KC_NO,     KC_NO,     KC_NO,     KC_NO,     KC_NO,     KC_LBRC,   KC_RBRC,   _______,
    KC_F1,      KC_F2,     KC_F3,     KC_F4,     KC_F5,     KC_F6,     KC_F7,     KC_F8,     KC_F9,     KC_F10,    KC_F11,    KC_F12,
    _______,    UK_PIPE,   KC_NO,     KC_NO,     KC_NO,     KC_NO,     KC_NO,     KC_NO,     KC_NO,     KC_NO,     KC_NO,     KC_NO,
    _______,    _______,   _______,   _______,   _______,   _______,   _______,              _______,   _______,   _______,   _______
),

[_NUMBERS] = LAYOUT_planck_1x2uR(
    KC_GRV,     KC_1,      KC_2,      KC_3,      KC_4,      KC_5,      KC_6,      KC_7,      KC_8,      KC_9,      KC_0,      _______,
    KC_NO,      KC_NO,     KC_NO,     KC_NO,     KC_NO,     KC_NO,     KC_NO,     KC_NO,     KC_NO,     KC_NO,     KC_NO,     KC_NO,
    _______,    KC_NO,     KC_NO,     KC_NO,     KC_NO,     KC_NO,     KC_NO,     KC_NO,     KC_NO,     KC_NO,     KC_NO,     KC_NO,
    _______,    _______,   _______,   _______,   _______,   _______,   _______,              _______,   _______,   _______,   _______
),

// LAYER: ONE - Nothing yet.
[_ONE] = LAYOUT_planck_1x2uR(
    KC_NO,      KC_NO,     KC_NO,     KC_NO,     KC_NO,     KC_NO,     KC_NO,     KC_NO,     KC_NO,     KC_NO,     KC_NO,     KC_NO,
    KC_NO,      KC_NO,     KC_NO,     KC_NO,     KC_NO,     KC_NO,     KC_NO,     KC_NO,     KC_NO,     KC_NO,     KC_NO,     KC_NO,
    _______,    KC_NO,     KC_NO,     KC_NO,     KC_NO,     KC_NO,     KC_NO,     KC_NO,     KC_NO,     KC_NO,     KC_NO,     KC_NO,
    _______,    _______,   _______,   _______,   _______,   _______,   _______,              _______,   _______,   _______,   _______
),

// LAYER: TWO - Media Controls
[_TWO] = LAYOUT_planck_1x2uR(
    KC_NO,      KC_NO,     KC_NO,     KC_NO,     KC_NO,     KC_NO,     KC_NO,     KC_NO,     KC_NO,     KC_NO,     KC_MPRV,   KC_VOLU,
    KC_NO,      KC_NO,     KC_MSTP,   KC_NO,     KC_NO,     KC_NO,     KC_NO,     KC_NO,     KC_NO,     KC_NO,     KC_NO,     KC_VOLD,
    _______,    KC_NO,     KC_NO,     KC_NO,     KC_NO,     KC_NO,     KC_MNXT,   KC_NO,     KC_MUTE,   KC_NO,     KC_NO,     KC_MUTE,
    _______,    _______,   _______,   _______,   _______,   _______,   KC_MPLY,              _______,   _______,   _______,   _______
),
// LAYER: THREE - Arrows, ESC and other movement
[_THREE] = LAYOUT_planck_1x2uR(
    KC_ESC,     KC_HOME,   KC_UP,     KC_END,    KC_NO,     KC_NO,     KC_NO,     KC_NO,     KC_NO,     KC_NO,     KC_HOME,   KC_DEL,
    KC_NO,      KC_LEFT,   KC_DOWN,   KC_RGHT,   KC_NO,     KC_NO,     KC_NO,     KC_NO,     KC_NO,     KC_NO,     KC_END,    KC_NO,
    _______,    KC_NO,     KC_NO,     KC_NO,     KC_NO,     KC_NO,     KC_NO,     KC_NO,     KC_NO,     KC_NO,     KC_NO,     KC_NO,
    _______,    _______,   _______,   _______,   _______,   _______,   _______,              _______,   _______,   _______,   _______
),

// Layer: Games - Roughly a 1 row offset to allow the numbers to be included by default.  HASH symbol on the right as I've got used 
// to mapping that to quicksave.
[_GAMES] = LAYOUT_planck_1x2uR(
    KC_ESC,     KC_1,      KC_2,      KC_3,      KC_4,      KC_5,      KC_6,      KC_7,      KC_8,      KC_9,      KC_0,      KC_NO,
    KC_TAB,     KC_Q,      KC_W,      KC_E,      KC_R,      KC_NO,     KC_NO,     KC_NO,     KC_NO,     KC_NO,     KC_NO,     KC_BSLS,
    _______,    KC_A,      KC_S,      KC_D,      KC_F,      KC_NO,     KC_NO,     KC_NO,     KC_NO,     KC_NO,     KC_NO,     KC_NO,
    KC_LSFT,    KC_Z,      KC_X,      KC_C,      KC_SPC,    KC_SPC,    KC_SPC,               _______,   _______,   _______,   _______
),

// Layer: Bootloader - Provides access to the bootloader and Caps Lock, both keys only to be used as an exception.
// Invoked by the layer_state_set_user in-built function, and the update_tri_layer_state function called within that.
[_ADMIN] = LAYOUT_planck_1x2uR(
    QK_BOOT,    KC_NO,     KC_NO,     KC_NO,     KC_NO,     KC_NO,     KC_NO,     KC_NO,     KC_NO,     KC_NO,     TG_SCRL,   TG_PC,
    KC_CAPS,    KC_NO,     KC_NO,     KC_NO,     KC_NO,     KC_NO,     KC_NO,     KC_NO,     KC_NO,     KC_NO,     KC_NO,     TG_MAC,
    _______,    KC_NO,     KC_NO,     KC_NO,     KC_NO,     KC_NO,     KC_NO,     KC_NO,     KC_NO,     KC_NO,     KC_NO,     TG_GAMS,
    _______,    _______,   _______,   _______,   _______,   _______,   _______,              _______,   _______,   _______,   _______
),

// Layer: To be used as a template for new layers
// [_BLANK] = LAYOUT_planck_1x2uR(
   // KC_NO,      KC_NO,     KC_NO,     KC_NO,     KC_NO,     KC_NO,     KC_NO,     KC_NO,     KC_NO,     KC_NO,     KC_NO,     KC_NO,
    // KC_NO,      KC_NO,     KC_NO,     KC_NO,     KC_NO,     KC_NO,     KC_NO,     KC_NO,     KC_NO,     KC_NO,     KC_NO,     KC_NO,
    // _______,    KC_NO,     KC_NO,     KC_NO,     KC_NO,     KC_NO,     KC_NO,     KC_NO,     KC_NO,     KC_NO,     KC_NO,     KC_NO,
    // _______,    _______,   _______,   _______,   _______,   _______,   _______,              _______,   _______,   _______,   _______
// ),

};

layer_state_t layer_state_set_user(layer_state_t state) {
  state = update_tri_layer_state(state, _ONE, _NUMBERS, _ADMIN);
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