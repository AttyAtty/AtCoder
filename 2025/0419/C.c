#include <stdio.h>

int sum(int N, int M, int A, int B1, int B2){
    int result = 0;
    for(int i=0; i<N; i++){
        int x1 = (A*i + B1) % M;
        int x2 = (A*i + B2) % M;
        result += x1*x2;
    }
    return result;
}

int main () {
    int T, N, M, A, B1, B2;
    scanf("%d ", &T);
    while(scanf("%d", &N) != EOF){
        scanf(" %d %d %d %d", &M,&A,&B1,&B2);
        int result = sum(N,M,A,B1,B2);
        printf("%d\n", result);
    }
}
