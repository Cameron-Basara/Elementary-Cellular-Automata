#include "cavisual.h"
#include <stdio.h>

void print_cells(ca1d *ca) {
    for (int i = 0; i < ca->cell_count; i++) {
        // Print a filled character for '1', space for '0'
        printf("%c", ca->cells[i] == '1' ? '#' : '.');
    }
    printf("\n"); // Move to the next line after printing the current generation
}