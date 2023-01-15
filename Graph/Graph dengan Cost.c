#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct simpul{
	struct edge * jalur;
	struct simpul * next;
	char idSimpul[20];
};

struct edge{
	struct edge * next_jalur;
	struct simpul * tujuan;
	int Cost;
};

struct Graph{
	struct simpul * first;
};

void createGraph(struct Graph * G){
	G->first=NULL;
}

void createSimpul(struct Graph * G, char a[20]){
	struct simpul * simpulBaru = (struct simpul *)malloc(sizeof(struct simpul));
	//simpulBaru->idSimpul=a;
	strcpy(simpulBaru->idSimpul,a);
	simpulBaru->jalur=NULL;
	simpulBaru->next=NULL;
	if(G->first==NULL){
		G->first=simpulBaru;
	}else{
		struct simpul *akhir = G->first;
		while(akhir->next!=NULL){
			akhir=akhir->next;
		}
	akhir->next=simpulBaru;
	}
}

void createEdge(struct simpul * awal, struct simpul * akhir, int nilaiJalur){
	struct edge * newEdge = (struct edge *)malloc(sizeof(struct edge));
	newEdge->Cost=nilaiJalur;
	newEdge->next_jalur=NULL;
	newEdge->tujuan=akhir;
	if(awal->jalur==NULL){
		awal->jalur=newEdge;
	}else{
		struct edge * jalurAkhir=awal->jalur;
		while(jalurAkhir->next_jalur!=NULL){
			jalurAkhir=jalurAkhir->next_jalur;
		}
		jalurAkhir->next_jalur=newEdge;
	}
}

void cetakGraph(struct Graph * G){
	struct simpul * tempSimpul=G->first;
	if(tempSimpul!=NULL){
		while(tempSimpul!=NULL){
			printf("Simpul %s \n", tempSimpul->idSimpul);
			struct edge * tempEdge = tempSimpul->jalur;
			while(tempEdge!= NULL){
				printf("Terhubung dengan simpul %s, dengan Cost %d", tempEdge->tujuan->idSimpul, tempEdge->Cost);
				tempEdge = tempEdge->next_jalur;
				printf("\n");
			}
			tempSimpul=tempSimpul->next;

		}
		}else{
			printf("Graph Kosong");
	}
}

struct simpul *  findSimpul(struct Graph * G, char a[20]){
	struct simpul * hasil = NULL;
	struct simpul * bantu = G->first;

	int ketemu = 0;
	while((bantu!=NULL)&&(ketemu==0)){
		if(strcmp(bantu->idSimpul,a)==0){
			hasil=bantu;
			ketemu=1;
		}else{
			bantu=bantu->next;
		}
	}
	return hasil;
}

int main() {
	struct Graph  G;
	struct simpul *a1, *a2, *a3, *a4, *a5;
	createGraph(&G);
	createSimpul(&G, "Jakarta");
	createSimpul(&G,"Bandung");
	createSimpul(&G,"Yogyakarta");
	createSimpul(&G,"Solo");
	createSimpul(&G,"Surabaya");
	a1=findSimpul(&G,"Jakarta");
	a2=findSimpul(&G,"Bandung");
	a3=findSimpul(&G,"Yogyakarta");
	a4=findSimpul(&G,"Solo");
	a5=findSimpul(&G,"Surabaya");
	createEdge(a1,a2, 300);
	createEdge(a5,a2, 1200);
	createEdge(a3,a2, 1000);
	createEdge(a1,a4, 1000);
	createEdge(a1,a5, 1500);
	createEdge(a5,a3, 300);
	createEdge(a2,a1, 400);
	createEdge(a4,a2, 700);
	cetakGraph(&G);
	return 0;
}
