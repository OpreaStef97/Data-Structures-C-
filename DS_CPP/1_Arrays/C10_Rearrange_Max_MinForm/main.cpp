#include <iostream>
#include <vector>

using namespace std;

void maxMin1(int arr[], int size) {
    // Write your code here
    int temp[size];
    int k = 0;
    for(int i = size-1; i >= 0; i--) {
        if(k > size) {
            break;
        }
        temp[k] = arr[i];
        k += 2;
    }
    k = 1;
    for(int i = 0; i < size; i++) {
        if(k > size) {
            break;
        }
        temp[k] = arr[i];
        k += 2;
    }

    for(int i = 0; i < size; i++) {
        arr[i] = temp[i];
    }
}

void maxMin2(int arr[], int size) {
    int* result = new int[size];

    int ptrS = 0;
    int ptrL = size - 1;
    bool switchPtr = true;
    for(int i = 0; i < size; i++) {
        if(switchPtr) {
            result[i] = arr[ptrL--];
        } else {
            result[i] = arr[ptrS++];
        }
        switchPtr = !switchPtr;
    }

    for(int i = 0; i < size; i++) {
        arr[i] = result[i];
    }
    delete [] result;
}

void maxMin3(vector<int>& arr, int size) {
    int maxIdx = size - 1;
    int minIdx = 0;
    int maxElem = arr[maxIdx] + 1;

    for(int i = 0; i < size; i++) {
        if(i % 2 == 0) {
            arr[i] += (arr[maxIdx] % maxElem) * maxElem;
            maxIdx--;
        } else {
            arr[i] += (arr[minIdx] % maxElem) * maxElem;
            minIdx++;
        }
    }

    for(int i = 0; i < size; i++) {
        cout << arr[i] << ' ';
    } 
    cout << endl;

    for(int i = 0; i < size; i++) {
        arr[i] = arr[i] / maxElem;
    } 
}


int main() {
    int arr[] = {1,2,3,4,5};
    int n = sizeof(arr)/sizeof(int);

    maxMin1(arr,n);
    for(int i = 0; i < n; i++) {
        cout << arr[i] << ' ';
    }
    cout << endl;

    vector<int> arr2 = {1,2,3,4,5};

    maxMin3(arr2, arr2.size());

    for(auto& e : arr2) {
        cout << e << ' ';
    }
    cout << endl;


}