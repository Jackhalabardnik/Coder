#include "mainwindow.h"

MainWindow::MainWindow() 
{
	setGUI();
}
void MainWindow::setGUI()
	{
		setChooseMethodGrid();
		setChooseInputGrid();
		setEntry();
		setOutInfo();

		setButtons();

		setMainGrid();
		fillMainGrid();

		setWindow();
	}

void MainWindow::setChooseInputGrid()
{
	chooseInputLabel.set_text("Choose input: ");

	readFromFile.set_label("readFromFile");
	readFromEntry.set_label("readFromEntry");
	
	readFromEntry.signal_toggled().connect(sigc::mem_fun(*this, &MainWindow::updateLabels));
	readFromFile.signal_toggled().connect(sigc::mem_fun(*this, &MainWindow::updateLabels));

	readFromFile.join_group(readFromEntry);
	readFromEntry.set_active();

	chooseInputGrid.set_row_spacing(3);

	chooseInputGrid.attach(chooseInputLabel, 0,0,1,1);
	chooseInputGrid.attach_next_to(readFromEntry, chooseInputLabel,Gtk::PositionType::POS_BOTTOM ,1,1);
	chooseInputGrid.attach_next_to(readFromFile, readFromEntry,Gtk::PositionType::POS_BOTTOM ,1,1);

}

void MainWindow::setChooseMethodGrid()
{
	choseWorkModeLabel.set_text("Choose work mode: ");

	doDecoding.set_label("Decoding");
	doEncoding.set_label("Encoding");

	doDecoding.signal_toggled().connect(sigc::mem_fun(*this, &MainWindow::updateLabels));
	doEncoding.signal_toggled().connect(sigc::mem_fun(*this, &MainWindow::updateLabels));

	doDecoding.join_group(doEncoding);
	doEncoding.set_active();

	chooseMethodGrid.set_row_spacing(3);

	chooseMethodGrid.attach(choseWorkModeLabel, 0,0,1,1);
	chooseMethodGrid.attach_next_to(doEncoding, choseWorkModeLabel,Gtk::PositionType::POS_BOTTOM ,1,1);
	chooseMethodGrid.attach_next_to(doDecoding, doEncoding,Gtk::PositionType::POS_BOTTOM ,1,1);
}

void MainWindow::setEntry()
{
	codeEntryLabel.set_text("Enter your public key:"); 
	textEntryLabel.set_text("Enter text to encode:");
	
		codeEntry.set_text("key");
		textEntry.set_text("text");
}

void MainWindow::setOutInfo()
{
	outputEntryLabel.set_text("Encoded text:");
	outputEntry.set_text("Nothing here");
	outputEntry.set_editable(false);
}

void MainWindow::setButtons()
{
	startButton.set_label("Go");
	exitButton.set_label("Exit");
}

void MainWindow::setMainGrid()
	{
		mainGrid.set_column_spacing(5);
		mainGrid.set_row_spacing(4);
		
		add(mainGrid);
	}

void MainWindow::fillMainGrid()
	{
		mainGrid.attach(codeEntryLabel, 3, 1,1,1);
		mainGrid.attach(codeEntry,1, 2, 4,1);
		mainGrid.attach(textEntryLabel,3,3, 1,1);
		mainGrid.attach(textEntry,1,4,4,1);

		mainGrid.attach(chooseMethodGrid,2,5,1,1);
		mainGrid.attach(chooseInputGrid,4, 5, 1, 1);

		mainGrid.attach(startButton, 2, 6, 3,1);

		mainGrid.attach(outputEntryLabel,2,7,3,1);
		mainGrid.attach(outputEntry,1, 8, 4,1);

		mainGrid.attach(exitButton, 2, 9, 4,1);
	}
	
void MainWindow::setWindow()
{
	set_border_width(10);
	set_resizable(false);
	set_title("Coder v1.0.1");
	show_all_children();
}

void MainWindow::updateLabels()
{
	std::string input_text = readFromEntry.get_active() ? "text" : "path to file";
	if(doEncoding.get_active())
	{
		codeEntryLabel.set_text("Enter your public key:"); 
		textEntryLabel.set_text(std::string("Enter " + input_text + " to encode:"));
		outputEntryLabel.set_text("Encoded text:");
	}
	else
	{
		codeEntryLabel.set_text("Enter your private key:"); 
		textEntryLabel.set_text(std::string("Enter " + input_text + " to decode:"));
		outputEntryLabel.set_text("Decoded text:");
	}
}