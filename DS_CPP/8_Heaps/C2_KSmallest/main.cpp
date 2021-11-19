#include <iostream>
#include <vector>
#include "../HeapImpl/MaxHeap.hpp"

using namespace std;

void min_heapify(vector<int>& arr, int n, int i) {
    int smallest = i;
    int l = 2 * i + 1;
    int r = 2 * i + 1;

    if(l < n && arr[l] < arr[smallest]) {
        smallest = l;
    }
    if(r < n && arr[r] < arr[smallest]) {
        smallest = r;
    }

    if(i != smallest) {
        swap(arr[i], arr[smallest]);
        min_heapify(arr, n, smallest);
    }
}

vector<int> findKSmallest(int  arr[], int size, int k){
  
    MaxHeap<int> Mh;
    for(int i = 0; i < size; ++i) {
        Mh.insert(arr[i]);

        if(Mh.size() > k) {
            Mh.removeMax();
        }
    }

    vector<int> output(k);
    // Write your code here
    while(Mh.size()) {
        output[--k] = Mh.getMax();
        Mh.removeMax();
    }

    return output;
}

int main() {
    int arr[] = {9,4,7,1,-2,6,5};

    int n = sizeof(arr)/sizeof(int);

    auto res = findKSmallest(arr, n, 3);

    for(auto& e : res) cout << e << ' ';
}
