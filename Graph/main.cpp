#include <iostream>
#define MVNum 100
#define VerTexType char
#define MAXSIZE 6
#define QElemType int
using namespace std;
typedef struct ArcNode{
    int adjvex;
    struct ArcNode *next; //指向有关系的顶点
    int weight;         //权值
}ArcNode;
typedef struct VNode{
    VerTexType data;
    ArcNode *first;
}VNode,AdjList;       //AdjList 是邻接表矩阵
typedef struct {
    AdjList *vertices;
    int vets; //顶点数
    int arcs; //边数
}ALGraph;
int index(ALGraph G,VerTexType v){
    int index = 0;
    while(G.vertices[index].data!= v)
        index++;
    return index;
}
void CreateG(ALGraph &G){
    int v,a;
    cout<<"输入顶点数：";cin>>v;
    G.vertices = new VNode [v];
    G.vets= v;
    cout<<"输入边数";cin>>a;
    G.arcs=a;
    for(int i = 0;i<G.vets;i++){
        cout<<"输入第"<<i+1<<"结点信息";
        cin>>G.vertices[i].data;
        G.vertices[i].first = NULL;
    }
    for(int k=0;k<G.arcs;k++){
        VerTexType v1,v2;
        int w;
        cout<<"输入边的两端：";
        cin>>v1>>v2;
//        cout<<"输入权值：" ;
//        cin>>w;
        int a,b;       //a -> b
         a= index(G,v1);
        b = index(G,v2);
        ArcNode* p1 = new ArcNode;
        ArcNode* p2 = new ArcNode;
        p1->adjvex = b;
        p1->next = G.vertices[a].first;
        G.vertices[a].first=p1;     //前插法
        p2->adjvex = a;
        p2->next=G.vertices[b].first;
        G.vertices[b].first =p2;
    }
}
void DFS_AL(ALGraph G,int n, bool visited[]){
    //深度遍历
    //从第n个结点开始遍历
    cout<<n+1;
    visited[n] = 1;
    ArcNode *p = new ArcNode;
    p=G.vertices[n].first;
    while(p!=NULL){

        int w=p->adjvex;  //w 是 v 的邻接点
        if(!visited[w]) DFS_AL(G,w,visited);      //如果w没有访问到，则递归调用DSF_AL
        p=p->next;
    }
}

//循环队列 结构
typedef struct {
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
    cout<<"深度优先遍历:"<<endl;
    bool visited1[MVNum]={0};
    DFS_AL(G,0,visited1);
    cout<<"广度优先遍历:"<<endl;
    BFS(G,visited);
    cout<<endl;

}
