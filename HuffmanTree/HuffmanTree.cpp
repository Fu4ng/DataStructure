//
// Created by Fu4ng on 2017/12/26.
//
#include <iostream>
#include <cstring>
#include <fstream>
#include "Huffman.h"
using namespace std;
#define MAX 100
#define CAF_FILE "D:\\Code\\DataStructure\\HuffmanTree\\CAF.txt"
#define TBT_FILE "D:\\Code\\DataStructure\\HuffmanTree\\ToBeTran.txt"
#define HFMTREE_FILE "D:\\Code\\DataStructure\\HuffmanTree\\hfmTree.txt"
#define TEXT_FILE "D:\\Code\\DataStructure\\HuffmanTree\\TextFile.txt"
#define CODE_FILE "D:\\Code\\DataStructure\\HuffmanTree\\CodeFile.txt"
#define HC_FILE "D:\\Code\\DataStructure\\HuffmanTree\\HC.txt"
#define CODE_PRIN "D:\\Code\\DataStructure\\HuffmanTree\\CodePrin.txt"
#define TREE_PRIN "D:\\Code\\DataStructure\\HuffmanTree\\TreePrin.txt"
#define CODESIZE 50  //print codeFile 50 code echo line

//HuffmanTree's functions
void Select(HuffmanTree HT,int i,int &s1,int &s2){
    int min =0;
    for (int j = 1; j <=i ; ++j) {
        if(HT[j].parent==0){
            min = j;
            break;
        }
    }//for
    for (int k = 1; k <=i ; ++k) {
        if(HT[k].parent==0){
            if(HT[k].weight<HT[min].weight) min =k;
        }
    }
    s1 = min;
    for (int j = 1; j <=i ; ++j) {
        if(HT[j].parent==0&& j!= s1){
            min = j;
            break;
        }
    }//for
    for (int l = 1; l <=i ; ++l) {
        if(HT[l].parent == 0 && l != s1){
            if(HT[l].weight<HT[min].weight) min =l;
        }
    }
    s2 = min;

}
void CreateHuffmanTree(HuffmanTree &HT,int *w,int n){
    //"w" used to store the n weights.
    //HuffmanTree T;
    if(n<=1)
        return ;
    int m = 2*n-1;
    HT = new HTNode [m+1];
    int i;
    for(i=1;i<m+1;++i){
        if(i<=n) HT[i].weight = w[i-1];
        HT[i].parent = 0;HT[i].lchild=0;HT[i].rchild =0;
    }
    int s1,s2;
    for (int j = n+1; j <=m ; ++j) {
        Select(HT,j-1,s1,s2);//choose the smallest two weights
        HT[s1].parent = j;
        HT[s2].parent = j;
        HT[j].rchild = s2;
        HT[j].lchild = s1;
        HT[j].weight = HT[s1].weight+HT[s2].weight;
    }
}
void Encoding_RAM(HuffmanCode HC,char *c){
     //"c" is used to find the index of character in HC table
    //data is store in this format "C:0102"
    fstream Textfile;
    Textfile.open(TBT_FILE,ios::in|ios::out);
    string temps;string code; //"code" will be written on CodeFile.
    char temp; //get one char each time.
    Textfile>>noskipws;
    while(Textfile>>temp){
        if(temp =='\n'){
            code +='\n'; //write to code
            cout<<"\n\n";//write to screen
        }//if
        else{
            //cout<<HC[index(c,temp)+1];
            temps = HC[index(c,temp)+1];
            //temps=temps.substr(2); //read temp_s from third character.
            code+=temps;
        }//else
    }//while
    cout<<"Code is:"<<code<<endl;
    char choose;
    cout<<"Do you want to save the code?(Y/N)";
    cin>>choose;
    if(choose = 'Y'||choose =='y'){
        //char *cvt = new char [strlen(code)+1];
        char *cvt = (char *)code.data();
        StoreCode(cvt);
        //delete cvt;
    }
}  //HuffmanCode in RAM
void Encoding_FILE(char *c){
    int len= 0;
    while(c[len]!='\0'){
        len++;
    }
    HuffmanCode E_HC = new char* [len+1];
    ReadHC(E_HC);
    Encoding_RAM(E_HC,c);
}                //HuffmanCode in FILE
void HuffmanCoding(HuffmanTree HT,HuffmanCode &HC,int n){
    int start,e,f;
    HC = new char*[n+1];
    char *cd = new char[n];
//    for(int i=0;i<n;i++) cd[i]='0';
    cd[n-1] = '\0';
    for(int j = 1; j <=n ; ++j){
        start =n-1;
        e =j;f =HT[j].parent;
        while(f!=0){
            --start;
            if(HT[f].lchild == e) cd[start]='0';
            else cd[start] ='1';
            e = f;f=HT[f].parent;
        }
        HC[j]=new char[n-start];
        strcpy(HC[j],&cd[start]);
        //cout<<HC[j];
    }

//    for(int i =0;i<n;i++)
//    {
//        cout<<HC[i]<<endl;
//    }
    delete cd;
}
void Decoding(HuffmanTree HT,int *w,char *c,int n){
    string text,code;
    ifstream ifile;
    ifile.open(CODE_FILE,ios::in);
    ifile>>code;
    ifile.close();// CodeFile reading is completed
    int i = 0;
    HuffmanTree T = (HT+(2*n-1));
    int t;
    while(code[i]){
        //end condition of loop is "code" string is read completed
        if(code[i]=='0'){
            t = (*T).lchild;
            T = HT+t;
        }
        else {
            t = (*T).rchild;
            T = HT+t;
        }
        if((*T).lchild==0 && (*T).rchild ==0){
            text += c[index(w,(*T).weight)];
            T = (HT+(2*n-1)); //reset
        }//if
        i++;
    }//while
    ofstream ofile;
    ofile.open(TEXT_FILE,ios::out);
    ofile<<text;
    ofile.close();
}

