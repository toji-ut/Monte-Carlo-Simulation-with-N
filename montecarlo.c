#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Function to simulate one experiment and return the count of empty boxes
int simulateOneExperiment(int N) {
    int boxes[N];
    for (int i = 0; i < N; i++) {
        boxes[i] = 0;  // Initialize boxes with 0 chips
    }
    
    int chips = N;

    // Number of chips to distribute
    while (chips > 0) {
        int box = rand() % N;  // Generate a random box number (0 to N-1)
        boxes[box]++;  // Place a chip in the selected box
        chips--;  // Decrement the number of chips
    }

    int emptyBoxes = 0;

    // Count the number of boxes with 0 chips
    for (int i = 0; i < N; i++) {
        if (boxes[i] == 0) {
            emptyBoxes++;
        }
    }

    return emptyBoxes;
}

int main() {
    srand(time(NULL));  // Seed the random number generator with current time

    int numSimulations = 100000;  // Number of Monte Carlo simulations
    int valuesOfN[] = {1, 100, 500, 1000, 1500, 2000, 2500, 3000};
    int numValues = sizeof(valuesOfN) / sizeof(valuesOfN[0]);

    // Run simulations for specific values of N
    for (int i = 0; i < numValues; i++) {
        int N = valuesOfN[i];
        double totalEmptyBoxes = 0;

        // Run the simulations
        for (int simulation = 0; simulation < numSimulations; simulation++) {
            int emptyBoxes = simulateOneExperiment(N);
            totalEmptyBoxes += emptyBoxes;
        }

        // Calculate the expected proportion of empty boxes
        double expectedProportion = totalEmptyBoxes / (numSimulations * N);

        // Print the results
        printf("N = %d, Expected Proportion of Empty Boxes: %.4f\n", N, expectedProportion);
    }

    return 0;
}



