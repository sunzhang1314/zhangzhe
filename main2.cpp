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
	cout << "������ȡֵ��Χ[n,m]:";
	cin >> min >> max;
	cout << "������������Ŀ������";
	cin >> y;
	cout << "��ѡ���ӡ��ʽ��1���������Ļ��0����ӡ���ļ�����������Ӧ��ţ�";
	cin >> s;
	cout << "��ѡ���Ƿ��г˳����㣺1���ǣ�0������������Ӧѡ�����ţ�";
	cin >> x;
	cout << "��ѡ��Ӽ����Ƿ��и�����1���ǣ�0����";
	cin >> z;
	cout << "��ѡ������Ƿ���������1���ǣ�0����";
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