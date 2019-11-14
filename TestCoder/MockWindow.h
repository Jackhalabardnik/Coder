#pragma once

#include <string>
#include "Coder/mainwindow.h"

class MockWindow : public MainWindow
{
public:
	void clickExitButton();
	void clickStartButton();
	
	bool isOpenChooseFileDialogVisible();
	bool isHelpLabelVisible();
	bool isOpenChooseOutcomeFileDialogVisible();
	
	void writeToFile(std::string path, std::string text);
	
	void showErrorDialog() override;
	
	void setDecodingMode();
	void setEncodingMode();
	
	void setEntryInputMode();
	void setFileInputMode();
	
	void setOutputToTextbox();
	void setOutputToFile();
	
	void setOneTimeCoding();
	void setRepetetiveCoding();
	
	void writeToTextInput(std::string text);
	
	void writeToKeyEntry(std::string text);
	bool hasKeyEntryGoodText();
	
	void writeToTextEntry(std::string text);
	bool hasTextEntryGoodText();
	
	void setPathLabelText(std::string text);
	
	std::string getTextInputText();
	std::string getKeyInputText();
	std::string getOutputTextboxText();

	std::string getTextEntryLabelText();
	
	std::string getMajorErrorMessage();
	std::string getMinorErrorMessage();
	
	bool isError();
};
