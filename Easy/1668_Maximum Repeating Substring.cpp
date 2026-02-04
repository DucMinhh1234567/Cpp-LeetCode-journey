#include <iostream>
#include <string>
#include <vector>
#include <stack>
#include <unordered_map>
#include <unordered_set>
#include <algorithm>
#include <cmath>
#include <sstream>

using namespace std;

// For a string sequence, a string word is k-repeating 
// if word concatenated k times is a substring of sequence. 
// The word's maximum k-repeating value is the highest value k 
// where word is k-repeating in sequence. If word is not a substring of sequence, 
// word's maximum k-repeating value is 0.

// Given strings sequence and word, 
// return the maximum k-repeating value of word in sequence.

// Example 1:

// Input: sequence = "ababc", word = "ab"
// Output: 2
// Explanation: "abab" is a substring in "ababc".

class Solution {
public:
    int maxRepeating(string sequence, string word) {
        int maxCount = 0;
        int n = sequence.size();
        int m = word.size();

        // Try starting from each position
        for (int i = 0; i <= n - m; i++) {
            int count = 0;
            int pos = i;
            
            // Count consecutive occurrences starting from position i
            while (pos <= n - m && sequence.substr(pos, m) == word) {
                count++;
                pos += m;
            }
            maxCount = max(maxCount, count);
        }
        
        return maxCount;
    }
};