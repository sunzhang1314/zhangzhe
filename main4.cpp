//����һ���������������������ĺ�
//���������и�����������������һ�������������һ�������飬ÿ�������鶼��һ���͡�ʱ�临�Ӷ�O(n)
//���ܡ������� 2016/3/22

#include<iostream>
#include<time.h>
using namespace std;

int main()
{
	//srand((unsigned)time(NULL));
	int num,*arr;
	int sum=0;
	cout<<"����������Ԫ�ظ�����";
	cin>>num;
	arr=new int[num];
	if(arr==NULL)
	{
		cout<<"����ռ�ʧ�ܣ�"<<endl;
		return 1;
	}
    cout<<"����������Ԫ�ص�ֵ��";
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
	cout<<"������͵����ֵΪ��"<<max<<endl;
	delete [] arr;
	return 0;
}