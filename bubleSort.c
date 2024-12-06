#include <stdio.h>
#include <stdlib.h>
#include <string.h>


int main()
{
        int arr[]={7,4,9,5,3,2,1};
        int size=sizeof(arr)/sizeof(arr[0]);
        int temp;
        for (int i = 0; i < size; i++)
        {
            temp=0;
            for (int j = 0; j < size; j++){
                if (arr[i]<arr[j])
                {
                    temp=arr[i];
                    arr[i]=arr[j];
                    arr[j]=temp;
                }
        }
            
        }
        for (int i = 0; i < size; i++)
        {
            printf("%d",arr[i]);
        }
        

        return 0;
}
