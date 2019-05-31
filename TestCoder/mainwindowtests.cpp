#include "catch.hpp"
#include "string.h"
#include "Coder/mainwindow.cpp"

class MockWindow : public MainWindow
{
public:
	void clickExitButton()
	{
		exitButton.clicked();
	}
	void setDecodingMode()
	{
		doDecoding.set_active();
	}
	void setEncodingMode()
	{
		doEncoding.set_active();
	}
	
	void setEntryInputMode()
	{
		readFromEntry.set_active();
	}
	
	void setFileInputMode()
	{
		readFromFile.set_active();
	}
	
	void setKeyText(std::string text)
	{
		keyEntry.set_text(text);
	}
	
	bool isErrorDialogOpened()
	{
		return false;
	}
	
	std::string getErrorDialogText()
	{
		return "";
	}
	
	std::string getKeyEntryLabelText()
	{
		return keyEntryLabel.get_text();
	}
	std::string getTextEntryLabelText()
	{
		return textEntryLabel.get_text();
	}
	std::string getOutputEntryLabelText()
	{
		return outputEntryLabel.get_text();
	}
};

Glib::RefPtr<Gtk::Application> app = Gtk::Application::create("I have to add this in order to make gtkmm going");

TEST_CASE( "MainWindow labels are updated", "[MainWindowTests]" ) {
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

TEST_CASE("Exit button closes program","[MainWindowTests]")
{
	MockWindow window;
	window.clickExitButton();
	CHECK(window.is_visible() == false);
}