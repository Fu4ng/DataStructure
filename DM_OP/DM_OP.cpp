//
// Created by Fu4ng on 2017/12/28.
//
#include <iostream>
#include "DM_OP_h.h"
using namespace std;

//mini function
int index(char *s,char r){
    //return the index of "r"in array "s"
    int index=0;
    while(s[index]!=r)
        index++;
    return index;
}
char menu(){
    cout<<"==========================="<<endl;
    cout<<"    ������Ҫִ�еĲ�������"<<endl;
    cout<<"         I.�󽻼�"<<endl;
    cout<<"         U.�󲢼�"<<endl;
    cout<<"         C.�󲹼�"<<endl;
    cout<<"         D.��"<<endl;
    cout<<"         Q.�˳�����"<<endl;
    cout<<"==========================="<<endl;
    char q ;
    cin>>q;
    return q;

}

//Matrix's function
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
    cout<<"���붥�������У���";
    cin>>rowV;
    cout<<"���붥�������У���";
    cin>>colV;
    M.rows = rowV;
    M.cols = colV;
    M.rowChar = new char [rowV+1];
    M.colChar = new char [colV+1];
    temp = rowV;
    CreateMatrix(M);
    cout<<"�����ж��㣨�ÿո������"<<endl;
    while(temp--){
        cin>>M.rowChar[rowV-temp-1];
    }
    M.rowChar[M.rows]='\0';
    cout<<"�����ж��㣨�ÿո������"<<endl;
    temp = colV;
    while(temp--){
        cin>>M.colChar[colV-temp-1];
    }
    M.colChar[M.cols]='\0';
}
void MatrixCvt(Mx &M){
    //Enter the vertex's relationship
    //convert to bool Matrix
    int t;
    cout<<"�������Ĺ�ϵ����";
    cin>>t;
    char v1;char v2; // the two vertices that have relations
    int v1Index,v2Index;
    int z =0;
    while(z++<t){
        cout<<"�����"<<z<<"����ϵ"<<endl;
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
void DeleteMatrix(Mx &M){
    delete M.matrix;
    delete M.colChar;
    delete M.rowChar;
}
void CopyMatrix(Mx &M2,Mx M1){
    //return a copy of M1
    M2.rows = M1.rows;
    M2.cols = M1.cols;
    CreateMatrix(M2);
    M2.colChar = new char[M2.cols+1];
    M2.rowChar = new char[M2.rows+1];
    for (int i = 0; (M1.rowChar[i])!='\0' ; ++i) {
        M2.rowChar[i] = M1.rowChar[i];
    }
    M2.rowChar[M2.rows]='\0';
    for (int i = 0; (M1.colChar[i])!='\0' ; ++i) {
        M2.colChar[i] = M1.colChar[i];
    }
    M2.colChar[M2.cols]='\0';

}


Mx Intersection(Mx M1,Mx M2){
    //return intersection of M1 and M2
    Mx M ;
    CopyMatrix(M,M1);
    for (int i = 0; i < M.rows ; ++i) {
        for (int j = 0; j <M.cols ; ++j) {
            M.matrix[i][j] = (M1.matrix[i][j])&&(M2.matrix[i][j]);//and
        }
    }
    return M;
}
Mx Union(Mx M1,Mx M2){
    //return union of M1 and M2
    Mx M ;
    CopyMatrix(M,M1);
    for (int i = 0; i < M.rows ; ++i) {
        for (int j = 0; j <M.cols ; ++j) {
            M.matrix[i][j] = (M1.matrix[i][j])&&(M2.matrix[i][j]);//or
        }
    }
    return M;
}
Mx Complement(Mx M1){
    //return complement of M1
    Mx M ;
    CopyMatrix(M,M1);
    for (int i = 0; i < M.rows ; ++i) {
        for (int j = 0; j <M.cols ; ++j) {
            M.matrix[i][j] = !(M1.matrix[i][j]);
        }
    }
    return M;
}
Mx DifferenceOfSet(Mx M1,Mx M2){
    //return difference of set of M1 and M2
    M2 = Complement(M2);
    Mx M = Intersection(M1,M2);
    return M;
}

void CS(Mx &M) {  //��֤�Է�
    int s=0;
    for(int i =0;i<M.rows;i++)
        s+=M.matrix[i][i];
    if(s == M.rows)
        cout<<"�����Է�"<<endl;
    else
        cout<<"�������Է�"<<endl;
}
void MS(Mx &M) {
    //����Գ�
    int s = M.rows;
    int f =1;
    if(s%2!=0) s=(s+1)/2;
    else s /= 2;
    for(int i =0;i<s;i++)
    {
        for(int j =0;j<s;j++)
        {
            if (M.matrix[i][j] == M.matrix[j][i]);
            else {
                cout<<"�����жԳ�"<<endl;
                i = s+1;j = s+1;
                f =0;
            }
        }
    }
    if(f) cout<<"���жԳ���"<<endl;
}
void IS(Mx &M) {
    //���鴫��
    int f = 1;
    for(int i = 0;i<M.rows;i++){
        for(int j=0;j<M.cols;j++){
            if(M.matrix[i][j]){
                for(int k =0;k<M.rows;k++){
                    if(!(M.matrix[j][k]&&M.matrix[i][k]))
                    {
                            f = 0;
                    }

                }
            }
        }
    }
    if(f)
        cout<<"���д�����"<<endl;
    else
        cout<<"���д�����"<<endl;
}