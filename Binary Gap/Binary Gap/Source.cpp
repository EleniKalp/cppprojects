#include <iostream>
#include <vector>     
#include <algorithm>
using namespace std;

vector<int> solution(vector<int>& A, int K)
{
	vector <int> shift;
	if (A.empty()) // check for empty array
		return {};
	if (K > A.size()) //if K bigger then size of array 
		K = K % A.size();
	if (K < A.size())
		K = A.size() - K; //normalize K to the position to start the shifted array
	if (K == A.size()) //if K= size of array, avoid any computation.
		return A;
	for (unsigned int i = K; i < A.size(); i++)
	{
		shift.push_back(A[i]);
	}
	for (unsigned int i = 0; i < K; i++)
	{
		shift.push_back(A[i]);
	}
	return shift;
}


int main()
{
	int n = 3;
	vector <int> A{ 3, 8, 9, 7, 6 };
	 solution(A,n);
	 return 0;
 }