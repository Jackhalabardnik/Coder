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

	Gtk::Button startButton, exitButton;

	Gtk::Label outputLabel, outputEntryLabel, codeEntryLabel, textEntryLabel, chooseInputLabel, choseWorkModeLabel;

	Gtk::RadioButton doEncoding, doDecription, readFromEntry, readFromFile;

	Gtk::Entry codeEntry, textEntry, outputEntry;

	Gtk::Grid mainGrid, chooseInputGrid, chooseMethodGrid;
};

#endif