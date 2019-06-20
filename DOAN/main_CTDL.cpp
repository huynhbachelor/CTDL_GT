/* 
graphics in Dev-C++ - Huynh Xuan Bach
*/



#include "File.h"
#include <math.h>
#include <winbgim.h> 
#include"Dictionary.h"



#define MaxX 800
#define MaxY 540

struct button btnSave, btnEdit, btnOk, btnDelete,btnAdd;
struct textbox txtNhap;

void GiaoDien(){
	setbkcolor(15);
	cleardevice();	
	
	setcolor(1);
	settextstyle(1,0,5);
	
	outtextxy(120,40,"Tu dien Anh - Viet");
	
	settextstyle(0,0,1);
	setcolor(1);
	line(0,60,MaxX,60);
	
	txtNhap.x=10;
	txtNhap.y=70;
	txtNhap.color=0;
	Ve_txt(txtNhap);
	
	btnOk.x=420;
	btnOk.y=70;
	btnOk.color=0;
	btnOk.text="OK";
	Ve_btn(btnOk);
	
	btnEdit.x=480;
	btnEdit.y=70;
	btnEdit.color=0;
	btnEdit.text="Edit";
	Ve_btn(btnEdit);
	
	btnAdd.x=540;
	btnAdd.y=70;
	btnAdd.color=0;
	btnAdd.text="Add";
	Ve_btn(btnAdd);
	
	btnDelete.x=600;
	btnDelete.y=70;
	btnDelete.Wight=70;
	btnDelete.color=0;
	btnDelete.text="Delete";
	Ve_btn(btnDelete);
	
		
	btnSave.x=680;
	btnSave.y=70;
	btnSave.color=0;
	btnSave.text="Save";
	Ve_btn(btnSave);
	
	setcolor(1);
	rectangle(10,109,151,511);
	rectangle(200,110,MaxX-30,510);
	
}

word out_list(HashTable &Dic, string &s){
	int i=0;
	word tmp= Seach_word(Dic,s);
	if(tmp==NULL){
		return NULL;
	}
	while(1){
		if(tmp==Dic.Hash[(s[0]-97)].Tail||i==19){
			outtextxy(20,125+i*20,convert_string(tmp->Tu));
			break;
		}
		setcolor(1);
		if(i==0){
			rectangle(11,110+i*20,150,110+20+i*20);
		}
		outtextxy(20,125+i*20,convert_string(tmp->Tu));
		tmp=tmp->Right;
		i++;
	}
	return Seach_word(Dic,s);
}

void Xoa_TreeTk(){
	setfillstyle(1,15);
	bar(10,109,151,511);
	setcolor(1);
	rectangle(10,109,151,511);
}

void Xoa_bang(){
	setfillstyle(1,15);
	bar(200,110,MaxX-30,510);
	setcolor(1);
	rectangle(200,110,MaxX-30,510);
}

word ChonTu(HashTable &Dic, word &w){
	char c;
	int i=0;
	word tmp=w;
	setcolor(1);
	rectangle(11,110+i*20,150,110+20+i*20);
	Xoa_bang();
	out_word(tmp);
	while(1){
		delay(0.001);
		c= getch();
		if(c==0)c=getch();
		if(c==80){
			if(tmp==Dic.Hash[(w->Tu[0]-97)].Tail||i==19){
				setcolor(15);
				rectangle(11,110+i*20,150,110+20+i*20);
				i=0;
				setcolor(1);
				rectangle(11,110+i*20,150,110+20+i*20);
				tmp=w;
				Xoa_bang();
				out_word(tmp);
				continue;
			}
			setcolor(15);
			rectangle(11,110+i*20,150,110+20+i*20);
			i++;
			setcolor(1);
			rectangle(11,110+i*20,150,110+20+i*20);
			tmp=tmp->Right;
			Xoa_bang();
			out_word(tmp);
		}
		if(c==72){
			if(tmp!=w){
				setcolor(15);
				rectangle(11,110+i*20,150,20+110+i*20);
				i--;
				setcolor(1);
				rectangle(11,110+i*20,150,110+20+i*20);
				tmp=tmp->Left;
				Xoa_bang();
				out_word(tmp);
			}
		}
		if(c==13){	
			setfillstyle(1,14);
			bar(11,111+i*20,150,110+20+i*20);
			outtextxy(20,125+i*20,convert_string(tmp->Tu));
			return tmp;
			break;
		}
	}
}

