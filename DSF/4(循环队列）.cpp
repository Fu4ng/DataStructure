/*
	Name: 1.对循环队列分别实现如下几个操作:
(1)创建队列  (2)入队   (3)出队   (4)判空

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
	QElemType *base; //存储空间基址   
	int front;     
 	int rear;  
}SqPtr;
void InitSq(SqPtr q){
	q.base = new QElemType [MAXSIZE];
	if(!q.base) {
		cout<<"分配出错";
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
        cout<<"队满"; 
        return;
    }
    q.rear = (q.rear+1) % MAXSIZE;
    q.base[q.rear] = e; 
}
QElemType DeSq(SqPtr q){    
  	if(IsEmpty(q)){
        cout<<"队空"; 
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
