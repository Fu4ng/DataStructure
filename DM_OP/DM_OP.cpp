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

//Matrix's function
void CreateMatrix(Mx &M){
    // Dynamically allocate memory to the matrix "M"
    M.matrix = (int **) new int*[M.rows];
    for (int i = 0; i <M.rows ; ++i) {
        M.matrix[i] = new int [M.cols];
    }
    //Initial Matrix to zero
    for (int i = 0; i <M.rows; ++i) {
        for (int j = 0; j <M.cols; ++j) {
            M.matrix[i][j]=0;
        }
    }
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
    cout<<"�����ж��㣨�ÿո������"<<endl;
    temp = colV;
    while(temp--){
        cin>>M.colChar[colV-temp-1];
    }
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