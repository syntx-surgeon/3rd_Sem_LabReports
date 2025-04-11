    
// This program draws a rectangle on the screen using the graphics library in C.
#include <graphics.h>
#include <conio.h>
#include <stdio.h>

void drawRectangle(int x1, int y1, int x2, int y2) {
    // Draw the rectangle using the rectangle function
    rectangle(x1, y1, x2, y2);
}

int main() {
    // Initialize the graphics system
    int gd = DETECT, gm;
    initgraph(&gd, &gm, "C:\\Turboc3\\BGI"); // Adjust the path as necessary

    // Define the coordinates of the rectangle's corners
    int x1, y1, x2, y2;
    printf("Enter the coordinates of the top-left corner (x1, y1): ");
    scanf("%d %d", &x1, &y1);
    printf("Enter the coordinates of the bottom-right corner (x2, y2): ");
    scanf("%d %d", &x2, &y2);

    // Call the function to draw the rectangle
    drawRectangle(x1, y1, x2, y2);

    // Wait for a key press
    getch();

    // Close the graphics system
    closegraph();
    return 0;
}
