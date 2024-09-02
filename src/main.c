#include <raylib.h>
#include <stdio.h>
#include "main_functions.h"
#include <time.h> // including our time library;
#include "plugins/button.c"
#include "main/menu.c"

const int SCREEN_WIDTH = 1280;
const int SCREEN_HEIGHT = 720;
Sound nextdiag;


typedef enum {
	TITLE, 
	MENU, 
} mainState;
mainState main_state = TITLE;
// game functions


void titleScreen()
{

	char titleStrings[3][100] = 
	{
		"DayCare...",
		"Presented to you by...",
		"draze studios with love <3",
	};

	double timeElapsed = GetTime(); // elapsed time since InitWindow() in seconds

	if ((int)timeElapsed == 3)
	{
		DrawText(titleStrings[0], SCREEN_WIDTH / 2, SCREEN_HEIGHT / 2, 20, WHITE);
		// PlaySound(nextdiag);
	}

	if ((int)timeElapsed >= 5)
	{
		ClearBackground(BLACK);
		DrawText(titleStrings[1], SCREEN_WIDTH / 2, SCREEN_HEIGHT / 2, 20, WHITE);
	}
	if ((int)timeElapsed >= 7)
	{
		DrawText(titleStrings[2], SCREEN_WIDTH / 2 + 10, SCREEN_HEIGHT / 2 - 30, 20, WHITE);
		if ((int) timeElapsed >= 9)
			main_state = 1; // 1 refers to MENU
	}


}



int main()
{
	

	InitAudioDevice();	
	InitWindow(SCREEN_WIDTH, SCREEN_HEIGHT, "DayCare");
	nextdiag = LoadSound("../assets/audio/sounds/chase/chase-1.wav");
	
	if (gameState == SELF)
	{
		loadMenuTextures();
		loadMenuSounds();
	}
	while (!WindowShouldClose())
	{
			// update function
			switch(main_state)
			{
				case (1):

					// StopSound(nextdiag);
					menuUpdate();
					break;
			} 
			BeginDrawing();

			// BeginMode2D(camera);
			ClearBackground(BLACK);

			if (main_state == TITLE)
				titleScreen();
			if (main_state == 1)
			{
				menuDraw();
			}
			//if (clickButton(10,10,100,20)) puts("clicked!");
			

			EndDrawing();
			
	}
	
	unloadAllMenuTextures();
	unloadMenuSounds();
	CloseAudioDevice();
	CloseWindow();
	return 0;

}
// all of the code from other files is called from here!

