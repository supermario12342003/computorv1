/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   LexicalException.hpp                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchoong <mchoong@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/30 12:38:50 by mchoong           #+#    #+#             */
/*   Updated: 2015/03/30 12:51:29 by mchoong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LEXICALEXCEPTION_HPP
# define LEXICALEXCEPTION_HPP

#include <iostream>
#include "GeneralException.hpp"

class LexicalException: public GeneralException {

public:
	LexicalException(void) throw();
	LexicalException(std::string const &) throw();
	virtual ~LexicalException(void) throw();

};

#endif
