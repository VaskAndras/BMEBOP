#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char * copystring(char * a ){
    int length = 0;
    while(a[length] != '\0')length++;
    char * s = (char *)malloc((length+1)*sizeof(char));
    if (s == NULL){
        printf("Allocation failed") ;}
    else{
    for (int i = 0; i < length+1; i++){
        s[i] = a[i];
    }
    return s;
    }
return NULL;
}

char * copycat(char * a , char * b ){
    int length1 = 0;
    int length2 = 0;

    while(a[length1] != '\0')length1++;
    while(b[length2] != '\0')length2++;

    char * s = (char *)malloc((length1+length2+1)*sizeof(char));
    if (s == NULL){
        printf("Allocation failed") ;}
    else{
    for (int i = 0; i < length1; i++){
        s[i] = a[i];
    }

    for (int i = 0; i < length2; i++){
    s[length1 + i] = b[i];
    }
    s[length1+length2] = '\0';
    return s;
    }

return NULL;
}

int main(){
    char *x;
    x = copystring("apple");  /* from the previous task */

    x = copycat(x, "tree");
    printf("%s\n", x);    // appletree

    free(x);

    return 0;
}

