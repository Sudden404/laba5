#include <stdio.h>
#include <stdlib.h>
#define N 10
char** make_array(int* words){
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
    if (array[i][j-1] != ' ')
        i++;
    *words = i;
    return array;
}
char* make_word(){
    int str_len = 0,k,j = 0;
    char c;
    char* str = NULL;
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
int compare(char* array,char* word){
    int i = 1, j = 0,tmp_i;
    while (array[i] != 0){
        if (array[i] == word[j]){
            tmp_i = i;
            while (array[tmp_i] == word[j]){
                tmp_i++;
                j++;
            }
            if (word[j] == 0 && array[tmp_i] != 0)
                return 1;
            j = 0;
        }
        i++;
    }
    return 0;
}

int main() {
    int i = 0,j = 0,words,k = 0;
    printf("Enter the string:");
    char** array = make_array(&words);
   /* for (j = 0;j < words; j++){
        while (array[j][i++] != 0)
            printf("%c",array[j][i]);
        printf("\n");
        i = 0;
    }*/
    printf("Enter the word:");
    char* word = make_word();
   /* while (word[k++] != 0)
        printf("%c",word[k]);*/

    for (j = 0;j< words;j++){
    if (compare(array[j],word) == 1){
        i = 0;
        while (array[j][i] != 0){
            printf("%c",array[j][i]);
            i++;
        }
        printf("\n");
    }
    }
    return 0;
}
