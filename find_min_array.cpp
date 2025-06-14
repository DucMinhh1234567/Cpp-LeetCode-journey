#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>
#include <numeric>
using namespace std;

int main() {
    // Cách 1: Sử dụng vòng lặp for thông thường
    vector<int> arr1 = {5, 2, 8, 1, 9, 3};
    int min1 = arr1[0];
    for(int i = 1; i < arr1.size(); i++) {
        if(arr1[i] < min1) {
            min1 = arr1[i];
        }
    }
    cout << "Cách 1 (for loop): " << min1 << endl;

    // Cách 2: Sử dụng min_element từ thư viện algorithm
    vector<int> arr2 = {5, 2, 8, 1, 9, 3};
    int min2 = *min_element(arr2.begin(), arr2.end());
    cout << "Cách 2 (min_element): " << min2 << endl;

    // Cách 3: Sử dụng INT_MAX
    vector<int> arr3 = {5, 2, 8, 1, 9, 3};
    int min3 = INT_MAX;
    for(int num : arr3) {
        min3 = min(min3, num);
    }
    cout << "Cách 3 (INT_MAX): " << min3 << endl;

    // Cách 4: Sử dụng range-based for loop
    vector<int> arr4 = {5, 2, 8, 1, 9, 3};
    int min4 = arr4[0];
    for(const int& num : arr4) {
        if(num < min4) {
            min4 = num;
        }
    }
    cout << "Cách 4 (range-based for): " << min4 << endl;

    // Cách 5: Sử dụng accumulate với min
    vector<int> arr5 = {5, 2, 8, 1, 9, 3};
    int min5 = accumulate(arr5.begin(), arr5.end(), arr5[0], 
                         [](int a, int b) { return min(a, b); });
    cout << "Cách 5 (accumulate): " << min5 << endl;

    return 0;
} 