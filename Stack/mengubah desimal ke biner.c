#include <stdio.h>
#define MAXSIZE 7
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
void pop(stack *s){
int i;


    printf("%d",s->data[s->top]);
    s->top--;


}



int main()
{

    stack s;
    s.top = -1;
    int desimal;
    printf("Masukan Bilangan Desimal \n");
    scanf("%d",&desimal);
    while(desimal > 0)
    {
        push(&s,desimal%2);
        desimal = desimal/2;

    }
    push(&s,desimal/2);
    while(s.top >= 0)
    {
        pop(&s);

    }


}
