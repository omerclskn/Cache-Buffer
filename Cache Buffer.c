#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct node{
	int cnt;
	char adr[10];
	struct node *next;
	struct node *prev;
	}*root,*index,*index1,*index2;
				
void LimKont(struct node *r,int L){
	int cnt=1;

	while(r->next!=NULL){
		cnt++;
		r=r->next;
		}
	if(cnt>L){	
		r->prev->next=NULL;		
		free(r);	
		}
	}
				
void Ekle(struct node *r, char *adres, int *flag, int T, int L){	
	index=r;
	index2=r;	
	while(index!=NULL){
		if(strcmp(index->adr,adres)==0){			
			index->cnt++; // indeximizin ici girilen adresle esitse sayacýmýz artar
				if(index->cnt>T){ //Eþik Kontrolü
					if(index->prev!=NULL)
						index->prev->next=index->next;
							// Bu iki if kontrolü index in prev i yoksa next i de olamayacagi icin var. bir de tam tersi
					if(index->next!=NULL  && r!=index) // Burda esik degerimiz gecildikten sonra bir daha gecilirse eleman yok oluyor onu kontrol ediyor
						index->next->prev=index->prev;
		
		while(index2->prev!=NULL)	
			index2=index2->prev;
				
				if(index2!=index){ // index nin index2 ye esit olmamasý durumunda basa tasýma islemi gerceklestirilir. ornegin head bastaysa tasýma islemine gerek kalmaz
					index->next=index2;
					index2->prev=index;
					index->prev=NULL;
					*flag=1;
					}
				}
					break;
			}
		index=index->next;	
		}
	if(index==NULL){	// index in null olmasý durumunda icerde deger bulunmamýs demektir ve yeni yer acýlýr.	
			
		r->prev=(struct node*)malloc(sizeof(struct node));		
		strcpy(r->prev->adr,adres);	
			
		r->prev->cnt=1;		
		r->prev->next=r;		
		r->prev->prev=NULL;		
		
		*flag=1;		
		LimKont(r->prev,L);	
		}
	}
	
int main(){	
 	
 	char tmp[10], state='e';
	int L,T,flag=0;
 	// flag degiskenimiz root degisiminin kontrolü icin var
	root=(struct node*) malloc(sizeof(struct node));	
	root->next=NULL;	
	root->prev=NULL;	
	root->cnt=1;

	printf("Limit(L) Giriniz:");	
	scanf("%d",&L);	
	printf("Esik(T) Giriniz:");	
	scanf("%d",&T);	
	
	printf("Adres Giriniz: ");	
	scanf("%s",root->adr);	
	printf("%s,%d \n",root->adr,root->cnt);
	
	do{		
	flag=0;	
	printf("Adres Giriniz: ");		
	scanf("%s",tmp);		

	Ekle(root,tmp,&flag,T,L);
	
	if(flag==1)		
	root=root->prev;
	
	index1=root;
	
	while(index1!=NULL){		
	printf("%s,%d ",index1->adr,index1->cnt);
	if(index1->next!=NULL){
		printf(" <-> ");
		}
	index1=index1->next;	
	}
	
	printf("     Adres Girmeye Devam Etmek icin e ye Basiniz \n");	
	
	state=getch();}while(state=='e');
	
	printf("Cache'in silinmesi icin c ye basiniz");
	state=getch();
	
	if(state=='c'){
		while(root!=NULL){
			free(root->prev);
			root=root->next;
			}
		free(root);
		}
		printf("\nCikmak icin Herhangi bir tusa basin...");
	}
