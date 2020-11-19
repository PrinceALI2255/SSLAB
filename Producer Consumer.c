#include <stdio.h>
#include <stdlib.h>

int mutex=1,item=0,full=0,empty=3;
int main()
{
  printf("\nPRODUCER CONSUMER PROBLEM\n");
    int n;
    void producer();
    void consumer();
    int wait(int);
    int signal(int);
    printf("\n1.PRODUCER");
    printf("\n2.CONSUMER");
    printf("\n3.Exit\n");
    while (1)
    {
        printf("\nEnter the choice: ");
        scanf("%d",&n);
        switch (n)
        {
        case 1:
              if ((mutex == 1) && (empty != 0))
                  producer();
              else
                  printf("\nBuffer is full!!\n");
              break;
        case 2:
              if ((mutex == 1) && (full != 0))
                  consumer();
              else
                  printf("\nBuffer is empty!!\n");
              break;
        case 3:
              printf("\nProgram exited\n");
              exit(0);
              break;
        }
    }

    return 0;
}

int wait(int s)
{
    return (--s);
}

int signal(int s)
{
    return (++s);
}

void producer()
{
    mutex = wait(mutex);
    full = signal(full);
    empty = wait(empty);
    item++;
    printf("\nProducer produces item %d", item);
    mutex = signal(mutex);
}

void consumer()
{
    mutex = wait(mutex);
    full = wait(full);
    empty = signal(empty);
    printf("\nConsumer consumes item %d", item);
    item--;
    mutex = signal(mutex);
}