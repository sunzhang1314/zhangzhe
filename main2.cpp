#include<iostream>
#include<fstream>
#include<stdio.h>
#include<time.h>
using namespace std;

void main2()
{
	ofstream outfile;
	outfile.open("aa.txt");
	int x, y, z, s, p, i, j, min, max;
	srand((unsigned)time(NULL));
	cout << "请输入取值范围[n,m]:";
	cin >> min >> max;
	cout << "请输入所需题目个数：";
	cin >> y;
	cout << "请选择打印方式：1、输出到屏幕；0、打印到文件，请输入相应序号：";
	cin >> s;
	cout << "请选择是否有乘除运算：1、是；0、否；请输入相应选择的序号：";
	cin >> x;
	cout << "请选择加减法是否有负数：1、是；0、否：";
	cin >> z;
	cout << "请选择除法是否有余数：1、是；0、否：";
	cin >> p;


	for (j = 1; j <= y; j++)
	{
		int a = rand() % (max - min + 1) + min;
		int b = rand() % (max - min + 1) + min;
		int c = rand() % (max - min + 1) + min;
		if (x == 1)
		{
			i = c % 4;

		}
		if (x == 0)
		{
			i = c % 2;

		}

		if (i == 0)
		{

			if (s == 1)
			{
				cout << a << "+" << b << "=" << endl;
			}
			if (s == 0)
			{
				outfile << a << "+" << b << "=" << endl;
			}


		}
		else if (i == 1)
		{
			if (z == 0)
			{

				if (a > b)
				{

					if (s == 1)
					{
						cout << a << "-" << b << "=" << endl;
					}
					if (s == 0)
					{
						outfile << a << "-" << b << "=" << endl;
					}
				}

				if (a < b)
				{
					if (s == 1)
					{
						cout << b << "-" << a << "=" << endl;
					}
					if (s == 0)
					{
						outfile << b << "-" << a << "=" << endl;
					}

				}

			}

			if (z == 1)
			{
				if (s == 1)
				{
					cout << a << "-" << b << "=" << endl;
				}
				if (s == 0)
				{
					outfile << a << "-" << b << "=" << endl;
				}

			}
		}
		else if (i == 2)
		{

			if (s == 1)
			{
				cout << a << "*" << b << "=" << endl;
			}
			if (s == 0)
			{
				outfile << a << "*" << b << "=" << endl;
			}


		}

		else if (i == 3)
		{
			if (p == 0)
			{
				if (a%b == 0)
				{
					if (s == 1)
					{
						cout << a << "/" << b << "=" << endl;
					}
					if (s == 0)
					{
						outfile << a << "/" << b << "=" << endl;
					}
				}

				else
				{
					int t, u;
					do
					{
						t = rand() % (max - min + 1) + min;
						u = rand() % (max - min + 1) + min;
					} while (t % u != 0);
					if (s == 1)
					{
						cout << t << "/" << u << "=" << endl;
					}
					if (s == 0)
					{
						outfile << t << "/" << u << "=" << endl;
					}
				}
			}

			if (p == 1)
			{
				if (s == 1)
				{
					cout << a << "/" << b << "=" << endl;
				}
				if (s == 0)
				{
					outfile << a << "/" << b << "=" << endl;
				}

			}
		}
	}
}