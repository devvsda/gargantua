# include <stdio.h>

/* Function to swap values at two pointers */
void swap (char *x, char *y)
{
    char temp;
    temp = *x;
    *x = *y;
    *y = temp;
}

/* Function to print permutations of string
   This function takes three parameters:
   1. String
   2. Starting index of the string
   3. Ending index of the string. */
void permute(char *a, int i, int n)
{
   int j;
   if (i == n)
     printf("\nResult is %s", a);
   else
   {
        for (j = i; j <= n; j++)
       {
          printf("\n1. %s   %d   %d  swap %c  with %c", a, i, j, *(a + i), *(a + j));
          swap((a+i), (a+j));
          printf("\n2. \t%s  %d  %d   ", a, i, j);
          permute(a, i+1, n);
          printf("\n3. \t\t%s  %d    %d  swap %c  with %c", a, i, j, *(a + i), *(a + j));
          swap((a+i), (a+j)); //backtrack
          printf("\n4. \t\t\t%s  %d   %d", a, i, j);
       }
   }
}

/* Driver program to test above functions */
int main()
{
   char a[] = "ABC";
   permute(a, 0, 2);
   getchar();
   return 0;
}
