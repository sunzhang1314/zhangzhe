//返回一个整数数组中最大子数组的和
//有正数、有负数、数组中连续的一个或多个整数组成一个子数组，每个子数组都有一个和、时间复杂度O(n)
//张哲、张晓菲 2016/3/22

#include<iostream>
#include<time.h>
using namespace std;

int main()
{
	//srand((unsigned)time(NULL));
	int num,*arr;
	int sum=0;
	cout<<"请输入数组元素个数：";
	cin>>num;
	arr=new int[num];
	if(arr==NULL)
	{
		cout<<"申请空间失败！"<<endl;
		return 1;
	}
    cout<<"请输入数组元素的值：";
	for(int i=0;i<num;i++)
		cin>>arr[i];
		/*arr[i]=r;and()%100;
		cout<<arr[i]<<" ";}*/
	int max=arr[0];
	for(int j=0;j<num;j++)
	{
		if(sum<=0)
			sum=arr[j];
		else
			sum=sum+arr[j];
		if(sum>max)
			max=sum;
	}
	cout<<"子数组和的最大值为："<<max<<endl;
	delete [] arr;
	return 0;
}