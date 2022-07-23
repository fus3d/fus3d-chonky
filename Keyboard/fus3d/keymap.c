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
#include <stdio.h>

#ifdef PIMORONI_TRACKBALL_ENABLE
#include "drivers/sensors/pimoroni_trackball.h"
#include "pointing_device.h"
#endif

#define _QWERTY 0
#define _RAISE 1
#define _LAYER2 2
#define _MLAYER 3
#define _NUMLAY 4
#define _TMUXLAY 5

enum custom_keycodes {
    BTAB = SAFE_RANGE,
    BBTAB,
    BPAGE,
    BBPAGE,
    TMUXU,
    TMUXD,
    TMUXL,
    TMUXR,
    TMUXZ,
    TMUXNEW,
    TMUXLOG,
    TMUXPAS,
    TMUXMNU,
    TMUXSPL,
    TMUXVSP,
    TMUXMVU,
    TMUXMVD,
    TMUXLST,
    TMUXTIT,
    TMUXCMD,
    TMUXRL,
    TMUXRR,
    TMUXRU,
    TMUXRD,
    TMUX0,
    TMUX1,
    TMUX2,
    TMUX3,
    TMUX4,
    TMUX5,
    TMUX6,
    TMUX7,
    TMUX8,
    TMUX9,
    TMUXNXT,
    TMUXPRV,
    RANDOMS,
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {                                     

  [_QWERTY] = LAYOUT_split_3x6_3(
  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
       KC_ESC,    KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,                         KC_Y,    KC_U,    KC_I,    KC_O,   KC_P,  KC_BSPC,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      KC_LSFT,    KC_A,    KC_S,    KC_D,    KC_F,    KC_G,                         KC_H,    KC_J,    KC_K,    KC_L, KC_SCLN, KC_QUOT,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      KC_LCTL,    KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,                         KC_N,    KC_M, KC_COMM,  KC_DOT, KC_SLSH, KC_BSLS,
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                            MO(2),   MO(1), KC_LGUI,     KC_SPC,  KC_ENT,   MO(4)
                                      //`--------------------------'  `--------------------------'

  ),

  [_RAISE] = LAYOUT_split_3x6_3(
  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
       KC_TAB,    KC_1,    KC_2,    KC_3,    KC_4,    KC_5,                         KC_6,    KC_7,    KC_8,    KC_9,    KC_0, KC_BSPC,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
       KC_LSFT, _______, _______, _______, _______, _______,                      KC_LEFT, KC_DOWN,   KC_UP,KC_RIGHT, _______, KC_MINS,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
       KC_LCTL, _______, _______, _______, _______, _______,                      KC_HOME, KC_PGDN, KC_PGUP,  KC_END, KC_TILD, _______,
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                          MO(3)  , _______,_______ ,     KC_SPC,  KC_ENT, KC_BSPC
                                      //`--------------------------'  `--------------------------'
  ),

  [_LAYER2] = LAYOUT_split_3x6_3(
  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
      _______, _______, _______, _______, _______, KC_LBRC,                      KC_RBRC, _______, _______, _______, _______, _______,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      KC_LSFT, _______, _______, _______, _______, KC_LPRN,                      KC_RPRN,  KC_EQL, KC_LBRC, KC_RBRC, KC_BSLS,  KC_GRV,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      KC_LCTL, _______, _______, _______, _______, KC_LCBR,                      KC_RCBR, KC_PLUS, KC_LCBR, KC_RCBR, KC_PIPE, KC_TILD,
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                          _______,   MO(3), _______,    _______, _______,   MO(5)
                                      //`--------------------------'  `--------------------------'
  ),

  [_MLAYER] = LAYOUT_split_3x6_3(
  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
      KC_F1  ,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,                        KC_F7,   KC_F8,   KC_F9,  KC_F10,  KC_F11,  KC_F12,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      KC_LSFT, _______, _______, _______, _______, KC_LPRN,                      KC_RPRN,  KC_EQL, KC_LBRC, KC_RBRC, KC_BSLS,  KC_GRV,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      KC_LCTL, _______, _______, _______, _______, KC_LCBR,                      KC_RCBR, KC_PLUS, KC_LCBR, KC_RCBR, KC_PIPE, KC_TILD,
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                          _______, _______, _______,    _______, _______, _______
                                      //`--------------------------'  `--------------------------'
  ),

  [_NUMLAY] = LAYOUT_split_3x6_3(
  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
      _______, KC_BTN1, KC_MS_U, KC_BTN2, _______, KC_WH_U,                        BPAGE, KC_PGUP, KC_PGDN,  BBPAGE, _______, _______,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      KC_LSFT, KC_MS_L, KC_MS_D, KC_MS_R, _______, KC_WH_D,                        BBTAB, KC_HOME,  KC_END,    BTAB, _______, _______,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      KC_LCTL, _______, _______, _______, _______, _______,                      _______, _______, _______, _______, _______, _______,
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                            MO(5), _______, _______,    _______, _______, _______
                                      //`--------------------------'  `--------------------------'
  ),

  [_TMUXLAY] = LAYOUT_split_3x6_3(
  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
        TMUX0,   TMUX1,   TMUX2,   TMUX3,   TMUX4,   TMUX5,                       TMUXRL,  TMUXRD,  TMUXRU,  TMUXRR, TMUXPAS, TMUXLOG,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      _______, TMUXTIT, TMUXSPL, _______, _______, _______,                        TMUXL,   TMUXD,   TMUXU,   TMUXR, TMUXCMD, TMUXLST,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      _______,   TMUXZ, _______, TMUXNEW, _______, _______,                      _______, _______, TMUXPRV, TMUXNXT, _______, TMUXVSP,
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                          _______, _______, _______,    _______, _______, _______
                                      //`--------------------------'  `--------------------------'
  )
};

#ifdef OLED_ENABLE
oled_rotation_t oled_init_user(oled_rotation_t rotation) {
  if (!is_keyboard_master()) {
    return OLED_ROTATION_180;  // flips the display 180 degrees if offhand
  }
  return rotation;
}

static const char PROGMEM symbol_logo[] = {
    0,0,0,0,0,192,224,224,240,240,112,112,240,240,224,224,224,224,224,192,192,60,252,252,240,224,128,0,0,0,0,0,0,128,192,240,240,240,0,0,0,0,192,248,252,254,254,252,240,128,0,128,240,240,240,240,128,0,0,0,0,0,0,0,248,252,252,28,28,28,28,28,252,252,252,192,0,0,0,0,0,0,0,192,224,224,240,240,240,112,240,240,240,192,0,0,0,0,0,240,240,240,240,0,0,0,0,0,0,0,0,0,128,192,224,224,240,240,240,120,120,56,56,56,56,0,0,0,0,0,0,0,0,63,127,255,240,240,224,224,192,192,192,192,128,129,1,1,1,0,0,7,63,127,255,254,240,240,240,248,126,63,31,7,3,0,0,0,240,254,255,255,15,1,1,7,31,63,62,63,31,15,7,31,255,254,248,224,0,0,0,0,63,255,255,252,248,248,248,252,254,223,207,199,128,128,0,0,0,224,255,255,255,3,1,0,0,0,0,7,31,255,255,248,224,0,0,1,127,255,255,224,128,0,0,0,0,0,0,0,31,255,255,251,225,192,128,0,0,0,0,0,0,0,0,0,0,0,0,0,192,192,192,192,128,128,1,1,1,1,3,3,135,223,255,255,252,0,0,0,0,0,63,255,255,255,1,1,0,0,0,0,0,0,0,240,255,255,255,3,0,0,0,0,0,0,0,0,0,0,0,0,0,3,31,255,255,252,192,0,0,63,255,255,255,240,1,1,1,3,3,7,7,31,63,254,252,251,255,255,255,252,224,128,128,128,128,128,128,192,255,255,255,0,0,0,0,3,63,255,255,248,128,0,0,0,0,128,128,128,129,3,3,7,135,143,207,255,254,252,124,0,0,0,0,0,0,0,1,3,3,3,7,7,7,7,7,7,7,7,7,7,3,1,0,0,0,0,0,0,0,7,7,7,0,0,0,0,0,0,0,0,0,3,7,7,7,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,7,7,7,0,0,7,15,15,63,63,62,28,28,28,28,30,30,30,15,15,7,7,1,0,1,3,3,3,3,3,3,3,3,3,3,3,1,0,0,0,0,0,0,1,31,63,63,63,31,15,15,7,31,31,31,30,30,15,15,7,7,3,3,1,0,0,0,0
};
static const char PROGMEM fus3d_logo[] = {
    //0,0,0,0,0,0,0,0,0,0,240,240,248,248,248,248,248,248,248,240,240,240,240,240,224,224,192,252,252,252,192,0,0,0,0,0,248,248,248,248,192,224,240,248,248,248,248,252,252,252,252,252,252,252,252,120,0,0,0,252,254,254,254,254,254,254,254,254,252,252,248,240,0,0,0,252,252,252,252,252,252,252,252,248,248,248,248,240,240,240,224,192,128,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,255,255,255,255,255,255,255,231,231,231,227,227,193,1,249,252,255,255,255,255,255,0,0,0,0,0,255,255,255,255,255,63,63,127,127,121,120,112,240,240,240,224,224,192,192,0,0,0,0,0,193,195,227,243,251,255,255,255,127,127,63,31,0,0,0,255,255,255,255,255,255,0,0,1,1,3,3,3,7,255,255,255,255,255,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,127,255,255,255,255,255,7,3,3,3,3,1,1,0,15,127,255,255,255,255,193,192,192,224,240,252,255,255,255,255,251,240,224,224,192,192,192,192,192,128,128,193,231,255,255,255,0,0,0,192,195,195,195,131,131,131,199,207,255,254,252,0,0,0,254,255,255,255,255,255,128,128,192,192,224,240,240,248,252,255,127,63,31,7,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,3,7,7,7,1,0,0,0,0,0,0,0,0,0,0,0,1,3,3,3,3,3,3,3,3,3,3,1,0,0,1,1,1,3,3,3,3,3,3,3,3,3,3,1,0,0,0,0,1,1,3,3,3,3,3,3,3,3,3,3,0,0,0,3,7,7,7,7,7,3,3,3,3,3,3,1,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0
    0,240,240,240,248,248,248,248,248,248,248,248,248,248,248,240,240,240,240,240,240,240,240,224,224,224,252,252,252,252,252,252,192,  0,  0,  0,  0,  0,  0,  0,248,248,248,248,248,248,248,224,224,240,248,248,248,248,248,248,252,252,252,252,252,252,252,252,252,252,252,252,252,248,248,  0,  0,  0,252,254,254,254,254,254,254,254,254,254,254,254,254,254,252,252,252,248,248,240,  0,  0,  0,  0,252,252,252,252,252,252,252,252,252,252,252,252,252,248,248,248,248,248,248,240,240,240,240,224,192,192,128,  0,  0,  0,
    0,255,255,255,255,255,255,255,255,255,255,255,223,223,223,223,223,199,207,199,131,  3,243,251,249,255,255,255,255,255,255,255,255,  0,  0,  0,  0,  0,  0,  0,255,255,255,255,255,255,255,255,255,255,255,255,255,255,243,243,241,225,225,225,225,225,225,193,193,193,129,129,129,  0,  0,  0,  0,  0,  1,131,131,143,207,207,239,247,247,255,255,255,255,255,255,255,255,255,255,127,  0,  0,  0,  0,255,255,255,255,255,255,255,255,255,255,  1,  1,  3,  3,  7, 15, 15, 15,  7, 15,255,255,255,255,255,255,255,255,254,  0, 
    0,255,255,255,255,255,255,255,255,255,255, 31, 31, 15, 15, 15, 15, 15,  7,  7,  7,  0, 63,255,255,255,255,255,255,255,255,255,  7,  0,  0,128,128,192,240,248,255,255,255,255,255,255,255,239,192,192,129,129,129,  1,  1,  1,  1,  1,  3,  3,  3,  3,  7,159,159,255,255,255,255,254,254,  0,  0,  0,  0, 15, 15, 15, 15, 15, 15, 15, 15, 15, 31, 31, 63,255,255,253,253,248,240,  0,  0,  0,252,252,255,255,255,255,255,255,255,255,  3,  3,  0,  0,  0,128,128,192,192,224,224,240,255,255,255,255,255,255,255,127, 31,  0, 
    0,  3, 31, 31, 63, 63, 63, 63, 63, 47, 15,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  3,  3,  7, 15, 15, 31, 31, 31, 31, 31, 31, 31, 31, 31, 31, 31, 31, 31, 31, 31, 31, 15,  7,  7, 15, 15, 15, 15, 15, 31, 31, 31, 31, 31, 31, 31, 31, 30, 30, 31, 31, 31, 31, 31, 15, 15,  7,  7,  0,  0,  0, 15, 15, 15, 31, 31, 31, 31, 30, 30, 30, 31, 31, 31, 31, 31, 31, 31, 31, 31,  0,  0,  0, 31, 31, 63, 63, 63, 63, 63, 63, 63, 63, 30, 30, 31, 31, 31, 31, 31, 31, 31, 15, 15, 15, 15, 15,  7,  3,  1,  1,  0,  0,  0,  0,
};
// static const char PROGMEM qwerty_logo[] = {
//     0,0,0,128,224,224,240,240,240,240,248,248,248,248,248,240,240,240,224,192,192,0,0,248,248,248,248,248,240,224,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,128,224,240,240,240,240,112,0,240,248,248,120,56,56,56,120,120,120,120,120,112,0,0,248,252,252,252,60,60,60,60,56,120,120,120,120,120,240,240,240,224,0,56,60,124,124,124,124,252,252,252,252,252,252,124,124,124,252,252,248,248,240,112,0,248,248,248,224,128,0,0,0,0,0,192,240,252,252,124,0,0,0,0,0,255,255,255,255,255,3,1,0,0,0,0,0,128,129,131,3,7,31,255,254,252,243,239,63,255,255,255,255,252,240,128,0,0,128,192,224,224,224,224,192,128,192,248,254,255,255,255,63,15,1,0,248,255,255,255,224,224,224,224,224,224,224,224,0,0,0,0,255,255,255,255,192,192,192,224,224,240,240,248,124,62,63,31,31,15,0,0,0,0,0,0,0,3,63,255,255,255,0,0,0,0,0,0,0,0,0,0,0,0,1,15,63,255,255,252,252,126,127,63,31,7,1,0,0,0,0,0,0,15,63,127,255,255,224,192,192,128,128,128,128,131,135,239,255,255,254,255,255,255,255,231,192,128,3,15,31,127,255,255,255,254,255,255,255,255,255,255,255,255,255,255,127,63,15,1,0,0,0,0,255,255,255,255,193,129,129,129,129,129,129,129,128,128,128,0,255,255,255,255,255,31,15,31,63,127,126,252,252,252,248,240,240,224,128,0,0,0,0,0,0,0,0,255,255,255,255,0,0,0,0,0,0,0,0,0,0,0,0,0,0,127,255,255,255,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,7,15,15,15,15,15,15,31,31,31,15,15,15,7,3,7,15,15,15,15,15,0,0,0,0,1,15,31,31,31,31,7,3,15,15,15,15,7,1,0,0,0,0,0,0,0,0,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,0,15,31,31,31,15,0,0,0,0,0,0,0,0,1,15,31,31,31,31,31,0,0,0,0,0,28,30,31,31,15,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,31,31,31,0,0,0,0,0,0,0,0,0
// };

void oled_render_layer_state(void) {
    uint8_t layer = biton32(layer_state);
    switch (layer) {
        case _QWERTY:
            oled_write_raw_P(fus3d_logo, sizeof(fus3d_logo));
            break;
        case _RAISE:
            static const char PROGMEM number_logo[] = {
                0,0,240,248,248,248,240,240,192,0,0,0,0,0,0,128,240,252,252,60,0,0,192,240,240,240,0,0,0,0,0,0,0,192,224,224,224,0,0,224,240,240,252,252,252,248,240,0,0,128,224,248,248,248,192,0,0,0,0,0,0,248,248,248,248,60,60,60,60,120,120,248,240,240,224,0,0,192,252,252,252,252,252,124,60,60,60,62,126,126,126,254,252,252,56,0,0,224,252,252,252,252,252,28,60,124,248,248,240,192,0,0,0,240,252,252,60,30,30,30,30,28,28,60,60,60,0,0,0,0,255,255,255,255,255,255,255,254,0,0,0,0,224,255,255,255,15,0,0,192,255,255,255,1,0,0,0,0,0,0,0,255,255,255,31,0,128,255,255,255,255,3,7,127,127,127,126,63,31,7,31,255,255,252,0,0,0,128,254,255,255,255,224,224,224,224,224,224,240,240,127,127,63,31,0,255,255,255,193,225,225,224,224,224,224,224,224,224,0,0,0,0,0,0,0,255,255,255,255,255,255,0,0,0,0,131,223,255,255,248,0,7,31,63,127,248,240,224,224,192,128,128,0,0,0,0,0,0,247,255,255,255,15,3,31,255,255,248,192,248,255,255,255,0,0,0,0,255,255,255,241,224,224,192,192,192,240,252,255,255,127,3,0,0,255,255,255,255,0,0,0,0,0,0,0,0,0,0,0,3,255,255,255,128,0,255,255,255,255,255,1,3,3,7,7,15,63,254,252,240,0,0,0,255,255,255,135,7,7,7,7,7,7,7,3,3,0,0,0,0,0,0,0,1,255,255,255,255,255,255,255,255,247,231,199,131,131,0,0,0,0,0,0,0,1,1,3,3,15,63,255,252,240,0,0,0,15,15,15,3,0,0,0,0,1,15,15,15,15,7,1,0,0,0,0,3,15,31,31,31,31,31,31,31,15,15,7,3,0,0,0,0,7,31,31,31,0,0,0,0,0,0,0,0,0,0,0,0,1,31,31,31,0,3,31,31,63,61,56,56,56,56,56,60,63,31,31,3,0,0,0,1,255,255,255,126,126,126,126,124,124,124,60,56,56,56,56,0,0,0,0,0,63,63,63,63,63,1,0,0,1,3,3,15,31,31,30,28,0,28,60,60,60,56,56,56,60,62,31,31,7,0
            };
            oled_write_raw_P(number_logo, sizeof(number_logo));
            break;
        case _LAYER2:
            oled_write_raw_P(symbol_logo, sizeof(symbol_logo));
            break;
        case _MLAYER:
            oled_write_raw_P(symbol_logo, sizeof(symbol_logo));
            break;
        case _NUMLAY:
            static const char PROGMEM browser_logo[] = {
                0,0,0,248,252,252,252,28,60,60,120,248,240,224,192,0,0,0,0,56,248,252,252,156,60,60,120,248,240,224,128,0,0,0,0,0,0,192,240,240,252,124,60,60,120,248,240,224,224,128,56,248,248,240,128,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,248,248,248,0,0,0,192,224,240,240,120,120,56,56,56,56,120,120,112,240,240,224,224,0,0,0,248,248,252,60,60,28,28,28,28,28,28,12,0,0,128,254,254,254,28,28,60,124,120,240,240,224,192,128,0,0,0,0,0,255,255,255,255,225,224,224,192,192,240,255,255,63,0,0,0,0,0,255,255,255,255,192,192,192,225,231,255,255,126,0,0,0,0,254,255,255,7,1,0,0,0,0,0,1,15,255,255,254,1,15,127,255,252,224,128,0,0,0,0,0,0,0,0,0,0,0,192,254,255,255,15,0,0,127,255,255,227,224,192,192,192,192,128,128,128,0,0,0,0,0,0,0,0,0,7,127,255,255,224,128,128,128,128,128,0,0,0,0,255,255,255,255,248,0,0,0,0,0,1,135,255,255,254,0,0,0,0,255,255,255,15,1,1,3,3,7,15,15,31,190,252,248,240,0,0,255,255,255,255,15,31,63,125,249,248,240,192,0,0,0,15,255,255,255,192,0,0,0,0,0,0,128,224,255,255,255,0,0,0,1,15,255,255,252,224,224,248,248,248,240,192,0,240,254,255,63,7,1,0,0,0,0,0,1,1,1,1,1,3,3,3,7,135,143,143,254,254,252,248,0,0,0,0,0,255,255,255,7,3,3,3,3,0,0,0,0,0,255,255,255,255,31,63,127,255,247,231,199,135,3,1,0,0,0,0,15,31,63,63,60,60,62,30,14,14,14,14,15,15,7,3,0,0,31,31,31,3,0,0,0,0,0,3,15,15,15,0,0,0,0,3,7,15,15,14,14,14,14,15,15,7,7,1,0,0,0,0,0,0,0,7,31,31,31,15,1,7,15,63,63,63,63,3,0,0,0,0,15,15,15,30,30,28,28,28,30,30,15,15,7,7,7,3,3,3,1,0,0,0,0,0,0,31,63,63,56,56,56,56,56,56,56,56,0,0,7,31,31,31,0,0,0,0,1,3,7,31,127,126,120,0
            };
            oled_write_raw_P(browser_logo, sizeof(browser_logo));
            break;
        case _TMUXLAY:
            static const char PROGMEM tmux_logo[] = {
                0,0,0,0,0,0,0,120,248,248,248,248,248,248,248,248,248,248,248,248,248,248,248,248,248,248,248,248,248,248,248,248,248,248,248,248,120,0,0,0,0,0,0,0,0,192,248,248,252,252,252,248,224,0,0,0,0,0,192,240,252,252,254,254,254,240,128,0,0,0,0,248,248,252,252,252,128,0,0,0,0,0,0,0,0,0,192,252,252,252,248,0,0,0,0,0,0,124,252,252,248,240,224,192,192,128,0,0,0,0,0,0,0,0,0,128,192,224,248,248,120,56,0,0,0,0,0,0,0,0,0,0,0,0,0,0,3,3,3,3,3,1,1,1,1,1,255,255,255,255,255,255,255,255,255,1,1,1,1,1,1,1,1,0,0,0,0,0,0,0,224,248,254,255,255,255,255,127,255,255,255,255,252,240,248,254,255,255,255,255,255,255,255,255,255,252,224,0,0,1,31,255,255,255,255,248,192,0,0,0,0,0,224,252,255,255,255,255,255,0,0,0,0,0,0,0,0,3,7,7,15,31,63,127,255,254,252,248,240,240,248,254,254,63,15,15,3,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,31,255,255,255,255,255,255,255,7,0,0,0,0,0,0,0,0,0,0,0,0,0,128,254,255,255,255,255,255,255,7,0,1,3,7,15,31,31,31,31,15,3,1,0,1,15,63,255,255,255,255,255,224,0,0,7,63,255,255,255,255,254,252,252,248,254,255,255,255,255,255,255,15,0,0,0,0,0,0,0,0,0,0,128,192,240,252,255,255,255,255,255,63,63,255,255,255,255,252,240,224,192,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,127,127,127,63,63,63,15,0,0,0,0,0,0,0,0,0,0,0,0,0,0,31,31,63,127,127,127,15,15,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,3,15,31,31,31,15,14,0,0,0,1,15,15,31,31,31,63,63,63,63,31,15,3,1,0,0,0,0,0,0,0,0,0,240,252,254,255,255,255,63,31,15,7,1,0,0,0,0,1,3,7,15,31,63,63,127,126,124,120,0,0,0,0
            };
            oled_write_raw_P(tmux_logo, sizeof(tmux_logo));
            break;
    }
}

char keylog_str[24] = {};

const char code_to_name[60] = {
    ' ', ' ', ' ', ' ', 'a', 'b', 'c', 'd', 'e', 'f',
    'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p',
    'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z',
    '1', '2', '3', '4', '5', '6', '7', '8', '9', '0',
    'R', 'E', 'B', 'T', '_', '-', '=', '[', ']', '\\',
    '#', ';', '\'', '`', ',', '.', '/', ' ', ' ', ' '};

void set_keylog(uint16_t keycode, keyrecord_t *record) {
  char name = ' ';
    if ((keycode >= QK_MOD_TAP && keycode <= QK_MOD_TAP_MAX) ||
        (keycode >= QK_LAYER_TAP && keycode <= QK_LAYER_TAP_MAX)) { keycode = keycode & 0xFF; }
  if (keycode < 60) {
    name = code_to_name[keycode];
  }

  // update keylog
  snprintf(keylog_str, sizeof(keylog_str), "%dx%d, k%2d : %c",
           record->event.key.row, record->event.key.col,
           keycode, name);
}

void oled_render_keylog(void) {
    oled_write(keylog_str, false);
}

void render_bootmagic_status(bool status) {
    /* Show Ctrl-Gui Swap options */
    static const char PROGMEM logo[][2][3] = {
        {{0x97, 0x98, 0}, {0xb7, 0xb8, 0}},
        {{0x95, 0x96, 0}, {0xb5, 0xb6, 0}},
    };
    if (status) {
        oled_write_ln_P(logo[0][0], false);
        oled_write_ln_P(logo[0][1], false);
    } else {
        oled_write_ln_P(logo[1][0], false);
        oled_write_ln_P(logo[1][1], false);
    }
}

void oled_render_logo(void) {
  oled_write_raw_P(fus3d_logo, sizeof(fus3d_logo));
}

//     static const char PROGMEM crkbd_logo[] = {
//         0x80, 0x81, 0x82, 0x83, 0x84, 0x85, 0x86, 0x87, 0x87, 0x89, 0x8a, 0x8b, 0x8c, 0x8d, 0x8e, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 
//         0xa0, 0xa1, 0xa2, 0xa3, 0xa4, 0xa5, 0xa6, 0xa7, 0xa8, 0xa9, 0xaa, 0xab, 0xac, 0xad, 0xae, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 
//         0xc0, 0xc1, 0xc2, 0xc3, 0xc4, 0xc5, 0xc6, 0xc7, 0xc8, 0xc9, 0xca, 0xcb, 0xcc, 0xcd, 0xce, 0x00,
//         };
//     oled_write_P(crkbd_logo, false);

bool oled_task_user(void) {
    if (is_keyboard_master()) {
        oled_render_layer_state();
        // oled_render_keylog();
        //oled_render_logo();
    } else {
        // oled_render_logo();
    }

    return false;
}
#endif


void keyboard_post_init_user(void) {
#ifdef PIMORONI_TRACKBALL_ENABLE
    trackball_set_rgbw(0,0,0,80);
#endif
}


bool process_record_user(uint16_t keycode, keyrecord_t *record){
  #ifdef OLED_ENABLE
  if (record->event.pressed) {
     set_keylog(keycode, record);
  }
  #endif
  switch (keycode) {
  #ifdef PIMORONI_TRACKBALL_ENABLE
    case BALL_LC:
       record->event.pressed?register_code(KC_BTN1):unregister_code(KC_BTN1);
       break;
    case BALL_SCR:
      if(record->event.pressed){
        trackball_set_scrolling(true);
      } else{
        trackball_set_scrolling(false);
      }
      break;
  #endif
    case BTAB:
      if (record->event.pressed) {
          // when keycode is pressed
          register_code(KC_LCTL);
          register_code(KC_TAB);
          unregister_code(KC_LCTL);
          unregister_code(KC_TAB);
      } else {
          // when keycode is released
      }
      break;
    case BBTAB:
      if (record->event.pressed) {
          // when keycode is pressed
          register_code(KC_LCTL);
          register_code(KC_LSFT);
          register_code(KC_TAB);
          unregister_code(KC_LCTL);
          unregister_code(KC_LSFT);
          unregister_code(KC_TAB);
      } else {
          // when keycode is released
      }
      break;
    case BPAGE:
      if (record->event.pressed) {
          // when keycode is pressed
          register_code(KC_LALT);
          register_code(KC_LEFT);
          unregister_code(KC_LALT);
          unregister_code(KC_LEFT);
      } else {
          // when keycode is released
      }
      break;
    case BBPAGE:
      if (record->event.pressed) {
          // when keycode is pressed
          register_code(KC_LALT);
          register_code(KC_RGHT);
          unregister_code(KC_LALT);
          unregister_code(KC_RGHT);
      } else {
          // when keycode is released
      }
      break;
    case TMUXL:
      if (record->event.pressed) {
          // when keycode is pressed
          SEND_STRING(SS_LCTL("a"));
          register_code(KC_LEFT);
          unregister_code(KC_LEFT);
      } else {
          // when keycode is released
      }
      break;
    case TMUXR:
      if (record->event.pressed) {
          // when keycode is pressed
          SEND_STRING(SS_LCTL("a"));
          register_code(KC_RGHT);
          unregister_code(KC_RGHT);
      } else {
          // when keycode is released
      }
      break;
    case TMUXU:
      if (record->event.pressed) {
          // when keycode is pressed
          SEND_STRING(SS_LCTL("a"));
          register_code(KC_UP);
          unregister_code(KC_UP);
      } else {
          // when keycode is released
      }
      break;
    case TMUXD:
      if (record->event.pressed) {
          // when keycode is pressed
          SEND_STRING(SS_LCTL("a"));
          register_code(KC_DOWN);
          unregister_code(KC_DOWN);
      } else {
          // when keycode is released
      }
      break;
    case TMUXZ:
      if (record->event.pressed) {
          // when keycode is pressed
          SEND_STRING(SS_LCTL("a"));
          SEND_STRING("z");
      } else {
          // when keycode is released
      }
      break;
    case TMUXMNU:
      if (record->event.pressed) {
          // when keycode is pressed
          SEND_STRING(SS_LCTL("a"));
          SEND_STRING("\"");
      } else {
          // when keycode is released
      }
      break;
    case TMUXLOG:
      if (record->event.pressed) {
          // when keycode is pressed
          SEND_STRING(SS_LCTL("a"));
          SEND_STRING("[");
      } else {
          // when keycode is released
      }
      break;
    case TMUXPAS:
      if (record->event.pressed) {
          // when keycode is pressed
          SEND_STRING(SS_LCTL("a"));
          SEND_STRING("]");
      } else {
          // when keycode is released
      }
      break;
    case TMUXSPL:
      if (record->event.pressed) {
          // when keycode is pressed
          SEND_STRING(SS_LCTL("a"));
          SEND_STRING("S");
      } else {
          // when keycode is released
      }
      break;
    case TMUXVSP:
      if (record->event.pressed) {
          // when keycode is pressed
          SEND_STRING(SS_LCTL("a"));
          SEND_STRING("|");
      } else {
          // when keycode is released
      }
      break;
    case TMUXMVU:
      if (record->event.pressed) {
          // when keycode is pressed
          SEND_STRING(SS_LCTL("a"));
          SEND_STRING(SS_LSFT("["));
      } else {
          // when keycode is released
      }
      break;
    case TMUXMVD:
      if (record->event.pressed) {
          // when keycode is pressed
          SEND_STRING(SS_LCTL("a"));
          SEND_STRING(SS_LSFT("]"));
      } else {
          // when keycode is released
      }
      break;
    case TMUXLST:
      if (record->event.pressed) {
          // when keycode is pressed
          SEND_STRING(SS_LCTL("a"));
          SEND_STRING(SS_LCTL("a"));
      } else {
          // when keycode is released
      }
      break;
    case TMUXTIT:
      if (record->event.pressed) {
          // when keycode is pressed
          SEND_STRING(SS_LCTL("a"));
          SEND_STRING("A");
      } else {
          // when keycode is released
      }
      break;
    case TMUXCMD:
      if (record->event.pressed) {
          // when keycode is pressed
          SEND_STRING(SS_LCTL("a"));
          SEND_STRING(":");
      } else {
          // when keycode is released
      }
      break;
    case TMUX0:
      if (record->event.pressed) {
          // when keycode is pressed
          SEND_STRING(SS_LCTL("a"));
          SEND_STRING("0");
      } else {
          // when keycode is released
      }
      break;
    case TMUX1:
      if (record->event.pressed) {
          // when keycode is pressed
          SEND_STRING(SS_LCTL("a"));
          SEND_STRING("1");
      } else {
          // when keycode is released
      }
      break;
    case TMUX2:
      if (record->event.pressed) {
          // when keycode is pressed
          SEND_STRING(SS_LCTL("a"));
          SEND_STRING("2");
      } else {
          // when keycode is released
      }
      break;
    case TMUX3:
      if (record->event.pressed) {
          // when keycode is pressed
          SEND_STRING(SS_LCTL("a"));
          SEND_STRING("3");
      } else {
          // when keycode is released
      }
      break;
    case TMUX4:
      if (record->event.pressed) {
          // when keycode is pressed
          SEND_STRING(SS_LCTL("a"));
          SEND_STRING("4");
      } else {
          // when keycode is released
      }
      break;
    case TMUX5:
      if (record->event.pressed) {
          // when keycode is pressed
          SEND_STRING(SS_LCTL("a"));
          SEND_STRING("5");
      } else {
          // when keycode is released
      }
      break;
    case TMUX6:
      if (record->event.pressed) {
          // when keycode is pressed
          SEND_STRING(SS_LCTL("a"));
          SEND_STRING("6");
      } else {
          // when keycode is released
      }
      break;
    case TMUX7:
      if (record->event.pressed) {
          // when keycode is pressed
          SEND_STRING(SS_LCTL("a"));
          SEND_STRING("7");
      } else {
          // when keycode is released
      }
      break;
    case TMUX8:
      if (record->event.pressed) {
          // when keycode is pressed
          SEND_STRING(SS_LCTL("a"));
          SEND_STRING("8");
      } else {
          // when keycode is released
      }
      break;
    case TMUX9:
      if (record->event.pressed) {
          // when keycode is pressed
          SEND_STRING(SS_LCTL("a"));
          SEND_STRING("9");
      } else {
          // when keycode is released
      }
      break;
    case TMUXNXT:
      if (record->event.pressed) {
          // when keycode is pressed
          SEND_STRING(SS_LCTL("a"));
          SEND_STRING("n");
      } else {
          // when keycode is released
      }
      break;
    case TMUXPRV:
      if (record->event.pressed) {
          // when keycode is pressed
          SEND_STRING(SS_LCTL("a"));
          SEND_STRING("p");
      } else {
          // when keycode is released
      }
      break;
    case TMUXNEW:
      if (record->event.pressed) {
          // when keycode is pressed
          SEND_STRING(SS_LCTL("a"));
          SEND_STRING("c");
      } else {
          // when keycode is released
      }
      break;
    case TMUXRL:
      if (record->event.pressed) {
          // when keycode is pressed
          SEND_STRING(SS_LCTL("a"));
          register_code(KC_LALT);
          register_code(KC_LEFT);
          unregister_code(KC_LALT);
          unregister_code(KC_LEFT);
      } else {
          // when keycode is released
      }
      break;
    case TMUXRR:
      if (record->event.pressed) {
          // when keycode is pressed
          SEND_STRING(SS_LCTL("a"));
          register_code(KC_LALT);
          register_code(KC_RGHT);
          unregister_code(KC_LALT);
          unregister_code(KC_RGHT);
      } else {
          // when keycode is released
      }
      break;
    case TMUXRU:
      if (record->event.pressed) {
          // when keycode is pressed
          SEND_STRING(SS_LCTL("a"));
          register_code(KC_LALT);
          register_code(KC_UP);
          unregister_code(KC_LALT);
          unregister_code(KC_UP);
      } else {
          // when keycode is released
      }
      break;
    case TMUXRD:
      if (record->event.pressed) {
          // when keycode is pressed
          SEND_STRING(SS_LCTL("a"));
          register_code(KC_LALT);
          register_code(KC_DOWN);
          unregister_code(KC_LALT);
          unregister_code(KC_DOWN);
      } else {
          // when keycode is released
      }
      break;
     }
    return true;
};

#ifdef PIMORONI_TRACKBALL_ENABLE
layer_state_t layer_state_set_user(layer_state_t state) {
    switch (get_highest_layer(state)) {
    case _BASE:
        trackball_set_rgbw(0,0,0,80);
        break;
    case _NAV:
        trackball_set_rgbw(0,153,95,0);
        break;
    case _SYM:
        trackball_set_rgbw(153,113,0,0);
        break;
    default: //  for any other layers, or the default layer
        trackball_set_rgbw(0,0,0,80);
        break;
    }
  return state;
}
#endif
