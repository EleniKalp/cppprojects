#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int solution(int A, int B, int K)
{
	vector<int> numbers;
	int size = B - A;
	int res = 0;

	for (int i = 0; i < size; i++) {
		numbers.push_back(A + i);
		if (numbers[i] % K == 0)
			res++;
	}
		
	
	return res;
}

int main()
{
	cout << solution(6,11,2);
	return 0;
}