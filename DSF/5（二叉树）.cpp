/*
	Name: 1.���������ö�����ʽ�洢�ṹ,��Ƶݹ��㷨����һ�ö�����.
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
	//������������
	char d; //��ʱΪ�ַ����� 
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
void PreOrder(BiTree T){  //������� 
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
