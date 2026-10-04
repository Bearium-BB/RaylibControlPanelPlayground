#include <vector>
#include "KeyWidget.hpp"
#include "TextBoxWidget.hpp"
#include "WebBooter.hpp"

class WebSearchingWidget
{
	public:
		WebSearchingWidget(int posX, int posY, int keyPadding, int columnSize, int keyWidgetSize);
		void Draw();
		void Update();

	private:
		int posX;	
		int posY;
		int keyPadding;
		int columnSize;
		int keyWidgetSize;
		std::vector<KeyWidget> keyWidgets;
		TextBoxWidget textBoxWidget;
		WebBooter webBooter{};
};

