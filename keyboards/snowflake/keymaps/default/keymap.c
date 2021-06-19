#include QMK_KEYBOARD_H
#include "rgblight.h"
#include "rgb_matrix.h"
#include "eeprom.h"

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [0] = LAYOUT(KC_GRV,  KC_1, KC_2, KC_3,    KC_4,  KC_5,                /**/       KC_6,   KC_7,   KC_8,    KC_9,   KC_0,    KC_BSPC,
                 KC_TAB,  KC_Q, KC_W, KC_E,    KC_R,  KC_T,                /**/       KC_Y,   KC_U,   KC_I,    KC_O,   KC_P,    KC_BSLS,
                 KC_LSFT, KC_A, KC_S, KC_D,    KC_F,  KC_G,  TT(4),        /**/KC_NO, KC_H,   KC_J,   KC_K,    KC_L,   KC_SCLN, KC_QUOT,
        KC_LCTL, TT(3),   KC_Z, KC_X, KC_C,    KC_V,  KC_B,  OSM(MOD_HYPR),/**/KC_NO, KC_N,   KC_M,   KC_COMM, KC_DOT, KC_SLSH, KC_RSFT, KC_PENT,
                          KC_LGUI,    KC_LALT, TT(1), TT(2), KC_SPC,       /**/TT(2), KC_ENT, KC_SPC, KC_BSPC,         KC_PENT),
// Symbols
    [1] = LAYOUT(KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,         /**/         KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
                 KC_TRNS, KC_EXLM, KC_AT,   KC_HASH, KC_DLR,  KC_PERC,         /**/         KC_CIRC, KC_AMPR, KC_ASTR, KC_MINS, KC_EQL,  KC_TRNS,
                 KC_TRNS, KC_TRNS, KC_TRNS, KC_LBRC, KC_RBRC, KC_TRNS, KC_TRNS,/**/KC_TRNS, KC_MINS, KC_LPRN, KC_RPRN, KC_EQL,  KC_BSLS, KC_TRNS,
        KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,/**/KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
                          KC_TRNS,          KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,/**/KC_TRNS, KC_TRNS, KC_TRNS, KC_BSPC,          KC_TRNS),
// Navigation
    [2] = LAYOUT(KC_ESC,  KC_F1,  KC_F2,   KC_F3,   KC_F4,   KC_F5,           /**/         KC_F6,   KC_F7,   KC_F8,  KC_F9,   KC_F10,   KC_F11,
                 KC_CAPS, KC_ESC, KC_TRNS, KC_TRNS, KC_F11,  KC_F12,          /**/         KC_PGUP, KC_HOME, KC_DEL, KC_END,  KC_NO,    KC_F12,
                 KC_TRNS, KC_F1,  KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_TRNS,/**/KC_TRNS, KC_LEFT, KC_DOWN, KC_UP,  KC_RGHT, KC_INS,   KC_TRNS,
        KC_TRNS, KC_TRNS, KC_F6,  KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_TRNS,/**/KC_TRNS, KC_PGDN, KC_NO,   KC_NO,  KC_NO,   KC_PSCR,  KC_SLCK, KC_PAUS,
                          KC_TRNS,         KC_TRNS, KC_LALT, KC_TRNS, KC_TRNS,/**/KC_TRNS, KC_BSPC, KC_BSPC, KC_BSPC,         KC_APP),
// Mouse/numpad
    [3] = LAYOUT(RESET,         KC_NO, KC_NO,   KC_NO,   KC_NO,   KC_NO,           /**/            KC_NO,   KC_NO, KC_PSLS, KC_PAST, KC_PMNS, KC_NO,
                 KC_NO,         KC_NO, KC_BTN3, KC_MS_U, KC_BTN2, KC_WH_U,         /**/            KC_PSLS, KC_P7, KC_P8,   KC_P9,   KC_PMNS, KC_NO,
                 LCTL(KC_LSFT), KC_NO, KC_MS_L, KC_MS_D, KC_MS_R, KC_BTN1, KC_TRNS,/**/KC_NUMLOCK, KC_PAST, KC_P4, KC_P5,   KC_P6,   KC_PPLS, KC_NO,
          KC_NO, KC_TRNS,       KC_NO, KC_NO,   KC_NO,   KC_NO,   KC_WH_D, KC_NO,  /**/     KC_NO, KC_BSPC, KC_P1, KC_P2,   KC_P3,   KC_NO,   KC_PENT, KC_NO,
                                KC_NO,          KC_NO,   KC_TRNS, KC_TRNS, KC_NO,  /**/     KC_NO, KC_PENT, KC_P0, KC_BSPC,          KC_NO),
