#include <iostream>
#include <vector>

using namespace std;

int findFirstUnique(int arr[], int size) {
    int maxn = 0;
    for(int i = 0; i < size; i++) {
        maxn = max(maxn, arr[i]);
    }

    vector<int> freq(maxn + 1, 0);

    for(int i = 0; i < (int)size; i++) {
        freq[arr[i]]++;
    }

    for(int i = 0; i < (int)size; i++) {
        if(freq[arr[i]] == 1) {
            return arr[i];
        }
    }
    return -1;
}

int main() {
    int arr[] = {2,3,9,2,3,6};
    int n = sizeof(arr)/sizeof(int);

    cout << findFirstUnique(arr, n) << endl;

}
