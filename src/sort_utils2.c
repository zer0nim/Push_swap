/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_utils2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emarin <emarin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/16 12:07:45 by emarin            #+#    #+#             */
/*   Updated: 2018/01/19 16:08:24 by emarin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_push_swap.h"

t_pile			*ft_cop_pile(t_pile *pile)
{
	t_pile	*cop;

	cop = NULL;
	while (pile)
	{
		ft_pile_cop_to(&pile, &cop);
		pile = pile->next;
	}
	return (cop);
}

char			best_rot(t_pile *pile, int *up_dw)
{
	int		pos;
	int		len;
	t_pile	*cop;

	len = ft_pile_len(pile);
	cop = ft_cop_pile(pile);
	pos = 0;
	if (up_dw[2])
	{
		while (pos < len && cop->content != up_dw[3])
		{
			ft_pile_rot(&cop, 0);
			++pos;
		}
	}
	else if (up_dw[0])
	{
		while (pos < len && ft_get_last(cop) != up_dw[1])
		{
			ft_pile_rot(&cop, 0);
			++pos;
		}
	}
	ft_pile_free(cop);
	return (pos < (len / 2) + (len % 2 != 0));
}

char			best_rot_last(t_pile *pile, int *up_dw)
{
	int		pos;
	int		len;
	t_pile	*cop;

	len = ft_pile_len(pile);
	cop = ft_cop_pile(pile);
	pos = 0;
	if (up_dw[2])
	{
		while (pos < len && ft_get_last(cop) != up_dw[3])
		{
			ft_pile_rot(&cop, 0);
			++pos;
		}
	}
	else if (up_dw[0])
	{
		while (pos < len && cop->content != up_dw[1])
		{
			ft_pile_rot(&cop, 0);
			++pos;
		}
	}
	ft_pile_free(cop);
	return (pos < (len / 2) + (len % 2 != 0));
}

void			ft_reorder(t_pile **pile, char state)
{
	int	max[2];
	int	up_dw[4];

	max[0] = 0;
	ft_get_max(*pile, max);
	if (max[0])
	{
		up_dw[0] = 0;
		up_dw[2] = 1;
		up_dw[3] = max[1];
		if (best_rot(*pile, up_dw))
			while ((*pile)->content != up_dw[3])
				ft_pile_rot(pile, state);
		else
			while ((*pile)->content != up_dw[3])
				ft_pile_rot_down(pile, state);
	}
}

void			ft_reorder_last(t_pile **pile, char state)
{
	int	min[2];
	int	up_dw[4];

	min[0] = 0;
	ft_get_min(*pile, min);
	if (min[0])
	{
		up_dw[0] = 0;
		up_dw[2] = 1;
		up_dw[3] = min[1];
		if (best_rot(*pile, up_dw))
			while ((*pile)->content != up_dw[3])
				ft_pile_rot(pile, state);
		else
			while ((*pile)->content != up_dw[3])
				ft_pile_rot_down(pile, state);
	}
}
