/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchoong <mchoong@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/05 15:11:34 by mchoong           #+#    #+#             */
/*   Updated: 2015/03/30 18:15:21 by mchoong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "computorv1.hpp"
#include "LexicalException.hpp"
#include "SyntaxException.hpp"
#include "Lexer.hpp"

void		ft_usage(void)
{
	std::cout << "usage: ./computorv1 \"expression\"" << std::endl;
	exit(0);
}

int			main(int argc, char **argv)
{
	if (argc != 2)
		ft_usage();
	try {
		Lexer l = Lexer(argv[1]);
	}
	catch (LexicalException e) {
		std::cerr << e.what() << std::endl;
		exit(1);
	}
	catch (SyntaxException e) {
		std::cerr << e.what() << std::endl;
		exit(1);
	}
	return 0;
}
