
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef struct element
{
    int id;
    char namaproduk[10];
    int hargaproduk;
    struct element * next;
}element;
element * buatlist(int id,char namaproduk[10],int hargaproduk)
{

    element *elementBaru = NULL; //masih kosong

    elementBaru = (element*) malloc (sizeof(element));
    elementBaru -> id = id;
    strcpy(elementBaru->namaproduk,namaproduk);
    elementBaru->hargaproduk = hargaproduk;
    elementBaru -> next = NULL;
    return elementBaru;

}
void depan(int id,char namaproduk[10],int hargaproduk,element **listaku)
{

    element * newlist = buatlist(id,namaproduk,hargaproduk);
    newlist -> next = (*listaku);
    (*listaku) = newlist;



}
void belakang(int id,char namaproduk[10],int hargaproduk,element *listaku)
{
    element * newlist = buatlist(id,namaproduk,hargaproduk);
    element * temp = NULL;
    temp =  listaku;
    while(temp->next != NULL)
    {

        temp = temp->next;

    }
    temp->next= newlist;

}

void tengah(int id,char namaproduk[10],int hargaproduk,element *listaku)
{

    element * newlist = buatlist(id,namaproduk,hargaproduk);
    element * temp = NULL;
    temp = (listaku);
    (listaku) = newlist;
    while(temp->id != 8)
    {
        temp = temp->next;

    }

    newlist -> next = temp->next;
    temp -> next = newlist;


}
void cetak(element * listaku)
{


    element * temp = listaku;
     do
    {



        printf("Produk %d\n%s\n%d\n",temp->id,temp->namaproduk, temp->hargaproduk);
        temp = temp ->next;

    }

    while(temp!=NULL);

}
int main()
{
    element * mainutama;
    int id;
    char namaproduk[50];
    int hargaproduk;
    int inputan;
    printf("Element Pertama dalam List\n");
    printf("Id Produk:\n");scanf("%d",&id);
    getchar() !=0;
    printf("Nama Produk:\n");scanf("%[^\n]%*c", namaproduk);
    printf("harga Produk:\n");scanf("%d",&hargaproduk);
    getchar() !=0;
    mainutama = buatlist(id,namaproduk,hargaproduk);
    awal:
    printf("Masukan code  \n");
    printf("1.Depan 2.Tengah 3.belakang 4.langsung gas \n");
    scanf("%d",&inputan);
    switch(inputan)
    {

    case 1 :
    printf("Add Element di awal\n");
    printf("Id Produk:\n");scanf("%d",&id);
    getchar() !=0;
    printf("Nama Produk:\n");scanf("%[^\n]%*c", namaproduk);
    printf("harga Produk:\n");scanf("%d",&hargaproduk);
    getchar() !=0;
    depan(id,namaproduk,hargaproduk,&mainutama);
    goto awal;
    break;
    case 2:
    printf("Add Element di tengah\n");
    printf("Id Produk:\n");scanf("%d",&id);
    getchar() !=0;
    printf("Nama Produk:\n");scanf("%[^\n]%*c", namaproduk);
    printf("harga Produk:\n");scanf("%d",&hargaproduk);
    getchar() !=0;
    tengah(id,namaproduk,hargaproduk,mainutama);
    goto awal;
    break;
    case 3:
    printf("Add Element di belakang\n");
    printf("Id Produk:\n");scanf("%d",&id);
    getchar() !=0;
    printf("Nama Produk:\n");scanf("%[^\n]%*c", namaproduk);
    printf("harga Produk:\n");scanf("%d",&hargaproduk);
    getchar() !=0;
    belakang(id,namaproduk,hargaproduk,mainutama);
    goto awal;
    case 4:
    goto akhir;


    }

akhir:
    cetak(mainutama);
}
