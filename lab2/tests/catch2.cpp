#define CATCH_CONFIG_MAIN
#include <catch2/catch.hpp>
#include "/home/qurst/automata_theory/lab2/regex_lib.hpp"

TEST_CASE("strings")
{
	SECTION("usual string")
	{
		std::string in = "abc", m = "abc";
		SRegex *reg = new SRegex(in);
		REQUIRE(reg->match(m) == true);
		delete reg;
	}

	SECTION("string with metacharacters escaping")
	{
		std::string in = "#(expelled#)", m = "(expelled)", m2 = "not?";
		SRegex *reg = new SRegex(in);
		REQUIRE(reg->match(m) == true);
		REQUIRE(reg->match(m2) == false);
		delete reg;
	}

	SECTION("just some strings")
	{
		std::string in = "mephi|ms(u+)", m = "mephi";
		SRegex reg(in);
		REQUIRE(reg.match(m) == true);
		m = "ms";
		REQUIRE(reg.match(m) == false);
		m = "msuuuuuu";
		REQUIRE(reg.match(m) == true);
		m = "mephi";
		REQUIRE(reg.match(m) == true);
		m = "mephidron";
		REQUIRE(reg.match(m) == false);
	}

	SECTION ("{}")
	{
		std::string in = "(#|#.#|){3,5}", m = "|.|";
		SRegex reg(in);
		REQUIRE(reg.match(m) == false);
		m = "|.||.|";
		REQUIRE(reg.match(m) == false);
		m = "|.||.||.|";
		REQUIRE(reg.match(m) == true);
                m = "|.||.||.||.|";
                REQUIRE(reg.match(m) == true);
                m = "|.||.||.||.||.|";
                REQUIRE(reg.match(m) == true);
                m = "|.||.||.||.||.||.|";
                REQUIRE(reg.match(m) == false);
	}
	SECTION("capture groups")
	{
		std::string in = "jrw(1:bwjerg)tu(2:dkjgb)(3:ogo, it's over)", m = "jrwbwjergtudkjgbogo, it's over";
		SRegex reg(in);
		REQUIRE(reg.match(m) == true);
		m = "kakaya to hren";
		REQUIRE(reg.match(m) == false);
		reg.set_capture_groups();
	}
}
