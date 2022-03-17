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

uint8_t wordMin = 2;
uint8_t wordMax = 15;
uint8_t SentenceMin = 2;
uint8_t SentenceMax = 15;
char val_to_write[20];

bool is_jcMacroActive = false;
bool isWaiting = false;
bool isClicking = false;

uint8_t rem_words = 10;
uint8_t rem_letters = 20;

uint32_t wait_time;
static uint32_t timer;


uint32_t randomRange(uint32_t lower, uint32_t upper)
{
    return (rand() % (upper - lower + 1)) + lower;
}

void housekeeping_task_kb(void)
{
    if(isWaiting)
    {
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
            wait_time = randomRange(3000, 65000);

            timer = timer_read32();
            isWaiting = true;
            rem_words = randomRange(2, 15);
            rem_letters = randomRange(wordMin,wordMax);
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

