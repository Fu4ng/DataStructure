//
// Created by Fu4ng on 2017/12/28.
//

#ifndef DM_OP_DM_OP_H_H
#define DM_OP_DM_OP_H_H

#endif //DM_OP_DM_OP_H_H

typedef  struct {
    int **matrix;  //Matrix
    int rows;
    int cols;  //columns
    char *rowChar; //store vertex character
    char *colChar;
}Mx;

void CreateMatrix(Mx &M);
void InputVertex(Mx &M);
void MatrixCvt(Mx &M);
void ShowMatrix(Mx &M);
void DeleteMatrix(Mx &M);
void InitialMatrix(Mx &M);
void CopyMatrix(Mx &M2,Mx M1);
Mx Intersection(Mx M1,Mx M2);
Mx Union(Mx M1,Mx M2);
Mx Complement(Mx M1);
Mx DifferenceOfSet(Mx M1,Mx M2);
Mx MartrixMul(Mx M,Mx M1);
Mx Achieve(Mx M);
bool MartixEqual(Mx M1,Mx M2);
void CreateI(Mx &M,int n);
void CS(Mx &M);
void MS(Mx &M);
void IS(Mx &M);
void BCS(MX M);
void BMS(MX M);
void BIS(MX M);
char menu();
