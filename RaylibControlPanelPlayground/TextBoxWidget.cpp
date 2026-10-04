#include "TextBoxWidget.hpp"
#include "raylib.h"
#include <iostream>

TextBoxWidget::TextBoxWidget(
	std::string text,
	int sizeX,
	int sizeY,
	int posX,
	int posY,
	int padding,
	int fontSize,
	int textPadding
	) 
	: 
	text(text),
	sizeX(sizeX),
	sizeY(sizeY),
	posX(posX),
	posY(posY),
	padding(padding),
	fontSize(fontSize),
	textPadding(textPadding)
{

}

void TextBoxWidget::Draw()
{
	DrawRectangle(posX - padding / 2, posY - padding / 2, sizeX + padding, sizeY + padding, BLUE);
	DrawRectangle(posX, posY, sizeX, sizeY, LIGHTGRAY);

	int textWidth = MeasureText(text.c_str(), fontSize);

	//DrawText(text.c_str(), (posX - textWidth / 2) + sizeX / 2 , (posY - fontSize / 2) + sizeY / 2, fontSize, BLACK);
	DrawText(text.c_str(), posX + textPadding/2 , (posY - fontSize / 2) + sizeY / 2, fontSize, BLACK);

}

void TextBoxWidget::Update()
{

}

void TextBoxWidget::AddLetter(char letter) {

	std::string test = text + letter;

    if (MeasureText(test.c_str(), fontSize) <= sizeX - textPadding/2)
	{
        text.push_back(letter);
	}
}

void TextBoxWidget::RemoveLetter() {
	if (text.length() != 0) 
	{
		text.pop_back();
	}
}

std::string TextBoxWidget::GetText() {
	return text;
}