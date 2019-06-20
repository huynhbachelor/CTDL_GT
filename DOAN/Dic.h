
#ifndef DIC_H
#define DIC_H

#include <iostream>
#include "Chuoi.h"
using namespace std;

//Khai bao

typedef struct ViDu {
    string data;
    struct ViDu *next; 
};
typedef struct ViDu *List_VD;

typedef struct Word{
	string Tu;
	string Loai;
	string Nghia[5];
	List_VD VD=NULL;
	struct Word* Left;
	struct Word* Right;
};

typedef struct Word* word;


struct D_List{
	word Head , Tail;	
};

struct HashTable{
	D_List Hash[26];
};

void Init(D_List &L);
void Init_Dic(HashTable &H);
int Isempty (D_List &L);
void Insert_first (D_List &L, word w);
void Insert_last (D_List &L, word w);
int Insert_last_word(D_List &L, word w);
word Seach_word(HashTable &Dic, string &s);
//int Insert_last_word(HashTable &Dic, word w);
void Del_first (D_List &L);
void Del_last (D_List &L);
int Del_word(D_List &L,word &w);
int Lengh(D_List L);
int Del_k (D_List &L,int k);
word Edit_k (D_List &L,int k);
void Output (D_List &L);
void KhoiTao (List_VD &L);
List_VD TaoMoi (List_VD P, string &x);
void ThemViDu (List_VD &L, string x);
int size(List_VD L);
int Sua_vt_k(List_VD &L, string &x, int k);
void Out_dsVD(List_VD &L);
int Delete_ListVD(List_VD &L);

#endif
