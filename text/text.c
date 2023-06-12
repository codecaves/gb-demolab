#include <gb/gb.h>

#include "tileset.h"

#define PHRASE_LENGTH 8

const unsigned char phrase[] = {
    0x1d, 0x22, 0x1b, 0x2e, 0x2d, 0x2f, 0x1c, 0x29
};

void draw_phrase(uint8_t len) {
    SPRITES_8x8;
    uint8_t offset = 8;
    uint8_t sprite = 0;
    for (uint8_t i = 0; i < len; ++i) {
        set_sprite_data(0, TILESET_SIZE, tileset); // load the font spritesheet
        set_sprite_tile(sprite, phrase[i]);
        move_sprite(sprite, offset, 75);
        ++sprite;
        offset += 8;
    }
    SHOW_SPRITES;
}

void main(void) {

    DISPLAY_ON;
    draw_phrase(PHRASE_LENGTH);
    
    while(1) {
        delay(2000);
        __asm__("nop");
    }
}