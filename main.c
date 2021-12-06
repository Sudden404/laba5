#include <stdio.h>
#include <stdlib.h>
#define N 10
char* make_array(){
    int str_len = 0,k,j = 0;
    char c;
    char** array = NULL;
    char* str = NULL;
    array = malloc(N * sizeof(*array));
    for (int i = 0; i < N; ++i) {
        array[i] = malloc(N * sizeof(**array));
    }
    str = malloc(str_len*sizeof(char));

    start:
    str_len += N;
    k = N;
    str = realloc(str,str_len*sizeof(char));
    while ((k != 0) && ((c = getchar()) != 10)){
        str[j++] = c;
        k--;
    }
    if (k == 0)
        goto start;
    else str[j] = 0;
    return str;
}

int main() {
    char* q = make_array();
    while (*q != 0){
        printf("%c",*q);
        q++;
    }
    return 0;
}
