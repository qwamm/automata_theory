#include <iostream>
#include <chrono>
#include <unordered_map>
#include <FlexLexer.h>
#ifndef REC_HPP
#define REC_HPP
#include "../rec.hpp"
#endif
enum State {DEFAULT, TYPE, SPACESHIP, FUNC_NAME, LEFT_PARENT, PARAM_NAME, COMMA, RIGHT_PARENT, SEMICOLON, ERROR};

class Flex_Recognizer : public Recognizer
{
	private:
		State Current_State;
	public:
		bool is_parameter;
		Flex_Recognizer()
		{
			Current_State = State::DEFAULT;
			is_parameter = false;
		}
		~Flex_Recognizer() = default;
		bool check_string(std::string s, std::string *fname) override;
		void setState(State s)
		{
			Current_State = s;
		}
		State getState()
		{
			return Current_State;
		}
		void Spaceship()
		{
			if (Current_State == TYPE)
			{
				Current_State = State::SPACESHIP;
			}
			else
			{
				Current_State = State::ERROR;
			}
		}
		void FunctionName()
		{
			if (Current_State == State::SPACESHIP)
			{
				Current_State = State::FUNC_NAME;
			}
                        else
                        {
                                Current_State = State::ERROR;
                        }
		}
		void LeftParent()
		{
                        if (Current_State == State::FUNC_NAME)
                        {
                                Current_State = State::LEFT_PARENT;
				is_parameter = true;
                        }
                        else
                        {
                                Current_State = State::ERROR;
                        }
		}
		void Type()
		{
                        if (Current_State == State::DEFAULT || Current_State == State::LEFT_PARENT || Current_State == State::COMMA)
                        {
                                Current_State = State::TYPE;
                        }
                        else
                        {
                                Current_State = State::ERROR;
                        }
		}
		void ParameterName()
		{
			if (Current_State == State::SPACESHIP)
			{
				Current_State = State::PARAM_NAME;
			}
                        else
                        {
                                Current_State = State::ERROR;
                        }
		}
		void Comma()
		{
                        if (Current_State == State::PARAM_NAME)
                        {
                                Current_State = State::COMMA;
                        }
                        else
                        {
                                Current_State = State::ERROR;
                        }
		}
		void RightParent()
		{
                        if (Current_State == State::PARAM_NAME || Current_State == State::LEFT_PARENT)
                        {
                                Current_State = State::RIGHT_PARENT;
				is_parameter = false;
                        }
                        else
                        {
                                Current_State = State::ERROR;
                        }
		}
		void Semicolon()
		{
			if (Current_State == State::RIGHT_PARENT)
			{
				Current_State = State::SEMICOLON;
			}
			else
			{
				Current_State = State::ERROR;
			}
		}
};
