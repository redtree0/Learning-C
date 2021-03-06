//
// https://www.geeksforgeeks.org/recursive-bubble-sort/
//
#include <iostream>

using namespace std;

int bubbleSort(int arr[], int n);

void printArray(int arr[], int n);

void swap(int *a, int *b);

// Driver program to test above functions
int main()
{
    int arr[] = {64, 34, 25, 12, 22, 11, 90};
    int n = sizeof(arr)/sizeof(arr[0]);
    bubbleSort(arr, n);
    printf("Sorted array: \n");
    printArray(arr, n);
    return 0;
}

int bubbleSort(int arr[], int n){
    
    if(n == 1 ){
        return 1;
    }
 
    for(int i=0; i< n - 1 ; i++){
        if(arr[i] >= arr[i+1]){
            swap(&arr[i], &arr[i+1]);
        }
    }

    return bubbleSort(arr, n-1);

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
