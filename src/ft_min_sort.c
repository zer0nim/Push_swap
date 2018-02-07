/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_min_sort.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emarin <emarin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/19 14:47:29 by emarin            #+#    #+#             */
/*   Updated: 2018/01/19 15:40:00 by emarin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_push_swap.h"

char	min_plc(int min, int *lastmin)
{
	int	i;

	i = lastmin[0];
	while (i > 0 && lastmin[i] != min)
		--i;
	return (i > 0);
}

int		ft_next_min(t_pile *pile, int *lastmin, char is_min)
{
	int		min;
	int		first;

	first = 1;
	while (pile)
	{
		if ((first || pile->content < min)
		&& (!is_min || !min_plc(pile->content, lastmin)))
		{
			min = pile->content;
			first = 0;
		}
		pile = pile->next;
	}
	return ((first) ? lastmin[lastmin[0]] : min);
}

void	ft_init_min_sort(int *mina, t_pile **a, t_pile **b, int *i)
{
	*mina = ft_next_min(*a, 0, 0);
	while ((*a)->content != *mina)
		ft_pile_push_to(a, b, 2);
	if ((*a)->next)
		ft_pile_rot(a, 1);
	*i = 0;
}

void	ft_place_min_sort(int *minb, t_pile **a, t_pile **b)
{
	if (best_path(*b, *minb))
		while ((*b)->content != *minb)
			ft_pile_rot(b, 2);
	else
		while ((*b)->content != *minb)
			ft_pile_rot_down(b, 2);
	ft_pile_push_to(b, a, 1);
	if ((*a)->next)
		ft_pile_rot(a, 1);
}

int		ft_min_sort(t_pile **a, t_pile **b, int start_len)
{
	int		mina;
	int		minb;
	int		*lastmin;
	int		i;

	if (!(lastmin = (int *)malloc(sizeof(int) * (ft_pile_len(*a) + 1))))
		return (0);
	ft_init_min_sort(&mina, a, b, &i);
	while (lastmin[0] < start_len)
	{
		lastmin[0] = ++i;
		lastmin[i] = (((i == 1) || (!min_plc(mina, lastmin) && (mina < minb
		|| min_plc(minb, lastmin)))) ? mina : minb);
		mina = ft_next_min(*a, lastmin, 1);
		minb = ft_next_min(*b, lastmin, 1);
		if (!min_plc(mina, lastmin) && (mina < minb || min_plc(minb, lastmin)))
			while ((*a)->content != mina)
				ft_pile_push_to(a, b, 2);
		else if (*b)
			ft_place_min_sort(&minb, a, b);
		if ((!min_plc(mina, lastmin)
		&& (mina < minb || min_plc(minb, lastmin))) && (*a)->next)
			ft_pile_rot(a, 1);
	}
	return (1);
}
