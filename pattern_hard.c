#include <stdio.h>

// Helper function to find the minimum of two numbers
int min(int a, int b) {
    return (a < b) ? a : b;
}

int main() {
    int n = 7; // The maximum number for the pattern
    int size = 2 * n - 1; // Total rows and columns (7 for n = 4)

    // Outer loop for rows
    for (int i = 0; i < size; i++) {
        // Inner loop for columns
        for (int j = 0; j < size; j++) {
            
            // Calculate distances to the four borders
            int from_top = i;
            int from_bottom = size - 1 - i;
            int from_left = j;
            int from_right = size - 1 - j;
            
            // Find the absolute minimum distance to any border
            int min_dist = min(min(from_top, from_bottom), min(from_left, from_right));
            
            // Print the value followed by a single space
            printf("%d ", n - min_dist);
        }
        // Move to the next line after completing a row
        printf("\n");
    }

    return 0;
}