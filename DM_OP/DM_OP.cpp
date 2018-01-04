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
    cout<<"    ÊäÈëÄãÒªÖ´ÐÐµÄ²Ù×÷´úÂë"<<endl;
    cout<<"         I.Çó½»¼¯"<<endl;
    cout<<"         U.Çó²¢¼¯"<<endl;
    cout<<"         C.Çó²¹¼¯"<<endl;
    cout<<"         D.Çó²î¼¯"<<endl;
    cout<<"         Q.ÍË³ö³ÌÐò"<<endl;
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
    cout<<"ÊäÈë¶¥µãÊý£¨ÐÐ£©£º";
    cin>>rowV;
    cout<<"ÊäÈë¶¥µãÊý£¨ÁÐ£©£º";
    cin>>colV;
    M.rows = rowV;
    M.cols = colV;
    M.rowChar = new char [rowV+1];
    M.colChar = new char [colV+1];
    temp = rowV;
    CreateMatrix(M);
    cout<<"ÊäÈëÐÐ¶¥µã£¨ÓÃ¿Õ¸ñ¸ô¿ª£©"<<endl;
    while(temp--){
        cin>>M.rowChar[rowV-temp-1];
    }
    M.rowChar[M.rows]='\0';
    cout<<"ÊäÈëÁÐ¶¥µã£¨ÓÃ¿Õ¸ñ¸ô¿ª£©"<<endl;
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
    cout<<"ÊäÈë¾ØÕóµÄ¹ØÏµÊý£º";
    cin>>t;
    char v1;char v2; // the two vertices that have relations
    int v1Index,v2Index;
    int z =0;
    while(z++<t){
        cout<<"ÊäÈëµÚ"<<z<<"¸ö¹ØÏµ"<<endl;
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

void CS(Mx &M) {  //ÑéÖ¤×Ô·´
    int s=0;
    for(int i =0;i<M.rows;i++)
        s+=M.matrix[i][i];
    if(s == M.rows)
        cout<<"¾ßÓÐ×Ô·´"<<endl;
    else
        cout<<"²»¾ßÓÐ×Ô·´"<<endl;
}
void MS(Mx &M) {
    //¼ìÑé¶Ô³Æ
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
                cout<<"²»¾ßÓÐ¶Ô³Æ"<<endl;
                i = s+1;j = s+1;
                f =0;
            }
        }
    }
    if(f) cout<<"¾ßÓÐ¶Ô³ÆÐÔ"<<endl;
}
void IS(Mx &M) {
    //¼ìÑé´«µÝ
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
        cout<<"¾ßÓÐ´«µÝÐÔ"<<endl;
    else
        cout<<"¾ßÓÐ´«µÝÐÔ"<<endl;
}

//
bool MatrixEqual(Mx M1,Mx M2){ //ÅÐ¶ÏÁ½¸ö¾ØÕóÊÇ·ñÏàµÈ
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
                    i = M1.rows; //Ìø³öÑ­»·
                    break;
                }
            }//for
        }//for
    }//else
    return eq;
}
void CreateI(Mx &M, int n ){
    //½¨Á¢Ò»¸ö¶Ô½ÇÏßÎª1 µÄ¾ØÕó
    M.cols = n;M.rows = n;
    CreateMatrix(M);
    InitialMatrix(M);
    for (int i = 0; i < n; ++i) {
        M.matrix[i][i] = 1;
    }
}
Mx MatrixMul(Mx M,Mx M1){
    //¾ØÕóÏà³Ë
    Mx M2;
    M2.cols = M.cols;
    M2.rows = M.rows;
    CreateMatrix(M2);
    for(int i = 0;i<M.rows;i++){
	for(int j = 0;j<M.cols;j++){
		for(int k = 0;k<M.rows;k++){
			M2.matrix[i][j]+= (M.matrix[i][k]*M1.matrix[k][i]);
		}
	}//sed for
    }//fst for
    return M2;
}

void BCS(Mx M){//Í¨¹ý±Õ°üÑéÖ¤×Ô·´
    Mx M1 ,I;
    CreateI(I,M.cols);
    CopyMatrix(M1,M);
    M1 = Union(M,I);
    if(MatrixEqual(M,M1)) cout<<"==¾ØÕó×Ô·´=="<<endl;
    else cout<<"==¾ØÕó²»×Ô·´=="<<endl;

}
void BMS(Mx M){
    Mx M1;
    CopyMatrix(M1,M);
    for (int i = 0; i <M1.cols ; ++i) {
        for (int j = 0; j < M1.rows; ++j) {
            if(M1.matrix[i][j]==1) M1.matrix[j][i]=1;
        }
    }//for
    if(MatrixEqual(M,M1)) cout<<"==¾ØÕó¶Ô³Æ=="<<endl;
    else cout<<"==¾ØÕó²»¶Ô³Æ=="<<endl;
}
void BIS(Mx M){
    //ÅÐ¶Ï¾ØÕóÊÇ·ñ´«µÝ
    Mx M1;
    Mx M2;
    int n = M.cols;
    CopyMatrix(M1,M);
    CopyMatrix(M2,M);
    while(n--){
	M1 = MatrixMul(M,M1);
	M2 = Union(M1,M2);
    }//¿¿M¿n¿¿
    if(MatrixEqual(M,M2)) cout<<"¿¿¿¿"<<endl;
    else cout<<"¿¿¿¿¿"<<endl;
}
Mx Achieve(M){
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

