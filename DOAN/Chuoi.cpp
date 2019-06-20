#include "Chuoi.h"

int SoSanh(string &str1, string &str2){
	if(str1.length()>=str2.length()){
		int i=0;
		for(i;i<str2.length();i++){
			if(str1[i]!=str2[i]){
				if(str1[i]>str2[i]){
					return 1;
				}else{
					return -1;
				}
			}
		}
		if(str1.length()==str2.length())return 0;
		return 1;
	}else{
		int i=0;
		for(i;i<str1.length();i++){
			if(str1[i]!=str2[i]){
				if(str1[i]>str2[i]){
					return 1;
				}else{
					return -1;
				}
			}
		}
		return -1;
	}
}

void ToiUu(string &str) {
	if(str != "") {
		while(str[0] == ' ') str.erase(0, 1);
		while(str[str.length() - 1] == ' '){
			str.erase(str.length() - 1, 1); 
		}
		if(str.length() > 3){
			for(short i = 1; i < str.length() - 2; i++){
				if(str[i] == ' ' && str[i+1] == ' '){
					str.erase(i, 1);
					i--;
				}
			}
		}		
		for(short i = 0; i < str.length(); i++){
			if(str[i] >= 'A' && str[i] <= 'Z'){
				str[i] += 32;
			}
		}	
	}
}
