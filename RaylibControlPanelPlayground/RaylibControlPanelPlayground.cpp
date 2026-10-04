#include <iostream>
#include <raylib.h>
#include "KeyWidget.hpp"
#include <vector>
#include "TextBoxWidget.hpp"
#include <regex>
#include "WebBooter.hpp"
#include "WebSearchingWidget.hpp"

static bool isRun = 1;

int main()
{
    WebBooter webBooter;


    InitWindow(1080, 607.50, "Beargle");

    SetTargetFPS(60);

    std::vector<char> urlCharacters = {
        // Uppercase letters
        'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K', 'L', 'M',
        'N', 'O', 'P', 'Q', 'R', 'S', 'T', 'U', 'V', 'W', 'X', 'Y', 'Z',

        // Lowercase letters
        'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm',
        'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z',

        // Numbers
        '0', '1', '2', '3', '4', '5', '6', '7', '8', '9',

        // URL characters
        ':', '/', '.', '?', '=', '&', '#', '%',
        '+', '-', '_', '~', '@', '!',
        '$', '\'', '(', ')', '*', ',', ';'
    };

	std::vector<KeyWidget> keyWidgets;
	int padding = 10;
    int columnSize = 15;
    int sizeOfInputWidgets = 50;
	int sizeOfInputWidgetsWithPadding = sizeOfInputWidgets + 10;
    int textBoxWidgetPox = 100;
    TextBoxWidget textBoxWidget("", (15 * sizeOfInputWidgetsWithPadding - 9) - padding, 100 - padding / 2, (textBoxWidgetPox -1) + padding / 2, 20, padding, 30, 10);


    for (int i = 0; i < urlCharacters.size(); i++)
    {
        char letter = urlCharacters[i];
        int x = 100 + (i % columnSize) * sizeOfInputWidgetsWithPadding;
        int y = 140 + (i / columnSize) * sizeOfInputWidgetsWithPadding;

		//std::cout << std::string(1, letter).c_str() << std::endl;   
        KeyWidget keyWidget(x, y, sizeOfInputWidgets, sizeOfInputWidgets, std::string(1, letter).c_str(), BLUE, GREEN, PURPLE, 30);
		keyWidget.onClick([letter, &textBoxWidget]() { textBoxWidget.AddLetter(letter); });
		keyWidgets.push_back(keyWidget);
    }

    KeyWidget enterWidget(100, 140 + (37 / 6) * sizeOfInputWidgetsWithPadding, 110, 50, "Enter", BLUE, GREEN, PURPLE, 30);
    KeyWidget backspaceWidget(100 + (38 % 6) * sizeOfInputWidgetsWithPadding, 140 + (38 / 6) * sizeOfInputWidgetsWithPadding, 170, 50, "Backspace", BLUE, GREEN, PURPLE, 30);
    KeyWidget closeButtonWidget(100 + (41 % 6) * sizeOfInputWidgetsWithPadding, 140 + (41 / 6) * sizeOfInputWidgetsWithPadding, 110, 50, "ESC", BLUE, GREEN, PURPLE, 30);
    
	enterWidget.onClick([&textBoxWidget, &webBooter]() { webBooter.OpenBrowser(textBoxWidget.GetText()); });
	backspaceWidget.onClick([&textBoxWidget]() { textBoxWidget.RemoveLetter(); });
    closeButtonWidget.onClick([]() { isRun = 0; });
	
    
    keyWidgets.push_back(enterWidget);
    keyWidgets.push_back(backspaceWidget);
    keyWidgets.push_back(closeButtonWidget);

	WebSearchingWidget webSearchingWidget(100, 140, 10, 15, 50);

    while (!WindowShouldClose() && isRun)
    {
        //for (KeyWidget& keyWidget : keyWidgets)
        //{
        //    keyWidget.Update();
        //}

        //textBoxWidget.Update();
        webSearchingWidget.Update();
        BeginDrawing();


        //for (KeyWidget& keyWidget : keyWidgets)
        //{

        //    keyWidget.Draw();
        //}

        //textBoxWidget.Draw();
        webSearchingWidget.Draw();

        ClearBackground(RAYWHITE);
        EndDrawing();
    }

    CloseWindow();

}