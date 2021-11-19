#include <iostream>

using namespace std;

void rightRotate(int arr[], int size) {
    // Write your code here
    int temp = arr[size - 1];
    for(int i = size - 1; i >= 1; i--) {
        arr[i] = arr[i - 1];
    }
    arr[0] = temp;
}

int main() {

    int arr[] = {1, 2, 3, 4, 5};
    int n = sizeof(arr)/sizeof(int);
    rightRotate(arr, n);
    for(auto& e : arr) {
        cout << e << ' ';
    }

}