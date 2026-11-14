#include <assert.h>
#include <raylib.h>
#include <stdio.h>

// wang tiles

struct tile {
    unsigned t; // top
    unsigned r; // right
    unsigned b; // bottom
    unsigned l; // left
};
typedef struct tile Tile;

#define TPIXELSCALE 100
#define COLORSCOUNT 5
Color colors[COLORSCOUNT] = {
    BLUE,
    YELLOW,
    ORANGE,
    GREEN,
    PURPLE,
};

#define GCOUNT 64
#define GWIDTH 8
#define GHEIGHT GCOUNT/GWIDTH
Tile grid[GCOUNT] = {0};

Tile *tileat(unsigned x, unsigned y) {
    if (x >= GWIDTH || y*GWIDTH+x >= GCOUNT)
        return NULL;
    return &grid[y*GWIDTH+x];
}

void drawtiletoscreenpos(Tile *ptr, unsigned x, unsigned y) {
    Vector2 tl, tr, bl, br, center;
    tl = tr = bl = br = (Vector2){x, y};
    tr.x += TPIXELSCALE;
    br.x += TPIXELSCALE;
    bl.y += TPIXELSCALE;
    br.y += TPIXELSCALE;
    center = (Vector2){x+TPIXELSCALE/2, y+TPIXELSCALE/2};

    DrawTriangle(center, tr, tl, colors[ptr->t]);
    DrawTriangle(center, br, tr, colors[ptr->r]);
    DrawTriangle(center, bl, br, colors[ptr->b]);
    DrawTriangle(center, tl, bl, colors[ptr->l]);
}

void drawgrid(void) {
    for (int y = 0; y < GHEIGHT; y++) {
        for (int x = 0; x < GWIDTH; x++) {
            drawtiletoscreenpos(tileat(x, y), x*TPIXELSCALE, y*TPIXELSCALE);
        }
    }
}

void randomizegridfully(void) {
    for (int y = 0; y < GHEIGHT; y++) {
        for (int x = 0; x < GWIDTH; x++) {
            tileat(x, y)->t = GetRandomValue(0, COLORSCOUNT-1);
            tileat(x, y)->r = GetRandomValue(0, COLORSCOUNT-1);
            tileat(x, y)->b = GetRandomValue(0, COLORSCOUNT-1);
            tileat(x, y)->l = GetRandomValue(0, COLORSCOUNT-1);
        }
    }
}

int main(void) {
    assert(GCOUNT % GWIDTH == 0);
    randomizegridfully();

    InitWindow(GWIDTH*TPIXELSCALE, GHEIGHT*TPIXELSCALE, "wang tiles");

    while (!WindowShouldClose()) {
        if (IsKeyPressed(KEY_SPACE)) {
            randomizegridfully();
        }

        BeginDrawing();
        ClearBackground(BLACK);
        drawgrid();
        EndDrawing();
    }

    CloseWindow();
    return 0;
}

