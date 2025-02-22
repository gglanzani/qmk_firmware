// This is the keymap for a Binepad BNK9
// It showcases how to activate the led/RGB matrix for a single button to indicate
// which layer is active

#include QMK_KEYBOARD_H

// the board has 9 leds, starting from position 0
int led_min = 0;
int led_max = 8;

enum custom_keycodes {
    MACRO0 = SAFE_RANGE,
    MACRO1,
    MACRO2,
    MACRO3,
    MACRO4,
    MACRO5,
    MACRO6
};

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case MACRO0:
            if (record->event.pressed) {
                SEND_STRING(SS_LGUI("["));
            }
            break;
        case MACRO1:
            if (record->event.pressed) {
                SEND_STRING(SS_LGUI("]"));
            }
            break;
        case MACRO2:
            if (record->event.pressed) {
                SEND_STRING(SS_LGUI("{"));
            }
            break;
        case MACRO3:
            if (record->event.pressed) {
                SEND_STRING(SS_LGUI("}"));
            }
            break;
        case MACRO4:
            if (record->event.pressed) {
                SEND_STRING(SS_LGUI(SS_LSFT("m")));
            }
            break;
        case MACRO6:
            if (record->event.pressed) {
                SEND_STRING(SS_LCTL(SS_LGUI(SS_LALT(SS_LSFT("q")))));
            }
            break;
    }
    return true;
}

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [0] = LAYOUT(
        KC_MUTE, // activated when pressing the wheel
        KC_F12,    KC_F13,    KC_F16,
        KC_F17,    MACRO4,    KC_F19,
        MACRO6,    RM_TOGG,    TO(1)
    ),
    [1] = LAYOUT(
        RM_TOGG,
        MACRO0,  MACRO1,  RM_SPDU,
        MACRO2,  MACRO3,  RM_SPDD,
        RM_PREV,  RM_NEXT,  TO(0)
    )
};

led_config_t g_led_config = { {
  // Key Matrix to LED Index
  { 1, 2, 3},
  { 4, 5, 6},
  { 7, 8, 9}
}, {
  // LED Index to Physical Position
  { 0,  0},   { 187,  0},  { 224,  0},
  { 0,  32 }, { 187,  32}, { 224,  32},
  { 0,  64 }, { 187,  64}, { 224,  64 }
}, {
  // LED Index to Flag
  1, 1, 1, 1, 1, 1, 1, 1, 1
} };

#if defined(ENCODER_MAP_ENABLE)
// rotation of the wheel in the different layers
const uint16_t PROGMEM encoder_map[][NUM_ENCODERS][NUM_DIRECTIONS] = {
    [0] = { ENCODER_CCW_CW(KC_VOLD, KC_VOLU) },
    [1] = { ENCODER_CCW_CW(KC_MS_WH_DOWN, KC_MS_WH_UP) }
};

#endif

void keyboard_post_init_user(void) {
    // we enable the rgb matrix
    rgb_matrix_enable_noeeprom();
}

bool rgb_matrix_indicators_advanced_user(uint8_t led_min, uint8_t led_max) {
    switch(get_highest_layer(layer_state|default_layer_state)) {
        case 1:
            // somehow, I need to turn them off here as they do not work in keyboard_post_init_user
            for (uint8_t i = led_min; i < led_max; i++) {
                rgb_matrix_set_color(i, 0, 0, 0);
            }
            rgb_matrix_set_color(1, RGB_BLUE);
            break;
        case 0:
            for (uint8_t i = led_min; i < led_max; i++) {
                rgb_matrix_set_color(i, 0, 0, 0);
            }
            rgb_matrix_set_color(0, RGB_BLUE);
            break;
        default:
            break;
    }
    return false;
}
