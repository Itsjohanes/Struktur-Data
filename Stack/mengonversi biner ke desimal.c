#include <stdio.h>
#define MAXSIZE 5
typedef struct stack
{
    int data[MAXSIZE];
    int top;
}stack;
void push(stack * s,int x)
{//merenovasi rumah harus diberi alamatnya
    if(s->top <MAXSIZE-1)
    {
    s->top++;
    s->data[s->top] = x;
    }

    else
    {

        printf("Stack penuh");
    }
}
int pop(stack *s){
    int nilai;
    nilai = s->data[s->top];
    s->top--;
    return nilai;
}


int main()
{

    stack s;
    s.top = -1;
    int n,i,k, nilaidesimal = 0,nilaibiner;
    printf("Masukan jumlah digit biner");
    scanf("%d",&n);
    for(i=0;i<n;i++)
    {

        scanf("%d",&k);
        push(&s,k);

    }
    k = 1;
    for(i=0;i<n;i++)
    {

        nilaibiner = pop(&s);
        if(i>0)
        {

            k  = k * 2;
        }
            nilaidesimal += nilaibiner*k;

    }
printf("nilainya adalah %d",nilaidesimal);
}
