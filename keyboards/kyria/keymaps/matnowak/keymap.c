/* Copyright 2019 Thomas Baart <thomas@splitkb.com>
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */
#include QMK_KEYBOARD_H

enum layers {
    _QWERTY = 0,
    _LOWER,
    _RAISE,
    _STANDARD,
    _ADJUST,
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [_QWERTY] = LAYOUT(
      KC_TAB,           KC_Q,   KC_W,   KC_E,   KC_R,   KC_T,                                      KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_PIPE,
      KC_CAPSLOCK,    MT(MOD_LSFT, KC_A),   LCTL_T(KC_S),   KC_D,   KC_F,   KC_G,                                       KC_H,    KC_J,    KC_K,    LCTL_T(KC_L),    LSFT_T(KC_SCLN), KC_QUOT,
      KC_LSFT, KC_Z,   KC_X,   KC_C,   KC_V,   KC_B,   KC_LSFT, KC_LEAD,                                       TG(_RAISE), KC_LSFT, KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, KC_LSFT,

        KC_LSFT, MT(MOD_LALT, KC_ENT), LGUI_T(KC_SPC),  LT(_LOWER, KC_SPC), LT(_RAISE, KC_ESC),         MT(MOD_LCTL, KC_ENT), LT(_LOWER, KC_SPC), KC_SPC,  MT(MOD_LALT, KC_BSPC), KC_RALT
    ),

    [_STANDARD] = LAYOUT(
      KC_TAB,           KC_Q,   KC_W,   KC_E,   KC_R,   KC_T,                                      KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_PIPE,
      KC_CAPSLOCK,    KC_A,   KC_S,   KC_D,   KC_F,   KC_G,                                       KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_QUOT,
      KC_LSFT, KC_Z,   KC_X,   KC_C,   KC_V,   KC_B,   TG(_STANDARD), KC_LEAD,                                       TG(_RAISE), KC_LSFT, KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, KC_LSFT,

        KC_LGUI, MT(MOD_LALT, KC_ENT), LGUI_T(KC_SPC),  LT(_LOWER, KC_SPC), LT(_RAISE, KC_ESC),         MT(MOD_LCTL, KC_ENT), LT(_LOWER, KC_SPC), KC_SPC,  MT(MOD_LALT, KC_BSPC), KC_RALT
    ),

    [_LOWER] = LAYOUT(
      _______, KC_EXLM, KC_AT,   KC_LCBR, KC_RCBR, KC_PIPE,                                     _______, _______, _______, _______, _______, KC_BSLS,
      _______, KC_HASH, KC_DLR,  KC_LPRN, KC_RPRN, KC_GRV,                                      KC_PLUS, KC_MINS, KC_SLSH, KC_ASTR, KC_PERC, KC_QUOT,
      _______, KC_PERC, KC_CIRC, KC_LBRC, KC_RBRC, KC_TILD, _______, _______, _______, _______, KC_AMPR, KC_EQL,  KC_COMM, KC_DOT,  KC_SLSH, KC_MINS,
                                 _______, _______, _______, KC_SCLN, KC_EQL,  KC_EQL,  KC_SCLN, _______, _______, _______
    ),

    [_RAISE] = LAYOUT(
      TG(_ADJUST), KC_1, 	  KC_2,    KC_3,    KC_4,    KC_5,                                      KC_6, KC_7, KC_8,    KC_9,    KC_0,    _______,
      _______, _______, KC_MPRV, KC_MPLY, KC_MNXT, KC_VOLU,                                  KC_LEFT, KC_DOWN, KC_UP, KC_RIGHT, _______, _______,
      _______, _______, _______, _______, KC_MUTE, KC_VOLD, TG(_STANDARD), _______, TG(_RAISE), _______, KC_1, KC_2, KC_3, _______, _______, _______,
                                 _______, _______, _______, _______, _______, _______, _______, KC_0, _______, _______
    ),

