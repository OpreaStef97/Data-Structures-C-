#include <iostream>

using namespace std;

int * mergeArrays(int arr1[], int arr2[], int arr1Size,int arr2Size)
{
    int * arr3; // creating new array
    // Write your code here
    arr3 = new int[arr1Size + arr2Size];

    int i = 0, j = 0;
    int m = 0;
    while (i < arr1Size && j < arr2Size) {
        if(arr1[i] < arr2[j]) {
            arr3[m] = arr1[i];
            i++;
            m++; 
        } else {
            arr3[m] = arr2[j];
            j++;
            m++;
        }
    }

    while(i < arr1Size) {
        arr3[m++] = arr1[i++];
    }

    while(j < arr2Size) {
        arr3[m++] = arr2[j++];
    }
    return arr3; // returning array
}

int main() {
    int *arr1 = new int[4];
    int *arr2 = new int[4];

    arr1[0] = 1; arr1[1] = 3; arr1[2] = 4; arr1[3] = 5;

    arr2[0] = 2; arr2[1] = 6; arr2[2] = 7; arr2[3] = 8;

    int *arr3 = mergeArrays(arr1, arr2, 4, 4);

    for(int i = 0; i < 8; i++) {
        cout << arr3[i] << ' ';
    }
    cout << endl;

}