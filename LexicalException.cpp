/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   LexicalException.cpp                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchoong <mchoong@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/05 15:48:06 by mchoong           #+#    #+#             */
/*   Updated: 2015/03/30 19:44:22 by mchoong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "LexicalException.hpp"
#include <iostream>
#include <sstream>

LexicalException::LexicalException(void) throw(): GeneralException()
{
	this->message = std::string("Lexical Error");
}

LexicalException::LexicalException(std::string const & s)
throw(): GeneralException()
{
	std::stringstream ss;
	ss << "[..." << s << "] : Lexical Error" << std::endl;
	ss << "known characters = \"1234567890.+-*/=^X\"";
	this->message = ss.str();
}

LexicalException::~LexicalException(void) throw()
{
}
