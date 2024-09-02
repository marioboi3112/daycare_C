#include <stdio.h>
#include <raylib.h>

// structs (typedef structs or normal structs)
typedef struct
{
    float x, y, width, height;
} Button;





// definitions


// fonts

Font menuFont;

// texture declartations
Texture menuBackground;

// colors

Color menuTint = {255, 255, 255, 100}; // playing around with transparency
Color hoveredColor = {255,255,255,255};

// sound and music declarations 
Music backgroundMusic;



typedef enum {
    PLAY,
    OPTIONS, 
    CREDITS, 
    SELF,

} GameState;
GameState gameState = SELF; // default gameState (self refers to its own class (menu.c))
void unloadAllMenuTextures()
{
    // textures

    UnloadTexture(menuBackground);

    // fonts
    UnloadFont(menuFont);
}


void loadMenuSounds()
{
    backgroundMusic = LoadMusicStream("../assets/audio/sounds/ambience/background_ambience.mp3");
    PlayMusicStream(backgroundMusic);
}
void unloadMenuSounds()
{
    UnloadMusicStream(backgroundMusic);
} 

void loadMenuTextures()
{
    menuBackground = LoadTexture("../assets/thumbnail/thumbnail_1_resized.png");
    // fonts
    menuFont = LoadFont("../assets/fonts/crimes_times_six/Crimes_Times_Six.ttf");    
}
Button playButton = {
    .x = 200, 
    .y = 400,
    .width = 85,
    .height = 50,
};
Button creditsButton = {
    .x = 200,
    .y = 500,
    .width = 21.5  * 7,
    .height = 50,
};



void menuUpdate()
{   
    UpdateMusicStream(backgroundMusic); // updates the music stream buffer with new data
    // check for mouse pressed and change gamestate according to that

}


void  menuDraw()
{

    // drawing the texts
    DrawTextEx(menuFont, "PLAY", (Vector2) {playButton.x, playButton.y}, 50, 2, hoveredColor);
    DrawTextEx(menuFont, "CREDITS", (Vector2) {creditsButton.x, creditsButton.y}, 50, 1, hoveredColor);
    // DrawTextEx(menuFont, "PLAY", (Vector2) {playButton.x, playButton.y}, 50, 2, WHITE);
    if (hoverButton(playButton.x, playButton.y, playButton.width, playButton.height));
    ClearBackground(BLACK);
    
    DrawTexture(menuBackground,0,0,menuTint); // tint the menu background to be a bit darker
    

}   

void exitMenuState ()
{
    // this function gets called when gameState is set to one of those on the menu
    unloadAllMenuTextures();
    unloadMenuSounds();
    
}