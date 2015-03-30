/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Term.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchoong <mchoong@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/02 18:51:36 by mchoong           #+#    #+#             */
/*   Updated: 2015/03/30 19:32:17 by mchoong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Term.hpp"

Term::Term(void)
{
}

Term::Term(double multiplier, int degree)
{
	this->degree = degree;
	this->multiplier = multiplier;
}

Term::~Term(void)
{
}

Term::Term(Term const & src)
{
	*this = src;
}

Term & Term::operator=(Term const & rhs)
{
	this->degree = rhs.degree;
	this->multiplier = rhs.multiplier;
	return *this;
}

int				Term::getDegree(void) const
{
	return this->degree;
}

double			Term::getMultiplier(void) const
{
	return this->multiplier;
}

void			Term::addMultiplier(double m)
{
	this->multiplier += m;
}
