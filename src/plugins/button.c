#include <stdio.h>
#include <raylib.h>
#include <stdbool.h>

bool clickButton(int x, int y, int width, int height)
{

    Vector2 mousePos = GetMousePosition();
    bool isClicked;
    
    for (int i = x; i < x + width; i++)
    {
        for(int j = y; j < y + height; j++)
        {
            if (mousePos.x == i && mousePos.y == j && IsMouseButtonPressed(0)) isClicked = true;
            
        }
    }
    
    return isClicked;
}