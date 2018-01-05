
#include <iostream>
using namespace std;
int main(){
		
		/*算法一，时间复杂度为O(1) 
				输入N的值，
				建立一个具有N元素的数组*/
		int n;
		cout<<"输入n:";
		cin>>n;
		int *m = new int[n]; 
		
		/*算法二  时间复杂度为O(n)
				给数组M赋值*/
		for(int i=0;i<n;i++){
			m[i]=i;
		} 
		
		/*算法三 时间复杂度为O(logn)
				在数组中，查找一个小于N的数字*/
		int search ;
		cout<<"输入要查找的数：";
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
				cout<<endl<<search<<"下标为"<<mid;
				break;
			}
		} 
} 
