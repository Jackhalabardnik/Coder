#include <catch.hpp>
#include <Coder/InputInterferance.h>
#include <Coder/FileInput.cpp>

TEST_CASE("Basic FileInput workflow works", "[FileInputTests]")
{
	FileInput input;
	SECTION("Returns false with no file")
	{
		CHECK(input.isInputGood() == false);
	}
	input.setText("/home/jacek/CLP/Coder/Release/file.txt");
	SECTION("For exsisting and non-empty file returns true")
	{
		CHECK(input.isInputGood() == true);
	}
	input.setText("/home/jacek/CLP/Coder/Release/emptyfile.txt");
	SECTION("For exsisting and empty file returns false")
	{
		CHECK(input.isInputGood() == false);
	}
	input.setText("/home/jacek/CLP/Coder/Release/nofile.txt");
	SECTION("For non-exsisting file returns false")
	{
		CHECK(input.isInputGood() == false);
	}
	input.setText("/home/jacek/CLP/Coder/Release/file.txt");
	SECTION("Returnes file text")
	{
		CHECK(input.getText() == "Some text\nSome texts");
	}
	SECTION("After std::fstream buffer is read and empty, still returns true")
	{
		CHECK(input.isInputGood() == true);
	}
	SECTION("After getting text once is able to get text one more time")
	{
		CHECK(input.getText() == "Some text\nSome texts");
	}
	input.setText("/home/jacek/CLP/Coder/Release/emptyfile.txt");
	SECTION("When given empty file returns empty string")
	{
		CHECK(input.getText() == "");
	}
	input.setText("/home/jacek/CLP/Coder/Release/nofile.txt");
	SECTION("When given non-exsisting file returns empty string")
	{
		CHECK(input.getText() == "");
	}
}