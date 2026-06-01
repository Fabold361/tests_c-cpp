#include <string.h>
#include <stdio.h>
#include <assert.h>

int concatenate(const char *s1, const char *s2, int size, char *result){
    int good_size;

    if (strlen(s1) + strlen(s2) + 1 > size) return good_size = 0;
    else good_size = 1;

    int i;
    for (i = 0; i < strlen(s1); i++){
        result[i] = s1[i];
    }
    
    int j;
    for (j = 0; j < strlen(s2); j++){
        
        result[i] = s2[j];
        i++;
    }

    result[i] = '\0';

    return good_size;
}





int main(){


    char s1[] = "ab";
    char s2[] = "cdef";
    int size = 10;
    char result[size];

    printf("%d\n", concatenate(s1, s2, size, result));

    printf("String: %s\n", result);


    return 0;
}