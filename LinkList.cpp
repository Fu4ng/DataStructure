//
// Created by Fu4ng on 2017/10/7.
//
typedef int ElemType;

typedef struct LNode{
    ElemType data;
    struct  LNode *next;
}LNode, *LinkList;

void InitList(LinkList &L){
    L = new LNode;
    L->next = NULL;
}

ElemType GetElem(LinkList L,int i){
    LinkList p = L->next;
    int j = 1;
    while(p && j<i){
        p = p->next;
        j++;
    }
    if(!p||j>i) {
        cout<<"index is no correct"<<endl;
        return -1;
    }
    return p->data;

}
LinkList LocateElem(LinkList L,ElemType e){//返回e的地址
    LinkList p;
    p = L->next;
    while(p && p->data!=e){
        p = p->next;
    }
    if(!p){
        cout<<"No found e"<<endl;
        return NULL;
    } else
        return p;
}
void ListInset(LinkList &L,ElemType e, int index){
    LinkList p = LocateElem(L,GetElem(L,index));
    q =new LNode;
    q->data = e;
    q->next = p->next;
    p->next =s;
}
void ListDelete(LinkList &L,ElemType e){
    LinkList q;
    LinkList p = LocateElem(L,e);
    q = p->next;
    p->next = p->next->next;
    delete q;
}