#include <stdio.h>
#include <stdlib.h>
#include <sys/time.h>

#define MAX 100
int adj[MAX][MAX], n, n_degree[MAX];
void computeInnode()
{
    int i,j;
    for (i = 0; i < n; i++)
    {
        n_degree[i] = 0;
        for (j = 0; j < n; j++)
        {
            if (adj[j][i] == 1)
            {
                n_degree[i]++;
            }
        }
    }
}
void toposort()
{
    computeInnode();
    int order[MAX], count=0, queue[MAX], rear=0, front=0;
    int i,v;
    for (i = 0; i < n; i++)
    {
        if (n_degree[i] == 0)
            queue[rear++] = i;
    }
    while(front<rear){
    v = queue[front++];
    order[count++] = v;
    for (i = 0; i < n; i++)
    {
        if (adj[v][i] == 1){
            n_degree[i]--;
            if (n_degree[i] == 0)
                queue[rear++] = i;
        }
    }
}
    if (count < n)
        printf("Cycle exists");
    for (i = 0; i < count; i++)
    {
        printf("%d ", order[i]+1);
    }
}
int main()
{
    int  i, j;
    struct timeval start, end;
    struct timezone ind;
    printf("Enter the number of vertices:");
    scanf("%d", &n);
    printf("Enter adjacency matrix:");
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < n; j++)
        {
            scanf("%d", &adj[i][j]);
        }
    }
    gettimeofday(&start, &ind);
    toposort();
    gettimeofday(&end, &ind);
    double time = (end.tv_sec - start.tv_sec) * 1e6 + (end.tv_usec - start.tv_usec);
    printf("\ntime : %.2f", time);
    return 0;
}