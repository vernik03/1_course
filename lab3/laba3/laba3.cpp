#include <iostream>
#include <clocale>
#include <string>
#include <ctime>
#include <Windows.h>
#include <vector>
#include <cmath>   
#include <algorithm>
#include <fstream>
#include <iomanip> 

using namespace std;

int Foo(double d) {
	int test = (int)d;
	int count = 0;
	while (test != d) {
		count++;
		d *= 10;
		test = (int)d;
	}
	return count;
}

int main()
{
	int n, a, count;
	long double  x0, x1, xend;
	float e;
	cout << "A: ";
	cin >> a;
	cout << "n: ";
	cin >> n;
	cout << "e: ";
	cin >> e;
	/*int k = 2;
	while (k <= n) {
		if (n % k == 0) {
			break;
		}
		k++;  
	}*/
	//count = Foo(e);
	e = e + 1;
	if (n==0)
	{
		cout << "ERROR";
	}
	else {

	
	if (a==0)
	{
		cout << n << (unsigned char)251 << a << " = " << 0;
	}
	else if (a<0)
	{
		if (n%2==0)
		{
			cout << "ERROR";
		}
		else {
			x0 = 1;
			cout << "\n";
			/*for (int i = 0; i < 10000; i++)
			{*/
			x1 = pow(n, -1) * ((n - 1) * x0 + (a / pow(x0, n - 1)));
			xend = x1;
			x0 = x1;
			while (true)
			{
			x1 = pow(n, -1) * ((n - 1) * x0 + (a / pow(x0, n - 1)));

			if (x0 / x1 <= e)
			{
				break;
			}
				xend = x1;
				x0 = x1;
				
			
			}
			/*x0 = x1;
			e = e - 1;
			x0 = x0 / e;
			x0 = (int)x0;
			x0 = x0 * e;
			x1 = x0;*/
			cout << n << (unsigned char)251 << a << " = " <<  x1;
		}
	}
	else {

	
	x0 = 1;
	cout << "\n";
	/*for (int i = 0; i < 10000; i++)
	{
		x1 = pow(n, -1)*((n - 1)*x0+(a/pow(x0, n-1)));
		xend = x1;
		x0 = x1;
	}*/
	x1 = pow(n, -1) * ((n - 1) * x0 + (a / pow(x0, n - 1)));
	xend = x1;
	x0 = x1;
	while (true)
	{
		x1 = pow(n, -1) * ((n - 1) * x0 + (a / pow(x0, n - 1)));

		if (x0 / x1 <= e)
		{
			break;
		}
			xend = x1;
			x0 = x1;
		
	}
	/*x0 = x1;
	e = e - 1;
	x0 = x0 / e;
	x0 = (int)x0;
	x0 = x0 * e;
	x1 = x0;*/
	cout << n << (unsigned char)251 << a << " = " << x1;
	}
	}
}

//<< fixed << setprecision(count)



