//
// Created by Fu4ng on 2017/9/23.
//

//线性表
#include <iostream>

#define MAXSIZE 50
using namespace std;

typedef int ElemType;
typedef struct {
    ElemType *list;
    int length;
    int list_size;
} SqList;

bool cmp(ElemType a,ElemType b);
void InitList(SqList &L);//n = length, l = list
void DestroList(SqList &L);
void ClearList(SqList &L); //L本来是存在的，将其重置为空表
void ListInset(SqList &L, int index, ElemType e);//插入元素，长度加一
void DisplayList(SqList &L);
bool ListIsEmpty(SqList &L); //L为空表返回TRUE,反之
int ListLength(SqList &L); //返回L长度
int ListElemIndex(SqList &L,ElemType e); //返回e的位序
int LocateList(SqList &L, ElemType e, bool cmp(ElemType a,ElemType b)); //返回满足与e比较符合cmp()函数的元素位序，若无返回0
int BinarySearch(SqList &L,ElemType e); //二分搜索
ElemType GetElem(SqList &L, int index); //index为返回元素的位序
ElemType NextElem(SqList &L, ElemType cur_e); //若cur_e不是最后一项，则返回其后一项
ElemType PrioElem(SqList &L, ElemType cur_e);//若cur_e不是第一项，则返回其前一项
ElemType ListDelete(SqList &L, int index); //删除第index项，并返回其值


/*
int main() {
    SqList L;
    InitList(L);
    ElemType a[10]={0,1,2,3,4,5,6,7,8,9};
    for (int i = 0; i < sizeof(a)/ sizeof(ElemType) ; ++i) {
        L.list[i] = a[i];
        L.length++;
    }
    DisplayList(L);
    cout<<endl;
    cout<<"Length is "<<ListLength(L)<<endl;
    cout<<BinarySearch(L,0)<<endl;
    cout<<LocateList(L,5,cmp)<<endl;
    cout<<GetElem(L,2)<<endl;
    cout<<NextElem(L,2)<<endl;
    cout<<PrioElem(L,2)<<endl;
    cout<<ListDelete(L,2)<<endl;
    ClearList(L);
    cout<<ListIsEmpty(L);

}
 */


void InitList(SqList &L) {
    L.list = new ElemType(sizeof(ElemType) * MAXSIZE);
    L.length =0;
    L.list_size = MAXSIZE;

}

void DestroList(SqList &L) {
    delete[]L.list;
}

void ClearList(SqList &L) {
    delete[]L.list;
    InitList(L);
}

void ListInset(SqList &L, int index,ElemType e){
    if(index<0||index>L.length){
        cout<<"请输入正确位序，当前表的长度为"<<L.length<<endl;
    }
    else {
        //index合法
        for (int j = L.length; j > index; j--) {
            L.list[L.length] = L.list[L.length - 1];
        }
        L.list[index] = e;
        L.length++;
    }
}
void DisplayList(SqList &L){
    for(int i =0;i<L.length;i++){
        cout<<L.list[i]<<" ";
    }
}

bool ListIsEmpty(SqList &L){
    if(L.length == 0)
        return 1;
    return 0;
}

int ListLength(SqList &L){
    return L.length;
}

bool cmp(ElemType a,ElemType b){
    if(a==b)
        return 1;
    return 0;
}
int LocateList(SqList &L, ElemType e, bool cmp(ElemType a,ElemType b)){
    for (int i = 0; i <L.length ; ++i) {
        if(cmp(e,*(L.list+i)))
            return i;
    }
    return 0;
}

int ListElemIndex(SqList &L,ElemType e){
    for(int i = 0;i<L.length-1;i++){
        if(L.list[i] == e)
            return i;
    }
    //不返回0，防止与e的位序是0想冲突
    cout<<"位序不正确"<<endl;
}

int BinarySearch(SqList &L, ElemType e){
    int low =0;
    int high =L.length-1;
    while(low<=high){
        int mid = (low+high)/2;
        if (L.list[mid] == e) return mid;
        if (L.list[mid]< e) low = mid+1;
        else
            high = low -1;
    }
}

ElemType GetElem(SqList &L, int index){
    if(index>L.length-1){
        cout<<"输入正确位序"<<endl;
        return 0;
    }
    else
        return L.list[index];

}

ElemType NextElem(SqList &L, ElemType cur_e){
    if(ListElemIndex(L,cur_e)!=L.length-1){
        return L.list[ListElemIndex(L,cur_e)+1];
    }
    else{
        cout<<"这是最后一项"<<endl;
    }
}

ElemType PrioElem(SqList &L, ElemType cur_e){
    if(ListElemIndex(L,cur_e)){
        return L.list[ListElemIndex(L,cur_e)-1];
    }
    else{
        cout<<"这是第一项"<<endl;
    }
}

ElemType ListDelete(SqList &L, int index){
    ElemType DleteElem = L.list[index];
    if(index<L.length-1){
        for(int i = index; i <L.length-1 ; ++i) {
            L.list[index] = L.list[index + 1];
        }
        L.length--;
        return DleteElem;
    }
    else
        cout<<"请输入正确位序"<<endl;
}