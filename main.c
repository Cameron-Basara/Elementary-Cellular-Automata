#include "ca1da.h" 
#include "cavisual.h" 

int main() {
    // Example initialization, adjust parameters as needed
    int cell_count = 200; // Number of cells
    int gens = 100; // Number of generations
    unsigned char rule = 30; // Rule for the cellular automaton
    char init_state[cell_count+1]; 
    memset(init_state, '0', cell_count); // Set all to '0'
    // Change initial state as desired
    init_state[cell_count / 2] = '1'; // Set middle cell to '1'
    init_state[cell_count] = '\0'; // Null-terminate the string




    // Initialize the cellular automaton
    ca1d *ca = ca_init(cell_count, gens, init_state, rule, print_cells);
    if (ca == NULL) {
        fprintf(stderr, "Failed to initialize cellular automaton\n");
        return 1;
    }

    // Start the cellular automaton simulation
    ca_start(ca);

    // Clean up
    ca_free(ca);

    return 0;
}
