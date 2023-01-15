 #include <stdio.h>

#include <stdlib.h>

/* N tree implementasi Binary Tree

 Johanesalex774@gmail.com



*/



typedef struct Node

{

    char data;

    struct Node * nextchild;

    struct Node * nextsibling;



}Node;



Node * createtree(char a)

{

  Node * news;

  news = (Node *) malloc(sizeof(Node));

  news->data  = a;

  news->nextchild  = NULL;

  news->nextsibling = NULL;

  return news;

}

Node * telusuriparent(char a,  Node ** tree)

{



    Node * temp = (*tree);

    Node * child = NULL;

    while(temp->data !=  a && temp->nextchild != NULL)

    {

        //periksa anak

        child = temp->nextchild;

        while(child->data != a && child->nextsibling != NULL)

        {

            child = child->nextsibling;

        }

        if(child->data == a)

        {

             return temp;

        }

        temp = temp->nextchild;

        if(temp->data == a)

            return temp;





    }

  return temp;

}

void insertdata (char data,char parent,Node ** tree)

{



    Node * news;

    news = createtree(data);

    Node * posisiparent;

    posisiparent  = telusuriparent(parent, tree);

    if(posisiparent->nextchild == NULL)

    {

        posisiparent->nextchild = news;



    }else

    {



        Node * temp;

        temp = posisiparent->nextchild;

        while(temp->nextsibling != NULL)

        {

            temp = temp->nextsibling;

        }



        temp->nextsibling = news;

    }

}

void preorder(Node * tree)

{

    if(tree != NULL)

    {

        printf(" %c ",tree->data);

        Node * bantu = tree->nextchild;

        if(bantu != NULL)

        {

            if(bantu->nextsibling == NULL)

            {

                preorder(bantu);

            }



       else

        {

            while(bantu->nextsibling != bantu->nextchild)

            {



                preorder(bantu);

                bantu = bantu->nextsibling;

            }

            preorder(bantu);

        }

    }

}

}




int main()

{

    Node * trees  = NULL;

    trees =  createtree('A');

    Node * news = NULL;

   insertdata('B','A',&trees);

   insertdata('C','B',&trees);

   insertdata('D','B',&trees);

   insertdata('E','B',&trees);

   insertdata('F','A',&trees);

   insertdata('G','A',&trees);

   insertdata('H','G',&trees);

   insertdata('I','G',&trees);

   insertdata('J','I',&trees);

   insertdata('K','I',&trees);



   preorder(trees);





    return 0;

}