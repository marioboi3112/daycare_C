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
    mouse_pos_clicked = GetMousePosition();
    return (mouse_pos_clicked.x > x && mouse_pos_clicked.x < x + width)
           && (mouse_pos_clicked.y > y && mouse_pos_clicked.y < y + height);
}
