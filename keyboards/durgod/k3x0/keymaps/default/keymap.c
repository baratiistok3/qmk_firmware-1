#include QMK_KEYBOARD_H


#define _LAYER0 0
#define _LAYER1 1

enum custom_keycodes {
    LAYER0 = SAFE_RANGE,
    LAYER1,
    JC_ON,
    JC_OFF,
    JC_MINWD,    //jc min word letter count --
    JC_MINWU,    //jc min word letter count ++
    JC_MAXWD,    //jc max word letter count --
    JC_MAXWU,    //jc max word letter count ++
    JC_MINSD,    //jc min sentence word count --
    JC_MINSU,    //jc min sentence word count ++
    JC_MAXSD,    //jc max sentence word count --
    JC_MAXSU,    //jc max sentence word count ++
    JC_MAXWAITU,
    JC_MAXWAITD,
    JC_MINWAITU,
    JC_MINWAITD,
    JC_RATIOU,
    JC_RATIOD,
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

 [_LAYER0] = LAYOUT_all(KC_ESC, KC_F1, KC_F2, KC_F3, KC_F4, KC_F5, KC_F6, KC_F7, KC_F8, KC_F9, KC_F10, KC_F11, KC_F12, KC_PSCR, KC_SLCK, KC_PAUS,
 KC_GRV, KC_1, KC_2, KC_3,  KC_4, KC_5, KC_6, KC_7, KC_8, KC_9, KC_0, KC_MINS, KC_EQL, KC_BSPC, KC_INS, KC_HOME, KC_PGUP, KC_NLCK, KC_PSLS, KC_PAST, KC_PMNS,
 KC_TAB, KC_Q, KC_W, KC_E, KC_R, KC_T, KC_Y, KC_U, KC_I, KC_O, KC_P, KC_LBRC, KC_RBRC, KC_BSLS, KC_DEL, KC_END, KC_PGDN, KC_P7, KC_P8, KC_P9, KC_PPLS,
 KC_CAPS, KC_A, KC_S, KC_D, KC_F, KC_G, KC_H, KC_J, KC_K, KC_L, KC_SCLN, KC_QUOT, KC_NUHS, KC_ENT, KC_P4, KC_P5, KC_P6,
 KC_LSFT, KC_NUBS, KC_Z, KC_X, KC_C, KC_V, KC_B, KC_N, KC_M, KC_COMM, KC_DOT, KC_SLSH, KC_RSFT, KC_UP, KC_P1, KC_P2, KC_P3, KC_PENT,
 KC_LCTL, KC_LGUI, KC_LALT, KC_SPC, KC_RALT, MO(1), KC_APP, KC_RCTL, KC_LEFT, KC_DOWN, KC_RGHT, KC_P0, KC_PDOT),

[_LAYER1] = LAYOUT_all(RESET, KC_MPLY, KC_MSTP, KC_MPRV, KC_MNXT, KC_MUTE, KC_VOLD, KC_VOLU, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
JC_ON, JC_OFF, JC_MINWD, JC_MINWU, JC_MAXWD, JC_MAXWU, JC_MINSD, JC_MINSU, JC_MAXSD, JC_MAXSU, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
TEST, JC_RATIOD, JC_RATIOU, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
KC_TRNS, KC_TGUI, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS)

};

uint8_t mode;

#define sentence 0
#define clicking 1
#define mouseMaxMove 10

uint8_t wordMinLetters = 2;
uint8_t wordMaxLetters = 8;
uint8_t SentenceMin = 2;
uint8_t SentenceMax = 8;
uint8_t clickMin = 2;
uint8_t clickMax = 30;
uint8_t clickSentenceRatio = 7;
char val_to_write[20];

bool is_jcMacroActive = false;
bool isWaiting = false;
bool isClicking = false;
bool isBigClick = false;

uint8_t rem_words = 10;
uint8_t rem_letters = 20;
uint8_t rem_clicks = 0;

uint32_t wait_time;
uint32_t waitTimeMinSentence = 5*1000;
uint32_t waitTimeMaxSentence = 110*1000;
uint32_t waitTimeMinClick = 5*1000;
uint32_t waitTimeMaxClick = 15*1000;

static uint32_t timer;

void MouseMoveLeftRight(void);
void MouseMoveUpDown(void);
void Clicking(void);
void LogClickSentenceRatio(void);

