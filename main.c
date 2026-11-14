#include <assert.h>
#include <stdio.h>

// wang tiles

// GWIDTH 4
// GCOUNT 16

//  0[0,0]  1[1,0]  2[2,0]  3[3,0]
//  4[0,1]  5[1,1]  6[2,1]  7[3,1]
//  8[0,2]  9[1,2] 10[2,2] 11[3,2]
// 12[0,3] 13[1,3] 14[2,3] 15[3,3]

// x = (int)a%GWIDTH
// y = (int)a/GWIDTH

struct tile {
    unsigned t : 1; // top
    unsigned r : 1; // right
    unsigned b : 1; // bottom
    unsigned l : 1; // left
};
typedef struct tile Tile;

#define GWIDTH 8
#define GCOUNT 64
Tile grid[GCOUNT] = {0};

Tile *tileat(unsigned x, unsigned y) {
    if (x >= GWIDTH || y*GWIDTH+x >= GCOUNT)
        return NULL;
    return &grid[y*GWIDTH+x];
}

int main(void) {
    assert(GCOUNT % GWIDTH == 0);

    grid[0].t = 1;

    printf("%d\n", grid[0].t);
    printf("%d\n", tileat(0, 7)->t);

    printf("Hello, World!");
    return 0;
}

