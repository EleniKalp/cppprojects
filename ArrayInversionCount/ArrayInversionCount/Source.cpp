#include <iostream>
#include <math.h>
#include <vector>

using namespace std;

int solution(vector<int>& A)
{
	int count = 0;

	for (int i = 0; i < (int(A.size()) - 1); i++)
		for (int j = i + 1; j < int(A.size()); j++)
			if (A[j] < A[i])
				count++;

	if (count < 1000000)
		return count;
	else
		return -1;

}

int main()
{
	vector <int> A{ -1, 6, 3, 4, 7, 4 };
	cout << solution(A);
	return 0;
}