int Chonbtn(int x, int y){
	if(btn_checked(btnSave,x,y)){
		btnEdit.color=0;
		Ve_btn(btnEdit);
		btnSave.color=1;
		Ve_btn(btnSave);
		delay(500);
		btnSave.color=0;
		Ve_btn(btnSave);
		return 2;
	}
	if(btn_checked(btnOk,x,y)){
		btnEdit.color=0;
		Ve_btn(btnEdit);
		btnOk.color=1;
		Ve_btn(btnOk);
		delay(500);
		btnOk.color=0;
		Ve_btn(btnOk);
		return 3;
	}
	if(btn_checked(btnEdit,x,y)){
		btnEdit.color=1;
		Ve_btn(btnEdit);
		return 4;
	}
	if(btn_checked(btnDelete,x,y)){
		btnEdit.color=0;
		Ve_btn(btnEdit);
		btnDelete.color=1;
		Ve_btn(btnDelete);
		delay(500);
		btnDelete.color=0;
		Ve_btn(btnDelete);
		return 5;
	}
	if(btn_checked(btnAdd,x,y)){
		btnEdit.color=0;
		Ve_btn(btnEdit);
		btnAdd.color=1;
		Ve_btn(btnAdd);
		delay(500);
		btnAdd.color=0;
		Ve_btn(btnAdd);
		return 6;
	}
	if(txt_checked(txtNhap,x,y)){
		btnEdit.color=0;
		Ve_btn(btnEdit);
		txtNhap.color=1;
		Ve_txt(txtNhap);
		delay(500);
		txtNhap.color=0;
		Ve_txt(txtNhap);
		return 7;
	}
	return 0;
}


