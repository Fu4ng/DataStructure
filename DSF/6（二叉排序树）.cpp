/*
	Name: ���������� 
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

void MinBS(BSTPtr &B){  //���Ҷ����������е���С����Ԫ�ز�ɾ����
	if(!B->lchild){
		cout<<B->data<<endl;
		BSTPtr p =new BSTNode;
		p = B; delete p;
	}
	else MinBS(B->lchild);
} 
void InsertBST(BSTree &T,int e){ //���� 
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
	int i;              //��ʼ��
	cout<<"����ֵ������#������սڵ㣩��";
	cin>>i;
	while(i!='#'){
		InsertBST(T,i);
		cin>>e;06/01/18 15:16
	} 
} 
int main(){
	
}
