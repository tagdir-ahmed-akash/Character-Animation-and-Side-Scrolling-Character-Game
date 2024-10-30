#include <stdio.h>
#include <graphics.h>
#include "conio.h"
#include "EasyXPng.h"

#define WIDTH  640
#define HEIGHT 480

int dx, bg_x, speed;
int direction; // 1 for left to right, -1 for right to left
const int numImages = 4;

int main()
{
    IMAGE im_bk;
    initgraph(WIDTH, HEIGHT);

    int i = 0;
    TCHAR filename[20];
    IMAGE img_left[numImages];  // Images for left-facing
    IMAGE img_right[numImages]; // Images for right-facing

    // Load images for both directions
    for (i = 0; i < numImages; i++)
    {
        _stprintf_s(filename, _T("g%d.png"), i); // Load left-facing images
        loadimage(&img_left[i], filename);
        _stprintf_s(filename, _T("g%d.png"), i); // Load right-facing images
        loadimage(&img_right[i], filename);
    }

    loadimage(&im_bk, _T("bg.png"));

    dx = 0;       // Starting position for the girl
    bg_x = 0;     // Starting position for the background
    speed = 3;
    direction = 1; // Start moving from left to right
    BeginBatchDraw();

    while (1)
    {
        // Move background
        bg_x += speed * direction;

        // Check boundaries for background and change direction
        if (bg_x < -WIDTH) // If off screen to the left
        {
            bg_x = 0;       // Reset background position
        }
        else if (bg_x > 0) // If off screen to the right
        {
            bg_x = -WIDTH;  // Reset background position
        }

        // Draw the background
        putimage(bg_x, 0, &im_bk); // Draw the background image
        putimage(bg_x + WIDTH, 0, &im_bk); // Draw a second instance for seamless scrolling

        // Move the girl based on direction
        dx += speed * direction;

        // Check boundaries for the girl and change direction
        if (dx < -100) // If off screen to the left
        {
            dx = 0;                  // Reset position
            direction = 1;           // Change direction to right
        }
        else if (dx > WIDTH) // If off screen to the right
        {
            dx = WIDTH;              // Reset position
            direction = -1;          // Change direction to left
        }

        // Determine which images to use based on direction
        if (direction == -1)
        {
            putimagePng(dx, HEIGHT / 2, &img_left[i % numImages]); // Left-facing image
        }
        else
        {
            putimagePng(dx, HEIGHT / 2, &img_right[i % numImages]); // Right-facing image
        }

        Sleep(65);
        i++;

        FlushBatchDraw();
    }

    _getch();
    return 0;
}