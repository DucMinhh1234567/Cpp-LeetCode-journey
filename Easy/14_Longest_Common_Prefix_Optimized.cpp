#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Solution {
public:
    // Cách 1: Vertical Scanning
    string longestCommonPrefix_Vertical(vector<string>& strs) {
        if (strs.empty()) return "";
        
        // Lấy độ dài của từ ngắn nhất
        int minLen = strs[0].length();
        for (const string& str : strs) {
            minLen = min(minLen, (int)str.length());
        }
        
        // So sánh từng cột
        for (int i = 0; i < minLen; i++) {
            char c = strs[0][i];
            for (int j = 1; j < strs.size(); j++) {
                if (strs[j][i] != c) {
                    return strs[0].substr(0, i);
                }
            }
        }
        
        return strs[0].substr(0, minLen);
    }

    // Cách 2: Binary Search
    bool isCommonPrefix(vector<string>& strs, int len) {
        string prefix = strs[0].substr(0, len);
        for (int i = 1; i < strs.size(); i++) {
            if (strs[i].substr(0, len) != prefix) {
                return false;
            }
        }
        return true;
    }
    
    string longestCommonPrefix_Binary(vector<string>& strs) {
        if (strs.empty()) return "";
        
        // Tìm độ dài ngắn nhất
        int minLen = strs[0].length();
        for (const string& str : strs) {
            minLen = min(minLen, (int)str.length());
        }
        
        // Binary search
        int left = 1;
        int right = minLen;
        
        while (left <= right) {
            int mid = (left + right) / 2;
            if (isCommonPrefix(strs, mid)) {
                left = mid + 1;
            } else {
                right = mid - 1;
            }
        }
        
        return strs[0].substr(0, (left + right) / 2);
    }
};

// Hàm main để test
int main() {
    Solution solution;
    vector<string> test1 = {"flower", "flow", "flight"};
    vector<string> test2 = {"dog", "racecar", "car"};
    
    cout << "Test 1:" << endl;
    cout << "Vertical Scanning: " << solution.longestCommonPrefix_Vertical(test1) << endl;
    cout << "Binary Search: " << solution.longestCommonPrefix_Binary(test1) << endl;
    
    cout << "\nTest 2:" << endl;
    cout << "Vertical Scanning: " << solution.longestCommonPrefix_Vertical(test2) << endl;
    cout << "Binary Search: " << solution.longestCommonPrefix_Binary(test2) << endl;
    
    return 0;
} 