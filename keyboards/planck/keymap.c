#include QMK_KEYBOARD_H

enum layers {
  _COLEMAK,  // mac base
  _LINUX,    // linux base
  _NAV,
  _LOWER,
  _RAISE,
  _TMUX,
  _ADJUST,
};

#define LOWER  MO(_LOWER)
#define RAISE  MO(_RAISE)

#define NAV_SP LT(_NAV, KC_SPC)
#define CMD_BK MT(MOD_LGUI, KC_BSPC)

#define MAC_RGH C(KC_RIGHT)
#define MAC_LFT C(KC_LEFT)
#define LIN_RGH LCA(KC_RIGHT)
#define LIN_LFT LCA(KC_LEFT)

#define IS_LINUX() (get_highest_layer(default_layer_state) == _LINUX)

#define DF_MAC DF(_COLEMAK)
#define DF_LNX DF(_LINUX)

#define TMUX_LEADER LCTL(KC_B)
#define TMUX_CMD(x) tap_code16(TMUX_LEADER); tap_code16(x);

enum custom_keycodes {
    // TMUX
    T_WN_PV = SAFE_RANGE, // Prev Window
    T_WN_NX,              // Next Window
    T_WN_LS,              // Last Window
    T_PN_LF,              // Left Pane
    T_PN_DN,              // Down Pane
    T_PN_UP,              // Up Pane
    T_PN_RG,              // Right Pane

    T_WN_C,               // Create Window
    T_PN_CH,              // Create Pane Horizontal Split
    T_PN_CV,              // Create Pane Vertical Split

    T_PASTE,              // PASTE
    T_DTACH,              // DETACH
    T_ZOOM,               // ZOOM
    T_KILL,               // KILL
    T_RNAME,              // Rename Window

    T_MARK,               // MARK
    T_SWAP,               // SWAP
    T_YANK,               // Run tmux-yank
    T_CMD,                // (COMMAND) Colon mode

    // OS-aware desktop switching
    SCR_LFT,              // prev desktop: mac ctrl+left, linux ctrl+alt+left
    SCR_RGH,              // next desktop: mac ctrl+right, linux ctrl+alt+right
};

// HOME ROW MOD - mac: middle finger cmd, index ctrl
#define MOD_S MT(MOD_LGUI, KC_S)
#define MOD_E MT(MOD_LGUI, KC_E)
#define MOD_T MT(MOD_LCTL, KC_T)
#define MOD_N MT(MOD_LCTL, KC_N)

// HOME ROW MOD - linux: middle finger ctrl, index tmux
#define LNX_S MT(MOD_LCTL, KC_S)
#define LNX_E MT(MOD_LCTL, KC_E)
#define LNX_T LT(_TMUX, KC_T)
#define LNX_N LT(_TMUX, KC_N)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [_COLEMAK] = LAYOUT_planck_grid(
        KC_TAB , KC_Q   , KC_W   , KC_F   , KC_P   , KC_B   , KC_J   , KC_L   , KC_U   , KC_Y   , KC_SCLN, KC_CAPS,
        KC_ESC , KC_A   , KC_R   , MOD_S  , MOD_T  , KC_G   , KC_M   , MOD_N  , MOD_E  , KC_I   , KC_O   , KC_QUOT,
        XXXXXXX, KC_Z   , KC_X   , KC_C   , KC_D   , KC_V   , KC_K   , KC_H   , KC_COMM, KC_DOT , KC_SLSH, XXXXXXX,
        KC_LSFT, XXXXXXX, XXXXXXX, KC_LWIN, LOWER  , NAV_SP , KC_BSPC, RAISE  , XXXXXXX, XXXXXXX, XXXXXXX, KC_ENT
    ),
    [_LINUX] = LAYOUT_planck_grid(
        KC_TAB , KC_Q   , KC_W   , KC_F   , KC_P   , KC_B   , KC_J   , KC_L   , KC_U   , KC_Y   , KC_SCLN, KC_CAPS,
        KC_ESC , KC_A   , KC_R   , LNX_S  , LNX_T  , KC_G   , KC_M   , LNX_N  , LNX_E  , KC_I   , KC_O   , KC_QUOT,
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
    [_TMUX] = LAYOUT_planck_grid(
        XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, T_PASTE, XXXXXXX, XXXXXXX, T_MARK , T_SWAP , T_YANK , T_CMD  , T_WN_LS,
        XXXXXXX, XXXXXXX, T_RNAME, XXXXXXX, XXXXXXX, T_PN_CH, T_PN_LF, T_PN_DN, T_PN_UP, T_PN_RG, XXXXXXX, XXXXXXX,
        XXXXXXX, T_ZOOM , T_KILL , T_WN_C , T_DTACH, T_PN_CV, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
        T_WN_PV, XXXXXXX, XXXXXXX, XXXXXXX, _______, _______, _______, _______, XXXXXXX, XXXXXXX, XXXXXXX, T_WN_NX
    ),
    [_ADJUST] = LAYOUT_planck_grid(
        XXXXXXX, QK_BOOT, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, DF_LNX , XXXXXXX, XXXXXXX, XXXXXXX, UG_TOGG,
        XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, DF_MAC , XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, UG_NEXT,
        XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
        XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, _______, _______, _______, _______, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX
    )
};

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    if (record->event.pressed) {
        switch (keycode) {
            case T_WN_PV: TMUX_CMD(KC_P);       return false;
            case T_WN_NX: TMUX_CMD(KC_N);       return false;
            case T_WN_LS: TMUX_CMD(KC_L);       return false;
            case T_PN_LF: TMUX_CMD(KC_LEFT);    return false;
            case T_PN_DN: TMUX_CMD(KC_DOWN);    return false;
            case T_PN_UP: TMUX_CMD(KC_UP);      return false;
            case T_PN_RG: TMUX_CMD(KC_RIGHT);   return false;

            case T_WN_C : TMUX_CMD(KC_C);       return false;
            case T_PN_CH: TMUX_CMD(KC_PIPE);    return false;
            case T_PN_CV: TMUX_CMD(KC_MINS);    return false;

            case T_PASTE: TMUX_CMD(KC_RBRC);    return false;
            case T_ZOOM : TMUX_CMD(KC_Z);       return false;
            case T_KILL : TMUX_CMD(KC_X);       return false;
            case T_DTACH: TMUX_CMD(KC_D);       return false;
            case T_RNAME: TMUX_CMD(KC_COMM);    return false;

            case T_MARK : TMUX_CMD(KC_M);       return false;
            case T_SWAP : TMUX_CMD(KC_U);       return false;
            case T_YANK : TMUX_CMD(KC_Y);       return false;
            case T_CMD  : TMUX_CMD(KC_COLN);    return false;

            case SCR_LFT:
                tap_code16(IS_LINUX() ? LIN_LFT : MAC_LFT);
                return false;
            case SCR_RGH:
                tap_code16(IS_LINUX() ? LIN_RGH : MAC_RGH);
                return false;
        }
    }
    return true;
}

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
