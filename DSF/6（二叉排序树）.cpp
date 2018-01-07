/*
	Name: 二叉排序树 
	Author: JunLong 
	Date: 06/01/18 15:16
	Description: 
*/
#include<iostream>
using namespace std;
typedef struct BSTNode{
	int data;
	struct BSTnode *lchild,*rchild;
}BSTNode,*BSTPtr;

void MinBS(BSTPtr &B){  //查找二叉排序树中的最小数据元素并删除它
	if(!B->lchild){
		cout<<B->data<<endl;
		BSTPtr p =new BSTNode;
		p = B; delete p;
	}
	else MinBS(B->lchild);
} 
void InsertBST(BSTree &T,int e){ //插入 
	if(!T){
		BSTPtr s =new BSTNode;
		s->data=i;
		s->lchild=NULL;
		s->rchild=NULL;
	}
	else if(i<T->data) InsertBST(T->lchild,i);
	else if(i>T->data) InsertBST(T->rchild,i);
}
void CtreateBST(BSTPtr &T){
	T =NULL;
	int i;              //初始化
	cout<<"输入值（输入#，代表空节点）：";
	cin>>i;
	while(i!='#'){
		InsertBST(T,i);
		cin>>e;06/01/18 15:16
	} 
} 
int main(){
	
}
