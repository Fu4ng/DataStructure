//Binary tree traversal 

#include<iostream>
 using namespace std;
 typedef char TElemType;
 typedef struct BiTNode{
 	TElemType data;
 	struct BiTNode *lchild,*rchild;
 }BiTNode,*BiTree;
 
 typedef struct TNodeStack{
 	 BiTNode *data;
 	 struct TNodeStack *next;
 }TNodeStack,*TStack;
 
 void CreateBT(BiTree &T){
 	char d;
 	cin>>d;
 	if(d == '#') T=NULL;
	else{
		T = new BiTNode;
		T->data = d;
		CreateBT(T->lchild);
		CreateBT(T->rchild);
	} 
 }
 
void InitTStack(TStack &S){
	S->next = NULL;
}
void Push(TStack &S,BiTree T){
	TStack q = new TNodeStack;
	q->data = T;
	q->next = S;
	S = q; 
}
void Pop(TStack &S){
	if(S->next==NULL); //
	else {
		TStack q = new TNodeStack;
		q = S;
		S = S->next;
		delete q;
		}
}
BiTree Top(TStack S){
	return S->data;
}
bool StackEmpty(TStack S){
	if(S->next==NULL) return 0;
	else return 1; 
} 
void InOrder(BiTree T){
 	if(T){
 		InOrder(T->lchild);
 		cout<<T->data;
 		InOrder(T->rchild);
	 }
	 else
	 	cout<<" ";
 }
 
 void PreOrder(BiTree T){
 	if(T){
 		cout<<T->data;
 		PreOrder(T->lchild);
 		PreOrder(T->rchild);
	 }
	else
	 	cout<<" ";
 }
 
 void PosOrder(BiTree T){
 	if(T){
 		PosOrder(T->lchild);
 		PosOrder(T->rchild);
 		cout<<T->data;
	 }
	else
		cout<<" ";
  
 } 
 void InOrder2(BiTree T){
 	TStack S;
 	InitTStack(S);
 	BiTree q= new BiTNode;
 	q = T;
 	while(StackEmpty(S)||q){
 		while(q){
 		Push(S,q);
 		q = q->lchild;
	 }
	if(StackEmpty(S)){
		q = Top(S);
		Pop(S);
		cout<<q->data<<" ";
		q= q->rchild;
	}
	 }
 }
 void PreOrder2(BiTree T){
 	TStack S;
 	InitTStack(S);
 	BiTree q= new BiTNode;
 	q = T;
 	while(StackEmpty(S) || q){
 		while(q){
 			Push(S,q);
 			cout<<q->data;
 			q = q->lchild; 
		 }
		 if(StackEmpty(S)){
		 	q = Top(S);
			Pop(S);
			q = q->rchild; 
		 }
	 }
 } 
 
void PosOrder2(BiTree T){
	TStack S;
 	InitTStack(S);
 	BiTree q= new BiTNode;
 	q = T;
 	BiTNode *lastVisit;
	while(q){
		Push(S,q);
		q=q->lchild;
	}  
	while(!StackEmpty(S)){
		q = Top(S);
		Pop(S);
		if(q->rchild == NULL || q->rchild == lastVisit){
			cout<<q->data<<" ";
			lastVisit = q; 
		}
		else{
			Push(S,q);
			q = q->rchild;
			while(q){
				Push(S,q);
				q=q->rchild;
			}
		}
	}
}

 int main()
 {
 	BiTree T;
 	CreateBT(T);
 	cout<<"ÖÐÐò£º"; 
 	//InOrder(T);
 	cout<<endl;
 	//InOrder2(T);
 	cout<<endl;
 	
 	cout<<"ÏÈÐò£º";
	//PreOrder(T);
	cout<<endl;
	//PreOrder2(T);
	cout<<endl;
	
	cout<<"ºóÐò£º";
	//PosOrder(T);
	cout<<endl;
	//PosOrder2(T);
	cout<<endl;
 }
