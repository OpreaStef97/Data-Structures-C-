#include <iostream>

using namespace std;

int findSecondMaximum(int arr[], int size) {
    int secondmax = INT_MIN;
    int max1 = INT_MIN;
    // Write your code here
    
    for(int i = 0; i < size; i++) {
        if(max1 < arr[i]){
            secondmax = max1;
            max1 = arr[i];
        } else if (secondmax < arr[i]) {
            secondmax = arr[i];
        }
    }
    return secondmax;
}

int main() {
    int arr[] = {9,2,3,6,15,27};
    int n = sizeof(arr)/sizeof(int);

    cout << findSecondMaximum(arr, n) << endl;
}