#include<iostream>
#include<cstring>
#include <stdlib.h>
using namespace std;
typedef char Elemtype;
typedef struct  Node{
	Elemtype data;
	struct Node *next;
}Node,*LinkStack;


void InitStack(LinkStack &s){
	s = NULL;
}

void Push(LinkStack &s,Elemtype e){
	LinkStack p =new Node;
	p->data = e;
	p->next=s;
	s=p;
}

void Pop(LinkStack &s){
	LinkStack p =new Node;
	p = s;
	s = s->next;
	delete p;
}
Elemtype GetTop(LinkStack s)
{
	return s->data;
}

//栈的基本操作

bool IsOperate(char p){
	char op[7] = {'+','-','*','/','(',')','#'};
	for(int i = 0;i<7;i++)
		if(p==op[i]) return 1;
	return 0;
} 



char Operate(Elemtype a,Elemtype o,Elemtype b){
	//a,b是运算数，o是运算符
	switch(o)
	{
		case '+' :return a+b;
		case '-' :return a-b;
		case '/' :return b/a;
		case '*' :return a*b;
			 } 
}

char Precede(char a, char b){  
    int i,j;  
    char pre[][7]={           
    /*运算符之间的优先级制作成一张表格*/  
        {'>','>','<','<','<','>','>'},  
        {'>','>','<','<','<','>','>'},  
        {'>','>','>','>','<','>','>'},  
        {'>','>','>','>','<','>','>'},  
        {'<','<','<','<','<','=','0'},  
        {'>','>','>','>','0','>','>'},  
        {'<','<','<','<','<','0','='}};  
    switch(a){  
        case '+': i=0; break;  
        case '-': i=1; break;  
        case '*': i=2; break;  
        case '/': i=3; break;  
        case '(': i=4; break;  
        case ')': i=5; break;  
        case '#': i=6; break;  
    }  
    switch(b){  
        case '+': j=0; break;  
        case '-': j=1; break;  
        case '*': j=2; break;  
        case '/': j=3; break;  
        case '(': j=4; break;  
        case ')': j=5; break;  
        case '#': j=6; break;  
    }  
    return pre[i][j];  
}  

int Eval(char* p)  
{   
    LinkStack OPND;      //操作数栈 
	LinkStack OPTR;      //运算符栈
	InitStack(OPND);
	InitStack(OPTR);
    char TempData[20];   
    int Data,a,b;   
    char theta,*c,Dr[]={'#','\0'};   
    Push(OPTR,'#');   
    c=strcat(p,Dr);   
    strcpy(TempData,"\0");//字符串拷贝函数   
    while (*c!= '#' || GetTop(OPTR)!='#')  
    {   
        if (!IsOperate(*c))  
        {   
            Dr[0]=*c;   
            strcat(TempData,Dr);           
            c++;   
            if (IsOperate(*c))  
            {   
                Data=atoi(TempData);      
                Push(OPND, Data);   
                strcpy(TempData,"\0");   
            }   
        }   
        else    
        {  
            switch (Precede(GetTop(OPTR), *c))  
            {  
            case '<':   
                Push(OPTR, *c);   
                c++;   
                break;   
            case '=': 
                Pop(OPTR);   
                c++;   
                break;   
            case '>': 
                theta=GetTop(OPTR);Pop(OPTR);   
                a = GetTop(OPND);Pop(OPND);   
                b = GetTop(OPND);Pop(OPND);   
                Push(OPND, Operate(a, theta, b));   
                break;   
        }   
    } 
}
    return GetTop(OPND);   
} 
int main(){
	cout<<"输入你的表达式："<<endl; 
	char e[100];
	gets(e);
	cout<<"表达式等于："<<Eval(e);
}
