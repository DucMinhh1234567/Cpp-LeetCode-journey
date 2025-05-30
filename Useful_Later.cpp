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

int main(){
    // Sắp xếp theo thứ tự ngược lại
    string str = "hello";
    reverse(str.begin(), str.end()); // Kết quả: "olleh"

    // Sắp xếp theo độ dài của các từ trong string
    string str = "cat dog elephant";
    vector<string> words;
    stringstream ss(str);
    string word;
    while (ss >> word) {
        words.push_back(word);
    }
    sort(words.begin(), words.end(), [](const string& a, const string& b) {
        return a.length() < b.length();
    }); // Kết quả: "cat dog elephant"
}