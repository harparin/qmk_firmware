#include QMK_KEYBOARD_H

#include "keymap_german_osx.h"
#include "keymap_steno.h"

// layers
#define LYR_BASE 0
#define LYR_NUMS_OSX 1
#define LYR_NAV 2
#define LYR_FUNC 3
#define LYR_PLOVER 4


#define MOD_CMD MOD_LGUI

#define DE_LX_LCBR  RALT(KC_8)        // {
#define DE_LX_LBRC  RALT(KC_5)        // [
#define DE_LX_RBRC  RALT(KC_6)        // ]
#define DE_LX_RCBR  RALT(KC_9)        // }
#define DE_LX_BSLS  RALT(LSFT(KC_7))  // backslash
#define DE_LX_EURO  RALT(KC_E)        // €
#define DE_LX_TILD  RALT(DE_N)    // ~
#define DE_LX_PIPE  RALT(DE_7)    // |


enum custom_keycodes {
  PLACEHOLDER = SAFE_RANGE, // can always be here
};

void matrix_init_user() {
  steno_set_mode(STENO_MODE_GEMINI); // or STENO_MODE_BOLT
}

uint16_t get_tapping_term(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case LSFT_T(DE_U):
        case RSFT_T(DE_H):
            return TAPPING_TERM - 70;
        default:
            return TAPPING_TERM;
    }
}

bool get_permissive_hold(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case LSFT_T(DE_U):
        case RSFT_T(DE_H):
            return true; // Immediately select the hold action when another key is tapped.
        default:
            return false; // Do not select the hold action when another key is tapped.
    }
}


const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [LYR_BASE] = LAYOUT(
    DE_UDIA,      LALT_T(KC_O),  LCMD_T(KC_E),         KC_P,          KC_Z,                                         KC_F,           KC_G, RCMD_T(KC_T), LALT_T(KC_N),         KC_L,
	LCTL_T(DE_A),      KC_COMM,        KC_DOT, LSFT_T(KC_U),          KC_I,                                         KC_D,   RSFT_T(KC_H),         KC_C,         KC_R, RCTL_T(KC_S),
	DE_ODIA,              KC_Q,          KC_J,         KC_K,          KC_X,                                         KC_B,           KC_M,         KC_W,         KC_V,         KC_Y,
 	DE_ADIA,             TO(4),       DE_HASH,        MO(3), LT(1, KC_BSPC), LT(2, KC_DEL), LT(2, KC_ENT), LT(1, KC_SPC),          MO(3),         KC_2,        DE_LSQU,      DE_SS
  ),

  [LYR_NUMS_OSX] = LAYOUT(
    DE_DLR,  DE_PIPE, DE_BSLS, DE_LCBR, DE_RCBR,                   DE_PLUS, KC_7, KC_8,   KC_9,       DE_PERC,
    DE_AT,   DE_AMPR, DE_SLSH, DE_LPRN, DE_RPRN,                   DE_EQL,  KC_4, KC_5,   KC_6,       DE_MINS,
    KC_TRNS, DE_LABK, DE_RABK, DE_LBRC, DE_RBRC,                   DE_ASTR, KC_1, KC_2,   KC_3,       KC_TRNS,
    KC_TRNS, KC_TRNS, S(KC_2), KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_0, KC_DOT, S(KC_COMM), KC_TRNS
  ),

  [LYR_NAV] = LAYOUT(
    KC_ESC,   KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,                      KC_TRNS, KC_F7,   KC_F8,   KC_F9,   KC_F10,
    KC_TAB,   KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,                      KC_TRNS, KC_F4,   KC_F5,   KC_F6,   KC_F11,
    KC_TRNS,  KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,                      KC_TRNS, KC_F1,   KC_F2,   KC_F3,   KC_F12,
    KC_TRNS,  KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,   KC_TRNS, KC_TRNS,  KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS
  ),

   [LYR_FUNC] = LAYOUT(
    RESET,   KC_TRNS, DE_SECT,     KC_TRNS, KC_TRNS,                     KC_HOME, KC_PGUP, KC_UP,   KC_PGDOWN, KC_END,
    KC_TRNS, KC_TRNS, KC_TRNS,     KC_TRNS, KC_TRNS,                     KC_TRNS, KC_LEFT, KC_DOWN, KC_RIGHT,  KC_TRNS,
    KC_CAPS, KC_TRNS, KC_TRNS,     KC_TRNS, KC_TRNS,                     KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,   KC_TRNS,
    KC_TRNS, KC_TRNS, KC_TRNS,     KC_TRNS, KC_TRNS,   KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,   KC_TRNS
  ),
    /* Plover layer (http://opensteno.org)
    * ,-----------------------------------------------------------------------------------.
    * |   #  |   #  |   #  |   #  |   #  |   #  |   #  |   #  |   #  |   #  |   #  |   #  |
    * |------+------+------+------+------+-------------+------+------+------+------+------|
    * |  FN  |   S  |   T  |   P  |   H  |   *  |   *  |   F  |   P  |   L  |   T  |   D  |
    * |------+------+------+------+------+------|------+------+------+------+------+------|
    * |      |   S  |   K  |   W  |   R  |   *  |   *  |   R  |   B  |   G  |   S  |   Z  |
    * |------+------+------+------+------+------+------+------+------+------+------+------|
    * | Exit |      |      |   A  |   O  |             |   E  |   U  |  PWR | RES1 | RES2 |
    * `-----------------------------------------------------------------------------------'
    */

    [LYR_PLOVER] = LAYOUT(
    STN_N1,  STN_N2,  STN_N3,  STN_N4,  STN_N5,               STN_N6,  STN_N7,  STN_N8,  STN_N9,  STN_NA,
    STN_S1,  STN_TL,  STN_PL,  STN_HL, STN_ST1,               STN_FR,  STN_PR,  STN_LR,  STN_TR,  STN_DR,
    STN_S2,  STN_KL,  STN_WL,  STN_RL, STN_ST2,               STN_RR,  STN_BR,  STN_GR,  STN_SR,  STN_ZR,
    XXXXXXX,  TO(0), XXXXXXX, XXXXXXX,   STN_A, STN_O, STN_E,  STN_U, XXXXXXX, STN_PWR, STN_RE1, STN_RE2
    ),
};



