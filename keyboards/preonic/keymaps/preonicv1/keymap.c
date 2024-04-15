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
// #include "muse.h"

enum preonic_layers {
  _QWERTYPC,
  _QWERTYMAC,
  _NUMBERS,
  _SYMBOLS,
  _ONE,
  _TWO,
  _THREE,
  _FNKEYS,
  _GAMES,
  _SCROLL,
  _ADMIN
};

// enum preonic_keycodes {
//   QWERTY = SAFE_RANGE,
//   COLEMAK,
//   DVORAK,
//   LOWER,
//   RAISE,
//   BACKLIT
// };

// Toggles, turn a layer on permanently
#define TG_GAMS TO(_GAMES)
#define TG_PC TO(_QWERTYPC)
#define TG_MAC TO(_QWERTYMAC)
#define TG_SCRL TO(_THREE)

// Layer Holds
#define LT_1DASH LT(_ONE, KC_MINS)
#define LT_2PIPE LT(_TWO, KC_EQUAL)
#define LT_3HASH LT(_THREE, KC_BSLS)

// Redefines for Enter and Space
#define SFT_ENT RSFT_T(KC_ENTER)
#define LEFT_SPC LT(_NUMBERS, KC_SPC)
#define RGHT_SPC LT(_SYMBOLS, KC_SPC)

// i3 Shortcuts
#define i3_UP LGUI(KC_L)
#define i3_DOWN LGUI(KC_K)
#define i3_LEFT LGUI(KC_J)
#define i3_RGHT LGUI(KC_SCLN)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

/* Qwerty
 * ,-----------------------------------------------------------------------------------.
 * |   `  |   1  |   2  |   3  |   4  |   5  |   6  |   7  |   8  |   9  |   0  | Bksp |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | Tab  |   Q  |   W  |   E  |   R  |   T  |   Y  |   U  |   I  |   O  |   P  | Del  |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * | Esc  |   A  |   S  |   D  |   F  |   G  |   H  |   J  |   K  |   L  |   ;  |  "   |
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * | Shift|   Z  |   X  |   C  |   V  |   B  |   N  |   M  |   ,  |   .  |   /  |Enter |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | Brite| Ctrl | Alt  | GUI  |Lower |    Space    |Raise | Left | Down |  Up  |Right |
 * `-----------------------------------------------------------------------------------'
 */
[_QWERTYPC] = LAYOUT_preonic_2x2u(
    KC_ESC,     KC_1,      KC_2,      KC_3,      KC_4,      KC_5,      KC_6,      KC_7,      KC_8,      KC_9,      KC_0,      KC_BSPC,
    KC_TAB,     KC_Q,      KC_W,      KC_E,      KC_R,      KC_T,      KC_Y,      KC_U,      KC_I,      KC_O,      KC_P,      KC_BSPC,
    KC_GRAVE,   KC_A,      KC_S,      KC_D,      KC_F,      KC_G,      KC_H,      KC_J,      KC_K,      KC_L,      KC_SCLN,   KC_QUOT,
    KC_LSFT,    KC_Z,      KC_X,      KC_C,      KC_V,      KC_B,      KC_N,      KC_M,      KC_COMM,   KC_DOT,    KC_SLSH,   SFT_ENT,
    KC_LCTL,    KC_LGUI,   KC_LALT,   KC_LBRC,   LEFT_SPC,             RGHT_SPC,             KC_RBRC,   LT_1DASH,  LT_2PIPE,  LT_3HASH
),

