/*
	Name: 1.二叉树采用二叉链式存储结构,设计递归算法复制一棵二叉树.
	Copyright: 
	Author: Junlong 
	Date: 05/01/18 17:24
	Description: 
*/

#include <iostream>
using namespace std;
typedef char TElemType;
 typedef struct BiTNode{
 	TElemType data;
 	struct BiTNode *lchild,*rchild;
 }BiTNode,*BiTree;
 
void CreateBT(BiTree &T){
	//先序建立二叉树
	char d; //此时为字符类型 
	cin>>d; 
	if(d=='#') 
	{
		T = NULL;	
	}
	else{
		T = new BiTNode; 
		T->data = d;
		CreateBT(T->lchild);
		CreateBT(T->rchild);
	} 
} 

void CopyBT(BiTree &C,BiTree T){
	if(!T){
		C = NULL;
	}
	else {
		C = new BiTNode;
		C->data = T->data;
		CopyBT(C->lchild,T->lchild);
		CopyBT(C->rchild,T->rchild);
	}
} 
void PreOrder(BiTree T){  //先序输出 
 	if(T!=NULL)
 	{	
	 	cout<<T->data<<endl;
		PreOrder(T->lchild);
		PreOrder(T->rchild);
	}
	else cout<<endl;
}
int main(){
	BiTree T;
	BiTree C;
	CreateBT(T);
	CopyBT(C,T);
	//PreOrder(T);
	PreOrder(C);
	 
	

} 
