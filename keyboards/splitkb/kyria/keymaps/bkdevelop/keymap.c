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
    _GAMING,
    _COLEMAK_DH,
    _NAV,
    _SYM,
    _FUNCTION,
    _ADJUST,
};

// Aliases for readability
#define QWERTY DF(_QWERTY)
#define GAMING DF(_GAMING)
#define COLEMAK  DF(_COLEMAK_DH)

#define SYM    MO(_SYM)
#define NAV    MO(_NAV)
#define FKEYS MO(_FUNCTION)
#define ADJUST MO(_ADJUST)

// german chars
enum unicode_names {
    AE_LC,
    AE_UC,
    OE_LC,
    OE_UC,
    UE_LC,
    UE_UC,
    SZ,
    EUR,
    GBP,
};

const uint32_t PROGMEM unicode_map[] = {
    [AE_LC] = 0x00E4, // ä
    [AE_UC] = 0x00C4, // Ä
    [OE_LC] = 0x00F6, // ö
    [OE_UC] = 0x00D6, // Ö
    [UE_LC] = 0x00FC, // ü
    [UE_UC] = 0x00DC, // Ü
    [SZ]    = 0x00DF, // ß
    [EUR]   = 0x20AC, // €
    [GBP]   = 0x00A3  // £
};

// Note: LAlt/Enter (ALT_ENT) is not the same thing as the keyboard shortcut Alt+Enter.
// The notation `mod/tap` denotes a key that activates the modifier `mod` when held down, and
// produces the key `tap` when tapped (i.e. pressed and released).

// clang-format off
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

    [_QWERTY] = LAYOUT(
    KC_ESC  , KC_Q , KC_W , KC_E  , KC_R  , KC_T ,                                               KC_Y , KC_U ,  KC_I ,   KC_O ,  KC_P , KC_BSPC,
    KC_TAB  , KC_A , KC_S , KC_D  , KC_F  , KC_G ,                                               KC_H , KC_J ,  KC_K ,   KC_L ,KC_SCLN, KC_QUOT,
    KC_LALT , KC_Z , KC_X , KC_C  , KC_V  , KC_B    , KC_DEL , KC_CAPS ,       FKEYS , KC_LGUI , KC_N , KC_M ,KC_COMM, KC_DOT ,KC_SLSH, KC_BSLS,
                            ADJUST , NAV , KC_LSFT , KC_SPC , KC_LCTL ,       SYM , KC_ENT , KC_LBRC , KC_RBRC , KC_RALT
    ),

    [_GAMING] = LAYOUT(
    KC_TAB, KC_G,  KC_Q, KC_W , KC_E   , KC_R,                                        KC_Y   , KC_U   , KC_I,    KC_O,   KC_P   , KC_BSPC,
    KC_T, KC_LSFT, KC_A, KC_S , KC_D   , KC_F,                                        KC_BSLS, KC_J   , KC_K,    KC_L,   KC_SCLN, KC_DEL,
    KC_B, KC_LCTL, KC_Z, KC_X , KC_C   , KC_V, KC_H, LT(_SYM, KC_CAPS),     FKEYS  , KC_LGUI, KC_RBRC, KC_QUOT, KC_COMM, KC_DOT, KC_SLSH, KC_RALT,
                         LT(_FUNCTION, KC_ESC), KC_LALT, KC_N, KC_SPC, KC_M,        SYM  , KC_ENT , KC_LBRC, NAV  , QWERTY
    ),

    [_COLEMAK_DH] = LAYOUT(
     KC_ESC  , KC_Q ,  KC_W   ,  KC_F  ,   KC_P ,   KC_B ,                                        KC_J,   KC_L ,  KC_U ,   KC_Y ,KC_SCLN, KC_BSPC,
     KC_TAB  , KC_A ,  KC_R   ,  KC_S  ,   KC_T ,   KC_G ,                                        KC_M,   KC_N ,  KC_E ,   KC_I ,  KC_O , KC_QUOT,
     KC_LALT , KC_Z ,  KC_X   ,  KC_C  ,   KC_D ,   KC_V , KC_DEL , KC_CAPS ,     FKEYS , KC_LGUI , KC_K,   KC_H ,KC_COMM, KC_DOT ,KC_SLSH, KC_BSLS,
                            ADJUST , NAV , KC_LSFT , KC_SPC , KC_LCTL ,       SYM , KC_ENT , KC_LBRC , KC_RBRC , KC_RALT
    ),

