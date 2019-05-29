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

TEST_CASE( "MainWindow sets labels to decode method after choosing decode method", "[MainWindowTests]" ) {
	MockWindow window;
	window.setDecodingMode();
    ( window.getKeyEntryLabelText() == "Enter your private key:" );
	CHECK( window.getTextEntryLabelText() == "Enter text to decode:" );
	CHECK( window.getOutputEntryLabelText() == "Decoded text:" );
}

TEST_CASE( "MainWindow sets labels to decode method after choosing encode method", "[MainWindowTests]" ) {
	MockWindow window;
	window.setDecodingMode();
	window.setEncodingMode();
	CHECK( window.getKeyEntryLabelText() == "Enter your public key:" );
	CHECK( window.getTextEntryLabelText() == "Enter text to encode:" );
	CHECK( window.getOutputEntryLabelText() == "Encoded text:" );
}

TEST_CASE( "MainWindow sets inputTextLabel to text input after choosing readFromEntry radio button", "[MainWindowTests]" ) {
	MockWindow window;
	window.setFileInputMode();
	window.setEntryInputMode();
	CHECK(window.getTextEntryLabelText() == "Enter text to encode:");
}

TEST_CASE( "MainWindow sets inputTextLabel to file input after choosing readFromFile radio button", "[MainWindowTests]" ) {
	MockWindow window;
	window.setEntryInputMode();
	window.setFileInputMode();
	CHECK(window.getTextEntryLabelText() == "Enter path to file to encode:");
}