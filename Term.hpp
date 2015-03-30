/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Term.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchoong <mchoong@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/30 12:41:40 by mchoong           #+#    #+#             */
/*   Updated: 2015/03/30 19:33:37 by mchoong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TERM_HPP
# define TERM_HPP

class Term {

private:
	Term(void);
	int			degree;
	double		multiplier;

public:
	Term(double, int);
	virtual ~Term(void);
	Term(Term const &);
	Term & operator=(Term const &);

	int				getDegree(void) const;
	double			getMultiplier(void) const;
	void			addMultiplier(double m);
};

#endif
