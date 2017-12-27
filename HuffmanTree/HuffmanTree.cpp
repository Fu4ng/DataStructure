//
// Created by Fu4ng on 2017/12/26.
//
#include <iostream>
#include <cstring>
#include <fstream>
#include "Huffman.h"
using namespace std;
#define MAX 100
#define CAF_FILE "D:\\Code\\HuffmanTree\\CAF.txt"
#define TBT_FILE "D:\\Code\\HuffmanTree\\ToBeTran.txt"
#define HFMTREE_FILE "D:\\Code\\HuffmanTree\\hfmTree.txt"
#define TEXT_FILE "D:\\Code\\HuffmanTree\\TextFile.txt"
#define CODE_FILE "D:\\Code\\HuffmanTree\\CodeFile.txt"
#define HC_FILE "D:\\Code\\HuffmanTree\\HC.txt"

//HuffmanTree's functions
void Select(HuffmanTree HT,int i,int &s1,int &s2){
    s1 = 0; s2 =0;
    for (int j = 1; j < i ; ++j) {
        if(HT[j].weight >= HT[s1].weight){
            s2 = s1; s1 = j;
        }//if
        else{
            //HT[j].weight is not greater than HT[s1].weight,
            // but may be greater than HT[s2].weight
            if(HT[j].weight>HT[s2].weight){
                s2 = j;
            }
        }//else
    }//for
}
void CreateHuffmanTree(HuffmanTree &HT,int *w,int n){
    //"w" used to store the n weights.
    HuffmanTree T;
    if(n<=1)
        return ;
    int m = 2*n-1;
    HT = new HTNode[m+1];
    int i;
    for(T=HT+1,i=1;i<=m+1;++i,++T,++w){
        if(i<=n)T->weight = *w;
        T->parent = 0;T->lchild=0;T->rchild =0;
    }
    //
    int s1,s2;
    for (int j = n+1; j <=m ; ++j) {
        Select(HT,j-1,s1,s2);//choose the smallest two weights
        HT[s1].parent = j;
        HT[s2].parent = j;
        HT[j].rchild = s1;
        HT[j].lchild = s2;
        HT[j].weight = HT[s1].weight+HT[s2].weight;
    }
}
void Encoding_RAM(HuffmanCode HC,char *c){
     //"c" is used to find the index of character in HC table
    //data is store in this format "C:0102"
    fstream Textfile;
    Textfile.open(TBT_FILE,ios::in|ios::out);
    string code; //"code" will be written on CodeFile.
    char temp; //get one char each time.
    string temp_s;
    while(Textfile>>temp){
        if(temp =='\n'){
            code +='\n'; //write to code
            cout<<"\n\n";//write to screen
        }//if
        else{
            temp_s = HC[index(c,temp)];
            temp_s=temp_s.substr(2); //read temp_s from third character.
            cout<<temp_s; //write to screen.
            code+=temp_s;
        }//else
    }//while
    cout<<endl;
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
    HC = new char* [n+1];
    char *cd = new char[n];
    cd[n-1]='\0';
    for (int j = 1; j <=n ; ++j) {
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
    }
    delete cd;
}
void DisHuffman(HuffmanTree HT,int m){
    cout<<" Huffman Table"<<endl;
    cout<<"================="<<endl;
    HuffmanTree i;
    int j;
    for (i = HT+1,j=1;j<=m; ++j,i++) {
        cout<<"++  "<<j<<" "<<i->weight<<" "<<i->parent<<" "<<i->lchild<<" "<<i->rchild<<"  ++"<<endl;
    }
    cout<<"=================="<<endl;
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
void DisFrequency(FrePoint f,int n){
    for (int i = 0; i < n; i++) {
        cout << f[i].a << ":" << f[i].n << endl;
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
    ofile.open(CAF_FILE);
    for(int i = 0;i<n;i++){
        ofile<<f[i].a<<":"<<f[i].n<<endl;
    }
    ofile.close();
}
void StoreText(){
    string s;
    cout<<"====input text===="<<endl;
    getline(cin,s);
    fstream ofile;
    ofile.open(TBT_FILE,ios::out);
    ofile<<s;
    //ofile.write((char *)&a,L);
    ofile.close();
}
void StoreHfmTree(HuffmanTree HT,int n){
    HuffmanTree T =HT;
    fstream ofile;
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
    ofile.open(CODE_FILE);
    int L = int(strlen(t));
    ofile.write((char *)&t,L);
    ofile.close();
}
void StoreHC(HuffmanCode HC,char *c){
    //c is the characters
    fstream ofile;
    ofile.open(HC_FILE);
    for(int i=0;HC[i];i++){
        ofile<<c[i]<<":"<<HC[i]<<endl;
    }
    ofile.close();
}

void ReadHfmTree(HuffmanTree &HT){
    ifstream ifile;
    ifile.open(HFMTREE_FILE);
    string s;
    int lineCount =0; //store the number of the rows
    while(getline(ifile,s)){
        lineCount++;
    }//This time file-stream-pointer at the end of the file
    ifile.close();
    ifstream ifile2;
    ifile.open(HFMTREE_FILE);//Back to the beginning of the file
    getline(ifile2,s);//read the first line that has not been used
    HT = new HTNode[lineCount];
    //HT's first Node is not used,and the first line of "hfmTree.txt" is not used.
    for (int i = 1; i <lineCount ; ++i) {
        //The data is store in this format "N-W-P-L-R".
        // "N" represents the order.
        getline(ifile2,s);
        HT[i].weight = int(s[2]);
        HT[i].parent = int(s[4]);
        HT[i].lchild = int(s[6]);
        HT[i].rchild = int(s[8]);
    }
    ifile2.close();
}
void ReadPrintCode(){
    fstream ifile;
    ifile.open(CODE_FILE,ios::in|ios::out);
    string s;
    // It is also possible to use "char" here,
    // but it is more convenient to use "string"
    while(getline(ifile,s)){
        cout<<s<<endl;
    }
    ifile.close();
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

