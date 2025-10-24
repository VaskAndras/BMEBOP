#include <stdio.h>
#include <string.h>
int main(){
    char str1[61], str2[31];
    //read from user here
    printf("Enter first string (max 30 chars): ");
    for (int i = 0; i < 30; i++) {
        scanf("%s", &str1[i]);
        if (str1[i] == '\n') {
            str1[i] = '\0';
            break;
        }
    }
    for (int i = 0; i < 30; i++) {
        str2[i] = str1[i];
        if (str1[i] == '\0') {
            break;
        }
    } 
    str1[30] = '\0';
    str2[30] = '\0';
    for(int i=0;i<31;i++) {
        printf("%dth letter='%c', code=%d\n", i,str1[i], str2[i]);
    }
    printf("Length of str1: %lu\n", strlen(str1));
    printf("The result of the comparison: %d\n", strcmp(str1, str2));
    strcpy(str1, str2);
    printf("After copying, str1: %s\n", str1);
    strcat(str1, str2);
    printf("After concatenation, str1: %s\n", str1);

    return 0;
}