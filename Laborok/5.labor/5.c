#include <stdio.h>
int main(){
    int h=1,m=2,s=3;
    int maxSpeed[24] = {0}; 
    while (h+m+s != 0) {
        printf("Please enter hours, minutes, and the speed: ");
        scanf("%d %d %d", &h, &m, &s);
    if (h >= 0 && h < 24 && m >= 0 && m < 60 && s > 0) {
        if (s > maxSpeed[h]) {
                maxSpeed[h] = s;  
            }
        }
    }
    for (int i = 0; i < 24; i++) {
        if (maxSpeed[i] == 0) {
            printf("%02d:00-%02d:59 No data\n", i, i);
        } 
        else {
        printf("%02d:00-%02d:59 Max Speed = %dkm/h \n", i, i, maxSpeed[i]);
        }
    }
    return 0;
}