int Add(HashTable &Dic){
	setcolor(0);
	settextstyle(1,0,2);
	int x=220,y=140;
	int x1=320,y1=125;
	outtextxy(x,y,"Tu: ");
	textbox txt_Tu;
	txt_Tu.color=0;
	txt_Tu.Wight=200;
	txt_Tu.x=x1;
	txt_Tu.y=y1;
	Ve_txt(txt_Tu);
	
	
	y+=35;
	y1+=35;
	settextstyle(1,0,2);
	outtextxy(x,y,"Loai: ");
	textbox txt_Loai;
	txt_Loai.color=0;
	txt_Loai.Wight=200;
	txt_Loai.x=x1;
	txt_Loai.y=y1;
	Ve_txt(txt_Loai);
	
	y+=35;
	y1+=35;
	settextstyle(1,0,2);
	outtextxy(x,y,"Nghia: ");
	textbox txt_Nghia;
	txt_Nghia.color=0;
	txt_Nghia.Wight=200;
	txt_Nghia.x=x1;
	txt_Nghia.y=y1;
	Ve_txt(txt_Nghia);
	
	y+=35;
	y1+=35;
	textbox txt_Nghia1;
	txt_Nghia1.color=0;
	txt_Nghia1.Wight=200;
	txt_Nghia1.x=x1;
	txt_Nghia1.y=y1;
	Ve_txt(txt_Nghia1);
	
	y+=35;
	y1+=35;
	textbox txt_Nghia2;
	txt_Nghia2.color=0;
	txt_Nghia2.Wight=200;
	txt_Nghia2.x=x1;
	txt_Nghia2.y=y1;
	Ve_txt(txt_Nghia2);
	
	y+=35;
	y1+=35;
	textbox txt_Nghia3;
	txt_Nghia3.color=0;
	txt_Nghia3.Wight=200;
	txt_Nghia3.x=x1;
	txt_Nghia3.y=y1;
	Ve_txt(txt_Nghia3);
	
	y+=35;
	y1+=35;
	textbox txt_Nghia4;
	txt_Nghia4.color=0;
	txt_Nghia4.Wight=200;
	txt_Nghia4.x=x1;
	txt_Nghia4.y=y1;
	Ve_txt(txt_Nghia4);
	
	y+=35;
	y1+=35;
	settextstyle(1,0,2);
	outtextxy(x,y,"VD: ");
	textbox txt_VD;
	txt_VD.color=0;
	txt_VD.Wight=200;
	txt_VD.x=x1;
	txt_VD.y=y1;
	Ve_txt(txt_VD);
	
	
	settextstyle(0,0,1);
	x1+=220;
	button btn_Addvd, btn_Okvd, btn_AddTu,btn_Thoat;
	btn_Addvd.text="Add";
	btn_Addvd.color=0;
	btn_Addvd.x=x1;
	btn_Addvd.y=y1;
	Ve_btn(btn_Addvd);
	
	
	x1+=60;
	btn_Okvd.text="OK";
	btn_Okvd.color=0;
	btn_Okvd.x=x1;
	btn_Okvd.y=y1;
	Ve_btn(btn_Okvd);
	
	y1+=60;
	x1-=120;
	settextstyle(1,0,2);
	btn_AddTu.text="ADD TU";
	btn_AddTu.color=0;
	btn_AddTu.x=x1;
	btn_AddTu.y=y1;
	btn_AddTu.Wight=150;
	btn_AddTu.Height=50;
	Ve_btn(btn_AddTu);
	
	x1+=160;
	btn_Thoat.text="EXIT";
	btn_Thoat.color=0;
	btn_Thoat.x=x1;
	btn_Thoat.y=y1;
	btn_Thoat.Wight=100;
	btn_Thoat.Height=50;
	Ve_btn(btn_Thoat);
	
	settextstyle(0,0,1);
	int p1, p2,chon;
	word w= new Word;
	while(1){	
		delay(0.001);
		if (ismouseclick(WM_LBUTTONDOWN)){
			getmouseclick(WM_LBUTTONDOWN, p1, p2);
			clearmouseclick(WM_LBUTTONDOWN);
			if(txt_checked(txt_Tu,p1,p2)==TRUE){
				txt_Tu.color=1;
				Ve_txt(txt_Tu);
				Nhap_text(txt_Tu);
				txt_Tu.color=0;
				Ve_txt(txt_Tu);
				txt_Loai.color=1;
				Ve_txt(txt_Loai);
				Nhap_text(txt_Loai);
				txt_Loai.color=0;
				Ve_txt(txt_Loai);
			}
			if(txt_checked(txt_Nghia,p1,p2)==TRUE){
				txt_Nghia.color=1;
				Ve_txt(txt_Nghia);
				chon=Nhap_text(txt_Nghia);
				if(chon==TAB){
					txt_Nghia.color=0;
					Ve_txt(txt_Nghia);
					txt_Nghia1.color=1;
					Ve_txt(txt_Nghia1);
					chon=Nhap_text(txt_Nghia1);
					if(chon==TAB){
						txt_Nghia1.color=0;
						Ve_txt(txt_Nghia1);
						txt_Nghia2.color=1;
						Ve_txt(txt_Nghia2);
						chon=Nhap_text(txt_Nghia2);
						if(chon==TAB){
							txt_Nghia2.color=0;
							Ve_txt(txt_Nghia2);
							txt_Nghia3.color=1;
							Ve_txt(txt_Nghia3);
							chon=Nhap_text(txt_Nghia3);
							if(chon==TAB){
								txt_Nghia3.color=0;
								Ve_txt(txt_Nghia3);
								txt_Nghia4.color=1;
								Ve_txt(txt_Nghia4);
								Nhap_text(txt_Nghia4);
								txt_Nghia4.color=0;
								Ve_txt(txt_Nghia4);
							}else{
								txt_Nghia3.color=0;
								Ve_txt(txt_Nghia3);
							}
						}else{
							txt_Nghia2.color=0;
							Ve_txt(txt_Nghia2);
						}
					}else{
						txt_Nghia1.color=0;
						Ve_txt(txt_Nghia1);
					}
				}else{
					txt_Nghia.color=0;
					Ve_txt(txt_Nghia);
				}
			}					
		}
		if(txt_checked(txt_VD,p1,p2)==TRUE){
			int d1,d2;
			txt_VD.color=1;
			Ve_txt(txt_VD);
			Nhap_text(txt_VD);
			txt_VD.color=0;
			Ve_txt(txt_VD);
			while(1){
				delay(0.001);
				if (ismouseclick(WM_LBUTTONDOWN)){
					getmouseclick(WM_LBUTTONDOWN, d1, d2);
					clearmouseclick(WM_LBUTTONDOWN);
				}
				if(btn_checked(btn_Addvd,d1,d2)==TRUE){
					if(txt_VD.text!=""){
						try{
							ThemViDu(w->VD,txt_VD.text);
							
						}catch(int e){
							cout<< "loi deo gi eo biet"<<e<<endl;
						}
						
					}
					txt_VD.color=1;
					txt_VD.text="";
					Ve_txt(txt_VD);
					Nhap_text(txt_VD);
					txt_VD.color=0;
					Ve_txt(txt_VD);
					d1=0;
					continue;
				}
				if(btn_checked(btn_Okvd,d1,d2)==TRUE){
					txt_VD.color=0;
					Ve_txt(txt_VD);
					p1=0;
					break;
				}	
			}
		}
		if(btn_checked(btn_Thoat,p1,p2)==TRUE){
			Xoa_bang();
			return 0;
		}
		if(btn_checked(btn_AddTu,p1,p2)==TRUE){
			if(txt_Tu.text!=""){
				w->Tu=txt_Tu.text;
				w->Loai=txt_Loai.text;
				w->Nghia[0]=txt_Nghia.text;
				w->Nghia[1]=txt_Nghia1.text;
				w->Nghia[2]=txt_Nghia2.text;
				w->Nghia[3]=txt_Nghia3.text;
				w->Nghia[4]=txt_Nghia4.text;
				if(Insert_last_word(Dic.Hash[(w->Tu[0]-97)],w)==0){
					setcolor(1);
					outtextxy(540,500,"LOI! Trung tu");
					delay(2000);
					setcolor(15);
					outtextxy(540,500,"LOI! Trung tu");
				}else{
					delay(0.001);
					w=new Word;
				}
				
			}else{
				setcolor(1);
				outtextxy(540,500,"Tu khong duoc trong!");
				delay(2000);
				setcolor(15);
				outtextxy(540,500,"Tu khong duoc trong!");
			}
			p1=0;
		}
	}	
}

