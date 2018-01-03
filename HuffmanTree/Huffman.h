//
// Created by Fu4ng on 2017/12/26.
//

#ifndef HUFFMANTREE_HUFFMAN_H
#define HUFFMANTREE_HUFFMAN_H

#endif //HUFFMANTREE_HUFFMAN_H
//HuffmanTree's data structure
using namespace std;
typedef struct {
    int weight;
    int parent,lchild,rchild;
}HTNode,*HuffmanTree;

typedef char **HuffmanCode;


typedef struct{
    int n;  // the frequency of character
    char a; //store character
}Frequency,*FrePoint;

void Select(HuffmanTree  HT,int i,int &s1,int &s2);
void CreateHuffmanTree(HuffmanTree &HT,int *w,int n);
void DisHuffman(HuffmanTree HT,int m);
void HuffmanCoding(HuffmanTree HT,HuffmanCode &HC,int n);
void Encoding_RAM(HuffmanCode HC,char *c);   //HuffmanCode in RAM
void Encoding_FILE(char *c);                //HuffmanCode in FILE
void InputFrequancy(FrePoint &f,int n,int *w,char *c);
void InputCharacter(FrePoint &f,int n,int *w,char *c);
void DisFrequency(FrePoint f,int n);
//void PrintTree(HuffmanTree HT,char *c,int *w,int n);
void StoreFrequency(FrePoint f,int n);
void StoreText();
void StoreHfmTree(HuffmanTree HT,int n);
void ReadHfmTree(HuffmanTree &HT);
void StoreCode(char *s);
void StoreCodePrin(string s);
void ReadPrintCode();
void StoreHC(HuffmanCode HC,char *c);
void ReadHC(HuffmanCode &HC);
void Decoding(HuffmanTree HT,int *w,char *c,int n);
char Menu();

//
template<typename T>
int index(T *a,T c){
    int i = 0;
    while(c!=a[i]){
        i++;
    }
    return i;
}

