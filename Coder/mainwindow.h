#pragma once

#include <gtkmm.h>
#include <string>
#include <memory>

#include <EntryInput.h>
#include <FileInput.h>
#include <CodingInterface.h>
#include <CaesarCoding.h>

class MainWindow : public Gtk::Window
{
public:
	MainWindow();

private:
	void setGUI();

	void setMainGrid();

	void setChooseInputGrid();

	void setChooseMethodGrid();

	void setChooseOutputGrid();
	
	void setChooseRepetetiveGrid();

	void setChooseCodeTypeGrid();

	void setEntry();

	void setInputInterferance();

	void setOutInfo();

	void setTextToTextBuffer(std::string text);

	void setButtons();

	void setPathLabel();

	void fillMainGrid();

	void setWindow();

	void showEverythingAtCreation();

	void updateCodingMethod();

	void updateInputMode();

	void updateInput();

	void updateWorkMode();

	void updateInputTextLabel();

	void updateOutcomeMode();

	void chooseSourceFileFromADialog();

	void chooseTextFileFromDialog();
 
	std::string askUserForNewFileName();
 
	virtual void showErrorDialog();

	void doWork();
protected:

	void writeToFile(std::string path, std::string text);

	void transferTextFromEntriesToInput();

	std::string getMajorErrorMessage();

	std::string getMinorErrorMessage();

	bool isError();


	Gtk::Button startButton, exitButton, openChooseSourceFileDialog, openChooseOutcomeFileDialog;

	Gtk::Label outputEntryLabel, keyEntryLabel, textEntryLabel, pathLabel;

	Gtk::RadioButton doEncoding, doDecoding, readFromEntry, readFromFile,
	writeToTextBox, writeToFileAndTextBox, codeOneTime, codeRepetetive,
	codeTypeRSA, codeTypeReplace;

	Gtk::Entry keyEntry, textEntry;

	Gtk::TextView outputTextView;

	Gtk::ScrolledWindow scrolledWindow;

	Gtk::Grid mainGrid, chooseInputGrid, chooseOutputGrid, chooseMethodGrid, chooseRepetetiveGrid, chooseCodeTypeGrid;

	std::shared_ptr<InputInterferance> textInput;

	EntryInput keyInput, textInputEntryMode;

	FileInput textInputFileMode;

	std::shared_ptr<CodingInterface> codingService;

	CaesarCoding cesearCoding;
	
	std::string previousText;
};
