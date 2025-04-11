// Cohen-Sutherland Line Clipping Algorithm in C
// This program uses the graphics.h library for drawing.

#include <stdio.h>
#include <graphics.h>

#define LEFT 1
#define RIGHT 2
#define BOTTOM 4
#define TOP 8
/*
Enter the coordinates of the line (x1 y1 x2 y2): 
50 200 350 200
*/
int x_min, y_min, x_max, y_max;

// Function to compute region code
int computeCode(int x, int y) {
    int code = 0;
    if (x < x_min) code |= LEFT;
    if (x > x_max) code |= RIGHT;
    if (y < y_min) code |= BOTTOM;
    if (y > y_max) code |= TOP;
    return code;
}

// Function to clip a line using Cohen-Sutherland algorithm
void cohenSutherlandClip(int x1, int y1, int x2, int y2) {
    int code1 = computeCode(x1, y1);
    int code2 = computeCode(x2, y2);
    int accept = 0;

    while (1) {
        if ((code1 == 0) && (code2 == 0)) {
            accept = 1; // Line is completely inside
            break;
        } else if (code1 & code2) {
            break; // Line is completely outside
        } else {
            int code_out;
            int x, y;

            // Pick an endpoint outside the clipping rectangle
            if (code1 != 0)
                code_out = code1;
            else
                code_out = code2;

            // Find intersection point
            if (code_out & TOP) { 
                x = x1 + (x2 - x1) * (y_max - y1) / (y2 - y1);
                y = y_max;
            } else if (code_out & BOTTOM) { 
                x = x1 + (x2 - x1) * (y_min - y1) / (y2 - y1);
                y = y_min;
            } else if (code_out & RIGHT) { 
                y = y1 + (y2 - y1) * (x_max - x1) / (x2 - x1);
                x = x_max;
            } else if (code_out & LEFT) { 
                y = y1 + (y2 - y1) * (x_min - x1) / (x2 - x1);
                x = x_min;
            }

            // Replace the endpoint outside with the new intersection
            if (code_out == code1) {
                x1 = x;
                y1 = y;
                code1 = computeCode(x1, y1);
            } else {
                x2 = x;
                y2 = y;
                code2 = computeCode(x2, y2);
            }
        }
    }

    // Draw the clipped line if accepted
    if (accept) {
        setcolor(RED);
        line(x1, y1, x2, y2);
    }
}

int main() {
    int gd = DETECT, gm;
    int x1, y1, x2, y2;

    // Initialize graphics mode
    initgraph(&gd, &gm, NULL);

    // Define the clipping window (change values as needed)
    x_min = 100; y_min = 100;
    x_max = 300; y_max = 300;

    // Get user input for the line segment
    printf("Enter the coordinates of the line (x1 y1 x2 y2): ");
    scanf("%d %d %d %d", &x1, &y1, &x2, &y2);

    // Draw the clipping rectangle
    setcolor(WHITE);
    rectangle(x_min, y_min, x_max, y_max);

    // Draw the original line in WHITE
    setcolor(WHITE);
    line(x1, y1, x2, y2);

    // Perform line clipping
    cohenSutherlandClip(x1, y1, x2, y2);

    // Wait for user input before closing
    getch();
    closegraph();

    return 0;
}
