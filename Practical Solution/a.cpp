#include <iostream>

using namespace std;

int main() {
	int m = INT_MIN, num;

	do
	{
		cout << "Enter a number: ";
		cin >> num;

		// m = max(m, num);
		if (m < num)
			m = num;

	} while (num != -99);
	
	cout << "\nMaximum number is " << m << endl;

	return 0;
}