    [_ADJUST] = LAYOUT(
      TG(_ADJUST), KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,                                       KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  _______,
      _______, RGB_TOG, RGB_SAI, RGB_HUI, RGB_VAI, RGB_MOD,                                     _______, _______, _______, KC_F11,  KC_F12,  _______,
      _______, _______, RGB_SAD, RGB_HUD, RGB_VAD, RGB_RMOD,_______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
                                 _______, _______, _______, _______, _______, _______, _______, _______, _______, _______
    ),

//     [_LAYERINDEX] = LAYOUT(
//       _______, _______, _______, _______, _______, _______,                                     _______, _______, _______, _______, _______, _______,
//       _______, _______, _______, _______, _______, _______,                                     _______, _______, _______, _______, _______, _______,
//       _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
//                                  _______, _______, _______, _______, _______, _______, _______, _______, _______, _______
//     ),
};

// layer_state_t layer_state_set_user(layer_state_t state) {
//    return update_tri_layer_state(state, _LOWER, _RAISE, _ADJUST);
//}

#ifdef OLED_DRIVER_ENABLE
oled_rotation_t oled_init_user(oled_rotation_t rotation) {
	return OLED_ROTATION_180;
}

static void render_kyria_logo(void) {
    static const char PROGMEM kyria_logo[] = {};
    oled_write_raw_P(kyria_logo, sizeof(kyria_logo));
}

static void render_qmk_logo(void) {
  static const char PROGMEM qmk_logo[] = {
    0x80,0x81,0x82,0x83,0x84,0x85,0x86,0x87,0x88,0x89,0x8a,0x8b,0x8c,0x8d,0x8e,0x8f,0x90,0x91,0x92,0x93,0x94,
    0xa0,0xa1,0xa2,0xa3,0xa4,0xa5,0xa6,0xa7,0xa8,0xa9,0xaa,0xab,0xac,0xad,0xae,0xaf,0xb0,0xb1,0xb2,0xb3,0xb4,
    0xc0,0xc1,0xc2,0xc3,0xc4,0xc5,0xc6,0xc7,0xc8,0xc9,0xca,0xcb,0xcc,0xcd,0xce,0xcf,0xd0,0xd1,0xd2,0xd3,0xd4,0};

  oled_write_P(qmk_logo, false);
}

static void render_status(void) {
    // QMK Logo and version information
    render_qmk_logo();
    oled_write_P(PSTR("Kyria rev1.0\n\n"), false);

    // Host Keyboard Layer Status
    oled_write_P(PSTR("Layer: "), false);
    switch (get_highest_layer(layer_state)) {
        case _QWERTY:
            oled_write_P(PSTR("Default\n"), false);
            break;
        case _LOWER:
            oled_write_P(PSTR("Lower\n"), false);
            break;
        case _RAISE:
            oled_write_P(PSTR("Raise\n"), false);
            break;
        case _ADJUST:
            oled_write_P(PSTR("Adjust\n"), false);
            break;
        default:
            oled_write_P(PSTR("Undefined\n"), false);
    }

    // Host Keyboard LED Status
    uint8_t led_usb_state = host_keyboard_leds();
    oled_write_P(IS_LED_ON(led_usb_state, USB_LED_CAPS_LOCK) ? PSTR("CAPLCK ") : PSTR("       "), false);
}

void oled_task_user(void) {
    if (is_keyboard_master()) {
        render_status(); // Renders the current keyboard state (layer, lock, caps, scroll, etc)
    } else {
        render_kyria_logo();
    }
}
#endif

enum combos {
  FD_TAB,
  JK_ESC,
};

const uint16_t PROGMEM fd_combo[] = {KC_F, KC_D, COMBO_END};
const uint16_t PROGMEM jk_combo[] = {KC_J, KC_K, COMBO_END};


combo_t key_combos[COMBO_COUNT] = {
  [JK_ESC] = COMBO(jk_combo, KC_ESC),
  [FD_TAB] = COMBO(fd_combo, KC_TAB),
};


LEADER_EXTERNS();

void matrix_scan_user(void) {
  LEADER_DICTIONARY() {
    leading = false;
    leader_end();
    // Replace the sequences below with your own sequences.
    SEQ_ONE_KEY(KC_T) {
      // When I press KC_LEAD and then T, this sends CTRL + SHIFT + T
      SEND_STRING(SS_LGUI(SS_LSFT("t")));
    }
    SEQ_THREE_KEYS(KC_P, KC_G, KC_T) {
        SEND_STRING("/unlabel ~triage \n/label ~\"workflow::needs-priority\" \n/estimate ");
    }
  }
}