void MenuEditVD(List_VD &tmp){
	Xoa_bang();
	setcolor(0);
	settextstyle(1,0,2);
	int x=220,y=140;
	int x1=320,y1=125;
	outtextxy(x,y,"Vi du: ");
	textbox txt_vd1;
	txt_vd1.color=0;
	txt_vd1.Wight=250;
	txt_vd1.x=x1;
	txt_vd1.y=y1;
	if(tmp==NULL){
		txt_vd1.text="null";
	}else{
		txt_vd1.text=tmp->data;
		tmp=tmp->next;
	}
	Ve_txt(txt_vd1);
	
	
	
	y1+=35;
	textbox txt_vd2;
	txt_vd2.color=0;
	txt_vd2.Wight=250;
	txt_vd2.x=x1;
	txt_vd2.y=y1;
	if(tmp==NULL){
		txt_vd2.text="null";
	}else{
		txt_vd2.text=tmp->data;
		tmp=tmp->next;
	}
	Ve_txt(txt_vd2);
	

	
	y1+=35;
	textbox txt_vd3;
	txt_vd3.color=0;
	txt_vd3.Wight=250;
	txt_vd3.x=x1;
	txt_vd3.y=y1;
	if(tmp==NULL){
		txt_vd3.text="null";
	}else{
		txt_vd3.text=tmp->data;
		tmp=tmp->next;
	}
	Ve_txt(txt_vd3);


	
	y1+=35;
	textbox txt_vd4;
	txt_vd4.color=0;
	txt_vd4.Wight=250;
	txt_vd4.x=x1;
	txt_vd4.y=y1;
	if(tmp==NULL){
		txt_vd4.text="null";
	}else{
		txt_vd4.text=tmp->data;
		tmp=tmp->next;
	}
	Ve_txt(txt_vd4);
	
	
	y1+=35;
	textbox txt_vd5;
	txt_vd5.color=0;
	txt_vd5.Wight=250;
	txt_vd5.x=x1;
	txt_vd5.y=y1;
	if(tmp==NULL){
		txt_vd5.text="null";
	}else{
		txt_vd5.text=tmp->data;
		tmp=tmp->next;
	}
	Ve_txt(txt_vd5);
	
	
	y1+=35;
	textbox txt_vd6;
	txt_vd6.color=0;
	txt_vd6.Wight=250;
	txt_vd6.x=x1;
	txt_vd6.y=y1;
	if(tmp==NULL){
		txt_vd6.text="null";
	}else{
		txt_vd6.text=tmp->data;
		tmp=tmp->next;
	}
	Ve_txt(txt_vd6);
	
	
	y1+=35;
	textbox txt_vd7;
	txt_vd7.color=0;
	txt_vd7.Wight=250;
	txt_vd7.x=x1;
	txt_vd7.y=y1;
	if(tmp==NULL){
		txt_vd7.text="null";
	}else{
		txt_vd7.text=tmp->data;
		tmp=tmp->next;
	}
	Ve_txt(txt_vd7);
	
	
	y1+=35;
	textbox txt_vd8;
	txt_vd8.color=0;
	txt_vd8.Wight=250;
	txt_vd8.x=x1;
	txt_vd8.y=y1;
	if(tmp==NULL){
		txt_vd8.text="null";
	}else{
		txt_vd8.text=tmp->data;
		tmp=tmp->next;
	}
	Ve_txt(txt_vd8);
	
	

	x1+=220;
	
	
	y1+=60;
	x1-=120;
	settextstyle(1,0,2);
	button btn_Back;
	btn_Back.text="    OK";
	btn_Back.color=0;
	btn_Back.x=x1;
	btn_Back.y=y1;
	btn_Back.Wight=150;
	btn_Back.Height=50;
	Ve_btn(btn_Back);

	int p1,p2;
	
	while(1){
		delay(0.001);
		if (ismouseclick(WM_LBUTTONDOWN)){
			getmouseclick(WM_LBUTTONDOWN, p1, p2);
			clearmouseclick(WM_LBUTTONDOWN);
		}
		if(btn_checked(btn_Back,p1,p2)==TRUE){
			Delete_ListVD(tmp);
			if(txt_vd1.text!="null"){
				ThemViDu(tmp,txt_vd1.text);
			}
			if(txt_vd2.text!="null"){
				ThemViDu(tmp,txt_vd2.text);
			}
			if(txt_vd3.text!="null"){
				ThemViDu(tmp,txt_vd3.text);
			}
			if(txt_vd4.text!="null"){
				ThemViDu(tmp,txt_vd4.text);
			}
			if(txt_vd5.text!="null"){
				ThemViDu(tmp,txt_vd5.text);
			}
			if(txt_vd6.text!="null"){
				ThemViDu(tmp,txt_vd6.text);
			}
			if(txt_vd7.text!="null"){
				ThemViDu(tmp,txt_vd7.text);
			}
			if(txt_vd8.text!="null"){
				ThemViDu(tmp,txt_vd8.text);
			}
			break;
		}
		if(txt_checked(txt_vd1,p1,p2)==TRUE){
			Nhap_text(txt_vd1);
			p1=0;
			continue;
		}
		if(txt_checked(txt_vd2,p1,p2)==TRUE){
			Nhap_text(txt_vd2);
			cout << txt_vd2.text;
			p1=0;
			continue;
		}
		if(txt_checked(txt_vd3,p1,p2)==TRUE){
			Nhap_text(txt_vd3);
			p1=0;
			continue;
		}
		if(txt_checked(txt_vd4,p1,p2)==TRUE){
			Nhap_text(txt_vd4);
			p1=0;
			continue;
		}
		if(txt_checked(txt_vd5,p1,p2)==TRUE){
			Nhap_text(txt_vd5);
			p1=0;
			continue;
		}
		if(txt_checked(txt_vd6,p1,p2)==TRUE){
			Nhap_text(txt_vd6);
			p1=0;
			continue;
		}
		if(txt_checked(txt_vd7,p1,p2)==TRUE){
			Nhap_text(txt_vd7);
			p1=0;
			continue;
		}
		if(txt_checked(txt_vd8,p1,p2)==TRUE){
			Nhap_text(txt_vd8);
			p1=0;
			continue;
		}
	}	
	settextstyle(0,0,1);
}


