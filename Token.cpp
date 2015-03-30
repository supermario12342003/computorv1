/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Token.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchoong <mchoong@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/02 18:51:36 by mchoong           #+#    #+#             */
/*   Updated: 2015/03/30 17:43:15 by mchoong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Token.hpp"

Token::Token(void)
{
}

Token::Token(std::string const & str, eTokenType type)
{
	this->str = str;
	this->type = type;
}

Token::~Token(void)
{
}

Token::Token(Token const & src)
{
	*this = src;
}

Token & Token::operator=(Token const & rhs)
{
	this->str = rhs.str;
	this->type = rhs.type;
	return *this;
}

std::string		Token::getStr(void) const
{
	return this->str;
}

eTokenType		Token::getType(void) const
{
	return this->type;
}