void DisFrequency(FrePoint f,int n){
    for (int i = 0; i < n; i++) {
        cout << f[i].a << ":" << f[i].n << endl;
    }
}
void InputFrequancy(FrePoint &f,int n,int *w,char *c) {
    //"w" used to store the weight converted from frequency.
    //"c" used to store the characters.
    f = new Frequency[n];
    for (int i = 0; i < n; ++i) {
        cout << "input " << i + 1 << "th's character :";
        f[i].a = char(cin.get());
        cout << "input " << f[i].a << "'s frequency :";
        cin >> f[i].n;
        // cin.clear();
        cin.ignore();
    }
    cout << "==Input is complete==" << endl;
    cout << "==Check the input==" << endl;
    DisFrequency(f, n);
    StoreFrequency(f, n);
    for (int j = 0; j < n ; ++j) {
        w[j] = f[j].n;
        c[j] = f[j].a;
    }
}
void InputCharacter(FrePoint &f,int n,int *w,char *c){
    //int flag = 1;
    cout << "==========input Character and it's Frequency.=====" << endl;
    //while(flag){
        FrePoint ch;
        InputFrequancy(ch,n,w,c);
        cout << "===============" << endl;
        //DisFrequency(f,n);
        //cout << "Enter 1 if correct,otherwise enter 0" << endl;
        //cin >> flag;
        //if(!flag){
            //delete ch;
            //cout<<"please enter character and frequency again"<<endl;
        //}//if
    //}//while
    delete f;
}

