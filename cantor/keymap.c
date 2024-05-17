// Copyright 2022 Yale Thomas

#include QMK_KEYBOARD_H

// Each layer gets a name for readability, which is then used in the keymap matrix below.
// The underscores don't mean anything - you can have a layer called STUFF or any other name.
// Layer names don't all need to be of the same length, obviously, and you can also skip them
// entirely and just use numbers.
#define _QWERTY 0
#define _NUM 3
#define _FUNC 4
#define _NAV 16

enum custom_keycodes {
  QWERTY,
  NUM,
  FUNC,
  NAV,
};

#define _____    KC_TRNS
#define KC_XXXXX KC_NO
#define KC_FUNC  MO(_FUNC)
#define KC_NAV   MO(_NAV)
#define KC_RST   RESET
#define KC_LTOG  RGB_TOG
#define KC_LHUI  RGB_HUI
#define KC_LHUD  RGB_HUD
#define KC_LSAI  RGB_SAI
#define KC_LSAD  RGB_SAD
#define KC_LVAI  RGB_VAI
#define KC_LVAD  RGB_VAD
#define KC_LMOD  RGB_MOD
#define KC_CTLTB CTL_T(KC_TAB)
#define KC_GUIEI GUI_T(KC_ENT)
#define KC_ALTKN ALT_T(KC_ENT)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [_QWERTY] = LAYOUT_split_3x6_3( \
        KC_ESC,     KC_Q,     KC_W,     KC_E,     KC_R,     KC_T,       KC_Y,    KC_U,     KC_I,     KC_O,     KC_P,  KC_BSPC,
      KC_CTLTB,     KC_A,     KC_S,     KC_D,     KC_F,     KC_G,       KC_H,    KC_J,     KC_K,     KC_L,  KC_SCLN,  KC_QUOT,
       KC_LSFT,     KC_Z,     KC_X,     KC_C,     KC_V,     KC_B,       KC_N,    KC_M,  KC_COMM,   KC_DOT,  KC_SLSH,  KC_RSFT,
                                     KC_LGUI, MO(_NUM),   KC_ENT,     KC_SPC, KC_FUNC, KC_ALTKN
  ),

  [_NUM] = LAYOUT_split_3x6_3( \
         _____,     KC_1,     KC_2,     KC_3,     KC_4,     KC_5,        KC_6,     KC_7,     KC_8,     KC_9,     KC_0,    _____,
       KC_LCTL,   KC_GRV,  KC_LBRC,  KC_LCBR,  KC_LPRN,  KC_SLSH,     KC_BSLS,  KC_RPRN,  KC_RCBR,  KC_RBRC,  KC_MINS,   KC_EQL,
         _____,  KC_EXLM,    KC_AT,  KC_HASH,   KC_DLR,  KC_PERC,     KC_CIRC,  KC_AMPR,  KC_ASTR,  KC_UNDS,  KC_PLUS,    _____,
                                     KC_LGUI, MO(_NUM),   KC_ENT,     KC_BSPC,   KC_NAV, KC_ALTKN
  ),

  [_FUNC] = LAYOUT_split_3x6_3( \
         _____,     KC_1,     KC_2,     KC_3,     KC_4,     KC_5,        KC_6,     KC_7,     KC_8,     KC_9,     KC_0,    _____,
         _____,  KC_LSFT,  KC_LCTL,  KC_LALT,  KC_LGUI,    _____,     KC_LEFT,  KC_DOWN,    KC_UP,  KC_RGHT,   KC_DEL,    _____,
         _____,    _____,    _____,    _____,    _____,    _____,     KC_MPRV,  KC_VOLD,  KC_VOLU,  KC_MNXT,  KC_MUTE,    _____,
                                     KC_LGUI,   KC_NAV,   KC_ENT,      KC_SPC,  KC_FUNC,  KC_MPLY
  ),

  [_NAV] = LAYOUT_split_3x6_3( \
        KC_RST, KC_XXXXX, KC_XXXXX, KC_XXXXX, KC_XXXXX, KC_XXXXX,      KC_XXXXX, KC_XXXXX, KC_XXXXX, KC_XXXXX, KC_XXXXX,   KC_PWR,
       KC_LTOG,  KC_LHUI,  KC_LSAI,  KC_LVAI,  KC_LTOG, KC_XXXXX,      KC_XXXXX, KC_XXXXX, KC_XXXXX, KC_XXXXX, KC_XXXXX, KC_XXXXX,
       KC_LMOD,  KC_LHUD,  KC_LSAD,  KC_LVAD, KC_XXXXX, KC_XXXXX,      KC_XXXXX,  KC_BRID,  KC_BRIU, KC_XXXXX, KC_XXXXX,  KC_SLEP,
                                     KC_LGUI, MO(_NUM),   KC_ENT,        KC_SPC,  KC_FUNC, KC_ALTKN
  )
};
