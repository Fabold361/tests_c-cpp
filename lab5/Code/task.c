#include <stdio.h>
#include <string.h>


void erase_all_of(char const *str, char *result, const char *to_erase){

    
 int i;
 int j = 0;
    for (i = 0; i < strlen(str); i++){
        if (str[i] != to_erase[0] && str[i] != to_erase[1]){    //checkt ob str an stelle i -> i geht von 0 bis länge von str (input) ungleich wie to_erase ist und wenn beide gleich sind wird die stelle skip
            
            result[j] = str[i];
              j++;
        }
        

    }
    result[i] = '\0';





} 










int main() {
 char str[] = "hello, world!";
 char result[256];
 const char to_erase[] = "oe";
 erase_all_of(str, result, to_erase);
 printf("%s\n", result); // expected to print "hll, wrld!"
 erase_all_of(str, result, ",!");
 printf("%s\n", result); // expected to print "hello world"
}

