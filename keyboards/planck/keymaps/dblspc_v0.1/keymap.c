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

// #ifdef AUDIO_ENABLE
// #    include "muse.h"
// #endif

enum planck_layers {
  _QWERTYPC,
  _QWERTYMAC,
  _NUMBERS,
  _SYMBOLS,
  _EMOJI,
  _MEDIA,
  _MOVE,
  _GAMES,
  _BOOTLD,
  _LAYERNAVIGATION
};

enum planck_keycodes {
  QWERTY = SAFE_RANGE,
  BACKLIT
};

#define TG_QWER TO(_QWERTYPC)
#define TG_GAMS TO(_GAMES)
#define TG_PC TO(_QWERTYPC)
#define TG_MAC TO(_QWERTYMAC)
#define ME_PIPE S(KC_NUBS)
#define LY_MED LT(_MEDIA, ME_PIPE)
#define LY_MOVE LT(_MOVE, KC_BSLS)
#define LY_GAMS MO(_GAMES)
#define LY_SYMB MO(_SYMBOLS)
#define LY_NUMS MO(_NUMBERS)
#define LT_EMOJ LT(_EMOJI, KC_MINS)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

[_QWERTYPC] = LAYOUT_planck_2x2u(
    KC_TAB,    KC_Q,     KC_W,     KC_E,     KC_R,     KC_T,     KC_Y,     KC_U,     KC_I,     KC_O,     KC_P,     KC_BSPC,
    KC_GRAVE,  KC_A,     KC_S,     KC_D,     KC_F,     KC_G,     KC_H,     KC_J,     KC_K,     KC_L,     KC_SCLN,  KC_QUOT,
    KC_LSFT,   KC_Z,     KC_X,     KC_C,     KC_V,     KC_B,     KC_N,     KC_M,     KC_COMM,  KC_DOT,   KC_SLSH,  KC_ENT,
    KC_LCTL,   KC_LGUI,  KC_LALT,  LY_SYMB,  KC_SPC,             KC_SPC,             LY_NUMS,  LT_EMOJ,  LY_MED,   LY_MOVE
),

[_QWERTYMAC] = LAYOUT_planck_2x2u(
    KC_TAB,    KC_Q,     KC_W,     KC_E,     KC_R,     KC_T,     KC_Y,     KC_U,     KC_I,     KC_O,     KC_P,     KC_BSPC,
    KC_GRAVE,  KC_A,     KC_S,     KC_D,     KC_F,     KC_G,     KC_H,     KC_J,     KC_K,     KC_L,     KC_SCLN,  KC_QUOT,
    KC_LSFT,   KC_Z,     KC_X,     KC_C,     KC_V,     KC_B,     KC_N,     KC_M,     KC_COMM,  KC_DOT,   KC_SLSH,  KC_ENT,
    KC_LCTL,   KC_LALT,  KC_LGUI,  LY_SYMB,  KC_SPC,             KC_SPC,             LY_NUMS,  LT_EMOJ,  LY_MED,   LY_MOVE
),

[_SYMBOLS] = LAYOUT_planck_2x2u(
    KC_TILD,   KC_EXLM,  KC_AT,    KC_HASH,  KC_DLR,   KC_PERC,  KC_CIRC,  KC_AMPR,  KC_ASTR,  KC_MINS,  KC_EQL,   KC_BSPC,
    KC_DEL,    KC_F1,    KC_F2,    KC_F3,    KC_F4,    KC_F5,    KC_F6,    KC_UNDS,  KC_PLUS,  KC_LBRC,  KC_RBRC,  _______,
    _______,   KC_NUBS,  KC_F8,    KC_F9,    KC_F10,   KC_F11,   KC_F12,   KC_NO,    KC_NO,    KC_HOME,  KC_NUHS,  KC_NO,
    _______,   _______,  _______,  _______,  _______,            _______,            _______,  _______,  _______,  _______
),

