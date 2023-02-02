#include<iostream>
#include<stdio.h>
using namespace std;


int main()
{
	int A, B;
	cin >> A >> B;
	cout << int(A / B)<< ".";
	A = A % B;
	for (int i = 0; i <= 1000; i++)
	{
		A *= 10;
		cout << A/ B;
		A = A - (A / B)*B;
	}
}