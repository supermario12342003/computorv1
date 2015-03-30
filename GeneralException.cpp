/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   GeneralException.cpp                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchoong <mchoong@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/05 15:38:42 by mchoong           #+#    #+#             */
/*   Updated: 2015/02/05 15:44:53 by mchoong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "GeneralException.hpp"
#include <iostream>
#include <exception>

GeneralException::GeneralException(void) throw() :
std::exception()
{
	this->message = std::string("Unknown error");
}

GeneralException::GeneralException(std::string const & message) throw() :
std::exception()
{
	this->message = message;
}

GeneralException::GeneralException(
GeneralException const & src) throw()
{
	*this = src;
}

GeneralException::~GeneralException(void) throw()
{
}

GeneralException & GeneralException::operator=(
GeneralException const & target) throw()
{
	this->message = target.message;
	return *this;
}

const char *		GeneralException::what(void) const throw()
{
	return this->message.c_str();
}
