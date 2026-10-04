#pragma once
#include <string>
#include "raylib.h"
#include <functional>

class KeyWidget
{
	public:
		KeyWidget(int x, int y, int width, int height, std::string text, Color normalColor, Color highlightedColor, Color pressedColor, int fontSize);
		void Draw();
		void Update();
		void onClick(std::function<void()> listener);
		void click();

	private:
		int sizeX;
		int sizeY;
		int posX;
		int posY;
		std::string text;
		int fontSize;
		Color normalColor;
		Color highlightedColor;
		Color pressedColor;
		Color keyColor;
		std::vector<std::function<void()>> listeners;
};
