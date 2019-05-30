#include <catch.hpp>
#include <Coder/InputInterferance.h>
#include <Coder/EntryInput.cpp>

TEST_CASE("Basic workflow works","[EntryInputTests]")
{
	EntryInput input;
	SECTION("Entry Input returnes false with no set text")
	{
		CHECK(input.isInputGood() == false);
	}
	input.setText("Text");
	SECTION("Entry Input returnes true with set text")
	{
		CHECK(input.isInputGood() == true);
	}
	input.setText("");
	SECTION("Entry Input returnes false with set empty text")
	{
		CHECK(input.isInputGood() == false);
	}
	input.setText("Text");
	SECTION("Entry Input returns set text")
	{
		CHECK(input.getText() == "Text");
	}
}