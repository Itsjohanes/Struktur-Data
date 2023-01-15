#include <stdio.h>
#include <string.h>
typedef struct stacks
{

    char data[100];
    int top;

}stacks;
char copi[100];
void push(char data,stacks * s)
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

        char abc[100] = {s->data[s->top]};
        strcat(copi,abc);

        s->top --;
    }else
    {

        printf("kosong \n");
    }
}
int main()
{
    char kalimat[100];
    gets(kalimat);
    stacks s;
    s.top = -1;
    int i;
    for(i=0;i<strlen(kalimat);i++)
    {

        push(kalimat[i],&s);
    }
     for(i=0;i<strlen(kalimat);i++)
    {

        pop(&s);
    }
    if(strcmp(kalimat,copi)==0)
    {

        printf("palindrom");

    }else
    {

        printf("bukan palindrom");
    }




}

