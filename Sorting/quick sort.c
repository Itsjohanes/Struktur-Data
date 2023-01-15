#include <stdio.h>
void quicksort(int arr[],int l,int r)
{
    int i;
    int j;
    i  = l;
    j  =  r;
    int pivot;
    int temp;
    pivot = arr[(i+r)/2];
    do
    {
        while(arr[i] < pivot && (i<=j))//pivot kanan
        {
            i++;
        }

        while(arr[j] > pivot && (i<=j))
        {
            j--;
        }
        if(i<j)
        {
            temp  = arr[i];
            arr[i] = arr[j];
            arr[j] = temp;
            i++;
            j--;
        }
    }while(i<j);
    if(l<j && j<r)
    {
        quicksort(arr,l,j);
    }
    if(i<r && i>l)
    {

        quicksort(arr,i,r);
    }

}
int main()
{
int i ;
    int arr[5] = {5,4,3,2,1};
    quicksort(arr,0,4);
    for(i = 0;i<5;i++)
    {
        printf("%d",arr[i]);
    }
}
