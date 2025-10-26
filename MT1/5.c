#include <stdio.h>
double absolute(double t1, double t2){
    double t = t2-t1;
    
    if (t < 0){
    t = -t;
    }
    return t;
}

int main(){
    double t1;
    double t2;
    double max = 0;
    int interval = 0;
    scanf("%lf", &t2 );
    while (scanf("%lf", &t1)== 1 && t1 != 999.0){
        double swing = absolute (t1, t2);
        if (max < swing){
            max = swing;
        }
    interval++;
    t2 = t1;
    }
    printf("In the %d periods, the maximum swing was: %.2f", interval, max ); 
    return 0;
}