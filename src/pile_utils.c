/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pile_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emarin <emarin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/18 20:23:43 by emarin            #+#    #+#             */
/*   Updated: 2018/01/19 16:20:27 by emarin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_push_swap.h"

int		ft_pile_len(t_pile *pile)
{
	int	i;

	i = 0;
	while (pile)
	{
		++i;
		pile = pile->next;
	}
	return (i);
}

char	best_path(t_pile *pile, int min)
{
	int	pos;
	int	len;

	len = ft_pile_len(pile);
	pos = 1;
	while (pile && pile->content != min)
	{
		pile = pile->next;
		++pos;
	}
	return (pos < (len / 2));
}

void	ft_get_min(t_pile *pile, int *min)
{
	while (pile)
	{
		if (!min[0] || min[1] > pile->content)
		{
			min[0] = 1;
			min[1] = pile->content;
		}
		pile = pile->next;
	}
}

void	ft_get_max(t_pile *pile, int *max)
{
	while (pile)
	{
		if (!max[0] || max[1] < pile->content)
		{
			max[0] = 1;
			max[1] = pile->content;
		}
		pile = pile->next;
	}
}

int		ft_get_last(t_pile *pile)
{
	int	res;

	res = 0;
	while (pile)
	{
		res = pile->content;
		pile = pile->next;
	}
	return (res);
}