[_QWERTYMAC] = LAYOUT_preonic_2x2u(
    KC_ESC,     KC_1,      KC_2,      KC_3,      KC_4,      KC_5,      KC_6,      KC_7,      KC_8,      KC_9,      KC_0,      KC_BSPC,
    KC_TAB,     KC_Q,      KC_W,      KC_E,      KC_R,      KC_T,      KC_Y,      KC_U,      KC_I,      KC_O,      KC_P,      KC_BSPC,
    KC_GRAVE,   KC_A,      KC_S,      KC_D,      KC_F,      KC_G,      KC_H,      KC_J,      KC_K,      KC_L,      KC_SCLN,   KC_QUOT,
    KC_LSFT,    KC_Z,      KC_X,      KC_C,      KC_V,      KC_B,      KC_N,      KC_M,      KC_COMM,   KC_DOT,    KC_SLSH,   SFT_ENT,
    KC_LCTL,    KC_LALT,   KC_LGUI,   KC_LBRC,   LEFT_SPC,             RGHT_SPC,             KC_RBRC,   LT_1DASH,  LT_2PIPE,  LT_3HASH
),

[_SYMBOLS] = LAYOUT_preonic_2x2u(
    _______,    _______,   _______,   _______,   _______,   _______,   _______,   _______,   _______,   _______,   _______,   _______,
    KC_NO,      KC_NO,     KC_NO,     KC_NO,     KC_NO,     KC_NO,     KC_NO,     KC_NO,     KC_NO,     KC_NO,     KC_NO,     _______,
    KC_NO,      KC_EXLM,   KC_AT,     KC_HASH,   KC_DLR,    KC_PERC,   KC_CIRC,   KC_AMPR,   KC_ASTR,   KC_LPRN,   KC_RPRN,   _______,
    _______,    KC_NUBS,   KC_NO,     KC_NO,     KC_NO,     KC_NO,     KC_NO,     KC_NO,     KC_COMM,   KC_DOT,    KC_SLSH,   _______,
    _______,    _______,   _______,   _______,   _______,              _______,              _______,   _______,   _______,   _______
),

[_NUMBERS] = LAYOUT_preonic_2x2u(
    _______,    _______,   _______,   _______,   _______,   _______,   _______,   _______,   _______,   _______,   _______,   _______,
    KC_GRV,     KC_NO,     KC_NO,     KC_NO,     KC_NO,     KC_NO,     KC_NO,     KC_NO,     KC_NO,     KC_NO,     KC_NO,     _______,
    KC_NO,      KC_1,      KC_2,      KC_3,      KC_4,      KC_5,      KC_6,      KC_7,      KC_8,      KC_9,      KC_0,      _______,
    _______,    KC_NO,     KC_NO,     KC_NO,     KC_NO,     KC_NO,     KC_NO,     KC_NO,     KC_COMM,   KC_DOT,    KC_SLSH,   _______,
    _______,    _______,   _______,   _______,   _______,              _______,              _______,   _______,   _______,   _______
),

// LAYER: ONE - Nothing yet.
[_ONE] = LAYOUT_preonic_2x2u(
    _______,    _______,   _______,   _______,   _______,   _______,   _______,   _______,   _______,   _______,   _______,   _______,
    KC_NO,      KC_NO,     i3_UP,     KC_NO,     KC_NO,     KC_NO,     KC_NO,     KC_NO,     KC_NO,     KC_NO,     KC_NO,     KC_NO,
    KC_NO,      i3_LEFT,   i3_DOWN,   i3_RGHT,   KC_NO,     KC_NO,     KC_NO,     KC_NO,     KC_NO,     KC_NO,     KC_NO,     KC_NO,
    _______,    KC_NO,     KC_NO,     KC_NO,     KC_NO,     KC_NO,     KC_NO,     KC_NO,     KC_NO,     KC_NO,     KC_NO,     KC_NO,
    _______,    _______,   _______,   _______,   _______,              _______,              _______,   _______,   _______,   _______
),

