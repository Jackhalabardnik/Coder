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
		setInputInterferance();
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
	
	readFromEntry.signal_toggled().connect(sigc::mem_fun(*this, &MainWindow::updateInputMode));
	readFromFile.signal_toggled().connect(sigc::mem_fun(*this, &MainWindow::updateInputMode));

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

	doDecoding.signal_toggled().connect(sigc::mem_fun(*this, &MainWindow::updateWorkMode));
	doEncoding.signal_toggled().connect(sigc::mem_fun(*this, &MainWindow::updateWorkMode));

	doDecoding.join_group(doEncoding);
	doEncoding.set_active();

	chooseMethodGrid.set_row_spacing(3);

	chooseMethodGrid.attach(choseWorkModeLabel, 0,0,1,1);
	chooseMethodGrid.attach_next_to(doEncoding, choseWorkModeLabel,Gtk::PositionType::POS_BOTTOM ,1,1);
	chooseMethodGrid.attach_next_to(doDecoding, doEncoding,Gtk::PositionType::POS_BOTTOM ,1,1);
}

void MainWindow::setEntry()
{
	keyEntryLabel.set_text("Enter your key:"); 
	textEntryLabel.set_text("Enter text to encode:");
	
	keyEntry.set_text("key");
	textEntry.set_text("text");
}

void MainWindow::setInputInterferance()
{
	textInput = std::make_shared<EntryInput>();
	keyInput.setText(keyEntry.get_text());
	textInput->setText(textEntry.get_text());
}

void MainWindow::setOutInfo()
{
	outputEntryLabel.set_text("Encoded text:");
	setTextToTextBuffer("Nothing here");
	outputTextView.set_editable(false);
	scrolledWindow.add(outputTextView);
	scrolledWindow.set_size_request(300,100);
	scrolledWindow.set_policy(Gtk::POLICY_AUTOMATIC, Gtk::POLICY_AUTOMATIC);
}

void MainWindow::setTextToTextBuffer(std::string text)
{
	Glib::RefPtr<Gtk::TextBuffer> textBuffer = Gtk::TextBuffer::create();
	textBuffer->set_text(text);
	outputTextView.set_buffer(textBuffer);
}

void MainWindow::setButtons()
{
	startButton.set_label("Go");
	startButton.signal_clicked().connect(sigc::mem_fun(*this,&MainWindow::doWork));
	exitButton.set_label("Exit");
	exitButton.signal_clicked().connect(sigc::mem_fun(*this,&MainWindow::close));
	openChooseFileDialog.set_label("...");
	openChooseFileDialog.signal_clicked().connect(sigc::mem_fun(*this,&MainWindow::chooseFileFromADialog));
}

void MainWindow::setMainGrid()
{
		mainGrid.set_column_spacing(5);
		mainGrid.set_row_spacing(4);
		
		add(mainGrid);
}

void MainWindow::fillMainGrid()
{
		mainGrid.attach(keyEntryLabel, 3, 1,1,1);
		mainGrid.attach(keyEntry,1, 2, 4,1);
		mainGrid.attach(textEntryLabel,3,3, 1,1);
		mainGrid.attach(textEntry,1,4,4,1);
		mainGrid.attach(openChooseFileDialog, 5,4,1,1);

		mainGrid.attach(chooseMethodGrid,2,5,1,1);
		mainGrid.attach(chooseInputGrid,4, 5, 1, 1);

		mainGrid.attach(startButton, 2, 6, 4,1);

		mainGrid.attach(outputEntryLabel,3,7,1,1);
		mainGrid.attach(scrolledWindow,2, 8, 5,3);

		mainGrid.attach(exitButton, 2, 12, 4,1);
}

void MainWindow::setWindow()
{
	set_border_width(10);
	set_size_request(300,400);
	set_resizable(false);
	set_title("Coder v1.1.2");
	show_all_children();
}

void MainWindow::updateLabels()
{
	std::string input_text = readFromEntry.get_active() ? "text" : "non-relative path to file";
	if(doEncoding.get_active())
	{
		textEntryLabel.set_text(std::string("Enter " + input_text + " to encode:"));
		outputEntryLabel.set_text("Encoded text:");
	}
	else
	{
		textEntryLabel.set_text(std::string("Enter " + input_text + " to decode:"));
		outputEntryLabel.set_text("Decoded text:");
	}
}

void MainWindow::updateInputMode()
{
	updateInput();
	updateWorkMode();
}

void MainWindow::updateInput()
{
	if(readFromEntry.get_active())
	{
		textInput = std::make_shared<EntryInput>();
	}
	else
	{
		textInput = std::make_shared<FileInput>();
	}
}

void MainWindow::updateWorkMode()
{
	updateLabels();
}

void MainWindow::doWork()
{
	transferTextFromEntriesToInput();
	if(isError())
	{
		showErrorDialog();
	}
	else
	{
		if(doEncoding.get_active())
		{
			setTextToTextBuffer(codingService.encode(textInput->getText(),keyInput.getText()));
		} 
		else
		{
			setTextToTextBuffer(codingService.decode(textInput->getText(),keyInput.getText()));
		}
	}
}

void MainWindow::transferTextFromEntriesToInput()
{
	keyInput.setText(keyEntry.get_text());
	textInput->setText(textEntry.get_text());
}

bool MainWindow::isError()
{
	return textInput->isInputGood() == false || keyInput.isInputGood() == false;
}

void MainWindow::showErrorDialog()
{
	Gtk::MessageDialog dialog(*this,"Nothing", false, Gtk::MessageType::MESSAGE_ERROR, Gtk::ButtonsType::BUTTONS_CLOSE, false);
	dialog.set_message(getMajorErrorMessage());
	dialog.set_secondary_text(getMinorErrorMessage());
	dialog.run();
}

std::string MainWindow::getMajorErrorMessage()
{
		std::string str = doEncoding.get_active() ? "Encoding " : "Decoding ";
		return std::string(str + "is not possible");
}

std::string MainWindow::getMinorErrorMessage()
{
		std::string message;
		if(keyInput.isInputGood() == false)
		{
			message += "Key entry is empty";
		}
		if(textInput->isInputGood() == false)
		{
			if(message.size()>0)
			{
				message +="\n";
			}
			message += readFromEntry.get_active() ? "Text entry is empty" : "File is empty or it does not exsists";
		}
		return message;
}

void MainWindow::chooseFileFromADialog()
{
	if(readFromFile.get_active())
	{
		 Gtk::FileChooserDialog dialog("Please choose a text file", Gtk::FILE_CHOOSER_ACTION_OPEN);
		dialog.set_transient_for(*this);

		dialog.add_button("_Cancel", Gtk::RESPONSE_CANCEL);
		dialog.add_button("_Open", Gtk::RESPONSE_OK);

		auto filter_text = Gtk::FileFilter::create();
		filter_text->set_name("Text files");
		filter_text->add_mime_type("text/plain");
		dialog.add_filter(filter_text);
		
		int result = dialog.run();
		
		if(result == Gtk::ResponseType::RESPONSE_OK)
		{
			std::string uri = dialog.get_uri();
			uri.erase(uri.begin(),uri.begin()+7);
			textEntry.set_text(uri);
		}
	}
}
