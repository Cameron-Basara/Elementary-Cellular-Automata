#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <math.h>

#include "ca1da.h"

//*************************************************************************************************************************************
//
// Used Help from https://www.codedrome.com/one-dimensional-cellular-automata-in-c/ -My reference for C knowledge and setup :P
// Full Disclosure: This is the least optimized code you will ever have the misfortune of reading
//
//*************************************************************************************************************************************

static void setRules(ca1d *ca);
static void cellState(ca1d *ca);

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
                .rule_bytes = "",
                .printCell = printCell,
        };
        //Copy initial state to cells, feed old data to print
        if (ca->cells != NULL && ca->next_state != NULL){
            
            setRules(ca);

            for (int i; i<ca->cell_count; i++){
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
    // Set all the possible outcomes for next state
    char neighbourhood[4];

    for (int i = 0; i < strlen(ca->cells); i++){
        //setting the neighbourhood
        neighbourhood[1] = ca->cells[i];
        neighbourhood[3] = '\0';
        
        if (ca->cells[i-1] == '0' || ca->cells[i-1] == '1'){
            neighbourhood[0] = ca->cells[i-1];
        }
        else if (ca->cells[i-1] != '0' || ca->cells[i-1] != '1'){
            neighbourhood[0] = ca->cells[strlen(ca->cells)-1];
        }
        else if (ca->cells[i+1] == '0' || ca->cells[i+1] == '1'){
            neighbourhood[2] = ca->cells[i-1];
        }
        else if (ca->cells[i+1] != '0' || ca->cells[i+1] != '1'){
            neighbourhood[2] = ca->cells[0];
        }

        // Rule 30 
        for (int j = 0; j < strlen(ca->cells); j++){
            if (neighbourhood[0] == '0'){
                if (neighbourhood[1] == '0'){
                    if (neighbourhood[2] == '0'){
                        ca->rule = '0';
                    }
                    else if (neighbourhood[2] == '1'){
                        ca->rule = '1';
                    }
                }
                else if (neighbourhood[1] == '1'){
                    if (neighbourhood[2] == '0'){
                        ca->rule = '1';
                    }
                    else if (neighbourhood[2] == '1'){
                        ca->rule = '1';
                    }
                }
            }
            else if (neighbourhood[0] == '1'){
                if (neighbourhood[1] == '0'){
                    if (neighbourhood[2] == '0'){
                        ca->rule = '1';
                    }
                    else if (neighbourhood[2] == '1'){
                        ca->rule = '0';
                    }
                }
                else if (neighbourhood[1] == '1'){
                    if (neighbourhood[2] == '0'){
                        ca->rule = '0';
                    }
                    else if (neighbourhood[2] == '1'){
                        ca->rule = '0';
                    }
                }
            }
            ca->next_state[j] = ca->rule;
        }  
    }
}
    
    

static void cellState(ca1d *ca){
    for (int i = 0; i < strlen(ca->cells); i++){
            
        }
}

void ca_start(ca1d *ca){

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