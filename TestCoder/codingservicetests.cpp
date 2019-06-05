#include <catch.hpp>
#include <iostream>

#include <Coder/CodingService.cpp>

TEST_CASE("Coding service codes given text", "[CodingServiceTests]")
{
	CodingService service;
	SECTION("Encoding")
	{
		CHECK(service.encode("TEXT", "KEY") == "\"j4\"");
		CHECK(service.encode("KEY", "TEXT") == "\"j4");
		CHECK(service.encode("K E Y", "T EXT") == "\" jX0");
	}
	SECTION("Decoding")
	{
		CHECK(service.decode("\"j4\"", "KEY") == "TEXT");
		CHECK(service.decode("\"j4", "TEXT") == "KEY");
	}
	SECTION("No given text")
	{
		CHECK(service.decode("", "KEY") == "");
		CHECK(service.encode("", "KEY") == "");
	}
	SECTION("No given key")
	{
		CHECK(service.decode("text", "") == "text");
		CHECK(service.encode("text", "") == "text");
	}
}
