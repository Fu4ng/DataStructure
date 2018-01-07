#include <iostream>
using namespace std;
#define MaxInt 32767
#define MVNum 100
typedef char VerTexType; //顶点类型 
typedef int ArcType;    //权值类型
typedef struct{
	VerTexType vexs[MVNum];      //顶点表
	ArcType arc[MVNum][MVNum];   //邻接矩阵 
	int vexnum,arcnum;  		//当前图的点数和边数 
}AMGraph;
typedef struct ArcNode{ //邻接表边结点 
	int adjvex;
	struct ARCnODE *next;
}ArcNode; 
typedef struct VNode{   //结点 
	VerTexType data;
	ArcNode *f;     //指向第一条依附该顶点的边的指针
	 
}VNode,AdjList[MVNum];  //AdjList是邻接表类型
typedef struct{			//邻接表 
	AdjList *vertices;  //顶点数组 
	int vexs,arcs;  //图的顶点数和边数 
}ALGraph; 
template<typename T>
int index(T *a,T c){
	int index;
	for(index = 0;a[index]&&a[index]!=c;index++);
	return index;
}
int index_T(ALGraph G,int v){
    int index = 0;
    while(G.vertices[index].data!= v)
        index++;
    return index;
}
void CreateM(AMGraph &G){ //邻接矩阵 _创建图 
	cout<<"输入顶点数：";cin>>G.vexnum;
	cout<<"输入边数：";cin>>G.arcnum; 
	int i ;
	for(i =0;i<G.vexnum;++i) cin>>G.vexs[i]; //依次输入点的信息
	for(i = 0;i<G.arcnum;i++){                     //初始化邻接矩阵，边的权值都设为最大值 
		for(int j = 0;j<G.arcnum;j++){
			G.arc[i][j]=MaxInt;
		}
	}
	for(int j = 0;j<G.arcnum;j++){//构造邻接矩阵 
		VerTexType v1,v2;
		ArcType w; 
		cout<<"输入边的两端：";
		cin>>v1>>v2;
		cout<<"输入权值：" ;
		cin>>w;
		int row = index(G.vexs,v1);
		int col = index(G.vexs,v2);
		G.arc[i][j] = w;           //有向图 
	} 

}
void CreateT(ALGraph &G){ //邻接表 _创建图
	 int v,a;
	 cout<<"输入顶点数：";cin>>v;
	 cout<<"输入边数";cin>>a;
	 for(int i = 0;i<G.vexs;i++){
	 	cout<<"输入第"<<i+1<<"结点信息"; 
	 	cin>>G.vertices[i].data;
	 	G.vertices[i].f = NULL;
	 }
	 for(int k=0;k<G.arcs;k++){
	 	VerTexType v1,v2;
		ArcType w; 
		cout<<"输入边的两端：";
		cin>>v1>>v2;
		cout<<"输入权值：" ;
		cin>>w;
		int row,col;
		row = index_T(G,v1);
		col = index_T(G,v2);
		ArcNode* p1 = new ArcNode;
		ArcNode* p2 = new ArcNode;
		
		p1->adjvex =    row;
		p1->next = G.vertices[col].f;
		G.vertices[col].f = p2;  
	 } 
	 
}

int main(){

} 
