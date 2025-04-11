// A-Buffer Algorithm Implementation in C
// This program demonstrates the A-Buffer algorithm for handling transparency in 2D graphics.
// It allows drawing multiple transparent triangles and blends them correctly based on depth and alpha values.
// The program uses the graphics.h library for rendering graphics in C.


#include <graphics.h>
#include <stdio.h>
#include <stdlib.h>
#include <float.h>

#define WIDTH 640
#define HEIGHT 480
#define MAX_FRAGMENTS 10  // Max fragments per pixel

// Structure to store pixel fragments (depth, color, alpha)
typedef struct {
    float depth;
    int color;
    float alpha;  // Transparency
} Fragment;

// A-Buffer storing multiple fragments per pixel
Fragment ABuffer[WIDTH][HEIGHT][MAX_FRAGMENTS];
int fragmentCount[WIDTH][HEIGHT];

// Initialize A-Buffer (Clear screen)
void initializeABuffer() {
    for (int x = 0; x < WIDTH; x++) {
        for (int y = 0; y < HEIGHT; y++) {
            fragmentCount[x][y] = 0;  // No fragments initially
        }
    }
}

// Add a fragment to A-Buffer
void addFragment(int x, int y, float depth, int color, float alpha) {
    if (x < 0 || x >= WIDTH || y < 0 || y >= HEIGHT) return;
     
    int count = fragmentCount[x][y];

    // If space available, store new fragment
    if (count < MAX_FRAGMENTS) {
        ABuffer[x][y][count].depth = depth;
        ABuffer[x][y][count].color = color;
        ABuffer[x][y][count].alpha = alpha;
        fragmentCount[x][y]++;
    }
}

// Blend fragments to compute final color
int blendFragments(int x, int y) {
    float finalAlpha = 1.0;  // Start with full opacity
    int finalColor = BLACK;  // Background color
    
    // Sort fragments by depth (painter's algorithm)
    for (int i = 0; i < fragmentCount[x][y] - 1; i++) {
        for (int j = i + 1; j < fragmentCount[x][y]; j++) {
            if (ABuffer[x][y][i].depth > ABuffer[x][y][j].depth) {
                Fragment temp = ABuffer[x][y][i];
                ABuffer[x][y][i] = ABuffer[x][y][j];
                ABuffer[x][y][j] = temp;
            }
        }
    }

    // Blend using alpha compositing
    for (int i = 0; i < fragmentCount[x][y]; i++) {
        int color = ABuffer[x][y][i].color;
        float alpha = ABuffer[x][y][i].alpha;

        // Apply alpha blending formula: C_final = C1 * α1 + C2 * (1 - α1)
        finalColor = (color * alpha) + (finalColor * (1 - alpha));
        finalAlpha *= (1 - alpha);  // Reduce transparency
    }

    return finalColor;
}

// Render final image
void renderABuffer() {
    for (int x = 0; x < WIDTH; x++) {
        for (int y = 0; y < HEIGHT; y++) {
            if (fragmentCount[x][y] > 0) {
                int finalColor = blendFragments(x, y);
                putpixel(x, y, finalColor);
            }
        }
    }
}

// Draw a transparent triangle using A-Buffer
void drawTriangleABuffer(int x1, int y1, float z1, 
                         int x2, int y2, float z2, 
                         int x3, int y3, float z3, int color, float alpha) {
    line(x1, y1, x2, y2);
    line(x2, y2, x3, y3);
    line(x3, y3, x1, y1);
    
    for (int y = y1; y <= y3; y++) {
        for (int x = x1; x <= x3; x++) {
            float depth = (z1 + z2 + z3) / 3;  // Average depth
            addFragment(x, y, depth, color, alpha);
        }
    }
}

int main() {
    int gd = DETECT, gm;
    initgraph(&gd, &gm, NULL);  // Use appropriate graphics driver path

    initializeABuffer();

    int n;
    printf("Enter number of triangles: ");
    scanf("%d", &n);

    for (int i = 0; i < n; i++) {
        int x1, y1, z1, x2, y2, z2, x3, y3, z3, color;
        float alpha;

        printf("Enter x1 y1 z1: ");
        scanf("%d %d %d", &x1, &y1, &z1);
        printf("Enter x2 y2 z2: ");
        scanf("%d %d %d", &x2, &y2, &z2);
        printf("Enter x3 y3 z3: ");
        scanf("%d %d %d", &x3, &y3, &z3);
        printf("Enter color (1-15): ");
        scanf("%d", &color);
        printf("Enter transparency (0.0 - 1.0): ");
        scanf("%f", &alpha);

        drawTriangleABuffer(x1, y1, z1, x2, y2, z2, x3, y3, z3, color, alpha);
    }

    renderABuffer();
    
    printf("A-Buffer Applied. Press any key to exit.");
    getch();
    closegraph();
    
    return 0;
}