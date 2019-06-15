#ifndef GTKMM_MAINWINDOW_H
#define GTKMM_MAINWINDOW_H

#include <gtkmm.h>
#include <string>
#include <memory>
#include <InputInterferance.h>
#include <EntryInput.h>
#include <FileInput.h>
#include <CodingService.h>

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

	void setEntry();

	void setInputInterferance();

	void setOutInfo();

	void setTextToTextBuffer(std::string text);

	void setButtons();

	void setHelpLabel();

	void fillMainGrid();

	void setWindow();

	void showEverythingAtCreation();

	void updateInputMode();

	void updateInput();

	void updateWorkMode();

	void updateInputTextLabel();

	void updateHelpLabel();

	void chooseSourceFileFromADialog();

 std::string askUserForPathToOutputFile();

	virtual void showErrorDialog();

	void doWork();
protected:

	void writeToFile(std::string path, std::string text);

	void transferTextFromEntriesToInput();

	std::string getMajorErrorMessage();

	std::string getMinorErrorMessage();

	bool isError();


	Gtk::Button startButton, exitButton, openChooseSourceFileDialog;

	Gtk::Label outputEntryLabel, keyEntryLabel, textEntryLabel, helpLabel;

	Gtk::RadioButton doEncoding, doDecoding, readFromEntry, readFromFile, writeToTextBox, writeToFileAndTextBox;

	Gtk::Entry keyEntry, textEntry;

	Gtk::TextView outputTextView;

	Gtk::ScrolledWindow scrolledWindow;

	Gtk::Grid mainGrid, chooseInputGrid, chooseOutputGrid, chooseMethodGrid;

	std::shared_ptr<InputInterferance> textInput;

	EntryInput keyInput, textInputEntryMode;

	FileInput textInputFileMode;

	CodingService codingService;
};

#endif