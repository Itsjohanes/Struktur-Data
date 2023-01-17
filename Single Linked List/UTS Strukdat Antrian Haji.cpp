#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define max 100
#include <iostream>
using namespace std;
typedef struct element
{
   
    char nama[15];
    char gender [10];
    int usia;
    struct element * alamat;
    //untuk next variable untuk nilai berupa alamat / jadi pake pointer! karena nyimpen alamat
}element;
typedef struct bantuan{
	char nama[15];
    char gender[10];
    int usia;
}bantuan;
element * CreatedList(char nama[15],char gender [10],int usia) //yang direturn itu alamat
{
    element *elementBaru = NULL; //masih kosong

    elementBaru = (element*) malloc (sizeof(element));
    strcpy(elementBaru->nama,nama);
    strcpy(elementBaru->gender,gender);
    elementBaru->usia = usia;    
    elementBaru -> alamat = NULL;

    return elementBaru; //mengembalilam element baru
}
void akhir(char nama[15],char gender [10],int usia,element *listsaya)
{

     element * newlist = CreatedList(nama,gender,usia);
    element * temp = NULL;
    temp =  listsaya;
    while(temp->alamat != NULL)
    {

        temp = temp->alamat;

    }
    temp->alamat= newlist;
}



void cetak(element * listsaya)
{

    element * temp = listsaya;
    if(temp != NULL)
    {
    	do
    {
        printf("%s \n",temp->nama);
        printf("%s \n",temp->gender);
        printf("%d \n",temp->usia);
        temp = temp ->alamat;

    }
    while(temp!=NULL);
    	
	 } else{
	 	printf("List kosong");
	 }
     
    
}
void deldepan(element ** listsaya)
{
	if(listsaya != NULL){
	element * del = (*listsaya);
    (*listsaya) = del->alamat;
    del->alamat = NULL;
    free(del);
	}
    

}

int main()

{
    int i,tukar;
    element * listUtama;
    int n;
    char tempgender[10];
    char tempnama[15];
    int tempusia;
    int z;
    int inputan = 10;
    bantuan input[100];
    int tambah = 0;
    int keluar;
    int j;
    int belum = 0;
    int last = 0;
    int kek = 0; //Menampung jumlah data
    scanf("%d",&inputan);
    while(inputan != 0){
    	
    	if(inputan == 1){ //jika inputan 1 maka diminta untuk memasukan data
    	printf("Masukan banyak data yang akan dimasukan \n");
    	scanf("%d",&kek);
    	tambah = tambah + kek;
    	for(i = last;i<tambah;i++){
    		
    	printf("Masukan data ke- %d \n",i);
    	cin>>input[i].nama;
    	cin>>input[i].gender;
    	cin>>input[i].usia;
  
		
		
	}
	
	last = tambah;
	}else if(inputan == 2 || inputan == 3){
			if(belum == 0)
			{
			belum = 1;


			do {
	
       tukar = 0;
        for(i=0;i<tambah-1;i++)
        {

 
            if(input[i].usia < input[i+1].usia)
            {
                tempusia = input[i].usia;
                strcpy(tempnama,input[i].nama);
                strcpy(tempgender,input[i].gender);

                input[i].usia = input[i+1].usia;
                strcpy(input[i].nama,input[i+1].nama);
                strcpy(input[i].gender,input[i+1].gender);

                input[i+1].usia = tempusia;
                strcpy(input[i+1].nama,tempnama);
                strcpy(input[i+1].gender,tempgender);
                tukar = 1;
            }else if(input[i].usia == input[i+1].usia){
            	if((strcmp(input[i].gender,"Laki-laki") == 0) && (strcmp(input[i+1].gender,"Perempuan") == 0)){
            		tempusia = input[i].usia;
                strcpy(tempnama,input[i].nama);
                strcpy(tempgender,input[i].gender);

                input[i].usia = input[i+1].usia;
                strcpy(input[i].nama,input[i+1].nama);
                strcpy(input[i].gender,input[i+1].gender);

                input[i+1].usia = tempusia;
                strcpy(input[i+1].nama,tempnama);
                strcpy(input[i+1].gender,tempgender);
                tukar = 1;
				}
            

        }
    }
    
    }while(tukar == 1);
   
//Inputan awal yang akan dipilih
    tempusia = input[0].usia;
    strcpy(tempnama,input[0].nama);
    strcpy(tempgender,input[0].gender);
    listUtama = CreatedList(tempnama,tempgender,tempusia);
    for(i = 1;i<tambah;i++){
    	akhir(input[i].nama,input[i].gender,input[i].usia,listUtama);
	}
}
		
		 
	    if(inputan == 2){//berapa banyak yang keluar
	    
	    scanf("%d",&z);
	    for( j = 0;j<z;j++){
	       deldepan(&listUtama);

		}
		}else if(inputan == 3){
			if(tambah != 0){
			cetak(listUtama);
			goto selesai;

			}else{
				printf("List Anda itu kosong");
			goto selesai;
			}
		}
		
	    
	}
	
	//Algoritma Bubble Sort
  scanf("%d",&inputan);
	
    	
	}
	
    
    selesai:
    

    return 0;



}

