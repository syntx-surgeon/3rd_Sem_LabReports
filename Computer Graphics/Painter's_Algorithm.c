// C program to demonstrate the Painter's Algorithm for 2D object rendering
// using the graphics.h library.
// This program sorts the objects based on their depth (z-value) and draws them in the correct order.
// The program uses a simple bubble sort to sort the objects by depth and then draws them from farthest to nearest.
// The objects are represented as rectangles with specified coordinates, depth, and color.
// The program uses the graphics.h library for rendering the objects on the screen.
// The user is prompted to enter the number of objects and their properties (coordinates, depth, and color).
// The program then sorts the objects based on depth and draws them in the correct order using the Painter's Algorithm.
// also known as the "depth sorting" algorithm, is a technique used in computer graphics to render overlapping objects correctly by drawing them in the correct order based on their depth (z-value).
// It is commonly used in 2D and 3D graphics to ensure that objects closer to the viewer are drawn on top of those that are farther away.

#include <graphics.h>
#include <stdio.h>
#include <stdlib.h>

#define MAX_OBJECTS 10  
/*
INPUT TO BE GIVEN.....
Enter number of objects: 3

Enter x1, y1, x2, y2, depth (z), and color for object 1: 
100 100 200 200 2 4

Enter x1, y1, x2, y2, depth (z), and color for object 2: 
120 120 250 250 5 2

Enter x1, y1, x2, y2, depth (z), and color for object 3: 
140 140 300 300 1 14
*/

typedef struct {
    int x1, y1, x2, y2, z; 
    int color;             
} Object;

Object objects[MAX_OBJECTS];
int n; 

void swap(Object *a, Object *b) {
    Object temp = *a;
    *a = *b;
    *b = temp;
}

// Sort objects by depth (Descending order)
void sortObjectsByDepth() {
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (objects[j].z < objects[j + 1].z) {
                swap(&objects[j], &objects[j + 1]);
            }
        }
    }
}

// Draw objects from farthest to nearest
void drawObjects() {
    for (int i = 0; i < n; i++) {
        setcolor(objects[i].color);
        rectangle(objects[i].x1, objects[i].y1, objects[i].x2, objects[i].y2);
        floodfill((objects[i].x1 + objects[i].x2) / 2, (objects[i].y1 + objects[i].y2) / 2, objects[i].color);
    }
}

int main() {
    int gd = DETECT, gm;
    initgraph(&gd, &gm, NULL);

    printf("Enter number of objects (max %d): ", MAX_OBJECTS);
    scanf("%d", &n);

    for (int i = 0; i < n; i++) {
        printf("Enter x1, y1, x2, y2, depth (z), and color for object %d: ", i + 1);
        scanf("%d %d %d %d %d %d", &objects[i].x1, &objects[i].y1, &objects[i].x2, &objects[i].y2, &objects[i].z, &objects[i].color);
    }

    sortObjectsByDepth(); // Sort objects by depth
    drawObjects();        // Draw objects using Painter’s Algorithm

    printf("Painter's Algorithm Applied. Press any key to exit.");
    getch();
    closegraph();

    return 0;
}