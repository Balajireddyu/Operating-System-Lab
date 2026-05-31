#include <stdio.h>

void firstFit(int bs[], int b, int ps[], int p)
{
    int a[p];
    int u[b];

    for(int i = 0; i < p; i++)
        a[i] = -1;

    for(int i = 0; i < b; i++)
        u[i] = 0;

    for(int i = 0; i < p; i++)
    {
        for(int j = 0; j < b; j++)
        {
            if(!u[j] && bs[j] >= ps[i])
            {
                a[i] = j;
                u[j] = 1;
                break;
            }
        }
    }

    printf("\nFirst Fit\n");
    printf("Process\tSize\tBlock\n");

    for(int i = 0; i < p; i++)
    {
        printf("P%d\t%d\t", i + 1, ps[i]);

        if(a[i] != -1)
            printf("%d\n", a[i] + 1);
        else
            printf("Not Allocated\n");
    }
}

void bestFit(int bs[], int b, int ps[], int p)
{
    int a[p];
    int u[b];

    for(int i = 0; i < p; i++)
        a[i] = -1;

    for(int i = 0; i < b; i++)
        u[i] = 0;

    for(int i = 0; i < p; i++)
    {
        int bestIdx = -1;

        for(int j = 0; j < b; j++)
        {
            if(!u[j] && bs[j] >= ps[i])
            {
                if(bestIdx == -1 || bs[j] < bs[bestIdx])
                    bestIdx = j;
            }
        }

        if(bestIdx != -1)
        {
            a[i] = bestIdx;
            u[bestIdx] = 1;
        }
    }

    printf("\nBest Fit\n");
    printf("Process\tSize\tBlock\n");
    for(int i = 0; i < p; i++)
    {
        printf("P%d\t%d\t", i + 1, ps[i]);

        if(a[i] != -1)
            printf("%d\n", a[i] + 1);
        else
            printf("Not Allocated\n");
    }
}

void worstFit(int bs[], int b, int ps[], int p)
{
    int a[p];
    int u[b];

    for(int i = 0; i < p; i++)
        a[i] = -1;

    for(int i = 0; i < b; i++)
        u[i] = 0;
    for(int i = 0; i < p; i++)
    {
        int worstIdx = -1;

        for(int j = 0; j < b; j++)
        {
            if(!u[j] && bs[j] >= ps[i])
            {
                if(worstIdx == -1 || bs[j] > bs[worstIdx])
                    worstIdx = j;
            }
        }
        if(worstIdx != -1)
        {
            a[i] = worstIdx;
            u[worstIdx] = 1;
        }
    }
    printf("\nWorst Fit\n");
    printf("Process\tSize\tBlock\n");
    for(int i = 0; i < p; i++)
    {
        printf("P%d\t%d\t", i + 1, ps[i]);

        if(a[i] != -1)
            printf("%d\n", a[i] + 1);
        else
            printf("Not Allocated\n");
    }
}
int main()
{
    printf("Name : UPPALURI BALAJI REDDY\nUSN : 1BF24CS323\n\n");
    int blocks, processes;
    printf("Enter number of blocks: ");
    scanf("%d", &blocks);
    int blockSize[blocks];
    printf("Enter block sizes:\n");
    for(int i = 0; i < blocks; i++)
        scanf("%d", &blockSize[i]);
    printf("Enter number of processes: ");
    scanf("%d", &processes);

    int processSize[processes];
    printf("Enter process sizes:\n");
    for(int i = 0; i < processes; i++)
        scanf("%d", &processSize[i]);
    firstFit(blockSize, blocks, processSize, processes);
    bestFit(blockSize, blocks, processSize, processes);
    worstFit(blockSize, blocks, processSize, processes);
    return 0;
}
