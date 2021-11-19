#include <iostream>

using namespace std;

int * findProduct(int arr[], int size)  { 
    int temp = 1;
    int * product = new int[size]; 

    for(int i = 0; i < size; i++) {
        product[i] = temp;
        temp *= arr[i];
    }
    
    temp = 1;

    for(int i = size - 1; i >= 0; i--) {
        product[i] *= temp;
        temp *= arr[i];
    }
    return product; 
} 

int main() {
    int arr[] = {1,2,3,4,5};
    int n = sizeof(arr)/sizeof(int);

    int* res = findProduct(arr,n);

    for(int i = 0; i < n; i++) {
        cout << res[i] << ' ';
    }
}