
#include <iostream>
using namespace std;
int main(){
		
		/*�㷨һ��ʱ�临�Ӷ�ΪO(1) 
				����N��ֵ��
				����һ������NԪ�ص�����*/
		int n;
		cout<<"����n:";
		cin>>n;
		int *m = new int[n]; 
		
		/*�㷨��  ʱ�临�Ӷ�ΪO(n)
				������M��ֵ*/
		for(int i=0;i<n;i++){
			m[i]=i;
		} 
		
		/*�㷨�� ʱ�临�Ӷ�ΪO(logn)
				�������У�����һ��С��N������*/
		int search ;
		cout<<"����Ҫ���ҵ�����";
		cin>>search; 
		int right = n-1;int left = 0;
		int mid;
		while(left<right){
			mid =(left+right)/2;
			if(m[mid]<search)
				left = mid +1;
			if(m[mid]>search)
				right = mid -1;
			else{
				cout<<endl<<search<<"�±�Ϊ"<<mid;
				break;
			}
		} 
} 
