#include <stdio.h>

typedef struct {
    float x, y;
} cordinates;

typedef struct{
    cordinates middle;
    float radius;
} Circle;
void Circle_print(Circle c){
    printf("Center: (%.2f, %.2f), Radius: %.2f\n", c.middle.x, c.middle.y, c.radius);
}
Circle Circle_read(){
    Circle c;
    printf("Enter center coordinates (x y): ");
    scanf("%f %f", &c.middle.x, &c.middle.y);
    printf("Enter radius: ");
    scanf("%f", &c.radius);
    return c;
}
int overlap(Circle a, Circle b){
    float dx = a.middle.x - b.middle.x;
    float dy = a.middle.y - b.middle.y;
    float distanceSquared = dx * dx + dy * dy;
    float radiusSum = a.radius + b.radius;
    return distanceSquared < (radiusSum * radiusSum);
}

int main(){
    Circle circles[3];
    for(int i=0;i<3;i++){
        printf("Circle %d:\n", i+1);
        circles[i] = Circle_read();
    }
    for(int i=0;i<3;i++){
        printf("Circle %d: ", i+1);
        Circle_print(circles[i]);
    }
    for(int i=0;i<3;i++){
        for(int j=i+1;j<3;j++){
            if(overlap(circles[i], circles[j])){
                printf("Circle %d overlaps with Circle %d\n", i+1, j+1);
            } else {
                printf("Circle %d does not overlap with Circle %d\n", i+1, j+1);
            }
        }
    }
    return 0;
}
