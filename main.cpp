#include<iostream>
#include<stdio.h>
#include<time.h>
using namespace std;

void main()
{
	int i, j, n;
	srand((unsigned)time(NULL));
	for (j = 0; j < 30; j++)
	{
		int a = rand() % 100;
		int b = rand() % 100;
		int c = rand() % 100;
		int d = rand() % 100;
		int e = rand() % 100;
		i = c % 4;
		n = e % 2;
		if (i == 0)
		{
			if (n == 0)
				cout << a << "+" << b << "=" << endl;
			if (n == 1)
			{
				if (a < b)
				{
					if (c < d)
						cout << a << "/" << b << " + " << c << "/" << d << "=" << endl;
					else
						cout << a << "/" << b << " + " << d << "/" << c << "=" << endl;
				}
				else
				{
					if (c < d)
						cout << b << "/" << a << " + " << c << "/" << d << "=" << endl;
					else
						cout << b << "/" << a << " + " << d << "/" << c << "=" << endl;
				}

			}

		}
		else if (i == 1)
		{
			if (n == 0)
				cout << a << "-" << b << "=" << endl;
			if (n == 1)
			{
				if (a < b)
				{
					if (c < d)
						cout << a << "/" << b << " - " << c << "/" << d << "=" << endl;
					else
						cout << a << "/" << b << " - " << d << "/" << c << "=" << endl;
				}
				else
				{
					if (c < d)
						cout << b << "/" << a << " - " << c << "/" << d << "=" << endl;
					else
						cout << b << "/" << a << " - " << d << "/" << c << "=" << endl;
				}
			}
		}
		else if (i == 2)
		{
			if (n == 0)
				cout << a << "*" << b << "=" << endl;
			if (n == 1)
			{
				if (a < b)
				{
					if (c < d)
						cout << a << "/" << b << " * " << c << "/" << d << "=" << endl;
					else
						cout << a << "/" << b << " * " << d << "/" << c << "=" << endl;
				}
				else
				{
					if (c < d)
						cout << b << "/" << a << " * " << c << "/" << d << "=" << endl;
					else
						cout << b << "/" << a << " * " << d << "/" << c << "=" << endl;
				}
			}
		}

		else if (i == 3)
		{
			if (n == 0)
				cout << a << "/" << b << "=" << endl;
			if (n == 1)
			{
				if (a < b)
				{
					if (c < d)
						cout << a << "/" << b << " / " << c << "/" << d << "=" << endl;
					else
						cout << a << "/" << b << " / " << d << "/" << c << "=" << endl;
				}
				else
				{
					if (c < d)
						cout << b << "/" << a << " / " << c << "/" << d << "=" << endl;
					else
						cout << b << "/" << a << " / " << d << "/" << c << "=" << endl;
				}
			}
		}
	}
}
			

		

