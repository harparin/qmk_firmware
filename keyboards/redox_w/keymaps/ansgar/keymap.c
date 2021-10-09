#include QMK_KEYBOARD_H

#include "keymap_german.h"
#include "keymap_german_osx.h"

// Each layer gets a name for readability, which is then used in the keymap matrix below.
// The underscores don't mean anything - you can have a layer called STUFF or any other name.
// Layer names don't all need to be of the same length, obviously, and you can also skip them
// entirely and just use numbers.
#define _SYMB 1
#define _NAV 2
#define _ADJUST 3

// layers
#define LYR_BASE  0
#define LYR_NUMS  1
#define LYR_NAV   2
#define LYR_FUNC   3


#define MOD_CMD MOD_LGUI

#define DE_OSX_LT    KC_NUBS
#define DE_OSX_GT    S(KC_NUBS)


enum custom_keycodes {
  QWERTY = SAFE_RANGE,
  SYMB,
  NAV,
  ADJUST,
};

// Shortcut to make keymap more readable
#define LT_BSPC MT(MOD_CMD, KC_BSPC)
#define LT_DEL MT(MOD_RALT, KC_DEL)
#define LT_ENT MT(MOD_RALT, KC_ENT)
#define LT_SPC MT(MOD_CMD, KC_SPC)
#define LT_HASH LT(2,DE_HASH)
#define LT_DQUOT LT(2,S(KC_2))
#define LT_SZ LT(3,DE_SS)

#define KC_BKSL KC_BSLASH
#define SYM_L   TG(_SYMB)

#define KC_ALAS LALT_T(KC_PAST)
#define KC_CTPL LCTL_T(KC_PSLS)

