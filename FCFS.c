#include<stdio.h>
#include<stdlib.h>
int main() 
{
    int DiskQueue[20], n, i, SeekTime=0, diff;
    printf("Enter the size of Queue= ");
    scanf("%d", &n);
    printf("Enter the Queue: ");
    for(i=1;i<=n;i++)
    {                                                     
        scanf("%d",&DiskQueue[i]);
    }
    printf("Enter the initial head position= ");
    scanf("%d",&DiskQueue[0]);                            
    printf("\nMovement of Cylinders\n");
    for(i=0;i<n;i++)
    {
        diff= abs(DiskQueue[i+1] - DiskQueue[i]);          
        SeekTime+= diff;                    
        printf("Move from %d to %d with seek time %d\n", DiskQueue[i], DiskQueue[i+1], diff);
    }
    printf("\nTotal Seek Time: %d",SeekTime);
    printf("\nAverage Seek Time = %f",(float) SeekTime);
    printf("\n");
    return 0;
}
