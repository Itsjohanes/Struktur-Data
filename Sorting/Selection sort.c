#include <stdio.h>
int main()
{

    int arr[5] = {5,3,4,2,1};
    int tukar;
    int minindex;
    int i;
    int j;
    for(i=0;i<4;i++)
    {
        minindex = i;
        for(j = i+1;j<5;j++)
        {
            if(arr[minindex]> arr[j])
            {

                minindex = j;
            }
        }
        tukar = arr[i];
        arr[i] = arr[minindex];
        arr[minindex] = tukar;

    }
    for(i=0;i<5;i++)
    {
        printf("%d",arr[i]);
    }
}
