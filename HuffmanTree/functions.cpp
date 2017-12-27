//
// Created by Fu4ng on 2017/12/26.
//

#include <iostream>
#include <fstream>
#include "Huffman.h"
using namespace std;

//small function
int index(char *a,char c){
    int i = 0;
    while(c!=a[i]){
        i++;
    }
    return i;
}