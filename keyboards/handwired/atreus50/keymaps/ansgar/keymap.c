#include QMK_KEYBOARD_H

#include "keymap_german.h"
#include "keymap_german_osx.h"
#include "keymap_plover.h"

// layers
#define LYR_BASE 0
#define LYR_NUMS_OSX 1
#define LYR_NAV 2
#define LYR_FUNC 3
#define LYR_STENO 4


#define MOD_CMD MOD_LGUI 

#define DE_OSX_LT    KC_NUBS
#define DE_OSX_GT    S(KC_NUBS)
 
enum custom_keycodes {
  PLACEHOLDER = SAFE_RANGE, // can always be here
  PLOVER,
  EXT_PLV
};


const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [LYR_BASE] = LAYOUT(
    KC_ESC,  DE_UE,          KC_O,        KC_E,          KC_P,  DE_Y,                                           KC_F,          KC_G,  KC_T,         KC_N,        KC_L, S(KC_2),
	  KC_TAB,  KC_A,           KC_COMM,     KC_DOT,        KC_U,  KC_I,                                           KC_D,          KC_H,  KC_C,         KC_R,        KC_S, DE_MINS,
	  KC_LSFT, DE_OE,          KC_Q,        KC_J,          KC_K,  KC_X,                                           KC_B,          KC_M,  KC_W,         KC_V,        DE_Z, KC_LSFT,
 	  KC_LCTL, DE_AE,          TT(3),       LT(2,DE_HASH), TT(1), CMD_T(KC_BSPC), LALT_T(KC_DEL), RALT_T(KC_ENT), CMD_T(KC_SPC), MO(1), LT(2,KC_2),   TT(3),       DE_SS, KC_RCTL
  ),

  [LYR_NUMS_OSX] = LAYOUT(
    KC_TRNS, DE_OSX_DLR,  DE_OSX_PIPE, DE_OSX_BSLS, DE_OSX_LCBR, DE_OSX_RCBR,                   DE_OSX_PLUS, KC_7, KC_8,   KC_9,       DE_OSX_PERC, KC_TRNS,
    KC_TRNS, DE_OSX_AT,   DE_OSX_AMPR, DE_OSX_SLSH, DE_OSX_LPRN, DE_OSX_RPRN,                   DE_OSX_EQL,  KC_4, KC_5,   KC_6,       DE_OSX_MINS, KC_TRNS,
    KC_TRNS, KC_TRNS,     DE_OSX_LT,   DE_OSX_GT,   DE_OSX_LBRC, DE_OSX_RBRC,                   DE_OSX_ASTR, KC_1, KC_2,   KC_3,       KC_TRNS,     KC_TRNS,
    KC_TRNS, KC_TRNS,     KC_TRNS,     S(KC_2),     KC_TRNS,     KC_TRNS,     KC_TRNS, KC_TRNS, KC_TRNS,     KC_0, KC_DOT, S(KC_COMM), KC_TRNS,     KC_TRNS
  ),

  [LYR_NAV] = LAYOUT(
    KC_TRNS, KC_ESC,   KC_F1,   KC_F2,   KC_F3,   KC_F4,                        KC_HOME, KC_PGUP, KC_UP,   KC_PGDOWN, KC_END,  KC_TRNS,
    KC_TRNS, KC_TRNS,  KC_F5,   KC_F6,   KC_F7,   KC_F8,                        KC_TRNS, KC_LEFT, KC_DOWN, KC_RIGHT,  KC_TRNS, KC_TRNS,
    KC_TRNS, KC_TRNS,  KC_F9,   KC_F10,  KC_F11,  KC_F12,                       KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,   KC_TRNS, KC_TRNS,
    KC_TRNS, KC_TRNS,  KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,   KC_TRNS, KC_TRNS,  KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,   KC_TRNS, KC_TRNS
  ), 

  [LYR_FUNC] = LAYOUT(
    KC_TRNS, RESET,   KC_TRNS, DE_OSX_PARA, KC_TRNS, KC_TRNS,                      PLOVER,      KC_TRNS,    KC_MS_U, KC_TRNS, KC_TRNS, KC_TRNS,
    KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,     KC_TRNS, KC_TRNS,                      KC_TRNS,     KC_MS_L,    KC_MS_D, KC_MS_R, KC_TRNS, KC_TRNS,
    KC_TRNS, KC_CAPS, KC_TRNS, KC_TRNS,     KC_TRNS, KC_TRNS,                      KC_TRNS,     KC_TRNS,    KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
    KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,     KC_TRNS, KC_TRNS,   KC_TRNS, KC_TRNS,  KC_MS_BTN1,  KC_MS_BTN2, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS
  ), 
  [LYR_STENO] = LAYOUT(
    KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,              KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
    PV_NUM,  PV_LS,  PV_LT, PV_LP, PV_LH, KC_TRNS,                     KC_NO, PV_RF, PV_RP, PV_RL,  PV_RT,  PV_RD, 
    KC_NO,   PV_LS,  PV_LK, PV_LW, PV_LR, KC_TRNS,                     KC_NO, PV_RR, PV_RB, PV_RG,  PV_RS,  PV_RZ,
    EXT_PLV, KC_NO,  KC_NO, KC_NO, PV_A,  PV_O,    PV_STAR, PV_STAR,   PV_E,  PV_U,  KC_NO, KC_NO,  KC_NO,  KC_NO
  ), 
};



bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
    case PLOVER:
      if (!record->event.pressed) {
        layer_on(LYR_STENO);
      }
      return false;
      break;
    case EXT_PLV:
      if (record->event.pressed) {
        layer_off(LYR_STENO);
      }
      return false;
      break;
  }
  return true;
}

