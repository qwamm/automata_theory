#define CATCH_CONFIG_MAIN
#include <catch2/catch.hpp>
#include "/home/qurst/automata_theory/lab2/regex_lib.hpp"

TEST_CASE("strings")
{
	SECTION("usual string")
	{
		std::string m = "abc";
		SRegex *reg = new SRegex("abc");
		REQUIRE(reg->match(m));
		delete reg;
		reg = new SRegex("abcd");
		REQUIRE(!reg->match(m));
		delete reg;
		m = "iufs";
                reg = new SRegex("abcd");
                REQUIRE(!reg->match(m));
		delete reg;
	}

	SECTION("string with metacharacters escaping")
	{
		std::string in = "#(expelled#)", m = "(expelled)", m2 = "not?";
		SRegex *reg = new SRegex(in);
		REQUIRE(reg->match(m) == true);
		REQUIRE(reg->match(m2) == false);
		delete reg;
		reg = new SRegex("#((expelled)#)");
		REQUIRE(reg->match(m) == true);
		delete reg;
	}

	SECTION("just some strings")
	{
		std::string in = "mephi|ms(u+)", m = "mephi";
		SRegex *reg = new SRegex("n+");
		m = "nnnnn";
		REQUIRE(reg->match(m) == true);
		delete reg;
		reg = new SRegex("(abc)+");
		m = "abcabcabcabcabc";
		REQUIRE(reg->match(m) == true);
		delete reg;
                reg = new SRegex("(abc)+");
                m = "abc";
                REQUIRE(reg->match(m) == true);
                delete reg;
                reg = new SRegex("h++");
                m = "hhhh";
                REQUIRE(reg->match(m) == true);
                delete reg;
                reg = new SRegex("h++");
                m = "h";
                REQUIRE(reg->match(m) == true);
                delete reg;
                reg = new SRegex("a|b");
                m = "a";
                REQUIRE(reg->match(m) == true);
                delete reg;
                reg = new SRegex("a|b");
                m = "b";
                REQUIRE(reg->match(m) == true);
                delete reg;
                reg = new SRegex("a|a");
                m = "a";
                REQUIRE(reg->match(m) == true);
                delete reg;
                reg = new SRegex("(a|b)|c+");
                m = "a";
                REQUIRE(reg->match(m) == true);
                delete reg;
                reg = new SRegex("(a|b)|c+");
                m = "b";
                REQUIRE(reg->match(m) == true);
                delete reg;
                reg = new SRegex("(a|b)|c+");
                m = "ccccccc";
                REQUIRE(reg->match(m) == true);
                delete reg;
                reg = new SRegex("(a|b)+");
                m = "abababab";
                REQUIRE(reg->match(m) == true);
                delete reg;
		 reg = new SRegex("g(abc)+");
                m = "gabcabcabcabc";
                REQUIRE(reg->match(m) == true);
                 reg = new SRegex("(abc)+t");
                m = "abcabct";
                REQUIRE(reg->match(m) == true);
		m = "mephi";
		reg = new SRegex(in);
		REQUIRE(reg->match(m) == true);
		m = "ms";
		REQUIRE(reg->match(m) == false);
		m = "msuuuuuu";
		REQUIRE(reg->match(m) == true);
		m = "mephi";
		REQUIRE(reg->match(m) == true);
		m = "mephidron";
		REQUIRE(reg->match(m) == false);
	}

	SECTION ("{}")
	{
		std::string in = "(#|#.#|){3,5}", m = "|.|";
		SRegex *reg = new SRegex(in);
		REQUIRE(reg->match(m) == false);
		m = "|.||.|";
		REQUIRE(reg->match(m) == false);
		m = "|.||.||.|";
		REQUIRE(reg->match(m) == true);
                m = "|.||.||.||.|";
                REQUIRE(reg->match(m) == true);
                m = "|.||.||.||.||.|";
                REQUIRE(reg->match(m) == true);
                m = "|.||.||.||.||.||.|";
                REQUIRE(reg->match(m) == false);
		delete reg;
		reg = new SRegex("ab{0,0}c");
		m = "ac";
		REQUIRE(reg->match(m) == true);
		delete reg;
                /*reg = new SRegex("ab{1,1}c");
                m = "abc";
		REQUIRE(reg->match(m) == true);
		delete reg;
                reg = new SRegex("ab{0,1}c");
                m = "abc";
                REQUIRE(reg->match(m) == true);
                delete reg;
                reg = new SRegex("ab{0,1}c");
                m = "ab";
                REQUIRE(reg->match(m) == true);
                delete reg;
                reg = new SRegex("b{0,1}+");
                m = "b";
                REQUIRE(reg->match(m) == true);
                delete reg;
                reg = new SRegex("b{0,1}+");
                m = "";
                REQUIRE(reg->match(m) == true);
                delete reg;
                reg = new SRegex("b{0,1}+");
                m = "bb";
                REQUIRE(reg->match(m) == true);
                delete reg;
                reg = new SRegex("ab{0,1}c");
                m = "abc";
                REQUIRE(reg->match(m) == true);
                delete reg; */
	}

}
/*	SECTION("capture groups")
	{
		std::string in = "jrw(1:bwjerg)tu(2:dkjgb)(3:ogo, it's over)", m = "jrwbwjergtudkjgbogo, it's over";
		SRegex *reg = new SRegex(in);
		REQUIRE(reg->match(m) == true);
		m = "kakaya to hren";
		REQUIRE(reg->match(m) == false);
		reg->set_capture_groups();
		REQUIRE(reg->m[1] == "b.w.j.e.r.g");
                REQUIRE(reg->m[2] == "d.k.j.g.b");
                REQUIRE(reg->m[3] == "o.g.o.,. .i.t.'.s. .o.v.e.r");
		delete reg;
                reg = new SRegex("((1:ab)|(2:ac))");
		m = "ab";
		REQUIRE(reg->match(m) == true);
		reg->set_capture_groups();
		REQUIRE(reg->m[1] == "a.b");
		REQUIRE(reg->m[2] == "a.c");
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

*/
