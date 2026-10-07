#include <iostream>
#include <math.h>
#include <algorithm>
#include <vector>
#include <set>

using namespace std;

int solution(vector<int>& A)
{
	int res = 0;

	std::sort(A.begin(), A.end());
	for (int i = 0; i < int(A.size() - 1); i++)
		if (A[i] <= 0)
			res = 1;
		else if (A[i + 1] - A[i] == 2) 
			res = A[i + 1] - 1;
		else
			res = A[i+1] + 1;
	

	return res;
}

int main()
{
	vector <int> A{ 1,2,3 };
	cout << solution(A);
	return 0;
}