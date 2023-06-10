#include <gb/gb.h>
#include <stdint.h>
#include <stdio.h>

#include "input.h"

void handle_input(uint8_t keymask) {
    switch (keymask) {
    case J_A:
        printf("%s\n", KEYMSG_A_BUTTON);
        delay(100);
        break;
    case J_B:
        printf("%s\n", KEYMSG_B_BUTTON);
        delay(100);
        break;
    case J_UP:
        printf("%s\n", KEYMSG_UP_BUTTON);
        delay(100);
        break;
    case J_DOWN:
        printf("%s\n", KEYMSG_DOWN_BUTTON);
        delay(100);
        break;
    case J_LEFT:
        printf("%s\n", KEYMSG_LEFT_BUTTON);
        delay(100);
        break;
    case J_RIGHT:
        printf("%s\n", KEYMSG_RIGHT_BUTTON);
        delay(100);
        break;
    case J_SELECT:
        printf("%s\n", KEYMSG_SELECT_BUTTON);
        delay(100);
        break;
    case J_START:
        printf("%s\n", KEYMSG_START_BUTTON);
        delay(100);
        break;
    default:
        break;
    }
}

void main(void) {
    while (1) {
        uint8_t keymask = joypad();
        handle_input(keymask);
    }
}