/*
Copyright 2019 @foostan
Copyright 2020 Drashna Jaelre <@drashna>

This program is free software: you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation, either version 2 of the License, or
(at your option) any later version.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/

#include QMK_KEYBOARD_H
#include "sendstring_spanish_latin_america.h"

enum layers {
    _DVORAK,
    _QWERTY,
    _NUMPAD,
    _SYMBOLS,
    _UTIL
};

enum custom_keycodes {
    MW_COPY = SAFE_RANGE,   // Copiar
    MW_PASTE,               // Pegar
    MW_CUT,                 // Pegar
    MW_PSCR,                // Captera de pantalla
    MW_WDS,                 // Captera de pantalla
    MW_LEFT,                // Mover a la izquierda (macOS)
    MW_RIGHT,               // Mover a la derecha (macOS)
};

// Variable para el modo (macOS o Windows)
bool is_mac_mode = true;
// Cambia entre Dvorak y QWERTY
bool is_dvorak = true;


#define TG_GAME TG(_QWERTY)
#define NUMPAD  MO(_NUMPAD)
#define SYMBOLS MO(_SYMBOLS)
#define UTIL    MO(_UTIL)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [_DVORAK] = LAYOUT_split_3x6_3(
  //,-----------------------------------------------------.                              ,-----------------------------------------------------.
       KC_ESC, ES_QUOT, ES_COMM,  ES_DOT,    ES_P,    ES_Y,                                   ES_F,    ES_G,    ES_C,    ES_R,    ES_L, KC_BSPC,
  //|--------+--------+--------+--------+--------+--------|                              |--------+--------+--------+--------+--------+--------|
      KC_LCTL,    ES_A,    ES_O,    ES_E,    ES_U,    ES_I,                                   ES_D,    ES_H,    ES_T,    ES_N,    ES_S, ES_NTIL,
  //|--------+--------+--------+--------+--------+--------|                              |--------+--------+--------+--------+--------+--------|
      KC_LSFT, ES_PIPE,    ES_Q,    ES_J,    ES_K,    ES_X,                                   ES_B,    ES_M,    ES_W,    ES_V,    ES_Z,  KC_TAB,
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+---------+--------+--------+--------+--------+--------|
                                          KC_LGUI,  NUMPAD,  KC_SPC,     KC_ENT,  SYMBOLS,  KC_RALT
                                      //`--------------------------'  `---------------------------'
  ),
    [_QWERTY] = LAYOUT_split_3x6_3(
  //,-----------------------------------------------------.                   ,-----------------------------------------------------.
       KC_TAB,    KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,                        KC_Y,    KC_U,    KC_I,    KC_O,   KC_P,  KC_BSPC,
  //|--------+--------+--------+--------+--------+--------|                   |--------+--------+--------+--------+--------+--------|
      KC_LCTL,    KC_A,    KC_S,    KC_D,    KC_F,    KC_G,                        KC_H,    KC_J,    KC_K,    KC_L, KC_SCLN, KC_QUOT,
  //|--------+--------+--------+--------+--------+--------|                   |--------+--------+--------+--------+--------+--------|
      KC_LSFT,    KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,                        KC_N,    KC_M, KC_COMM,  KC_DOT, KC_SLSH,  KC_ESC,
  //|--------+--------+--------+--------+--------+--------+--------|  |-------+--------+--------+--------+--------+--------+--------|
                                          KC_LGUI,  NUMPAD,  KC_SPC,    KC_ENT, SYMBOLS, KC_RALT
                                      //`--------------------------'  `-------------------------'
  ),
    [_NUMPAD] = LAYOUT_split_3x6_3(
  //,-----------------------------------------------------.                                ,-----------------------------------------------------.
       KC_DEL,    ES_1,    ES_2,    ES_3,    ES_4,    ES_5,                                     ES_6,    ES_7,    ES_8,    ES_9,   ES_0,   KC_INS,
  //|--------+--------+--------+--------+--------+--------|                                |--------+--------+--------+--------+--------+--------|
        KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5, ES_PLUS,                                  ES_ASTR, KC_LEFT, KC_DOWN,   KC_UP,KC_RIGHT, KC_CAPS,
  //|--------+--------+--------+--------+--------+--------|                                |--------+--------+--------+--------+--------+--------|
        KC_F6,   KC_F7,   KC_F8,   KC_F9,  KC_F10, ES_MINS,                                  ES_SLSH,  KC_F11,  KC_F12, MW_LEFT,MW_RIGHT,  MW_WDS,
  //|--------+--------+--------+--------+--------+--------+---------|  |--------+----------+--------+--------+--------+--------+--------+--------|
                                          MW_COPY,  NUMPAD, MW_PASTE,     MW_CUT, UTIL,   MW_PSCR
                                      //`---------------------------'  `----------------------------'
  ),
    [_SYMBOLS] = LAYOUT_split_3x6_3(
  //,-----------------------------------------------------.                               ,-----------------------------------------------------.
       ES_DLR, ES_LBRC, ES_LCBR, ES_LPRN, ES_AMPR,  ES_EQL,                                 ES_EXLM, ES_QUES, ES_RPRN, ES_RCBR, ES_RBRC,  ES_NOT,
  //|--------+--------+--------+--------+--------+--------|                               |--------+--------+--------+--------+--------+--------|
       ES_GRV, ES_MINS, ES_SLSH,   ES_AT, ES_NUMB, ES_DQUO,                                 ES_QUOT, ES_PERC, ES_TILD, ES_BSLS, ES_UNDS, ES_ACUT,
  //|--------+--------+--------+--------+--------+--------|                               |--------+--------+--------+--------+--------+--------|
      ES_MORD, ES_LABK, ES_IEXL, KC_VOLD, KC_VOLU, KC_MUTE,                                 KC_MPRV, KC_MPLY, KC_MNXT, ES_IQUE, ES_RABK, ES_CIRC,
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------+--------|
                                            KC_NO,    UTIL,   KC_NO,      KC_NO, SYMBOLS,   KC_NO
                                      //`----------==--------------'  `--------------------------'
  ),
    [_UTIL] = LAYOUT_split_3x6_3(
  //,------------------------------------------------------.                    ,-----------------------------------------------------.
      QK_BOOT, TG_GAME, XXXXXXX, XXXXXXX, XXXXXXX,  XXXXXXX,                       XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
  //|--------+--------+--------+--------+--------+---------|                    |---------+--------+--------+--------+--------+--------|
      RGB_TOG, RGB_HUI, RGB_SAI, RGB_VAI, RGB_SPI,  XXXXXXX,                       XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
  //|--------+--------+--------+--------+--------+---------|                    |---------+--------+--------+--------+--------+--------|
      RGB_MOD, RGB_HUD, RGB_SAD, RGB_VAD, RGB_SPD,  XXXXXXX,                       XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
  //|--------+--------+--------+--------+--------+---------+--------|  |--------+---------+--------+--------+--------+--------+--------|
                                          KC_LGUI,  KC_TRNS,  KC_SPC,     KC_ENT,  KC_TRNS, KC_RALT
                                      //`---------------------------'  `---------------------------'
  )
};

#ifdef OLED_ENABLE

/* 32 * 32 logo */
static void render_logo(void) {
    static const char PROGMEM turtle_logo[] = {0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x80, 0x80, 0x80, 0x80, 0x80, 0x80, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xf0, 0xf8, 0x1e, 0x06, 0x03, 0x03, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x03, 0x87, 0xce, 0xec, 0x78, 0x3c, 0x0e, 0x07, 0x83, 0x9b, 0xc3, 0xe6, 0x7e, 0x38, 0x00, 0x00, 0x00, 0x10, 0x18, 0xde, 0xcf, 0xef, 0xac, 0x8c, 0xcc, 0xcc, 0xcc, 0xc6, 0xc6, 0xc6, 0xc6, 0xc3, 0xc3, 0x61, 0xe1, 0x80, 0x80, 0xbc, 0xff, 0xe3, 0xc1, 0x01, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00};

    oled_write_raw_P(turtle_logo, sizeof(turtle_logo));
}

