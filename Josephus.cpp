//
// Created by Fu4ng on 2017/10/12.
//
#include <iostream>
using namespace std;
typedef int ElemType;

typedef struct LNode{
    ElemType data;
    struct  LNode *next;
}LNode, *LinkList;

void InitList(LinkList &L){
    L = new LNode;
    L->next = NULL;
}
void CreateList(LinkList &L,int n){
    InitList(L);
    LinkList r = L;
    for (int i = 1; i <=n ; ++i) {
        LinkList p = new LNode;
        cin>>p->data;
        p->next=NULL;
        r->next = p;
        r=p;
    }
    r->next=L->next;
}

void ScanLink(LinkList &L,int n){

	LinkList temp;
    LinkList p = L->next;
   	int count = n;
    while(p!=p->next){
        for (int i = 0; i <count-1 ; ++i)
        {
        	temp = p;
        	p = p->next;
		}
		count=p->data;
		cout<<count<<endl;
		temp->next = p->next;
		delete(p);
		p = temp->next; 
    }
    cout<<p->data<<endl;
    
}

