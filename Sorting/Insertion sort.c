#include <stdio.h>
int main()
{

    int arr[5] = {5,4,3,2,1};
    int i;
    int sisip;
    int j;
    for(i=1;i<5;i++)
    {
        sisip = arr[i];
        j = i-1;
        while(sisip < arr[j] && j>=0)
        {
            arr[j+1] = arr[j];
            j--;

        }
        arr[j+1] = sisip;

    }
    for(i=0;i<5;i++)
    {
        printf("%d",arr[i]);
    }
}
