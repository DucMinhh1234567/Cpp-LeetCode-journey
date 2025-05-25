#include <iostream>
#include <unordered_map>
#include <string>

using namespace std;

int main() {
    unordered_map<int, string> myMap;
    
    // Sử dụng operator []
    cout << "Using operator []:" << endl;
    myMap[1] = "first";
    cout << "After first insert: " << myMap[1] << endl;  // "first"
    
    myMap[1] = "second";
    cout << "After second insert: " << myMap[1] << endl;  // "second"
    
    // Sử dụng insert()
    cout << "\nUsing insert():" << endl;
    myMap.clear();
    
    myMap.insert({1, "first"});
    cout << "After first insert: " << myMap[1] << endl;  // "first"
    
    myMap.insert({1, "second"});
    cout << "After second insert: " << myMap[1] << endl;  // "first" (không thay đổi)
    
    return 0;
}