[_NUMBERS] = LAYOUT_planck_2x2u(
    KC_GRV,    KC_1,     KC_2,     KC_3,     KC_4,     KC_5,     KC_6,     KC_7,     KC_8,     KC_9,     KC_0,     KC_BSPC,
    KC_NO,     KC_F1,    KC_F2,    KC_F3,    KC_F4,    KC_F5,    KC_F6,    KC_MINS,  KC_EQL,   KC_LBRC,  KC_RBRC,  KC_BSLS,
    _______,   KC_F7,    KC_F8,    KC_F9,    KC_F10,   KC_F11,   KC_F12,   KC_NUHS,  KC_NUBS,  KC_PGUP,  KC_PGDN,  KC_NO,
    _______,   _______,  _______,  _______,  _______,            _______,            _______,  _______,  _______,  _______
),

// LAYER KEY ONE
[_EMOJI] = LAYOUT_planck_2x2u(
    KC_NO,     KC_NO,    KC_NO,    KC_NO,    KC_NO,    KC_NO,    KC_NO,    KC_NO,    KC_NO,    KC_NO,    KC_NO,    KC_NO,
    KC_NO,     KC_NO,    KC_NO,    KC_NO,    KC_NO,    KC_NO,    KC_NO,    KC_NO,    KC_NO,    KC_NO,    KC_NO,    KC_NO,
    _______,   KC_NO,    KC_NO,    KC_NO,    KC_NO,    KC_NO,    KC_NO,    KC_NO,    KC_NO,    KC_NO,    KC_NO,    KC_NO,
    _______,   _______,  _______,  _______,  _______,            _______,            _______,  _______,  _______,  _______
),

// LAYER KEY TWO
[_MEDIA] = LAYOUT_planck_2x2u(
    KC_NO,     KC_NO,    KC_NO,    KC_NO,    KC_NO,    KC_NO,    KC_NO,    KC_NO,    KC_NO,    KC_NO,    KC_MPRV,  KC_VOLU,
    KC_NO,     KC_NO,    KC_MSTP,  KC_NO,    KC_NO,    KC_NO,    KC_NO,    KC_NO,    KC_NO,    KC_NO,    KC_NO,    KC_VOLD,
    _______,   KC_NO,    KC_NO,    KC_NO,    KC_NO,    KC_NO,    KC_MNXT,  KC_NO,    KC_MUTE,  KC_NO,    KC_NO,    KC_MUTE,
    _______,   _______,  _______,  _______,  KC_MPLY,            KC_MPLY,            _______,  _______,  _______,  _______
),
// LAYER KEY THREE
[_MOVE] = LAYOUT_planck_2x2u(
    KC_ESC,    KC_HOME,  KC_UP,    KC_END,   KC_NO,    KC_NO,    KC_NO,    KC_NO,    KC_NO,    KC_NO,    KC_HOME,  KC_DEL,
    KC_NO,     KC_LEFT,  KC_DOWN,  KC_RGHT,  KC_NO,    KC_NO,    KC_NO,    KC_NO,    KC_NO,    KC_NO,    KC_END,   KC_NO,
    _______,   KC_NO,    KC_NO,    KC_NO,    KC_NO,    KC_NO,    KC_NO,    KC_NO,    KC_NO,    KC_NO,    KC_NO,    KC_NO,
    _______,   _______,  _______,  _______,  _______,            _______,            _______,  _______,  _______,  _______
),

[_GAMES] = LAYOUT_planck_2x2u(
    KC_ESC,    KC_1,     KC_2,     KC_3,     KC_4,     KC_5,     KC_6,     KC_7,     KC_8,     KC_9,     KC_0,     KC_NO,
    KC_TAB,    KC_Q,     KC_W,     KC_E,     KC_R,     KC_NO,    KC_NO,    KC_NO,    KC_NO,    KC_NO,    KC_NO,    KC_NO,
    _______,   KC_A,     KC_S,     KC_D,     KC_F,     KC_NO,    KC_NO,    KC_NO,    KC_NO,    KC_NO,    KC_NO,    KC_NO,
    KC_LSFT,   KC_Z,     KC_X,     KC_C,     KC_SPC,             _______,            _______,  _______,  _______,  _______
),

