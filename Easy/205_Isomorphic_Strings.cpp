#include <iostream>
#include <string>
#include <vector>
#include <stack>
#include <unordered_map>
#include <unordered_set>
#include <algorithm>
#include <cmath>

using namespace std;

class Solution {
public:
    bool isIsomorphic(string s, string t) {
        // Cách matday
        if (s.length() != t.length()) return false;

        vector<int> lens(200, 0);
        vector<int> lent(200, 0);

        for (int i = 0; i < s.length(); i++){
            // Nếu chữ cái gặp lần đầu sẽ cho qua hết
            if (lens[s[i]] != lent[t[i]]) return false;
            // Kể từ chữ trùng lặp lần sau nếu khác giá trị thì oẳng
            // Ví dụ gg và da
            // g = d = 0
            // g = 1 != a = 0
            lens[s[i]] = i + 1;
            lent[t[i]] = i + 1; 
        }

        return true;

        // Dùng map thì chắc nhét 2 map rồi so sánh từng lượng chữ ở từng vị trí
        // Kể ra cách matday kia là cách rút gọn của cách này
    }
};