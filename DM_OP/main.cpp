#include <iostream>
#include "DM_OP_h.h"
using namespace std;
int main() {
//    Mx M1,M2;
//    InputVertex(M1);
//    cout<<"�����һ���������Ϣ��"<<endl;
//    //input vertices and create a Matrix
//    MatrixCvt(M1);
//    ShowMatrix(M1);
//    cout<<"����ڶ����������Ϣ��"<<endl;
//    //input vertices and create a Matrix
//    CreateMatrix(M2);
//    CopyMatrix(M2,M1);
//    //InitialMatrix(M2);
//    MatrixCvt(M2);
//    ShowMatrix(M2);
//    //
//    cout<<"��һ�����������е��������£�"<<endl;
//    MS(M1);CS(M1);IS(M1);
//    cout<<"�ڶ������������е��������£�"<<endl;
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
//                cout<<"����"<<endl;
//                ShowMatrix(M);
//                break;
//            case 'U':
//            case 'u':
//                M = Union(M1,M2);
//                cout<<"����"<<endl;
//                ShowMatrix(M);
//                break;
//            case 'C':
//            case 'c':
//                Mx CM;
//                M = Complement(M1);
//                CM = Complement(M2);
//                cout<<"��һ������Ĳ���"<<endl;
//                ShowMatrix(M);
//                cout<<"�ڶ�������Ĳ���"<<endl;
//                ShowMatrix(CM);
//                DeleteMatrix(CM);
//                break;
//            case 'D':
//            case 'd':
//                M = DifferenceOfSet(M1,M2);
//                cout<<"�"<<endl;
//                ShowMatrix(M);
//                break;
//            default:
//                if(q=='q'||q=='Q'){
//                    cout<<"�˳�����"<<endl;
//                }
//                else
//                    cout<<"�Ҳ����ô���������Ĳ��������������롣";
//                break;
//
//
//        }//switch
//        DeleteMatrix(M);
//    }//while
    Mx M;
    InputVertex(M);
    cout<<"���������Ϣ��"<<endl;
    MatrixCvt(M);
    cout<<"�ڽӾ������£�"<<endl;
    ShowMatrix(M);



}
