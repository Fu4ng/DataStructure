#include<iostream>
using namespace std;
typedef  char TElemType;


//����洢 
typedef struct BiTNode{
	TElemType data;                  
	struct BiTNode *lchild;
	struct BiTNode *rchild;  
}BiTNode,*BiTree;

//����
void CreateBiTree(BiTree &T){
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
		CreateBiTree(T->lchild);
		CreateBiTree(T->rchild);
	} 
} 

//����
void InOrder(BiTree T)
{
	if(T!=NULL)
	{
		InOrder(T->lchild);
		cout<<T->data<<endl;
		InOrder(T->rchild);
	}
	else cout<<endl;
}
 
 //����
void PreOrder(BiTree T){
 	if(T!=NULL)
 	{	
	 	cout<<T->data<<endl;
		PreOrder(T->lchild);
		PreOrder(T->rchild);
	}
	else cout<<endl;
}
 
  //����
void PosOrder(BiTree T){
 	if(T!=NULL)
 	{	
		PosOrder(T->lchild);
		PosOrder(T->rchild);
		cout<<T->data<<endl;
	}
	else cout<<endl;
 }
 
int main(){  
	
	BiTree T;
	CreateBiTree(T);
	cout<<"����ݹ������"<<endl;  
  	InOrder(T);  
	cout<<"����ݹ������"<<endl;  
	PreOrder(T);  

	cout<<"����ݹ������"<<endl;  
    PosOrder(T);  
  	return 0;
}  
