enum planck_layers {
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

enum custom_keycodes {
  MY_PIPE = SAFE_RANGE
};

// Toggles, turn a layer on permanently
#define TG_GAMS TO(_GAMES)
#define TG_PC TO(_QWERTYPC)
#define TG_MAC TO(_QWERTYMAC)
#define TG_SCRL TO(_THREE)

// Layer Holds
#define LT_1DASH LT(_ONE, KC_MINS)
#define LT_2PIPE LT(_TWO, KC_EQUAL)
#define LT_3HASH LT(_THREE, KC_BSLS)

// #define LY_GAMS MO(_GAMES)
// #define LT_SYMB LT(_SYMBOLS, KC_NUBS)
// #define LY_NUMS MO(_NUMBERS)

// Redefines for Enter and Space
#define SFT_ENT RSFT_T(KC_ENTER)
#define LEFT_SPC LT(_NUMBERS, KC_SPC)
#define RGHT_SPC LT(_SYMBOLS, KC_SPC)

// i3 Shortcuts
// #define i3_UP LSG(KC_L)
// #define i3_DOWN LSG(KC_K)
// #define i3_LEFT LSG(KC_J)
// #define i3_RGHT LSG(KC_SCLN)
#define i3_UP LGUI(KC_L)
#define i3_DOWN LGUI(KC_K)
#define i3_LEFT LGUI(KC_J)
#define i3_RGHT LGUI(KC_SCLN)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

[_QWERTYPC] = LAYOUT_planck_2x2u(
    KC_TAB,     KC_Q,      KC_W,      KC_E,      KC_R,      KC_T,      KC_Y,      KC_U,      KC_I,      KC_O,      KC_P,      KC_BSPC,
    KC_GRAVE,   KC_A,      KC_S,      KC_D,      KC_F,      KC_G,      KC_H,      KC_J,      KC_K,      KC_L,      KC_SCLN,   KC_QUOT,
    KC_LSFT,    KC_Z,      KC_X,      KC_C,      KC_V,      KC_B,      KC_N,      KC_M,      KC_COMM,   KC_DOT,    KC_SLSH,   SFT_ENT,
    KC_LCTL,    KC_LGUI,   KC_LALT,   KC_LBRC,   LEFT_SPC,             RGHT_SPC,             KC_RBRC,   LT_1DASH,  LT_2PIPE,  LT_3HASH
),

[_QWERTYMAC] = LAYOUT_planck_2x2u(
    KC_TAB,     KC_Q,      KC_W,      KC_E,      KC_R,      KC_T,      KC_Y,      KC_U,      KC_I,      KC_O,      KC_P,      KC_BSPC,
    KC_GRAVE,   KC_A,      KC_S,      KC_D,      KC_F,      KC_G,      KC_H,      KC_J,      KC_K,      KC_L,      KC_SCLN,   KC_QUOT,
    KC_LSFT,    KC_Z,      KC_X,      KC_C,      KC_V,      KC_B,      KC_N,      KC_M,      KC_COMM,   KC_DOT,    KC_SLSH,   SFT_ENT,
    KC_LCTL,    KC_LALT,   KC_LGUI,   KC_LBRC,   LEFT_SPC,             RGHT_SPC,             KC_RBRC,   LT_1DASH,  LT_2PIPE,  LT_3HASH
),

[_SYMBOLS] = LAYOUT_planck_2x2u(
    KC_NO,      KC_NO,     KC_NO,     KC_NO,     KC_NO,     KC_NO,     KC_NO,     KC_NO,     KC_NO,     KC_NO,     KC_NO,     _______,
    KC_NO,      KC_EXLM,   KC_AT,     KC_HASH,   KC_DLR,    KC_PERC,   KC_CIRC,   KC_AMPR,   KC_ASTR,   KC_LPRN,   KC_RPRN,   _______,
    _______,    KC_NUBS,   KC_NO,     KC_NO,     KC_NO,     KC_NO,     KC_NO,     KC_NO,     KC_COMM,   KC_DOT,    KC_SLSH,   _______,
    _______,    _______,   _______,   _______,   _______,              _______,              _______,   _______,   _______,   _______
),

[_NUMBERS] = LAYOUT_planck_2x2u(
    KC_GRV,     KC_NO,     KC_NO,     KC_NO,     KC_NO,     KC_NO,     KC_NO,     KC_NO,     KC_NO,     KC_NO,     KC_NO,     _______,
    KC_NO,      KC_1,      KC_2,      KC_3,      KC_4,      KC_5,      KC_6,      KC_7,      KC_8,      KC_9,      KC_0,      _______,
    _______,    KC_NO,     KC_NO,     KC_NO,     KC_NO,     KC_NO,     KC_NO,     KC_NO,     KC_COMM,   KC_DOT,    KC_SLSH,   _______,
    _______,    _______,   _______,   _______,   _______,              _______,              _______,   _______,   _______,   _______
),

// LAYER: ONE - Nothing yet.
[_ONE] = LAYOUT_planck_2x2u(
    KC_NO,      KC_NO,     i3_UP,     KC_NO,     KC_NO,     KC_NO,     KC_NO,     KC_NO,     KC_NO,     KC_NO,     KC_NO,     KC_NO,
    KC_NO,      i3_LEFT,   i3_DOWN,   i3_RGHT,   KC_NO,     KC_NO,     KC_NO,     KC_NO,     KC_NO,     KC_NO,     KC_NO,     KC_NO,
    _______,    KC_NO,     KC_NO,     KC_NO,     KC_NO,     KC_NO,     KC_NO,     KC_NO,     KC_NO,     KC_NO,     KC_NO,     KC_NO,
    _______,    _______,   _______,   _______,   _______,              _______,              _______,   _______,   _______,   _______
),

// LAYER: TWO - Media Controls
[_TWO] = LAYOUT_planck_2x2u(
    KC_NO,      KC_NO,     KC_NO,     KC_NO,     KC_NO,     KC_NO,     KC_NO,     KC_NO,     KC_NO,     KC_NO,     KC_MPRV,   KC_VOLU,
    KC_NO,      KC_NO,     KC_MSTP,   KC_NO,     KC_NO,     KC_NO,     KC_NO,     KC_NO,     KC_NO,     KC_NO,     KC_NO,     KC_VOLD,
    _______,    KC_NO,     KC_NO,     KC_NO,     KC_NO,     KC_NO,     KC_MNXT,   KC_NO,     KC_MUTE,   KC_NO,     KC_NO,     KC_MUTE,
    _______,    _______,   _______,   _______,   KC_MPLY,              KC_MPLY,              _______,   _______,   _______,   _______
),
// LAYER: THREE - Arrows, ESC and other movement
[_THREE] = LAYOUT_planck_2x2u(
    KC_ESC,     C(KC_LEFT),KC_UP,     C(KC_RGHT),KC_NO,     KC_NO,     KC_NO,     KC_NO,     KC_NO,     KC_NO,     KC_HOME,   KC_DEL,
    KC_NO,      KC_LEFT,   KC_DOWN,   KC_RGHT,   KC_NO,     KC_NO,     KC_NO,     KC_NO,     KC_NO,     KC_NO,     KC_END,    KC_NO,
    _______,    KC_HOME,   KC_NO,     KC_END,    KC_NO,     KC_NO,     KC_NO,     KC_NO,     KC_NO,     KC_NO,     KC_NO,     KC_NO,
    _______,    _______,   _______,   _______,   _______,              _______,              _______,   _______,   _______,   _______
),

// Layer: To be used as a template for new layers
[_FNKEYS] = LAYOUT_planck_2x2u(
    KC_F1,      KC_F2,     KC_F3,     KC_F4,     KC_F5,     KC_F6,     KC_F7,     KC_F8,     KC_F9,     KC_F10,    KC_F11,    KC_F12,
    KC_NO,      KC_NO,     KC_NO,     KC_NO,     KC_NO,     KC_NO,     KC_NO,     KC_NO,     KC_NO,     KC_NO,     KC_NO,     KC_NO,
    _______,    KC_NO,     KC_NO,     KC_NO,     KC_NO,     KC_NO,     KC_NO,     KC_NO,     KC_NO,     KC_NO,     KC_NO,     KC_NO,
    _______,    _______,   _______,   _______,   _______,              _______,              _______,   _______,   _______,   _______
),

// Layer: Games - Roughly a 1 row offset to allow the numbers to be included by default.  HASH symbol on the right as I've got used 
// to mapping that to quicksave.
// [_GAMES] = LAYOUT_planck_2x2u(
//     KC_ESC,     KC_1,      KC_2,      KC_3,      KC_4,      KC_5,      KC_6,      KC_7,      KC_8,      KC_9,      KC_0,      KC_NO,
//     KC_TAB,     KC_Q,      KC_W,      KC_E,      KC_R,      KC_NO,     KC_NO,     KC_NO,     KC_NO,     KC_NO,     KC_NO,     KC_BSLS,
//     KC_NO,      KC_A,      KC_S,      KC_D,      KC_F,      KC_NO,     KC_NO,     KC_M,      KC_NO,     KC_NO,     KC_NO,     KC_ENTER,
//     KC_LSFT,    KC_Z,      KC_X,      KC_C,      KC_SPC,               KC_SPC,    _______,   _______,   _______,   _______,   _______
// ),

// Layer: Bootloader - Provides access to the bootloader and Caps Lock, both keys only to be used as an exception.
// Invoked by the layer_state_set_user in-built function, and the update_tri_layer_state function called within that.
[_ADMIN] = LAYOUT_planck_2x2u(
    QK_BOOT,    KC_NO,     KC_NO,     KC_NO,     KC_NO,     KC_NO,     KC_NO,     KC_NO,     KC_NO,     KC_NO,     TG_SCRL,   TG_PC,
    KC_CAPS,    KC_NO,     KC_NO,     KC_NO,     KC_NO,     KC_NO,     KC_NO,     KC_NO,     KC_NO,     KC_NO,     KC_NO,     TG_MAC,
    _______,    KC_NO,     KC_NO,     KC_NO,     KC_NO,     KC_NO,     KC_NO,     KC_NO,     KC_NO,     KC_NO,     KC_NO,     TG_GAMS,
    RGB_TOG,    _______,   _______,   _______,   _______,              _______,              _______,   _______,   _______,   _______
),

// Layer: To be used as a template for new layers
// [_BLANK] = LAYOUT_planck_2x2u(
//    KC_NO,      KC_NO,     KC_NO,     KC_NO,     KC_NO,     KC_NO,     KC_NO,     KC_NO,     KC_NO,     KC_NO,     KC_NO,     KC_NO,
//    KC_NO,      KC_NO,     KC_NO,     KC_NO,     KC_NO,     KC_NO,     KC_NO,     KC_NO,     KC_NO,     KC_NO,     KC_NO,     KC_NO,
//    _______,    KC_NO,     KC_NO,     KC_NO,     KC_NO,     KC_NO,     KC_NO,     KC_NO,     KC_NO,     KC_NO,     KC_NO,     KC_NO,
//    _______,    _______,   _______,   _______,   _______,              _______,              _______,   _______,   _______,   _______
// ),

};


layer_state_t layer_state_set_user(layer_state_t state) {
  state = update_tri_layer_state(state, _TWO, _THREE, _FNKEYS);
  state = update_tri_layer_state(state, _ONE, _TWO, _ADMIN);
  return state;
};