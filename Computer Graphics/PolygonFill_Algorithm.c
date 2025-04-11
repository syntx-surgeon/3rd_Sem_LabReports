
//polygon
#include <graphics.h>
#include <conio.h>
#include <stdio.h>

#define MAX_VERTICES 20

typedef struct { int x, y; } Point;

void scanFill(Point v[], int n) {
    int edges[MAX_VERTICES][2], edgeCount = 0;
    for (int i = 0; i < n; i++) {
        edges[edgeCount][0] = (v[i].y > v[(i + 1) % n].y) ? v[(i + 1) % n].x : v[i].x;
        edges[edgeCount++][1] = (v[i].y > v[(i + 1) % n].y) ? v[(i + 1) % n].y : v[i].y;
    }
    for (int y = edges[0][1]; y <= edges[edgeCount - 1][1]; y++) {
        int xStart = 0, xEnd = 0;
        for (int i = 0; i < edgeCount; i++) {
            if (edges[i][1] == y) {
                if (xStart == 0) xStart = edges[i][0];
                else xEnd = edges[i][0];
            }
        }
        if (xStart && xEnd) for (int x = xStart; x <= xEnd; x++) putpixel(x, y, WHITE);
    }
}

int main() {
    int gd = DETECT, gm, n;
    Point v[MAX_VERTICES];
    initgraph(&gd, &gm, "C:\\Turboc3\\BGI");
    printf("Enter number of vertices: ");
    scanf("%d", &n);
    printf("Enter vertices (x y):\n");
    for (int i = 0; i < n; i++) scanf("%d %d", &v[i].x, &v[i].y);
    for (int i = 0; i < n; i++) line(v[i].x, v[i].y, v[(i + 1) % n].x, v[(i + 1) % n].y);
    scanFill(v, n);
    getch();
    closegraph();
    return 0;
}
