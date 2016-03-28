//返回一个整数数组中最大子数组的和
//有正数、有负数、数组中连续的一个或多个整数组成一个子数组，每个子数组都有一个和、将数组首尾相连、返回最大子数组的位置
//张哲、张晓菲 2016/3/22

#include<iostream>
using namespace std;
#define N 10000

int main()
{
	int num,arr[N];
	int sum=0;
	cout<<"请输入数组元素个数：";
	cin>>num;
    cout<<"请输入数组元素的值：";
	for(int i=0;i<num;i++)//输入环状数组的元素值
	{
		cin>>arr[i];
	}
	for(int i=num;i<(2*num-1);i++)//将环抻直，例如环状数组值原先为[A,B,C,D],那么抻直之后为[A,B,C,D,A,B,C]
	{
		arr[i]=arr[i%num];
	}
	cout<<"环抻直之后的数组相当于："<<endl;
	for(int i=0;i<(2*num-1);i++)
	{
		cout<<arr[i]<<" ";
	}
	cout<<endl;

	int max=arr[0];
	int end,start,cstart;//end为结束位置 start为起始位置

	//求子数组最大和
	for(int j=0;j<num;j++)
	{
		sum=0;
		for(int i=j;i<j+num;i++)
		{
			if(sum<=0)
			{
				sum=arr[i];
				cstart=i;//当前最大子数组的起始位置
			}
			else
				sum=sum+arr[i];
			if(sum>max)
			{
				max=sum;
				start=cstart;
				end=i;
			 }
		}
	}

	cout<<"子数组和的最大值为："<<max<<endl;
	cout<<"最大子数组的起始位置为环抻直后的第"<<start+1<<"个元素，结束位置为环抻直后的第"<<end+1<<"个元素。"<<endl;
	return 0;
}