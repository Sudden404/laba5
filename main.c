#include <stdio.h>
#include <stdlib.h>
#define N 10
char* make_array(){
    int str_len = 0,k,j = 0,i = 0,word_len = N,word_len_old;
    char c;
    char** array = NULL;
    array = malloc(word_len * sizeof(*array));
    for (int z = 0; z < N; ++z) {
        array[z] = malloc(str_len * sizeof(**array));
    }

    start:
    str_len += N;
    k = N;
    array[i] = realloc(array[i],str_len*sizeof(char));
    while ((k != 0) && ((c = getchar()) != 10) && (c != ' ')){
        array[i][j++] = c;
        k--;
    }
    if (c == ' ') {
        array[i][j] = 0;
        j = 0;
        str_len = 0;
        if (i+1 < word_len)
            i++;
        else
        {
            word_len_old = word_len;
            word_len += 3;
            array = realloc(array,word_len * sizeof(*array));
            for(int d = word_len_old;d<word_len;++d)
                array[d] = malloc(sizeof(**array));
            i++;
        }
        goto start;

    }
    if (k == 0)
        goto start;
    else array[i][j] = 0;
    return array[3];
}

int main() {
    char* q = make_array();
    while (*q != 0){
        printf("%c",*q);
        q++;
    }
    return 0;
}