/* 32 * 14 os logos */
static const char PROGMEM windows_logo[] = {0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xbc, 0xbc, 0xbe, 0xbe, 0x00, 0xbe, 0xbe, 0xbf, 0xbf, 0xbf, 0xbf, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x07, 0x07, 0x0f, 0x0f, 0x00, 0x0f, 0x0f, 0x1f, 0x1f, 0x1f, 0x1f, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00};

static const char PROGMEM mac_logo[] = {0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xc0, 0xf0, 0xf8, 0xf8, 0xf8, 0xf0, 0xf6, 0xfb, 0xfb, 0x38, 0x10, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x01, 0x07, 0x0f, 0x1f, 0x1f, 0x0f, 0x0f, 0x1f, 0x1f, 0x0f, 0x06, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00};

/* KEYBOARD PET START */

/* settings */
#    define MIN_WALK_SPEED      10
#    define MIN_RUN_SPEED       40

/* advanced settings */
#    define ANIM_FRAME_DURATION 200  // how long each frame lasts in ms
#    define ANIM_SIZE           96   // number of bytes in array. If you change sprites, minimize for adequate firmware size. max is 1024

/* timers */
uint32_t anim_timer = 0;

/* current frame */
uint8_t current_frame = 0;

/* status variables */
int   current_wpm = 0;
led_t led_usb_state;

