#include QMK_KEYBOARD_H


#define _LAYER0 0
#define _LAYER1 1

enum custom_keycodes {
    LAYER0 = SAFE_RANGE,
    LAYER1,
    JC_ON,
    JC_OFF,
    JC_MIND,
    JC_MINU,
    JC_MAXD,
    JC_MAXU,
};

enum {
    TD_0_S,
    TD_1_S,
    TD_2_S,
    TD_3_S,
    TD_4_S,
    TD_5_S,
    TD_6_S,
    TD_7_S,
    TD_8_S,
    TD_9_S,
    TD_F1_F13,
    TD_F2_F14,
    TD_F3_F15,
    TD_F4_F16,
    TD_F5_F17,
    TD_F6_F18,
    TD_F7_F19,
    TD_F8_F20,
    TD_F9_F21,
    TD_F10_F22,
    TD_F11_F23,
    TD_F12_F24
};

// Tap Dance definitions
qk_tap_dance_action_t tap_dance_actions[] = {
    // Tap once for Escape, twice for Caps Lock
    [TD_0_S] = ACTION_TAP_DANCE_DOUBLE(KC_GRV, LSFT(KC_GRV)),
    [TD_1_S] = ACTION_TAP_DANCE_DOUBLE(KC_1, LSFT(KC_1)),
    [TD_2_S] = ACTION_TAP_DANCE_DOUBLE(KC_2, LSFT(KC_2)),
    [TD_3_S] = ACTION_TAP_DANCE_DOUBLE(KC_3, LSFT(KC_3)),
    [TD_4_S] = ACTION_TAP_DANCE_DOUBLE(KC_4, LSFT(KC_4)),
    [TD_5_S] = ACTION_TAP_DANCE_DOUBLE(KC_5, LSFT(KC_5)),
    [TD_6_S] = ACTION_TAP_DANCE_DOUBLE(KC_6, LSFT(KC_6)),
    [TD_7_S] = ACTION_TAP_DANCE_DOUBLE(KC_7, LSFT(KC_7)),
    [TD_8_S] = ACTION_TAP_DANCE_DOUBLE(KC_8, LSFT(KC_8)),
    [TD_9_S] = ACTION_TAP_DANCE_DOUBLE(KC_9, LSFT(KC_9)),
    [TD_F1_F13] = ACTION_TAP_DANCE_DOUBLE(KC_F1, KC_F13),
    [TD_F2_F14] = ACTION_TAP_DANCE_DOUBLE(KC_F1, KC_F14),
    [TD_F3_F15] = ACTION_TAP_DANCE_DOUBLE(KC_F1, KC_F15),
    [TD_F4_F16] = ACTION_TAP_DANCE_DOUBLE(KC_F1, KC_F16),
    [TD_F5_F17] = ACTION_TAP_DANCE_DOUBLE(KC_F1, KC_F17),
    [TD_F6_F18] = ACTION_TAP_DANCE_DOUBLE(KC_F1, KC_F18),
    [TD_F7_F19] = ACTION_TAP_DANCE_DOUBLE(KC_F1, KC_F19),
    [TD_F8_F20] = ACTION_TAP_DANCE_DOUBLE(KC_F1, KC_F20),
    [TD_F9_F21] = ACTION_TAP_DANCE_DOUBLE(KC_F1, KC_F21),
    [TD_F10_F22] = ACTION_TAP_DANCE_DOUBLE(KC_F10, KC_F22),
    [TD_F11_F23] = ACTION_TAP_DANCE_DOUBLE(KC_F11, KC_F23),
    [TD_F12_F24] = ACTION_TAP_DANCE_DOUBLE(KC_F12, KC_F24)
};


 const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

 [_LAYER0] = LAYOUT_all(KC_ESC, TD(TD_F1_F13), TD(TD_F2_F14), TD(TD_F3_F15), TD(TD_F4_F16), TD(TD_F5_F17), TD(TD_F6_F18), TD(TD_F7_F19), TD(TD_F8_F20), TD(TD_F9_F21), TD(TD_F10_F22), TD(TD_F11_F23), TD(TD_F12_F24), KC_PSCR, KC_SLCK, KC_PAUS,
 TD(TD_0_S), TD(TD_1_S),  TD(TD_2_S),  TD(TD_3_S),  TD(TD_4_S),  TD(TD_5_S),  TD(TD_6_S),  TD(TD_7_S),  TD(TD_8_S),  TD(TD_9_S), KC_0, KC_MINS, KC_EQL, KC_BSPC, KC_INS, KC_HOME, KC_PGUP, KC_NLCK, KC_PSLS, KC_PAST, KC_PMNS,
 KC_TAB, KC_Q, KC_W, KC_E, KC_R, KC_T, KC_Y, KC_U, KC_I, KC_O, KC_P, KC_LBRC, KC_RBRC, KC_BSLS, KC_DEL, KC_END, KC_PGDN, KC_P7, KC_P8, KC_P9, KC_PPLS,
 KC_CAPS, KC_A, KC_S, KC_D, KC_F, KC_G, KC_H, KC_J, KC_K, KC_L, KC_SCLN, KC_QUOT, KC_NUHS, KC_ENT, KC_P4, KC_P5, KC_P6,
 KC_LSFT, KC_NUBS, KC_Z, KC_X, KC_C, KC_V, KC_B, KC_N, KC_M, KC_COMM, KC_DOT, KC_SLSH, KC_RSFT, KC_UP, KC_P1, KC_P2, KC_P3, KC_PENT,
 KC_LCTL, KC_LGUI, KC_LALT, KC_SPC, KC_RALT, MO(1), KC_APP, KC_RCTL, KC_LEFT, KC_DOWN, KC_RGHT, KC_P0, KC_PDOT),