// LAYER: TWO - Media Controls
[_TWO] = LAYOUT_preonic_2x2u(
    _______,    _______,   _______,   _______,   _______,   _______,   _______,   _______,   _______,   _______,   _______,   _______,
    KC_NO,      KC_NO,     KC_NO,     KC_NO,     KC_NO,     KC_NO,     KC_NO,     KC_NO,     KC_NO,     KC_NO,     KC_MPRV,   KC_VOLU,
    KC_NO,      KC_NO,     KC_MSTP,   KC_NO,     KC_NO,     KC_NO,     KC_NO,     KC_NO,     KC_NO,     KC_NO,     KC_NO,     KC_VOLD,
    _______,    KC_NO,     KC_NO,     KC_NO,     KC_NO,     KC_NO,     KC_MNXT,   KC_NO,     KC_MUTE,   KC_NO,     KC_NO,     KC_MUTE,
    _______,    _______,   _______,   _______,   KC_MPLY,              KC_MPLY,              _______,   _______,   _______,   _______
),
// LAYER: THREE - Arrows, ESC and other movement
[_THREE] = LAYOUT_preonic_2x2u(
    _______,    _______,   _______,   _______,   _______,   _______,   _______,   _______,   _______,   _______,   _______,   _______,
    KC_ESC,     C(KC_LEFT),KC_UP,     C(KC_RGHT),KC_NO,     KC_NO,     KC_NO,     KC_NO,     KC_NO,     KC_NO,     KC_HOME,   KC_DEL,
    KC_NO,      KC_LEFT,   KC_DOWN,   KC_RGHT,   KC_NO,     KC_NO,     KC_NO,     KC_NO,     KC_NO,     KC_NO,     KC_END,    KC_NO,
    _______,    KC_HOME,   KC_NO,     KC_END,    KC_NO,     KC_NO,     KC_NO,     KC_NO,     KC_NO,     KC_NO,     KC_NO,     KC_NO,
    _______,    _______,   _______,   _______,   _______,              _______,              _______,   _______,   _______,   _______
),

// Layer: To be used as a template for new layers
[_FNKEYS] = LAYOUT_preonic_2x2u(
    _______,    _______,   _______,   _______,   _______,   _______,   _______,   _______,   _______,   _______,   _______,   _______,
    KC_F1,      KC_F2,     KC_F3,     KC_F4,     KC_F5,     KC_F6,     KC_F7,     KC_F8,     KC_F9,     KC_F10,    KC_F11,    KC_F12,
    KC_NO,      KC_NO,     KC_NO,     KC_NO,     KC_NO,     KC_NO,     KC_NO,     KC_NO,     KC_NO,     KC_NO,     KC_NO,     KC_NO,
    _______,    KC_NO,     KC_NO,     KC_NO,     KC_NO,     KC_NO,     KC_NO,     KC_NO,     KC_NO,     KC_NO,     KC_NO,     KC_NO,
    _______,    _______,   _______,   _______,   _______,              _______,              _______,   _______,   _______,   _______
),

// Layer: Bootloader - Provides access to the bootloader and Caps Lock, both keys only to be used as an exception.
// Invoked by the layer_state_set_user in-built function, and the update_tri_layer_state function called within that.
[_ADMIN] = LAYOUT_preonic_2x2u(
    QK_BOOT,    _______,   _______,   _______,   _______,   _______,   _______,   _______,   _______,   _______,   _______,   _______,
    QK_BOOT,    KC_NO,     KC_NO,     KC_NO,     KC_NO,     KC_NO,     KC_NO,     KC_NO,     KC_NO,     KC_NO,     TG_SCRL,   TG_PC,
    KC_CAPS,    KC_NO,     KC_NO,     KC_NO,     KC_NO,     KC_NO,     KC_NO,     KC_NO,     KC_NO,     KC_NO,     KC_NO,     TG_MAC,
    _______,    KC_NO,     KC_NO,     KC_NO,     KC_NO,     KC_NO,     KC_NO,     KC_NO,     KC_NO,     KC_NO,     KC_NO,     TG_GAMS,
    RGB_TOG,    _______,   _______,   _______,   _______,              _______,              _______,   _______,   _______,   _______
)

};


layer_state_t layer_state_set_user(layer_state_t state) {
  state = update_tri_layer_state(state, _TWO, _THREE, _FNKEYS);
  state = update_tri_layer_state(state, _ONE, _TWO, _ADMIN);
  return state;
};



