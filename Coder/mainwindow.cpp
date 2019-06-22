#include "mainwindow.h"

MainWindow::MainWindow()
{
	setGUI();
}

void MainWindow::setGUI()
{
		setChooseMethodGrid();
		setChooseInputGrid();
		setChooseOutputGrid();
		setEntry();
		setInputInterferance();
		setOutInfo();

		setButtons();
		setPathLabel();

		setMainGrid();
		fillMainGrid();

		setWindow();

		showEverythingAtCreation();
}

void MainWindow::setChooseInputGrid()
{
	auto label = Gtk::manage(new Gtk::Label("Choose input:"));

	readFromFile.set_label("File");
	readFromEntry.set_label("Textbox");
	
	readFromEntry.signal_toggled().connect(sigc::mem_fun(*this, &MainWindow::updateInputMode));
	readFromFile.signal_toggled().connect(sigc::mem_fun(*this, &MainWindow::updateInputMode));

	readFromFile.join_group(readFromEntry);
	readFromEntry.set_active();

	chooseInputGrid.set_row_spacing(3);

	chooseInputGrid.attach(*label, 0,0,1,1);
	chooseInputGrid.attach_next_to(readFromEntry, *label,Gtk::PositionType::POS_BOTTOM ,1,1);
	chooseInputGrid.attach_next_to(readFromFile, readFromEntry,Gtk::PositionType::POS_BOTTOM ,1,1);

}

void MainWindow::setChooseMethodGrid()
{
	auto label = Gtk::manage(new Gtk::Label("Choose work mode: "));

	doDecoding.set_label("Decoding");
	doEncoding.set_label("Encoding");

	doDecoding.signal_toggled().connect(sigc::mem_fun(*this, &MainWindow::updateWorkMode));
	doEncoding.signal_toggled().connect(sigc::mem_fun(*this, &MainWindow::updateWorkMode));

	doDecoding.join_group(doEncoding);
	doEncoding.set_active();

	chooseMethodGrid.set_row_spacing(3);

	chooseMethodGrid.attach(*label, 0,0,1,1);
	chooseMethodGrid.attach_next_to(doEncoding, *label,Gtk::PositionType::POS_BOTTOM ,1,1);
	chooseMethodGrid.attach_next_to(doDecoding, doEncoding,Gtk::PositionType::POS_BOTTOM ,1,1);
}

void MainWindow::setChooseOutputGrid()
{
	auto label = Gtk::manage(new Gtk::Label("Choose output place: "));

	writeToFileAndTextBox.set_label("File & Textbox");
	writeToTextBox.set_label("Textbox");

	writeToFileAndTextBox.signal_toggled().connect(sigc::mem_fun(*this, &MainWindow::updateOutcomeMode));
	writeToTextBox.signal_toggled().connect(sigc::mem_fun(*this, &MainWindow::updateOutcomeMode));

	writeToFileAndTextBox.join_group(writeToTextBox);
	writeToTextBox.set_active();

	chooseOutputGrid.set_row_spacing(3);

	chooseOutputGrid.attach(*label, 0,0,1,1);
	chooseOutputGrid.attach_next_to(writeToTextBox, *label,Gtk::PositionType::POS_BOTTOM ,1,1);
	chooseOutputGrid.attach_next_to(writeToFileAndTextBox, writeToTextBox,Gtk::PositionType::POS_BOTTOM ,1,1);
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
	outputEntryLabel.set_text("Result:");
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
	openChooseSourceFileDialog.set_label("...");
	openChooseSourceFileDialog.signal_clicked().connect(sigc::mem_fun(*this,&MainWindow::chooseSourceFileFromADialog));
	openChooseOutcomeFileDialog.set_label("...");
	openChooseOutcomeFileDialog.signal_clicked().connect(sigc::mem_fun(*this,&MainWindow::chooseTextFileFromDialog));
}

void MainWindow::setPathLabel()
{
	pathLabel.set_text("No path selected");
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
		mainGrid.attach(textEntryLabel,1,3, 4,1);
		mainGrid.attach(textEntry,1,4,4,1);
		mainGrid.attach(openChooseSourceFileDialog, 5,4,1,1);

		mainGrid.attach(chooseMethodGrid,2,5,1,1);
		mainGrid.attach(chooseInputGrid,3, 5, 1, 1);
		mainGrid.attach(chooseOutputGrid,4, 5, 1, 1);

		mainGrid.attach(startButton, 2, 6, 4,1);

		mainGrid.attach(outputEntryLabel,3,7,1,1);
		mainGrid.attach(scrolledWindow,1, 8, 4,2);
		mainGrid.attach(openChooseOutcomeFileDialog, 5,8,1,2);

		mainGrid.attach(exitButton, 2, 12, 4,1);
		mainGrid.attach(pathLabel, 1, 13, 4,1);
}

