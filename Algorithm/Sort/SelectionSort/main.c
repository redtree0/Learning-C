//
// https://www.geeksforgeeks.org/selection-sort/
//
#include <iostream>

using namespace std;

int selectionSort(int arr[], int n);

void printArray(int arr[], int n);

void swap(int *a, int *b);
// Driver program to test above functions
int main()
{
    int arr[] = {64, 25, 12, 22, 11};
    int n = sizeof(arr)/sizeof(arr[0]);
    selectionSort(arr, n);
    printf("Sorted array: \n");
    printArray(arr, n);
    return 0;
}

int selectionSort(int arr[], int n){
    for(int k=0; k<n-1; k++){
        
        int min_idx = k;
        for(int i=k; i<n; i++){
            if(arr[min_idx] >= arr[i]){
                min_idx = i;
            }
        }
        swap(&arr[k], &arr[min_idx]);
    }
    return 0;
}

void swap(int *a, int *b){
    int tmp = *a;
    *a = *b;
    *b = tmp;
}

void printArray (int arr[], int n) {
    for(int i=0; i < n ; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}
