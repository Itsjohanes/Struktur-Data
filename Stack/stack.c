#include <stdio.h>
typedef struct stacks
{

    int data[30];
    int top;

}stacks;

void push(int data,stacks * s)
{

    if(s->top < 30 )
    {

        s->top++;
        s->data[s->top] = data;
    }else
    {

        printf("penuh");

    }
}
void pop(stacks * s)
{

    if(s->top != -1)
    {

        printf("%d",s->data[s->top]);
        s->top --;
    }else
    {

        printf("kosong \n");
    }
}
int main()
{

	stacks s;
    push(3,&s);
    pop(&s);

}
