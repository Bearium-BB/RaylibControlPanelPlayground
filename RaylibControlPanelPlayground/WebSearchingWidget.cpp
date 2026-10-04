#include "WebSearchingWidget.hpp"
extern int isRun;

void WebSearchingWidget::Draw() 
{
    for (KeyWidget& keyWidget : keyWidgets)
    {

        keyWidget.Draw();
    }

    textBoxWidget.Draw();
}

void WebSearchingWidget::Update() 
{
    for (KeyWidget& keyWidget : keyWidgets)
    {
        keyWidget.Update();
    }

    textBoxWidget.Update();
}



WebSearchingWidget::WebSearchingWidget(int posX, int posY, int keyPadding, int columnSize, int keyWidgetSize) : posX(posX), posY(posY), keyPadding(keyPadding), columnSize(columnSize), keyWidgetSize(keyWidgetSize), textBoxWidget("", (columnSize* (keyWidgetSize + keyPadding) - 9) - 10, 100 - 10 / 2, (posX - 1) + 10 / 2, 20, 10, 30, 10)
{
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

    for (int i = 0; i < urlCharacters.size(); i++)
    {
        char letter = urlCharacters[i];
        int x = 100 + (i % columnSize) * (keyWidgetSize + keyPadding);
        int y = 140 + (i / columnSize) * (keyWidgetSize + keyPadding);

        //std::cout << std::string(1, letter).c_str() << std::endl;   
        KeyWidget keyWidget(x, y, keyWidgetSize, keyWidgetSize, std::string(1, letter).c_str(), BLUE, GREEN, PURPLE, 30);
        keyWidget.onClick([letter, this]() { textBoxWidget.AddLetter(letter); });
        keyWidgets.push_back(keyWidget);
    }

    KeyWidget enterWidget(100, 140 + (37 / 6) * keyWidgetSize + keyPadding, 110, 50, "Enter", BLUE, GREEN, PURPLE, 30);
    KeyWidget backspaceWidget(100 + (38 % 6) * keyWidgetSize + keyPadding, 140 + (38 / 6) * keyWidgetSize + keyPadding, 170, 50, "Backspace", BLUE, GREEN, PURPLE, 30);
    KeyWidget closeButtonWidget(100 + (41 % 6) * keyWidgetSize + keyPadding, 140 + (41 / 6) * keyWidgetSize + keyPadding, 110, 50, "ESC", BLUE, GREEN, PURPLE, 30);

    enterWidget.onClick([this]() { webBooter.OpenBrowser(textBoxWidget.GetText()); });
    backspaceWidget.onClick([this]() { textBoxWidget.RemoveLetter(); });
    closeButtonWidget.onClick([]() { isRun = 0; });


    keyWidgets.push_back(enterWidget);
    keyWidgets.push_back(backspaceWidget);
    keyWidgets.push_back(closeButtonWidget);
}