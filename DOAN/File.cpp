#include "File.h"

void Save_List(HashTable &Dic){ 
	ofstream fo("data.txt");
	if(fo.is_open()) {
		for(int i=0;i<26;i++){
			word w = Dic.Hash[i].Head;
			if(w!=NULL){
				while(w != Dic.Hash[i].Tail->Right) {
				fo << w->Tu
					<< "$" << w->Loai
					<< "$" << w->Nghia[0]
					<< "$" << w->Nghia[1]
					<< "$" << w->Nghia[2]
					<< "$" << w->Nghia[3]
					<< "$" << w->Nghia[4];
					List_VD vd=w->VD;
					while(vd!=0){
						fo << "$" <<vd->data;
						vd=vd->next;
					}
					fo << "$" << "@\n";
					w = w->Right;
				}
			}
		}
	}
	fo.close();
}

void Read_Line(string line, word &w){
	string tmp="";
	int i=0;
	while(line[i]!='$'){
		tmp+=line[i++];
	}
	w->Tu=tmp;
	i++;
	tmp="";
	while(line[i]!='$'){
		tmp+=line[i++];
	}
	w->Loai=tmp;
	i++;
	tmp="";
	while(line[i]!='$'){
		tmp+=line[i++];
	}
	w->Nghia[0]=tmp;
	i++;
	tmp="";
	while(line[i]!='$'){
		tmp+=line[i++];
	}
	w->Nghia[1]=tmp;
	i++;
	tmp="";
	while(line[i]!='$'){
		tmp+=line[i++];
	}
	w->Nghia[2]=tmp;
	i++;
	tmp="";
	while(line[i]!='$'){
		tmp+=line[i++];
	}
	w->Nghia[3]=tmp;
	i++;
	tmp="";
	while(line[i]!='$'){
		tmp+=line[i++];
	}
	w->Nghia[4]=tmp;
	i++;	
	while(line[i]!='@'){
		tmp="";
		while(line[i]!='$'){
			tmp+=line[i++];
		}
		ThemViDu(w->VD,tmp);
		i++;
	}
}

void Read_List(HashTable &Dic) { 
	ifstream fi("data.txt");
	string line;
	if(fi.is_open()) {
		while(getline(fi, line)) {
			word tmp= new Word;
			Read_Line(line,tmp);
			Insert_last_word(Dic.Hash[(tmp->Tu[0]-97)],tmp);
		}
		fi.close();
	}
}
