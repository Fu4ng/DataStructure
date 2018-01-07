/*
	Name: .分别实现二分查找的递归与非递归算法.
	Copyright: 
	Author: Junlong
	Date: 06/01/18 15:26
	Description: 
*/

#include <iostream>
using namespace std;
int BTS(int w[],int a,int left,int right){
	
	if(left<=right){
		int mid = (left + right)/2;
		if(w[mid]==a) return mid;
		else{
			if(w[mid]>a)
				return BTS(w,a,left,mid-1);
			if(w[mid]<a)
				return BTS(w,a,mid+1,right);
		}
	}
}
int BTS_D(int w[],int a,int left,int right){
	while(left<right){
		int mid = (left+right)/2;
		if(a==w[mid]) return mid;
		else if(a<w[mid]) right=mid-1;
		else if(a>w[mid]) left = mid+1;
	}
}

int main(){
	int w[5] ={1,2,3,4,5};
	int i = BTS(w,2,0,4);
	cout<<i;
	
} 