// bool process_record_user(uint16_t keycode, keyrecord_t *record) {
//   switch (keycode) {
//         case QWERTY:
//           if (record->event.pressed) {
//             set_single_persistent_default_layer(_QWERTY);
//           }
//           return false;
//           break;
//         case COLEMAK:
//           if (record->event.pressed) {
//             set_single_persistent_default_layer(_COLEMAK);
//           }
//           return false;
//           break;
//         case DVORAK:
//           if (record->event.pressed) {
//             set_single_persistent_default_layer(_DVORAK);
//           }
//           return false;
//           break;
//         case LOWER:
//           if (record->event.pressed) {
//             layer_on(_LOWER);
//             update_tri_layer(_LOWER, _RAISE, _ADJUST);
//           } else {
//             layer_off(_LOWER);
//             update_tri_layer(_LOWER, _RAISE, _ADJUST);
//           }
//           return false;
//           break;
//         case RAISE:
//           if (record->event.pressed) {
//             layer_on(_RAISE);
//             update_tri_layer(_LOWER, _RAISE, _ADJUST);
//           } else {
//             layer_off(_RAISE);
//             update_tri_layer(_LOWER, _RAISE, _ADJUST);
//           }
//           return false;
//           break;
//         case BACKLIT:
//           if (record->event.pressed) {
//             register_code(KC_RSFT);
//             #ifdef BACKLIGHT_ENABLE
//               backlight_step();
//             #endif
//             #ifdef RGBLIGHT_ENABLE
//               rgblight_step();
//             #endif
//             #ifdef __AVR__
//             writePinLow(E6);
//             #endif
//           } else {
//             unregister_code(KC_RSFT);
//             #ifdef __AVR__
//             writePinHigh(E6);
//             #endif
//           }
//           return false;
//           break;
//       }
//     return true;
// };

// bool muse_mode = false;
// uint8_t last_muse_note = 0;
// uint16_t muse_counter = 0;
// uint8_t muse_offset = 70;
// uint16_t muse_tempo = 50;

// bool encoder_update_user(uint8_t index, bool clockwise) {
//   if (muse_mode) {
//     if (IS_LAYER_ON(_RAISE)) {
//       if (clockwise) {
//         muse_offset++;
//       } else {
//         muse_offset--;
//       }
//     } else {
//       if (clockwise) {
//         muse_tempo+=1;
//       } else {
//         muse_tempo-=1;
//       }
//     }
//   } else {
//     if (clockwise) {
//       register_code(KC_PGDN);
//       unregister_code(KC_PGDN);
//     } else {
//       register_code(KC_PGUP);
//       unregister_code(KC_PGUP);
//     }
//   }
//     return true;
// }

// bool dip_switch_update_user(uint8_t index, bool active) {
//     switch (index) {
//         case 0:
//             if (active) {
//                 layer_on(_ADJUST);
//             } else {
//                 layer_off(_ADJUST);
//             }
//             break;
//         case 1:
//             if (active) {
//                 muse_mode = true;
//             } else {
//                 muse_mode = false;
//             }
//     }
//     return true;
// }


// void matrix_scan_user(void) {
// #ifdef AUDIO_ENABLE
//     if (muse_mode) {
//         if (muse_counter == 0) {
//             uint8_t muse_note = muse_offset + SCALE[muse_clock_pulse()];
//             if (muse_note != last_muse_note) {
//                 stop_note(compute_freq_for_midi_note(last_muse_note));
//                 play_note(compute_freq_for_midi_note(muse_note), 0xF);
//                 last_muse_note = muse_note;
//             }
//         }
//         muse_counter = (muse_counter + 1) % muse_tempo;
//     } else {
//         if (muse_counter) {
//             stop_all_notes();
//             muse_counter = 0;
//         }
//     }
// #endif
// }

// bool music_mask_user(uint16_t keycode) {
//   switch (keycode) {
//     case RAISE:
//     case LOWER:
//       return false;
//     default:
//       return true;
//   }
// }
