/*
	Name: 1.��ѭ�����зֱ�ʵ�����¼�������:
(1)��������  (2)���   (3)����   (4)�п�

	Copyright: 
	Author: JunLong
	Date: 05/01/18 15:48
	Description: 
*/

#include<iostream>
using namespace std; 
#define MAXSIZE 6
#define QElemType int 
typedef struct{     
	QElemType *base; //�洢�ռ��ַ   
	int front;     
 	int rear;  
}SqPtr;
void InitSq(SqPtr q){
	q.base = new QElemType [MAXSIZE];
	if(!q.base) {
		cout<<"�������";
		return;
	}
	q.front = 0;
	q.rear = 0;
}
bool IsEmpty(SqPtr q){
	 return q.front == q.rear;
}
void EnSq(SqPtr q, QElemType e){
    if( (q.rear+1)%MAXSIZE == q.front )
    {
        cout<<"����"; 
        return;
    }
    q.rear = (q.rear+1) % MAXSIZE;
    q.base[q.rear] = e; 
}
QElemType DeSq(SqPtr q){    
  	if(IsEmpty(q)){
        cout<<"�ӿ�"; 
        return -1;
    }
    else {
        q.front = (q.front+1) % MAXSIZE;
        return q.base[q.front];
    }
} 


int main(){
	
	SqPtr q;
	InitSq(q);
	cout<<IsEmpty(q);
	for(int i =0;i<5;i++) EnSq(q,i);
	cout<<DeSq(q);
}
