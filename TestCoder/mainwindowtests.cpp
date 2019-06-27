#include "catch.hpp"
#include "string.h"
#include "Coder/mainwindow.cpp"
#include <MockWindow.h>

Glib::RefPtr<Gtk::Application> app = Gtk::Application::create("I have to add this in order to make gtkmm going");

TEST_CASE( "Labels are updated", "[MainWindowTests]" ) 
{
	MockWindow window;
	SECTION("Sets labels by defualt to EntryInput-Encoding mode")
	{
		CHECK( window.getTextEntryLabelText() == "Enter text to encode:" );
	}
	
	window.setFileInputMode();
	SECTION("Changes textEntry label to file input in both modes")
	{
		window.setEncodingMode();
		CHECK(window.getTextEntryLabelText() == "Enter non-relative path to file to encode:");
		window.setDecodingMode();
		CHECK(window.getTextEntryLabelText() == "Enter non-relative path to file to decode:");
	}
	
	window.setEntryInputMode();
	SECTION("Changes textEntry label to entry input in both modes")
	{
		window.setEncodingMode();
		CHECK(window.getTextEntryLabelText() == "Enter text to encode:");
		window.setDecodingMode();
		CHECK(window.getTextEntryLabelText() == "Enter text to decode:");
	}
}

TEST_CASE("Shows helpLabel and button to choose output file only when output to file is active")
{
	MockWindow window;
	SECTION("After creation label and button is hidden => textbox output mode")
	{
		CHECK(window.isHelpLabelVisible() == false);
		CHECK(window.isOpenChooseOutcomeFileDialogVisible() == false);
	}
	window.setOutputToFile();
	SECTION("In file&textbox output mode help label and button is visible")
	{
		CHECK(window.isHelpLabelVisible() == true);
		CHECK(window.isOpenChooseOutcomeFileDialogVisible() == true);
	}
	window.setOutputToTextbox();
	SECTION("In textbox output mode help label and button is hidden")
	{
		CHECK(window.isHelpLabelVisible() == false);
		CHECK(window.isOpenChooseOutcomeFileDialogVisible() == false);
	}
}

TEST_CASE("Updates InputInterferance", "[MainWindowTests]" )
{
	MockWindow window;
	window.writeToTextInput("message");
	SECTION("InputInterferance is set on EntryInput after construction => returnes set text")
	{
		CHECK(window.getTextInputText() == "message");
	}
	window.setFileInputMode();
	window.writeToTextInput("file.txt");
	SECTION("InputInterferance changes to FileInput mode after click => returnes file text")
	{
		CHECK(window.getTextInputText() == "Some text\nSome texts");
	}
	window.setEntryInputMode();
	window.writeToTextInput("AMEN");
	SECTION("InputInterferance changes to EntryInput mode after click => returnes set text")
	{
		CHECK(window.getTextInputText() == "AMEN");
	}
}

TEST_CASE("KeyEntryInput workflow works", "[MainWindowTests]")
{
	MockWindow window;
	window.clickStartButton();
	SECTION("EntryInput returns default KeyEntry text")
	{
		CHECK(window.getKeyInputText() == "key");
	}
	window.writeToKeyEntry("12345");
	window.clickStartButton();
	SECTION("EntryInput returns entered to KeyEntry text")
	{
		CHECK(window.getKeyInputText() == "12345");
	}
	SECTION("EntryInput returns true to appropirate KeyEntry text")
	{
		CHECK(window.hasKeyEntryGoodText() == true);
	}
	
	window.writeToKeyEntry("");
	window.clickStartButton();
	SECTION("EntryInput returns false to empty KeyEntry text")
	{
		CHECK(window.hasKeyEntryGoodText() == false);
	}
}

