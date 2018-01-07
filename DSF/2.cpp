/*
	Name: 1. ��������й�˳�����㷨:
(1) SqList  CreateSqList(int n): nΪ˳����Ԫ�ظ���,����Ԫ��ֵ�ɼ����������,������  �������ɵ�˳���.
(2)void InsertSq(SqList& L, ElemType x,int pos): ��Ԫ��x���뵽˳���L�е�pos��(pos>=1).
(3)ElemType  DeleteSq(SqList& L, int pos):ɾ��˳���Lλ��pos����Ԫ��,����ɾ��Ԫ��ֵ.
(4)��Ʋ��Գ���.
	Author: JunLong 
	Date: 05/01/18 13:21
	Description: 
*/
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
    	cout<<"�����"<<t<<"��ֵ��";
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
