#include "Dic.h"


void Init(D_List &L) {
    L.Head = NULL; 
    L.Tail = NULL; 
}


void Init_Dic(HashTable &H){
	int i=0;
	for(i; i<26;i++){
		Init(H.Hash[i]);
	}
}


int Isempty (D_List &L){
    return (L.Head == NULL);
}

void Insert_first (D_List &L, word w){
    if (Isempty(L)){
        L.Head = w;
        L.Tail = w;
    }
    else{
        w->Right = L.Head; 
        L.Head->Left = w;
        L.Head = w;
    }
}

void Insert_last (D_List &L, word w){
    if (Isempty(L)){
        L.Head = w;
        L.Tail = w;
    }
    else{
        L.Tail->Right = w;
        w->Left = L.Tail; 
        L.Tail = w; 
    }
}

int Insert_last_word(D_List &L, word w){
	ToiUu(w->Tu);
    word tmp = L.Head, tmp1;
    if(tmp==NULL){
    	L.Head = w;
        L.Tail = w;	
        return 1;
	}else{
		if(SoSanh(tmp->Tu,w->Tu)==0){
			return 0;
		}
		if(SoSanh(tmp->Tu,w->Tu)==1){
			Insert_last(L,w);
			return 1;
		}
		while(tmp!=L.Tail){
			tmp=tmp->Right;
			if(SoSanh(tmp->Tu,w->Tu)==1){
				break;
			}
			if(SoSanh(tmp->Tu,w->Tu)==0){
				return 0;
			}
		}
		if(SoSanh(tmp->Tu,w->Tu)==1){
			tmp1=tmp->Left;
			tmp1->Right=w;
			w->Left=tmp1;
			w->Right=tmp;
			tmp->Left=w;
			return 1;
		}else{
			Insert_last(L,w);
			return 1;
		}
	}   
}


word Seach_word(HashTable &h, string &s){
	if(s=="")return NULL;
    word tmp = h.Hash[(s[0]-97)].Head;
    if(tmp==NULL){
        return NULL;
	}else{
		while(tmp!=h.Hash[(s[0]-97)].Tail->Right){
			if(SoSanh(tmp->Tu,s)>=0){
				return tmp;
			}	
			tmp=tmp->Right;
		}
	}  
}

void Del_first (D_List &L){
    if (!Isempty(L)){
        L.Head = L.Head->Right;
    }
}
 
void Del_last (D_List &L){
    if (!Isempty(L)){
        L.Tail = L.Tail->Left;
        L.Tail->Right = NULL;
    }
}

int Del_word(D_List &L,word &w){
	word tmp;
	if (!Isempty(L)){
		if(w==L.Tail){
			Del_last(L);
			return 1;
		} 
		if(w==L.Head){
			Del_first(L);
			return 1;
		} 
        tmp=w->Right;
        w->Left->Right=tmp;
        delete w;
        return 1;
    }
}

int Lengh(D_List L){
    word PH = L.Head, PT = L.Tail;
    int i = 0; 
    if (PH != NULL) i = 1;
    while (PH != NULL)
    {
        if (PH == PT) break;
        PH = PH->Right;
        i++;
        if (PH == PT) break;
        PT = PT->Left;
        i++;
    }
    return i; 
}

int Del_k (D_List &L,int k){
    word PH = L.Head, PT;
    int i=1, l = Lengh(L);
    if (k == 1) Del_first(L);
    else
        if (k == l) Del_last(L);
        else{
        	while (PH != NULL && i != k-1){
                i++;
                PH = PH->Right;
            }
            PT = PH->Right->Right;
            PH->Right = PT;  
            PT->Left = PH;   
        }
    return 1;   
}


word Edit_k (D_List &L,int k){
    int i=1, l = Lengh(L);
    cout<<l<<endl;
    if(k==1){
    	return L.Head;
	}
	if(k==l){
		return L.Tail;
	}
    word PH = L.Head;
	while (PH != NULL && i != k-1){
        i++;
        PH = PH->Right;
    }
    return PH->Right;   
}


void Output (D_List &L){
    word tmp=L.Head;
    if(tmp!=NULL){
	    while (tmp != L.Tail->Right){
	    	cout << tmp->Tu<<endl;
	        tmp = tmp->Right;
	    }
	    printf("\n");
	}    
}



void KhoiTao (List_VD &L) {
    L=NULL; 
}

List_VD TaoMoi (List_VD P, string &x) {
    //P = (List) malloc (sizeof (ViDu)); 
    P = new ViDu;
    P->next = NULL; 
	P->data=x;
    return P; 
}



void ThemViDu (List_VD &L, string x){
    List_VD P; 
    P = TaoMoi(P,x); 
    P->next = L; 
    L = P; 
}


int size(List_VD L) {
    List_VD P=L; 			
    int i=0;
    while (P!=NULL) 
    {
        i++; 
        P=P->next; 
    }
    return i; 
}






int Sua_vt_k(List_VD &L, string &x, int k){ 
	List_VD Q=L;
    int i=1;
    if (k<1 || k>size(Q)) return 0;
    else{
        if(k==1){
        	Q->data=x;
        	return 1;
		}
        while (Q != NULL && i != k-1) 
        {
            Q=Q->next;
            i++;
        }
        Q->data=x;
        return 1;
    }
}

void Out_dsVD(List_VD &L){
	List_VD P=L; 			
    while (P!=NULL){	 	
    	cout<<P->data;
        P=P->next; 		
    }
}



int Delete_ListVD(List_VD &L){
	List_VD P;
	while(L!=NULL){
		P=L;
		L=L->next;
		delete P;
	}
	return 1;
}




