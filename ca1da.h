#ifndef CA1DA_H
#define CA1DA_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//Struct Declaration
typedef struct cellularAutomata {
    char *cells; // Current state of cells
    int cell_count; // Number of cells
    char *next_state; // Next state of cells after applying the rule
    unsigned char rule; // Rule for cell state transitions
    int gens; // Total number of generations to simulate
    int gen; // Current generation
    void (*printCell)(struct cellularAutomata *ca); // Function pointer for printing cells
} ca1d;

//Function Prototypes
ca1d* ca_init(int cell_count, int gens, char *init_state, unsigned char rule, void(*printCell)(ca1d *ca));
void ca_start(ca1d *ca);
void ca_free(ca1d *ca);

#endif // CA1D_H

