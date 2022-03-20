#include QMK_KEYBOARD_H


#define _LAYER0 0
#define _LAYER1 1

enum custom_keycodes {
    LAYER0 = SAFE_RANGE,
    LAYER1,
    JC_ON,
    JC_OFF,
    JC_MINWD,
    JC_MINWU,
    JC_MAXWD,
    JC_MAXWU,
    JC_MINSD,
    JC_MINSU,
    JC_MAXSD,
    JC_MAXSU,
    JC_MAXWAITU,
    JC_MAXWAITD,
    TEST
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
    [TD_F2_F14] = ACTION_TAP_DANCE_DOUBLE(KC_F2, KC_F14),
    [TD_F3_F15] = ACTION_TAP_DANCE_DOUBLE(KC_F3, KC_F15),
    [TD_F4_F16] = ACTION_TAP_DANCE_DOUBLE(KC_F4, KC_F16),
    [TD_F5_F17] = ACTION_TAP_DANCE_DOUBLE(KC_F5, KC_F17),
    [TD_F6_F18] = ACTION_TAP_DANCE_DOUBLE(KC_F6, KC_F18),
    [TD_F7_F19] = ACTION_TAP_DANCE_DOUBLE(KC_F7, KC_F19),
    [TD_F8_F20] = ACTION_TAP_DANCE_DOUBLE(KC_F8, KC_F20),
    [TD_F9_F21] = ACTION_TAP_DANCE_DOUBLE(KC_F9, KC_F21),
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
JC_ON, JC_OFF, JC_MINWD, JC_MINWU, JC_MAXWD, JC_MAXWU, JC_MINSD, JC_MINSU, JC_MAXSD, JC_MAXSU, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
TEST, JC_MAXWAITD, JC_MAXWAITU, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
KC_TRNS, KC_TGUI, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS)

};

uint8_t mode;

#define sentence 0
#define clicking 1
#define mouseMaxMove 10

uint8_t wordMin = 2;
uint8_t wordMax = 15;
uint8_t SentenceMin = 2;
uint8_t SentenceMax = 15;
char val_to_write[20];

bool is_jcMacroActive = false;
bool isWaiting = false;
bool isClicking = false;
bool isBigClick = false;

uint8_t rem_words = 10;
uint8_t rem_letters = 20;

uint32_t wait_time;
uint32_t wait_time_min = 5000;
uint32_t wait_time_max = 150000;
static uint32_t timer;

void MouseMoveLeftRight(void);
void MouseMoveUpDown(void);
void Clicking(void);

int randomRange(int lower, int upper)
{
    return (rand() % (upper - lower + 1)) + lower;
}

void wait(uint32_t waitTime)
{
    uint32_t startTime = timer_read32();
    while(timer_elapsed32(startTime) < waitTime)
    {

    }
}

void MouseSend(uint16_t keycode)
{
    register_code16(keycode);
    wait(50);
    unregister_code16(keycode);
    wait(50);
}

void MouseMoveLeftRight()
{
    MouseSend(KC_BTN1);
    int moveCount = randomRange(1, mouseMaxMove);
    for(uint8_t i; i<=moveCount;i++ )
    {
        MouseSend(KC_MS_LEFT);
    }
    MouseSend(KC_BTN1);
     for(uint8_t i; i<=moveCount;i++ )
    {
        MouseSend(KC_MS_RIGHT);
    }
    MouseSend(KC_BTN1);
}


void MouseMoveUpDown()
{
    int moveCount = randomRange(1, mouseMaxMove);
    for(uint8_t i; i<=moveCount;i++ )
    {
        MouseSend(KC_MS_UP);
    }
     for(uint8_t i; i<=moveCount;i++ )
    {
        MouseSend(KC_MS_DOWN);
    }
}

