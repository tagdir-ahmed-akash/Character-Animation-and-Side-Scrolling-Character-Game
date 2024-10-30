Practice 2: 
nstructions:
Controls:
Press 'A': Move the character from right to left (left-facing animation).
Press 'S': Move the character from left to right (right-facing animation).
Press 'D': Stop the character's movement.
Press 'Esc': Exit the game.
Requirements:
Compiler: Use a C++ compiler that supports the EasyX library (recommended: Visual Studio).
Libraries: Make sure graphics.h, EasyXPng.h, and windows.h are included in your project files.
File Descriptions:
Source Code: Contains the main game logic.
Image Files:
g0.png to g3.png: Left-facing animation images.
g4.png to g7.png: Right-facing animation images.
bg.png: Background image file.
Setup:
Place all images (g0.png to g7.png for character sprites and bg.png for the background) in the project directory.
Compile and run the program using Visual Studio or another C++ IDE compatible with EasyX.
Game Logic:
The program continuously monitors for key presses to control the character’s movement.
The character begins from either the left or right edge of the screen based on the selected direction and moves across until reaching the opposite edge.
If the D key is pressed, the character halts and remains stationary until A or S is pressed to move again.

Practice 1: 
Instructions:
Left-Right Movement: The character moves left-to-right and right-to-left, switching directions when it reaches the screen edges.
Seamless Background Scrolling: The background scrolls in a loop to provide a continuous effect, enhancing immersion.
Requirements:
Compiler: Ensure you have a C++ compiler that supports EasyX (Visual Studio is recommended).
Libraries: Include graphics.h, EasyXPng.h, and conio.h in the project files.
File Descriptions:
Source Code: Contains the main game logic.
Image Files:
g0.png, g1.png, g2.png, g3.png: Character images for animation (must be stored in the same directory as the code).
bg.png: Background image file for seamless scrolling.
Setup:
Place all images (g0.png to g3.png for character sprites and bg.png for the background) in the project's directory.
Compile and run the game using your IDE or a C++ compiler compatible with the EasyX library.
Controls:
The game runs automatically without user input, with the character moving autonomously across the screen.
