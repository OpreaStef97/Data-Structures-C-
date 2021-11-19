#include <iostream>

using namespace std;

int partitioning(int arr[], int s, int e) {
    int pivot = arr[e];
    int i = s - 1;

    for(int j = s; j < e; j++) {
        if(arr[j] < pivot) {
            i++;
            swap(arr[i],arr[j]);
        }
    }

    swap(arr[i + 1], arr[e]);

    return i + 1;
}

void sort(int arr[], int s, int e) {
    if(s >= e) {
        return;
    }
    int p = partitioning(arr, s, e);
    sort(arr, s, p - 1);
    sort(arr, p + 1, e);
}


int main() {
    int arr[] = {9, 312, 32, 78, 5, 3, 25, 11, 0, 22, 55, 78, 1};
    sort(arr, 0, sizeof(arr)/sizeof(int) - 1);

    for(auto& e : arr) {
        cout << e << ' ';
    }
    cout << endl;


    return 0;
}