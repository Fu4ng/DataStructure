#include<iostream>
using namespace std;
typedef int Elemtype;
#define MAXSIZE 100 
//顺序栈的表示和实现 

typedef struct sqstack{
	Elemtype *base;
	Elemtype *top;
	int stacksize;
}sqstack;

sqstack InitStack(sqstack s){
	s.base = new Elemtype[MAXSIZE];
	if(!s.base) ;//
	s.top=s.base;
	s.stacksize = MAXSIZE;
	return s;
}

void Push(sqstack &s,Elemtype e){
	if(s.top-s.base == s.stacksize) ;//
	*s.top++ = e;

}

void Pop(sqstack &s,Elemtype &e){
	if(s.top == s.base) ;//
	e = *(s.top-1);
	s.top--;
}

int GetLength(sqstack s){
	return s.top-s.base;
}

Elemtype GetTop(sqstack s){
	if(s.base == s.top) ;//
	return *(s.top-1);
}


//int main(){
//	sqstack s;
//	s = InitStack(s);
//	int n=0;
//	while(n<5)
//	{
//		Push(s,n);
//		n++;
//	}
//	while(n>0){
//		int e = GetTop(s);
//		cout<<e<<endl;
//		Pop(s,e);
//		n--; 
//	}
//	
//}

typedef struct StackNode{
	Elemtype data;
	struct StackNode *next;
}StackNode,*LinkStack;

void InitLinkStack(LinkStack &s){
	//没必要加头结点,以链表的头部作为栈顶 
	s= NULL;
}

void LSPush(LinkStack &s,Elemtype e){
	//先建立一个节点
	StackNode* p = new StackNode;
	p->data = e;
	p->next = s;
	s=p; 
} 

void Pop2(LinkStack &s){
	LinkStack q = s;
	s = s->next;
	delete q;
}

Elemtype GetTop2(LinkStack s){
	if(s==NULL) cout<<"Empty"<<endl;
	return s->data;
}
int main(){
	LinkStack s;
	InitLinkStack(s);
	int n=0;
	while(n<5){
		LSPush(s,n);
		n++;
	}
	while(n>0){
		cout<<GetTop2(s)<<endl;
		Pop2(s);
		n--;
	}
}