/*
 * Nav Layer: Media, navigation
 *
 * ,-------------------------------------------.                              ,-------------------------------------------.
 * |        |      |      |      |      |      |                              | PgUp | Home |M Play| End  | VolUp| Delete |
 * |--------+------+------+------+------+------|                              |------+------+------+------+------+--------|
 * |        |  GUI |  Alt | Ctrl | Shift|      |                              | ←    |   ↓  |   ↑  |   →  | VolDn| Insert |
 * |--------+------+------+------+------+------+-------------.  ,-------------+------+------+------+------+------+--------|
 * |        |      |      |      |      |      |      |ScLck |  |      |      | PgDn |M Prev| Pause|M Next|VolMut| PrtSc  |
 * `----------------------+------+------+------+------+------|  |------+------+------+------+------+----------------------'
 *                        |      |      |      |      |      |  |      |      |      |      |      |
 *                        |      |      |      |      |      |  |      |      |      |      |      |
 *                        `----------------------------------'  `----------------------------------'
 */
    [_NAV] = LAYOUT(
      _______, _______, _______, _______, _______, _______,                                        KC_PGUP, KC_HOME, KC_MPLY , KC_END , KC_VOLU, KC_DEL,
      _______, KC_LGUI, KC_LALT, KC_LCTL, KC_LSFT, _______,                                        KC_LEFT, KC_DOWN, KC_UP   , KC_RGHT, KC_VOLD, KC_INS,
      _______, _______, _______, _______, _______, _______, _______, KC_SCRL,    _______, _______, KC_PGDN, KC_MPRV, KC_PAUSE, KC_MNXT, KC_MUTE, KC_PSCR,
                                 _______, _______, _______, _______, _______,    _______, _______, _______, _______, _______
    ),

    [_SYM] = LAYOUT(
    KC_GRV,  KC_1, KC_2, KC_3,    KC_4,    KC_5,                                             KC_6,         KC_7,            KC_8,             KC_9,             KC_0,       KC_MINS,
    KC_PIPE, KC_5, KC_6, KC_7,    KC_8,    _______,                                          _______,      KC_LSFT,         KC_LCTL,          KC_LALT,          KC_LGUI,    KC_EQL,
    KC_TILD, KC_9, KC_0, KC_MINS, KC_EQL,  _______, KC_TRNS, KC_TRNS,      _______, _______, XP(EUR, GBP), XP(AE_LC,AE_UC), XP(OE_LC, OE_UC), XP(UE_LC, UE_UC), XP(SZ, SZ), _______,
                         _______, _______, _______, KC_TRNS, _______,      _______, KC_TRNS, _______,      _______,         KC_TRNS
    ),

    [_FUNCTION] = LAYOUT(
     _______, KC_F1, KC_F2, KC_F3,    KC_F4,   KC_F5,                                            KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,
     _______, KC_F5, KC_F6, KC_F7,    KC_F8,   _______,                                          _______, KC_LSFT, KC_LCTL, KC_LALT, KC_LGUI, KC_F12,
     _______, KC_F9, KC_F10, KC_F11,  KC_F12,  _______, KC_TRNS, KC_TRNS,      _______, _______, _______, _______, _______, _______, _______, _______,
                             _______, _______, _______, KC_TRNS, _______,      _______, KC_TRNS, _______, _______, KC_TRNS
    ),
/*
 * Adjust Layer: Default layer settings, RGB
 *
 * ,------------------------------------------------------.                                       ,-------------------------------------------.
 * |        |      |      | QWERTY | UNICODE_WINC  |      |                                       |      |      |      |      |      |        |
 * |--------+------+------+--------+---------------+------|                                       |------+------+------+------+------+--------|
 * |        |      |      | Gaming | UNICODE_LINUX |      |                                       | TOG  | SAI  | HUI  | VAI  | MOD  |        |
 * |--------+------+------+--------+---------------+------+------+--------.           ,-------------+------+------+------+------+------+--------|
 * |        |      |      |        | UNICODE_MACOS |      |      | NumLck |           |      |      |      | SAD  | HUD  | VAD  | RMOD |        |
 * `----------------------+--------+---------------+------+------+--------|           |------+------+------+------+------+----------------------'
 *                        |        |               |      |      |        |           |      |      |      |      |      |
 *                        |        |               |      |      |        |           |      |      |      |      |      |
 *                        `-----------------------------------------------'           `----------------------------------'
 */
    [_ADJUST] = LAYOUT(
      _______, _______, _______, QWERTY , UC_WINC, _______,                                                _______, _______, _______, _______, _______ , _______,
      _______, _______, _______, GAMING , UC_LINX, _______,                                                RGB_TOG, RGB_SAI, RGB_HUI, RGB_VAI, RGB_MOD , _______,
      _______, _______, _______, COLEMAK, UC_MAC, _______,_______, KC_NUM_LOCK,         _______, _______, _______, RGB_SAD, RGB_HUD, RGB_VAD, RGB_RMOD, _______,
                                 _______, _______, _______,_______, _______,             _______, _______, _______, _______, _______
    ),

