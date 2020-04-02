#include QMK_KEYBOARD_H

extern keymap_config_t keymap_config;

// Each layer gets a name for readability, which is then used in the keymap matrix below.
// The underscores don't mean anything - you can have a layer called STUFF or any other name.
// Layer names don't all need to be of the same length, obviously, and you can also skip them
// entirely and just use numbers.
#define _BASE 0
#define _FN1 1

enum custom_keycodes {
  QWERTY = SAFE_RANGE,
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [_BASE] = LAYOUT_65(
    KC_ESC,  KC_GRV,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_LBRC, KC_RBRC,  KC_BSLS,  KC_DEL, \
    KC_TAB,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_COPY, KC_PSTE, KC_BSPC, KC_UNDO, \
    KC_CAPS, KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_FIND, KC_ENT,  KC_EQL, \
    OSM(MOD_LSFT), KC_LALT,    KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_N,    KC_M, KC_COMM,  KC_DOT, OSM(MOD_RSFT), KC_SLSH,   KC_MINS, \
    MO(_FN1), KC_PWR, KC_LGUI, KC_LCTL,KC_SPC,           KC_SPC,KC_SPC,  KC_RALT, KC_RCTL, KC_RGUI, KC_BRID, KC_BRIU, MO(_FN1)
  ),

  [_FN1] = LAYOUT_65(
    KC_PWR, KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12,  KC_PSCR,  KC_PAUS, KS_SLCK, \
    _______, KC_MUTE, KC_VOLD, KC_VOLU, KC_MPLY, KC_MSTP, _______, _______, _______, _______, _______, _______, _______, _______, KC_HOME, \
    _______, _______, KC_BRID, KC_BRIU, _______, _______, _______, KC_DEL, KC_END, _______, _______, _______, _______, KC_PGUP, \
    _______, _______, _______, _______, _______, RESET, KC_UNDO, KC_CUT, KC_COPY, KC_PSTE, KC_FIND, _______, KC_UP, KC_PGDN, \
    _______, _______, _______, _______, _______,          _______, _______, _______, _______, _______, KC_LEFT, KC_DOWN, KC_RGHT
  )
};

void encoder_update_user(uint8_t index, bool clockwise) {
    if (index == 0) {
        if (clockwise) {
            tap_code(KC_PGDN);
        } else {
            tap_code(KC_PGUP);
        }
    }
    else if (index == 1) {
        if (clockwise) {
            tap_code(KC_VOLU);
        } else {
            tap_code(KC_VOLD);
        }
    }
}
