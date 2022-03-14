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

 const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

 [_LAYER0] = LAYOUT_all(KC_ESC, KC_F1, KC_F2, KC_F3, KC_F4, KC_F5, KC_F6, KC_F7, KC_F8, KC_F9, KC_F10, KC_F11, KC_F12, KC_PSCR, KC_SLCK, KC_PAUS, 
 KC_GRV, KC_1, KC_2, KC_3, KC_4, KC_5, KC_6, KC_7, KC_8, KC_9, KC_0, KC_MINS, KC_EQL, KC_BSPC, KC_INS, KC_HOME, KC_PGUP, KC_NLCK, KC_PSLS, KC_PAST, KC_PMNS, 
 KC_TAB, KC_Q, KC_W, KC_E, KC_R, KC_T, KC_Y, KC_U, KC_I, KC_O, KC_P, KC_LBRC, KC_RBRC, KC_BSLS, KC_DEL, KC_END, KC_PGDN, KC_P7, KC_P8, KC_P9, KC_PPLS, 
 KC_CAPS, KC_A, KC_S, KC_D, KC_F, KC_G, KC_H, KC_J, KC_K, KC_L, KC_SCLN, KC_QUOT, KC_NUHS, KC_ENT, KC_P4, KC_P5, KC_P6, 
 KC_LSFT, KC_NUBS, KC_Z, KC_X, KC_C, KC_V, KC_B, KC_N, KC_M, KC_COMM, KC_DOT, KC_SLSH, KC_RSFT, KC_UP, KC_P1, KC_P2, KC_P3, KC_PENT, 
 KC_LCTL, KC_LGUI, KC_LALT, KC_SPC, KC_RALT, MO(1), KC_APP, KC_RCTL, KC_LEFT, KC_DOWN, KC_RGHT, KC_P0, KC_PDOT),

[_LAYER1] = LAYOUT_all(RESET, KC_MPLY, KC_MSTP, KC_MPRV, KC_MNXT, KC_MUTE, KC_VOLD, KC_VOLU, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, 
JC_ON, JC_OFF, JC_MIND, JC_MINU, JC_MAXD, JC_MAXU, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TGUI, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS) 

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