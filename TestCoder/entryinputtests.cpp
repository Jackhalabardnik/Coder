#include <catch.hpp>
#include <Coder/InputInterferance.h>
#include <Coder/EntryInput.cpp>

TEST_CASE("Basic EntryInput workflow works","[EntryInputTests]")
{
	EntryInput input;
	SECTION("Returnes false with no set text")
	{
		CHECK(input.isInputGood() == false);
	}
	input.setText("Text");
	SECTION("Returnes true with set text")
	{
		CHECK(input.isInputGood() == true);
	}
	input.setText("");
	SECTION("Returnes false with set empty text")
	{
		CHECK(input.isInputGood() == false);
	}
	input.setText("Text");
	SECTION("Returns set text")
	{
		CHECK(input.getText() == "Text");
	}
}