// /*
//  * Layer template
//  *
//  * ,-------------------------------------------.                              ,-------------------------------------------.
//  * |        |      |      |      |      |      |                              |      |      |      |      |      |        |
//  * |--------+------+------+------+------+------|                              |------+------+------+------+------+--------|
//  * |        |      |      |      |      |      |                              |      |      |      |      |      |        |
//  * |--------+------+------+------+------+------+-------------.  ,-------------+------+------+------+------+------+--------|
//  * |        |      |      |      |      |      |      |      |  |      |      |      |      |      |      |      |        |
//  * `----------------------+------+------+------+------+------|  |------+------+------+------+------+----------------------'
//  *                        |      |      |      |      |      |  |      |      |      |      |      |
//  *                        |      |      |      |      |      |  |      |      |      |      |      |
//  *                        `----------------------------------'  `----------------------------------'
//  */
//     [_LAYERINDEX] = LAYOUT(
//       _______, _______, _______, _______, _______, _______,                                     _______, _______, _______, _______, _______, _______,
//       _______, _______, _______, _______, _______, _______,                                     _______, _______, _______, _______, _______, _______,
//       _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
//                                  _______, _______, _______, _______, _______, _______, _______, _______, _______, _______
//     ),
};

/* The default OLED and rotary encoder code can be found at the bottom of qmk_firmware/keyboards/splitkb/kyria/rev1/rev1.c
 * These default settings can be overriden by your own settings in your keymap.c
 * For your convenience, here's a copy of those settings so that you can uncomment them if you wish to apply your own modifications.
 * DO NOT edit the rev1.c file; instead override the weakly defined default functions by your own.
 */

#ifdef OLED_ENABLE
oled_rotation_t oled_init_user(oled_rotation_t rotation) { return OLED_ROTATION_180; }

