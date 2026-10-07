#include <iostream>
#include <vector> 
#include <set>
#include <algorithm>
using namespace std;

int solution(vector<int>& A)
{
	set<int> s;

	for (auto i : A) {
		if (s.find(i) == s.end()) {
			s.insert(i);
		}
		else {
			s.erase(i);
		}
	}

	return *s.begin();
}


int main()
{
	
	vector <int> A{ 9, 3, 9, 3, 9, 7, 9 };
	cout << solution(A);
	return 0;
}