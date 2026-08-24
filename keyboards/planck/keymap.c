#include QMK_KEYBOARD_H

enum layers {
  _COLEMAK,
  _NAV,
  _LOWER,
  _RAISE,
  _ADJUST,
};

#define LOWER  MO(_LOWER)
#define RAISE  MO(_RAISE)

#define NAV_SP LT(_NAV, KC_SPC)
#define CMD_BK MT(MOD_LGUI, KC_BSPC)

#define SCR_RGH C(KC_RIGHT)
#define SCR_LFT C(KC_LEFT)

// HOME ROW MOD
#define MOD_S MT(MOD_LGUI, KC_S)
#define MOD_E MT(MOD_LGUI, KC_E)
#define MOD_T MT(MOD_LCTL, KC_T)
#define MOD_N MT(MOD_LCTL, KC_N)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [_COLEMAK] = LAYOUT_planck_grid(
        KC_TAB , KC_Q   , KC_W   , KC_F   , KC_P   , KC_B   , KC_J   , KC_L   , KC_U   , KC_Y   , KC_SCLN, XXXXXXX,
        KC_ESC , KC_A   , KC_R   , MOD_S  , MOD_T  , KC_G   , KC_M   , MOD_N  , MOD_E  , KC_I   , KC_O   , KC_QUOT,
        XXXXXXX, KC_Z   , KC_X   , KC_C   , KC_D   , KC_V   , KC_K   , KC_H   , KC_COMM, KC_DOT , KC_SLSH, XXXXXXX,
        KC_LSFT, XXXXXXX, XXXXXXX, KC_LWIN, LOWER  , NAV_SP , KC_BSPC, RAISE  , XXXXXXX, XXXXXXX, XXXXXXX, KC_ENT
    ),
    [_NAV] = LAYOUT_planck_grid(
        XXXXXXX, KC_F12 , KC_F7  , KC_F8  , KC_F9  , XXXXXXX, XXXXXXX, KC_PGDN, KC_PGUP, XXXXXXX, XXXXXXX, XXXXXXX,
        XXXXXXX, KC_F11 , KC_F4  , KC_F5  , KC_F6  , XXXXXXX, KC_LEFT, KC_DOWN, KC_UP  , KC_RGHT, XXXXXXX, XXXXXXX,
        XXXXXXX, KC_F10 , KC_F1  , KC_F2  , KC_F3  , XXXXXXX, XXXXXXX, MS_BTN1, MS_BTN2, XXXXXXX, XXXXXXX, XXXXXXX,
        _______, XXXXXXX, XXXXXXX, XXXXXXX, _______, _______, _______, _______, XXXXXXX, XXXXXXX, XXXXXXX, _______
    ),
    [_LOWER] = LAYOUT_planck_grid(
        XXXXXXX, KC_UNDS, KC_AMPR, KC_ASTR, KC_GRV , KC_TILD, XXXXXXX, KC_LBRC, KC_RBRC, XXXXXXX, XXXXXXX, XXXXXXX,
        XXXXXXX, XXXXXXX, KC_DLR , KC_PERC, KC_CIRC, KC_BSLS, XXXXXXX, KC_LPRN, KC_RPRN, KC_QUOT, KC_DQUO, XXXXXXX,
        XXXXXXX, XXXXXXX, KC_EXLM, KC_AT  , KC_HASH, KC_PIPE, XXXXXXX, KC_LCBR, KC_RCBR, KC_LABK, KC_RABK, XXXXXXX,
        SCR_LFT, XXXXXXX, XXXXXXX, XXXXXXX, _______, _______, _______, _______, XXXXXXX, XXXXXXX, XXXXXXX, SCR_RGH
    ),
    [_RAISE] = LAYOUT_planck_grid(
        XXXXXXX, KC_UNDS, KC_7   , KC_8   , KC_9   , XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
        XXXXXXX, XXXXXXX, KC_4   , KC_5   , KC_6   , XXXXXXX, XXXXXXX, KC_PLUS, KC_MINS, KC_ASTR, KC_SLSH, XXXXXXX,
        XXXXXXX, KC_0   , KC_1   , KC_2   , KC_3   , XXXXXXX, XXXXXXX, KC_CIRC, KC_EQL , XXXXXXX, XXXXXXX, XXXXXXX,
        SCR_LFT, XXXXXXX, XXXXXXX, XXXXXXX, _______, _______, _______, _______, XXXXXXX, XXXXXXX, XXXXXXX, SCR_RGH
    ),
    [_ADJUST] = LAYOUT_planck_grid(
        XXXXXXX, QK_BOOT, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, UG_TOGG,
        XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, UG_NEXT,
        XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
        XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, _______, _______, _______, _______, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX
    )
};

void keyboard_post_init_user(void) {
    if (!eeconfig_read_user()) {
        set_single_persistent_default_layer(_COLEMAK);
        eeconfig_update_user(1);
    }
}

layer_state_t layer_state_set_user(layer_state_t state) {
  return update_tri_layer_state(state, _LOWER, _RAISE, _ADJUST);
}

// |Mode |Description          |
// |-----|---------------------|
// |1    |Solid color          |
// |2-5  |Solid color breathing|
// |9-14 |Swirling rainbow     |

void startup_user (void) {
  rgblight_mode(9);
}
