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
#include "keymap_swedish.h"

#include <qp.h>
#include "pedro.qgf.h"
#include "gslogo.qgf.h"
#include "thintel15.qff.h"


enum layers {
    _QWERTY = 0,
    _DVORAK,
    _COLEMAK_DH,
    _NAV,
    _SYM,
    _FUNCTION,
    _ADJUST,
};

// Aliases for readability
#define QWERTY DF(_QWERTY)
#define COLEMAK DF(_COLEMAK_DH)
#define DVORAK DF(_DVORAK)

#define SYM MO(_SYM)
#define NAV MO(_NAV)
#define FKEYS MO(_FUNCTION)
#define ADJUST MO(_ADJUST)

#define CTL_ESC MT(MOD_LCTL, KC_ESC)
#define CTL_QUOT MT(MOD_RCTL, KC_QUOTE)
#define CTL_MINS MT(MOD_RCTL, KC_MINUS)
#define ALT_ENT MT(MOD_LALT, KC_ENT)
#define ___ KC_NO

// Note: LAlt/Enter (ALT_ENT) is not the same thing as the keyboard shortcut Alt+Enter.
// The notation `mod/tap` denotes a key that activates the modifier `mod` when held down, and
// produces the key `tap` when tapped (i.e. pressed and released).

// clang-format off
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
/*
 * Base Layer: QWERTY
 *
 * ,-------------------------------------------.                              ,--------------------------------------------.
 * |  Esc   |   Q  |   W  |   E  |   R  |   T  |                              |   Y  |   U  |   I  |   O  |   P  |    Å    |
 * |--------+------+------+------+------+------|                              |------+------+------+------+------+---------|
 * |Ctrl/Esc|   A  |   S  |   D  |   F  |   G  |                              |   H  |   J  |   K  |   L  |   Ö  |    Ä    |
 * |--------+------+------+------+------+------+-------------.  ,-------------+------+------+------+------+------+---------|
 * | LShift | Ctrl |   Z  |   X  |   C  |   V  | [ {  |CapsLk|  |F-keys|  ] } |   B  |   N  |   M  | ,  < | . >  |  RShift |
 * `----------------------+------+------+------+------+------|  |------+------+------+------+------+-----------------------'
 *                        |Adjust| LGUI | LAlt/| Bksp | Nav  |  | Sym  | Space| AltGr| RGUI | Menu |
 *                        |      |      | Enter|      |      |  |      |      |      |      |      |
 *                        `----------------------------------'  `----------------------------------'
 */
    [_QWERTY] = LAYOUT(
     KC_ESC  , KC_Q ,     KC_W   ,  KC_E  ,   KC_R ,   KC_T ,                                                                   KC_Y,   KC_U ,  KC_I ,   KC_O ,   KC_P ,   SE_ARNG,
     CTL_ESC , KC_A ,     KC_S   ,  KC_D  ,   KC_F ,   KC_G ,                                                                   KC_H,   KC_J ,  KC_K ,   KC_L ,   SE_ODIA, SE_ADIA,
     KC_LSFT , MOD_LCTL , KC_Z,     KC_X   ,  KC_C  ,  KC_V ,KC_LBRC,  KC_CAPS,           FKEYS  , KC_RBRC,     KC_B ,      KC_N,       KC_M ,       KC_COMM,     KC_DOT , KC_RSFT,
                                     ADJUST ,   KC_LGUI, ALT_ENT,        KC_BSPC ,  NAV   ,            SYM    , KC_SPC ,    KC_RALT, KC_RGUI, KC_APP
    ),


/*
 * Nav Layer: Media, navigation
 *
 * ,-------------------------------------------.                              ,-------------------------------------------.
 * |        |      |      |      |      |      |                              | PgUp | Home |   ↑  | End  |      |        |
 * |--------+------+------+------+------+------|                              |------+------+------+------+------+--------|
 * |        |  GUI |  Alt | Ctrl |      |      |                              | PgDn |  ←   |   ↓  |   →  |      |        |
 * |--------+------+------+------+------+------+-------------.  ,-------------+------+------+------+------+------+--------|
 * | Shift  |      |      |      |      |      |      |      |  |      |      |      |      |      |      |      |        |
 * `----------------------+------+------+------+------+------|  |------+------+------+------+------+----------------------'
 *                        |      |      |      |      |      |  |      |      |      |      |      |
 *                        |      |      |      |      |      |  |      |      |      |      |      |
 *                        `----------------------------------'  `----------------------------------'
 */
    [_NAV] = LAYOUT(
      ___, ___, ___, ___,     ___,     ___,                                                   KC_PGUP, KC_HOME, KC_UP,   KC_END,  ___, ___,
      ___, ___, ___, KC_LGUI, KC_LALT, ___,                                                   KC_PGDN, KC_LEFT, KC_DOWN, KC_RGHT, ___, ___,
      KC_LSFT, ___, ___, ___, ___, ___, ___, ___,                      ___, ___, ___, ___, ___, ___, ___, ___,
                                    ___, ___, ___, ___, ___,                        ___, ___, ___, ___, ___
    ),

