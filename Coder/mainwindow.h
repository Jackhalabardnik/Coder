#ifndef GTKMM_MAINWINDOW_H
#define GTKMM_MAINWINDOW_H

#include <gtkmm.h>

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

	void setOutInfo();

	void setButtons();

	void fillMainGrid();

	void setWindow();

	void changeLabelsToDecodingMode();
	void changeLabelsToEncodingMode();
	
	void changeLabelsToFileInputMode();
	void changeLabelsToEntryInputMode();
protected:

	Gtk::Button startButton, exitButton;

	Gtk::Label outputEntryLabel, codeEntryLabel, textEntryLabel, chooseInputLabel, choseWorkModeLabel;

	Gtk::RadioButton doEncoding, doDecoding, readFromEntry, readFromFile;

	Gtk::Entry codeEntry, textEntry, outputEntry;

	Gtk::Grid mainGrid, chooseInputGrid, chooseMethodGrid;
};

#endif