// Misc
    [4] = LAYOUT(KC_NO,   KC_NO, KC_NO, KC_NO,            KC_NO,   KC_NO,           /**/       KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO,
                 KC_NO,   KC_NO, KC_NO, KC_NO,            RGB_VAD, RGB_VAI,         /**/       KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO,
                 KC_NO,   KC_NO, KC_NO, KC_MPRV,          KC_MNXT, KC_MPLY, KC_TRNS,/**/KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO,
          KC_NO, KC_TRNS, KC_NO, KC_NO, RGB_MODE_REVERSE, RGB_MOD, RGB_TOG, KC_NO,  /**/KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO,
                          KC_NO,        KC_NO,            KC_TRNS, KC_TRNS, KC_NO,  /**/KC_NO, KC_NO, KC_NO, KC_NO,        KC_NO)
};

const rgblight_segment_t PROGMEM my_layer1_layer[] = RGBLIGHT_LAYER_SEGMENTS(
    {0, 1, HSV_RED}
);
const rgblight_segment_t PROGMEM my_layer2_layer[] = RGBLIGHT_LAYER_SEGMENTS(
    {1, 1, HSV_GREEN}
);
const rgblight_segment_t PROGMEM my_layer3_layer[] = RGBLIGHT_LAYER_SEGMENTS(
    {2, 1, HSV_BLUE}
);
const rgblight_segment_t PROGMEM my_layer4_layer[] = RGBLIGHT_LAYER_SEGMENTS(
    {3, 1, HSV_PURPLE}
);

const rgblight_segment_t PROGMEM my_num_lock_layer[] = RGBLIGHT_LAYER_SEGMENTS(
    {4, 1, HSV_RED}
);

const rgblight_segment_t PROGMEM my_caps_lock_layer[] = RGBLIGHT_LAYER_SEGMENTS(
    {5, 1, HSV_YELLOW}
);

const rgblight_segment_t PROGMEM my_scroll_lock_layer[] = RGBLIGHT_LAYER_SEGMENTS(
    {6, 1, HSV_GREEN}
);

// Now define the array of layers. Later layers take precedence
const rgblight_segment_t* const PROGMEM my_rgb_layers[] = RGBLIGHT_LAYERS_LIST(
    my_num_lock_layer,
    my_layer1_layer,
    my_layer2_layer,
    my_layer3_layer,
    my_layer4_layer,
    my_caps_lock_layer,
    my_scroll_lock_layer
);
 
void keyboard_post_init_user(void) {
    rgblight_layers = my_rgb_layers;
}

layer_state_t layer_state_set_user(layer_state_t state) {
    uint8_t brightness = rgblight_get_val();

    rgblight_set_layer_state(1, layer_state_cmp(state, 1), brightness);
    rgblight_set_layer_state(2, layer_state_cmp(state, 2), brightness);
    rgblight_set_layer_state(3, layer_state_cmp(state, 3), brightness);
    rgblight_set_layer_state(4, layer_state_cmp(state, 4), brightness);

    return state;
}

bool led_update_user(led_t led_state) {
    uint8_t brightness = rgblight_get_val();
    rgblight_set_layer_state(0, !led_state.num_lock, brightness);
    rgblight_set_layer_state(5, led_state.caps_lock, brightness);
    rgblight_set_layer_state(6, led_state.scroll_lock, brightness);
    return true;
}
