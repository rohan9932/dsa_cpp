#include<bits/stdc++.h>
using namespace std;


class Heap {
public:
    int arr[100];
    int size;

    Heap() {
        arr[0] = -1;
        size = 0;
    }

    void insert(int val) {
        size++;
        int idx = size;
        arr[idx] = val;

        while(idx > 1) {
            int parent = idx/2;
            if(arr[idx] > arr[parent]) {
                swap(arr[parent], arr[idx]);
                idx = parent;
            } else return;
        }
    }

    void deletefromHeap() {
        if(size == 0) {
            cout << "Nothing to delete\n";
            return;
        }

        arr[1] = arr[size]; //put last el into first
        size--; //remove last el

        //take root node to correct pos
        int i = 1;
        while(i < size) {
            int leftIdx = 2*i;
            int rightIdx = 2*i+1;
            int compIdx = 0;
            
            //handling out of bound situations
            if(leftIdx < size && rightIdx < size && arr[leftIdx] < arr[rightIdx]) {
                compIdx = rightIdx;
            }
            else if(leftIdx < size && rightIdx < size && arr[rightIdx] < arr[leftIdx]) {
                compIdx = leftIdx;
            }
            
            
            if(arr[compIdx] > arr[i]) {
                swap(arr[compIdx], arr[i]);
                i = compIdx; 
            } else return; //proper heap
        }
    } 

    void print() {
        for (int i = 1; i <= size; i++)
        {
            cout << arr[i] << " ";
        }
        cout << "\n";
    }
};

void heapifyMax(int arr[], int n, int idx) {
    int largest = idx;
    int left = 2*idx;
    int right = 2*idx+1;

    if(left <= n && arr[largest] < arr[left]) largest = left;
    if(right <= n && arr[largest] < arr[right]) largest = right;

    if(largest != idx) { //not in correct pos
        swap(arr[largest], arr[idx]);
        heapifyMax(arr, n, largest); //check for next subtree
    }
}

void heapSort(int arr[], int n) {
    int temp = n;

    while(temp > 1) {
        //Swap
        swap(arr[1], arr[temp]);
        //ignore the lase element
        temp--;
        //heapify
        heapifyMax(arr, temp, 1);
    }
}

void heapSortRec(int arr[], int n) {
    if(n <= 1) return;
    swap(arr[1], arr[n]);
    heapifyMax(arr, n-1, 1);
    heapSortRec(arr, n-1);
}


int main() {
    Heap h1;
    h1.insert(1);
    h1.insert(2);
    h1.insert(4);
    h1.insert(3);
    h1.insert(5);

    h1.print();

    h1.deletefromHeap();
    h1.print();

    int arr[] = {-1, 1, 2, 3, 4, 5};
    int n = 5;
    for (int i = n/2; i > 0; i--)
    {
        heapifyMax(arr, n, i);
    }

    cout << "Printing the heapified arr:\n";
    for (int i = 1; i <= n; i++)
    {
        cout << arr[i] << " ";
    }
    cout << "\n";

    heapSortRec(arr, 5);
    for(int i = 1; i <= n; i++) {
        cout << arr[i] << " ";
    }
    cout << "\n";
    
    return 0;
}