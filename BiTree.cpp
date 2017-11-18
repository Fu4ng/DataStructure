#include<iostream>
using namespace std;
typedef  char TElemType;


//链表存储 
typedef struct BiTNode{
	TElemType data;                  
	struct BiTNode *lchild;
	struct BiTNode *rchild;  
}BiTNode,*BiTree;

//建立
void CreateBiTree(BiTree &T){
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
		CreateBiTree(T->lchild);
		CreateBiTree(T->rchild);
	} 
} 

//中序
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
 
 //先序
void PreOrder(BiTree T){
 	if(T!=NULL)
 	{	
	 	cout<<T->data<<endl;
		PreOrder(T->lchild);
		PreOrder(T->rchild);
	}
	else cout<<endl;
}
 
  //后序
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
	cout<<"中序递归遍历："<<endl;  
  	InOrder(T);  
	cout<<"先序递归遍历："<<endl;  
	PreOrder(T);  

	cout<<"后序递归遍历："<<endl;  
    PosOrder(T);  
  	return 0;
}  
