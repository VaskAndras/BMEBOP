#include <stdio.h>
#include <ctype.h>

int is_vower(char c){
    int b = 0;
    c = tolower(c);
    if (c=='a' || c=='e' || c=='i' || c=='o' || c=='u'){
        b= 1;
    }
    return b;
}
int main(void) {
    char c;
    while (scanf("%c", &c) == 1) {
        if (is_vower(c)==1)
            printf("%ch%c", c, tolower(c));
        else
            printf("%c", c);
    }

    return 0;
}

