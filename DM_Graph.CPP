#include<iostream>
using namespace std;
typedef struct {
	int **p; //���� 
	int v; //���󶥵��� 
}Mx;
void InitM(Mx &M){
	//�Ѿ����ʼ��Ϊȫ0 
	for(int i = 0;i<M.v;i++)
		for(int j=0;j<M.v;j++)
			M.p[i][j] = 0;
}
void Show(Mx M){
	//������� 
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
	//����ߵ����˺󣬸ı��������Ӧ��ֵ 
	cout<<"������ �ߵ����ˣ�����0 0ʱ�˳�"<<endl; 
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
			cout<<"������С��"<<M.v<<"����"<<endl;
			continue; 
		}
		M.p[a-1][b-1]=1;
	}
	
}
void GetV(Mx& M){
	//�����������������Ӧ�ľ��� 
	cout<<"���붥����"<<endl;
	cin>>M.v;
	M.p = (int**) new int* [M.v];
	for(int i = 0;i<M.v;i++)
		M.p[i]=new int [M.v];
}
void Input(Mx& M){
	//���뺯�� 
	GetV(M);
	InitM(M);
	GetE(M);
	cout<<"�������"<<endl;
}
void GetData(Mx& M){
	Input(M);
	Show(M);
}
void CS(Mx &M)
{  //��֤�Է� 
	int s=0;
	for(int i =0;i<M.v;i++)
		s+=M.p[i][i];
	if(s == M.v)
		cout<<"�����Է�"<<endl;
	else
		cout<<"�������Է�"<<endl;
}
void MS(Mx &M)
{
	//����Գ� 
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
				cout<<"�����жԳ�"<<endl;
				i = s+1;j = s+1;
				f =0;
			}
		}
	}
	if(f) cout<<"���жԳ���"<<endl;
}
//int IS_c(Mx &M,int j,int &f){
//	for(int i = 0;i<M.v;i++)
//	{
//		if(M.p[j][i] == 1);
//		else 
//		{
//			cout<<"�����д�����"<<endl;
//			i =M.v+1;
//			f=0;
//		}
//		if(f==0) return 0;
//	}
 
//	return 0;}
void IS(Mx &M)
{	
	//���鴫�� 
	int f = 1;
	for(int j = 0;j<M.v;j++){
		for(int i=0;i<M.v;i++){
			if(M.p[i][j]){
				for(int m =0;m<M.v;m++){
					if(M.p[i][m]*M.p[m][j]==0)
					{
						f = 0;
						cout<<"�����д�����"<<endl;
						i = M.v+1;j = M.v+1;
						break;
					}
						
				}
			}
		}
	}
	if(f) cout<<"���д�����"<<endl;
}
int main(){
	Mx M;
	GetData(M);
	CS(M);
	MS(M);
	IS(M);
	return 0;
}