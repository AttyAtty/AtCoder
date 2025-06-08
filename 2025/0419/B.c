#include <stdio.h>

int main() {
    int Q;
    scanf("%d", &Q);

    int queue[100];
    int front = 0, rear = 0;

    for (int i = 0; i < Q; i++) {
        int type;
        scanf("%d", &type);

        if (type == 1) {
            int x;
            scanf("%d", &x);
            queue[rear] = x;
            rear++;
        } else if (type == 2) {
            printf("%d\n", queue[front]);
            front++;
        }
    }

    return 0;
}
