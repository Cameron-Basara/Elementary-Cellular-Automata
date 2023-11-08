#include <stdio.h>
#include <stdlib.h>

//Struct Declaration

typedef struct cellularAutomata{
        char *cells; // declare cells
        int cell_count; // declare quantity of cells 
        char *next_state; // next state
        unsigned char rule; // declaring rule
        int gen; // generation we are at
        int gens; //how many iterations we have done
        char rule_bytes[9]; //rule bytes
        void (*printCell)(ca1d *ca);
        
} ca1d;

//Function Prototypes
ca1d* ca_init(int cell_count, int gens, char *init_state, unsigned char rule, void(*printCell)(ca1d *ca));
void ca_start(ca1d *ca);
void ca_free(ca1d *ca);

