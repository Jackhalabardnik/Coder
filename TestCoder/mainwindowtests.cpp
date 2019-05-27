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


TEST_CASE( "MainWindow sets labels to encode method after itself creation", "[MainWindowTests]" ) {
	Glib::RefPtr<Gtk::Application> app = Gtk::Application::create("I have to add this in order to make gtkmm going");
	MockWindow window;
    REQUIRE( window.getKeyEntryLabelText() == "Enter your public key:" );
	REQUIRE( window.getTextEntryLabelText() == "Enter text to encode:" );
	REQUIRE( window.getOutputEntryLabelText() == "Encoded text:" );
}