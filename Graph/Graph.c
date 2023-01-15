#include <stdio.h>
#include <malloc.h>
#include <stdlib.h>
struct vertex
{
    struct edge * jalur;
    struct vertex * next;
    char a;

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
void buatvertex(char a,struct graph * g)
{

    struct vertex *vertexbaru = (struct vertex*)malloc(sizeof(struct vertex));
    vertexbaru->a = a;
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
struct vertex *cari(char a,struct graph  g )
{
    struct vertex * hasil = NULL;
    struct vertex * help = g.first;
    int ketemu = 0;
    while((help != NULL) && ketemu == 0)
    {
        if(help->a == a)
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

    struct vertex *tempvertex = g->first;
    if(tempvertex != NULL)
    {

        printf("Data simpul \n");
        while(tempvertex != NULL)
        {

            printf("\n simpul %c \n",tempvertex->a);
            struct edge *tempedge = tempvertex->jalur;
            while(tempedge != NULL)
            {

                printf("terhubung simpul %c dengan beban %d ",tempedge->tujuan->a,tempedge->beban);
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
void delall(struct graph * g)
{

    struct vertex * bantu = g->first;
    struct vertex * hapus = NULL;
    while(bantu != NULL)
    {
        hapus = bantu;
        bantu = bantu->next;
        g->first = bantu;
        free(hapus);
    }
}

void deljalur(char tujuan,struct graph * g)
{

    struct edge * hapus  = (*g).first;
    if(hapus != NULL)
    {

        struct edge * prev = NULL;
        int ketemu  = 0;
        while(hapus != NULL && ketemu == 0)
        {

            if(hapus->tujuan->a == tujuan)
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

            if(prev == NULL)
            {
                (*g).first = hapus->nextedge;
                hapus->nextedge = NULL;
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
void delsimpul(char c,struct graph * g)
{
    struct vertex * hapus  = g->first;
    if(hapus != NULL)
    {

       struct vertex * prev = NULL;
        int ketemu = 0;
        while((hapus != NULL) && ketemu == 0)
        {

            if(hapus->a == c)
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
            while(bantu != NULL)
            {

                if(bantu != hapus)
                {
                    deljalur(hapus->a , bantu);


                }
                bantu = bantu->next;
            }
            delall(hapus);
            if(prev == NULL)
            {
                g->first = hapus->next;
                hapus->next = NULL;

            }else
            {

                if(hapus->next == NULL)
                {

                    prev->next = NULL;
                }else
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
    struct vertex *a, *b, *c;
    newgraph(&g);
    buatvertex('a',&g);
    buatvertex('b',&g);
    buatvertex('c',&g);
    a = cari('a', g);
    b = cari('b', g);
    c = cari('c', g);
    buatedge(a,b,100);
    buatedge(a,c,20);
    buatedge(b,a,300);
    buatedge(c,a,100);
    print(&g);
   // delall(&g);
   a = cari('a',g);
   if(a !=NULL)
   {
       deljalur('b',a);
   }
    print(&g);
    return 0;

}