int Edit(word &w){
	Xoa_bang();
	setcolor(0);
	settextstyle(1,0,2);
	int x=220,y=140;
	int x1=320,y1=125;
	outtextxy(x,y,"Tu: ");
	textbox txt_Tu;
	txt_Tu.color=0;
	txt_Tu.Wight=250;
	txt_Tu.x=x1;
	txt_Tu.y=y1;
	txt_Tu.text=w->Tu;
	Ve_txt(txt_Tu);
	
	
	y+=35;
	y1+=35;
	settextstyle(1,0,2);
	outtextxy(x,y,"Loai: ");
	textbox txt_Loai;
	txt_Loai.color=0;
	txt_Loai.Wight=250;
	txt_Loai.x=x1;
	txt_Loai.y=y1;
	txt_Loai.text=w->Loai;
	Ve_txt(txt_Loai);
	
	y+=35;
	y1+=35;
	settextstyle(1,0,2);
	outtextxy(x,y,"Nghia: ");
	textbox txt_Nghia;
	txt_Nghia.color=0;
	txt_Nghia.Wight=250;
	txt_Nghia.x=x1;
	txt_Nghia.y=y1;
	if(w->Nghia[0]==""){
		txt_Nghia.text="null";
	}else{
		txt_Nghia.text=w->Nghia[0];
	}
	Ve_txt(txt_Nghia);
	
	y+=35;
	y1+=35;

	textbox txt_Nghia1;
	txt_Nghia1.color=0;
	txt_Nghia1.Wight=250;
	txt_Nghia1.x=x1;
	txt_Nghia1.y=y1;
	if(w->Nghia[1]==""){
		txt_Nghia1.text="null";
	}else{
		txt_Nghia1.text=w->Nghia[1];
	}
	Ve_txt(txt_Nghia1);
	
	y+=35;
	y1+=35;
	textbox txt_Nghia2;
	txt_Nghia2.color=0;
	txt_Nghia2.Wight=250;
	txt_Nghia2.x=x1;
	txt_Nghia2.y=y1;
	if(w->Nghia[2]==""){
		txt_Nghia2.text="null";
	}else{
		txt_Nghia2.text=w->Nghia[2];
	}
	Ve_txt(txt_Nghia2);
	
	y+=35;
	y1+=35;
	textbox txt_Nghia3;
	txt_Nghia3.color=0;
	txt_Nghia3.Wight=250;
	txt_Nghia3.x=x1;
	txt_Nghia3.y=y1;
	if(w->Nghia[3]==""){
		txt_Nghia3.text="null";
	}else{
		txt_Nghia3.text=w->Nghia[3];
	}
	Ve_txt(txt_Nghia3);
	
	y+=35;
	y1+=35;
	textbox txt_Nghia4;
	txt_Nghia4.color=0;
	txt_Nghia4.Wight=250;
	txt_Nghia4.x=x1;
	txt_Nghia4.y=y1;
	if(w->Nghia[4]==""){
		txt_Nghia4.text="null";
	}else{
		txt_Nghia4.text=w->Nghia[4];
	}
	Ve_txt(txt_Nghia4);
	
	y+=35;
	y1+=35;
	settextstyle(1,0,2);
	outtextxy(x,y,"VD: ");
	textbox txt_VD;
	txt_VD.color=0;
	txt_VD.Wight=250;
	txt_VD.x=x1;
	txt_VD.y=y1;
	if(w->VD!=NULL){
		txt_VD.text=w->VD->data;
	}else{
		txt_VD.text="null";
	}
	Ve_txt(txt_VD);
	
	
	settextstyle(0,0,1);
	x1+=270;
	button btn_Editvd, btn_EditTu;
	btn_Editvd.text="Edit";
	btn_Editvd.color=0;
	btn_Editvd.x=x1;
	btn_Editvd.y=y1;
	Ve_btn(btn_Editvd);
	
	y1+=60;
	x1-=170;
	settextstyle(1,0,2);
	btn_EditTu.text="Edit TU";
	btn_EditTu.color=0;
	btn_EditTu.x=x1;
	btn_EditTu.y=y1;
	btn_EditTu.Wight=150;
	btn_EditTu.Height=50;
	Ve_btn(btn_EditTu);
	
	
	settextstyle(0,0,1);
	int p1,p2;
	while(1){
		delay(0.001);
		if (ismouseclick(WM_LBUTTONDOWN)){
			getmouseclick(WM_LBUTTONDOWN, p1, p2);
			clearmouseclick(WM_LBUTTONDOWN);
		}
		if(txt_checked(txt_Tu,p1,p2)==TRUE){
			txt_Tu.color=1;
			Ve_txt(txt_Tu);
			Nhap_text(txt_Tu);
			w->Tu=txt_Tu.text;
			txt_Tu.color=0;
			Ve_txt(txt_Tu);
			p1=0;
		}
		if(txt_checked(txt_Loai,p1,p2)==TRUE){
			txt_Loai.color=1;
			Ve_txt(txt_Loai);
			Nhap_text(txt_Loai);
			w->Loai=txt_Loai.text;
			txt_Loai.color=0;
			Ve_txt(txt_Loai);
			p1=0;
		}
		if(txt_checked(txt_Nghia,p1,p2)==TRUE){
			txt_Nghia.color=1;
			Ve_txt(txt_Nghia);
			Nhap_text(txt_Nghia);
			w->Nghia[0]=txt_Nghia.text;
			txt_Nghia.color=0;
			Ve_txt(txt_Nghia);
			p1=0;
		}
		if(txt_checked(txt_Nghia1,p1,p2)==TRUE){
			txt_Nghia1.color=1;
			Ve_txt(txt_Nghia1);
			Nhap_text(txt_Nghia1);
			w->Nghia[1]=txt_Nghia1.text;
			txt_Nghia1.color=0;
			Ve_txt(txt_Nghia1);
			p1=0;
		}
		if(txt_checked(txt_Nghia2,p1,p2)==TRUE){
			txt_Nghia2.color=1;
			Ve_txt(txt_Nghia2);
			Nhap_text(txt_Nghia2);
			w->Nghia[2]=txt_Nghia2.text;
			txt_Nghia2.color=0;
			Ve_txt(txt_Nghia2);
			p1=0;
		}
		if(txt_checked(txt_Nghia3,p1,p2)==TRUE){
			txt_Nghia3.color=1;
			Ve_txt(txt_Nghia3);
			Nhap_text(txt_Nghia3);
			w->Nghia[3]=txt_Nghia3.text;
			txt_Nghia3.color=0;
			Ve_txt(txt_Nghia3);
			p1=0;
		}
		if(txt_checked(txt_Nghia4,p1,p2)==TRUE){
			txt_Nghia4.color=1;
			Ve_txt(txt_Nghia4);
			Nhap_text(txt_Nghia4);
			w->Nghia[4]=txt_Nghia4.text;
			txt_Nghia4.color=0;
			Ve_txt(txt_Nghia4);
			p1=0;
		}
		if(btn_checked(btn_Editvd,p1,p2)==TRUE){
			MenuEditVD(w->VD);
			Xoa_bang();
			setcolor(0);
			settextstyle(1,0,2);
			int x=220,y=140;
			outtextxy(x,y,"Tu: ");
			Ve_txt(txt_Tu);
			
			
			y+=35;
			settextstyle(1,0,2);
			outtextxy(x,y,"Loai: ");
			Ve_txt(txt_Loai);
			
			y+=35;
			settextstyle(1,0,2);
			outtextxy(x,y,"Nghia: ");
			Ve_txt(txt_Nghia);
			
			y+=35;
			Ve_txt(txt_Nghia1);
			
			y+=35;
			Ve_txt(txt_Nghia2);
			
			y+=35;
			Ve_txt(txt_Nghia3);
			
			y+=35;
			Ve_txt(txt_Nghia4);
			
			y+=35;
			settextstyle(1,0,2);
			outtextxy(x,y,"Vi Du: ");
			if(w->VD==NULL){
				txt_VD.text="null";
			}else{
				txt_VD.text=w->VD->data;
			}
			Ve_txt(txt_VD);
			
			
			settextstyle(0,0,1);
			Ve_btn(btn_Editvd);
			

			settextstyle(1,0,2);
			Ve_btn(btn_EditTu);
			
			
			settextstyle(0,0,1);
			
			
			settextstyle(0,0,1);
			p1=0;
		}
		if(btn_checked(btn_EditTu,p1,p2)==TRUE){
			return 1;
		}
	}
}

