#include <stdio.h>
#include <stdlib.h>
int main(){
    char *s = ( char * ) malloc ( sizeof ( char ));
    char c;
    int num = 1;
    while (scanf("%c",&c) == 1 && c != '\0' ){
    num++;
    s = realloc (s, num*sizeof ( char ));
    s[num-1] = c;
    }
    for (int i = 0; s[i] != '\n'; i++){
        printf("%c \n", s[i]);
    }
    

    return 0;
}