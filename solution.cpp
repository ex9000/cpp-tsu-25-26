#include<iostream>
using namespace std;

int main()
{
	int n;
	cin >> n;
	int sum = 0;
	for (int i = 0; i < n; i++)
	{
		int k, p;
		cin >> k >> p;
		sum = sum + (k * p);
	}
	cout << sum << endl;
}
