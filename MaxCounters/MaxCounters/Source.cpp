#include <iostream>
#include <math.h>
#include <vector>
#include <set>

using namespace std;

vector<int> solution(int N, vector<int>& A);
{
	vector<int> counter(N, 0);
	int maximum = 0;

	for(int i=0; i<int(A.size()); i++)
		if(A[i] == N+1)
			maximum =0 ,

 return -1; 
}

int main()
{
	int N = 5;
	vector <int> A{ 3, 4, 4, 6, 1, 4, 4};
	cout << solution(N, A);
	return 0;
}