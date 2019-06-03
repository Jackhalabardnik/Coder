#ifndef MOCK_WINDOW_H
#define MOCK_WINDOW_H

#include <string>
#include "Coder/mainwindow.h"

class MockWindow : public MainWindow
{
public:
	void clickExitButton();
	void setDecodingMode();
	void setEncodingMode();
	
	void setEntryInputMode();
	
	void setFileInputMode();
	
	void setKeyText(std::string text);
	
	bool isErrorDialogOpened();

	std::string getErrorDialogText();

	std::string getKeyEntryLabelText();
	std::string getTextEntryLabelText();
	std::string getOutputEntryLabelText();
};

#endif