[_LAYER1] = LAYOUT_all(RESET, KC_MPLY, KC_MSTP, KC_MPRV, KC_MNXT, KC_MUTE, KC_VOLD, KC_VOLU, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
JC_ON, JC_OFF, JC_MIND, JC_MINU, JC_MAXD, JC_MAXU, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
KC_TRNS, KC_TGUI, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS)

};

uint32_t min_time = 2000;
uint32_t max_time = 5000;
uint32_t step = 100;
static uint16_t key_timer;
uint32_t wait = 2000;
char val_to_write[20];
bool is_jcMacroActive = false;

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case JC_ON:
            if (record->event.pressed) {
                is_jcMacroActive = true;
                key_timer = timer_read();
                SEND_STRING("JC_ON");
            }
        break;

        case JC_MINU:
            if (record->event.pressed) {
                min_time+=step;
                SEND_STRING("JC_MIN: ");
                SEND_STRING( itoa(min_time, val_to_write, 10));
                SEND_STRING("    ");
            }
        break;

        case JC_MIND:
            if (record->event.pressed && min_time>step) {
                min_time-=step;
                SEND_STRING("JC_MIN: ");
                SEND_STRING( itoa(min_time, val_to_write, 10));
                SEND_STRING("    ");
            }
        break;

          case JC_MAXU:
            if (record->event.pressed) {
                max_time+=step*10;
                SEND_STRING("JC_MAX: ");
                SEND_STRING( itoa(max_time, val_to_write, 10));
                SEND_STRING("    ");
            }
        break;

        case JC_MAXD:
            if (record->event.pressed && max_time>min_time+step*10) {
                max_time-=step*10;
                SEND_STRING("JC_MAX: ");
                SEND_STRING( itoa(max_time, val_to_write, 10));
                SEND_STRING("    ");
            }
        break;

        case JC_OFF:
        if(record-> event.pressed)
        {
            is_jcMacroActive = false;
            SEND_STRING("JC_OFF");
        }
        break;
    }

    return true;
}

void housekeeping_task_kb(void)
{
     if(is_jcMacroActive)
    {
        if(timer_elapsed(key_timer) > wait)
        {
            tap_random_base64();
            key_timer = timer_read();

            uint32_t randomMod = (max_time-min_time);
            wait = (rand() % randomMod)+min_time;
            if(rand()%5==0)
            {
                register_code16(KC_BTN1);
                unregister_code16(KC_BTN1);
            }
        }
    }
}
