#include <iostream>
#define MVNum 100
#define VerTexType char
#define MAXSIZE 6
#define QElemType int
using namespace std;
typedef struct ArcNode{
    int adjvex;
    struct ArcNode *next; //ָ���й�ϵ�Ķ���
    int weight;         //Ȩֵ
}ArcNode;
typedef struct VNode{
    VerTexType data;
    ArcNode *first;
}VNode,AdjList;       //AdjList ���ڽӱ����
typedef struct {
    AdjList *vertices;
    int vets; //������
    int arcs; //����
}ALGraph;
int index(ALGraph G,VerTexType v){
    int index = 0;
    while(G.vertices[index].data!= v)
        index++;
    return index;
}
void CreateG(ALGraph &G){
    int v,a;
    cout<<"���붥������";cin>>v;
    G.vertices = new VNode [v];
    G.vets= v;
    cout<<"�������";cin>>a;
    G.arcs=a;
    for(int i = 0;i<G.vets;i++){
        cout<<"�����"<<i+1<<"�����Ϣ";
        cin>>G.vertices[i].data;
        G.vertices[i].first = NULL;
    }
    for(int k=0;k<G.arcs;k++){
        VerTexType v1,v2;
        int w;
        cout<<"����ߵ����ˣ�";
        cin>>v1>>v2;
//        cout<<"����Ȩֵ��" ;
//        cin>>w;
        int a,b;       //a -> b
         a= index(G,v1);
        b = index(G,v2);
        ArcNode* p1 = new ArcNode;
        ArcNode* p2 = new ArcNode;
        p1->adjvex = b;
        p1->next = G.vertices[a].first;
        G.vertices[a].first=p1;     //ǰ�巨
        p2->adjvex = a;
        p2->next=G.vertices[b].first;
        G.vertices[b].first =p2;
    }
}
void DFS_AL(ALGraph G,int n, bool visited[]){
    //��ȱ���
    //�ӵ�n����㿪ʼ����
    cout<<n+1;
    visited[n] = 1;
    ArcNode *p = new ArcNode;
    p=G.vertices[n].first;
    while(p!=NULL){

        int w=p->adjvex;  //w �� v ���ڽӵ�
        if(!visited[w]) DFS_AL(G,w,visited);      //���wû�з��ʵ�����ݹ����DSF_AL
        p=p->next;
    }
}

//ѭ������ �ṹ
typedef struct {
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

void BFS(ALGraph G,bool vis[]){
    int i;
    SqPtr q ;
    InitSq(q);
    for(i=0;i<G.vets;++i){
        if(!vis[i]){
            vis[i]  = true;
            cout<<G.vertices->data;
            EnSq(q,i);
            while(!IsEmpty(q)){
                i=DeSq(q);
                ArcNode *p = G.vertices[i].first;
                while(p){
                    if(!vis[p->adjvex]){
                        vis[p->adjvex] = true;
                        cout<<G.vertices[p->adjvex].data;
                        EnSq(q,p->adjvex);
                    }//if
                    p=p->next;
                }//whil e
            }//while
        }//if
    }//for

}

int main(){
    ALGraph G;
    CreateG(G);
    bool visited[MVNum]={0};
    cout<<"������ȱ���:"<<endl;
    bool visited1[MVNum]={0};
    DFS_AL(G,0,visited1);
    cout<<"������ȱ���:"<<endl;
    BFS(G,visited);
    cout<<endl;

}
