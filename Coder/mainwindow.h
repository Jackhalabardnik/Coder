#ifndef GTKMM_MAINWINDOW_H
#define GTKMM_MAINWINDOW_H

#include <gtkmm.h>
#include <string>
#include <memory>

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

	void updateLabels();
	
	void setErrorDialog();

	void pushedStartButton();
protected:

	Gtk::Button startButton, exitButton;

	Gtk::Label outputEntryLabel, keyEntryLabel, textEntryLabel, chooseInputLabel, choseWorkModeLabel;

	Gtk::RadioButton doEncoding, doDecoding, readFromEntry, readFromFile;

	Gtk::Entry keyEntry, textEntry, outputEntry;

	Gtk::Grid mainGrid, chooseInputGrid, chooseMethodGrid;

	std::unique_ptr<Gtk::MessageDialog> dialog;
};

#endif