/*
 * Sym Layer: Numbers and symbols
 *
 * ,-------------------------------------------.                              ,-------------------------------------------.
 * |    `   |  1   |  2   |  3   |  4   |  5   |                              |   6  |  7   |  8   |  9   |  0   |   =    |
 * |--------+------+------+------+------+------|                              |------+------+------+------+------+--------|
 * |    ~   |  !   |  @   |  #   |  $   |  %   |                              |   ^  |  &   |  *   |  (   |  )   |   +    |
 * |--------+------+------+------+------+------+-------------.  ,-------------+------+------+------+------+------+--------|
 * |    |   |   \  |  :   |  ;   |  -   |  [   |  {   |      |  |      |   }  |   ]  |  _   |  ,   |  .   |  /   |   ?    |
 * `----------------------+------+------+------+------+------|  |------+------+------+------+------+----------------------'
 *                        |      |      |      |      |      |  |      |      |      |      |      |
 *                        |      |      |      |      |      |  |      |      |      |      |      |
 *                        `----------------------------------'  `----------------------------------'
 */
    [_SYM] = LAYOUT(
      KC_GRV ,   KC_1 ,   KC_2 ,   KC_3 ,   KC_4 ,   KC_5 ,                                       KC_6 ,   KC_7 ,   KC_8 ,   KC_9 ,   KC_0 , KC_EQL ,
     KC_TILD , KC_EXLM,  KC_AT , KC_HASH,  KC_DLR, KC_PERC,                                     KC_CIRC, KC_AMPR, KC_ASTR, KC_LPRN, KC_RPRN, KC_PLUS,
     KC_PIPE , KC_BSLS, KC_COLN, KC_SCLN, KC_MINS, KC_LBRC, KC_LCBR, ___, ___, KC_RCBR, KC_RBRC, KC_UNDS, KC_COMM,  KC_DOT, KC_SLSH, KC_QUES,
                                 ___, ___, ___, ___, ___, ___, ___, ___, ___, ___
    ),

/*
 * Function Layer: Function keys
 *
 * ,-------------------------------------------.                              ,-------------------------------------------.
 * |        |  F9  | F10  | F11  | F12  |      |                              |      |      |      |      |      |        |
 * |--------+------+------+------+------+------|                              |------+------+------+------+------+--------|
 * |        |  F5  |  F6  |  F7  |  F8  |      |                              |      | Shift| Ctrl |  Alt |  GUI |        |
 * |--------+------+------+------+------+------+-------------.  ,-------------+------+------+------+------+------+--------|
 * |        |  F1  |  F2  |  F3  |  F4  |      |      |      |  |      |      |      |      |      |      |      |        |
 * `----------------------+------+------+------+------+------|  |------+------+------+------+------+----------------------'
 *                        |      |      |      |      |      |  |      |      |      |      |      |
 *                        |      |      |      |      |      |  |      |      |      |      |      |
 *                        `----------------------------------'  `----------------------------------'
 */
    [_FUNCTION] = LAYOUT(
      ___,  KC_F9 ,  KC_F10,  KC_F11,  KC_F12, ___,                                     ___, ___, ___, ___, ___, ___,
      ___,  KC_F5 ,  KC_F6 ,  KC_F7 ,  KC_F8 , ___,                                     ___, KC_RSFT, KC_RCTL, KC_LALT, KC_RGUI, ___,
      ___,  KC_F1 ,  KC_F2 ,  KC_F3 ,  KC_F4 , ___, ___, ___, ___, ___, ___, ___, ___, ___, ___, ___,
                                 ___, ___, ___, ___, ___, ___, ___, ___, ___, ___
    ),

