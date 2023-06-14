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

/*
    draw_text
    Draw text into the background layer by writing bytes to specific locations in VRAM
*/
void draw_text(const char *text, uint8_t max_len) {
    uint8_t xc = 0;
    uint8_t yc = 8;
    uint8_t i = 0;

    set_bkg_data(0, TILESET_SIZE, tileset); // Load the tileset as BKG data
    init_bkg(0);

    for (const char *ch = text; i < max_len; ++ch, ++i) {
        uint8_t ord = 0; // This will be a blank tile

        if ((uint8_t) *ch >= 65 && (uint8_t) *ch <= 90) {
            ord = ((uint8_t) *ch) - 64;
        } else if ((uint8_t) *ch >= 97 && (uint8_t) *ch <= 122) {
            ord = ((uint8_t) *ch) - 70;
        } else {
            // We can only draw A-Za-z0-9 right now, so we want to leave it blank here.
        }

        // Set and place the tile in VRAM
        uint8_t *vram_origin = get_bkg_xy_addr(xc, yc);
        set_vram_byte(vram_origin, ord);
        ++xc;

        SHOW_BKG;
    }
}

void main(void) {

    DISPLAY_ON;
    //draw_phrase(PHRASE_LENGTH);
    
    const char *greeting = "Hello world ABCDEFGH";
    uint8_t len = strlen(greeting);
    draw_text(greeting, len);
    
}