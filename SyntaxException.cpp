/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   SyntaxException.cpp                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchoong <mchoong@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/05 15:48:06 by mchoong           #+#    #+#             */
/*   Updated: 2015/03/30 18:53:05 by mchoong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "SyntaxException.hpp"
#include <iostream>
#include <sstream>

SyntaxException::SyntaxException(void) throw(): GeneralException()
{
	this->message = std::string("Syntax Error");
}

SyntaxException::SyntaxException(std::string const & s)
throw(): GeneralException()
{
	std::stringstream ss;
	ss << "[..." << s << "] : Syntax Error";
	this->message = ss.str();
}

SyntaxException::~SyntaxException(void) throw()
{
}
