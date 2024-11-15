#include <stdio.h>
#include <stdlib.h>

int* getRow(int rowIndex, int* returnSize) {
    *returnSize = rowIndex + 1;
    int* row = (int*)malloc((*returnSize) * sizeof(int));

    // Initialize the row array with 1s
    for (int i = 0; i <= rowIndex; i++) {
        row[i] = 1;
    }

    for (int i = 2; i <= rowIndex; i++) { // Starting from index 2, as 0 and 1 are base cases
        for (int j = i - 1; j > 0; j--) { // Update values from the end towards the beginning
            row[j] += row[j - 1];
        }
    }

    return row;
}

int main() {
    int rowIndex = 3; // Example rowIndex
    int returnSize;
    int* row = getRow(rowIndex, &returnSize);

    // Print the row
    for (int i = 0; i < returnSize; i++) {
        printf("%d ", row[i]);
    }
    printf("\n");

    // Free allocated memory
    free(row);

    return 0;
}
