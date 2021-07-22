#include <stdio.h>
#include <malloc.h>
#include <stdlib.h>
#include <string.h>
/* Johannes Alexander Putra


*/
struct vertex
{
    struct edge * jalur;
    struct vertex * next;
    char a[200];

};
struct edge
{

    struct edge *nextedge;
    struct vertex * tujuan;
    int beban;

};
struct graph
{
    struct vertex * first;
};
void newgraph(struct graph * g)
{
    g->first = NULL;
}
void buatvertex(char a[200],struct graph * g)
{

    struct vertex *vertexbaru = (struct vertex*)malloc(sizeof(struct vertex));
    strcpy(vertexbaru->a,a);
    vertexbaru->jalur  = NULL;
    vertexbaru->next = NULL;
    if(g->first == NULL)
    {

        g->first = vertexbaru;
    }else
    {

        struct vertex * bantu = g->first;
        while(bantu->next != NULL)
        {

            bantu = bantu->next;
        }
        bantu->next = vertexbaru;
    }
}
void buatedge(struct vertex * awal, struct vertex * akhir,int beban )
{
    struct edge *edgebaru = (struct edge*)malloc(sizeof(struct edge));
    edgebaru->beban  = beban;
    edgebaru->nextedge = NULL;
    edgebaru->tujuan = akhir;
    if(awal->jalur == NULL)
    {
        awal->jalur  = edgebaru;
    }else
    {

        struct edge * bantu = awal->jalur;
        while(bantu->nextedge != NULL)
        {

            bantu = bantu->nextedge;
        }
        bantu->nextedge = edgebaru;
    }
}
struct vertex *cari(char a[200],struct graph  *g ) //cari simpul (vertexnya)
{
    struct vertex * hasil = NULL;
    struct vertex * help = g->first;
    int ketemu = 0;
    while((help != NULL) && ketemu == 0)
    {
        if(strcmp(help->a,a) == 0)
        {
            hasil  = help;
            ketemu  = 1;
        }else
        {

            help = help->next;
        }

    }
    return hasil;
}
void print(struct graph * g)
{

    struct vertex *tempvertex = g->first; //dari awal telusuri vertex
    if(tempvertex != NULL)
    {

        printf("Data simpul \n");
        while(tempvertex != NULL)
        {

            printf("\n simpul %s \n",tempvertex->a);
            struct edge *tempedge = tempvertex->jalur ; //menelusuri edge/jalur
            while(tempedge != NULL)
            {

                printf("terhubung simpul %s dengan beban %d ",tempedge->tujuan->a,tempedge->beban);
                tempedge  = tempedge->nextedge;
                printf("\n");
            }
           tempvertex = tempvertex->next;
        }
        printf("================================");
    }else
    {

        printf("Kosongg");
    }
}
void delall(struct vertex* g)
{

    struct edge * bantu = g->jalur;
    struct edge  * hapus = NULL;
    while(bantu != NULL)
    {
        hapus = bantu;
        bantu = bantu->nextedge;
        g->jalur = bantu;
        hapus->nextedge = NULL;
        free(hapus);
    }
}

void deljalur(char tujuan[200],struct vertex * g)
{

    struct edge * hapus  = g->jalur;
    if(hapus != NULL) //MENCARI JALUR YANG AKAN DIHAPUS
    {

        struct edge * prev = NULL;
        int ketemu  = 0;
        while(hapus != NULL && ketemu == 0)
        {

            if(strcmp(hapus->tujuan->a,tujuan) == 0)
            {

                ketemu = 1;
            }else
            {

                prev = hapus;
                hapus = hapus->nextedge;
            }
        }
        if(ketemu == 1)
        {

            if(prev == NULL) //Hapus jalur pertama
            {
                g->jalur = hapus->nextedge;
                hapus->nextedge = NULL;
            }else
            {
                if(hapus->nextedge == NULL) // hapus jalur terakhir
                {
                    prev->nextedge = NULL;
                }else//hapus jalur tengah
                {

                    prev->nextedge = hapus->nextedge;
                    hapus->nextedge = NULL;
                }

            }
            free(hapus);
        }else
        {

            printf("ndak ada \n");
        }

    }
    else
    {

        printf("ndak ada \n");
    }

}
void delsimpul(char c[200],struct graph * g)
{
    struct vertex * hapus  = g->first;
    if(hapus != NULL)
    {

       struct vertex * prev = NULL;
        int ketemu = 0;
        while((hapus != NULL) && ketemu == 0)
        {

            if(strcmp(hapus->a,c) == 0)
            {

                ketemu  = 1;

            }else
            {

                prev = hapus;
                hapus  = hapus->next;
            }
        }
        if(ketemu == 1)
        {

            struct vertex * bantu = g->first;
            while(bantu != NULL) //panggil deljalur
            {

                if(bantu != hapus)
                {
                    deljalur(hapus->a , bantu);


                }
                bantu = bantu->next;
            }
            delall(hapus);
            if(prev == NULL) //deldepan
            {
                g->first = hapus->next;
                hapus->next = NULL;

            }else
            {

                if(hapus->next == NULL)//delujung
                {

                    prev->next = NULL;
                }else //del tengah
                {

                    prev->next = hapus->next;
                    hapus->next = NULL;
                }
            }
            free(hapus);
        }
        else
        {

            printf("nda ada \n");
        }
    }
    else
    {

        printf("nda ada \n");
    }


}


int main()
{

    struct graph g;
    struct vertex *a1, *a2, *a3, *a4, *a5;
    newgraph(&g);
    buatvertex("Jakarta",&g);
    buatvertex("Bandung",&g);
    buatvertex("Yogjakarta",&g);
    buatvertex("Solo",&g);
    buatvertex("Surabaya",&g);
    a1=cari("Jakarta",&g);
    a2=cari("Bandung",&g);
    a3=cari("Yogjakarta",&g);
    a4=cari("Solo",&g);
    a5=cari("Surabaya",&g);
    buatedge(a1,a2,300);
    buatedge(a5,a2,1200);
    buatedge(a3,a2,1000);
    buatedge(a1,a4,1000);
    buatedge(a1,a5,1500);
    buatedge(a5,a3,300);
    buatedge(a2,a1,400);
    buatedge(a4,a2,700);
    print(&g);
    printf("\n");
    printf("Setelah di delete Jalur  yang menghubungkan jakarta ke Bandung: \n");
    a1 = cari("Jakarta",&g);
   if(a1 !=NULL)
   {
       deljalur("Bandung" ,a1);
   }
    print(&g);
    printf("\n");
    printf("setelah di delete jalur antara Surabaya ke Bandung \n");
    a5 = cari("Surabaya",&g);
    if(a5 != NULL)
    {
        deljalur("Bandung",a5);
    }
    print(&g);
    delsimpul("Surabaya",&g);
    print(&g);
    return 0;

}
