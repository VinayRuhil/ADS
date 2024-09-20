//Randomized quick sort

#include <iostream>
#include <cstdlib>
#include <ctime>  

using namespace std;


int partition(int arr[], int low, int high) {

    int pivotIndex = low + rand() % (high - low + 1);
    cout << "Pivot Index: " << pivotIndex << endl;
    

    swap(arr[pivotIndex], arr[high]);
    int pivot = arr[high];
    
    
    int i = low - 1;
    for (int j = low; j <= high - 1; j++) {
        if (arr[j] <= pivot) {
            i++;
            swap(arr[i], arr[j]);
        }
    }
    swap(arr[i + 1], arr[high]);
    

    return i + 1;
}


void randomizedQuickSort(int arr[], int low, int high) {
    if (low < high) {
     
        int pivotIndex = partition(arr, low, high);
        
  
        randomizedQuickSort(arr, low, pivotIndex - 1);
        randomizedQuickSort(arr, pivotIndex + 1, high);
    }
}

int main() {
   
    srand(time(0));
    

    int n;
    cout << "Enter the number of elements: ";
    cin >> n;
    

    int* arr = new int[n];
    

    cout << "Enter " << n << " elements: ";
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    

    randomizedQuickSort(arr, 0, n - 1);
    

    cout << "Sorted array: ";
    for (int i = 0; i < n; i++)
        cout << arr[i] << " ";
    cout << endl;
    
 
    delete[] arr;
    
    return 0;
}

