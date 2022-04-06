#include QMK_KEYBOARD_H

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    /*
     * ┌───┐
     * │ A │
     * └───┘
     */
    [0] = LAYOUT_ortho_4x4(
         KC_P7,   KC_P8,   KC_P9,   KC_PSLS,
        KC_P4,   KC_P5,   KC_P6,   KC_PAST,
        KC_P1,   KC_P2,   KC_P3,   KC_PMNS,
        KC_P0,   KC_PDOT, KC_PENT, KC_PPLS
    )
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
uint32_t waitTimeMaxSentence = 30*1000;
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
 uint8_t waitingCount = 5;

void SetWaitTimer (int ms)
{
    wait_time = ms;
    timer = timer_read32();
    isWaiting = true;

}

void housekeeping_task_kb(void)
{
    if(is_jcMacroActive)
    {
        if(isWaiting){
            if(timer_elapsed32(timer) < wait_time)
            {
                //még nem telt le a timer
                return;
            }
            //timer lejárt rész
            waitingCount--;
            SetWaitTimer(wait_time);
            if(waitingCount == 0)
            {
                isWaiting = false;
                waitingCount = 5;
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
            return;
        }

        if(rem_clicks != 0)
        {
            //clickelő fázis van
            rem_clicks--;
            MouseSend(KC_MS_WH_UP);
            wait(randomRange(100, 1000));
            MouseSend(KC_MS_WH_DOWN);

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


bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case KC_P7:
            if (record->event.pressed) {
                is_jcMacroActive = true;
                SEND_STRING("JON");
            }
        break;

    

        case KC_P5:
            if (record->event.pressed && clickSentenceRatio>0) {
                clickSentenceRatio--;
                LogClickSentenceRatio();
            }
        break;

        case KC_P3:
            if (record->event.pressed && clickSentenceRatio<10) {
                clickSentenceRatio++;
                LogClickSentenceRatio();
            }
        break;

        case KC_PPLS:
        if(record-> event.pressed)
        {
            is_jcMacroActive = false;
            SEND_STRING("JOFF");
        }
        break;
    }

    return true;
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