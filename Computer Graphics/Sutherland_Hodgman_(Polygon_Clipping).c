// Sutherland-Hodgman Polygon Clipping Algorithm
// This program clips a polygon using the Sutherland-Hodgman algorithm.
// It uses the graphics.h library for drawing the polygon and clipping window.

#include <stdio.h>
#include <graphics.h>

#define MAX_POINTS 20
/*
Input to be given:
Enter the number of vertices: 4
Enter the coordinates of the polygon:
50 150
200 50
350 150
200 300
*/
// Clipping window boundaries
int x_min = 100, y_min = 100, x_max = 300, y_max = 300;

// Structure for a point
typedef struct {
    int x, y;
} Point;

// Function to compute intersection of polygon edge with a clipping edge
Point intersect(Point p1, Point p2, int edge) {
    Point new_point;
    float m;

    // Compute slope
    if (p1.x != p2.x) 
        m = (float)(p2.y - p1.y) / (p2.x - p1.x);

    switch (edge) {
        case 0:  // Left Edge (x = x_min)
            new_point.x = x_min;
            new_point.y = p1.y + m * (x_min - p1.x);
            break;
        case 1:  // Right Edge (x = x_max)
            new_point.x = x_max;
            new_point.y = p1.y + m * (x_max - p1.x);
            break;
        case 2:  // Bottom Edge (y = y_min)
            new_point.y = y_min;
            new_point.x = p1.x + (1 / m) * (y_min - p1.y);
            break;
        case 3:  // Top Edge (y = y_max)
            new_point.y = y_max;
            new_point.x = p1.x + (1 / m) * (y_max - p1.y);
            break;
    }
    return new_point;
}

// Function to check if a point is inside a clipping boundary
int isInside(Point p, int edge) {
    switch (edge) {
        case 0: return (p.x >= x_min);  // Left
        case 1: return (p.x <= x_max);  // Right
        case 2: return (p.y >= y_min);  // Bottom
        case 3: return (p.y <= y_max);  // Top
    }
    return 0;
}

// Sutherland-Hodgman Polygon Clipping function
void sutherlandHodgman(Point poly[], int *n) {
    Point new_poly[MAX_POINTS];
    int new_n, i, j;
    
    for (int edge = 0; edge < 4; edge++) {
        new_n = 0;
        for (i = 0; i < *n; i++) {
            j = (i + 1) % *n;  // Next vertex
            Point p1 = poly[i], p2 = poly[j];

            int inside1 = isInside(p1, edge);
            int inside2 = isInside(p2, edge);

            if (inside1 && inside2) {  
                // Both inside: Keep second point
                new_poly[new_n++] = p2;
            } else if (inside1 && !inside2) {  
                // First inside, second outside: Keep intersection
                new_poly[new_n++] = intersect(p1, p2, edge);
            } else if (!inside1 && inside2) {  
                // First outside, second inside: Keep intersection & second point
                new_poly[new_n++] = intersect(p1, p2, edge);
                new_poly[new_n++] = p2;
            }
        }
        *n = new_n;
        for (i = 0; i < new_n; i++)
            poly[i] = new_poly[i];  // Update polygon points
    }
}

// Function to draw a polygon
void drawPolygon(Point poly[], int n, int color) {
    setcolor(color);
    for (int i = 0; i < n; i++) {
        int j = (i + 1) % n;
        line(poly[i].x, poly[i].y, poly[j].x, poly[j].y);
    }
}

int main() {
    int gd = DETECT, gm, n;
    Point poly[MAX_POINTS];

    // Initialize graphics
    initgraph(&gd, &gm, NULL);

    // Get polygon input
    printf("Enter the number of vertices: ");
    scanf("%d", &n);
    
    printf("Enter the coordinates of the polygon:\n");
    for (int i = 0; i < n; i++) {
        scanf("%d %d", &poly[i].x, &poly[i].y);
    }

    // Draw original polygon (WHITE)
    drawPolygon(poly, n, WHITE);

    // Draw clipping window (YELLOW)
    setcolor(YELLOW);
    rectangle(x_min, y_min, x_max, y_max);

    // Clip the polygon
    sutherlandHodgman(poly, &n);

    // Draw clipped polygon (RED)
    drawPolygon(poly, n, RED);

    // Wait for user to close
    getch();
    closegraph();

    return 0;
}
