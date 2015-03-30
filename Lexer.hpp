/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Lexer.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchoong <mchoong@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/30 12:41:40 by mchoong           #+#    #+#             */
/*   Updated: 2015/03/30 19:30:41 by mchoong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LEXER_HPP
# define LEXER_HPP

#include <iostream>
#include <list>
#include "Token.hpp"
#include "Term.hpp"

class Lexer {

private:
	Lexer(void);
	std::string					str;
	bool						isValidNumber(std::string const &);
	std::list<Token *>			tokenList;
	std::list<Term *>			termList;
	void						makeTermList(void);
	void						lex(std::string const & str);
	void						parse(void);
	void						insertTerm(double multiplier, double degree);

public:
	Lexer(std::string const &);
	virtual ~Lexer(void);
	Lexer(Lexer const &);
	Lexer & operator=(Lexer const &);
};

#endif
