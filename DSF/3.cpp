#include <iostream>
using namespace std;
#define MAXQSIZE 6
typedef int QElemType; 
typedef struct{
	QElemType *base;
	int front;
	int rear ; //尾巴 
}SqQueue;
bool IsEmpty(SqQueue q){//判空
	if(q.front==q.rear) return 1;
	else return 0; 
}
void InitQueue(SqQueue &q){//创建队列 
	q.base=new QElemType[MAXQSIZE];
	if(!q.base) return ;//分配失败
	q.front = 0;q.rear=0; 
}
void EnQueue(SqQueue &q,QElemType e){//入队 
	if((q.rear +1)%MAXQSIZE==q.front)  //队满 
		return ;
	q.base[q.rear] =e;
	q.rear=(q.rear+1)%MAXQSIZE;
} 
void DeQueue(SqQueue &q){//出队
	 	if(IsEmpty(q))  //队空
	 	return ;
	 	
		q.front = (q.front+1)%MAXQSIZE; 
	 	
}

int main(){
	SqQueue q;
	InitQueue(q);
	cout<<IsEmpty(q)<<endl;
	for(int i=0;i<5;i++) EnQueue(q,i);
	for(int i=0;i<5;i++) {
		cout<<q.base[i];
		DeQueue(q);
	}
	cout<<endl;
	cout<<IsEmpty(q)<<endl;
	
} 
