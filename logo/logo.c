#include <gb/gb.h>

#include "tileset.h"

void main(void) {
    set_bkg_data(0, 10, tileset);

    init_bkg(2);

    SHOW_BKG;
    DISPLAY_ON;
}