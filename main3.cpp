//�����ο���С���飬2016/3/14
//�����ơ�����
//��������������㣬�����ж��û������Ƿ���ȷ�Լ������������ܸ���������������������ʽ��

#include<stack>
#include<iostream>
#include<string>
#include<sstream>
#include<time.h>
#include<iomanip>
#include<fstream>
using namespace std;

int check_1(int a)//�ж��û������Ƿ����Ҫ��
{
	if (a != 1 && a != 0)
	{
		cout << "�����ʽ����ȷ�����������룺";
		cin >> a;
	}
	return 0;
}
int check_2(int a)
{
	if (a <= 0)
	{
		cout << "�����ʽ����ȷ�����������룺";
		cin >> a;
	}
	return 0;
}

string change(int num0)//�����ʽת��Ϊ�ַ�������
{
	char str[100];
	_itoa_s(num0, str, 10);
	string str1 = str;
	return str1;
}

int judge(char c1, char c2)//����+.-.*./.(.)�����ȵȼ�
{
	int a1, a2;
	if ('+' == c1 || '-' == c1) a1 = 3;
	if ('*' == c1 || '/' == c1)a1 = 5;
	if ('(' == c1) a1 = 1;
	if (')' == c1) a1 = 7;
	if ('#' == c1) a1 = 0;
	if ('+' == c2 || '-' == c2)a2 = 2;
	if ('*' == c2 || '/' == c2)a2 = 4;
	if ('(' == c2) a2 = 6;
	if (')' == c2) a2 = 1;
	if ('#' == c2) a2 = 0;
	if (a1>a2) return 1;
	if (a1 == a2) return 0;
	if (a1<a2) return -1;
}
//�������㺯��
double run(char c, double d1, double d2)//������������
{
	switch (c)
	{
	case '+':
		return d1 + d2;
		break;
	case '-':
		return d1 - d2;
		break;
	case'*':
		return d1*d2;
		break;
	case '/':
		return d1/d2;
		break;
	default:
		return 0.0;
		break;
	}
}
double calculate(string str4)//������ʽ��ֵ
{
	char * op = "+-*/()#";
	//�����ʽ�ַ���str���'#'������ʶ��
	str4.append(1, '#');
	stack<char> OPTR;//�����ջ
	stack<double> OPND;//������ջ
	int a = -1;
	//�Ƚ�#������ջ
	OPTR.push('#');
	while (true)
	{
		int b = a + 1;
		a = str4.find_first_of(op, a + 1);
		if (a == string::npos) break;
		if (a != b)
		{
			string ss(str4, b, a - b);
			double d = atof(ss.c_str());
			//��������ջ
			OPND.push(d);
		}
		//��������ȼ��Ƚ�
		int ju = judge(OPTR.top(), str4[a]);
		if (-1 == ju)//ջ�����ȼ���ֱ����ջ
		{
			OPTR.push(str4[a]);
		}
		if (0 == ju)//ջ�������ȼ�������ջ
		{
			OPTR.pop();
		}
		if (1 == ju)//ջ�����ȼ���,��ջ��������
		{
			double d1 = OPND.top();
			OPND.pop();
			double d2 = OPND.top();
			OPND.pop();
			d1 = run(OPTR.top(), d2, d1);
			//��������ջ
			OPND.push(d1);
			OPTR.pop();
			a--;
		}
	}
	//ɾ�����ʽ����'#'������ʶ��
	str4.erase(str4.length() - 1, 1);
	return  OPND.top();
}
int main()//������
{
	srand((unsigned)time(NULL));//ʱ������
	int max, num, choose_way, choose_chengchu,choose_minus, choose_brackets;
	int num_suanshi;
	double input_result;
	int count = 0;
	int len;//���ַ�������
	ofstream fout("1.txt");//������ļ�

	cout << "����������������ֵ��";
	cin >> max;
	int k = check_2(max);

	cout << "���������ɵ���Ŀ������";
	cin >> num;
	int k1 = check_2(num);

	cout << "��ѡ�������ʽ(1���������Ļ 0��������ļ�)��";
	cin >> choose_way;
	int k2 = check_1(choose_way);

	cout << "�Ƿ��г˳���(1���� 0��û��)��";
	cin >> choose_chengchu;
	int k3 = check_1(choose_chengchu);

	switch (choose_chengchu)
	{
	case 1:

		break;
	case 0:
		cout << "��ѡ��Ӽ��Ƿ��и�����1���� 0��û�У���";
		cin >> choose_minus;
		int k5 = check_1(choose_minus);
		break;
	}
	
	cout << "��ѡ���Ƿ������ţ�1���� 0��û�У���";
	cin >> choose_brackets;
	int k6 = check_1(choose_brackets);

	cout<<"��ѡ��һ��������ٸ���ʽ��";
	cin>>num_suanshi;
	char sym[4] = { '+', '-', '*', '/' };
	double result[1000];
	double result1[1000];
	int i;
	for (i = 0; i < num; i++)
	{
		int oper_num = rand() % 8 + 1;//һ��ʽ���к��м�����
		string str_1, str_2_1, str_3;
		int num1 = rand() % (max + 1)+1;
		int num2 = rand() % (max + 1)+1;
		int d;
		switch (choose_chengchu)//�Ƿ��г˳�
		{
		case 1:
			d = rand() % 4;
			break;
		case 0:
			d = rand() % 2;
			break;
		}
		str_1 = change(num1) + sym[d] + change(num2);
		for (int j = 0; j < oper_num; j++)
		{
			int c;
			int num3 = rand() % (max + 1)+1;
			switch (choose_chengchu)//�Ƿ��г˳�
			{
			case 1:
				c = rand() % 4;
				break;
			case 0:
				c = rand() % 2;
				break;
			}
			str_1 = str_1 + sym[c] + change(num3);
			int b;
			b = rand() % 2;
			switch (choose_brackets)//�ж��Ƿ�������
			{
			case 1://������ʱ�����������
				if (b == 0)
				{
					str_1 = '(' + str_1 + ')';
				}
				if (b == 1)
				{
					str_1 = str_1;
				}
				break;
			case 0://ѡ��������ʱ
				break;
			}
			str_3 = str_1;
		}
		result[i]= calculate(str_3);//����calculate������������������ʽ�Ľ��
		switch (choose_chengchu)
		{
		case 1://�г˳�
			break;
		case 0://û�г˳�
			switch (choose_minus)
			{
			case 1://�и���
				break;
			case 0://û�и���
			panduan :
				if (result[i]<0)//�Ӽ���������б�֤����޸���
				{
					for (int j = 0; j<oper_num; j++)
					{
						int num2_1 = rand() % (max + 1)+1;
						int d1;
						d1 = rand() % 2;
						str_1 = change(num2_1) + sym[d1];
						str_2_1 = str_2_1 + str_1;
						int num3 = rand() % (max + 1);
						str_3 = str_2_1 + change(num3) ;
						result[i] = calculate(str_3);
						goto panduan;
					}
				}
				break;
			}
			break;
		}
		len=sizeof(str_3);
		int m=40-len;
		result1[i]= calculate(str_3);
		str_3=change(i+1)+"��"+str_3+"=";

		if((int(result1[i])-result1[i])!=0)//������������½����������λС��
		{
			result1[i]=result1[i]*100+0.5;
			result1[i]=int(result1[i]);
			result1[i]=result1[i]/100;
		}
		switch (choose_way)//ѡ�������ʽ
		{
		case 1://�������Ļ
			cout.flags(ios::left);
			cout <<setw(40)<<str_3 ;
			if((i+1)%num_suanshi==0)
				cout<<endl;
			break;
		case 0://������ļ�
			fout.flags(ios::left);
			fout <<setw(40)<<str_3 ;
			if((i+1)%num_suanshi==0)
				fout<<endl;
			break;
		} 
	}
	cout<<"������ʽ�ӵĴ𰸣�"<<endl;
	for(i=0;i<num;i++)
	{
		cout<<i+1<<"��";
		cin >> input_result;//�û�����ļ�����
		if (((result1[i]-0.05)<input_result)&&(input_result<(result1[i]+0.05)))
		{
			cout << "������ȷ��" << endl;
			count = count + 1;
		}
		else
			cout << "�������" << endl;
	}
	cout << "���ܹ�������ĸ����ǣ�";
	cout << count << endl;
	return 0;
}
