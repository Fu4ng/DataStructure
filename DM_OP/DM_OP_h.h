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