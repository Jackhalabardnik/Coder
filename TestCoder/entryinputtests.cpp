#include <catch.hpp>
#include <Coder/InputInterferance.h>
#include <Coder/EntryInput.cpp>

TEST_CASE("Entry Input returns false state without set text","[EntryInputTests]")
{
	EntryInput input;
	CHECK(input.isInputGood() == false);
}

TEST_CASE("Entry Input returns true state with set good text","[EntryInputTests]")
{
	EntryInput input;
	input.setText("Text");
	CHECK(input.isInputGood() == true);
}

TEST_CASE("Entry Input returns false state with set no text","[EntryInputTests]")
{
	EntryInput input;
	input.setText("");
	CHECK(input.isInputGood() == false);
}

TEST_CASE("Entry Input returns set text","[EntryInputTests]")
{
	EntryInput input;
	input.setText("Text");
	CHECK(input.getText() == "Text");
}