
#include <stdio.h>
#include <stdlib.h>
typedef struct elememt
{
    int data;
    struct elememt * left;
    struct elememt * right;


}element;
element * createdtree(int data)
{
    element * tree;
    tree = (element *) malloc(sizeof(element));
    tree->data = data;
    tree->right = NULL;
    tree->left = NULL;
    return tree;

}
void inorder(element *p)
{

    if(p == NULL) return;
    inorder(p->left);
    printf("%d \n",p->data);
    inorder(p->right);

}


int main()
{

    element * tree;
    tree = createdtree(8);
    element * subtreekiri;
    subtreekiri = createdtree(38);
    tree->left = subtreekiri;
    element * subtreekanan;
    subtreekanan  = createdtree(18);
    tree->right = subtreekanan;
    element * Newtree;
    Newtree = createdtree(10);
    tree->left->left = Newtree;
    tree->left->right = Newtree;
    inorder(tree);

    return 0;
}
