#include <iostream>
#include <math.h>

using namespace std;

void merge(int A[], int p, int q, int r) {
    int leftSize = q - p + 1;
    int rightSize = r - q;
    int L[leftSize], R[rightSize], i, j, k;
    for(i = 0; i < leftSize; i++)
        L[i] = A[p + i];
    for(j = 0; j < rightSize; j++) // j = 1 because we want to start on q + 1
        R[j] = A[q + j];
    // loop invariants are are manipulated based on conditional statements within a loop
    i = 1;
    j = 1;
    for(k = p; k < r; k++) {
        if(L[i] <= R[j]){
            A[k] = L[i];
            i++;
        } else {
            A[k] = R[j];
            j++;
        }
    }
}

void mergeSort(int A[], int p, int r) {
    int q;
    if(p < r) {
        q = floor((p + r) / 2);
        mergeSort(A, p, q);
        mergeSort(A, q + 1, r);
        merge(A, p, q, r);
    }
}

int main() {
    int A[5] = {5, 4, 3, 2, 1};

    for (int i = 0; i < 5; i++) {
        cout << A[i] << ",";
    }

    cout << endl;

    mergeSort(A, 0, 5);

    for (int i = 0; i < 5; i++) {
        cout << A[i] << ",";
    }

    return 0;
}