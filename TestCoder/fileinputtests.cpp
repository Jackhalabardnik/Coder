#include <catch.hpp>
#include <Coder/InputInterferance.h>
#include <Coder/FileInput.cpp>

TEST_CASE("File Input returns false with no file","[FileInputTests]")
{
	FileInput input;
	CHECK(input.isInputGood() == false);
}

TEST_CASE("File Input return true with exsisting and non-empty file, non-relative path","[FileInputTests]")
{
	FileInput input;
	input.setText("/home/jacek/CLP/Coder/Release/file.txt");
	CHECK(input.isInputGood() == true);
}

TEST_CASE("File Input return false with exsisting and empty file, non-relative path","[FileInputTests]")
{
	FileInput input;
	input.setText("/home/jacek/CLP/Coder/Release/emptyfile.txt");
	CHECK(input.isInputGood() == false);
}

TEST_CASE("File Input return true with non-exsisting file","[FileInputTests]")
{
	FileInput input;
	input.setText("/home/jacek/CLP/Coder/Release/nofile.txt");
	CHECK(input.isInputGood() == false);
}

TEST_CASE("File Input return file text","[FileInputTests]")
{
	FileInput input;
	input.setText("/home/jacek/CLP/Coder/Release/file.txt");
	CHECK(input.getText() == "Some text\nSome texts");
}

TEST_CASE("File Input return empty string when false state","[FileInputTests]")
{
	FileInput input;
	input.setText("/home/jacek/CLP/Coder/Release/emptyfile.txt");
	CHECK(input.getText() == "");
}

TEST_CASE("File Input return true after getting file text","[FileInputTests]")
{
	FileInput input;
	input.setText("/home/jacek/CLP/Coder/Release/file.txt");
	input.getText();
	CHECK(input.isInputGood() == true);
}