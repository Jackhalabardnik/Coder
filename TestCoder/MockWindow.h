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

	std::string getKeyEntryLabelText();
	std::string getTextEntryLabelText();
	std::string getOutputEntryLabelText();
};

#endif