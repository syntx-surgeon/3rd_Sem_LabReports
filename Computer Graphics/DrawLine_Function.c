//write a C program to draw a Line by using building in function line().
#include <graphics.h>
#include <conio.h>
#include <stdio.h>

int main() {
    int gd = DETECT, gm;
    int x1, y1, x2, y2;

    // Initialize graphics mode
    initgraph(&gd, &gm, "");

    // Get line coordinates from user
    printf("Enter the starting point (x1, y1): ");
    scanf("%d %d", &x1, &y1);
    printf("Enter the ending point (x2, y2): ");
    scanf("%d %d", &x2, &y2);

    // Draw the line
    line(x1, y1, x2, y2);

    // Wait for a key press
    getch();

    // Close the graphics mode
    closegraph();
    return 0;
}
