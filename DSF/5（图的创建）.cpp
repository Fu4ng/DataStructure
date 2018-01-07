#include <iostream>
using namespace std;
#define MaxInt 32767
#define MVNum 100
typedef char VerTexType; //�������� 
typedef int ArcType;    //Ȩֵ����
typedef struct{
	VerTexType vexs[MVNum];      //�����
	ArcType arc[MVNum][MVNum];   //�ڽӾ��� 
	int vexnum,arcnum;  		//��ǰͼ�ĵ����ͱ��� 
}AMGraph;
typedef struct ArcNode{ //�ڽӱ�߽�� 
	int adjvex;
	struct ARCnODE *next;
}ArcNode; 
typedef struct VNode{   //��� 
	VerTexType data;
	ArcNode *f;     //ָ���һ�������ö���ıߵ�ָ��
	 
}VNode,AdjList[MVNum];  //AdjList���ڽӱ�����
typedef struct{			//�ڽӱ� 
	AdjList *vertices;  //�������� 
	int vexs,arcs;  //ͼ�Ķ������ͱ��� 
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
void CreateM(AMGraph &G){ //�ڽӾ��� _����ͼ 
	cout<<"���붥������";cin>>G.vexnum;
	cout<<"���������";cin>>G.arcnum; 
	int i ;
	for(i =0;i<G.vexnum;++i) cin>>G.vexs[i]; //������������Ϣ
	for(i = 0;i<G.arcnum;i++){                     //��ʼ���ڽӾ��󣬱ߵ�Ȩֵ����Ϊ���ֵ 
		for(int j = 0;j<G.arcnum;j++){
			G.arc[i][j]=MaxInt;
		}
	}
	for(int j = 0;j<G.arcnum;j++){//�����ڽӾ��� 
		VerTexType v1,v2;
		ArcType w; 
		cout<<"����ߵ����ˣ�";
		cin>>v1>>v2;
		cout<<"����Ȩֵ��" ;
		cin>>w;
		int row = index(G.vexs,v1);
		int col = index(G.vexs,v2);
		G.arc[i][j] = w;           //����ͼ 
	} 

}
void CreateT(ALGraph &G){ //�ڽӱ� _����ͼ
	 int v,a;
	 cout<<"���붥������";cin>>v;
	 cout<<"�������";cin>>a;
	 for(int i = 0;i<G.vexs;i++){
	 	cout<<"�����"<<i+1<<"�����Ϣ"; 
	 	cin>>G.vertices[i].data;
	 	G.vertices[i].f = NULL;
	 }
	 for(int k=0;k<G.arcs;k++){
	 	VerTexType v1,v2;
		ArcType w; 
		cout<<"����ߵ����ˣ�";
		cin>>v1>>v2;
		cout<<"����Ȩֵ��" ;
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
