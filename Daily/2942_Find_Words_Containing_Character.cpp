#include <iostream>
#include <string>
#include <vector>
#include <stack>
#include <unordered_map>

using namespace std;

class Solution {
public:
    vector<int> findWordsContaining(vector<string>& words, char x) {
        vector<int> pos;
        for (int i = 0; i < words.size(); i++) {
            if (words[i].find(x) != string::npos) {
                pos.push_back(i);
            }
        }
        return pos;
    }
};