#include <MockWindow.h>

void MockWindow::clickExitButton()
	{
		exitButton.clicked();
	}
void MockWindow::setDecodingMode()
	{
		doDecoding.set_active();
	}
void MockWindow::setEncodingMode()
	{
		doEncoding.set_active();
	}
	
void MockWindow::setEntryInputMode()
	{
		readFromEntry.set_active();
	}
	
void MockWindow::setFileInputMode()
	{
		readFromFile.set_active();
	}

void MockWindow::setKeyText(std::string text)
	{
		keyEntry.set_text(text);
	}

bool MockWindow::isErrorDialogOpened()
	{
		return false;
	}

std::string MockWindow::getErrorDialogText()
	{
		return "";
	}

std::string MockWindow::getKeyEntryLabelText()
	{
		return keyEntryLabel.get_text();
	}
std::string MockWindow::getTextEntryLabelText()
	{
		return textEntryLabel.get_text();
	}
std::string MockWindow::getOutputEntryLabelText()
	{
		return outputEntryLabel.get_text();
	}