/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emarin <emarin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/15 12:03:31 by emarin            #+#    #+#             */
/*   Updated: 2018/01/17 14:50:48 by emarin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_push_swap.h"

static	char	ft_as_double(int nb, t_pile *a)
{
	while (a && a->content != nb)
		a = a->next;
	return (a != NULL);
}

int				init_pile(t_pile **a, int argc, char **argv)
{
	t_pile	*tmp;
	int		nb;

	*a = NULL;
	while (--argc > 0)
	{
		nb = ft_atoi(argv[argc]);
		if (ft_bad_arg(argv[argc]) || ft_as_double(nb, *a))
			return (0);
		if (*a)
		{
			if (!(tmp = ft_pile_new(nb)))
				return (0);
			ft_pile_push(a, tmp);
		}
		else if (!(*a = ft_pile_new(nb)))
			return (0);
	}
	return (1);
}
