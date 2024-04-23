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
	        reg = new SRegex("ab{0,0}c");
	        m = "abc";
	        REQUIRE(reg->match(m) == false);
	        delete reg;
	        reg = new SRegex("ab{1,1}c");
	        m = "abc";
			REQUIRE(reg->match(m) == true);
			delete reg;
	        reg = new SRegex("ab{0,1}c");
	        m = "abc";
	        REQUIRE(reg->match(m) == true);
	        delete reg;
	        reg = new SRegex("ab{0,1}c");
	        m = "ac";
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
	        reg = new SRegex("b{2,2}+");
	        m = "bb";
	        REQUIRE(reg->match(m) == true);
			m = "b";
			REQUIRE(reg->match(m) == false);
	        m = "bbb";
	        REQUIRE(reg->match(m) == false);
	        m = "bbbb";
	        REQUIRE(reg->match(m) == true);
	        delete reg;
	}


	SECTION("capture groups")
	{
		std::string in = "jrw(1:bwjerg)tu(2:dkjgb)(3:ogo, it's over)", m = "jrwbwjergtudkjgbogo, it's over";
		SRegex *reg = new SRegex(in);
		REQUIRE(reg->match(m) == true);
		//m = "kakaya to hren";
		//REQUIRE(reg->match(m) == false);
		std::cout << reg->m[0] << "\n";
		REQUIRE(reg->m[1] == "bwjerg");
                REQUIRE(reg->m[2] == "dkjgb");
                REQUIRE(reg->m[3] == "ogo, it's over");
		delete reg;
                reg = new SRegex("((1:ab)|(2:ac))");
		REQUIRE(reg->match("ab") == true);
		REQUIRE(reg->m[1] == "ab");
		REQUIRE(reg->m[2].size() == 0);
		delete reg;
		reg = new SRegex("cef(1:ab+)b");
		REQUIRE(reg->match("cefabbbb") == true);
		REQUIRE(reg->m[1] == "abbb");
		reg = new SRegex("((ab)|(1:ac))");
		REQUIRE(reg->match("ac") == true);
		REQUIRE(reg->m[1] == "ac");
		REQUIRE(reg->match("ab") == true);
		REQUIRE(reg->m[1].size() == 0);
		delete reg;
		reg = new SRegex("b(1:baa)+a");
		REQUIRE(reg->match("bbaabaaa") == true);
		REQUIRE(reg->m[1]=="baabaa");
		reg = new SRegex("ac(1:ab|ac)ab");
		REQUIRE(reg->match("acabab") == true);
		REQUIRE(reg->m[1]=="ab");
		REQUIRE(reg->match("acacab") == true);
		REQUIRE(reg->m[1]=="ac");
		delete reg;
		reg = new SRegex("a+(1:a+)a+");
		REQUIRE(reg->match("aaaaaaaa") == true);
		std::cout << reg->m[1] << "\n";
		reg = new SRegex("(1:a|b)(2:a|b)(3:a|b)");
		delete reg;
		reg = new SRegex("(a|b)|(a|b)|(a|b)");
		reg->d->minimize_DFA();
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
		SRegex reg3("(a|^)b");
		m = "ab";
		REQUIRE(reg3.match(m) == true);
		REQUIRE(reg3.match("b") == true);
		SRegex reg4("a^+b");
		REQUIRE(reg4.match("ab") == true);
	}
}

