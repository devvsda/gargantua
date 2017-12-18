# include <stdio.h>

void swap(char &s, char &t) {
    char tmp;
    tmp = s;
    s = t;
    t = tmp;
}

/* Function to print reverse of the passed string */
void reverse(char *str, char *temp)
{
    char *tt = str;
   if(*temp == '\0') return;
   else {
       reverse(str, temp + 1);
       printf("\n\n%s \t %s", str, temp);
       swap((*tt), (*temp));
       tt++;
       //printf("%c", *str);
   }
}

/* Driver program to test above function */
int main()
{
   char a[] = "ram";
   reverse(a, a);
   printf("\n\n%s", a);
   getchar();
   return 0;
}
