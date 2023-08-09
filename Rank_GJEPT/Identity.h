#include <iostream>
#include <vector>

using namespace std;

template<typename T>
vector<vector<int>> Identity(T num)
{
   vector<vector<int>> matrix(num, vector<int>(num, 0));

   for (size_t i = 0; i < num; i++)
   {
      matrix[i][i] = 1;
   }

   return matrix;
}




// Driver Code
//int main()
//{
//	int size = 5;
//	identity(size);
//	return 0;
//}


