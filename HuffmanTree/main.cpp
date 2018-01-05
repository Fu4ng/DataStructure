#include <iostream>
#include <fstream>
#include "Huffman.h"
//template <typename T>;
using namespace std;
#define CAF_FILE "D:\\Code\\HuffmanTree\\HuffmanTree\\CAF.txt"
#define TBT_FILE "D:\\Code\\DataStructure\\HuffmanTree\\ToBeTran.txt"
#define HFMTREE_FILE "D:\\Code\\HuffmanTree\\HuffmanTree\\hfmTree.txt"
#define TEXT_FILE "D:\\Code\\HuffmanTree\\HuffmanTree\\TextFile.txt"
#define CODE_FILE "D:\\Code\\HuffmanTree\\HuffmanTree\\CodeFile.txt"
#define HC_FILE "D:\\Code\\HuffmanTree\\HuffmanTree\\HC.txt"
int main() {
//    FrePoint f;
//    cout<<"input n:"<<endl;
//    int n;cin>>n;
//    cin.ignore();
//    //Input and store Character's frequency.
//    //w and c
//    int *w = new int[n];char *c = new char[n];
//    InputCharacter(f,n,w,c);
//    StoreText();
//                此部分代码可用于快速测试（不用输入27个字符）
//    int w[27]={186,64,13,22,32,103,21,15,47,57,1,5,32,20,57,63,15,
//               1,48,51,80,23,8,18,1,16,1};
//    char c[27] = {' ','A','B','C','D','E','F','G','H','I','J','K','L','M','N','O','P',
//                  'Q','R','S','T','U','V','W','X','Y','Z'};
//    int n = 27;
//    // de
//    HuffmanTree HT;
//    CreateHuffmanTree(HT,w,n);
//    StoreHfmTree(HT,n);
//    HuffmanCode HC;
//    HuffmanCoding(HT,HC,n);
//    Encoding_RAM(HC,c);
//    Decoding(HT,w,c,n);
//    ReadPrintCode();
    HuffmanTree HT;
    HuffmanCode HC;
    char q =Menu();
    int *w;char *c;
    while(q!='Q'|| q!='q'){
        switch(q){
            case 'I'://Initialization
            case 'i':
                //Ini
                FrePoint f;
                cout<<"input n:"<<endl;
                int n;cin>>n;
                cin.ignore();
                w = new int[n]; c = new char[n];
                InputCharacter(f,n,w,c);
                StoreText();
                CreateHuffmanTree(HT,w,n);
                StoreHfmTree(HT,n);
                break;
            case 'E': //Encoding
            case 'e':
                HuffmanCoding(HT,HC,n);
                cout<<"HuffmanTree in RAM?(Y/N)"<<endl;
                char h;cin>>h;
                if(h=='Y'||h=='y') Encoding_RAM(HC,c);
                else Encoding_FILE(c);
                break;
            case 'D'://Decoding
            case 'd':
                Decoding(HT,w,c,n);
                cout<<"Save successfully!"<<endl;
                break;
            case 'P':
            case 'p':
                ReadPrintCode();
                break;
            case 'Q':
            case 'q':
                cout<<"QUIT!";
                break;
            default:
                cout<<"Wrong input.Enter again!"<<endl;
                break;
        }
        q=Menu();

    }

}
