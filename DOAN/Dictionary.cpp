#include"Dictionary.h"

char* convert_string(string &str){
	char* x= new char[str.length()];
	int i=0;
	for(i;i<str.length();i++){
		x[i]=str[i];
	}
	x[i]='\0';
	return x;
}

string convert_string(char *s){
	string str;
	int i=0;
	while(s[i]!='\0'){
		i++;
		str+=s[i];
	}
	return str;
}

char * ChepDau(string &s){
	char* str= new char[23];
	int i=s.length();
	int j=0;
	for(j;j<22;j++){
		if(j==i){
			str[j]='\0';
			return str;
		}
		str[j]=s[j];
	}
	str[j]='\0';
	return str;
}

char * Chep(string &s){
	char* str= new char[23];
	int i = s.size();
	int j,m=0;
	for(j=i-22;j<i;j++){
		str[m]=s[j];
		m++;
	}
	str[m]='\0';
	return str;
}

int Nhap_text(struct textbox &txt){
	settextstyle(0,0,1);
	int x=txt.x+12;
	int y=txt.y+2*txt.Height/3;
	setcolor(0);
	int vt,i;
	if(txt.text.length()>21){
		outtextxy(x,y,Chep(txt.text));
	}
//	if(txt.vt_nhay!=0){
//		i=txt.vt_nhay;
//		vt=txt.vt_nhay;
//	}else{
//		i=0;
//		vt=txt.vt_nhay;
//	}
	i=txt.text.length();
	if(i>20){
		vt=21;
	}else{
		vt=txt.text.length();
	}	
	line(x+8*vt,y+3,x+8+8*vt,y+3);
	char c,d;
	while(1){
		c = getch();
		if(c==0){
			d=getch();
		}
		if(c==32||c>64&&c<91||c>96&&c<123){
			if(c<91&&c!=32)c+=32;
			setcolor(15);
			line(x+8*vt,y+3,x+8+8*vt,y+3);
			if(i<22){
				if(vt==txt.text.length()){
					txt.text+=c;
					i++;
					vt++;
				}else{
					txt.text[vt]=c;
					vt++;
				}
			}else{
				if(vt==22){
					txt.text+=c;
					i++;
				}else{
					txt.text[i-22+vt]=c;
					vt++;
				}
			}
			setcolor(0);
			line(x+8*vt,y+3,x+8+8*vt,y+3);
		}else{
			if(c==13){
				setcolor(15);
				line(x+8*vt,y+3,x+8+8*vt,y+3);
				return ENTER;
			}
			if(c==8){
				if(vt>0){
					setcolor(15);	
					if(i<23){
						outtextxy(x,y,convert_string(txt.text));
						txt.text.erase(vt-1,1);
					}else{
						outtextxy(x,y,Chep(txt.text));
						txt.text.erase(i-22+vt,1);
					}
					setcolor(15);
					line(x+8*vt,y+3,x+8+8*vt,y+3);
					if(i!=0)i--;
					if(i<23){
						vt--;
					}					
					setcolor(0);
					line(x+8*vt,y+3,x+8+8*vt,y+3);
					//line(x+8*(i-1),y+3,x+8+8*(i-1),y+3);					
				}
			}
			if(c==9){
				setcolor(15);
				line(x+8*vt,y+3,x+8+8*vt,y+3);	
				return TAB;
			}
			if(d==75){
				if(vt>0){
					setcolor(15);
					line(x+8*vt,y+3,x+8+8*vt,y+3);
					vt--;
					setcolor(0);
					line(x+8*vt,y+3,x+8+8*vt,y+3);
				}
			}
			if(d==77){
				if(vt<22&&vt<txt.text.length()){
					setcolor(15);
					line(x+8*vt,y+3,x+8+8*vt,y+3);
					vt++;
					setcolor(0);
					line(x+8*vt,y+3,x+8+8*vt,y+3);
				}
			}
		}
		setcolor(0);		
		if(i<22){
			outtextxy(x,y,convert_string(txt.text));
		}else{
			outtextxy(x,y,Chep(txt.text));
		}
		if(vt>22)vt=22;
	}
}
//int Nhap_text(struct textbox &txt){
//	string str;
//	settextstyle(0,0,1);
//	int x=txt.x+12;
//	int y=txt.y+2*txt.Height/3;
//	setcolor(0);
//	int vt,i;
//	if(str.length()>21){
//		outtextxy(x,y,Chep(str));
//	}
////	if(txt.vt_nhay!=0){
////		i=txt.vt_nhay;
////		vt=txt.vt_nhay;
////	}else{
////		i=0;
////		vt=txt.vt_nhay;
////	}
//	i=str.length();
//	if(i>20){
//		vt=21;
//	}else{
//		vt=str.length();
//	}	
//	cout<<i<<"\t"<<vt<<endl;
//	line(x+8*vt,y+3,x+8+8*vt,y+3);
//	char c,d;
//	while(1){
//		c = getch();
//		cout<<c<<endl;
//		if(c==0){
//			d=getch();
//		}
//		if(c==32||c>64&&c<91||c>96&&c<123){
//			cout<<"bach"<<endl;
//			if(c<91&&c!=32)c+=32;
//			setcolor(15);
//			line(x+8*vt,y+3,x+8+8*vt,y+3);
//			if(i<22){
//				if(vt==str.length()){
//					try
//				  {
//				  	cout<<"bach1"<<endl;
//				  	cout<<"size: "<<str.size()<<endl;
//				  	cout<<c<<endl;
//				    str+=c;
//				    cout<<str<<endl;
//				  }
//				  catch (int e)
//				  {
//				    cout << "An exception occurred. Exception Nr. " << e << '\n';
//				  }
//					
//					i++;
//					vt++;
//				}else{
//					str[vt]=c;
//					vt++;
//				}
//			}else{
//				if(vt==22){
//					str+=c;
//					i++;
//				}else{
//					str[i-22+vt]=c;
//					vt++;
//				}
//			}
//			cout<<i<<"\t"<<vt<<endl;
//			setcolor(0);
//			line(x+8*vt,y+3,x+8+8*vt,y+3);
//		}else{
//			if(c==13){
//				txt.text=str;
//				setcolor(15);
//				line(x+8*vt,y+3,x+8+8*vt,y+3);
//				return ENTER;
//			}
//			if(c==8){
//				if(vt>0){
//					setcolor(15);	
//					if(i<23){
//						outtextxy(x,y,convert_string(str));
//						str.erase(vt-1,1);
//					}else{
//						outtextxy(x,y,Chep(str));
//						str.erase(i-22+vt,1);
//					}
//					setcolor(15);
//					line(x+8*vt,y+3,x+8+8*vt,y+3);
//					if(i!=0)i--;
//					if(i<23){
//						vt--;
//					}					
//					setcolor(0);
//					line(x+8*vt,y+3,x+8+8*vt,y+3);
//					//line(x+8*(i-1),y+3,x+8+8*(i-1),y+3);					
//				}
//			}
//			if(c==9){
//				txt.text=str;
//				setcolor(15);
//				line(x+8*vt,y+3,x+8+8*vt,y+3);	
//				return TAB;
//			}
//			if(d==75){
//				if(vt>0){
//					setcolor(15);
//					line(x+8*vt,y+3,x+8+8*vt,y+3);
//					vt--;
//					setcolor(0);
//					line(x+8*vt,y+3,x+8+8*vt,y+3);
//				}
//			}
//			if(d==77){
//				if(vt<22&&vt<str.length()){
//					setcolor(15);
//					line(x+8*vt,y+3,x+8+8*vt,y+3);
//					vt++;
//					setcolor(0);
//					line(x+8*vt,y+3,x+8+8*vt,y+3);
//				}
//			}
//		}
//		setcolor(0);		
//		if(i<22){
//			outtextxy(x,y,convert_string(str));
//		}else{
//			outtextxy(x,y,Chep(str));
//		}
//		if(vt>22)vt=22;
//	}
//}

