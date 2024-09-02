#include <stdio.h>
#include <raylib.h>
#include <stdbool.h>

Vector2 mousePos;
bool clickButton(int x, int y, int width, int height)

{
    mousePos = GetMousePosition();
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

bool hoverButton(int x, int y, int width, int height)
{
    mousePos = GetMousePosition();
    bool isHovered;
    for (int i = x; i < x + width; i++)
    {
        for(int j = y; j < y + height; j++)
        {
            if (mousePos.x == i && mousePos.y == j) isHovered = true;
            printf("x: %f, y: %f\n", mousePos.x, mousePos.y);   
        }
    }
    return isHovered;
}