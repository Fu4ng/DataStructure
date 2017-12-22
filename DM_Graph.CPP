#include<iostream>
using namespace std;
typedef struct {
	int **p; //矩阵 
	int v; //矩阵顶点数 
}Mx;
void InitM(Mx &M){
	//把矩阵初始化为全0 
	for(int i = 0;i<M.v;i++)
		for(int j=0;j<M.v;j++)
			M.p[i][j] = 0;
}
void Show(Mx M){
	//输出矩阵 
	cout<<"================================="<<endl;
	for(int i=0;i<M.v;i++)
	{	
		for(int j=0;j<M.v;j++)
		{cout<<M.p[i][j]<<" ";}
		cout<<endl;
	}
	cout<<"=================================="<<endl;
}
void GetE(Mx& M){
	//输入边的两端后，改变矩阵中相应的值 
	cout<<"请输入 边的两端，输入0 0时退出"<<endl; 
	int a,b;
	a=1;b=1;
	while(1)
	{
		cin>>a;
		cin>>b;
		if(a==0 && b == 0)
			break;
		if(a>M.v||b>M.v)
		{
			cout<<"请输入小于"<<M.v<<"的数"<<endl;
			continue; 
		}
		M.p[a-1][b-1]=1;
	}
	
}
void GetV(Mx& M){
	//按照输入的数创建相应的矩阵 
	cout<<"输入顶点数"<<endl;
	cin>>M.v;
	M.p = (int**) new int* [M.v];
	for(int i = 0;i<M.v;i++)
		M.p[i]=new int [M.v];
}
void Input(Mx& M){
	//输入函数 
	GetV(M);
	InitM(M);
	GetE(M);
	cout<<"输入完毕"<<endl;
}
void GetData(Mx& M){
	Input(M);
	Show(M);
}
void CS(Mx &M)
{  //验证自反 
	int s=0;
	for(int i =0;i<M.v;i++)
		s+=M.p[i][i];
	if(s == M.v)
		cout<<"具有自反"<<endl;
	else
		cout<<"不具有自反"<<endl;
}
void MS(Mx &M)
{
	//检验对称 
	int s = M.v;
	int f =1;
	if(s%2!=0) s=(s+1)/2;
	else s /= 2;
	for(int i =0;i<s;i++)
	{
		for(int j =0;j<s;j++)
		{
			if (M.p[i][j] == M.p[j][i]);
			else {
				cout<<"不具有对称"<<endl;
				i = s+1;j = s+1;
				f =0;
			}
		}
	}
	if(f) cout<<"具有对称性"<<endl;
}
//int IS_c(Mx &M,int j,int &f){
//	for(int i = 0;i<M.v;i++)
//	{
//		if(M.p[j][i] == 1);
//		else 
//		{
//			cout<<"不具有传递性"<<endl;
//			i =M.v+1;
//			f=0;
//		}
//		if(f==0) return 0;
//	}
 
//	return 0;}
void IS(Mx &M)
{	
	//检验传递 
	int f = 1;
	for(int j = 0;j<M.v;j++){
		for(int i=0;i<M.v;i++){
			if(M.p[i][j]){
				for(int m =0;m<M.v;m++){
					if(M.p[i][m]*M.p[m][j]==0)
					{
						f = 0;
						cout<<"不具有传递性"<<endl;
						i = M.v+1;j = M.v+1;
						break;
					}
						
				}
			}
		}
	}
	if(f) cout<<"具有传递性"<<endl;
}
int main(){
	Mx M;
	GetData(M);
	CS(M);
	MS(M);
	IS(M);
	return 0;
}
