#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void heapify(vector<int>& arr, int n, int i) {
    int largest = i;

    int l = 2 * i + 1;
    int r = 2 * i + 2;

    if(l < n && arr[l] > arr[largest]) {
        largest = l;
    }

    if(r < n && arr[r] > arr[largest]) {
        largest = r;
    }

    if(i != largest) {
        swap(arr[i], arr[largest]);
        heapify(arr, n, largest);
    }
}

void heapsort(vector<int>& arr) {
    // for(int i = (arr.size()/2) - 1; i >= 0; --i) {
    //     heapify(arr, arr.size(), i);
    // }

    make_heap(arr.begin(),arr.end());

    for(int i = arr.size() - 1; i > 0; --i) {
        swap(arr[i], arr[0]);
        heapify(arr, i, 0);
    }
}

int main()
{
    vector<int> vec = {6, 5, 3, 1, 8, 7, 2, 4};

    heapsort(vec);

    for (auto e : vec) {
        cout << e << ' ';
    }
    cout << endl;

}