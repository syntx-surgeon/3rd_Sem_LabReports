
//bresenham algorithm
#include <graphics.h>
#include <stdio.h>
#include <conio.h>
#include <math.h>

void bresenhamLine(int x1, int y1, int x2, int y2) {
    int dx = x2 - x1; // Change in x
    int dy = y2 - y1; // Change in y
    int steps, x, y, xIncrement, yIncrement;

    // Determine the number of steps required
    if (abs(dx) > abs(dy)) {
        steps = abs(dx);
    } else {
        steps = abs(dy);
    }

    // Calculate the increment in x and y for each step
    xIncrement = dx / (float)steps;
    yIncrement = dy / (float)steps;

    // Start from the first point
    x = x1;
    y = y1;

    // Draw the line
    for (int i = 0; i <= steps; i++) {
        putpixel((int)(x + 0.5), (int)(y + 0.5), WHITE); // Draw pixel
        x += xIncrement; // Increment x
        y += yIncrement; // Increment y
    }
}

int main() {
    // Initialize the graphics system
    int gd = DETECT, gm;
    initgraph(&gd, &gm, "C:\\Turboc3\\BGI"); // Adjust the path as necessary

    // Define the start and end points of the line
    int x1, y1, x2, y2;
    printf("Enter the coordinates of the first point (x1, y1): ");
    scanf("%d %d", &x1, &y1);
    printf("Enter the coordinates of the second point (x2, y2): ");
    scanf("%d %d", &x2, &y2);

    // Call the Bresenham line drawing function
    bresenhamLine(x1, y1, x2, y2);

    // Wait for a key press
    getch();

    // Close the graphics system
    closegraph();
    return 0;
}