void Ve_btn(struct button &btn){
	setcolor(btn.color);
	line(btn.x,btn.y,btn.x+btn.Wight,btn.y);
	line(btn.x,btn.y,btn.x,btn.y+btn.Height);
	line(btn.x,btn.y+btn.Height,btn.x+btn.Wight,btn.y+btn.Height);
	line(btn.x+btn.Wight,btn.y,btn.x+btn.Wight,btn.y+btn.Height);
	outtextxy(btn.x+5,btn.y+2*btn.Height/3,btn.text);
}

int btn_checked(struct button &btn,int x, int y){
	if(x>btn.x){
		if(y>btn.y){
			if(x<btn.x+btn.Wight){
				if(y<btn.y+btn.Height){
					return TRUE;
				}
			}
		}
	}
	return FALSE;
}



void Ve_txt(struct textbox &txt){
	setcolor(txt.color);
	settextstyle(0,0,1);
	line(txt.x,txt.y,txt.x+txt.Wight,txt.y);
	line(txt.x,txt.y,txt.x,txt.y+txt.Height);
	line(txt.x,txt.y+txt.Height,txt.x+txt.Wight,txt.y+txt.Height);
	line(txt.x+txt.Wight,txt.y,txt.x+txt.Wight,txt.y+txt.Height);
	if(txt.text.length()>21){
		outtextxy(txt.x+12,txt.y+2*txt.Height/3,Chep(txt.text));
	}else{
		outtextxy(txt.x+12,txt.y+2*txt.Height/3,convert_string(txt.text));
	}
}

