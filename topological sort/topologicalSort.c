#include <stdio.h>

int main() {
    int n, m, i, j;
    int a[100][100] = {0};
    int indeg[100] = {0};
    int q[100], front = 0, rear = 0;
    int res[100], k = 0;

    printf("Enter number of vertices: ");
    scanf("%d", &n);

    printf("Enter number of edges: ");
    scanf("%d", &m);

    printf("Enter edges (u v):\n");
    for(i = 0; i < m; i++) {
        int u, v;
        scanf("%d %d", &u, &v);
        a[u][v] = 1;
        indeg[v]++;
    }

    for(i = 0; i < n; i++) {
        if(indeg[i] == 0) {
            q[rear++] = i;
        }
    }

    while(front < rear) {
        int u = q[front++];
        res[k++] = u;

        for(int v = 0; v < n; v++) {
            if(a[u][v] == 1) {
                indeg[v]--;
                if(indeg[v] == 0) {
                    q[rear++] = v;
                }
            }
        }
    }

    if(k != n) {
        printf("G has cycles\n");
    } else {
        printf("Sorted order: ");
        for(i = 0; i < n; i++) {
            printf("%d ", res[i]);
        }
        printf("\n");
    }

    return 0;
}