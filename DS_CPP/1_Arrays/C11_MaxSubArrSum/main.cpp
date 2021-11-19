#include <iostream>

using namespace std;

int maxSumArr(int arr[], int arrSize) {
    int maxSum = numeric_limits<int> :: min();
    int cs = 0;
    for(int i = 0; i < arrSize; i++) {
        cs += arr[i];
        if(arr[i] > cs) {
            cs = arr[i];
        }
        maxSum = max(maxSum, cs);
    }
    return maxSum;
}

int main() {
    int arr[] = {-1, -7, -2, -5, -10, -1};
    int n = sizeof(arr)/sizeof(int);
    cout << maxSumArr(arr, n) << endl;
}