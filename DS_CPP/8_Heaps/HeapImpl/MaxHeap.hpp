#include <iostream>
#include <vector>

using namespace std;

template <typename T>
class MaxHeap {
private:
    void percolateUp(int i) {
        if(i <= 0) {
            return;
        }
        else if(h[(i - 1) / 2] < h[i]) {
            swap(h[i], h[(i - 1) / 2]);
            percolateUp((i - 1) / 2);
        }
    }

    void maxHeapify(int i) {
        int lc = i * 2 + 1;
        int rc = i * 2 + 2;
        int imax = i;

        if(lc < size() && h[lc] > h[imax]) {
            imax = lc;
        }

        if(rc < size() && h[rc] > h[imax]) {
            imax = rc;
        }

        if(i != imax) {
            swap(h[i], h[imax]);
            maxHeapify(imax);
        }
    }

public:
    vector<T> h;

    MaxHeap() {
        h.resize(0);
    }

    int size() {
        return h.size();
    }

    T getMax() {
        if(size() <= 0) {
            return -1;
        }
        else {
            return h[0];
        }
    }

    void insert(const T& key) {
        h.push_back(key);

        int i = size() - 1;

        percolateUp(i);
    }

    void removeMax() {
        if(size() == 1) {
            h.pop_back();
        }
        else if(size() > 1) {
            swap(h[0], h[size() - 1]);

            h.pop_back();

            maxHeapify(0);
        }
    }

    void buildHeap(T arr[], int size) {
        copy(&arr[0], &arr[size], back_inserter(h));

        for(int i = (size - 1) / 2; i >= 0; --i) {
            maxHeapify(i);
        }
    }

    void printHeap() {
        for(int i = 0; i <= size() - 1; ++i) {
            cout << h[i] << " ";
        }
        cout << endl;
    }

};