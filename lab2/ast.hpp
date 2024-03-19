#include <iostream>

class Expression
{
	public:
		virtual ~Expression() {}
		virtual Expression *clone() = 0;
		virtual std::string value () = 0;
};

class Disjunction : public Expression
{
	private:
		Expression *m_left, *m_right;
	public:
		Disjunction (Expression *left, Expression *right): m_left (left), m_right (right) {}
		Disjunction (const Disjunction &other) {
    				m_left = other.m_left->clone ();
    				m_right = other.m_right->clone ();
  		}
		virtual ~Disjunction ()
		{
			delete m_left;
			delete m_right;
		}
		Expression *clone() override
		{
			return new Disjunction(*this);
		}
		std::string value() override
		{
			return m_left->value() + m_right->value();
		}
};

class Symbol : public Expression
{
	private:
		std::string m_val;
	public:
		Symbol (std::string val): m_val (val) {}
		Symbol (const Symbol &other) { m_val = other.m_val; }
		Expression *clone() override {return new Symbol(*this);}
		std::string value() override {return m_val;}
};