void StoreFrequency(FrePoint f,int n){
    //"r" is path of file
    ofstream ofile;
    ofile.open(CAF_FILE,ios::out);
    for(int i = 0;i<n;i++){
        ofile<<f[i].a<<":"<<f[i].n<<endl;
    }
    ofile.close();
}
void StoreText(){
    string s;
    cout<<"====input text===="<<endl;
    getline(cin,s);
    ofstream ofile;
    ofile.open(TBT_FILE,ios::out);
    ofile<<s;
    //ofile.write((char *)&a,L);
    ofile.close();
}
void StoreHfmTree(HuffmanTree HT,int n){
    HuffmanTree T =HT;
    ofstream ofile;
    ofile.open(HFMTREE_FILE,ios::out);
    ofile<<"N-W-P-L-R"<<endl;
    for (int i = 1; i <=2*n-1 ; ++i) {
        ofile<<i<<"-"<<T[i].weight<<"-";
        ofile<<T[i].parent<<"-"<<T[i].lchild<<"-"<<T[i].rchild<<endl;

    }
}
void StoreCode(char *t){
    //"t" is code
    fstream ofile;
    ofile.open(CODE_FILE,ios::out);
//    int L = int(strlen(t));
//    ofile.write((char *)&t,L);
    ofile<<t;
    ofile.close();
}
void StoreHC(HuffmanCode HC,char *c){
    //c is the characters
    fstream ofile;
    ofile.open(HC_FILE);
    for(int i=0;HC[i];i++){
        ofile<<HC[i]<<endl;
    }
    ofile.close();
}
void StoreCodePrin(string s){
    ofstream code;
    code.open(CODE_PRIN);
    code<<s;
    code.close();
}

void ReadHfmTree(HuffmanTree &HT){
    ifstream ifile;
    ifile.open(HFMTREE_FILE);
    string s;
    int lineCount =0; //store the number of the rows
    while(getline(ifile,s)){
        lineCount++;
    }//This time,file-stream-pointer at the end of the file
    ifile.close();
    ifstream ifile2;
    ifile.open(HFMTREE_FILE);//Back to the beginning of the file
    getline(ifile2,s);//read the first line that has not been used
    HT = new HTNode[lineCount]; //malloc
    //HT's first Node is not used,and the first line of "hfmTree.txt" is not used.
    for (int i = 1; i <lineCount ; ++i) {
        //The data is store in this format "N-W-P-L-R".
        // "N" represents the order.
        getline(ifile2,s);
        char *ch = (char *)s.data();// because second argument of atoi() is 'char'
        HT[i].weight = atoi(ch);   //read weight
        while(*ch != '-') ch++;   //find '-' position
        ch++;                       //pass '-' position
        HT[i].parent = atoi(ch);
        while(*ch != '-') ch++;
        ch++;
        HT[i].lchild = atoi(ch);
        while(*ch != '-') ch++;
        ch++;
        HT[i].rchild = atoi(ch);
    }
    ifile2.close();
}
void ReadPrintCode(){
    fstream ifile;
    ifile.open(CODE_FILE,ios::in|ios::out);
    string code;
    // It is also possible to use "char" here,
    // but it is more convenient to use "string"
    char temp;int t =0;
    while(ifile>>temp){//read CodeFile ,one character echo time
        code+=temp;
        t++;
        if(t==50){
            code+='\n';
            t = 0;
        }
    }
    cout<<"CODEFILE:"<<endl<<code<<endl;
    ifile.close();
    StoreCodePrin(code);

}
void ReadHC(HuffmanCode &HC){
    ifstream ifile;
    ifile.open(HC_FILE);
    string s;int i =0;
    while(getline(ifile,s)){
        s = s.substr(2);
        HC[i] = (char *)s.data();
    }
    ifile.close();
}

char Menu(){
    cout<<"================================"<<endl<<endl;
    cout<<"            I.Initialzation"<<endl;
    cout<<"            E.Encoding"<<endl;
    cout<<"            D.Decoding"<<endl;
    cout<<"            P.PrintCode"<<endl;
    cout<<"            T.PrintTree"<<endl;
    cout<<"            Q.Quit"<<endl;
    cout<<endl<<endl<<"================================"<<endl<<endl;
    char q;
    cin>>q;
    return q;
}