bool isSneaking = false;
bool isJumping  = false;
bool showedJump = true;

/* logic */
static void render_luna(int LUNA_X, int LUNA_Y) {
    /* Sit */
    static const char PROGMEM sit[2][ANIM_SIZE] = {/* 'sit1', 32x22px */
                                                   {
                                                       0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xe0, 0x1c, 0x02, 0x05, 0x02, 0x24, 0x04, 0x04, 0x02, 0xa9, 0x1e, 0xe0, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xe0, 0x10, 0x08, 0x68, 0x10, 0x08, 0x04, 0x03, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x02, 0x06, 0x82, 0x7c, 0x03, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x01, 0x02, 0x04, 0x0c, 0x10, 0x10, 0x20, 0x20, 0x20, 0x28, 0x3e, 0x1c, 0x20, 0x20, 0x3e, 0x0f, 0x11, 0x1f, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
                                                   },

                                                   /* 'sit2', 32x22px */
                                                   {0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xe0, 0x1c, 0x02, 0x05, 0x02, 0x24, 0x04, 0x04, 0x02, 0xa9, 0x1e, 0xe0, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xe0, 0x90, 0x08, 0x18, 0x60, 0x10, 0x08, 0x04, 0x03, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x02, 0x0e, 0x82, 0x7c, 0x03, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x01, 0x02, 0x04, 0x0c, 0x10, 0x10, 0x20, 0x20, 0x20, 0x28, 0x3e, 0x1c, 0x20, 0x20, 0x3e, 0x0f, 0x11, 0x1f, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00}};

    /* Walk */
    static const char PROGMEM walk[2][ANIM_SIZE] = {/* 'walk1', 32x22px */
                                                    {
                                                        0x00, 0x00, 0x00, 0x00, 0x00, 0x80, 0x40, 0x20, 0x10, 0x90, 0x90, 0x90, 0xa0, 0xc0, 0x80, 0x80, 0x80, 0x70, 0x08, 0x14, 0x08, 0x90, 0x10, 0x10, 0x08, 0xa4, 0x78, 0x80, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x07, 0x08, 0xfc, 0x01, 0x00, 0x00, 0x00, 0x00, 0x80, 0x00, 0x00, 0x01, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x08, 0x18, 0xea, 0x10, 0x0f, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x03, 0x1c, 0x20, 0x20, 0x3c, 0x0f, 0x11, 0x1f, 0x03, 0x06, 0x18, 0x20, 0x20, 0x3c, 0x0c, 0x12, 0x1e, 0x01, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
                                                    },

                                                    /* 'walk2', 32x22px */
                                                    {
                                                        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x80, 0x40, 0x20, 0x20, 0x20, 0x40, 0x80, 0x00, 0x00, 0x00, 0x00, 0xe0, 0x10, 0x28, 0x10, 0x20, 0x20, 0x20, 0x10, 0x48, 0xf0, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x1f, 0x20, 0xf8, 0x02, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x03, 0x00, 0x00, 0x00, 0x00, 0x01, 0x00, 0x10, 0x30, 0xd5, 0x20, 0x1f, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x3f, 0x20, 0x30, 0x0c, 0x02, 0x05, 0x09, 0x12, 0x1e, 0x02, 0x1c, 0x14, 0x08, 0x10, 0x20, 0x2c, 0x32, 0x01, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
                                                    }};

    /* Run */
    static const char PROGMEM run[2][ANIM_SIZE] = {/* 'run1', 32x22px */
                                                   {
                                                       0x00, 0x00, 0x00, 0x00, 0xe0, 0x10, 0x08, 0x08, 0xc8, 0xb0, 0x80, 0x80, 0x80, 0x80, 0x80, 0x80, 0x80, 0x40, 0x40, 0x3c, 0x14, 0x04, 0x08, 0x90, 0x18, 0x04, 0x08, 0xb0, 0x40, 0x80, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x01, 0x02, 0xc4, 0xa4, 0xfc, 0x00, 0x00, 0x00, 0x00, 0x80, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x80, 0xc8, 0x58, 0x28, 0x2a, 0x10, 0x0f, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x0e, 0x09, 0x04, 0x04, 0x04, 0x04, 0x02, 0x03, 0x02, 0x01, 0x01, 0x02, 0x02, 0x04, 0x08, 0x10, 0x26, 0x2b, 0x32, 0x04, 0x05, 0x06, 0x00, 0x00, 0x00, 0x00, 0x00,
                                                   },

                                                   /* 'run2', 32x22px */
                                                   {
                                                       0x00, 0x00, 0x00, 0xe0, 0x10, 0x10, 0xf0, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x80, 0x80, 0x80, 0x78, 0x28, 0x08, 0x10, 0x20, 0x30, 0x08, 0x10, 0x20, 0x40, 0x80, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x03, 0x04, 0x08, 0x10, 0x11, 0xf9, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x01, 0x10, 0xb0, 0x50, 0x55, 0x20, 0x1f, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x01, 0x02, 0x0c, 0x10, 0x20, 0x28, 0x37, 0x02, 0x1e, 0x20, 0x20, 0x18, 0x0c, 0x14, 0x1e, 0x01, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
                                                   }};

    /* Bark */
    static const char PROGMEM bark[2][ANIM_SIZE] = {/* 'bark1', 32x22px */
                                                    {
                                                        0x00, 0xc0, 0x20, 0x10, 0xd0, 0x30, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x80, 0x80, 0x40, 0x3c, 0x14, 0x04, 0x08, 0x90, 0x18, 0x04, 0x08, 0xb0, 0x40, 0x80, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x03, 0x04, 0x08, 0x10, 0x11, 0xf9, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x80, 0xc8, 0x48, 0x28, 0x2a, 0x10, 0x0f, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x01, 0x02, 0x0c, 0x10, 0x20, 0x28, 0x37, 0x02, 0x02, 0x04, 0x08, 0x10, 0x26, 0x2b, 0x32, 0x04, 0x05, 0x06, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
                                                    },

                                                    /* 'bark2', 32x22px */
                                                    {
                                                        0x00, 0xe0, 0x10, 0x10, 0xf0, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x80, 0x80, 0x40, 0x40, 0x2c, 0x14, 0x04, 0x08, 0x90, 0x18, 0x04, 0x08, 0xb0, 0x40, 0x80, 0x00, 0x00, 0x00, 0x00, 0x00, 0x03, 0x04, 0x08, 0x10, 0x11, 0xf9, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x80, 0xc0, 0x48, 0x28, 0x2a, 0x10, 0x0f, 0x20, 0x4a, 0x09, 0x10, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x01, 0x02, 0x0c, 0x10, 0x20, 0x28, 0x37, 0x02, 0x02, 0x04, 0x08, 0x10, 0x26, 0x2b, 0x32, 0x04, 0x05, 0x06, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
                                                    }};

    /* Sneak */
    static const char PROGMEM sneak[2][ANIM_SIZE] = {/* 'sneak1', 32x22px */
                                                     {
                                                         0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x80, 0x40, 0x40, 0x40, 0x40, 0x80, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xc0, 0x40, 0x40, 0x80, 0x00, 0x80, 0x40, 0x80, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x1e, 0x21, 0xf0, 0x04, 0x02, 0x02, 0x02, 0x02, 0x03, 0x02, 0x02, 0x04, 0x04, 0x04, 0x03, 0x01, 0x00, 0x00, 0x09, 0x01, 0x80, 0x80, 0xab, 0x04, 0xf8, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x03, 0x1c, 0x20, 0x20, 0x3c, 0x0f, 0x11, 0x1f, 0x02, 0x06, 0x18, 0x20, 0x20, 0x38, 0x08, 0x10, 0x18, 0x04, 0x04, 0x02, 0x02, 0x01, 0x00, 0x00, 0x00, 0x00,
                                                     },

                                                     /* 'sneak2', 32x22px */
                                                     {
                                                         0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x80, 0x40, 0x40, 0x40, 0x80, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xe0, 0xa0, 0x20, 0x40, 0x80, 0xc0, 0x20, 0x40, 0x80, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x3e, 0x41, 0xf0, 0x04, 0x02, 0x02, 0x02, 0x03, 0x02, 0x02, 0x02, 0x04, 0x04, 0x02, 0x01, 0x00, 0x00, 0x00, 0x04, 0x00, 0x40, 0x40, 0x55, 0x82, 0x7c, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x3f, 0x20, 0x30, 0x0c, 0x02, 0x05, 0x09, 0x12, 0x1e, 0x04, 0x18, 0x10, 0x08, 0x10, 0x20, 0x28, 0x34, 0x06, 0x02, 0x01, 0x01, 0x00, 0x00, 0x00, 0x00, 0x00,
                                                     }};

    /* animation */
    void animate_luna(void) {
        /* jump */
        if (isJumping || !showedJump) {
            /* clear */
            oled_set_cursor(LUNA_X, LUNA_Y + 2);
            oled_write("     ", false);

            oled_set_cursor(LUNA_X, LUNA_Y - 1);

            showedJump = true;
        } else {
            /* clear */
            oled_set_cursor(LUNA_X, LUNA_Y - 1);
            oled_write("     ", false);

            oled_set_cursor(LUNA_X, LUNA_Y);
        }

        /* switch frame */
        current_frame = (current_frame + 1) % 2;

        /* current status */
        if (led_usb_state.caps_lock) {
            oled_write_raw_P(bark[current_frame], ANIM_SIZE);

        } else if (isSneaking) {
            oled_write_raw_P(sneak[current_frame], ANIM_SIZE);

        } else if (current_wpm <= MIN_WALK_SPEED) {
            oled_write_raw_P(sit[current_frame], ANIM_SIZE);

        } else if (current_wpm <= MIN_RUN_SPEED) {
            oled_write_raw_P(walk[current_frame], ANIM_SIZE);

        } else {
            oled_write_raw_P(run[current_frame], ANIM_SIZE);
        }
    }

#    if OLED_TIMEOUT > 0
    /* the animation prevents the normal timeout from occuring */
    if (last_input_activity_elapsed() > OLED_TIMEOUT && last_led_activity_elapsed() > OLED_TIMEOUT) {
        oled_off();
        return;
    } else {
        oled_on();
    }
#    endif

    /* animation timer */
    if (timer_elapsed32(anim_timer) > ANIM_FRAME_DURATION) {
        anim_timer = timer_read32();
        animate_luna();
    }
}

