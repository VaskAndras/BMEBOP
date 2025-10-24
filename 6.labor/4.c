#include <stdio.h>
#include <math.h>

typedef struct{
    float vx, vy;
} sumvel ;

float velocity( sumvel V){
    return sqrt(V.vx * V.vx + V.vy * V.vy );
}
sumvel read_velocity(){
    sumvel v;
    printf("Enter vx and vy: ");
    scanf("%f %f", &v.vx, &v.vy);
    return v;
}
sumvel add_velocity(sumvel a, sumvel b){
    sumvel result;
    result.vx = a.vx + b.vx;
    result.vy = a.vy + b.vy;
    return result;
}
int main(){
    sumvel v1 = read_velocity();
    sumvel v2 = read_velocity();
    printf("Velocity 1: %.2f\n", velocity(v1));
    printf("Velocity 2: %.2f\n", velocity(v2));
    sumvel v3 = add_velocity(v1, v2);
    printf("Added Velocity: (%.2f, %.2f), Magnitude: %.2f\n", v3.vx, v3.vy, velocity(v3));
    return 0;
}
