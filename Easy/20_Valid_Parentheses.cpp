#include <iostream>
#include <string>
#include <vector>
#include <stack>
#include <unordered_map>

using namespace std;

class Solution {
public:
    // Cách 1: Sử dụng nhiều if-else
    bool isValid(string s) {
        stack<char> valid;

        for (int i{0}; i < s.length(); i++){
            if (s[i] == '(' || s[i] == '{' || s[i] == '['){
                valid.push(s[i]);
            }
            else {
                if (valid.empty()) return false;
                else if (s[i] == ')' && valid.top() == '('){
                    valid.pop();
                    continue;
                }
                else if (s[i] == '}' && valid.top() == '{'){
                    valid.pop();
                    continue;
                }
                else if (s[i] == ']' && valid.top() == '['){
                    valid.pop();
                    continue;
                }
                else return false;
            }
        }
        if (!valid.empty()) return false;
        return true;
    }

    // Cách 2: Tối ưu hơn sử dụng map
    bool isValid_Optimized(string s) {
        stack<char> st;
        unordered_map<char, char> pairs = {
            {')', '('},
            {'}', '{'},
            {']', '['}
        };
        
        for(char c : s) {
            if(c == '(' || c == '{' || c == '[') {
                st.push(c);
            } else {
                if(st.empty() || st.top() != pairs[c]) {
                    return false;
                }
                st.pop();
            }
        }
        
        return st.empty();
    }
};