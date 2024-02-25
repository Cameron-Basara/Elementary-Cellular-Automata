#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <math.h>

#include "ca1da.h"

//*************************************************************************************************************************************
//
// Used Help from https://www.codedrome.com/one-dimensional-cellular-automata-in-c/ -My reference for C knowledge and setup :P
// 
//
//*************************************************************************************************************************************

static void setRules(ca1d *ca);
static void cellState(ca1d *ca);


// Initialize cells
ca1d* ca_init(int cell_count, int gens, char *init_state, unsigned char rule, void(*printCell)(ca1d *ca)){
    ca1d *ca = malloc(sizeof(ca1d));

    if(ca != NULL){
        //initialize mem/vals to ca struct 
        *ca = (ca1d){
                .cells = malloc(sizeof(char)*cell_count),
                .cell_count = cell_count,
                .next_state = malloc(sizeof(char)*cell_count),
                .rule = rule,
                .gens = gens,
                .gen = 0,
                .printCell = printCell,
        };
        //Copy initial state to cells, feed old data to print
        if (ca->cells != NULL && ca->next_state != NULL){
            
            setRules(ca);

            for (int i = 0; i<ca->cell_count; i++){
                if (init_state[i] == '0'){
                    ca->cells[i] = '0';
                }
                else if (init_state[i] == '1'){
                    ca->cells[i] = '1';
                }
            }

            ca->printCell(ca);
            return ca;
        }
        //free ca 
        else{
            ca_free(ca);
            return NULL;
        }
    }
    else{
        return NULL;
    }
}


static void setRules(ca1d *ca){
    // Loop over each cell in the array
    for (int i = 0; i < ca->cell_count; i++) {
        // Determine the index of the left and right neighbors with wrap-around
        int leftIndex = (i - 1 + ca->cell_count) % ca->cell_count;
        int rightIndex = (i + 1) % ca->cell_count;

        // Extract the states of the left, current, and right cells
        int left = ca->cells[leftIndex] - '0';  // Convert char to int
        int self = ca->cells[i] - '0';          
        int right = ca->cells[rightIndex] - '0';

        // Combine the states to form a 3-bit pattern
        int pattern = (left << 2) | (self << 1) | right;

        // Use the pattern to extract the corresponding bit from the rule
        // The bit extracted determines the next state of the cell
        ca->next_state[i] = ((ca->rule >> pattern) & 1) + '0';  // ANDing with 1 will leave the bit as either only every a 1 or 0, and conversion back to char
    }
}

    

static void cellState(ca1d *ca){
     // Copy the next state of each cell to the current state
    for (int i = 0; i < ca->cell_count; i++) {
        ca->cells[i] = ca->next_state[i];
    }
}

void ca_start(ca1d *ca){
    // Run the simulation for the specified number of generations
    for (int gen = 0; gen < ca->gens; gen++) {
        // Apply the rules to determine the next state for each cell
        setRules(ca);

        // Update the current state of each cell to the next state
        cellState(ca);

        // If a print function is provided, use it to print the current state
        if (ca->printCell != NULL) {
            ca->printCell(ca);
        }

        // Optionally, delay between gens
        // printf("Generation %d\n", gen + 1);
        // getchar(); // Wait for user input to proceed to the next generation
    }
}

void ca_free(ca1d *ca){
    if (ca != NULL){
        if (ca->cells != NULL){
            free(ca->cells);
        }
        if (ca->next_state != NULL){
            free(ca->next_state);
        }
        free(ca);
    }
}