TEST_CASE("TextInput workflow works", "[MainWindowTests]")
{
	MockWindow window;
	window.clickStartButton();
	SECTION("TextInput retruns default textEntry text")
	{
		CHECK(window.getTextInputText() == "text");
	}
	window.writeToTextEntry("abcd");
	window.clickStartButton();
	SECTION("TextInput returns text set to textEntry")
	{
		CHECK(window.getTextInputText() == "abcd");
	}
	window.setFileInputMode();
	window.writeToTextEntry("file.txt");
	window.clickStartButton();
	SECTION("TextInput returns file text from path set to textEntry")
	{
		CHECK(window.getTextInputText() == "Some text\nSome texts");
	}
	SECTION("TextInput returns true when given appropirate file")
	{
		CHECK(window.hasTextEntryGoodText() == true);
	}
	window.writeToTextEntry("/nonononooon-+/file.txt");
	window.clickStartButton();
	SECTION("TextInput returns false when given non-existing file")
	{
		CHECK(window.hasTextEntryGoodText() == false);
	}
}

TEST_CASE("Recognises error state", "[MainWindowTests]")
{
	MockWindow window;
	window.setEntryInputMode();
	
	SECTION("After creation everything is ok")
	{
		CHECK(window.isError() == false);
	}
	
	SECTION("For help label with default path alert in output to file mode returns error")
	{
		window.setOutputToFile();
		CHECK(window.isError() == true);
	}
	
	SECTION("For help label with path in output to file mode returns ok")
	{
		window.setOutputToFile();
		window.setPathLabelText("file.txt");
		CHECK(window.isError() == false);
	}
	
	SECTION("Empty text field returns error")
	{
		window.writeToTextEntry("");
		window.clickStartButton();
		CHECK(window.isError() == true);
	}
	
	SECTION("Empty key field returns error")
	{
		window.writeToKeyEntry("");
		window.clickStartButton();
		CHECK(window.isError() == true);
	}
	
	window.setFileInputMode();
	
	SECTION("For filled exsisting file returns ok")
	{
		window.writeToTextEntry("file.txt");
		window.clickStartButton();
		CHECK(window.isError() == false);
	}
	
	SECTION("For empty exsisting file returns error")
	{
		window.writeToTextEntry("emptyfile.txt");
		window.clickStartButton();
		CHECK(window.isError() == true);
	}
	
	SECTION("For non-exsisting file returns error")
	{
		window.writeToTextEntry("nofile.txt");
		window.clickStartButton();
		CHECK(window.isError() == true);
	}
	
}

TEST_CASE("Prompts appropirate ErrorDialog message when something is not ok", "[MainWindowTests]")
{
	MockWindow window;
	SECTION("Major message changes as code mode changes")
	{
		window.setEncodingMode();
		CHECK(window.getMajorErrorMessage() == "Encoding is not possible");
		window.setDecodingMode();
		CHECK(window.getMajorErrorMessage() == "Decoding is not possible");
	}
	SECTION("Minor message says that key entry is empty")
	{
		window.writeToKeyEntry("");
		window.clickStartButton();
		CHECK(window.getMinorErrorMessage() == "Key entry is empty\n");
	}
	SECTION("Minor message says that text entry in EntryInputMode is empty")
	{
		window.setEntryInputMode();
		window.writeToTextEntry("");
		window.clickStartButton();
		CHECK(window.getMinorErrorMessage() == "Text entry is empty\n");
	}
	SECTION("Minor message says that file in FileInputMode is empty or non-exsisting")
	{
		window.setFileInputMode();
		window.writeToTextEntry("");
		window.clickStartButton();
		CHECK(window.getMinorErrorMessage() == "File is empty or it does not exsists\n");
	}
	SECTION("Minor message says that file in FileInputMode is empty or non-exsisting and key entry is empty")
	{
		window.setFileInputMode();
		window.writeToTextEntry("");
		window.writeToKeyEntry("");
		window.clickStartButton();
		CHECK(window.getMinorErrorMessage() == "Key entry is empty\nFile is empty or it does not exsists\n");
	}
	SECTION("Minor message says that text entry in EntryInputMode is empty and key entry is empty")
	{
		window.setEntryInputMode();
		window.writeToTextEntry("");
		window.writeToKeyEntry("");
		window.clickStartButton();
		CHECK(window.getMinorErrorMessage() == "Key entry is empty\nText entry is empty\n");
	}
	SECTION("Minor message says that no outcome file is selected")
	{
		window.setPathLabelText("No path selected");
		window.setOutputToFile();
		CHECK(window.getMinorErrorMessage() == "No outcome file selected");
	}
}

