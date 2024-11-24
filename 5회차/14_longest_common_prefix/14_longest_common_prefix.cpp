#include <iostream>
#include <string>
#include <vector>

// Function to find the longest common prefix
std::string longest_common_prefix(const std::vector<std::string>& strs) {
    if (strs.empty()) {
        return "";
    }

    // Start with the first string as the prefix
    std::string prefix = strs[0];

    // Iterate over the remaining strings
    for (size_t i = 1; i < strs.size(); i++) {
        // Compare prefix with the current string
        while (strs[i].find(prefix) != 0) {
            prefix.pop_back(); // Remove the last character from prefix
            if (prefix.empty()) {
                return ""; // No common prefix
            }
        }
    }

    return prefix;
}