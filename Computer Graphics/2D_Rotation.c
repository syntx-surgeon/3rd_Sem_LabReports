//write a C program to implement 2D rotation of a triangle
#include <graphics.h>
#include <conio.h>
#include <stdio.h>
#include <math.h>

#define PI 3.14159

typedef struct {
    int x, y;
} Point;

// Function to draw a triangle using the three vertices
void drawTriangle(Point p1, Point p2, Point p3) {
    line(p1.x, p1.y, p2.x, p2.y);  // Draw side from p1 to p2
    line(p2.x, p2.y, p3.x, p3.y);  // Draw side from p2 to p3
    line(p3.x, p3.y, p1.x, p1.y);  // Draw side from p3 to p1
}

// Function to rotate a point around the origin (0, 0) by angle ?
void rotate(Point *p, float angle) {
    // Convert the angle to radians
    float radian = angle * PI / 180.0;
    
    // Rotate the point using the rotation matrix
    int x_new = p->x * cos(radian) - p->y * sin(radian);
    int y_new = p->x * sin(radian) + p->y * cos(radian);
    
    // Update the point with the new rotated coordinates
    p->x = x_new;
    p->y = y_new;
}

// Function to rotate a point around an arbitrary pivot (cx, cy)
void rotateAroundPoint(Point *p, float angle, int cx, int cy) {
    // Translate the point to the origin
    p->x -= cx;
    p->y -= cy;
    
    // Rotate the point around the origin
    rotate(p, angle);
    
    // Translate the point back to its original position
    p->x += cx;
    p->y += cy;
}

int main() {
    int gd = DETECT, gm;
    Point p1, p2, p3;  // Declare points for the triangle
    float angle;        // Rotation angle
    int cx, cy;         // Pivot point (center of rotation)

    // Initialize graphics mode
    initgraph(&gd, &gm, "");

    // Get the coordinates of the triangle's vertices
    printf("Enter the coordinates of the triangle's vertices:\n");
    printf("Vertex 1 (x, y): ");
    scanf("%d %d", &p1.x, &p1.y);
    printf("Vertex 2 (x, y): ");
    scanf("%d %d", &p2.x, &p2.y);
    printf("Vertex 3 (x, y): ");
    scanf("%d %d", &p3.x, &p3.y);

    // Get the rotation angle and pivot point
    printf("Enter the rotation angle (in degrees): ");
    scanf("%f", &angle);
    printf("Enter the pivot point (cx, cy): ");
    scanf("%d %d", &cx, &cy);

    // Draw the original triangle
    drawTriangle(p1, p2, p3);

    // Perform rotation on each vertex around the pivot point
    rotateAroundPoint(&p1, angle, cx, cy);
    rotateAroundPoint(&p2, angle, cx, cy);
    rotateAroundPoint(&p3, angle, cx, cy);

    // Draw the rotated triangle
    setcolor(RED);  // Change color to distinguish the rotated triangle
    drawTriangle(p1, p2, p3);

    // Wait for the user to press any key before closing the graphics window
    getch();

    // Close the graphics mode
    closegraph();

    return 0;
}