TEST_CASE("Prompts output to EntryOutput after clicking go button", "[MainWindowTests]")
{
	MockWindow window;
	SECTION("Normal output after encoding input")
	{
		window.setEncodingMode();
		window.writeToKeyEntry("KEY");
		window.writeToTextEntry("TEXT");
		window.clickStartButton();
		CHECK(window.getOutputTextboxText() == "\"j4\"");
	}
	SECTION("Normal output after decoding input")
	{
		window.setDecodingMode();
		window.writeToKeyEntry("KEY");
		window.writeToTextEntry("\"j4\"");
		window.clickStartButton();
		CHECK(window.getOutputTextboxText() == "TEXT");
	}
	SECTION("Nothing is changed after encoding bad input")
	{
		window.setEncodingMode();
		window.writeToTextEntry("");
		window.clickStartButton();
		CHECK(window.getOutputTextboxText() == "Nothing here");
	}
	SECTION("Normal output after decoding bad input")
	{
		window.setDecodingMode();
		window.writeToTextEntry("");
		window.clickStartButton();
		CHECK(window.getOutputTextboxText() == "Nothing here");
	}
}

TEST_CASE("Is openChooserFileDialog visible only when readFromFile is active", "[MainWindowTests]")
{
	MockWindow window;
	SECTION("After creation window is in EntryInput mode OpenChooserFileDialog is invisible")
	{
		CHECK(window.isOpenChooseFileDialogVisible() == false);
	}
	window.setFileInputMode();
	SECTION("Window is in FileInput mode => OpenChooserFileDialog is visible")
	{
		CHECK(window.isOpenChooseFileDialogVisible() == true);
	}
	window.setEntryInputMode();
	SECTION("Window is in EntryInput mode => OpenChooserFileDialog is invisible")
	{
		CHECK(window.isOpenChooseFileDialogVisible() == false);
	}
}

TEST_CASE("Writes to file coded text, path is always good", "[MainWindowTests]")
{
	MockWindow window;
	FileInput input;
	std::string test_1 = "Simple but true";
	std::string test_2 = "Repetetive\n but\n true";
	SECTION("Test if write method erases file before writting")
	{
		window.writeToFile("writeFile.txt", test_1);
		input.setText("writeFile.txt");
		CHECK(input.getText() == test_1);
	}
	SECTION("Test if write method writes enters")
	{
		window.writeToFile("writeFile.txt", test_2);
		input.setText("writeFile.txt");
		CHECK(input.getText() == test_2);
	}
}

TEST_CASE("Repetetive coding works", "[MainWindowTests]")
{
	MockWindow window;
	window.setRepetetiveCoding();
	SECTION("Codes text, and after that codes result till change of given text in repetetive mode")
	{
		window.clickStartButton();
		window.clickStartButton();
		CHECK(window.getOutputTextboxText() == "P5pP");
	}
	window.setOneTimeCoding();
	SECTION("Codes text once in one time mode")
	{
		window.clickStartButton();
		window.clickStartButton();
		CHECK(window.getOutputTextboxText() == "bMtb");
	}
	SECTION("User codes text once and then he goes to repetetive mode")
	{
		window.clickStartButton();
		window.setRepetetiveCoding();
		window.clickStartButton();
		CHECK(window.getOutputTextboxText() == "P5pP");
	}
}
