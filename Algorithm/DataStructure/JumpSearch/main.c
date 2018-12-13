#include <iostream>
#include <math.h>

using namespace std;

int jumpSearch(int arr[], int x, int n)  ;

int main()
{
    int arr[] = { 0, 1, 1, 2, 3, 5, 8, 13, 21,
        34, 55, 89, 144, 233, 377, 610 };
    int x = 55;
    int n = sizeof(arr) / sizeof(arr[0]);
    
    // Find the index of 'x' using Jump Search
    int index = jumpSearch(arr, x, n);
    
    // Print the index where 'x' is located
    cout << "\nNumber " << x << " is at index " << index;
    return 0;
}

int jumpSearch(int arr[], int x, int n) {
  
    int step = sqrt(n);
    int index = -1;
    
    for(int i=0; i< n; i+=step){
        if(arr[i] > x){
            index = i - step;
            break;
        }
    }
    
    for(int i=index; i< n; i++){
        if(arr[i]==x){
            return i;
        }
    }
    
    return -1;
    
};
