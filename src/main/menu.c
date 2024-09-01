#include <stdio.h>
#include <raylib.h>


// definitions



// texture declartations
Texture playButton;

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
    UnloadTexture(playButton);

}


void loadMenuSounds()
{
    backgroundMusic = LoadMusicStream("../assets/sounds/ambience/background_ambience.ogg");
}
void unloadMenuSounds()
{
    UnloadMusicStream(backgroundMusic);
} 

void loadMenuTextures()
{
    playButton = LoadTexture("../assets/graphics/ui/buttons/play.png");
    
}


Color colTest = {255, 255, 255, 100};
void menuUpdate()
{   
    PlayMusicStream(backgroundMusic);
    UpdateMusicStream(backgroundMusic);
    // check for mouse pressed and change gamestate according to that

}
void  menuDraw()
{

    ClearBackground(BLACK);
    DrawRectangle(10,100,500,500, colTest);
    
    DrawTexture(playButton, 450,300,RAYWHITE);
    

}