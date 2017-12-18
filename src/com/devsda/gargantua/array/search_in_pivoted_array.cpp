#include <stdio.h>
#include<iostream>

using namespace std;

int findPivot(int[], int, int);
int binarySearch(int[], int, int, int);

/* Searches an element no in a pivoted sorted array arrp[]
   of size arr_size */
int pivotedBinarySearch(int arr[], int arr_size, int no)
{
   int pivot = findPivot(arr, 0, arr_size-1);
   if(arr[pivot] == no)
     return pivot;
   if(arr[0] <= no)
     return binarySearch(arr, 0, pivot-1, no);
   else
     return binarySearch(arr, pivot+1, arr_size-1, no);
}

/* Function to get pivot. For array 3, 4, 5, 6, 1, 2
   it will return 3 */
int findPivot(int arr[], int low, int high)
{
   int mid = (low + high)/2;   /*low + (high - low)/2;*/
   if(arr[mid] > arr[mid + 1])
     return mid;
   if(arr[low] > arr[mid])
     return findPivot(arr, low, mid-1);
   else
     return findPivot(arr, mid + 1, high);
}

/* Standard Binary Search function*/
int binarySearch(int arr[], int low, int high, int no)
{
  if(high >= low)
  {
    int mid = (low + high)/2;  /*low + (high - low)/2;*/

    if(no == arr[mid])
      return mid;
    if(no > arr[mid])
      return binarySearch(arr, (mid + 1), high, no);
    else
      return binarySearch(arr, low, (mid -1), no);
  }
  /*Return -1 if element is not found*/
  return -1;
}

/* Driver program to check above functions */
int main()
{
   int arr[10] = {3, 4, 5, 6, 7, 1, 2};
   int n = 5;
   printf("Index of the element is %d", pivotedBinarySearch(arr, 7, 5));
   getchar();
   return 0;
}
