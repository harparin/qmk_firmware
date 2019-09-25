#include QMK_KEYBOARD_H

#include "keymap_german.h"
#include "keymap_german_osx.h"

// layers
#define LYR_BASE 0
#define LYR_NUMS_OSX 1
#define LYR_NAV 2
#define LYR_FUNC 3


#define MOD_CMD MOD_LGUI 

#define DE_OSX_LT    KC_NUBS
#define DE_OSX_GT    S(KC_NUBS)

enum custom_keycodes {
  PLACEHOLDER = SAFE_RANGE, // can always be here

};


const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [LYR_BASE] = LAYOUT(
    DE_UE,                KC_O,        KC_E,          KC_P,  KC_Z,                                                             KC_F,                KC_G,  KC_T,          KC_N,          KC_L, 
	  KC_A,                 KC_COMM,     KC_DOT,        KC_U,  KC_I,                                                             KC_D,                KC_H,  KC_C,          KC_R,          KC_S, 
	  MT(MOD_LSFT, DE_OE),  KC_Q,        KC_J,          KC_K,  KC_X,                                                             KC_B,                KC_M,  KC_W,          KC_V,          MT(MOD_RSFT, KC_Y), 
 	  MT(MOD_LCTL, KC_TAB), LT(3,DE_AE), LT(2,DE_HASH), MO(1), MT(MOD_CMD, KC_BSPC), MT(MOD_RALT, KC_DEL), MT(MOD_RALT, KC_ENT), MT(MOD_CMD, KC_SPC), MO(1), LT(2,KC_2),   LT(3,DE_SS), MT(MOD_LCTL, KC_ESC)
  ),

  [LYR_NUMS_OSX] = LAYOUT(
    DE_OSX_DLR,  DE_OSX_PERC, DE_OSX_BSLS, DE_OSX_LCBR, DE_OSX_RCBR,                   DE_OSX_ASTR, KC_7, KC_8,   KC_9,    DE_OSX_PARA,
    DE_OSX_AT,   DE_OSX_AMPR, DE_OSX_SLSH, DE_OSX_LPRN, DE_OSX_RPRN,                   DE_OSX_EQL,  KC_4, KC_5,   KC_6,    DE_OSX_MINS,
    DE_OSX_PIPE, DE_OSX_LT,   DE_OSX_GT,   DE_OSX_LBRC, DE_OSX_RBRC,                   DE_OSX_PLUS, KC_1, KC_2,   KC_3,    KC_TRNS,
    KC_TRNS,     KC_TRNS,     KC_TRNS,     KC_TRNS,     KC_TRNS,     KC_TRNS, KC_TRNS, KC_TRNS,     KC_0, KC_DOT, KC_COMM, KC_TRNS
  ),

  [LYR_NAV] = LAYOUT(
    KC_TRNS, KC_F1,   KC_F2,   KC_F3,   KC_F4,                        KC_HOME, KC_PGUP, KC_UP,   KC_PGDOWN, KC_END,
    KC_TRNS, KC_F5,   KC_F6,   KC_F7,   KC_F8,                        KC_TRNS, KC_LEFT, KC_DOWN, KC_RIGHT,  KC_TRNS,
    KC_TRNS, KC_F9,   KC_F10,  KC_F11,  KC_F12,                       KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,   KC_TRNS,
    KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,   KC_TRNS, KC_TRNS,  KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,   KC_TRNS
  ), 

   [LYR_FUNC] = LAYOUT(
    RESET,   KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,                      KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
    KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,                      KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
    KC_CAPS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,                      KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
    KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,   KC_TRNS, KC_TRNS,  KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS
  ), 
};



