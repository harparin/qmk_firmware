
#include QMK_KEYBOARD_H

// layers
#define LYR_BASE  0
#define LYR_NUMS  1
#define LYR_NAV   2
#define LYR_FUNC   3
#define BROWSER_CONTROL 4


#define KC_UE KC_LBRC
#define KC_OE KC_SCLN
#define KC_AE KC_QUOT
#define KC_SZ KC_MINUS
#define MOD_CMD MOD_LGUI 


enum custom_keycodes {
  PLACEHOLDER = SAFE_RANGE, // can always be here
  KC_APOs,
  KC_SPKL,
  DE_BSPC
};


const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [LYR_BASE] = LAYOUT(
    	KC_UE,                KC_O,        KC_E,          KC_P,  KC_Z,                                                             KC_F,                KC_G,  KC_T,          KC_N,          KC_L, 
	KC_A,                 KC_COMM,     KC_DOT,        KC_U,  KC_I,                                                             KC_D,                KC_H,  KC_C,          KC_R,          KC_S, 
	MT(MOD_LSFT, KC_OE),  KC_Q,        KC_J,          KC_K,  KC_X,                                                             KC_B,                KC_M,  KC_W,          KC_V,          MT(MOD_RSFT, KC_Y), 
 	MT(MOD_LCTL, KC_TAB), LT(3,KC_AE), LT(2,KC_BSLS), MO(1), MT(MOD_CMD, KC_BSPC), MT(MOD_RALT, KC_DEL), MT(MOD_RALT, KC_ENT), MT(MOD_CMD, KC_SPC), MO(1), LT(2,KC_2),     LT(3,KC_MINS), MT(MOD_LCTL, KC_ESC)
  ),

  [LYR_NUMS] = LAYOUT(
    KC_EXLM, KC_HASH,  A(S(KC_7)),    A(KC_8), A(KC_9),                   KC_ASTR,  KC_7, KC_8,   KC_9,    S(KC_3),
    A(KC_L), S(KC_6),  KC_AMPR,    S(KC_8), S(KC_9),                   KC_EQUAL, KC_4, KC_5,   KC_6,    KC_SLSH,
    A(KC_7), KC_NUBS,  S(KC_NUBS), A(KC_5), A(KC_6),                   KC_PLUS,  KC_1, KC_2,   KC_3,    KC_TRNS,
    KC_TRNS, KC_TRNS,  KC_BSLS,    KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,  KC_0, KC_DOT, KC_COMM, KC_TRNS
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
    KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,                      KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
    KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,   KC_TRNS, KC_TRNS,  KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS
  ), 
};

bool process_record_user(uint16_t keycode, keyrecord_t *record) {  
  switch (keycode) {
    case DE_BSPC:
      if (record->event.pressed) {
        SEND_STRING("f");
      }
      break;

    case KC_SPKL:
      if (record->event.pressed) {
        SEND_STRING("~");
      }
      break;
    }
  return true;
}

void matrix_init_user(void) {
    set_unicode_input_mode(UC_OSX);
}


