#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Comparator function for qsort
int compare(const void* a, const void* b) {
    char *s1 = *(char**)a;
    char *s2 = *(char**)b;

    // Repeat the strings to make them longer for comparison
    char str1[110], str2[110];
    strcpy(str1, "");
    strcpy(str2, "");
    for (int i = 0; i < 10; i++) {
        strcat(str1, s1);
        strcat(str2, s2);
    }

    // Compare the extended strings in reverse order
    return strcmp(str2, str1);
}

// Function to generate the largest number
char* largestNumber(int* nums, int numsSize) {
    // Allocate memory for string representations
    char** nums_str = (char**)malloc(numsSize * sizeof(char*));
    int totalLength = 0;
    for (int i = 0; i < numsSize; i++) {
        nums_str[i] = (char*)malloc(12 * sizeof(char)); // Max length for int
        sprintf(nums_str[i], "%d", nums[i]);
        totalLength += strlen(nums_str[i]);
    }

    // Sort the array using the custom comparator
    qsort(nums_str, numsSize, sizeof(char*), compare);

    // Handle the edge case where the largest number is '0'
    if (strcmp(nums_str[0], "0") == 0) {
        char* result = (char*)malloc(2 * sizeof(char));
        strcpy(result, "0");
        // Free allocated memory
        for (int i = 0; i < numsSize; i++) {
            free(nums_str[i]);
        }
        free(nums_str);
        return result;
    }

    // Concatenate the numbers to form the largest number
    char* result = (char*)malloc((totalLength + 1) * sizeof(char));
    result[0] = '\0';
    for (int i = 0; i < numsSize; i++) {
        strcat(result, nums_str[i]);
        free(nums_str[i]);
    }
    free(nums_str);

    return result;
}

// Test cases
int main() {
    // Test Case 1
    int nums1[] = {10, 2};
    int size1 = sizeof(nums1) / sizeof(nums1[0]);
    char* res1 = largestNumber(nums1, size1);
    printf("Input: [10, 2]\n");
    printf("Largest Number: %s\n\n", res1);
    free(res1);

    // Test Case 2
    int nums2[] = {3, 30, 34, 5, 9};
    int size2 = sizeof(nums2) / sizeof(nums2[0]);
    char* res2 = largestNumber(nums2, size2);
    printf("Input: [3, 30, 34, 5, 9]\n");
    printf("Largest Number: %s\n\n", res2);
    free(res2);

    return 0;
}