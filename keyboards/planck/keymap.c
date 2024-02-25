#include QMK_KEYBOARD_H

enum planck_layers {
  _COLEMAK,
  _LOWER,
  _RAISE,
  _ADJUST,
  _NAV,
};

#define LOWER  MO(_LOWER)
#define RAISE  MO(_RAISE)
#define NAV    MO(_NAV)
#define SPACE  LT(_NAV, KC_SPACE)

#define LWORD A(KC_LEFT)
#define RWORD A(KC_RIGHT)

#define COPY    G(KC_C)
#define PATSE   G(KC_V)
#define UNDO    G(KC_Z)

#define CLEFT  C(KC_LEFT)
#define CRIGHT C(KC_RIGHT)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

/* Qwerty
 * ,-----------------------------------------------------------------------------------.
 * | Tab  |   Q  |   W  |   E  |   R  |   T  |   Y  |   U  |   I  |   O  |   P  | CAPS |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * | Esc  |   A  |   S  |   D  |   F  |   G  |   H  |   J  |   K  |   L  |   ;  |  "   |
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * |  Nav |   Z  |   X  |   C  |   V  |   B  |   N  |   M  |   ,  |   .  |   /  |SHIFT |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | SHIFT| Ctrl | Alt  | GUI  |Lower |  SPC | BKSP |Raise | Globe|      |      |ENTER |
 * `-----------------------------------------------------------------------------------'
 */
// [_QWERTY] = LAYOUT_planck_grid(
//   KC_TAB,  KC_Q,    KC_W,    KC_E,    KC_R,  KC_T,   KC_Y,    KC_U,   KC_I,    KC_O,    KC_P,    KC_CAPS,
//   KC_ESC,  KC_A,    KC_S,    KC_D,    KC_F,  KC_G,   KC_H,    KC_J,   KC_K,    KC_L,    KC_SCLN, KC_QUOT,
//   NAV,     KC_Z,    KC_X,    KC_C,    KC_V,  KC_B,   KC_N,    KC_M,   KC_COMM, KC_DOT,  KC_SLSH, KC_RSFT,
//   KC_LSFT, KC_LCTL, KC_LALT, KC_LGUI, LOWER, KC_SPC, KC_BSPC, RAISE,  IPAD, _______, _______, KC_ENT
// ),

[_COLEMAK] = LAYOUT_planck_grid(
  KC_TAB,  KC_Q,    KC_W,    KC_F,    KC_P,  KC_B,   KC_J,    KC_L,   KC_U,    KC_Y,    KC_SCLN, KC_CAPS,
  KC_ESC,  KC_A,    KC_R,    KC_S,    KC_T,  KC_G,   KC_M,    KC_N,   KC_E,    KC_I,    KC_O,    KC_QUOT,
  NAV,     KC_Z,    KC_X,    KC_C,    KC_D,  KC_V,   KC_K,    KC_H,   KC_COMM, KC_DOT,  KC_SLSH, KC_RSFT,
  KC_LSFT, KC_LCTL, KC_LALT, KC_LGUI, LOWER, SPACE,  KC_BSPC, RAISE,  KC_RALT, _______, _______, KC_ENT
),

/* Lower
 * ,-----------------------------------------------------------------------------------.
 * | Next |   _  |   &  |   *  |   `  |   ~  |      |   [  |   ]  |      |      |      |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * | Vol+ |      |  $   |  %   |  ^   |  \   |      |  (   |   )  |   <  |   >  |      |
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * | Vol- |      |  !   |   @  |  #   |  |   |      |   {  |   }  |      |      |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | Play |      |      |      |      |      |      |      |      |      |      |      |
 * `-----------------------------------------------------------------------------------'
 */
[_LOWER] = LAYOUT_planck_grid(
  KC_MNXT, KC_UNDS, KC_AMPR, KC_ASTR, KC_GRV,  KC_TILD, XXXXXXX, KC_LBRC, KC_RBRC, XXXXXXX, XXXXXXX, XXXXXXX,
  KC_VOLU, XXXXXXX, KC_DLR,  KC_PERC, KC_CIRC, KC_BSLS, XXXXXXX, KC_LPRN, KC_RPRN, KC_QUOT, KC_DQUO, XXXXXXX,
  KC_VOLD, XXXXXXX, KC_EXLM, KC_AT,   KC_HASH, KC_PIPE, XXXXXXX, KC_LCBR, KC_RCBR, KC_LABK, KC_RABK, XXXXXXX,
  KC_MPLY, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______
),

/* Raise
 * ,-----------------------------------------------------------------------------------.
 * |      |   _  |  7   |  8   |  9   |      |      |      |      |      |      |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |  4   |  5   |  6   |      |      |   +  |   -  |   *  |   /  |      |
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * |      |  0   |  1   |  2   |  3   |      |      |   ^  |  =   |      |      |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |  <-  |      |      |      |      |      |      |      |      |      |      |  ->  |
 * `-----------------------------------------------------------------------------------'
 */
[_RAISE] = LAYOUT_planck_grid(
  XXXXXXX, KC_UNDS, KC_7,    KC_8,    KC_9,    XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
  XXXXXXX, XXXXXXX, KC_4,    KC_5,    KC_6,    XXXXXXX, XXXXXXX, KC_PLUS, KC_MINS, KC_ASTR, KC_SLSH, XXXXXXX,
  XXXXXXX, KC_0,    KC_1,    KC_2,    KC_3,    XXXXXXX, XXXXXXX, KC_CIRC, KC_EQL,  XXXXXXX, XXXXXXX, XXXXXXX,
  CLEFT,   _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, CRIGHT
),


