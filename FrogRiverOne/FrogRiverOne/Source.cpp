#include <iostream>
#include <math.h>
#include <vector>
#include <set>

using namespace std;

int solution(vector<int>& A, int X)
{
	for (int i = 0; i < A.size(); i++)
		if (A[i] == X)
			return i;

	/*set<int> s;
 for (size_t i = 0; i < A.size(); i++) {
        s.insert(A[i]);
 if (s.size() == X) return i;
    }
 
 return -1; */
}

int main()
{
	int X = 5;
	vector <int> A{ 1, 3, 1, 4, 2, 3, 5, 6};
	cout << solution(A, X);
	return 0;
}