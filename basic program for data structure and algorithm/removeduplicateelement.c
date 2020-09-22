<<<<<<< HEAD
#include<stdio.h>
int main()
{
    int arr[100],n,x,y,c;
    printf("enter the no. of elements\n");
    scanf("%d",&n);
    printf("enter the elements of the arrayts\n");
    for (x=0;x<n; x++)
    {
        scanf("%d",&arr[x]);
    }
    for (x = 0; x < n; x++)
	{
		for(y = x + 1; y < n; y++)
		{
    		if(arr[x] == arr[y])
    		{
    			for(c = y; c < n; c++)
    			{
    				arr[c] = arr[c + 1];
				}
				n--;
				y--;
			}
		}
	}

 	printf("\n Final Array after Deleteing Duplicate Array Elements is:\n");
 	for (x = 0; x < n; x++)
  	{
 		printf("%d\t", arr[x]);
  	}	     
 	return 0;
}
=======
#include<stdio.h>
int main()
{
    int arr[100],n,x,y,c;
    printf("enter the no. of elements\n");
    scanf("%d",&n);
    printf("enter the elements of the arrayts\n");
    for (x=0;x<n; x++)
    {
        scanf("%d",&arr[x]);
    }
    for (x = 0; x < n; x++)
	{
		for(y = x + 1; y < n; y++)
		{
    		if(arr[x] == arr[y])
    		{
    			for(c = y; c < n; c++)
    			{
    				arr[c] = arr[c + 1];
				}
				n--;
				y--;
			}
		}
	}

 	printf("\n Final Array after Deleteing Duplicate Array Elements is:\n");
 	for (x = 0; x < n; x++)
  	{
 		printf("%d\t", arr[x]);
  	}	     
 	return 0;
}
>>>>>>> 44cd96e6d5939d24db9d5401cd86c5c52a5a91e5
