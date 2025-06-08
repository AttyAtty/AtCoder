#include <stdio.h>
#include <math.h>
#include <stdlib.h>

int main () {
    char arr[101];
    char output[101];
    int index = 0;

    if (fgets(arr, sizeof(arr), stdin) == NULL) {
        return 1;
    }

    for(int i = 0; i<100; i++){
        if (arr[i] >= 'A' && arr[i] <= 'Z') {
            output[index] = arr[i];
            index++;
        }
    }
    int count = 0;
    while(count < index){
        printf("%c",output[count]);
        count++;
    }
    printf("\n");
}