void Clicking()
{
 int randomMoveNumber = randomRange(10, 40);
                for(int i=0;i<randomMoveNumber;i++)
                {
                    if(randomRange(0,1)==1)
                    {
                        MouseMoveUpDown();
                    }else
                    {
                        MouseMoveLeftRight();
                    }
                    wait(randomRange(200, 1500));
                }
                SEND_STRING("c d ");

}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case TEST:
            if (record->event.pressed) {
                Clicking();
            }
        break;

        case JC_ON:
            if (record->event.pressed) {
                is_jcMacroActive = true;
                SEND_STRING("JON");
            }
        break;

        case JC_MINWU:
            if (record->event.pressed && wordMin+1<wordMax) {
                wordMin++;
                SEND_STRING("JWMI: ");
                SEND_STRING( itoa(wordMin, val_to_write, 10));
            }
        break;

        case JC_MINWD:
            if (record->event.pressed && wordMin>1) {
                wordMin--;
                SEND_STRING("JWMI:");
                SEND_STRING( itoa(wordMin, val_to_write, 10));
            }
        break;

          case JC_MAXWU:
            if (record->event.pressed) {
                wordMax++;
                SEND_STRING("JWMA:");
                SEND_STRING( itoa(wordMax, val_to_write, 10));
            }
        break;

        case JC_MAXWD:
            if (record->event.pressed && wordMax>wordMin+2) {
                wordMax--;
                SEND_STRING("JWMA: ");
                SEND_STRING( itoa(wordMax, val_to_write, 10));
            }
        break;
          case JC_MINSU:
            if (record->event.pressed && SentenceMin+1<SentenceMax) {
                SentenceMin++;
                SEND_STRING("JSMI: ");
                SEND_STRING( itoa(SentenceMin, val_to_write, 10));
            }
        break;

        case JC_MINSD:
            if (record->event.pressed && SentenceMin>1) {
                SentenceMin--;
                SEND_STRING("JSMI:");
                SEND_STRING( itoa(SentenceMin, val_to_write, 10));
            }
        break;

          case JC_MAXSU:
            if (record->event.pressed) {
                SentenceMax++;
                SEND_STRING("JSMA:");
                SEND_STRING( itoa(SentenceMax, val_to_write, 10));
            }
        break;

        case JC_MAXSD:
            if (record->event.pressed && SentenceMax>SentenceMin+2) {
                SentenceMax--;
                SEND_STRING("JSMA: ");
                SEND_STRING( itoa(SentenceMax, val_to_write, 10));
            }
        break;

         case JC_MAXWAITU:
            if (record->event.pressed) {
                wait_time_max+=5000;
                SEND_STRING("JWAIT: ");
                SEND_STRING( itoa(wait_time_max, val_to_write, 10));
            }
        break;

        case JC_OFF:
        if(record-> event.pressed)
        {
            is_jcMacroActive = false;
            SEND_STRING("JOFF");
        }
        break;
    }

    return true;
}

void housekeeping_task_kb(void)
{
     if(is_jcMacroActive)
    {

        if(isWaiting){
            if(timer_elapsed32(timer) < wait_time)
            {
                return;
            }
            isWaiting = false;
            if(isClicking)
            {
                unregister_code16(KC_BTN1);
                isClicking = false;
            }
            return;
	    }
        if(rem_words == 0 && rem_letters ==0)
        {
            //szekvencia vége
            wait_time = randomRange(wait_time_min, wait_time_max);
            SEND_STRING( itoa(wait_time/1000, val_to_write, 10));
            timer = timer_read32();
            isWaiting = true;
            rem_words = randomRange(2, 15);
            rem_letters = randomRange(wordMin,wordMax);
            if(randomRange(0, 1)==1)
            {
                Clicking();
            }
            return;
        }

        if(rem_letters ==0)
        {
            //szó vége
            SEND_STRING(" ");
            wait_time = randomRange(100, 1500);
            timer = timer_read32();
            isWaiting = true;
            rem_letters = randomRange(wordMin,wordMax);
            rem_words--;

            if(randomRange(0, 5)% 5 == 2)
            {
                isClicking = true;
                isWaiting = true;
                wait_time = randomRange(20, 50);
                timer = timer_read32();
                SEND_STRING("cli");
                register_code16(KC_BTN1);
            }
            return;

        }
        else
        {
            //betü küldése
            tap_random_base64();
            wait_time = randomRange(30, 1000);
            isWaiting = true;
            timer = timer_read32();
            rem_letters--;

        }
    }
}
