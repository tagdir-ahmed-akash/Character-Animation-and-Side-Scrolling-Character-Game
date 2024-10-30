
//2021521460115
//MD AKASH HOSSAIN

#include <stdio.h>
#include <graphics.h>
#include <windows.h> 
#include "EasyXPng.h"

#define WIDTH  640
#define HEIGHT 480

int main()
{
    IMAGE im_bk, img[8];
    initgraph(WIDTH, HEIGHT);

    int i = 0;         
    int x = WIDTH / 2; 
    int y = HEIGHT / 2; 
    int direction = 0;  
    int isMoving = 0;   

    TCHAR filename[20];

    // Load images
    for (i = 0; i < 8; i++)
    {
        _stprintf_s(filename, _T("g%d.png"), i);
        loadimage(&img[i], filename);
    }

    loadimage(&im_bk, _T("bg.png"));

    i = 0;
    BeginBatchDraw();
    while (1)
    {
        // Draw the background
        putimage(0, 0, &im_bk);

        // Display the girl in the initial position if not moving
        if (!isMoving)
        {
            putimagePng(x, y, &img[i % 4]); // Display initial image (g0.png to g3.png)
        }

        // Check keyboard state using WinAPI for single press
        if ((GetAsyncKeyState('A') & 0x8000) && direction != -1) // 'A' key single press
        {
            direction = -1; // Set direction to left
            isMoving = 1;   // Start moving
            x = WIDTH - 50; // Start from the right side
            i = 0;          // Reset animation index
            Sleep(100);     // Delay to prevent rapid toggling
        }
        else if ((GetAsyncKeyState('S') & 0x8000) && direction != 1) // 'S' key single press
        {
            direction = 1;  // Set direction to right
            isMoving = 1;   // Start moving
            x = 0;          // Start from the left side
            i = 0;          // Reset animation index
            Sleep(100);     // Delay to prevent rapid toggling
        }
        else if (GetAsyncKeyState('D') & 0x8000) // 'D' key single press
        {
            isMoving = 0; // Stop moving and hold position
            direction = 0; // Reset direction
            Sleep(100);    // Delay to prevent rapid toggling
        }

        // Exit on ESC key
        if (GetAsyncKeyState(VK_ESCAPE) & 0x8000)
        {
            break;
        }

        // Show the girl based on the direction
        if (direction == 1) // Moving right
        {
            putimagePng(x, y, &img[4 + (i % 4)]); // Use g4.png to g7.png
        }
        else if (direction == -1) // Moving left
        {
            putimagePng(x, y, &img[i % 4]); // Use g0.png to g3.png
        }

        // Update the animation index for smooth movement
        if (isMoving)
        {
            i++;
            if (i >= 4) i = 0; // Reset index to loop within the current direction's images

            // Update the position of the girl
            x += direction * 5; // Move 5 pixels per frame

            // Stop movement if reaching the screen edges
            if (x >= WIDTH - 50 && direction == 1) // Right edge for right movement
            {
                x = WIDTH - 50; // Stop at the screen's right side
                isMoving = 0;   // Stop movement
                direction = 0;  // Reset direction
            }
            else if (x <= 0 && direction == -1) // Left edge for left movement
            {
                x = 0;         // Stop at the screen's left side
                isMoving = 0;  // Stop movement
                direction = 0; // Reset direction
            }
        }

        Sleep(65); // Delay for smoother animation
        FlushBatchDraw();
    }

    closegraph(); // Close the graphics window
    return 0;
}
