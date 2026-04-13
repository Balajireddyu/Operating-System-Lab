#include <stdio.h>

int in = 0, out = 0;
int mutex = 1, Full = 0, Empty = 10;
int a[10];

void wait(int *s)
{
    while (*s <= 0)
        ;
    (*s)--;
}

void signal(int *s)
{
    (*s)++;
}

int main()
{
    int p, item,c=0;;
    while (1)
    {
        printf("\n1: Produce\n2: Consume\n3: Exit\nEnter choice: ");
        scanf("%d", &p);
        if (p == 1)
        {
            wait(&Empty);
            wait(&mutex);
            printf("Enter number to produce: ");
            scanf("%d", &item);
            if(c==10){
                printf("Over FLow");
            }
            a[in] = item;
            in = (in + 1) % 10;
            c++;
            printf("Produced: %d\n", item);
            signal(&mutex);
            signal(&Full);
        }
        else if (p == 2)
        {
            wait(&Full);
            wait(&mutex);
            if(c==0){
                printf("Under FLow");            
            }
            item = a[out];
            out = (out + 1) % 10;
            printf("Consumed: %d\n", item);
            c--;
            signal(&mutex);
            signal(&Empty);
        }
        else if (p == 3)
        {
            break;
        }
        else
        {
            printf("Invalid choice\n");
        }
    }

    return 0;
}