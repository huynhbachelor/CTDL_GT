#ifndef DICTIONARY_H
#define DICTIONARY_H



#include "File.h"
#include <math.h>
#include <winbgim.h> 
using namespace std;



#define MAXSTR 100
#define TRUE  1
#define FALSE  0
#define ENTER  13
#define TAB  9
#define UP  72
#define DOWN 80



//Bang Mau
enum color{
	BLACK,
	BLUE,
	GREEN,
	CYAN,
	RED,
	MANGETA,
	BROWN,
	LIGHTGRAY,
	DARKGRAY,
	LIGHTBLUE,
	LIGHTGREEN,
	LIGHTCYAN,
	LIGHTRED,
	LIGHTMAGENTA,
	YELOW,
	WHILE
};


struct button{
	int x=50;
	int y=30;
	int Wight=50;
	int Height=20;
	int color;
	char* text;
};

struct textbox{
	int vt_nhay=0;
	int x;
	int y;
	int Wight=400;
	int Height=20;
	int color;
	string text;
};


char* convert_string(string &str);
string convert_string(char *);
void Ve_btn(struct button &btn);
int btn_checked(struct button &btn,int x, int y);
void Ve_txt(struct textbox &txt);
int txt_checked(struct textbox &txt,int x, int y);
int Nhap_text(struct textbox &txt);
int txt_changed(struct textbox &txt);
void out_word(word w);








#endif
