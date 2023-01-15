#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define Maxsize 7
typedef struct queue
{

    int head;
    int tail;
    int data[Maxsize];
}queue;
void inialisasi(queue *q)
{
    q->head = -1;
    q->tail = -1;

}
int isFull(queue  q)
{
    if(q.head == 0 &&  q.tail == (Maxsize-1))
        return 1;
    else if((q.head) - (q.tail) == 1)
    {
    	return 1;
	}

    else
	{
		return 0;

	}
}
int isEmpty(queue q)
{
    if(q.head == -1 && q.tail == -1)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

void enQueue (queue *q,int data)
{
    if(isFull(*q) ==0)
    {
         if(q->head == -1)
    {
        q->head = q->head +1;

    }
    q->tail = (q->tail + 1)%Maxsize;
    q->data[q->tail] = data;
    }
    else
    {

        printf("Penuh");
    }
}


 void deQueue(queue *q){
 int dataHapus;
 if(isEmpty(*q)== 0){
  dataHapus=q->data[q->head];
  printf("Antrian yang keluar %d", dataHapus);
  q -> data[q -> head] = NULL;
  if(q->head==q->tail){
   q->head=-1;
   q->tail=-1;
  }else{
   q->head=((q->head)+1)%Maxsize;
  }
 }else{
  printf("Data Kosong !\n");
 }
}
void cetak(queue q)
{
  if(q.head != -1){

 int i;
  for(i=q.head; i<=q.tail; i++){
   printf("\nsisa : %d", q.data[i]);
  }
  printf("\n");
 }else{
  printf("Data Kosong\n");
 }
}
int main()
{


 queue q;
 inialisasi(&q);
 enQueue(&q,10);
 enQueue(&q,9);
 enQueue(&q,11);
 enQueue(&q,11);
 enQueue(&q,11);
 enQueue(&q,11);
 enQueue(&q,11);
 deQueue(&q);
 deQueue(&q);





 cetak(q);

return 0;

}



