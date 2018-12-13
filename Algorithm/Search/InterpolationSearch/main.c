// https://www.geeksforgeeks.org/interpolation-search/
// 알고리즘 설명 : https://www.youtube.com/watch?v=-MPTAD4z0gY
//
#include <iostream>
using namespace std;

// If x is present in arr[0..n-1], then returns
// index of it, else returns -1.
int interpolationSearch(int arr[], int n, int x)
{
    int start = 0;
    int end = n-1;
    
    while( start < end && x >= arr[start] && x <= arr[end] ){
        
   
        int pos = start + ( ( end - start ) / ( arr[end] - arr[start] ) * (end - arr[start]) );

        if(arr[pos] == x) {
            return pos;
        }

        if (arr[pos] < x ){
            start = pos + 1;
        } else if (arr[pos] > x ) {
            end = pos - 1;
        }
        
     }
    return -1;
}

// Driver Code
int main()
{
    // Array of items on which search will
    // be conducted.
    int arr[] =  {10, 12, 13, 16, 18, 19, 20, 21, 22, 23,
        24, 33, 35, 42, 47};
    int n = sizeof(arr)/sizeof(arr[0]);
    
    int x = 18; // Element to be searched
    int index = interpolationSearch(arr, n, x);
    
    // If element was found
    (index == -1) ? cout << "Element not found." : cout << "Element found at index "<< index ;
    
    return 0;
}
