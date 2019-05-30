#include "catch.hpp"
#include "string.h"
#include "Coder/mainwindow.cpp"

class MockWindow : public MainWindow
{
public:
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
	
	std::string getKeyEntryLabelText()
	{
		return codeEntryLabel.get_text();
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
	SECTION("MainWindow sets labels by defualt to EntryInput-Encoding mode")
	{
		CHECK( window.getKeyEntryLabelText() == "Enter your public key:" );
		CHECK( window.getTextEntryLabelText() == "Enter text to encode:" );
		CHECK( window.getOutputEntryLabelText() == "Encoded text:" );
	}
	
	window.setDecodingMode();
	SECTION("MainWindow sets labels to decode method")
	{
		CHECK( window.getKeyEntryLabelText() == "Enter your private key:" );
		CHECK( window.getTextEntryLabelText() == "Enter text to decode:" );
		CHECK( window.getOutputEntryLabelText() == "Decoded text:" );
	}
	
	window.setEncodingMode();
	SECTION("MainWindow could set labels back to encoding mode")
	{
		CHECK( window.getKeyEntryLabelText() == "Enter your public key:" );
		CHECK( window.getTextEntryLabelText() == "Enter text to encode:" );
		CHECK( window.getOutputEntryLabelText() == "Encoded text:" );
	}
	
	window.setFileInputMode();
	SECTION("MainWindow changes textEntry label to file input in encoding mode")
	{
		CHECK(window.getTextEntryLabelText() == "Enter path to file to encode:");
	}
	
	window.setDecodingMode();
	SECTION("MainWindow changes textEntry label to file input in decoding mode")
	{
		CHECK(window.getTextEntryLabelText() == "Enter path to file to decode:");
	}
	
	window.setEntryInputMode();
	SECTION("MainWindow changes textEntry label to entry input in decoding mode")
	{
		CHECK(window.getTextEntryLabelText() == "Enter text to decode:");
	}
	
	window.setEncodingMode();
	SECTION("MainWindow changes textEntry label to entry input in encoding mode")
	{
		CHECK(window.getTextEntryLabelText() == "Enter text to encode:");
	}
}