/*
	Name: 1. 设计如下有关顺序表的算法:
(1) SqList  CreateSqList(int n): n为顺序表的元素个数,各个元素值由键盘随机输入,函数返  回所生成的顺序表.
(2)void InsertSq(SqList& L, ElemType x,int pos): 将元素x插入到顺序表L中的pos处(pos>=1).
(3)ElemType  DeleteSq(SqList& L, int pos):删除顺序表L位置pos处的元素,返回删除元素值.
(4)设计测试程序.
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