#define KC_NAMI LT(_NAV, DE_SS)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

  [LYR_BASE] = LAYOUT(
  //┌────────┬────────┬────────┬────────┬────────┬────────┐                                           ┌────────┬────────┬────────┬────────┬────────┬────────┐
     KC_ESC  ,DE_1    ,DE_2    ,DE_3    ,DE_4    ,DE_5    ,                                            DE_6    ,DE_7    ,DE_8    ,DE_9    ,DE_0    ,KC_TRNS ,
  //├────────┼────────┼────────┼────────┼────────┼────────┼────────┐                         ┌────────┼────────┼────────┼────────┼────────┼────────┼────────┤
     KC_HYPR ,DE_UE   ,DE_O    ,DE_E    ,DE_P    ,KC_Z    ,SYM_L   ,                          SYM_L   ,DE_F    ,DE_G    ,DE_T    ,DE_N    ,DE_L    ,KC_HYPR ,
  //├────────┼────────┼────────┼────────┼────────┼────────┼────────┤                         ├────────┼────────┼────────┼────────┼────────┼────────┼────────┤
     KC_TAB  ,DE_A    ,DE_COMM ,DE_DOT  ,DE_U    ,DE_I    ,KC_NO   ,                          KC_NO   ,DE_D    ,DE_H    ,DE_C    ,DE_R    ,DE_S    ,DE_MINS ,
  //├────────┼────────┼────────┼────────┼────────┼────────┼────────┼────────┐       ┌────────┼────────┼────────┼────────┼────────┼────────┼────────┼────────┤
     KC_LSFT ,DE_OE   ,DE_Q    ,DE_J    ,DE_K    ,DE_X    ,KC_HYPR ,KC_PGDN ,        KC_HOME ,KC_END  ,DE_B    ,DE_M    ,DE_W    ,DE_V    ,DE_Z    ,KC_RSFT ,
  //├────────┼────────┼────────┼ ────────┼────┬───┴───┬───┼────────┼────────┤       ├────────┼────────┼───┬────┴───┬────┼────────┼────────┼────────┼────────┤
     KC_LCTL ,DE_AE   ,TT(3)   ,LT_HASH ,     TT(1)   ,    LT_BSPC ,LT_DEL  ,        LT_ENT  ,LT_SPC  ,    LT(1,KC_0),   LT_DQUOT ,TT(3)   ,DE_SS   ,KC_RCTL
  //└────────┴────────┴────────┴────────┘    └────────┘   └────────┴────────┘       └────────┴────────┘    └────────┘    └────────┴────────┴────────┴────────┘
  ),


  [LYR_NUMS] = LAYOUT(
     _______ ,KC_F1,       KC_F2,       KC_F3,       KC_F4,       KC_F5,                                          KC_F6,       KC_F7,  KC_F8,   KC_F9,      KC_F10      ,KC_F11  ,
     _______ ,DE_OSX_DLR,  DE_OSX_PIPE, DE_OSX_BSLS, DE_OSX_LCBR, DE_OSX_RCBR,_______ ,                  _______ ,DE_OSX_PLUS, KC_7,   KC_8,    KC_9,       XXXXXXX     ,KC_F12  ,
     _______ ,DE_OSX_AT,   DE_OSX_AMPR, DE_OSX_SLSH, DE_OSX_LPRN, DE_OSX_RPRN,_______ ,                  _______ ,DE_OSX_EQL,  KC_4,   KC_5,    KC_6,       DE_SS       ,XXXXXXX ,
     _______ ,DE_OSX_PARA ,DE_OSX_LT,   DE_OSX_GT,   DE_OSX_LBRC, DE_OSX_RBRC,_______ ,_______ ,_______ ,_______ ,DE_OSX_ASTR, KC_1,   KC_2,    KC_3,       XXXXXXX     ,KC_RSFT ,
     _______ ,_______    , _______ ,    S(KC_2) ,              _______ ,      _______ ,_______ ,_______ ,_______ ,        KC_KP_0 ,    DE_DOT , S(DE_COMM), _______     , _______
  ),

  [_NAV] = LAYOUT(
  //┌────────┬────────┬────────┬────────┬────────┬────────┐                                           ┌────────┬────────┬────────┬────────┬────────┬────────┐
     _______ ,_______ ,_______ ,_______ ,_______ ,_______ ,                                            _______ ,_______ ,_______ ,_______ ,_______ ,_______ ,
  //├────────┼────────┼────────┼────────┼────────┼────────┼────────┐                         ┌────────┼────────┼────────┼────────┼────────┼────────┼────────┤
     XXXXXXX ,XXXXXXX ,KC_F1   ,KC_F2   ,KC_F3   ,KC_F4   ,_______ ,                          _______ ,KC_HOME ,KC_PGUP ,KC_UP   ,KC_PGDN ,KC_END  ,XXXXXXX ,
  //├────────┼────────┼────────┼────────┼────────┼────────┼────────┤                         ├────────┼────────┼────────┼────────┼────────┼────────┼────────┤
     XXXXXXX ,KC_MS_L ,KC_F5   ,KC_F6   ,KC_F7   ,KC_F8   ,_______ ,                          _______ ,XXXXXXX ,KC_LEFT ,KC_DOWN ,KC_RIGHT,XXXXXXX ,XXXXXXX ,
  //├────────┼────────┼────────┼────────┼────────┼────────┼────────┼────────┐       ┌────────┼────────┼────────┼────────┼────────┼────────┼────────┼────────┤
     XXXXXXX ,XXXXXXX ,KC_F9   ,KC_F10  ,KC_F11  ,KC_F12  ,_______ ,_______ ,        _______ ,XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX ,
  //├────────┼────────┼────────┼────────┼────┬───┴────┬───┼────────┼────────┤       ├────────┼────────┼───┬────┴───┬────┼────────┼────────┼────────┼────────┤
     XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX ,     KC_BTN1 ,    KC_BTN2 ,_______ ,        _______ ,_______ ,    XXXXXXX ,     XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX
  //└────────┴────────┴────────┴────────┘    └────────┘   └────────┴────────┘       └────────┴────────┘   └────────┘    └────────┴────────┴────────┴────────┘
  ),

  [_ADJUST] = LAYOUT(
  //┌────────┬────────┬────────┬────────┬────────┬────────┐                                           ┌────────┬────────┬────────┬────────┬────────┬────────┐
     XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX ,                                            XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX ,
  //├────────┼────────┼────────┼────────┼────────┼────────┼────────┐                         ┌────────┼────────┼────────┼────────┼────────┼────────┼────────┤
     XXXXXXX ,RESET   ,XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX ,                          XXXXXXX ,XXXXXXX ,XXXXXXX ,KC_MS_U ,XXXXXXX ,KC_WH_U ,XXXXXXX ,
  //├────────┼────────┼────────┼────────┼────────┼────────┼────────┤                         ├────────┼────────┼────────┼────────┼────────┼────────┼────────┤
     XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX ,                          XXXXXXX ,XXXXXXX ,KC_MS_L ,KC_MS_D ,KC_MS_R ,KC_WH_D ,XXXXXXX ,
  //├────────┼────────┼────────┼────────┼────────┼────────┼────────┼────────┐       ┌────────┼────────┼────────┼────────┼────────┼────────┼────────┼────────┤
     XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX ,_______ ,XXXXXXX ,        XXXXXXX ,_______ ,XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX ,
  //├────────┼────────┼────────┼────────┼────┬───┴────┬───┼────────┼────────┤       ├────────┼────────┼───┬────┴───┬────┼────────┼────────┼────────┼────────┤
     XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX ,     XXXXXXX ,    XXXXXXX ,XXXXXXX ,        XXXXXXX ,KC_MS_BTN1,  KC_MS_BTN2,   XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX
  //└────────┴────────┴────────┴────────┘    └────────┘   └────────┴────────┘       └────────┴────────┘   └────────┘    └────────┴────────┴────────┴────────┘
  )

};
