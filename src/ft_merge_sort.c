/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_merge_sort.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emarin <emarin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/19 16:03:21 by emarin            #+#    #+#             */
/*   Updated: 2018/01/19 19:09:09 by emarin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_push_swap.h"

static	void	ft_merge_small_sort(t_pile **a, t_pile **b, int nb, char state)
{
	if (state == 3 || state == 4)
		state -= 2;
	if (ft_pile_len(*a) == nb && state == 2)
		ft_lonely_sort(a, nb);
	if (ft_pile_len(*b) == 0 && state == 1)
	{
		ft_pile_push_to(a, b, 2);
		ft_pile_push_to(a, b, 2);
		if (nb == 3)
			ft_pile_push_to(a, b, 2);
		ft_lonely_sort2(b, nb);
	}
	else
		ft_sort(a, b, nb, state);
}

void			ft_merge_sort(t_pile **a, t_pile **b, int nb, char state)
{
	if (nb <= 3)
		ft_merge_small_sort(a, b, nb, state);
	else
	{
		if (state == 3 || state == 4)
			ft_merge_sort(a, b, nb / 2 + (nb % 2 != 0), 3);
		else
			ft_merge_sort(a, b, nb / 2 + (nb % 2 != 0), 1);
		if (state == 4 || state == 5)
			ft_merge_sort(a, b, nb / 2, 5);
		else
			ft_merge_sort(a, b, nb / 2, 2);
		if (state == 3)
			ft_simple_merge(a, b, nb / 2);
		else if (state == 4 || state == 5)
			ft_last_merge(a, b, nb / 2 + (nb % 2 != 0));
		else
			ft_merge(a, b, nb, state);
	}
}
