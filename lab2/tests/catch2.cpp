#define CATCH_CONFIG_MAIN
#include <catch2/catch.hpp>
#include "/home/fdfdas/automata_theory/lab2/regex_lib.hpp"

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
		REQUIRE(reg.m[1] == "b.w.j.e.r.g");
                REQUIRE(reg.m[2] == "d.k.j.g.b");
                REQUIRE(reg.m[3] == "o.g.o.,. .i.t.'.s. .o.v.e.r");
	}

	SECTION("void substrings")
	{
		std::string in = "ab^c", m = "abc";
		SRegex reg(in);
		REQUIRE(reg.match(m) == true);
		in = "^fg^";
		m = "fg";
		SRegex reg2(in);
		REQUIRE(reg2.match(m) == true);
	}
}

TEST_CASE("K-path")
{
	std::string in = "a(b|c)(d|m)", m = "acd";
	SRegex reg(in);
	REQUIRE(reg.match(m) == true);
	SRegex restore_reg(reg.restore_regex());
	REQUIRE(restore_reg.match(m) == true);
}

TEST_CASE("addition to language")
{
	 std::string in = "(a|b)c", m = "bc";
	 SRegex reg(in);
	 REQUIRE(reg.language_addition(m) == false);
}

TEST_CASE("traversial of languages")
{
	std::string r1 = "(a|b|c)(e|f)", r2 = "(c|h|m)(q|e)" ,m = "ae";
	SRegex reg(r1);
	REQUIRE(reg.regex_traversal (r2, m) == false);
	m = "ce";
	REQUIRE(reg.regex_traversal (r2, m) == true);
}
