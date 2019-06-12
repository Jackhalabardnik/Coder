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

	void setEntry();

	void setInputInterferance();

	void setOutInfo();

	void setTextToTextBuffer(std::string text);

	void setButtons();

	void fillMainGrid();

	void setWindow();

	void showEverythingAtCreation();

	void updateInputMode();

	void updateInput();

	void updateWorkMode();

	void updateInputTextLabel();

	void chooseSourceFileFromADialog();

	virtual void showErrorDialog();

	void doWork();
protected:
	void transferTextFromEntriesToInput();

	std::string getMajorErrorMessage();

	std::string getMinorErrorMessage();

	bool isError();


	Gtk::Button startButton, exitButton, openChooseSourceFileDialog;

	Gtk::Label outputEntryLabel, keyEntryLabel, textEntryLabel, chooseInputLabel, choseWorkModeLabel;

	Gtk::RadioButton doEncoding, doDecoding, readFromEntry, readFromFile;

	Gtk::Entry keyEntry, textEntry;

	Gtk::TextView outputTextView;

	Gtk::ScrolledWindow scrolledWindow;

	Gtk::Grid mainGrid, chooseInputGrid, chooseMethodGrid;

	std::shared_ptr<InputInterferance> textInput;

	EntryInput keyInput, textInputEntryMode;

	FileInput textInputFileMode;

	CodingService codingService;
};

#endif