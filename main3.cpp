//第三次课堂小测验，2016/3/14
//张晓菲、张哲
//随机生成四则运算，可以判断用户输入是否正确以及输出做对题的总个数；处理四则运算混合算式；

#include<stack>
#include<iostream>
#include<string>
#include<sstream>
#include<time.h>
#include<iomanip>
#include<fstream>
using namespace std;

int check_1(int a)//判断用户输入是否符合要求
{
	if (a != 1 && a != 0)
	{
		cout << "输入格式不正确，请重新输入：";
		cin >> a;
	}
	return 0;
}
int check_2(int a)
{
	if (a <= 0)
	{
		cout << "输入格式不正确，请重新输入：";
		cin >> a;
	}
	return 0;
}

string change(int num0)//将表达式转换为字符串类型
{
	char str[100];
	_itoa_s(num0, str, 10);
	string str1 = str;
	return str1;
}

int judge(char c1, char c2)//设置+.-.*./.(.)的优先等级
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
//符号运算函数
double run(char c, double d1, double d2)//计算四则运算
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
double calculate(string str4)//计算表达式的值
{
	char * op = "+-*/()#";
	//给表达式字符串str添加'#'结束标识符
	str4.append(1, '#');
	stack<char> OPTR;//运算符栈
	stack<double> OPND;//操作数栈
	int a = -1;
	//先将#符号入栈
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
			//数据先入栈
			OPND.push(d);
		}
		//运算符优先级比较
		int ju = judge(OPTR.top(), str4[a]);
		if (-1 == ju)//栈外优先级大直接入栈
		{
			OPTR.push(str4[a]);
		}
		if (0 == ju)//栈内外优先级相等则出栈
		{
			OPTR.pop();
		}
		if (1 == ju)//栈内优先级大,出栈进行运算
		{
			double d1 = OPND.top();
			OPND.pop();
			double d2 = OPND.top();
			OPND.pop();
			d1 = run(OPTR.top(), d2, d1);
			//运算结果入栈
			OPND.push(d1);
			OPTR.pop();
			a--;
		}
	}
	//删除表达式最后的'#'结束标识符
	str4.erase(str4.length() - 1, 1);
	return  OPND.top();
}
int main()//主函数
{
	srand((unsigned)time(NULL));//时间种子
	int max, num, choose_way, choose_chengchu,choose_minus, choose_brackets;
	int num_suanshi;
	double input_result;
	int count = 0;
	int len;//求字符串长度
	ofstream fout("1.txt");//输出到文件

	cout << "请输入允许的最大数值：";
	cin >> max;
	int k = check_2(max);

	cout << "请输入生成的题目个数：";
	cin >> num;
	int k1 = check_2(num);

	cout << "请选择输出方式(1、输出到屏幕 0、输出到文件)：";
	cin >> choose_way;
	int k2 = check_1(choose_way);

	cout << "是否有乘除法(1、有 0、没有)：";
	cin >> choose_chengchu;
	int k3 = check_1(choose_chengchu);

	switch (choose_chengchu)
	{
	case 1:

		break;
	case 0:
		cout << "请选择加减是否有负数（1、有 0、没有）：";
		cin >> choose_minus;
		int k5 = check_1(choose_minus);
		break;
	}
	
	cout << "请选择是否有括号（1、有 0、没有）：";
	cin >> choose_brackets;
	int k6 = check_1(choose_brackets);

	cout<<"请选择一行输出多少个算式：";
	cin>>num_suanshi;
	char sym[4] = { '+', '-', '*', '/' };
	double result[1000];
	double result1[1000];
	int i;
	for (i = 0; i < num; i++)
	{
		int oper_num = rand() % 8 + 1;//一个式子中含有几个数
		string str_1, str_2_1, str_3;
		int num1 = rand() % (max + 1)+1;
		int num2 = rand() % (max + 1)+1;
		int d;
		switch (choose_chengchu)//是否有乘除
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
			switch (choose_chengchu)//是否有乘除
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
			switch (choose_brackets)//判断是否有括号
			{
			case 1://有括号时随机产生括号
				if (b == 0)
				{
					str_1 = '(' + str_1 + ')';
				}
				if (b == 1)
				{
					str_1 = str_1;
				}
				break;
			case 0://选择无括号时
				break;
			}
			str_3 = str_1;
		}
		result[i]= calculate(str_3);//调用calculate函数计算四则运算表达式的结果
		switch (choose_chengchu)
		{
		case 1://有乘除
			break;
		case 0://没有乘除
			switch (choose_minus)
			{
			case 1://有负数
				break;
			case 0://没有负数
			panduan :
				if (result[i]<0)//加减混合运算中保证结果无负数
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
		str_3=change(i+1)+"、"+str_3+"=";

		if((int(result1[i])-result1[i])!=0)//除不尽的情况下将结果保留两位小数
		{
			result1[i]=result1[i]*100+0.5;
			result1[i]=int(result1[i]);
			result1[i]=result1[i]/100;
		}
		switch (choose_way)//选择输出方式
		{
		case 1://输出到屏幕
			cout.flags(ios::left);
			cout <<setw(40)<<str_3 ;
			if((i+1)%num_suanshi==0)
				cout<<endl;
			break;
		case 0://输出到文件
			fout.flags(ios::left);
			fout <<setw(40)<<str_3 ;
			if((i+1)%num_suanshi==0)
				fout<<endl;
			break;
		} 
	}
	cout<<"请输入式子的答案："<<endl;
	for(i=0;i<num;i++)
	{
		cout<<i+1<<"、";
		cin >> input_result;//用户输入的计算结果
		if (((result1[i]-0.05)<input_result)&&(input_result<(result1[i]+0.05)))
		{
			cout << "输入正确！" << endl;
			count = count + 1;
		}
		else
			cout << "输入错误！" << endl;
	}
	cout << "您总共做对题的个数是：";
	cout << count << endl;
	return 0;
}
