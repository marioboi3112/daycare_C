#include <raylib.h>
#include <stdio.h>
#include "plugins/button.c"
#include "main/menu.c"

const int SCREEN_WIDTH = 1280;
const int SCREEN_HEIGHT = 720;
Sound nextdiag;


typedef enum {
	TITLE, 
	MENU,
	PLAY_MAIN,
	OPTIONS_MAIN,
	CREDITS_MAIN,
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
		PlaySound(nextdiag);
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
			main_state = MENU; // 1 refers to MENU
	}


}



int main()
{
	

	InitAudioDevice();	
	InitWindow(SCREEN_WIDTH, SCREEN_HEIGHT, "DayCare");
	nextdiag = LoadSound("../assets/audio/sounds/216766__panzen__59_vhs_casette_in.wav");

	if (gameState == SELF)
	{
		loadMenuTextures();
		loadMenuSounds();
	}
	
	
	if (gameState == PLAY)
	{
		main_state = PLAY_MAIN;
	}

	if (main_state == PLAY_MAIN)
	{
		loadGameSounds();
		loadGameTextures();
		
	}

	while (!WindowShouldClose())
	{
			// update function
			switch(main_state)
			{
				case (1):

					StopSound(nextdiag);
					menuUpdate();
					break;
			} 
			if (main_state == PLAY_MAIN) gameUpdate();

			BeginDrawing();

			// BeginMode2D(camera);
			ClearBackground(BLACK);

			if (main_state == TITLE)
				titleScreen();
			if (main_state == MENU)
			{
				menuDraw();
			}
			if (main_state == PLAY_MAIN) {ClearBackground(BLACK); gameDraw();}
			//if (clickButton(10,10,100,20)) puts("clicked!");
			

			EndDrawing();
			printf("main_state: %d\n", main_state);
	}

	unloadAllMenuTextures();
	unloadMenuSounds();
	unloadGameSounds();
	unloadGameTextures();
	CloseAudioDevice();
	CloseWindow();
	return 0;

}
// all of the code from other files is called from here!

