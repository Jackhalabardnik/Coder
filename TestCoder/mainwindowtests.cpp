#include "catch.hpp"
#include "string.h"
#include "Coder/mainwindow.cpp"
#include <MockWindow.h>

Glib::RefPtr<Gtk::Application> app = Gtk::Application::create("I have to add this in order to make gtkmm going");

TEST_CASE( "MainWindow labels are updated", "[MainWindowTests]" ) 
{
	MockWindow window;
	SECTION("Sets labels by defualt to EntryInput-Encoding mode")
	{
		CHECK( window.getKeyEntryLabelText() == "Enter your public key:" );
		CHECK( window.getTextEntryLabelText() == "Enter text to encode:" );
		CHECK( window.getOutputEntryLabelText() == "Encoded text:" );
	}
	
	window.setDecodingMode();
	SECTION("Sets labels to decode method")
	{
		CHECK( window.getKeyEntryLabelText() == "Enter your private key:" );
		CHECK( window.getTextEntryLabelText() == "Enter text to decode:" );
		CHECK( window.getOutputEntryLabelText() == "Decoded text:" );
	}
	
	window.setEncodingMode();
	SECTION("Could set labels back to encoding mode")
	{
		CHECK( window.getKeyEntryLabelText() == "Enter your public key:" );
		CHECK( window.getTextEntryLabelText() == "Enter text to encode:" );
		CHECK( window.getOutputEntryLabelText() == "Encoded text:" );
	}
	
	window.setFileInputMode();
	SECTION("Changes textEntry label to file input in encoding mode")
	{
		CHECK(window.getTextEntryLabelText() == "Enter non-relative path to file to encode:");
	}
	
	window.setDecodingMode();
	SECTION("Changes textEntry label to file input in decoding mode")
	{
		CHECK(window.getTextEntryLabelText() == "Enter non-relative path to file to decode:");
	}
	
	window.setEntryInputMode();
	SECTION("Changes textEntry label to entry input in decoding mode")
	{
		CHECK(window.getTextEntryLabelText() == "Enter text to decode:");
	}
	
	window.setEncodingMode();
	SECTION("Changes textEntry label to entry input in encoding mode")
	{
		CHECK(window.getTextEntryLabelText() == "Enter text to encode:");
	}
}

TEST_CASE("MainWindow updates InputInterferance", "[MainWindowTests]" )
{
	MockWindow window;
	window.writeToTextInput("message");
	SECTION("InputInterferance is set on EntryInput after construction => returnes set text")
	{
		CHECK(window.getTextInputText() == "message");
	}
	window.setFileInputMode();
	window.writeToTextInput("/home/jacek/CLP/Coder/TestCoder/file.txt");
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
	window.writeToTextEntry("/home/jacek/CLP/Coder/TestCoder/file.txt");
	window.clickStartButton();
	SECTION("TextInput returns file text from path set to textEntry")
	{
		CHECK(window.getTextInputText() == "Some text\nSome texts");
	}
	SECTION("TextInput returns true when given appropirate file")
	{
		CHECK(window.hasTextEntryGoodText() == true);
	}
	window.writeToTextEntry("/home/file.txt");
	window.clickStartButton();
	SECTION("TextInput returns false when given non-existing file")
	{
		CHECK(window.hasTextEntryGoodText() == false);
	}
}

TEST_CASE("MainWindows recognises error state", "[MainWindowTests]")
{
	MockWindow window;
	window.setEntryInputMode();
	
	SECTION("When fields are filled after creation everything is okay")
	{
		CHECK(window.isError() == false);
	}
	window.writeToTextEntry("");
	window.clickStartButton();
	SECTION("Empty text field returns error")
	{
		CHECK(window.isError() == true);
	}
	window.writeToTextEntry("something");
	window.writeToKeyEntry("");
	window.clickStartButton();
	SECTION("Empty key field returns error")
	{
		CHECK(window.isError() == true);
	}
	window.writeToKeyEntry("keyyyyy");
	window.clickStartButton();
	SECTION("After filling both fields again return ok")
	{
		CHECK(window.isError() == false);
	}
	
	window.setFileInputMode();
	window.writeToTextEntry("/home/jacek/CLP/Coder/TestCoder/file.txt");
	window.clickStartButton();
	SECTION("For filled exsisting file returns ok")
	{
		CHECK(window.isError() == false);
	}
	window.writeToTextEntry("/home/jacek/CLP/Coder/TestCoder/emptyfile.txt");
	window.clickStartButton();
	SECTION("For empty exsisting file returns error")
	{
		CHECK(window.isError() == true);
	}
	window.writeToTextEntry("/home/jacek/CLP/Coder/TestCoder/nofile.txt");
	window.clickStartButton();
	SECTION("For non-exsisting file returns error")
	{
		CHECK(window.isError() == true);
	}
}

TEST_CASE("MainWindow prompts appropirate ErrorDialog message when something is not ok", "[MainWindowTests]")
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
		CHECK(window.getMinorErrorMessage() == "Key entry is empty");
	}
	SECTION("Minor message says that text entry in EntryInputMode is empty")
	{
		window.setEntryInputMode();
		window.writeToTextEntry("");
		window.clickStartButton();
		CHECK(window.getMinorErrorMessage() == "Text entry is empty");
	}
	SECTION("Minor message says that file in FileInputMode is empty or non-exsisting")
	{
		window.setFileInputMode();
		window.writeToTextEntry("");
		window.clickStartButton();
		CHECK(window.getMinorErrorMessage() == "File is empty or it does not exsists");
	}
	SECTION("Minor message says that file in FileInputMode is empty or non-exsisting and key entry is empty")
	{
		window.setFileInputMode();
		window.writeToTextEntry("");
		window.writeToKeyEntry("");
		window.clickStartButton();
		CHECK(window.getMinorErrorMessage() == "Key entry is empty\nFile is empty or it does not exsists");
	}
	SECTION("Minor message says that text entry in EntryInputMode is empty and key entry is empty")
	{
		window.setEntryInputMode();
		window.writeToTextEntry("");
		window.writeToKeyEntry("");
		window.clickStartButton();
		CHECK(window.getMinorErrorMessage() == "Key entry is empty\nText entry is empty");
	}
}