void MainWindow::setWindow()
{
	set_border_width(10);
	set_size_request(300,400);
	set_resizable(false);
	set_title("Coder v1.2.4");
}

void MainWindow::showEverythingAtCreation()
{
	exitButton.show();
	startButton.show();
	outputEntryLabel.show();
	outputTextView.show();
	scrolledWindow.show();
	keyEntryLabel.show();
	keyEntry.show();
	textEntryLabel.show();
	textEntry.show();
	chooseMethodGrid.show_all();
	chooseInputGrid.show_all();
	chooseOutputGrid.show_all();
	mainGrid.show();
	show();
}

void MainWindow::updateInputTextLabel()
{
	std::string input_text = readFromEntry.get_active() ? "text" : "non-relative path to file";
	std::string code_method = doEncoding.get_active() ? "encode" : "decode";
	textEntryLabel.set_text(std::string("Enter " + input_text + " to " + code_method +":"));
}

void MainWindow::updateOutcomeMode()
{
	pathLabel.set_visible(writeToFileAndTextBox.get_active());
	openChooseOutcomeFileDialog.set_visible(writeToFileAndTextBox.get_active());
}

void MainWindow::updateInputMode()
{
	openChooseSourceFileDialog.set_visible(readFromFile.get_active());
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
	updateInputTextLabel();
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
		std::string key = keyInput.getText();
		std::string text = textInput->getText();
		std::string output = doEncoding.get_active() ? codingService.encode(text,key) : codingService.decode(text,key);
		setTextToTextBuffer(output);
		
		if(writeToFileAndTextBox.get_active())
		{
			writeToFile(pathLabel.get_text(),output);
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
	bool isPathNotSelected = writeToFileAndTextBox.get_active() && pathLabel.get_text() == "No path selected";
	return textInput->isInputGood() == false || keyInput.isInputGood() == false || isPathNotSelected;
}

void MainWindow::showErrorDialog()
{
	if(isError())
	{
		Gtk::MessageDialog dialog(*this,"Nothing", false, Gtk::MessageType::MESSAGE_ERROR, Gtk::ButtonsType::BUTTONS_CLOSE, false);
		dialog.set_message(getMajorErrorMessage());
		dialog.set_secondary_text(getMinorErrorMessage());
		dialog.run();
	}
}

std::string MainWindow::getMajorErrorMessage()
{
		std::string str = doEncoding.get_active() ? "Encoding " : "Decoding ";
		return std::string(str + "is not possible");
}

std::string MainWindow::getMinorErrorMessage()
{
		std::string message;
		message += keyInput.isInputGood() == false ? "Key entry is empty\n" : "";
		if(textInput->isInputGood() == false)
		{
			message += readFromEntry.get_active() ? "Text entry is empty\n" : "File is empty or it does not exsists\n";
		}
		if(writeToFileAndTextBox.get_active())
		{
			message += pathLabel.get_text() == "No path selected" ? "No outcome file selected" : "";
		}
		return message;
}

void MainWindow::chooseSourceFileFromADialog()
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


void MainWindow::chooseTextFileFromDialog()
{
	Gtk::FileChooserDialog dialog("Please choose a text file", Gtk::FILE_CHOOSER_ACTION_OPEN);
	dialog.set_transient_for(*this);

	dialog.add_button("_Cancel", Gtk::RESPONSE_CANCEL);
	dialog.add_button("_Open", Gtk::RESPONSE_OK);
	dialog.add_button("New File", 1);

	auto filter_text = Gtk::FileFilter::create();
	filter_text->set_name("Text files");
	filter_text->add_mime_type("text/plain");
	dialog.add_filter(filter_text);
	
	int result = dialog.run();
	
	std::string uri;
	
	if(result == Gtk::ResponseType::RESPONSE_OK)
	{
		uri = dialog.get_uri();
		uri.erase(uri.begin(),uri.begin()+7);
	}
	else if(result == 1)
	{
		uri += dialog.get_current_folder_uri() + "/";
		uri.erase(uri.begin(),uri.begin()+7);
		uri += askUserForNewFileName();
	}
	else
	{
		uri = "No path selected";
	}
	pathLabel.set_text(uri);
}

std::string MainWindow::askUserForNewFileName()
{
	Gtk::MessageDialog dialog(*this, "Type new file name", false, Gtk::MessageType::MESSAGE_OTHER, Gtk::BUTTONS_OK_CANCEL,false);
	
	auto entry = Gtk::manage(new Gtk::Entry);
	entry->show();
	
	dialog.get_content_area()->pack_start(*entry, true, true, 1);
	
	
	int response = dialog.run();
	std::string uri;
	
	if(response == Gtk::RESPONSE_OK)
	{
		uri = entry->get_text();
	}
	
	return uri;
}

void MainWindow::writeToFile(std::string path, std::string text)
{
	std::fstream stream;
	stream.open(path, std::fstream::out | std::fstream::trunc);
	stream << text << "\n";
	stream.close();
}
