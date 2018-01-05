#include <iostream>
using namespace std;
typedef int ElemType;
typedef struct LNode{
    ElemType data;
    struct  LNode *next;
}LNode, *LinkList;

LinkList CreateLinkList(int n){
	LinkList L = new LNode;
    L->next = NULL;
    LinkList r = L;
    LinkList p; 
    int t =0; 
    while(t++<n){
    	p = new LNode;
    	cout<<"输入第"<<t<<"个值：";
		cin>>p->data;
		p->next =NULL;
		r->next = p;
		r = p;
	}
	return L; 
}

void InsertSq(LinkList& L,ElemType x,int pos){
	LinkList p = L;
	while(pos--) p=p->next;
    LinkList q =new LNode;
    q->data = x;
    q->next = p->next;
    p->next =q;

}
ElemType DeleteL(LinkList& L, int pos){
	LinkList q;
    LinkList p =L;
    int i =0;
	for(;i<pos;i++){
		p = p->next;
	}
    q = p->next;
    p->next = p->next->next;
    return q->data;
}
int main(){
		LinkList L = CreateLinkList(5);
		InsertSq(L,7,2);
		LinkList p =L;
		for(int i=0;i<7;i++){
			if(i==0) p= p->next;
			else{
				cout<<p->data;
				p=p->next;
			}
		}
		cout<<endl;
		cout<<DeleteL(L,2);
} 
