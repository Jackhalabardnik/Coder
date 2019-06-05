#ifndef MOCK_WINDOW_H
#define MOCK_WINDOW_H

#include <string>
#include "Coder/mainwindow.h"

class MockWindow : public MainWindow
{
public:
	void clickExitButton();
	void clickStartButton();
	
	void doWork() override;
	
	void setDecodingMode();
	void setEncodingMode();
	
	void setEntryInputMode();
	void setFileInputMode();
	
	void writeToTextInput(std::string text);
	
	void writeToKeyEntry(std::string text);
	bool hasKeyEntryGoodText();
	
	void writeToTextEntry(std::string text);
	bool hasTextEntryGoodText();
	
	std::string getTextInputText();
	std::string getKeyInputText();

	std::string getKeyEntryLabelText();
	std::string getTextEntryLabelText();
	std::string getOutputEntryLabelText();
	
	std::string getMajorErrorMessage();
	std::string getMinorErrorMessage();
	
	bool isError();
};

#endif