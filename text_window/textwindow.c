#include <gb/gb.h>
#include <stdio.h>
#include <string.h>

#include "tileset.h"
#include "text_tiles.h"

#define BOTTOM_AREA 112

/*
    draw_screen
    Draw a background with a window overlayed in the bottom forth of the screen.
*/
void draw_screen() {
    set_bkg_data(1, TILESET_SIZE, tileset);
    set_win_data(0, TEXT_TILES_SIZE, text_tiles); // This will overwrite the first few BG tiles because
                                                  // I'm not using a single tileset and they occupy the
                                                  // same VRAM on the GameBoy

    init_bkg(0x3f); // 0
    
    set_win_tiles(0, 0, TEXT_MAP_WIDTH, TEXT_MAP_HEIGHT, text_map);
    uint8_t *win_vram_origin = get_win_xy_addr(1, 1);
    uint8_t *win_vram_bottom = get_win_xy_addr(1, 2);

    // Hello world
    set_vram_byte(win_vram_origin+0, 0x09);
    set_vram_byte(win_vram_origin+1, 0x20);
    set_vram_byte(win_vram_origin+2, 0x27);
    set_vram_byte(win_vram_origin+3, 0x27);
    set_vram_byte(win_vram_origin+4, 0x2a);
    set_vram_byte(win_vram_origin+5, 0x00);
    set_vram_byte(win_vram_origin+6, 0x32);
    set_vram_byte(win_vram_origin+7, 0x2a);
    set_vram_byte(win_vram_origin+8, 0x2d);
    set_vram_byte(win_vram_origin+9, 0x27);
    set_vram_byte(win_vram_origin+10, 0x1f);

    // 1234567890
    for (uint8_t i = 0, base = 0x36; i < 10; ++i) {
        set_vram_byte(win_vram_bottom + i, base + i);
    }

    // Shift the window to the bottom of the screen so it doesn't
    // cover the background layer completely
    move_win(7, BOTTOM_AREA);

    SHOW_BKG;
    SHOW_WIN;
}

void main(void) {

    draw_screen();

    DISPLAY_ON;

    while(1) {
        scroll_bkg(1, -1);
        wait_vbl_done();
    }
    
}