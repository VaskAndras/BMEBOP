#include <stdio.h>
#include <math.h>
typedef struct {
    int x;
    int y;
} point;

point read_point() {
    point p;
    printf("Enter x and y coordinates: ");
    scanf("%d %d", &p.x, &p.y);
    return p;
}
point print_point(point p) {
    printf("Point coordinates: (%d, %d)\n", p.x, p.y);
    return p;
}
float distance(point a, point b) {
    int dx = a.x - b.x;
    int dy = a.y - b.y;
    return sqrt(dx * dx + dy * dy);
}
int equal(point a, point b) {
    return (a.x == b.x) && (a.y == b.y);
}
struct quadrangle {
    point p1, p2, p3, p4;
};
struct quadrangle read_quadrangle() {
    struct quadrangle q;
    printf("Enter coordinates for 4 points of the quadrangle:\n");
    q.p1 = read_point();
    q.p2 = read_point();
    q.p3 = read_point();
    q.p4 = read_point();
    return q;
}
float perimeter(struct quadrangle q) {
    return distance(q.p1, q.p2) + distance(q.p2, q.p3) + distance(q.p3, q.p4) + distance(q.p4, q.p1);
}
int main() {
    struct quadrangle q = read_quadrangle();
    printf("Perimeter of the quadrangle: %.2f\n", perimeter(q));
    return 0;
}
