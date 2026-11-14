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

#define GCOUNT 16
#define GWIDTH 4
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
    DrawCircleV(tl, 3, RED);
    DrawCircleV(tr, 3, GREEN);
    DrawCircleV(bl, 3, BLUE);
    DrawCircleV(br, 3, YELLOW);
    DrawCircleV(center, 3, WHITE);
}

int main(void) {
    assert(GCOUNT % GWIDTH == 0);

    grid[0].t = 0;
    grid[0].r = 1;
    grid[0].b = 2;
    grid[0].l = 3;

    InitWindow(GWIDTH*TPIXELSCALE, GHEIGHT*TPIXELSCALE, "wang tiles");

    while (!WindowShouldClose()) {
        BeginDrawing();
        ClearBackground(BLACK);
        drawtiletoscreenpos(&grid[0], 25, 25);
        EndDrawing();
    }

    CloseWindow();
    return 0;
}