/* KEYBOARD PET END */

static void print_logo_narrow(void) {
    render_logo();

    /* wpm counter */
    uint8_t n = get_current_wpm();
    char    wpm_str[4];
    oled_set_cursor(1, 14);
    wpm_str[3] = '\0';
    wpm_str[2] = '0' + n % 10;
    wpm_str[1] = '0' + (n /= 10) % 10;
    wpm_str[0] = '0' + n / 10;
    oled_write(wpm_str, false);

    oled_set_cursor(0, 15);
    oled_write(" wpm", false);
}

static void print_status_narrow(void) {
    /* Print current mode */
    oled_set_cursor(0, 0);
    if (is_mac_mode) {
        oled_write_raw_P(mac_logo, sizeof(mac_logo));
    } else {
        oled_write_raw_P(windows_logo, sizeof(windows_logo));
    }

    oled_set_cursor(0, 3);

    oled_write("CORNE", false);

    oled_set_cursor(0, 5);

    /* Print current layer */
    oled_write("LAYER", false);

    oled_set_cursor(0, 6);

    switch (get_highest_layer(layer_state)) {
        case _DVORAK:
            oled_write("Dvrak", false);
            break;
        case _QWERTY:
            oled_write("Gming", false);
            break;
        case _SYMBOLS:
            oled_write("Smbol", false);
            break;
        case _NUMPAD:
            oled_write("Nmpad", false);
            break;
        case _UTIL:
            oled_write("Util  ", false);
            break;
        default:
            oled_write("Undef", false);
    }

    /* caps lock */
    oled_set_cursor(0, 8);
    if (led_usb_state.caps_lock) {
        oled_write("CPSLK", false);
    } else {
        oled_write("     ", false);
    }

    /* KEYBOARD PET RENDER START */

    render_luna(0, 13);

    /* KEYBOARD PET RENDER END */
}