void XoaTu(HashTable &Dic,word &w){
	Xoa_bang();
	setcolor(1);
	rectangle(300,200,MaxX-150,300);
	outtextxy(390,250,"Ban chac muon xoa tu nay!");
	button btn_OkDele, btn_CancelDele;
	btn_OkDele.text="OK";
	btn_OkDele.color=1;
	btn_OkDele.x=410;
	btn_OkDele.y=270;
	Ve_btn(btn_OkDele);
	
	btn_CancelDele.text="Cancel";
	btn_CancelDele.Wight=70;
	btn_CancelDele.color=1;
	btn_CancelDele.x=490;
	btn_CancelDele.y=270;
	Ve_btn(btn_CancelDele);
	
	int p1,p2;
	while(1){
		delay(0.001);
		if (ismouseclick(WM_LBUTTONDOWN)){
			getmouseclick(WM_LBUTTONDOWN, p1, p2);
			clearmouseclick(WM_LBUTTONDOWN);
		}
		if(btn_checked(btn_OkDele,p1,p2)==TRUE){
			Del_word(Dic.Hash[(w->Tu[0]-97)],w);
			Xoa_bang();
			Xoa_TreeTk();
			w=out_list(Dic,txtNhap.text);
			out_word(w);
			break;
		}
		if(btn_checked(btn_CancelDele,p1,p2)==TRUE){
			Xoa_bang();
			out_word(w);
			break;
		}
	}
}


