#include <iostream>
#include <algorithm>

using namespace std;

void Heapify(int Tab1[], int n, int root);
void HeapSort(int Tab1[], int n);


int main()
{
    int tests;
    cin >> tests;

    while (tests > 0) {
        int size;
        cin >> size;
        int* Tab;
        Tab = new int[size];

        for (int i = 0; i < size; i++) {
            cin>>Tab[i];
        }

        HeapSort(Tab, size);

        for (int q = 0; q < size  ; q++) {
            cout << Tab[q] << " ";
        }cout << endl;

        cout << endl;
        
        tests--;
    }


    return 0;

}


void Heapify(int Tab1[], int n, int root){
    int largest = root;
    int left = 2 * root + 1;
    int right = 2 * root + 2;

    if (left<n && Tab1[left]>Tab1[largest]) {
        largest = left;
    }

    if (right<n && Tab1[right]>Tab1[largest]) {
        largest = right;
    }

    

    if (largest != root) {
        swap(Tab1[root], Tab1[largest]);

        Heapify(Tab1, n, largest);
    }
}

void HeapSort(int Tab1[], int n) {

    for (int i = n / 2 - 1; i >= 0; i--) {
        Heapify(Tab1, n, i);
    }

    
    for (int j = n - 1; j >=1 ; j--) {

        for (int i = 0; i <= j; ++i) {
            cout << Tab1[i] << " ";

        }cout << endl;

        swap(Tab1[0], Tab1[j]);
        Heapify(Tab1, j, 0);    
    }
}


