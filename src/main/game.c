#include <raylib.h>




// declarations

// fonts
Font gameFont;


// functions to load and unload our resources

void loadGameTextures()
{
    // textures

    // fonts
    gameFont = LoadFont("../assets/fonts/crimes_times_six/Crimes_Times_Six.ttf");

}
void unloadGameTextures()
{
}
void loadGameSounds()
{}
void unloadGameSounds()
{}

void gameUpdate()
{

}


void gameDraw()
{
    ClearBackground(BLACK); // clear our background
    DrawRectangle(0, GetScreenWidth() / 2, GetScreenWidth(), 200, WHITE );

    DrawText("this is written for debugging purposes", 10,10,30,WHITE);

}

