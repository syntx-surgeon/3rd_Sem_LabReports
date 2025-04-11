// Back Face Detection Algorithm in C using graphics.h      
// This program uses the graphics.h library to visualize the back-face detection algorithm.

#include <graphics.h>
#include <stdio.h>
/*
Input to be given:
Enter the number of polygons: 2

Enter coordinates of polygon 1:
Enter A (x1 y1 z1): 100 100 1
Enter B (x2 y2 z2): 200 100 1
Enter C (x3 y3 z3): 150 200 1

Enter coordinates of polygon 2:
Enter A (x1 y1 z1): 50 50 -1
Enter B (x2 y2 z2): 150 50 -1
Enter C (x3 y3 z3): 100 150 -1
*/
// Structure for a 3D point
typedef struct {
    int x, y, z;
} Point3D;

void crossProduct(Point3D v1, Point3D v2, Point3D *cross) {
    cross->x = v1.y * v2.z - v1.z * v2.y;
    cross->y = v1.z * v2.x - v1.x * v2.z;
    cross->z = v1.x * v2.y - v1.y * v2.x;
}

int isBackFace(Point3D p1, Point3D p2, Point3D p3) {
    Point3D v1, v2, normal;
    
     v1.x = p2.x - p1.x;
    v1.y = p2.y - p1.y;
    v1.z = p2.z - p1.z;

    v2.x = p3.x - p1.x;
    v2.y = p3.y - p1.y;
    v2.z = p3.z - p1.z;

    // Compute normal (cross product of AB and AC)
    crossProduct(v1, v2, &normal);

    // Viewing vector is (0, 0, 1)
    float dotProduct = normal.z;

    // If dot product ≤ 0, the polygon is back-facing
    return dotProduct <= 0;
}

// Function to draw a triangle
void drawTriangle(Point3D p1, Point3D p2, Point3D p3, int color) {
    setcolor(color);
    line(p1.x, p1.y, p2.x, p2.y);
    line(p2.x, p2.y, p3.x, p3.y);
    line(p3.x, p3.y, p1.x, p1.y);
}

int main() {
    int gd = DETECT, gm;
    initgraph(&gd, &gm, NULL);
    
    int n;
    printf("Enter the number of polygons: ");
    scanf("%d", &n);
    
    for (int i = 0; i < n; i++) {
        Point3D p1, p2, p3;
        
        printf("\nEnter coordinates of polygon %d:\n", i + 1);
        printf("Enter A (x1 y1 z1): ");
        scanf("%d %d %d", &p1.x, &p1.y, &p1.z);
        printf("Enter B (x2 y2 z2): ");
        scanf("%d %d %d", &p2.x, &p2.y, &p2.z);
        printf("Enter C (x3 y3 z3): ");
        scanf("%d %d %d", &p3.x, &p3.y, &p3.z);

        // Convert 3D to 2D (ignore Z-axis)
        p1.z = 0;  
        p2.z = 0;  
        p3.z = 0;

        // Determine if the polygon is back-facing
        if (isBackFace(p1, p2, p3)) {
            printf("Polygon %d is BACK-FACING (Hidden)\n", i + 1);
            drawTriangle(p1, p2, p3, RED);  // Draw in red
        } else {
            printf("Polygon %d is FRONT-FACING (Visible)\n", i + 1);
            drawTriangle(p1, p2, p3, GREEN);  // Draw in green
        }
    }

    // Wait for user input before closing
    getch();
    closegraph();

    return 0;
}