void LogClickSentenceRatio()
{
    switch(clickSentenceRatio)
    {
        case 0:
            SEND_STRING("R0");
            break;
        case 1:
            SEND_STRING("R1");
            break;
        case 2:
            SEND_STRING("R2");
            break;
        case 3:
            SEND_STRING("R3");
            break;
        case 4:
            SEND_STRING("R4");
            break;
        case 5:
            SEND_STRING("R5");
            break;
        case 6:
            SEND_STRING("R6");
            break;
        case 7:
            SEND_STRING("R7");
            break;
        case 8:
            SEND_STRING("R8");
            break;
        case 9:
            SEND_STRING("R9");
            break;
        case 10:
            SEND_STRING("R10");
            break;
    }
}

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
    switch(keycode)
    {
        case KC_MS_UP ... KC_MS_DOWN:
            wait(500);
        break;
        default:
            wait(50);
        break;
    }

    unregister_code16(keycode);
    wait(50);
}

void MouseMoveLeftRight()
{
    int moveCount = randomRange(1, mouseMaxMove);
    for(uint8_t i; i<=moveCount;i++ )
    {
        MouseSend(KC_MS_LEFT);
    }

     for(uint8_t i; i<=moveCount;i++ )
    {
        MouseSend(KC_MS_RIGHT);
    }
}

void SetWaitTimer (int ms)
{
    wait_time = ms;
    timer = timer_read32();
    isWaiting = true;

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
        case JC_ON:
            if (record->event.pressed) {
                is_jcMacroActive = true;
                SEND_STRING("JON");
            }
        break;

        case JC_MINWU:
            if (record->event.pressed && wordMinLetters+1<wordMaxLetters) {
                wordMinLetters++;
                SEND_STRING("JWMI: ");
                SEND_STRING( itoa(wordMinLetters, val_to_write, 10));
            }
        break;

        case JC_MINWD:
            if (record->event.pressed && wordMinLetters>1) {
                wordMinLetters--;
                SEND_STRING("JWMI:");
                SEND_STRING( itoa(wordMinLetters, val_to_write, 10));
            }
        break;

          case JC_MAXWU:
            if (record->event.pressed) {
                wordMaxLetters++;
                SEND_STRING("JWMA:");
                SEND_STRING( itoa(wordMaxLetters, val_to_write, 10));
            }
        break;

        case JC_MAXWD:
            if (record->event.pressed && wordMaxLetters>wordMinLetters+2) {
                wordMaxLetters--;
                SEND_STRING("JWMA: ");
                SEND_STRING( itoa(wordMaxLetters, val_to_write, 10));
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
                waitTimeMaxSentence+=5000;

                SEND_STRING("JWAIT: ");
                SEND_STRING( itoa(waitTimeMaxSentence, val_to_write, 10));

            }
        break;

        case JC_RATIOD:
            if (record->event.pressed && clickSentenceRatio>0) {
                clickSentenceRatio--;
                LogClickSentenceRatio();
            }
        break;

        case JC_RATIOU:
            if (record->event.pressed && clickSentenceRatio<10) {
                clickSentenceRatio++;
                LogClickSentenceRatio();
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

        //szekvencia vége van
        if(rem_words == 0 && rem_letters == 0 && rem_clicks == 0)
        {
            //click lesz a beallitott aranyban
            //r7 => 70% click
            if(randomRange(0, 10)%10<clickSentenceRatio)
            {
                //click szekvencia jön
                rem_clicks = randomRange(clickMin, clickMax);
                rem_words = 0;
                rem_letters = 0;
                SEND_STRING("cl");
                SetWaitTimer(randomRange(clickMin, clickMax));
            }else
            {
                //mondat szekvencia jön
                rem_words = randomRange(SentenceMin, SentenceMax);
                rem_letters = randomRange(wordMinLetters,wordMaxLetters);
                rem_clicks = 0;
                SEND_STRING("se");
                SetWaitTimer(randomRange(waitTimeMinSentence, waitTimeMaxSentence));
            }



            SEND_STRING( itoa(wait_time/1000, val_to_write, 10));
            return;
        }

        if(rem_clicks != 0)
        {
            //clickelő fázis van
            rem_clicks--;
            MouseSend(KC_MS_WH_UP);
            wait(randomRange(100, 1000));
            MouseSend(KC_MS_WH_DOWN);
            // if(randomRange(0, 1)%1==1)
            // {
            //     MouseMoveUpDown();

            //     return;
            // }
            // MouseMoveLeftRight();
            // return;
            return;
        }

        if(rem_letters == 0)
        {
            //szó vége
            SEND_STRING(" ");
            SetWaitTimer(randomRange(100, 1500));
            rem_letters = randomRange(wordMinLetters,wordMaxLetters);
            rem_words--;
        }
        else
        {
            //betü küldése
            tap_random_base64();
            SetWaitTimer(randomRange(30, 1000));
            rem_letters--;
        }
    }
}
