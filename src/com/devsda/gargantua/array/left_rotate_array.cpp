#include<stdio.h>
#include<iostream>

using namespace std;

/*Prototype for utility functions */
void printArray(int arr[], int size);
void swap(int arr[], int fi, int si, int d);

void leftRotate(int arr[], int d, int n)
{
  int i, j;

  if(d == 0 || d == n)
    return;

  i = d;
  j = n - d;

  while (i != j)
  {
    if(i < j) /*A is shorter*/
    {
      swap(arr, d-i, d+j-i, i);
      cout << "\nif\n"  << i << "  " << j << "  " <<  d << endl;
      printArray(arr, 7);
      j -= i;
    }
    else /*B is shorter*/
    {
      swap(arr, d-i, d, j);
      cout << "\nelse \n"<< i << "  " << j << "  " <<  d << endl;
      printArray(arr, 7);
      i -= j;
    }
    // printArray(arr, 7);
  }
  /*Finally, block swap A and B*/
  swap(arr, d-i, d, i);
}

/*UTILITY FUNCTIONS*/
/* function to print an array */
void printArray(int arr[], int size)
{
  int i;
  for(i = 0; i < size; i++)
    printf("%d ", arr[i]);
  printf("%\n ");
}

/*This function swaps d elements starting at index fi
  with d elements starting at index si */
void swap(int arr[], int fi, int si, int d)
{
   int i, temp;
   for(i = 0; i<d; i++)
   {
     temp = arr[fi + i];
     arr[fi + i] = arr[si + i];
     arr[si + i] = temp;
   }
}

/* Driver program to test above functions */
int main()
{
   int arr[] = {1, 2, 3, 4, 5, 6, 7};
   leftRotate(arr, 3, 7);
   cout << "\n\nanswer\n";
   printArray(arr, 7);
   getchar();
   return 0;
}

