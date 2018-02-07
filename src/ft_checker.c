/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_checker.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emarin <emarin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/12 10:57:05 by emarin            #+#    #+#             */
/*   Updated: 2018/01/30 11:20:09 by emarin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_push_swap.h"

static	char	do_op(t_pile **a, t_pile **b, char *op)
{
	char	ok;

	ok = 0;
	if ((!ft_strcmp(op, "sa") || !ft_strcmp(op, "ss")) && (ok = 1))
		ft_pile_swp(a, 0);
	if ((!ft_strcmp(op, "sb") || !ft_strcmp(op, "ss")) && (ok = 1))
		ft_pile_swp(b, 0);
	if (!ft_strcmp(op, "pa") && (ok = 1))
		ft_pile_push_to(b, a, 0);
	if (!ft_strcmp(op, "pb") && (ok = 1))
		ft_pile_push_to(a, b, 0);
	if ((!ft_strcmp(op, "ra") || !ft_strcmp(op, "rr")) && (ok = 1))
		ft_pile_rot(a, 0);
	if ((!ft_strcmp(op, "rb") || !ft_strcmp(op, "rr")) && (ok = 1))
		ft_pile_rot(b, 0);
	if ((!ft_strcmp(op, "rra") || !ft_strcmp(op, "rrr")) && (ok = 1))
		ft_pile_rot_down(a, 0);
	if ((!ft_strcmp(op, "rrb") || !ft_strcmp(op, "rrr")) && (ok = 1))
		ft_pile_rot_down(b, 0);
	return ((!ok) ? 0 : 1);
}

static	void	ft_pile_check(t_pile *pile, int len)
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
		ft_putstr("OK\n");
	else
		ft_putstr("KO\n");
}

int				main(int argc, char **argv)
{
	char	*order;
	t_pile	*a;
	t_pile	*b;
	int		len;

	if (argc > 1)
	{
		if (!(init_pile(&a, argc, argv)))
			return (ft_er());
		len = ft_pile_len(a);
		while (ft_get_next_line(STDIN_FILENO, &order))
		{
			if (!do_op(&a, &b, order))
				return (ft_er());
			free(order);
		}
		ft_pile_check(a, len);
		ft_pile_free(a);
	}
	return (0);
}
