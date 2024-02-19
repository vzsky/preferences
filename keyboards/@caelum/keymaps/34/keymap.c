#include QMK_KEYBOARD_H
#include "features/select_word.h"

enum layers {
  _QWERTY,
  _COLEMAK,
  _NAV,
  _LOWER,
  _RAISE,
  _ADJUST,
};

enum custom_keycodes {
  SELWORD = SAFE_RANGE,
  QWERTY, 
  COLEMAK
};


#define LTAB  LT(_LOWER, KC_TAB)
#define RENT  LT(_RAISE, KC_ENT)
#define NAV MO(_NAV)

#define CLEFT  C(KC_LEFT)
#define CRIGHT C(KC_RIGHT)

#define LWORD A(KC_LEFT)
#define RWORD A(KC_RIGHT)

#define COPY    G(KC_C)
#define PATSE   G(KC_V)



const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [_QWERTY] = LAYOUT(
        XXXXXXX, KC_Q   , KC_W   , KC_E   , KC_R   , KC_T   ,           KC_Y   , KC_U   , KC_I   , KC_O   , KC_P   , XXXXXXX,
        XXXXXXX, KC_A   , KC_S   , KC_D   , KC_F   , KC_G   ,           KC_H   , KC_J   , KC_K   , KC_L   , KC_SCLN, XXXXXXX,
        XXXXXXX, KC_Z   , KC_X   , KC_C   , KC_V   , KC_B   ,           KC_N   , KC_M   , KC_COMM, KC_DOT , KC_SLSH, XXXXXXX,
        XXXXXXX,          XXXXXXX, XXXXXXX, LTAB   , KC_SPC ,           KC_BSPC, RENT   , XXXXXXX, XXXXXXX,          XXXXXXX
    ),
    [_COLEMAK] = LAYOUT(
        XXXXXXX, KC_Q   , KC_W   , KC_F   , KC_P   , KC_B   ,           KC_J   , KC_L   , KC_U   , KC_Y   , KC_SCLN, XXXXXXX,
        XXXXXXX, KC_A   , KC_R   , KC_S   , KC_T   , KC_G   ,           KC_M   , KC_N   , KC_E   , KC_I   , KC_O   , XXXXXXX,
        XXXXXXX, KC_Z   , KC_X   , KC_C   , KC_D   , KC_V   ,           KC_K   , KC_H   , KC_COMM, KC_DOT , KC_SLSH, XXXXXXX,
        XXXXXXX,          XXXXXXX, XXXXXXX, LTAB   , KC_SPC ,           KC_BSPC, RENT   , XXXXXXX, XXXXXXX,          XXXXXXX
    ),
    [_NAV] = LAYOUT(
        XXXXXXX, KC_F1  , KC_F2  , KC_F3  , KC_F4  , XXXXXXX,           COPY,    SELWORD, XXXXXXX, XXXXXXX, PATSE  , XXXXXXX, 
        XXXXXXX, KC_F5  , KC_F6  , KC_F7  , KC_F8  , XXXXXXX,           KC_LEFT, KC_DOWN, KC_UP  , KC_RGHT, XXXXXXX, XXXXXXX,
        _______, KC_F9  , KC_F10 , KC_F11 , KC_F12 , XXXXXXX,           KC_PGDN, LWORD  , RWORD  , KC_PGUP, XXXXXXX, XXXXXXX,
        _______,          _______, _______, _______, _______,           _______, _______, _______, _______,          _______
                                       
    ),
    [_LOWER] = LAYOUT(
        XXXXXXX, KC_UNDS, KC_AMPR, KC_ASTR, KC_GRV,  KC_TILD,           XXXXXXX, KC_LBRC, KC_RBRC, XXXXXXX, XXXXXXX, XXXXXXX,
        XXXXXXX, XXXXXXX, KC_DLR,  KC_PERC, KC_CIRC, KC_BSLS,           XXXXXXX, KC_LPRN, KC_RPRN, KC_QUOT, KC_DQT , XXXXXXX,
        _______, XXXXXXX, KC_EXLM, KC_AT,   KC_HASH, KC_PIPE,           XXXXXXX, KC_LCBR, KC_RCBR, KC_LABK, KC_RABK, XXXXXXX,
        _______,          _______, _______, _______, _______,           _______, _______, _______, _______,          _______
    ),
    [_RAISE] = LAYOUT(
        XXXXXXX, KC_UNDS, KC_7   , KC_8   , KC_9   , XXXXXXX,           XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                       
        XXXXXXX, XXXXXXX, KC_4   , KC_5   , KC_6   , XXXXXXX,           XXXXXXX, KC_PLUS, KC_MINS, KC_ASTR, KC_SLSH, XXXXXXX,
        _______, KC_0   , KC_1   , KC_2   , KC_3   , XXXXXXX,           XXXXXXX, KC_CIRC, KC_EQL,  XXXXXXX, XXXXXXX, XXXXXXX,
        XXXXXXX,          _______, _______, _______, _______,           _______, _______, _______, _______,          XXXXXXX
    ),
    [_ADJUST] = LAYOUT(
        XXXXXXX, RESET  , XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,           XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
        XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,           XXXXXXX, QWERTY , COLEMAK, XXXXXXX, XXXXXXX, XXXXXXX,
        _______, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,           XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
        _______,          _______, _______, _______, _______,           _______, _______, _______, _______,          _______
    )
};

bool process_record_user(uint16_t keycode, keyrecord_t* record) {
  if (!process_select_word(keycode, record, SELWORD)) { return false; }
  switch (keycode) {
    case QWERTY:
      if (record->event.pressed) {
        set_single_persistent_default_layer(_QWERTY);
      }
      return false;
      break;
    case COLEMAK:
      if (record->event.pressed) {
        set_single_persistent_default_layer(_COLEMAK);
      }
      return false;
      break;
  }
  return true;
}

layer_state_t layer_state_set_user(layer_state_t state) {
  return update_tri_layer_state(state, _LOWER, _RAISE, _ADJUST);
}
