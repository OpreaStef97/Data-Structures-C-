#include <iostream>
#include <algorithm>

using namespace std;

void merge(int arr[], int s, int e) {
    int mid = (s + e)/2;
    int i = s;
    int j = mid + 1;
    int* temp = new int[e];
    int k = 0;

    while(i <= mid && j <= e) {
        if(arr[i] < arr[j]) {
            temp[k++] = arr[i++];
        } else {
            temp[k++] = arr[j++];
        } 
    }

    while(i <= mid) {
        temp[k++] = arr[i++];
    }
    while(j <= e) {
        temp[k++] = arr[j++];
    }
    k = 0;
    for(int i = s; i <= e; i++) {
        arr[i] = temp[k++];
    }
}


void mergesort(int arr[], int s, int e) {
    if(s >= e) {
        return;
    } 

    int mid = (s+e)/2;
    mergesort(arr, s, mid);
    mergesort(arr, mid + 1, e);
    merge(arr, s, e);
}



int * findSum(int arr[], int value, int size) {
    // Sorting function is prepended as sort(arr, low, high)
    sort(arr, arr + size);

    int* temp = new int[2];

    int pointer1 = 0;
    int pointer2 = size - 1;

    while (pointer1 != pointer2) {
        int sum = arr[pointer1] + arr[pointer2];

        if(sum < value) {
            pointer1++;
        } else if (sum > value) {
            pointer2--;
        } else {
            temp[0] = arr[pointer1];
            temp[1] = arr[pointer2];
            return temp;
        }
    }
    // Write your code here
    return arr; 
} 

int main() {
    int arr[] = {1, 21, 3, 14, 5, 60, 7, 6};

    int* res = findSum(arr, 81, 8);

    for(int i = 0; i < 2; i++) {
        cout << res[i] << ' ';
    }
}