bool oled_task_user(void) {
    if (is_keyboard_master()) {
        // QMK Logo and version information
        // clang-format off
        static const char PROGMEM qmk_logo[] = {
            0x80,0x81,0x82,0x83,0x84,0x85,0x86,0x87,0x88,0x89,0x8a,0x8b,0x8c,0x8d,0x8e,0x8f,0x90,0x91,0x92,0x93,0x94,
            0xa0,0xa1,0xa2,0xa3,0xa4,0xa5,0xa6,0xa7,0xa8,0xa9,0xaa,0xab,0xac,0xad,0xae,0xaf,0xb0,0xb1,0xb2,0xb3,0xb4,
            0xc0,0xc1,0xc2,0xc3,0xc4,0xc5,0xc6,0xc7,0xc8,0xc9,0xca,0xcb,0xcc,0xcd,0xce,0xcf,0xd0,0xd1,0xd2,0xd3,0xd4,0};
        // clang-format on

        oled_write_P(qmk_logo, false);
        oled_write_P(PSTR("Bens Kyria\n\n"), false);

        // Host Keyboard Layer Status
        oled_write_P(PSTR("Layer: "), false);
        switch (get_highest_layer(layer_state | default_layer_state)) {
            case _QWERTY:
                oled_write_P(PSTR("QWERTY\n"), false);
                break;
            case _GAMING:
                oled_write_P(PSTR("Gaming\n"), false);
                break;
            case _COLEMAK_DH:
                oled_write_P(PSTR("COLEMAK\n"), false);
                break;
            case _NAV:
                oled_write_P(PSTR("Nav\n"), false);
                break;
            case _SYM:
                oled_write_P(PSTR("Sym\n"), false);
                break;
            case _FUNCTION:
                oled_write_P(PSTR("Function\n"), false);
                break;
            case _ADJUST:
                oled_write_P(PSTR("Adjust\n"), false);
                break;
            default:
                oled_write_P(PSTR("Undefined\n"), false);
        }

        // Write host Keyboard LED Status to OLEDs
        led_t led_usb_state = host_keyboard_led_state();
        oled_write_P(led_usb_state.num_lock ? PSTR("NUMLCK ") : PSTR("       "), false);
        oled_write_P(led_usb_state.caps_lock ? PSTR("CAPLCK ") : PSTR("       "), false);
        oled_write_P(led_usb_state.scroll_lock ? PSTR("SCRLCK ") : PSTR("       "), false);
    } else {
        // clang-format off
        static const char PROGMEM bujin[] = {
        // 'bujin', 128x64px
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x80, 0xc0, 0xc0, 0x60,
        0x30, 0x30, 0x18, 0x18, 0x0c, 0x0c, 0x0c, 0x06, 0x06, 0x06, 0x06, 0x03, 0x03, 0x03, 0x03, 0x03,
        0x03, 0x03, 0x13, 0x73, 0xf3, 0xf6, 0xf6, 0xf6, 0x66, 0x0c, 0x0c, 0x0c, 0x18, 0x18, 0x30, 0x30,
        0x60, 0xc0, 0xc0, 0x80, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x80, 0xc0, 0xc0, 0x60,
        0x30, 0x30, 0x18, 0x18, 0x0c, 0x0c, 0x0c, 0x06, 0x06, 0x02, 0x02, 0x03, 0x01, 0x01, 0x01, 0x01,
        0x01, 0x01, 0x01, 0x03, 0x03, 0x02, 0x06, 0x0e, 0x1e, 0x3c, 0x7c, 0xfc, 0xf8, 0xf8, 0xf0, 0xf0,
        0xe0, 0xc0, 0xc0, 0x80, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
        0x00, 0x00, 0x00, 0x00, 0x00, 0x80, 0xe0, 0x70, 0x38, 0x0c, 0x06, 0x03, 0x01, 0x01, 0x00, 0x00,
        0x00, 0x00, 0x00, 0x20, 0x60, 0x60, 0xe1, 0xe3, 0xe7, 0xe7, 0xef, 0xef, 0xef, 0xef, 0xef, 0xef,
        0xef, 0xef, 0xef, 0xff, 0xff, 0xff, 0xff, 0xf1, 0xf0, 0xf0, 0xe0, 0x40, 0x06, 0x1e, 0xfc, 0xfc,
        0xf8, 0xf8, 0xe1, 0xc1, 0x03, 0x06, 0x0c, 0x38, 0x70, 0xe0, 0x80, 0x00, 0x00, 0x00, 0x00, 0x00,
        0x00, 0x00, 0x00, 0x00, 0x00, 0x80, 0xe0, 0x70, 0x38, 0x0c, 0x06, 0x03, 0x01, 0x01, 0x00, 0x00,
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x80, 0xc0, 0xe0, 0xe0,
        0xe0, 0xe0, 0xc0, 0x80, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x03, 0x1f, 0x7f, 0xff,
        0xff, 0xff, 0xff, 0xff, 0xff, 0xfe, 0xfc, 0xf8, 0xf0, 0xe0, 0x80, 0x00, 0x00, 0x00, 0x00, 0x00,
        0x00, 0x80, 0xf0, 0x7c, 0x0f, 0x03, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
        0x00, 0x00, 0x04, 0x0c, 0xfc, 0xf8, 0xf8, 0xf0, 0x01, 0x01, 0xff, 0xff, 0xff, 0xff, 0x71, 0x39,
        0x39, 0x39, 0x9d, 0x9f, 0xff, 0xff, 0xff, 0x9d, 0x1d, 0x09, 0x00, 0x00, 0x02, 0x87, 0x07, 0x07,
        0x07, 0x07, 0x03, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x03, 0x0f, 0x7c, 0xf0, 0x80, 0x00,
        0x00, 0x80, 0xf0, 0x7c, 0x0f, 0x03, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x07, 0x0f, 0x1f, 0x1f,
        0x1f, 0x1f, 0x0f, 0x07, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x80, 0xe0, 0xff,
        0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xfc, 0xf0, 0x80, 0x00,
        0xf8, 0xff, 0x07, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
        0x18, 0x38, 0x78, 0x78, 0x7f, 0x7f, 0x7f, 0x7f, 0x7e, 0xf8, 0xff, 0xff, 0xff, 0xff, 0x1e, 0x1f,
        0x0f, 0x0f, 0x07, 0xc7, 0xe3, 0xe3, 0xcf, 0x9f, 0xbf, 0x7c, 0xf8, 0xf0, 0xe0, 0xc3, 0xc7, 0xfe,
        0xfc, 0xf8, 0xe0, 0x80, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x07, 0xff, 0xf8,
        0xf8, 0xff, 0x07, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
        0x00, 0x00, 0x00, 0x00, 0x80, 0x80, 0xc0, 0xc0, 0xe0, 0xf0, 0xf8, 0xf8, 0xfc, 0xff, 0xff, 0xff,
        0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xf8,
        0x1f, 0xff, 0xe0, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
        0x38, 0x78, 0xf8, 0xf8, 0xf8, 0xf8, 0xfc, 0xfc, 0xfe, 0xfe, 0x7c, 0x39, 0x01, 0xf9, 0xfc, 0xf8,
        0xf0, 0x70, 0x70, 0x70, 0xff, 0xff, 0xff, 0xfb, 0x30, 0x30, 0x38, 0xfd, 0xfd, 0xf9, 0xf3, 0xe7,
        0xef, 0x0f, 0x0f, 0x07, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xe0, 0xff, 0x1f,
        0x1f, 0xff, 0xe0, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
        0x00, 0x00, 0x00, 0x00, 0x00, 0x80, 0xc0, 0xe0, 0xf0, 0xf8, 0xf8, 0xfe, 0xfe, 0xfe, 0xff, 0xff,
        0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
        0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0x1f,
        0x00, 0x01, 0x0f, 0x3e, 0xf0, 0xc0, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x80, 0xc0,
        0xe0, 0xf0, 0xf8, 0x7c, 0xff, 0xff, 0xff, 0xff, 0xff, 0x8f, 0x3f, 0x1e, 0x00, 0xff, 0xff, 0xff,
        0xff, 0xe7, 0xe7, 0xff, 0xff, 0xff, 0xff, 0xff, 0xe7, 0xe7, 0xe7, 0xff, 0xff, 0xff, 0x7f, 0x0f,
        0x01, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xc0, 0xf0, 0x3e, 0x0f, 0x01, 0x00,
        0x00, 0x01, 0x0f, 0x3e, 0xf0, 0xc0, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
        0x00, 0x00, 0xe0, 0xfc, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0x3f, 0x1f, 0x0f, 0x0f,
        0x0f, 0x0f, 0x1f, 0x3f, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
        0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0x3f, 0x0f, 0x01, 0x00,
        0x00, 0x00, 0x00, 0x00, 0x00, 0x01, 0x07, 0x0e, 0x1c, 0x30, 0x60, 0xc0, 0x86, 0x87, 0x07, 0x03,
        0x03, 0x01, 0x61, 0xf0, 0xff, 0xff, 0xff, 0xff, 0xff, 0x07, 0x00, 0x00, 0x00, 0x01, 0x03, 0x01,
        0x00, 0x00, 0x00, 0xf8, 0xff, 0xff, 0xff, 0xff, 0xf0, 0xc0, 0x01, 0x03, 0x03, 0x01, 0x00, 0x00,
        0x00, 0x00, 0x80, 0x80, 0xc0, 0x60, 0x30, 0x1c, 0x0e, 0x07, 0x01, 0x00, 0x00, 0x00, 0x00, 0x00,
        0x00, 0x00, 0x00, 0x00, 0x00, 0x01, 0x07, 0x0e, 0x1c, 0x30, 0x60, 0xc0, 0x80, 0x80, 0x00, 0x00,
        0x00, 0x00, 0x0f, 0x7f, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xfc, 0xf8, 0xf0, 0xf0,
        0xf0, 0xf0, 0xf8, 0xfc, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
        0xff, 0xff, 0xff, 0xff, 0xff, 0x7f, 0x3f, 0x1f, 0x0f, 0x07, 0x01, 0x00, 0x00, 0x00, 0x00, 0x00,
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x01, 0x03, 0x03, 0x06,
        0x0c, 0x0c, 0x18, 0x18, 0x31, 0x33, 0x33, 0x61, 0x60, 0x60, 0x60, 0xc0, 0xc0, 0xc0, 0xc0, 0xc0,
        0xc0, 0xc0, 0xc0, 0xc7, 0xcf, 0x6f, 0x67, 0x67, 0x63, 0x31, 0x30, 0x30, 0x18, 0x18, 0x0c, 0x0c,
        0x06, 0x03, 0x03, 0x01, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x01, 0x03, 0x03, 0x06,
        0x0c, 0x0c, 0x18, 0x18, 0x31, 0x33, 0x27, 0x6f, 0x7f, 0x7f, 0x7f, 0xff, 0xff, 0xff, 0xff, 0xff,
        0xff, 0xff, 0xff, 0xff, 0xff, 0x7f, 0x7f, 0x7f, 0x7f, 0x3f, 0x3f, 0x3f, 0x1f, 0x1f, 0x0f, 0x0f,
        0x07, 0x03, 0x03, 0x01, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00
        };
        // clang-format on
        oled_write_raw_P(bujin, sizeof(bujin));
    }
    return false;
}
#endif