/*
 * Adjust Layer: Default layer settings, RGB
 *
 * ,-------------------------------------------.                              ,-------------------------------------------.
 * |        |      |      |QWERTY|      |      |                              |      |      |      |      |      |        |
 * |--------+------+------+------+------+------|                              |------+------+------+------+------+--------|
 * |        |      |      |Dvorak|      |      |                              | TOG  | SAI  | HUI  | VAI  | MOD  |        |
 * |--------+------+------+------+------+------+-------------.  ,-------------+------+------+------+------+------+--------|
 * |        |      |      |Colmak|      |      |      |      |  |      |      |      | SAD  | HUD  | VAD  | RMOD |        |
 * `----------------------+------+------+------+------+------|  |------+------+------+------+------+----------------------'
 *                        |      |      |      |      |      |  |      |      |      |      |      |
 *                        |      |      |      |      |      |  |      |      |      |      |      |
 *                        `----------------------------------'  `----------------------------------'
 */
    [_ADJUST] = LAYOUT(
      ___, ___, ___, QWERTY , ___, ___,                                    ___, ___, ___, ___,  ___, ___,
      ___, ___, ___, DVORAK , ___, ___,                                    RGB_TOG, RGB_SAI, RGB_HUI, RGB_VAI,  RGB_MOD, ___,
      ___, ___, ___, COLEMAK, ___, ___,___, ___, ___, ___, ___, RGB_SAD, RGB_HUD, RGB_VAD, RGB_RMOD, ___,
                                 ___, ___, ___,___, ___, ___, ___, ___, ___, ___
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

// #ifdef OLED_ENABLE
// oled_rotation_t oled_init_user(oled_rotation_t rotation) { return OLED_ROTATION_180; }

static painter_image_handle_t pedro;
static painter_image_handle_t gslogo;

static painter_device_t      display;
static painter_font_handle_t thintel;

void print_bottom_inner(const char *text) {
    int16_t width = qp_textwidth(thintel, text);
    qp_clear(display);
    qp_flush(display);
    qp_drawtext(display, 128-width, 64-thintel->line_height, thintel, text);
    qp_flush(display);
}

void keyboard_post_init_user(void) {
    pedro   = qp_load_image_mem(gfx_pedro);
    gslogo  = qp_load_image_mem(gfx_gslogo);
    thintel = qp_load_font_mem(font_thintel15);
    display = qp_sh1106_make_i2c_device(128, 64, 0x3C);
    
    qp_init(display, QP_ROTATION_180);

    qp_clear(display);
    qp_flush(display);
}

bool set_rgb(int index, uint8_t hue, uint8_t sat, uint8_t val){
    // Using HSV and then converting to RGB allows the brightness 
    // to be limited (important when using the WS2812 driver).
    HSV hsv = {hue, sat, val};
    // if (hsv.v > 0) {
    //     hsv.v = 128;
    // }
    RGB rgb = hsv_to_rgb(hsv);
    rgb_matrix_set_color(index, rgb.r, rgb.g, rgb.b);
    return false;
}

bool set_rgb_all(uint8_t hue, uint8_t sat, uint8_t val){
    // Using HSV and then converting to RGB allows the brightness 
    // to be limited (important when using the WS2812 driver).
    HSV hsv = {hue, sat, val};
    // if (hsv.v > 0) {
    //     hsv.v = 128;
    // }
    RGB rgb = hsv_to_rgb(hsv);
    rgb_matrix_set_color_all(rgb.r, rgb.g, rgb.b);
    return false;
}

static deferred_token current_anim = INVALID_DEFERRED_TOKEN;

layer_state_t layer_state_set_user(layer_state_t state) {
    // https://docs.qmk.fm/feature_layers

    if (current_anim != INVALID_DEFERRED_TOKEN) {
        qp_stop_animation(current_anim);
    }

    switch(get_highest_layer(state)) { // could perhaps be state|default_layer_state
        case _QWERTY:
            if (thintel != NULL) {
                static const char *text = "DEF";
                print_bottom_inner(text);
            }
            break;
        case _FUNCTION:
            if (gslogo != NULL) {
                qp_clear(display);
                qp_flush(display);
                qp_drawimage(display, 32, 0, gslogo);
                qp_flush(display);
            }
            break;
        case _NAV:
            if (pedro != NULL) {
                qp_clear(display);
                qp_flush(display);
                current_anim = qp_animate(display,32, 0, pedro);
                qp_flush(display);

            }
            break;
        case _ADJUST: {
            char val_str[4];
            snprintf(val_str, sizeof(val_str), "%u", rgb_matrix_get_val());
            print_bottom_inner(val_str);
            break;
        }
        default: {
            char layer_str[10];
            snprintf(layer_str, sizeof(layer_str), "%u", state);
            print_bottom_inner(layer_str);
            break;
        }
    }


    return state;
}

// right, middle
int h = 50;
int j = 51;
int k = 52;
int l = 53;
int oe = 54;
int ae = 55;

// Right, top
int y = 56;
int u = 57;
int i = 58;
int o = 50;
int p = 60;
int ao = 61;

// COLORS
// #define GS_PINK 245, 204, 222 // actual
#define GS_PINK 250, 255, 255 // adapted to look better

bool rgb_matrix_indicators_user(void) {
    switch(get_highest_layer(layer_state)) {
        case _NAV:
            set_rgb(i, GS_PINK);
            set_rgb(j, GS_PINK);
            set_rgb(k, GS_PINK);
            set_rgb(l, GS_PINK);
            break;
        default:
            break;
    }
    return true;
}



void housekeeping_task_user(void) {
    static bool first_render = true;
    static uint32_t time = 0;

    if (time == 0) {
        time = timer_read32();
    }
    
    if (first_render && timer_elapsed32(time) > 2000) {
        first_render = false;
        qp_clear(display);
        qp_flush(display);
        qp_drawimage(display, 32, 0, gslogo);
        qp_flush(display);
    }
}

// bool oled_task_user(void) {
// //     if (is_keyboard_master()) {

// // //         // QMK Logo and version information
// // //         // clang-format off
// // //         static const char PROGMEM qmk_logo[] = {
// // //             0x80,0x81,0x82,0x83,0x84,0x85,0x86,0x87,0x88,0x89,0x8a,0x8b,0x8c,0x8d,0x8e,0x8f,0x90,0x91,0x92,0x93,0x94,
// // //             0xa0,0xa1,0xa2,0xa3,0xa4,0xa5,0xa6,0xa7,0xa8,0xa9,0xaa,0xab,0xac,0xad,0xae,0xaf,0xb0,0xb1,0xb2,0xb3,0xb4,
// // //             0xc0,0xc1,0xc2,0xc3,0xc4,0xc5,0xc6,0xc7,0xc8,0xc9,0xca,0xcb,0xcc,0xcd,0xce,0xcf,0xd0,0xd1,0xd2,0xd3,0xd4,0};
// // //         // clang-format on

// // //         oled_write_P(qmk_logo, false);
// // //         oled_write_P(PSTR("Kyria "), false);
// // // #if defined(KEYBOARD_splitkb_kyria_rev1)
// // //         oled_write_P(PSTR("rev1\n\n"), false);
// // // #elif defined(KEYBOARD_splitkb_kyria_rev2)
// // //         oled_write_P(PSTR("rev2\n\n"), false);
// // // #elif defined(KEYBOARD_splitkb_kyria_rev3)
// // //         oled_write_P(PSTR("rev3\n\n"), false);
// // // #endif
// // //         // Host Keyboard Layer Status
// // //         oled_write_P(PSTR("Layer: "), false);
// // //         switch (get_highest_layer(layer_state | default_layer_state)) {
// // //             case 0:
// // //                 oled_write_P(PSTR("QWERTY\n"), false);
// // //                 break;
// // //             case 1:
// // //                 oled_write_P(PSTR("Dvorak\n"), false);
// // //                 break;
// // //             case 2:
// // //                 oled_write_P(PSTR("Colemak-DH\n"), false);
// // //                 break;
// // //             case 3:
// // //                 oled_write_P(PSTR("Nav\n"), false);
// // //                 break;
// // //             case 4:
// // //                 oled_write_P(PSTR("Sym\n"), false);
// // //                 break;
// // //             case 5:
// // //                 oled_write_P(PSTR("Function\n"), false);
// // //                 break;
// // //             case 6:
// // //                 oled_write_P(PSTR("Adjust\n"), false);
// // //                 break;
// // //             default:
// // //                 oled_write_P(PSTR("Undefined\n"), false);
// // //         }

// // //         // Host Keyboard LED Status
// // //         led_t led_usb_state = host_keyboard_led_state();
// // //         oled_write_P(led_usb_state.num_lock ? PSTR("NUMLCK ") : PSTR("       "), false);
// // //         oled_write_P(led_usb_state.caps_lock ? PSTR("CAPLCK ") : PSTR("       "), false);
// // //         oled_write_P(led_usb_state.scroll_lock ? PSTR("SCRLCK ") : PSTR("       "), false);
// //         // qp_animate(display,0, 0, pedro);
// //         // qp_flush(display);
// //     } else {
// //         // qp_animate(display,-64, -64, pedro);
// //         // qp_flush(display);
// //     }
//     return false;
// }
// // #endif