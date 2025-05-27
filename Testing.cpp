#include <iostream>
#include <unordered_map>
#include <string>
#include <vector>

using namespace std;

void insertionSort(vector<int> &arr){
    for (int i = 1; i < arr.size(); i++){
        int temp = arr[i];
        int j = i - 1;
        
        // Di chuyển các phần tử lớn hơn temp về sau một vị trí
        while (j >= 0 && arr[j] > temp){
            arr[j + 1] = arr[j];
            j--;
        }
        // Đặt temp vào vị trí đúng
        arr[j + 1] = temp;
    }
}

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