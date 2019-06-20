#ifndef FILE_H
#define FILE_H

#include <iostream>
#include <fstream>
#include "Dic.h"

using namespace std;

void Save_List(HashTable &Dic);
void Read_Line(string line, word &w);
void Read_List(HashTable &Dic);

//Khong lam duoc
void Save_List_Bin(HashTable &Dic);
void Read_List_Bin(HashTable &Dic);

#endif
