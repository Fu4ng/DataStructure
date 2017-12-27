#include <iostream>
#include <fstream>
#include "Huffman.h"
using namespace std;

#define CAF_FILE "D:\\Code\\HuffmanTree\\CAF.txt"
#define TBT_FILE "D:\\Code\\HuffmanTree\\ToBeTran.txt"
#define HFMTREE_FILE "D:\\Code\\HuffmanTree\\hfmTree.txt"
#define TEXT_FILE "D:\\Code\\HuffmanTree\\TextFile.txt"
#define CODE_FILE "D:\\Code\\HuffmanTree\\CodeFile.txt"
int main() {
    FrePoint f;
    cout<<"input n:"<<endl;
    int n;cin>>n;
    cin.ignore();
    //Input and store Character's frequency.
    //w and c
    int *w = new int[n];char *c = new char[n];
    InputCharacter(f,n,w,c);
    StoreText();

    HuffmanTree HT;
    CreateHuffmanTree(HT,w,n);
    StoreHfmTree(HT,n);


}
