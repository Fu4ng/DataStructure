//
// Created by Fu4ng on 2017/10/2.
//

#include <iostream>

using namespace std;
#define MAXSIZE 100
#define INCREASE 10
typedef int Elemtype;


typedef struct {
    Elemtype *base;
    int length;
    int listsize;
} Sqlist;

//function
void InitList(Sqlist &L);
void ListInset(Sqlist &L, int index, Elemtype e);
void ListDelete(Sqlist &L, int index);
void ListSort(Sqlist &L, bool cmp = 1); //cmp =1 Ascending sort cmp =0 Descending sort
void IncreaseSize(Sqlist &L); //increase memory when it not enough
int SearchList(Sqlist &L, Elemtype e);
int BinarySearch(Sqlist L, Elemtype e);
void display(Sqlist L);

// MAIN
int main() {
    Sqlist L;
    InitList(L);
    cout<<"input 5 number"<<endl;
    int a[5];
    for (int j = 0; j <5; ++j) {
        cin>>a[j];
        ListInset(L,j,a[j]);
    }
    ListDelete(L, 5);
    cout<<"=== after delete last elem==="<<endl;
    display(L);
    cout<<"=== after sort ==="<<endl;
    ListSort(L);
    display(L);
    cout<<"input the number you want to search"<<endl;
    int s;
    cin>>s;
    cout << SearchList(L, s) << endl;
    cout << BinarySearch(L, s) << endl;
}


void IncreaseSize(Sqlist &L) {
    //backups
    Elemtype *p = new int[sizeof(Elemtype) * L.listsize];
    int i = 0;
    while (i++ < L.length) {
        p[i] = L.base[i];
    }
    i = 0;
    //delete and rebuild
    delete L.base;
    L.listsize += INCREASE;
    L.base = new int[sizeof(Elemtype) * L.listsize];
    while (i++ < L.length) {
        L.base[i] = p[i];
    }
    delete p;
}

void InitList(Sqlist &L) {
    L.base = new int[sizeof(Elemtype) * MAXSIZE];
    L.length = 0;
    L.listsize = MAXSIZE;
}

void ListInset(Sqlist &L, int index, Elemtype e) {
    if (L.length == L.listsize) IncreaseSize(L);
    for (int i = L.length; i > index; i--) {
        L.base[i] = L.base[i - 1];
    }
    L.base[index] = e;
    L.length++;
}

void ListDelete(Sqlist &L, int index) {
    if (!L.length) {
        cout << "length = 0  Can't Delete!!!!" << endl;
    }
    for (int i = index; i < L.length; ++i) {
        L.base[index] = L.base[index + 1];
    }
    L.length--;
}

void ListSort(Sqlist &L, bool cmp) {//default cmp =1
    bool flag=0;
    if (cmp) {//cmp =1 Ascending
        for (int i = 0; i < L.length; ++i) {
            if (flag) break;
            flag =1;
            for (int j = i; j < L.length; ++j) {
                if (L.base[i] >= L.base[j]) {
                    flag = 0;
                    swap(L.base[i],L.base[j]);
                }
            }
        }
    } else {//cmp =0 Descending
        for (int i = 0; i < L.length; ++i) {
            if(flag) break;
            flag = 1;
            for (int j = i; j < L.length; ++j) {
                if (L.base[i] <= L.base[j]) {
                    flag = 0;
                    swap(L.base[i],L.base[j]);
                }
            }
        }
    }
}

void display(Sqlist L){
    for (int k = 0; k <L.length; ++k) {
        cout<<L.base[k]<<" ";
    }
    cout<<endl;
}
int SearchList(Sqlist &L, Elemtype e) {
    if (!L.length) {
        cout << "length = 0,Can't Search!!!!" << endl;
    }
    for (int i = 0; i < L.length; ++i) {
        if (L.base[i] == e) return i;
    }
    return -1;
}

int BinarySearch(Sqlist L, Elemtype e) {
    ListSort(L);
    int low = 0;
    int high = L.length - 1;
    while (low <= high) {
        int mid = (low + high) / 2;
        if (L.base[mid] == e) return mid;
        if (L.base[mid] < e) low = mid + 1;
        else
            high = low - 1;
    }
    return -1;
}