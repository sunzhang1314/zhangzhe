//����һ���������������������ĺ�
//���������и�����������������һ�������������һ�������飬ÿ�������鶼��һ���͡���������β��������������������λ��
//���ܡ������� 2016/3/22

#include<iostream>
using namespace std;
#define N 10000

int main()
{
	int num,arr[N];
	int sum=0;
	cout<<"����������Ԫ�ظ�����";
	cin>>num;
    cout<<"����������Ԫ�ص�ֵ��";
	for(int i=0;i<num;i++)//���뻷״�����Ԫ��ֵ
	{
		cin>>arr[i];
	}
	for(int i=num;i<(2*num-1);i++)//������ֱ�����绷״����ֵԭ��Ϊ[A,B,C,D],��ô��ֱ֮��Ϊ[A,B,C,D,A,B,C]
	{
		arr[i]=arr[i%num];
	}
	cout<<"����ֱ֮��������൱�ڣ�"<<endl;
	for(int i=0;i<(2*num-1);i++)
	{
		cout<<arr[i]<<" ";
	}
	cout<<endl;

	int max=arr[0];
	int end,start,cstart;//endΪ����λ�� startΪ��ʼλ��

	//������������
	for(int j=0;j<num;j++)
	{
		sum=0;
		for(int i=j;i<j+num;i++)
		{
			if(sum<=0)
			{
				sum=arr[i];
				cstart=i;//��ǰ������������ʼλ��
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

	cout<<"������͵����ֵΪ��"<<max<<endl;
	cout<<"������������ʼλ��Ϊ����ֱ��ĵ�"<<start+1<<"��Ԫ�أ�����λ��Ϊ����ֱ��ĵ�"<<end+1<<"��Ԫ�ء�"<<endl;
	return 0;
}