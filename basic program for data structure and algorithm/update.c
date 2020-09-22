#include<stdio.h>
int main ()
{
    int arr[100],n,i,x,y;
    printf("enter the no. of elemnets\n");
    scanf("%d",&n);
    printf("enter the values of array\n");
    for(i=0;i<n;i++)
    {
        scanf("%d",&arr[i]);
    }
    printf("the primary array is\n");
    for(i=0;i<n;i++)
    {
        printf("%d\n",arr[i]);
    }
    printf("enter the position where you want to modify\n");
    scanf("%d",&x);
    if(x>=n+1 || x<1)
    {
        printf("modification not possible\n");
    }
    else
    {
       printf("enter the new value\n");
       scanf("%d",&y);
       arr[x-1]=y; 
    }
    printf("updated array is\n");
    for(i=0;i<n;i++)
    {
        printf("%d\n",arr[i]);
    }
}