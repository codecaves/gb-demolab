#include <gb/gb.h>
#include <stdio.h>
#include <string.h>

#include "tileset.h"

#define PHRASE_LENGTH 8

/*
    These are the sprite locations according to BGB VRAM viewer.
*/
const unsigned char phrase[] = {
    0x1d, 0x22, 0x1b, 0x2e, 0x2d, 0x2f, 0x1c, 0x29
};

/*
    draw_phrase
    Draws a hard-coded phrase from an array of sprite locations defined by phrase[].
*/
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

void draw_text(const char *text, uint8_t max_len) {
    SPRITES_8x8;
    uint8_t offset_x = 16;
    uint8_t offset_y = 75;
    uint8_t sprite = 0;
    uint8_t i = 0;
    for (const char *ch = text; i < max_len; ++ch, ++i) {
        uint8_t ord = 0; // This will be a blank tile

        if ((uint8_t) *ch >= 65 && (uint8_t) *ch <= 90) {
            ord = ((uint8_t) *ch) - 64;
        } else if ((uint8_t) *ch >= 97 && (uint8_t) *ch <= 122) {
            ord = ((uint8_t) *ch) - 70;
        } else {
            // We can only draw A-Za-z0-9 right now, so we want to leave it blank here.
        }

        // Set and place the tile
        set_sprite_data(0, TILESET_SIZE, tileset);
        set_sprite_tile(sprite, ord);
        move_sprite(sprite, offset_x, offset_y);
        ++sprite;
        offset_x += 8;

        // Handle scanline limitation by doing a kind of carriage return.
        if (sprite % 9 == 0) {
            offset_x = 16;
            offset_y += 8;
        }

        SHOW_SPRITES;
    }
}

void main(void) {

    DISPLAY_ON;
    //draw_phrase(PHRASE_LENGTH);
    
    const char *greeting = "This is a test";
    uint8_t len = strlen(greeting);
    //draw_text(greeting, len);

}