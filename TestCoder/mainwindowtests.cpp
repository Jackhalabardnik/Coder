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


TEST_CASE( "MainWindow sets labels to decode method after choosing decode method", "[MainWindowTests]" ) {
	Glib::RefPtr<Gtk::Application> app = Gtk::Application::create("I have to add this in order to make gtkmm going");
	MockWindow window;
	window.setDecodingMode();
    ( window.getKeyEntryLabelText() == "Enter your private key:" );
	CHECK( window.getTextEntryLabelText() == "Enter text to decode:" );
	CHECK( window.getOutputEntryLabelText() == "Decoded text:" );
}

TEST_CASE( "MainWindow sets labels to decode method after choosing firstly decode, secondly encode method", "[MainWindowTests]" ) {
	Glib::RefPtr<Gtk::Application> app = Gtk::Application::create("I have to add this in order to make gtkmm going");
	MockWindow window;
	window.setDecodingMode();
	window.setEncodingMode();
	CHECK( window.getKeyEntryLabelText() == "Enter your public key:" );
	CHECK( window.getTextEntryLabelText() == "Enter text to encode:" );
	CHECK( window.getOutputEntryLabelText() == "Encoded text:" );
}