#include "MaxHeap.hpp"

int main() {
  MaxHeap<int> heap;
  
  int size = 6;
  int arr[size] = {1,2,3,4,5,6};

  heap.buildHeap(arr,size);
  heap.printHeap();
  
  cout << heap.getMax() << endl;
  heap.removeMax();
  cout << heap.getMax() << endl;
  heap.removeMax();
  cout << heap.getMax() << endl;
  heap.insert(1000);
  cout << heap.getMax() << endl;
  
  return 0;
}