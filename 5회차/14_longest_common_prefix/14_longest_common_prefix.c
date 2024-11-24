#include <stdio.h>
#include <string.h>

// Function to find the longest common prefix
char* longest_common_prefix(char** strs, int strsSize) {
    if (strsSize == 0) {
        return "";
    }

    // Start with the first string as the prefix
    char* prefix = strs[0];
    int prefixLength = strlen(prefix);

    // Iterate over the remaining strings
    for (int i = 1; i < strsSize; i++) {
        // Compare prefix with the current string
        while (strncmp(prefix, strs[i], prefixLength) != 0) { // prefix 와 current string 을 비교
            prefixLength--;
            prefix[prefixLength] = '\0'; // prefix truncation
            if (prefixLength == 0) {
                return ""; 
            }
        }
    }

    return prefix;
}