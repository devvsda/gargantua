#include<iostream>

using namespace std;

/*int closestZero(int arr[], int size) {
    int i = 1;
    int j = 0;

    int minSum = INT_MAX;
    int sum;

    while(i < size && j < size) {
        sum = arr[i] + arr[j];

        if(minSum > sum ) minSum = sum;

        if(sum < 0) i++;
        else j++;
    }

    return minSum;
}*/

int closestZero(int arr[], int n)
{
  // Variables to keep track of current sum and minimum sum
  int sum, min_sum = INT_MAX;

  // left and right index variables
  int l = 0, r = n-1;

  // variable to keep track of the left and right pair for min_sum
  int min_l = l, min_r = n-1;

  /* Array should have at least two elements*/
  if(n < 2)
  {
    printf("Invalid Input");
    return -1;
  }

  /* Sort the elements */
  //quickSort(arr, l, r);

  while(l < r)
  {
    sum = arr[l] + arr[r];

    /*If abs(sum) is less then update the result items*/
    if(abs(sum) < abs(min_sum))
    {
      min_sum = sum;
      min_l = l;
      min_r = r;
    }
    if(sum < 0)
      l++;
    else
      r--;
  }

  printf(" The two elements whose sum is minimum are %d and %d",
          arr[min_l], arr[min_r]);
    return min_sum;
}

main() {
    int arr[] = {-23, -12, -1, 10, 81, 90};
    int size = sizeof(arr)/sizeof(arr[0]);
    cout << closestZero(arr, size) << endl;
    return 0;
}
