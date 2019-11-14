#include <catch.hpp>

#include <Coder/RSACoding.cpp>

TEST_CASE("RSA Coding codes given text", "[RSACoding]")
{
	RSACoding service;
	SECTION("RSA Coding Service encodes given text")
	{
		CHECK(service.encode("ABC","123") == "BCD");
	}
}
