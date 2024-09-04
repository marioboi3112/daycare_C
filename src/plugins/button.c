#include <stdio.h>
#include <raylib.h>
#include <stdbool.h>




Vector2 mousePos;
Vector2 mouse_pos_clicked;
 // the type of variable it is a vector2 (x, y)
bool clickButton(int x, int y, int width, int height)

{
    mousePos = GetMousePosition();
    bool isClicked;
    
    for (int i = x; i < x + width; i++)
    {
        for(int j = y; j < y + height; j++)
        {
            if ((mousePos.x == i && mousePos.y == j) && IsMouseButtonPressed(0)) isClicked = true;
            
        }
    }
    
    return isClicked;
}

bool hoverButton(int x, int y, int width, int height) // int func() 0 or 1 (false or true respectively)
{
    mouse_pos_clicked = GetMousePosition(); // raylib function ()x, y
    bool isHovered; 
    for (int i = x; i < x + width; i++) // 10,11,12 .. 42
    {
        for(int j = y; j < y + height; j++) // 10,11,12 .. 42
        {
            if (mouse_pos_clicked.x == i && mouse_pos_clicked.y == j) isHovered = true;
            // printf("x: %f, y: %f\n", mousePos.x, mousePos.y);
        }
    }
    return isHovered;
}