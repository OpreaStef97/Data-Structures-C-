#include <iostream>

using namespace std;

// void reArrange(int arr[], int size) {
//   // A swap function is prepended. Use it like swap(arg1,arg2)
//   // Write your code here
//     int* temp = new int[size];
//     int k = 0;
//     for(int i = 0; i < size; i++) {
//         if(arr[i] < 0) {
//             temp[k++] = arr[i];
//         }
//     }
//     for(int i = 0; i < size; i++) {
//         if(arr[i] >= 0) {
//             temp[k++] = arr[i];
//         }
//     }
//
//     for(int i = 0; i < size; i++) {
//         arr[i] = temp[i];
//     }
// }

void reArrange(int arr[], int size) {
  // A swap function is prepended. Use it like swap(arg1,arg2)
  // Write your code here
    int j = 0;
    for(int i = 0; i < size; i++) {
        if(arr[i] < 0) {
            if(i != j) {
                swap(arr[i],arr[j]);
                j++;
            }
        }
    }
}

int main() {
    int arr[] = {10, -1, 20, 4, 5, -9, -6};
    int n = sizeof(arr)/sizeof(int);

    reArrange(arr, n);

    for(auto& e : arr) {
        cout << e << ' ';
    }
    cout << endl;
}