#include <iostream>
#include <cstdlib>
#include <ctime>   

using namespace std;


void swap(int &a, int &b) {
    int temp = a;
    a = b;
    b = temp;
}


int partition(int arr[], int left, int right, int pivotIndex) {
    int pivotValue = arr[pivotIndex];
    swap(arr[pivotIndex], arr[right]); 
    int storeIndex = left;

    for (int i = left; i < right; i++) {
        if (arr[i] < pivotValue) {
            swap(arr[i], arr[storeIndex]);
            storeIndex++;
        }
    }
    swap(arr[storeIndex], arr[right]);
    return storeIndex;
}


int randomizedPartition(int arr[], int left, int right) {
    int pivotIndex = left + rand() % (right - left + 1);
    return partition(arr, left, right, pivotIndex);
}


int randomizedSelect(int arr[], int left, int right, int k) {
    if (left == right) 
        return arr[left];

    int pivotIndex = randomizedPartition(arr, left, right);
    int length = pivotIndex - left + 1;

    if (k == length) 
        return arr[pivotIndex];
    else if (k < length) 
        return randomizedSelect(arr, left, pivotIndex - 1, k);
    else 
        return randomizedSelect(arr, pivotIndex + 1, right, k - length);
}

int main() {
    srand(time(0));

    int n = 7;
   
    int* arr = new int[n];


    int values[] = {100, 3, 17, 70, 4, 19, 26};
    for (int i = 0; i < n; ++i) {
        arr[i] = values[i];
    }

    int k = 3;

    cout << "The " << k << "rd smallest element is " << randomizedSelect(arr, 0, n - 1, k) << endl;

   
    delete[] arr;

    return 0;
}
