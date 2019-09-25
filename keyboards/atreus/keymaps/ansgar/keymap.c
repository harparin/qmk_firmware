
#include QMK_KEYBOARD_H

// layers
#define LYR_BASE  0
#define LYR_NUMS  1
#define LYR_NAV   2
#define LYR_FUNC   3
#define BROWSER_CONTROL 4


#define MOD_CMD MOD_LGUI 

#define DE_UE    KC_LBRC
#define DE_OE    KC_SCLN
#define DE_AE    KC_QUOT
#define DE_SZ    KC_MINUS
#define DE_HASH  KC_BSLS

#define DE_AT    A(KC_L)
#define DE_AMPRS S(KC_6)
#define DE_DLLR  S(KC_4)
#define DE_PRCT  S(KC_5)
#define DE_LCBR  A(KC_8)
#define DE_RCBR  A(KC_9)
#define DE_FSLS  KC_AMPR
#define DE_BSLS  A(S(KC_7))
#define DE_LPRN  S(KC_8)
#define DE_RPRN  S(KC_9)
#define DE_LBKT  A(KC_5)
#define DE_RBKT  A(KC_6)
#define DE_LT    KC_NUBS
#define DE_GT    S(KC_NUBS)
#define DE_MINS  KC_SLSH
#define DE_PIPE  A(KC_7)
#define DE_PARA  S(KC_3)
#define DE_ASTR  S(KC_RBRC)
#define DE_EQUL  S(KC_0)
#define DE_PLUS  KC_RBRC


enum custom_keycodes {
  PLACEHOLDER = SAFE_RANGE, // can always be here

};


const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [LYR_BASE] = LAYOUT(
    DE_UE,                KC_O,        KC_E,          KC_P,  KC_Z,                                                             KC_F,                KC_G,  KC_T,          KC_N,          KC_L, 
	  KC_A,                 KC_COMM,     KC_DOT,        KC_U,  KC_I,                                                             KC_D,                KC_H,  KC_C,          KC_R,          KC_S, 
	  MT(MOD_LSFT, DE_OE),  KC_Q,        KC_J,          KC_K,  KC_X,                                                             KC_B,                KC_M,  KC_W,          KC_V,          MT(MOD_RSFT, KC_Y), 
 	  MT(MOD_LCTL, KC_TAB), LT(3,DE_AE), LT(2,DE_HASH), MO(1), MT(MOD_CMD, KC_BSPC), MT(MOD_RALT, KC_DEL), MT(MOD_RALT, KC_ENT), MT(MOD_CMD, KC_SPC), MO(1), LT(2,KC_2),     LT(3,DE_SZ), MT(MOD_LCTL, KC_ESC)
  ),

  [LYR_NUMS] = LAYOUT(
    DE_DLLR, DE_PRCT,  DE_BSLS,    DE_LCBR, DE_RCBR,                   DE_ASTR,  KC_7, KC_8,   KC_9,    DE_PARA,
    DE_AT,   DE_AMPRS, DE_FSLS,    DE_LPRN, DE_RPRN,                   DE_EQUL,  KC_4, KC_5,   KC_6,    DE_MINS,
    DE_PIPE, DE_LT,    DE_GT,      DE_LBKT, DE_RBKT,                   DE_PLUS,  KC_1, KC_2,   KC_3,    KC_TRNS,
    KC_TRNS, KC_TRNS,  KC_TRNS,    KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,  KC_0, KC_DOT, KC_COMM, KC_TRNS
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



