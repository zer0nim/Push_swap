/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_push_swap.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emarin <emarin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/12 10:59:53 by emarin            #+#    #+#             */
/*   Updated: 2018/01/30 14:54:16 by emarin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_push_swap.h"

static	char	ft_pile_check(t_pile *pile, int len)
{
	char	first;
	int		tmp;

	first = 1;
	tmp = 0;
	while (pile && (first || tmp < pile->content))
	{
		first = 0;
		tmp = pile->content;
		pile = pile->next;
		--len;
	}
	if (!pile && len == 0)
		return (1);
	return (0);
}

int				main(int argc, char **argv)
{
	t_pile	*a;
	t_pile	*b;

	if (argc > 1)
	{
		if (!(init_pile(&a, argc, argv)))
			return (ft_er());
		if (ft_pile_check(a, ft_pile_len(a)))
			return (0);
		b = NULL;
		ft_merge_sort(&a, &b, ft_pile_len(a), 4);
	}
	return (0);
}
