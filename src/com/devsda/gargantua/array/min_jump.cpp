#include <stdio.h>
#include <limits.h>

// Returns minimum number of jumps to reach arr[h] from arr[l]
int minJumps(int arr[], int l, int h)
{
   // Base case: when source and destination are same
   if (h == l){ printf("\nl is %d\n", h);     return 0; }

   // When nothing is reachable from the given source
   if (arr[l] == 0){ printf("\nnothing is reachable from here\n");     return INT_MAX; }

   // Traverse through all the points reachable from arr[l]. Recursively
   // get the minimum number of jumps needed to reach arr[h] from these
   // reachable points.
   int min = INT_MAX;
   for (int i = l+1; i <= h && i <= l + arr[l]; i++)
   {
       printf("\n jump from i position = %d    element = %d\n", i, arr[i]);
       int jumps = minJumps(arr, i, h);
       printf("\njumps = %d\n", jumps);
       if(jumps != INT_MAX && jumps + 1 < min)
           min = jumps + 1;
   }
    printf("\n\t\treturn min = %d\n", min);
   return min;
}

// Driver program to test above function
int main()
{
  int arr[] = {1, 3, 5, 8, 9, 2, 6, 7, 6, 8, 9};
  int n = sizeof(arr)/sizeof(arr[0]);
  printf("Minimum number of jumps to reach end is %d ", minJumps(arr, 0, n-1));
  return 0;
}
