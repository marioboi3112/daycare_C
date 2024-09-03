#include <stdio.h>
#include <raylib.h>

// structs (typedef structs or normal structs)
typedef struct
{
    float x, y, width, height;
} Button;

typedef struct 
{
    int x, y, z, w; // Vector4 (r, g, b, a values)
} ColorValues;


// definitions


// fonts

Font menuFont;

// texture declartations
Texture menuBackground;

// colors

Color menuTint = {255, 255, 255, 100}; // playing around with transparency

Color playCol = WHITE;
Color creditsCol = WHITE;
Color optionsCol = WHITE;
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
    .width = 21.5 * 4,
    .height = 21.5,
};
Button creditsButton = {
    .x = 200,
    .y = 500,
    .width = 21.5 * 7,
    .height = 21.5,
};

Button optionsButton =
{
    .x = 200,
    .y = 600,
    .width = 21.5 * 7,
    .height = 21.5
};

// wtf is going on
void menuUpdate()
{   
    UpdateMusicStream(backgroundMusic); // updates the music stream buffer with new data
    // check for mouse pressed and change gamestate according to that

}


void  menuDraw()
{

    // drawing the texts
    DrawTextEx(menuFont, "PLAY", (Vector2) {playButton.x, playButton.y}, 50, 1, playCol);
    DrawTextEx(menuFont, "CREDITS", (Vector2) {creditsButton.x, creditsButton.y}, 50, 1, creditsCol);
    
    DrawTextEx(menuFont, "OPTIONS", (Vector2) {optionsButton.x, optionsButton.y}, 50, 2, optionsCol);
    
    // check if the "buttons" are hovered over 
    if (hoverButton(playButton.x, playButton.y, playButton.width, playButton.height)) { playCol = RED;}
    else {playCol = WHITE;}
    
    if (hoverButton(creditsButton.x, creditsButton.y, creditsButton.width, creditsButton.height)) {creditsCol = RED;}
    else {creditsCol = WHITE;}

    if (hoverButton(optionsButton.x, optionsButton.y, optionsButton.width, optionsButton.height)) { optionsCol = RED;}
    else {optionsCol = WHITE;}
    
    ClearBackground(BLACK);
    
    DrawTexture(menuBackground,0,0,menuTint); // tint the menu background to be a bit darker
    

}   

void exitMenuState ()
{
    // this function gets called when gameState is set to one of those on the menu (when we cant to change the file to PLAY, credits and settings will still haev teh music going on )
    unloadAllMenuTextures();
    unloadMenuSounds();
    
}