void LamViec(HashTable &Dic){
	Init_Dic(Dic);
	Read_List(Dic);
   	int x,y,chon1,chon;
   	word tmp=NULL;
   	while(1){
		delay(0.001);
		if (ismouseclick(WM_LBUTTONDOWN)){
			getmouseclick(WM_LBUTTONDOWN, x, y);
			chon1= Chonbtn(x,y);
		}
		if(chon1!=0){
			switch(chon1){
				case 2:{
					Save_List(Dic);
					
					x=0;
					chon1=0;
					break;
				}
				case 3:{
					x=0;
					chon1=0;
					break;
				}
				case 4:{
					if(tmp!=NULL){
						Edit(tmp);
						Xoa_bang();
						out_word(tmp);
					}
					x=0;
					chon1=0;
					break;
				}
				case 5:{
					if(tmp!=NULL){
						XoaTu(Dic,tmp);
					}
					x=0;
					chon1=0;
					break;
				}
				case 6:{
					Xoa_bang();
					Add(Dic);
					//Output(Dic.Hash[0]);
					
					
					x=0;
					chon1=0;
					break;
				}
				case 7:{
					while(1){
						int chon=txt_changed(txtNhap);
						if(chon==TRUE){
							Xoa_TreeTk();
							tmp=out_list(Dic,txtNhap.text);
						}
						if(chon==TAB){
							
							x=0;
							chon1=0;
							break;
						}
						if(chon==ENTER){
							Xoa_TreeTk();
							tmp=out_list(Dic,txtNhap.text);
							if(tmp!=NULL){
								Xoa_bang();
								setfillstyle(1,14);
								bar(11,111,150,110+20);
								outtextxy(20,125,convert_string(tmp->Tu));
								out_word(tmp);
								chon1=0;
								break;
							}
						}
						if(chon==80){
							Xoa_TreeTk();
							tmp=out_list(Dic,txtNhap.text);
							if(tmp!=NULL){
								tmp=ChonTu(Dic,tmp);
								Xoa_bang();
								out_word(tmp);
								chon1=0;
								break;
							}
						}
					}
					break;					
				}
			}
		}
	}
}

int main(int argc, char *argv[])
{
	initwindow(800, 540);
	setbkcolor(0);					
	settextjustify(0,1);
   	cleardevice();
	GiaoDien();	
   	HashTable Dic;
	LamViec(Dic);
	
    system("pause");
    closegraph();
}


	
