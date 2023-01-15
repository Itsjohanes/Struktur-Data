
#include <stdio.h>
#include <stdlib.h>
typedef struct element
{

    int data;
    struct element * next;
    struct element * back;

}element;
element * created(int data)
{

    element * buat = NULL;
    buat = (element*)malloc(sizeof(element));
    buat->data = data;
    buat->next = NULL;
    buat->back = NULL;
    return buat;
}
void depan(int data,element ** list)
{
    element * newlist = created(data);
    newlist->next = (*list);
    (*list)->back = newlist;
    (*list) = newlist;
}
void tengah(int data,int cari,element * list)
{
     element * newlist = created(data);
     element * temp = NULL;
     temp = list;
     list = newlist;
     while(temp->data != cari)
     {

         temp = temp->next;
     }
     newlist->next = temp->next;
     temp->next = newlist;

}
void belakang (int data,element * list)
{

    element * newlist = created(data);
     element * temp = NULL;
     temp = list;
    // list = newlist;
     while(temp->next != NULL)
     {

         temp = temp->next;
     }
    temp->next = newlist;
    newlist->next = NULL;

}
void cetak(element * list)
{

    element * temp = list;
    do
    {
        printf("%d ",temp->data);
        temp = temp->next;
    }while(temp != NULL);
}
void delawal(element ** list)
{
    if(list != NULL)
    {
        element * hapus = (*list);
        (*list) = hapus->next;
        hapus->next = NULL;
        free(hapus);
    }
}
void deltengah(int cari,element * list)
{
 element * hapus = NULL;
 element * prev = NULL;
 hapus = list;
 prev = list;
 while(hapus->data != cari)
 {

     prev  = hapus;
     hapus = hapus->next;
 }
 prev->next = hapus->next;
 hapus->next = NULL;
 free(hapus);

}
void delakhir(element * list)
{
    element * hapus  = NULL;
    element * prev  = NULL;
    hapus = list;
    prev = list;
    while(hapus->next != NULL)
    {

        prev = hapus;
        hapus = hapus->next;
    }
    prev->next = hapus->next;
    hapus->next = NULL;
    free(hapus);

}
int main()
{

    element * list = NULL;
    list = created(10);
    depan(11,&list);
    depan(12,&list);
    tengah(20,11,list);
    //delakhir(list);
    //deltengah(20,list);
    //delawal(&list);
    cetak(list);
}
