/* by HunterXIII (Roman Volkov)*/
#include <stdio.h>
#include <stdlib.h>

char *strread() {
    /* 
        Read line and return array (char*)
    */
    char c;
    while ((c = getchar()) == '\n');
    int idx = 1;
    char *str = malloc(idx * sizeof(char));
    str[0] = c;

    while ((c = getchar()) != '\n') {
        idx++;
        char *new_str = realloc(str, idx * sizeof(char));
        str = new_str;
        str[idx - 1] = c;
    }
    idx++;
    char *new_str = realloc(str, idx * sizeof(char));
    str = new_str;
    str[idx - 1] = 0;
    // printf("strread: %s\n", str);
    return str;
}

