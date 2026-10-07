#include <iostream>
#include <math.h>
using namespace std;

int solution(int X, int Y, int D)
{
	int steps = 0;

	if (X > Y)
		return steps;
	else if (D >= Y)
		return 1;

	
	int distance = Y - X;
	if (distance % D == 0)
		steps = distance / D;
	else
		steps = (distance / D) + 1;

	return steps;
}


int main()
{
	cout << solution(10,100,30);
	return 0;
}