/* Adjust (Lower + Raise)
 * ,-----------------------------------------------------------------------------------.
 * |      | Reset|      |      |      |      |      |      |      |      |      | RGB  |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * |      |      |      |      |      |      |      |      |      |      |      |      |
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * |      |      |      |      |      |      |      | MIDI |      |      |      |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      |      |      |      |      |      |      |      |
 * `-----------------------------------------------------------------------------------'
 */
[_ADJUST] = LAYOUT_planck_grid(
  XXXXXXX, RESET,   XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, RGB_TOG,
  XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, RGB_MOD,
  XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
  _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______
),

/* Midi
 * ,-----------------------------------------------------------------------------------.
 * |  C   |  C#  |   D  |  D#  |   E  |   F  |  F#  |  G   |  G#  |  A   |  A#  |   B  |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * |  C   |  C#  |   D  |  D#  |   E  |   F  |  F#  |  G   |  G#  |  A   |  A#  |   B  |
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * |  C   |  C#  |   D  |  D#  |   E  |   F  |  F#  |  G   |  G#  |  A   |  A#  |   B  |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | SUST |      |      |      | CTRL |      |      | CTRL |      |      | QUIT | SUST |
 * `-----------------------------------------------------------------------------------'
 */
// [_MIDI] = LAYOUT_planck_grid(
//   MI_C_5,  MI_Cs_5, MI_D_5,  MI_Ds_5, MI_E_5,  MI_F_5,  MI_Fs_5, MI_G_5,  MI_Gs_5, MI_A_5,  MI_As_5, MI_B_5,
//   MI_C_4,  MI_Cs_4, MI_D_4,  MI_Ds_4, MI_E_4,  MI_F_4,  MI_Fs_4, MI_G_4,  MI_Gs_4, MI_A_4,  MI_As_4, MI_B_4,
//   MI_C_3,  MI_Cs_3, MI_D_3,  MI_Ds_3, MI_E_3,  MI_F_3,  MI_Fs_3, MI_G_3,  MI_Gs_3, MI_A_3,  MI_As_3, MI_B_3,
//   MI_SUS,  _______, _______, _______, MDCTRL,  _______, _______, MDCTRL,  _______, _______, COLEMAK,  MI_SUS
// ),

/* Midicontrol
 * ,-----------------------------------------------------------------------------------.
 * |      |      |      |      |      |      |      |      |      |      |      |      |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * |                              Octave Row                             |      |      |
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * |                                   Transpose Row                                   |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      |      |      |      |      |      |      |      |
 * `-----------------------------------------------------------------------------------'
 */
// [_MIDICTRL] = LAYOUT_planck_grid(
//   XXXXXXX,   XXXXXXX,   XXXXXXX,   XXXXXXX,   XXXXXXX,   XXXXXXX,   XXXXXXX,   XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,
//   MI_OCT_N2, MI_OCT_N1, MI_OCT_0,  MI_OCT_1,  MI_OCT_2,  MI_OCT_3,  MI_OCT_4,  MI_OCT_5,   MI_OCT_6,   MI_OCT_7,   XXXXXXX,    XXXXXXX,
//   MI_TRNS_0, MI_TRNS_1, MI_TRNS_2, MI_TRNS_3, MI_TRNS_4, MI_TRNS_5, MI_TRNS_6, MI_TRNS_N5, MI_TRNS_N4, MI_TRNS_N3, MI_TRNS_N2, MI_TRNS_N1,
//   _______,   _______,   _______,   _______,   _______,   _______,   _______,   _______,    _______,    _______,    _______,    _______
// ),


/* Nav
 * ,-----------------------------------------------------------------------------------.
 * |      |  F1  |  F2  |  F3  |  F4  |      |      |      |      |      |      |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |  F5  |  F6  |  F7  |  F8  |      | Left | Down |  Up  | Rght |      |      |
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * |      |  F9  |  F10 |  F11 |  F12 |      | PdDn | Lwrd | Rwrd | PgUp |      |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      |      |      |      |      |      |      |      |
 * `-----------------------------------------------------------------------------------'
 */
[_NAV] = LAYOUT_planck_grid(
  XXXXXXX, KC_F1,   KC_F2,   KC_F3,   KC_F4,   XXXXXXX, COPY,    UNDO,    XXXXXXX, XXXXXXX, PATSE,   XXXXXXX,
  XXXXXXX, KC_F5,   KC_F6,   KC_F7,   KC_F8,   XXXXXXX, KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT, XXXXXXX, XXXXXXX,
  XXXXXXX, KC_F9,   KC_F10,  KC_F11,  KC_F12,  XXXXXXX, KC_PGDN, LWORD,   RWORD,   KC_PGUP, XXXXXXX, XXXXXXX,
  XXXXXXX, _______, _______, _______, XXXXXXX, _______, _______, XXXXXXX, _______, _______, _______, XXXXXXX
)
};

layer_state_t layer_state_set_user(layer_state_t state) {

  const unsigned long ADJUST = ((1UL << _LOWER) | (1UL << _RAISE));
  if ((state & ADJUST) == ADJUST)   state |= 1UL << _ADJUST;
  else                                      state &= ~(1UL << _ADJUST);

  return state;
}


// |Mode |Description          |
// |-----|---------------------|
// |1    |Solid color          |
// |2-5  |Solid color breathing|
// |9-14 |Swirling rainbow     |

void startup_user (void) {
  rgblight_mode(9);
}

// void globe_mod(uint16_t keycode) {
//   register_code(KC_APFN);
//   register_code(keycode);
//   unregister_code(keycode);
//   unregister_code(KC_APFN);
// }

// bool process_record_user(uint16_t keycode, keyrecord_t *record) {
//   switch (keycode) {
//     case COLEMAK:
//       if (record->event.pressed) {
//         set_single_persistent_default_layer(_COLEMAK);
//       }
//       return false;
//   }
//   return true;
// }
