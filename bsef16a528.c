#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

void *Thread(void *vargp)
{
    int* a = (int*)vargp;
    int i;
    int tempSum=0;

	for(i=0;i<100;i++)
		{
			tempSum = tempSum + a[i];
		}

    return (void*)tempSum;
}



 
int main()
{

    int array[1000];
    int i; 

    for(i=0;i<1000;i++)
	{
		array[i]=i;
	}

    pthread_t tid[10];    
    int*  returns[10];

    for(i=0;i<10;i++)
	{
    		pthread_create(&tid[i], NULL, Thread, (void*)( array+(i*100) ) );
  	}
    for(i=0;i<10;i++)
	{
	    pthread_join(tid[i],(void*)&returns[i]);
	}

    int totalSum = 0;

    for(i=0;i<10;i++)
	{
		totalSum = totalSum + (int) returns[i];
	}
    
    printf("Total Sum is : %d",totalSum);

    exit(0);
}
