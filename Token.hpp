/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Token.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchoong <mchoong@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/30 12:41:40 by mchoong           #+#    #+#             */
/*   Updated: 2015/03/30 17:16:05 by mchoong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TOKEN_HPP
# define TOKEN_HPP

#include <iostream>
#include "Type.hpp"

class Token {

private:
	Token(void);
	std::string		str;
	eTokenType		type;

public:
	Token(std::string const &, eTokenType type);
	virtual ~Token(void);
	Token(Token const &);
	Token & operator=(Token const &);

	std::string		getStr(void) const;
	eTokenType		getType(void) const;
};

#endif