int txt_checked(struct textbox &txt,int x, int y){
	if(x>txt.x){
		if(y>txt.y){
			if(x<txt.x+txt.Wight){
				if(y<txt.y+txt.Height){
					return TRUE;
				}
			}
		}
	}
	return FALSE;
}

int txt_changed(struct textbox &txt){
	int x=txt.x+12;
	int y=txt.y+2*txt.Height/3;
	int i=txt.vt_nhay;
	setcolor(0);
	line(x+8*i,y+3,x+8+8*i,y+3);
	char c,d;
	while(1){
		c = getch();
		if(c==0){
			d=getch();
		}
		if(c==32||c>64&&c<91||c>96&&c<123){
			if(c<91&&c!=32)c+=32;
			if(i==txt.text.length()){
				txt.text+=c;
			}else{
				txt.text[i]=c;
			}
			setcolor(15);
			line(x+8*i,y+3,x+8+8*i,y+3);
			i++;
			setcolor(0);
			line(x+8*i,y+3,x+8+8*i,y+3);
			txt.vt_nhay=i;
			setcolor(0);
			outtextxy(x,y,convert_string(txt.text));
			return TRUE;
		}else{
			if(c==13){
				setcolor(15);
				line(x+8*i,y+3,x+8+8*i,y+3);
				txt.vt_nhay=i;	
				return ENTER;
			}
			if(c==8){
				if(i!=0){
					setcolor(15);	
					outtextxy(x,y,convert_string(txt.text));
					txt.text.erase(i-1,1);
					
					setcolor(15);
					line(x+8*i,y+3,x+8+8*i,y+3);
					i--;
					setcolor(0);
					line(x+8*i,y+3,x+8+8*i,y+3);
					//line(x+8*(i-1),y+3,x+8+8*(i-1),y+3);
					txt.vt_nhay=i;
					setcolor(0);	
					outtextxy(x,y,convert_string(txt.text));
					return TRUE;					
				}
			}
			if(c==9){
				setcolor(15);
				line(x+8*i,y+3,x+8+8*i,y+3);	
				txt.vt_nhay=i;	
				return TAB;
			}
			if(d==DOWN){
				setcolor(15);
				line(x+8*i,y+3,x+8+8*i,y+3);	
				txt.vt_nhay=i;	
				return DOWN;
			}
			if(d==75){
				if(i>0){
					setcolor(15);
					line(x+8*i,y+3,x+8+8*i,y+3);
					i--;
					setcolor(0);
					line(x+8*i,y+3,x+8+8*i,y+3);
				}
			}
			if(d==77){
				if(i<txt.text.length()){
					setcolor(15);
					line(x+8*i,y+3,x+8+8*i,y+3);
					i++;
					setcolor(0);
					line(x+8*i,y+3,x+8+8*i,y+3);
				}
			}
		}
	}
}


void out_word(word w){
	settextstyle(1,0,5);
	int x=220,y=150;
	int x1=420,y1=150;
	outtextxy(x1,y1,convert_string(w->Tu));
	
	settextstyle(1,0,2);
	x1=350;
	y+=35;
	y1+=35;
	outtextxy(x,y,"Loai: ");
	outtextxy(x1,y1,convert_string(w->Loai));
	
	
	y+=35;
	y1+=35;
	outtextxy(x,y,"Nghia: ");
	outtextxy(x1,y1,convert_string(w->Nghia[0]));

	y+=35;
	y1+=35;
	outtextxy(x1,y1,convert_string(w->Nghia[1]));
	

	y+=35;
	y1+=35;
	outtextxy(x1,y1,convert_string(w->Nghia[2]));
	

	y+=35;
	y1+=35;
	outtextxy(x1,y1,convert_string(w->Nghia[3]));
	

	y+=35;
	y1+=35;
	outtextxy(x1,y1,convert_string(w->Nghia[4]));

	y+=35;
	outtextxy(x,y,"Vi du: ");
	List_VD vd = w->VD;
	int i=0;
	while(vd!=NULL){
		y1+=35;
		if(vd->data.length()<22){
			outtextxy(x1,y1,convert_string(vd->data));
			vd=vd->next;
			i++;
			continue;
		}
		outtextxy(x1,y1,ChepDau(vd->data));
		outtextxy(700,y1,"...");
		vd=vd->next;
		i++;
		if(i==3){
			break;
		}
	}
	if(i==3){
		outtextxy(700,y1,"...");
	}
	settextstyle(0,0,1);		
}



