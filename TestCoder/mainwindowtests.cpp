#include "catch.hpp"
#include "string.h"
#include "Coder/mainwindow.cpp"
#include <MockWindow.h>

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
