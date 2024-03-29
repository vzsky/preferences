#include "quantum_keycodes.h"
#include QMK_KEYBOARD_H

enum layers {
  _QWERTY,
  _COLEMAK,
  _NAV,
  _LOWER,
  _RAISE,
  _ADJUST,
};

enum keycodes {
  QWERTY = SAFE_RANGE, 
  COLEMAK,
};

#define LOWER  MO(_LOWER)
#define RAISE  MO(_RAISE)
#define NAV MO(_NAV)

#define CLEFT  C(KC_LEFT)
#define CRIGHT C(KC_RIGHT)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [_QWERTY] = LAYOUT_5x6(
  KC_TAB , KC_Q   , KC_W   , KC_E   , KC_R   , KC_T   ,                         KC_Y   , KC_U   , KC_I   , KC_O   , KC_P   , KC_CAPS,
  KC_ESC , KC_A   , KC_S   , KC_D   , KC_F   , KC_G   ,                         KC_H   , KC_J   , KC_K   , KC_L   , KC_SCLN, KC_QUOT,
  NAV    , KC_Z   , KC_X   , KC_C   , KC_V   , KC_B   ,                         KC_N   , KC_M   , KC_COMM, KC_DOT , KC_SLSH, XXXXXXX,
                    KC_LCTL, KC_LGUI, LOWER  , KC_SPC ,                         KC_BSPC, RAISE  , KC_RGUI, KC_RALT,
                                               KC_LSFT,                         KC_ENT
    ),
    [_COLEMAK] = LAYOUT_5x6(
  KC_TAB , KC_Q   , KC_W   , KC_F   , KC_P   , KC_B   ,                         KC_J   , KC_L   , KC_U   , KC_Y   , KC_SCLN, KC_CAPS,
  KC_ESC , KC_A   , KC_R   , KC_S   , KC_T   , KC_G   ,                         KC_M   , KC_N   , KC_E   , KC_I   , KC_O   , KC_QUOT,
  NAV    , KC_Z   , KC_X   , KC_C   , KC_D   , KC_V   ,                         KC_K   , KC_H   , KC_COMM, KC_DOT , KC_SLSH, XXXXXXX,
                    KC_LCTL, KC_LGUI, LOWER  , KC_SPC ,                         KC_BSPC, RAISE  , KC_RGUI, KC_RALT,
                                               KC_LSFT,                         KC_ENT
    ),
    [_NAV] = LAYOUT_5x6(
  _______, KC_F1  , KC_F2  , KC_F3  , KC_F4  , _______,                         _______, _______, _______, _______, _______, _______,
  _______, KC_F5  , KC_F6  , KC_F7  , KC_F8  , _______,                         KC_LEFT, KC_DOWN, KC_UP  , KC_RGHT, _______, _______,
  _______, KC_F9  , KC_F10 , KC_F11 , KC_F12 , _______,                         KC_HOME, KC_PGDN, KC_PGUP, KC_END , _______, _______,
                    _______, _______, _______, _______,                         _______, _______, _______, _______,
                                               _______,                         _______
    ),
    [_LOWER] = LAYOUT_5x6(
  KC_MNXT, KC_UNDS, KC_AMPR, KC_ASTR, KC_GRV,  KC_TILD,                         _______, KC_LBRC, KC_RBRC, _______, _______, _______,
  KC_MPLY, _______, KC_DLR,  KC_PERC, KC_CIRC, KC_BSLS,                         _______, KC_LPRN, KC_RPRN, KC_LABK, KC_RABK, _______,
  _______, _______, KC_EXLM, KC_AT,   KC_HASH, KC_PIPE,                         _______, KC_LCBR, KC_RCBR, _______, _______, _______,
                    _______, _______, _______, _______,                         _______, _______, _______, _______,
                                               _______,                         _______
    ),
    [_RAISE] = LAYOUT_5x6(
  CLEFT  , KC_UNDS, KC_7   , KC_8   , KC_9   , _______,                         _______, _______, _______, _______, _______, CRIGHT ,                       
  _______, _______, KC_4   , KC_5   , KC_6   , _______,                         _______, KC_PLUS, KC_MINS, KC_ASTR, KC_SLSH, _______,
  _______, KC_0   , KC_1   , KC_2   , KC_3   , _______,                         _______, KC_CIRC, KC_EQL,  _______, _______, _______,
                    _______, _______, _______, _______,                         _______, _______, _______, _______,
                                               _______,                         _______
    ),
    [_ADJUST] = LAYOUT_5x6(
  _______, RESET  , _______, _______, _______, _______,                         _______, _______, _______, _______, _______, _______,
  _______, _______, _______, _______, _______, _______,                         _______, QWERTY, COLEMAK, _______, _______, _______,
  _______, _______, _______, _______, _______, _______,                         _______, _______, _______, _______, _______, _______,
                    _______, _______, _______, _______,                         _______, _______, _______, _______,
                                               _______,                         _______
    )
};


layer_state_t layer_state_set_user(layer_state_t state) {
  return update_tri_layer_state(state, _LOWER, _RAISE, _ADJUST);
}


bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
    case QWERTY:
      if (record->event.pressed) {
        set_single_persistent_default_layer(_QWERTY);
      }
      return false;
    case COLEMAK:
      if (record->event.pressed) {
        set_single_persistent_default_layer(_COLEMAK);
      }
      return false;
    }
  return true;
}
