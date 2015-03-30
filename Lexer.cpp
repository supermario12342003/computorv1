/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Lexer.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchoong <mchoong@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/02 18:51:36 by mchoong           #+#    #+#             */
/*   Updated: 2015/03/30 19:44:22 by mchoong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <sstream>
#include "Lexer.hpp"
#include "Token.hpp"
#include "Type.hpp"
#include "LexicalException.hpp"
#include "SyntaxException.hpp"

Lexer::Lexer(void)
{
}

Lexer::Lexer(std::string const & str)
{
	this->lex(str);
	this->parse();
	this->makeTermList();
	for (Term *t : termList)
	{
		std::cout << t->getMultiplier()
					<< " * "
					<< " X ^ "
					<< t->getDegree()
					<< std::endl;
	}
}

void	Lexer::insertTerm(double multiplier, double degree)
{
	int		d;

	d = static_cast<int>(degree);
	if (static_cast<double>(d) != degree)
		throw SyntaxException("power must be in integer");
	for (Term *t : termList)
	{
		if (t->getDegree() == d)
		{
			t->addMultiplier(multiplier);
			return ;
		}
	}
	termList.push_back(new Term(multiplier, d));
}

void	Lexer::makeTermList(void)
{
	double		multiplier;
	double		degree;
	int			termType;
	int			negate;

	multiplier = 1;
	degree = 0;
	termType = 0;
	negate = 1;
	for(Token * t : tokenList)
	{
		std::cout << multiplier << " " << degree << std::endl;
		if (t->getType() == NUMBER)
		{
			if (termType == 0)
				multiplier = std::stod(t->getStr());
			else
				degree = std::stod(t->getStr());
		}
		else
		{
			if (t->getStr().compare("*") != 0)
			{
				insertTerm(negate * multiplier, degree);
				if (t->getStr().compare("^") == 0)
					termType = 1;
				else
					termType = 0;
				if (t->getStr().compare("=") == 0)
					negate = -1;
				multiplier = 1;
				degree = 0;
			}
		}
	}
	return ;
}

void	Lexer::parse(void)
{
	std::list<Token *>::iterator it = tokenList.begin();
	int			expected[2] = {NUMBER|VARIABLE, OPERATOR};
	int			i;
	int			number_of_equality_sign;

	i = 0;
	number_of_equality_sign = 0;
	while (it != tokenList.end())
	{
		if ((*it)->getStr().compare("=") == 0)
			number_of_equality_sign++;
		if (((*it)->getType() & expected[i]) != (*it)->getType())
			throw SyntaxException((*it)->getStr());
		else
			i = (i + 1) % 2;
		it++;
	}
	if (number_of_equality_sign != 1)
		throw SyntaxException("Invalid number of equality sign");
}

void	Lexer::lex(std::string const & str)
{
	std::string		whitespace_chars(" \t\r\n");
	std::string		number_chars("1234567890.");
	std::string		operator_chars("+-*^=");
	std::string		number;

	number = std::string("");
	for(const char & c : str)
	{
		if (number_chars.find(c) != std::string::npos)
		{
			number += c;
			continue ;
		}
		else
		{
			if (number.compare("") != 0)
			{
				if (!this->isValidNumber(number))
					throw LexicalException(number);
				tokenList.push_back(new Token(number, NUMBER));
				number = std::string("");
			}
			if (operator_chars.find(c) != std::string::npos)
				tokenList.push_back(new Token(std::string(1, c), OPERATOR));
			else if (c == 'X')
				tokenList.push_back(new Token(std::string(1, 'X'), VARIABLE));
			else if (whitespace_chars.find(c) == std::string::npos)
				throw LexicalException(&c);
		}
	}
	if (number.compare("") != 0)
		tokenList.push_back(new Token(number, NUMBER));
	this->str = str;
}

bool Lexer::isValidNumber(std::string const & number)
{
	std::istringstream iss(number);
	float f;

	iss >> std::noskipws >> f;
	return (iss.eof() && !iss.fail());
}

Lexer::~Lexer(void)
{
}

Lexer::Lexer(Lexer const & src)
{
	*this = src;
}

Lexer & Lexer::operator=(Lexer const & rhs)
{
	this->str = rhs.str;
	return *this;
}
