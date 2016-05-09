#include<iostream>
using namespace std;

void AdjustDown(int a[],int n,int k)  //���µ���
{
    int temp=a[k];
    for(int i=2*k+1;i<n;i=i*2+1)
    {
        if(i<n-1&&a[i]<a[i+1])   //ѡȡ���������нϴ���
            i++;
        if(temp>=a[i])break;
        else
        {
            a[k]=a[i];
            k=i;
        }
    }
    a[k]=temp;
}

void MakeHeap(int a[],int n)  //�����󶥶�
{
    for(int i=n/2-1;i>=0;--i)
        AdjustDown(a,n,i);
}



void HeapSort(int a[],int n)
{
    MakeHeap(a,n);
    for(int i=n-1;i>=0;--i)
    {
        cout<<a[0]<<" ";   //�Ѷ�Ϊ���ֵ
        int temp=a[0];
        a[0]=a[i];    //�����һ���ڵ㽻��
        a[i]=temp;
        AdjustDown(a,i,0);   //�����Ѷ�
    }
}

int main()
{
    int a[]={3,6,1,8,3,2,5,4,9,-2,5,12,6,3,9};
    int n=sizeof(a)/sizeof(int);
    HeapSort(a,n);
    return 0;
}
