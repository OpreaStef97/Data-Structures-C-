#include <iostream>

using namespace std;

int* removeEven( int *& Arr, int size ) {
    // Write your code here
    int m = 0;
    for(int i = 0; i < size; i++){
        if(Arr[i] % 2 != 0) {
            Arr[m] = Arr[i];
            m++;
        }
    }
    int *temp = new int[m];
    for(int i = 0; i < m; i++) {
        temp[i] = Arr[i];
    }

    delete[] Arr;
    Arr = temp;
    return Arr;
}

int main() {
    int* arr;
    int size = 5;
    arr = new int[size];

    for(int i = 0; i < size; i++) {
        arr[i] = i;
    }

    removeEven(arr,size);

    for(int i = 0; i < 2; i++) {
        cout << arr[i] << ' ';
    }    
    cout << endl;
}