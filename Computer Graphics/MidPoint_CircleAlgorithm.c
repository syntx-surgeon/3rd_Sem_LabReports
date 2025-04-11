// Mid Point Circle Algorithm
// This program uses the Midpoint Circle Drawing Algorithm to draw a circle on the screen.
//mid point circle
#include <graphics.h>
#include <conio.h>

void drawCircle(int xc, int yc, int r) {
    int x = 0, y = r, d = 1 - r;
    while (x <= y) {
        putpixel(xc + x, yc + y, WHITE);
        putpixel(xc - x, yc + y, WHITE);
        putpixel(xc + x, yc - y, WHITE);
        putpixel(xc - x, yc - y, WHITE);
        putpixel(xc + y, yc + x, WHITE);
        putpixel(xc - y, yc + x, WHITE);
        putpixel(xc + y, yc - x, WHITE);
        putpixel(xc - y, yc - x, WHITE);
        x++;
        if (d < 0) d += 2 * x + 1;
        else { y--; d += 2 * (x - y) + 1; }
    }
}

int main() {
    int gd = DETECT, gm, xc, yc, r;
    initgraph(&gd, &gm, "C:\\Turboc3\\BGI");
    printf("Enter center (xc, yc) and radius: ");
    scanf("%d %d %d", &xc, &yc, &r);
    drawCircle(xc, yc, r);
    getch();
    closegraph();
    return 0;
}