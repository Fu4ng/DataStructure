
#include <iostream>
using namespace std;

typedef  struct {
    int **matrix;  //Matrix
    int rows;
    int cols;  //columns
    char *rowChar; //store vertex character
    char *colChar;
}Mx;
int index(char *s,char r){
    //return the index of "r"in array "s"
    int index=0;
    while(s[index]!=r)
        index++;
    return index;
}
void InitialMatrix(Mx &M){
    for (int i = 0; i <M.rows; ++i) {
        for (int j = 0; j <M.cols; ++j) {
            M.matrix[i][j]=0;
        }
    }
}
void CreateMatrix(Mx &M){
    // Dynamically allocate memory to the matrix "M"
    M.matrix = (int **) new int*[M.rows];
    for (int i = 0; i <M.rows ; ++i) {
        M.matrix[i] = new int [M.cols];
    }
    //Initial Matrix to zero
   InitialMatrix(M);
}

void InputVertex(Mx &M){
    //Vertex
    int rowV ; //vertex for Matrix'row
    int colV ; //vertex for Matrix'col
    int temp;
    cout<<"输入顶点数（行）：";
    cin>>rowV;
    colV=rowV; 
    M.rows = rowV;
    M.cols = colV;
    M.rowChar = new char [rowV+1];
    M.colChar = new char [colV+1];
    temp = rowV;
    CreateMatrix(M);
    cout<<"输入顶点（用空格隔开）"<<endl;
    while(temp--){
        cin>>M.rowChar[rowV-temp-1];
    }
    M.rowChar[M.rows]='\0';
    M.colChar=M.rowChar;
}
void MatrixCvt(Mx &M){
    //Enter the vertex's relationship
    //convert to bool Matrix
    int t;
    cout<<"输入矩阵的关系数：";
    cin>>t;
    char v1;char v2; // the two vertices that have relations
    int v1Index,v2Index;
    int z =0;
    while(z++<t){
        cout<<"输入第"<<z<<"个关系"<<endl;
        cin>>v1;
        cin>>v2;
        v1Index = index(M.rowChar,v1);
        v2Index = index(M.colChar,v2);
        M.matrix[v1Index][v2Index]= 1;
    }

}
void ShowMatrix(Mx &M){
    for (int i = 0; i <M.rows ; ++i) {
        for (int j = 0; j <M.cols ; ++j) {
            cout<<M.matrix[i][j]<<" ";
        }
        cout<<endl;
    }
}
void CopyMatrix(Mx &M2,Mx M1){
    //return a copy of M1
    M2.rows = M1.rows;
    M2.cols = M1.cols;
    CreateMatrix(M2);
    M2.colChar = new char[M2.cols+1];
    M2.rowChar = new char[M2.rows+1];
    for(int i = 0;i<M2.rows;i++)
    	for(int j = 0;j<M2.cols;j++)
    		M2.matrix[i][j] = M1.matrix[i][j];
}
Mx Union(Mx M1,Mx M2){
    //return union of M1 and M2
    Mx M ;
    CopyMatrix(M,M1);
    for (int i = 0; i < M.rows ; ++i) {
        for (int j = 0; j <M.cols ; ++j) {
            M.matrix[i][j] = (M1.matrix[i][j])||(M2.matrix[i][j]);//or
        }
    }
    return M;
} 
Mx Achieve(Mx M){
    Mx MA;
    CopyMatrix(MA,M);
    //n to m
    for(int i = 0;i<M.cols;i++){
        MA.matrix[i][i] = 1;
        for(int j = 0;j<M.rows;j++){
            if(MA.matrix[i][j]) MA.matrix[i][j] =1;
        }//second for
    }//first for
    return MA;
}

bool MatrixEqual(Mx M1,Mx M2){ //判断两个矩阵是否相等
    bool eq=true;
    if(M1.cols!=M2.cols||M1.rows!=M2.rows){
        eq= false;
    }
    else{
        for (int i = 0; i <M1.rows ; ++i) {
            for (int j = 0; j <M1.cols; ++j) {
                if(M1.matrix[i][j]!=M2.matrix[i][j])
                {
                    eq = false;
                    i = M1.rows; //跳出循环
                    break;
                }
            }//for
        }//for
    }//else
    return eq;
}
void CreateI(Mx &M, int n ){
    //建立一个对角线为1 的矩阵
    M.cols = n;M.rows = n;
    CreateMatrix(M);
    InitialMatrix(M);
    for (int i = 0; i < n; ++i) {
        M.matrix[i][i] = 1;
    }
}
Mx MatrixMul(Mx M,Mx M1){
    //矩阵相乘
    Mx M2;
    M2.cols = M.cols;
    M2.rows = M.rows;
    CreateMatrix(M2);
    for(int i = 0;i<M.rows;i++){
	for(int j = 0;j<M.cols;j++){
		for(int k = 0;k<M.rows;k++){
			M2.matrix[i][j]+= (M.matrix[i][k]*M1.matrix[k][j]);
		}
	}//sed for
    }//fst for
    return M2;
}

void BCS(Mx M){//通过闭包验证自反
    Mx M1 ,I;
    CreateI(I,M.cols);
    CopyMatrix(M1,M);
    M1 = Union(M,I);
    ShowMatrix(M1);
    if(MatrixEqual(M,M1)) cout<<"==矩阵自反=="<<endl;
    else cout<<"==矩阵不自反=="<<endl;

}
void BMS(Mx M){
    Mx M1;
    CopyMatrix(M1,M);
    for (int i = 0; i <M1.cols ; ++i) {
        for (int j = 0; j < M1.rows; ++j) {
            if(M1.matrix[i][j]==1) M1.matrix[j][i]=1; 
        }
    }//for
    ShowMatrix(M1);
    if(MatrixEqual(M,M1)) cout<<"==矩阵对称=="<<endl;
    else cout<<"==矩阵不对称=="<<endl;
}
void BIS(Mx M){
    //判断矩阵是否传递
    Mx M1;
    Mx M2;
    int n = M.cols;
    CopyMatrix(M1,M);
    CopyMatrix(M2,M);
    cout<<"M1:"<<endl;
	ShowMatrix(M1);
	cout<<"M2:"<<endl;
	ShowMatrix(M2);
    InitialMatrix(M2);
    int t = 1;
    cout<<"第1次闭包："<<endl;
	ShowMatrix(M); 
    while(t++<n){
	M1 = MatrixMul(M,M1);
	M2 = Union(M,M1);
	cout<<"M1:"<<endl;
	ShowMatrix(M1);
	cout<<"M2:"<<endl;
	ShowMatrix(M2);
	cout<<"第"<<t<<"次闭包："<<endl;
	ShowMatrix(M2);
    }
    if(MatrixEqual(M,M2)) cout<<"矩阵传递"<<endl;
    else cout<<"矩阵不传递"<<endl;
}
int main(){
	Mx M,C;
	InputVertex(M);
	MatrixCvt(M);
	//BMS(M);
	//BCS(M); 
	BIS(M);
	C=Achieve(M);
	cout<<"可达性矩阵为："<<endl;
	ShowMatrix(C);
	
}
