#include "KeyWidget.hpp"
#include "raylib.h"
#include <iostream>


KeyWidget::KeyWidget(
    int x,
    int y,
    int width,
    int height,
    std::string text,
    Color normalColor,
    Color highlightedColor, 
    Color pressedColor,
	int fontSize
    ) 
    : 
    posX(x), 
    posY(y), 
    sizeX(width), 
    sizeY(height), 
    text(text), 
    normalColor(normalColor), 
    highlightedColor(highlightedColor), 
    pressedColor(pressedColor),
    keyColor(normalColor),
	fontSize(fontSize)

{

}

void KeyWidget::Draw()
{
    DrawRectangle(posX, posY, sizeX, sizeY, keyColor);

    int textWidth = MeasureText(text.c_str(), fontSize);

    DrawText(text.c_str(), (posX - textWidth / 2) + sizeX / 2, (posY - fontSize / 2) + sizeY / 2, fontSize, BLACK);
    DrawRectangleLines( posX,  posY,  sizeX, sizeY, BLACK);

}

void KeyWidget::Update()
{
	Rectangle keyWidgetRec{ (float)posX, (float)posY, (float)sizeX, (float)sizeY };
    Rectangle mouseRec{ (float)GetMouseX(), (float)GetMouseY(), 1, 1 };

    bool isMouseOn = CheckCollisionRecs(keyWidgetRec, mouseRec);

    if (isMouseOn) 
    {
        if (IsMouseButtonDown(MOUSE_LEFT_BUTTON)) {
            keyColor = pressedColor;
        }
        else
        {
            keyColor = highlightedColor;
        }

        if (IsMouseButtonPressed(MOUSE_LEFT_BUTTON))
        {
            click();
        }
    }
    else 
    {
		keyColor = normalColor;
    }

}

void KeyWidget::onClick(std::function<void()> listener) {
    listeners.push_back(listener);
}

void KeyWidget::click() {
    for (const auto& listener : listeners) {
        listener();
    }
}