TEST_CASE("K-path")
{
	std::string in = "a(b|c)(d|m)", m = "acd";
	SRegex *reg = new SRegex(in);
	REQUIRE(reg->match(m) == true);
	SRegex *restore_reg = new SRegex(reg->restore_regex());
	REQUIRE(restore_reg->match(m) == true);
	delete reg;
	delete restore_reg;
	reg = new SRegex("abc");
	REQUIRE(reg->match("abc"));
	restore_reg = new SRegex(reg->restore_regex());
	REQUIRE(restore_reg->match("abc") == true);
	delete reg;
	delete restore_reg;
	reg = new SRegex("abcd");
	REQUIRE(!reg->match("abc"));
	restore_reg = new SRegex(reg->restore_regex());
	REQUIRE(restore_reg->match("abc") == false);
	delete reg;
	delete restore_reg;
	reg = new SRegex("#((expelled)#)");
	REQUIRE(reg->match("(expelled)"));
	restore_reg = new SRegex(reg->restore_regex());
	REQUIRE(restore_reg->match("(expelled)") == true);
	delete reg;
	delete restore_reg;
	reg = new SRegex("(abc)+");
	REQUIRE(reg->match("abcabcabcabcabc"));
	restore_reg = new SRegex(reg->restore_regex());
	REQUIRE(restore_reg->match("abcabcabcabcabc") == true);
	delete reg;
	delete restore_reg;
	reg = new SRegex("h++");
	REQUIRE(reg->match("hhhh"));
	restore_reg = new SRegex(reg->restore_regex());
	REQUIRE(restore_reg->match("hhhh") == true);
	delete restore_reg;
	REQUIRE(reg->match("h"));
	restore_reg = new SRegex(reg->restore_regex());
	REQUIRE(restore_reg->match("h") == true);
	delete reg;
	delete restore_reg;
	reg = new SRegex("a|b");
	REQUIRE(reg->match("a"));
	restore_reg = new SRegex(reg->restore_regex());
	REQUIRE(restore_reg->match("a") == true);
	delete restore_reg;
	REQUIRE(reg->match("b"));
	restore_reg = new SRegex(reg->restore_regex());
	REQUIRE(restore_reg->match("b") == true);
	delete reg;
	delete restore_reg;
	reg = new SRegex("(a|b)|c+");
	REQUIRE(reg->match("a"));
	restore_reg = new SRegex(reg->restore_regex());
	REQUIRE(restore_reg->match("a") == true);
	delete restore_reg;
	REQUIRE(reg->match("b"));
	restore_reg = new SRegex(reg->restore_regex());
	REQUIRE(restore_reg->match("b") == true);
	delete restore_reg;
	REQUIRE(reg->match("ccccccc"));
	restore_reg = new SRegex(reg->restore_regex());
	REQUIRE(restore_reg->match("ccccccc") == true);
	delete reg;
	delete restore_reg;
	reg = new SRegex("(a|b)+");
	REQUIRE(reg->match("abababab"));
	restore_reg = new SRegex(reg->restore_regex());
	REQUIRE(restore_reg->match("abababab") == true);
	delete reg;
	delete restore_reg;
	reg = new SRegex("g(abc)+");
	REQUIRE(reg->match("gabcabcabcabc"));
	restore_reg = new SRegex(reg->restore_regex());
	REQUIRE(restore_reg->match("gabcabcabcabc") == true);
	delete reg;
	delete restore_reg;
	reg = new SRegex("(abc)+t");
	REQUIRE(reg->match("abcabct"));
	restore_reg = new SRegex(reg->restore_regex());
	REQUIRE(restore_reg->match("abcabct") == true);
	delete reg;
	delete restore_reg;
	reg = new SRegex("ab{0,0}c");
	REQUIRE(reg->match("ac"));
	restore_reg = new SRegex(reg->restore_regex());
	REQUIRE(restore_reg->match("ac") == true);
	delete reg;
	delete restore_reg;
	reg = new SRegex("ab{0,0}c");
	REQUIRE(!reg->match("abc"));
	restore_reg = new SRegex(reg->restore_regex());
	REQUIRE(restore_reg->match("abc") == false);
	delete reg;
	delete restore_reg;
	reg = new SRegex("ab{1,1}c");
	REQUIRE(reg->match("abc"));
	restore_reg = new SRegex(reg->restore_regex());
	REQUIRE(restore_reg->match("abc") == true);
	delete reg;
	delete restore_reg;
	reg = new SRegex("ab{0,1}c");
	REQUIRE(reg->match("abc"));
	restore_reg = new SRegex(reg->restore_regex());
	REQUIRE(restore_reg->match("abc") == true);
	delete reg;
	delete restore_reg;
	reg = new SRegex("ab{0,1}c");
	REQUIRE(reg->match("ac"));
	restore_reg = new SRegex(reg->restore_regex());
	REQUIRE(restore_reg->match("ac") == true);
	delete reg;
	delete restore_reg;
	reg = new SRegex("b{0,1}+");
	REQUIRE(reg->match("b"));
	restore_reg = new SRegex(reg->restore_regex());
	REQUIRE(restore_reg->match("b") == true);
	delete reg;
	delete restore_reg;
	reg = new SRegex("b{0,1}+");
	REQUIRE(reg->match(""));
	restore_reg = new SRegex(reg->restore_regex());
	REQUIRE(restore_reg->match("") == true);
	delete reg;
	delete restore_reg;
	reg = new SRegex("b{0,1}+");
	REQUIRE(reg->match("bb"));
	restore_reg = new SRegex(reg->restore_regex());
	REQUIRE(restore_reg->match("bb") == true);
	delete reg;
	delete restore_reg;
	reg = new SRegex("b{2,2}+");
	REQUIRE(reg->match("bb"));
	restore_reg = new SRegex(reg->restore_regex());
	REQUIRE(restore_reg->match("bb") == true);
	delete reg;
	delete restore_reg;
	reg = new SRegex("b{2,2}+");
	REQUIRE(reg->match("bbbb"));
	restore_reg = new SRegex(reg->restore_regex());
	REQUIRE(restore_reg->match("bbbb") == true);
	delete reg;
	delete restore_reg;
	reg = new SRegex("b{2,2}+");
	REQUIRE(!reg->match("b"));
	restore_reg = new SRegex(reg->restore_regex());
	REQUIRE(restore_reg->match("b") == false);
	delete reg;
	delete restore_reg;
	reg = new SRegex("b{2,2}+");
	REQUIRE(!reg->match("bbb"));
	restore_reg = new SRegex(reg->restore_regex());
	REQUIRE(restore_reg->match("bbb") == false);
	delete reg;
	delete restore_reg;
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

// TEST_CASE("minimization")
// {
// 	SRegex reg("(a|a|a|a)b");
// 	reg.d->minimize_DFA();
// }


