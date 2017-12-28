#include <iostream>
#include "DM_OP_h.h"
int main() {
    Mx M;
    InputVertex(M);
    //input vertices and create a Matrix
    MatrixCvt(M);
    ShowMatrix(M);
}