#include <MockWindow.h>

void MockWindow::clickExitButton()
	{
		exitButton.clicked();
	}

void MockWindow::clickStartButton()
	{
		startButton.clicked();
	}
	
bool MockWindow::isOpenChooseFileDialogVisible()
	{
		return openChooseSourceFileDialog.get_visible();
	}
	
bool MockWindow::isHelpLabelVisible()
	{
		return pathLabel.get_visible();
	}
	
bool MockWindow::isOpenChooseOutcomeFileDialogVisible()
	{
		return openChooseOutcomeFileDialog.get_visible();
	}
	
void MockWindow::writeToFile(std::string path, std::string text)
	{
		MainWindow::writeToFile(path, text);
	}


void MockWindow::showErrorDialog() {}

void MockWindow::setDecodingMode()
	{
		doDecoding.set_active();
	}

void MockWindow::setEncodingMode()
	{
		doEncoding.set_active();
	}
	
void MockWindow::setOutputToTextbox()
	{
		writeToTextBox.set_active();
	}

void MockWindow::setOutputToFile()
	{
		writeToFileAndTextBox.set_active();
	}
	
void MockWindow::setEntryInputMode()
	{
		readFromEntry.set_active();
	}
	
void MockWindow::setFileInputMode()
	{
		readFromFile.set_active();
	}
	
void MockWindow::setOneTimeCoding()
	{
		codeOneTime.set_active();
	}
void MockWindow::setRepetetiveCoding()
	{
		codeRepetetive.set_active();
	}
	
void MockWindow::writeToTextInput(std::string text)
	{
		textInput->setText(text);
	}
	
void MockWindow::writeToKeyEntry(std::string text)
	{
		keyEntry.set_text(text);
	}
	
bool MockWindow::hasKeyEntryGoodText()
	{
		return keyInput.isInputGood();
	}

void MockWindow::writeToTextEntry(std::string text)
	{
		textEntry.set_text(text);
	}
	
bool MockWindow::hasTextEntryGoodText()
	{
		return textInput->isInputGood();
	}
	
std::string MockWindow::getTextInputText()
	{
		return textInput->getText();
	}

std::string MockWindow::getKeyInputText()
	{
		return keyInput.getText();
	}

std::string MockWindow::getOutputEntryText()
	{
		return outputTextView.get_buffer()->get_text();
	}

std::string MockWindow::getTextEntryLabelText()
	{
		return textEntryLabel.get_text();
	}
	
std::string MockWindow::getMajorErrorMessage()
	{
		return MainWindow::getMajorErrorMessage();
	}

std::string MockWindow::getMinorErrorMessage()
	{
		return MainWindow::getMinorErrorMessage();
	}
	
bool MockWindow::isError()
	{
		return MainWindow::isError();
	}
	
void MockWindow::setPathLabelText(std::string text)
{
	pathLabel.set_text(text);
}
