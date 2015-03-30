/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   GeneralException.hpp                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchoong <mchoong@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/05 15:21:31 by mchoong           #+#    #+#             */
/*   Updated: 2015/02/05 15:44:36 by mchoong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GENERALEXCEPTION_HPP
# define GENERALEXCEPTION_HPP

#include <iostream>
#include <exception>

class GeneralException: public std::exception {

public:
	GeneralException(void) throw();
	GeneralException(std::string const &) throw();
	virtual ~GeneralException(void) throw();
	GeneralException(GeneralException const &) throw();
	GeneralException &		operator=(GeneralException const &) throw();
	virtual const char *	what(void) const throw();

protected:
	std::string message;

};

#endif
