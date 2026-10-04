#pragma once
#include <string>

class TextBoxWidget
{
	public:
		TextBoxWidget(std::string text, int sizeX, int sizeY, int posX, int posY, int padding, int fontSize, int textPadding);
		void Draw();
		void Update();
		void AddLetter(char letter);
		void RemoveLetter();
		std::string GetText();

	private:
		int sizeX;
		int sizeY;
		int posX;
		int posY;
		int padding;
		int fontSize;
		int textPadding;
		std::string text;


};
