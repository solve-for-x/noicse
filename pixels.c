#include <stdlib.h>
#include <stdint.h>
#include <time.h>

#define WIDTH 800
#define HEIGHT 600 

static uint8_t* pixel_buffer = NULL;

// Produces a new seed to generate a new random image on every page refresh
void seed_rng(unsigned int seed) {
    srand(seed);
}

uint8_t* generate_image_data() {
    if (!pixel_buffer) {
        pixel_buffer = malloc(WIDTH * HEIGHT * 4);
        if (!pixel_buffer) return NULL; 
    }

    for (int i = 0; i < WIDTH * HEIGHT * 4; i++) {
        int offset = i * 4;
        pixel_buffer[offset] = rand() % 256;        // R
        pixel_buffer[offset + 1] = rand() % 256;    // G
        pixel_buffer[offset + 2] = rand() % 256;    // B
        pixel_buffer[offset + 3] = 255;             // A
    }

    return pixel_buffer;
}
