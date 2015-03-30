/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   SyntaxException.hpp                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchoong <mchoong@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/30 12:38:50 by mchoong           #+#    #+#             */
/*   Updated: 2015/03/30 17:58:35 by mchoong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SYNTAXEXCEPTION_HPP
# define SYNTAXEXCEPTION_HPP

#include <iostream>
#include "GeneralException.hpp"

class SyntaxException: public GeneralException {

public:
	SyntaxException(void) throw();
	SyntaxException(std::string const &) throw();
	virtual ~SyntaxException(void) throw();

};

#endif
