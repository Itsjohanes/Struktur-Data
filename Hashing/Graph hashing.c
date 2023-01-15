#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define max 4
struct vertex
{
    struct edge * jalur;
    char data[50];
    struct vertex * nextvertex;
};
struct edge
{
    struct edge * nextedge;
    struct vertex * tujuan;


};
struct graph
{
  struct vertex * first;
};
void newgraph(struct graph * g)
{
    g->first = NULL;
};
void buatvertex(char  a[50],struct graph * g)
{
    struct vertex * vertexbaru = (struct vertex*)malloc(sizeof(struct vertex));
  //  vertexbaru->data = a;
    strcpy(vertexbaru->data,a);
    vertexbaru->jalur = NULL;
    vertexbaru->nextvertex = NULL;
    if(g->first == NULL)
    {
        g->first = vertexbaru;

    }else
    {
        struct vertex * cari;
        cari = g->first;
        while(cari->nextvertex != NULL)
        {
            cari = cari->nextvertex;

        }
        cari->nextvertex = vertexbaru;
    }
}
void buatedge(struct vertex * awal, struct vertex * akhir)
{
    struct edge * baru = (struct edge*)malloc(sizeof(struct edge));
    baru->nextedge = NULL;
    baru->tujuan = akhir;
    if(awal->jalur == NULL)
    {
        awal->jalur = baru;
    }else
    {
        struct edge * cari = awal->jalur;
        while(cari->nextedge != NULL)
        {
            cari = cari->nextedge;
        }
        cari->nextedge = baru;
    }
}
struct vertex * cari(char  a[50],struct graph * g)
{
    struct vertex * hasil = NULL;
    struct vertex * help = g->first;
    int ketemu = 0;
    while(help != NULL && ketemu == 0)
    {
        if(strcmp(help->data,a) == 0)
        {
            hasil = help;
            ketemu = 1;
        }else
        {
            help = help->nextvertex;

        }
    }
    return hasil;
}
void printall(struct graph * g)
{
    struct vertex * tempvertex = g->first;

    if(tempvertex != NULL)
    {

        while(strcmp(tempvertex->data,"0")== 0 || strcmp(tempvertex->data,"1")== 0 || strcmp(tempvertex->data,"2")== 0||strcmp(tempvertex->data,"3")== 0 && tempvertex != NULL)
        {
            printf("chain[%s]->",tempvertex->data);
        struct edge * tempedge  = tempvertex->jalur;
        while(tempedge != NULL)
        {
            printf("%s->",tempedge->tujuan->data);
            tempedge = tempedge->nextedge;
        }
        printf("\n");
        tempvertex = tempvertex->nextvertex;
        }

    }
}
void deletesemua(struct graph * g)
{
    struct vertex * bantu = g->first;
    struct vertex * hapus = NULL;
    while(bantu != NULL)
    {
        hapus = bantu;
        bantu = bantu->nextvertex;
        g->first = bantu;
        free(hapus);
    }
}
void delall(struct vertex * g)
{
    struct edge * bantu = g->jalur;
    struct edge * hapus =  NULL;
    while(bantu != NULL)
    {
        hapus = bantu;
        bantu = bantu->nextedge;
        g->jalur = bantu;
        free(hapus);
    }
}
void deljalur(char  tujuan[50],struct vertex * g)
{
    struct edge * hapus = g->jalur;
    if(hapus != NULL)
    {
        struct edge * prev = NULL;
        int ketemu = 0;
        while(hapus != NULL && ketemu == 0)
        {
            if(strcmp(hapus->tujuan->data,tujuan)==0)
            {
                ketemu = 1;

            }else
            {
                prev = hapus;
                hapus  = hapus->nextedge;
            }
        }
        if(ketemu == 1)
        {
            if(prev == NULL)
            {
                g->jalur = hapus->nextedge;
            }else
            {
                if(hapus->nextedge == NULL)
                {
                    prev->nextedge = NULL;
                }else
                {
                    prev->nextedge = hapus->nextedge;
                    hapus->nextedge = NULL;
                }
            }
        }
    }
}
void delvertex(char tujuan[50],struct graph * g)
{
    struct vertex * hapus = g->first;
    if(hapus != NULL)
    {
        struct vertex * prev = NULL;
        int ketemu = 0;
        while(hapus != NULL && ketemu == 0)
        {
            if(strcmp(hapus->data,tujuan)==0)
            {
                ketemu = 1;

            }else
            {
                prev = hapus;
                hapus  = hapus->nextvertex;
            }
        }
        if(ketemu == 1)
        {
            struct vertex * bantu = g->first;
            while(bantu != NULL)
            {
                if(bantu != hapus)
                {
                    deljalur(hapus->data,bantu);
                }
                bantu = bantu->nextvertex;
            }
            delall(hapus);
            if(prev == NULL)
            {
                g->first = hapus->nextvertex;
                hapus->nextvertex = NULL;
            }else
            {
                if(hapus->nextvertex == NULL)
                {
                    prev->nextvertex = NULL;
                }else
                {
                    prev->nextvertex = hapus->nextvertex;
                    hapus->nextvertex = NULL;
                }
            }
        }
    }
}
int main()
{
    struct graph g;
    newgraph(&g);
    struct vertex *a1,*a2;
    buatvertex("0",&g);
    buatvertex("1",&g);
    buatvertex("2",&g);
    buatvertex("3",&g);
    char masukan[50];
    int i ;
    int hitung;
    hitung = 0;
     scanf("%s",masukan);
    for(i = 0;i<strlen(masukan);i++)
    {
        hitung = hitung + masukan[i];
    }
    int key;


    key = hitung % max;
    switch(key)
    {
        case 0:
        {
            buatvertex(masukan,&g);
            a1 = cari("0",&g);
            a2 = cari(masukan,&g);
            buatedge(a1,a2);
            break;
        }
        case 1:
        {
            buatvertex(masukan,&g);
            a1 = cari("1",&g);
            a2 = cari(masukan,&g);
            buatedge(a1,a2);
            break;
        }
        case 2:
        {
            buatvertex(masukan,&g);
            a1 = cari("2",&g);
            a2 = cari(masukan,&g);
            buatedge(a1,a2);
            break;
        }
        case 3:
        {
            buatvertex(masukan,&g);
            a1 = cari("3",&g);
            a2 = cari(masukan,&g);
            buatedge(a1,a2);
            break;
        }
    }



    printall(&g);

}
