#include <iostream>
#include "DM_OP_h.h"
using namespace std;
int main() {
//    Mx M1,M2;
//    InputVertex(M1);
//    cout<<"输入第一个矩阵的信息："<<endl;
//    //input vertices and create a Matrix
//    MatrixCvt(M1);
//    ShowMatrix(M1);
//    cout<<"输入第二个矩阵的信息："<<endl;
//    //input vertices and create a Matrix
//    CreateMatrix(M2);
//    CopyMatrix(M2,M1);
//    //InitialMatrix(M2);
//    MatrixCvt(M2);
//    ShowMatrix(M2);
//    //
//    cout<<"第一个矩阵所具有的性质如下："<<endl;
//    MS(M1);CS(M1);IS(M1);
//    cout<<"第二个矩阵所具有的性质如下："<<endl;
//    MS(M2);CS(M2);IS(M2);
//    //
//    char q = 'I';
//    while(q!='Q'&&q!='q'){
//        q = menu();
//        Mx M;
//        switch (q){
//            case 'I':
//            case 'i':
//                M = Intersection(M1,M2);
//                cout<<"交集"<<endl;
//                ShowMatrix(M);
//                break;
//            case 'U':
//            case 'u':
//                M = Union(M1,M2);
//                cout<<"并集"<<endl;
//                ShowMatrix(M);
//                break;
//            case 'C':
//            case 'c':
//                Mx CM;
//                M = Complement(M1);
//                CM = Complement(M2);
//                cout<<"第一个矩阵的补集"<<endl;
//                ShowMatrix(M);
//                cout<<"第二个矩阵的补集"<<endl;
//                ShowMatrix(CM);
//                DeleteMatrix(CM);
//                break;
//            case 'D':
//            case 'd':
//                M = DifferenceOfSet(M1,M2);
//                cout<<"差集"<<endl;
//                ShowMatrix(M);
//                break;
//            default:
//                if(q=='q'||q=='Q'){
//                    cout<<"退出程序！"<<endl;
//                }
//                else
//                    cout<<"找不到该代码所代表的操作，请重新输入。";
//                break;
//
//
//        }//switch
//        DeleteMatrix(M);
//    }//while
    Mx M;
    InputVertex(M);
    cout<<"输入矩阵信息："<<endl;
    MatrixCvt(M);
    cout<<"邻接矩阵如下："<<endl;
    ShowMatrix(M);



}
