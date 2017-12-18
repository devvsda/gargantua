#include<iostream>

using namespace std;

int numbers[] = {2, 3, 1, 4};

int DP[3][100];
int computed[2][100];
int lastPosition = 2;
int neededResult = 7;

int rec(int position, int currentValue)
{
   if (position == lastPosition)
   {
      cout << "\n\t\tfirst condition met  " << position << endl;
      return (currentValue == neededResult);
   }

   if (computed[position][currentValue]) {
       cout << "\n\t\tsecond condition met\n";
       return DP[position][currentValue];
   }

   int can = 0;
   int nextNumber = numbers[position + 1];

   cout << endl << "Position  " << position << " currentvalue  " << currentValue << endl;

   //Try every operation here and call rec again
   can |= rec(position + 1, currentValue + nextNumber);
   cout <<  "    1    " << position << "  " << currentValue << "  "  << can << endl;
   can |= rec(position + 1, currentValue - nextNumber);
   cout <<  "    2    " << position << "  " << currentValue << "  "  << can << endl;
   can |= rec(position + 1, currentValue * nextNumber);
   cout <<  "    3    " << position << "  " << currentValue << "  "  << can << endl;
   can |= rec(position + 1, currentValue / nextNumber);

   cout << position << "  " << currentValue << "  "  << can << endl;

   DP[position][currentValue] = can;
   computed[position][currentValue] = 1;
   cout << "\n position " << position << "  currentValue  " << currentValue << endl;
   return can;
}

main() {
    cout << rec(0, 2);
    return 0;
}