[_BOOTLD] = LAYOUT_planck_2x2u(
    QK_BOOT,   KC_NO,    KC_NO,    KC_NO,    KC_NO,    KC_NO,    KC_NO,    KC_NO,    KC_NO,    KC_NO,    KC_NO,    KC_NO,
    KC_CAPS,   KC_NO,    KC_NO,    KC_NO,    KC_NO,    KC_NO,    KC_NO,    KC_NO,    KC_NO,    KC_NO,    KC_NO,    KC_NO,
    _______,   KC_NO,    KC_NO,    KC_NO,    KC_NO,    KC_NO,    KC_NO,    KC_NO,    KC_NO,    KC_NO,    KC_NO,    KC_NO,
    _______,   _______,  _______,  _______,  _______,            _______,            _______,  _______,  _______,  _______
),

[_LAYERNAVIGATION] = LAYOUT_planck_2x2u(
    KC_NO,     KC_NO,    KC_NO,    KC_NO,    KC_NO,    KC_NO,    KC_NO,    KC_NO,    KC_NO,    KC_NO,    KC_NO,    TG_PC,
    KC_NO,     KC_NO,    KC_NO,    KC_NO,    KC_NO,    KC_NO,    KC_NO,    KC_NO,    KC_NO,    KC_NO,    KC_NO,    TG_MAC,
    _______,   KC_NO,    KC_NO,    KC_NO,    KC_NO,    KC_NO,    KC_NO,    KC_NO,    KC_NO,    KC_NO,    KC_NO,    TG_GAMS,
    _______,   _______,  _______,  _______,  _______,            _______,            _______,  _______,  _______,  _______
),

// [_BLANK] = LAYOUT_planck_2x2u(
    // KC_NO,     KC_NO,    KC_NO,    KC_NO,    KC_NO,    KC_NO,    KC_NO,    KC_NO,    KC_NO,    KC_NO,    KC_NO,    KC_NO,
    // KC_NO,     KC_NO,    KC_NO,    KC_NO,    KC_NO,    KC_NO,    KC_NO,    KC_NO,    KC_NO,    KC_NO,    KC_NO,    KC_NO,
    // _______,   KC_NO,    KC_NO,    KC_NO,    KC_NO,    KC_NO,    KC_NO,    KC_NO,    KC_NO,    KC_NO,    KC_NO,    KC_NO,
    // _______,   _______,  _______,  _______,  _______,            _______,            _______,  _______,  _______,  _______
// ),

};

layer_state_t layer_state_set_user(layer_state_t state) {
  state = update_tri_layer_state(state, _SYMBOLS, _NUMBERS, _BOOTLD);
  state = update_tri_layer_state(state, _MEDIA, _MOVE, _LAYERNAVIGATION);
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
    case _BOOTLD:
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

// layer_state_tt layer_state_set_user(layer_state_t state) {
//     switch (get_highest_layer(state)) {
//     case _QWERTY:
//         rgblight_setrgb (0xFF,  0xFF, 0xFF);
//         break;
//     case _BOOTLD:
//         rgblight_setrgb (0xFF,  0x00, 0x00);
//         break;
//     default: //  for any other layers, or the default layer
//         rgblight_setrgb (0x00,  0xFF, 0xFF);
//         break;
//     }
//   return state;
// };


// const rgblight_segment_t PROGMEM my_test_layer[] = RGBLIGHT_LAYER_SEGMENTS(
//     {6, 4, HSV_RED},       // Light 4 LEDs, starting with LED 6
//     {12, 4, HSV_RED}       // Light 4 LEDs, starting with LED 12
// );

// const rgblight_segment_t* const PROGMEM my_rgb_layers[] = RGBLIGHT_LAYERS_LIST(
//     my_test_layer
// );

// void keyboard_post_init_user(void) {
//     // Enable the LED layers
//     rgblight_layers = my_rgb_layers;
// }

// layer_state_t default_layer_state_set_user(layer_state_t state) {
//     rgblight_set_layer_state(0, layer_state_cmp(state, _GREY));
//     return state;
// }