#include QMK_KEYBOARD_H
#include "version.h"
#define MOON_LED_LEVEL LED_LEVEL
#define ML_SAFE_RANGE SAFE_RANGE

enum custom_keycodes {
  RGB_SLD = ML_SAFE_RANGE,
  HSV_0_245_245,
  HSV_74_255_206,
  HSV_152_255_255,
};


const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [0] = LAYOUT_moonlander(
    KC_GRAVE,       KC_1,           KC_2,           KC_3,           KC_4,           KC_5,           TT(1),                                          TT(2),          KC_6,           KC_7,           KC_8,           KC_9,           KC_0,           KC_MINUS,       
    KC_DELETE,      KC_Q,           KC_W,           KC_E,           KC_R,           KC_T,           KC_TAB,                                         KC_ENTER,       KC_Y,           KC_U,           KC_I,           KC_O,           KC_P,           KC_EQUAL,       
    KC_BSPC,        KC_A,           KC_S,           KC_D,           KC_F,           KC_G,           KC_ESCAPE,                                                                      KC_HYPR,        KC_H,           KC_J,           KC_K,           KC_L,           KC_SCLN,        KC_QUOTE,       
    KC_LEFT_SHIFT,  KC_Z,           KC_X,           KC_C,           KC_V,           KC_B,                                           KC_N,           KC_M,           KC_COMMA,       KC_DOT,         KC_SLASH,       KC_MINUS, 
    MO(1),          CW_TOGG,        KC_LEFT,        KC_RIGHT,       SC_LCPO,   KC_LEFT_CTRL,                                                                                                   KC_RIGHT_CTRL,  SC_RCPC,  KC_UP,          KC_DOWN,        KC_LBRC,        KC_RBRC,        
    KC_BSPC,        SC_LAPO,    SC_LSPO,                  SC_RSPC, SC_RAPC,    KC_SPACE
  ),
  [1] = LAYOUT_moonlander(
    KC_ESCAPE,      KC_F1,          KC_F2,          KC_F3,          KC_F4,          KC_F5,          KC_TRANSPARENT,                                 KC_TRANSPARENT, KC_F6,          KC_F7,          KC_F8,          KC_F9,          KC_F10,         KC_UNDS,        
    KC_TRANSPARENT, RGB_MODE_FORWARD,RGB_VAD,        RGB_VAI,        TOGGLE_LAYER_COLOR,KC_PIPE,        KC_TRANSPARENT,                                 KC_TRANSPARENT, KC_UP,          KC_LCBR,        KC_RCBR,        KC_LBRC,        KC_RBRC,        KC_F12,         
    KC_TRANSPARENT, RGB_TOG,        RGB_SLD,        RGB_HUD,        RGB_HUI,        KC_GRAVE,       KC_TRANSPARENT,                                                                 KC_TRANSPARENT, KC_LEFT,        KC_DOWN,        KC_UP,          KC_RIGHT,       KC_KP_PLUS,     KC_TRANSPARENT, 
    KC_TRANSPARENT, KC_PERC,        KC_CIRC,        KC_LBRC,        KC_RBRC,        KC_TILD,                                        KC_AMPR,        KC_1,           KC_LABK,        KC_RABK,        KC_BSLS,        KC_TRANSPARENT, 
    KC_TRANSPARENT, KC_COMMA,       HSV_0_245_245,  HSV_74_255_206, HSV_152_255_255,KC_LEFT_CTRL,                                                                                                   KC_RIGHT_CTRL,  A(KC_LEFT), A(KC_RIGHT),         KC_0,           KC_EQUAL,       KC_TRANSPARENT, 
    KC_BSPC,        KC_LEFT_GUI,    KC_LEFT_SHIFT,                  KC_RIGHT_SHIFT, KC_LEFT_ALT,    KC_SPACE
  ),
  [2] = LAYOUT_moonlander(
    AU_TOGG,        KC_F1,          KC_F2,          KC_F3,          KC_F4,          KC_F5,          KC_TRANSPARENT,                                 KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, QK_BOOT,        
    MU_TOGG,        KC_TRANSPARENT, KC_TRANSPARENT, KC_MS_UP,       KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,                                 KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, 
    MU_NEXT,        KC_TRANSPARENT, KC_MS_LEFT,     KC_MS_DOWN,     KC_MS_RIGHT,    KC_TRANSPARENT, KC_TRANSPARENT,                                                                 KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_MEDIA_PLAY_PAUSE,
    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,                                 KC_TRANSPARENT, KC_TRANSPARENT, KC_MEDIA_PREV_TRACK,KC_MEDIA_NEXT_TRACK,KC_TRANSPARENT, KC_TRANSPARENT, 
    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_MS_BTN1,     KC_MS_BTN2,     KC_TRANSPARENT,                                                                                                 KC_TRANSPARENT, KC_AUDIO_VOL_UP,KC_AUDIO_VOL_DOWN,KC_AUDIO_MUTE,  KC_TRANSPARENT, KC_TRANSPARENT, 
    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,                 KC_TRANSPARENT, KC_TRANSPARENT, KC_WWW_BACK
  ),
};

