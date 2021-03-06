#include QMK_KEYBOARD_H

extern keymap_config_t keymap_config;

static uint32_t key_timer = 0;
static bool key_trigger = false;
enum custom_keycodes {
    KEY_TIMER = SAFE_RANGE,
};

bool process_record_user(uint16_t keycode, keyrecord_t* record) {
    switch (keycode) {
        case KEY_TIMER:
            if (record->event.pressed) {
                key_trigger ^= true;
				if (key_trigger) {
					// ON
					tap_code(KC_O);
					tap_code(KC_N);
				} else {
					// OFF
					tap_code(KC_O);
					tap_code(KC_F);
					tap_code(KC_F);
				}
            }
            break;
    }
    return true;
}

void matrix_scan_user(void) { 
    if (timer_elapsed32(key_timer) > 30000) { // 30 seconds
        key_timer = timer_read32();  // resets timer
        if (key_trigger) tap_code(KC_LSFT); // tap if enabled
    }
}

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

	LAYOUT_planck_mit(
		KC_TAB, KC_Q, KC_W, KC_E, KC_R, KC_T, KC_Y, KC_U, KC_I, KC_O, KC_P, KC_BSPC, 
		KC_ESC, KC_A, KC_S, KC_D, KC_F, KC_G, KC_H, KC_J, KC_K, KC_L, KC_SCLN, KC_QUOT, 
		KC_LSFT, KC_Z, KC_X, KC_C, KC_V, KC_B, KC_N, KC_M, KC_COMM, KC_DOT, KC_SLSH, RSFT_T(KC_ENT), 
		KC_LCTL, KC_LCTL, KC_LGUI, KC_LALT, MO(2), KC_SPC, MO(1), KC_HOME, KC_PGDOWN, KC_PGUP, KC_END),

	LAYOUT_planck_mit(
		KC_TILD, KC_EXLM, KC_AT, KC_HASH, KC_DLR, KC_PERC, KC_CIRC, KC_AMPR, KC_ASTR, KC_LPRN, KC_RPRN, KC_TRNS, 
		KC_DEL, KC_UNDS, KC_LCBR, KC_RCBR, KC_TRNS, KC_PLUS, KC_LEFT, KC_DOWN, KC_UP, KC_RGHT, KC_TRNS, KC_TRNS, 
		KC_TRNS, KC_F7, KC_F8, KC_F9, KC_F10, KC_F11, KC_F12, KC_PIPE, KC_MNXT, KC_HOME, KC_END, KC_TRNS, 
		KEY_TIMER, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_MUTE, KC_VOLD, KC_VOLU, KC_MPLY),

	LAYOUT_planck_mit(
		KC_GRV, KC_1, KC_2, KC_3, KC_4, KC_5, KC_6, KC_7, KC_8, KC_9, KC_0, KC_TRNS, 
		KC_DEL, KC_MINS, KC_LBRC, KC_RBRC, KC_TRNS, KC_EQL, KC_LEFT, KC_DOWN, KC_UP, KC_RGHT, KC_TRNS, KC_TRNS, 
		KC_TRNS, KC_F1, KC_F2, KC_F3, KC_F4, KC_F5, KC_F6, KC_BSLS, KC_INS, KC_PGDN, KC_PGUP, KC_TRNS, 
		RESET, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_PSCR, KC_INS, KC_CAPS, KC_PAUS),
};

const macro_t *action_get_macro(keyrecord_t *record, uint8_t id, uint8_t opt) {
	return MACRO_NONE;
}

void matrix_init_user(void) {
}

void led_set_user(uint8_t usb_led) {

	if (usb_led & (1 << USB_LED_NUM_LOCK)) {
		
	} else {
		
	}

	if (usb_led & (1 << USB_LED_CAPS_LOCK)) {
		
	} else {
		
	}

	if (usb_led & (1 << USB_LED_SCROLL_LOCK)) {
		
	} else {
		
	}

	if (usb_led & (1 << USB_LED_COMPOSE)) {
		
	} else {
		
	}

	if (usb_led & (1 << USB_LED_KANA)) {
		
	} else {
		
	}

}