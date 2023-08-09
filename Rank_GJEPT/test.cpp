#include<iostream>

using namespace std;

template<typename T>
void Identity(T num)
{
   for (T row = 0; row < num; row++)
   {
      for (T col = 0; col < num; col++)
      {
         // Checking if row is equal to column
         if (row == col)
            cout << 1 << " ";
         else
            cout << 0 << " ";
      }
      cout << endl;
   }
}

int main() {
   int num = 5;
   Identity<int>(num);
   return 0;
}