oled_rotation_t oled_init_user(oled_rotation_t rotation) { return OLED_ROTATION_270; }

bool oled_task_user(void) {
    /* KEYBOARD PET VARIABLES START */

    current_wpm   = get_current_wpm();
    led_usb_state = host_keyboard_led_state();

    /* KEYBOARD PET VARIABLES END */

    if (is_keyboard_master()) {
        print_status_narrow();
    } else {
        print_logo_narrow();
    }
    return false;
}


#endif
bool process_detected_host_os_kb(os_variant_t detected_os) {
    if (!process_detected_host_os_user(detected_os)) {
        return false;
    }
    switch (detected_os) {
        case OS_MACOS:
        case OS_IOS:
            is_mac_mode = true;
            break;
        case OS_WINDOWS:
            is_mac_mode = false;
            break;
        case OS_LINUX:
            is_mac_mode = false;
            break;
        case OS_UNSURE:
            is_mac_mode = false;
            break;
    }

    return true;
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case MW_COPY:
            if (record->event.pressed) {
                if (is_mac_mode) {
                    register_mods(mod_config(MOD_LGUI));
                    register_code(KC_C);
                } else {
                    register_mods(mod_config(MOD_LCTL));
                    register_code(KC_C);
                }
            } else {
                if (is_mac_mode) {
                    unregister_mods(mod_config(MOD_LGUI));
                    unregister_code(KC_C);
                } else {
                    unregister_mods(mod_config(MOD_LCTL));
                    unregister_code(KC_C);
                }
            }
            return false;
        case MW_PASTE:
            if (record->event.pressed) {
                if (is_mac_mode) {
                    register_mods(mod_config(MOD_LGUI));
                    register_code(KC_V);
                } else {
                    register_mods(mod_config(MOD_LCTL));
                    register_code(KC_V);
                }
            } else {
                if (is_mac_mode) {
                    unregister_mods(mod_config(MOD_LGUI));
                    unregister_code(KC_V);
                } else {
                    unregister_mods(mod_config(MOD_LCTL));
                    unregister_code(KC_V);
                }
            }
            return false;
        case MW_CUT:
            if (record->event.pressed) {
                if (is_mac_mode) {
                    register_mods(mod_config(MOD_LGUI));
                    register_code(KC_X);
                } else {
                    register_mods(mod_config(MOD_LCTL));
                    register_code(KC_X);
                }
            } else {
                if (is_mac_mode) {
                    unregister_mods(mod_config(MOD_LGUI));
                    unregister_code(KC_X);
                } else {
                    unregister_mods(mod_config(MOD_LCTL));
                    unregister_code(KC_X);
                }
            }
            return false;
        case MW_PSCR:
            if (record->event.pressed) {
                if (is_mac_mode) {
                    register_mods(mod_config(MOD_LSFT));
                    register_mods(mod_config(MOD_LGUI));
                    register_code(KC_4);
                } else {
                    register_mods(mod_config(MOD_LGUI));
                    register_mods(mod_config(MOD_LSFT));
                    register_code(KC_S);
                }
            } else {
                if (is_mac_mode) {
                    unregister_mods(mod_config(MOD_LSFT));
                    unregister_mods(mod_config(MOD_LGUI));
                    unregister_code(KC_4);
                } else {
                    unregister_mods(mod_config(MOD_LGUI));
                    unregister_mods(mod_config(MOD_LSFT));
                    unregister_code(KC_S);
                }
            }
            return false;
        case MW_WDS:
            if (record->event.pressed) {
                if (is_mac_mode) {
                    register_mods(mod_config(MOD_LCTL));
                    register_code(KC_UP);
                } else {
                    unregister_mods(mod_config(MOD_LCTL));
                    unregister_code(KC_TAB);
                }
            } else {
                if (is_mac_mode) {
                    unregister_mods(mod_config(MOD_LCTL));
                    unregister_mods(mod_config(MOD_LGUI));
                } else {
                    unregister_mods(mod_config(MOD_LCTL));
                    unregister_code(KC_TAB);
                }
            }
            return false;
        case MW_LEFT:
            if (record->event.pressed) {
                if (is_mac_mode) {
                    register_mods(mod_config(MOD_LCTL));
                    register_code(KC_LEFT);
                }
            } else {
                if (is_mac_mode) {
                    unregister_mods(mod_config(MOD_LCTL));
                    unregister_code(KC_LEFT);
                }
            }
            return false;
        case MW_RIGHT:
            if (record->event.pressed) {
                if (is_mac_mode) {
                    register_mods(mod_config(MOD_LCTL));
                    register_code(KC_RIGHT);
                }
            } else {
                if (is_mac_mode) {
                    unregister_mods(mod_config(MOD_LCTL));
                    unregister_code(KC_RIGHT);
                }
            }
            return false;
    }
    return true;
}
