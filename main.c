#include <stdio.h>
#include <stdlib.h>
#define N 10
#define Find 1
#define Not_found -1

char** make_array(int* words)
{
    int str_len = 0, j = 0, i = 0, word_len = N;
    int k, word_len_old;
    char c;
    char** array = NULL;
    array = malloc(word_len * sizeof(*array));
    for (int z = 0; z < N; ++z)
    {
        array[z] = malloc(str_len * sizeof(**array));
    }

    start:
    str_len += N;
    k = N;
    array[i] = realloc(array[i],str_len*sizeof(char));
    while ((k != 0) && ((c = getchar()) != 10) && (c != ' '))
    {
        array[i][j++] = c;
        k--;
    }
    if (c == ' ')
    {
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
char* make_word_1()
{
    int str_len = 0, j = 0;
    int k;
    char c;
    char* str = NULL;
    str = malloc(str_len*sizeof(char));

    start:
    str_len += N;
    k = N;
    str = realloc(str,str_len*sizeof(char));
    while ((k != 0) && ((c = getchar()) != 10))
    {
        if (c == ' ')
        {
            printf("You write spaces in your word, you cant find word with space");
            return NULL;
        }
        str[j++] = c;
        k--;
    }
    if (k == 0)
        goto start;
    else
        str[j] = 0;


    return str;
}
char* make_word_2(int* length)
{
    int str_len = 0, j = 0;
    int k;
    char c;
    char* str = NULL;
    str = malloc(str_len*sizeof(char));

    start:
    str_len += N;
    k = N;
    str = realloc(str,str_len*sizeof(char));
    while ((k != 0) && ((c = getchar()) != 10))
    {
        str[j++] = c;
        k--;
    }
    if (k == 0)
        goto start;
    else
        str[j] = 0;


    *length = str_len - k;
    return str;
}
int compare(char* array, char* word_1){
    int i = 1, j = 0, tmp_i;
    while (array[i] != 0){
        if (array[i] == word_1[j]){
            tmp_i = i;
            while (array[tmp_i] == word_1[j]){
                tmp_i++;
                j++;
            }
            if (word_1[j] == 0 && array[tmp_i] != 0)
                return Find;
            j = 0;
        }
        i++;
    }
    return Not_found;
}

int main() {
    int i, j, words_in_array, k, len;
    int count = 0;

    printf("Enter the string:");
    char** array = make_array(&words_in_array);

    printf("Enter the word_1:");
    char* word_1 = make_word_1();
    if (word_1 == NULL)
        return 0;

    printf("Enter the word_2:");
    char* word_2 = make_word_2(&len);

    for (j = 0; j < words_in_array; j++){
    if (compare(array[j], word_1) == Find){
        count++;
        i = 0; k = 0;
        array[j] = realloc(array[j],len * sizeof(*array));
        while (word_2[k] != 0)
            array[j][i++] = word_2[k++];
        array[j][i] = 0;
    }
    }

    i = 0;
     for (j = 0;j < words_in_array; j++){
        while (array[j][i] != 0){
            printf("%c",array[j][i]);
            i++;
        }
        printf("\n");
        i = 0;
    }

    for(j = 0; j < words_in_array; j++)
        free(array[j]);
    free(array);
    free(word_1);
    free(word_2);

    printf("%d",count);
    return 0;
}//заменить выписанные слова другим введённым словом и счётчик замен
