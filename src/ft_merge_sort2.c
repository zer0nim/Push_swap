/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_merge_sort2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emarin <emarin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/19 19:05:18 by emarin            #+#    #+#             */
/*   Updated: 2018/01/19 19:06:29 by emarin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_push_swap.h"

void	ft_merge_a(t_pile **a, t_pile **b, int nb)
{
	int	ra;
	int	rra;

	rra = 0;
	ra = nb / 2;
	nb = nb / 2 + (nb % 2 != 0);
	while ((*a)->content < (*b)->content && ra)
	{
		--ra;
		++rra;
		ft_pile_rot(a, 1);
	}
	while (nb-- > 0)
	{
		while (ft_get_last(*a) > (*b)->content && rra)
		{
			++ra;
			--rra;
			ft_pile_rot_down(a, 1);
		}
		ft_pile_push_to(b, a, 1);
		++ra;
	}
	while (rra--)
		ft_pile_rot_down(a, 1);
}

void	ft_last_merge(t_pile **a, t_pile **b, int nb)
{
	int		up_dw[4];
	int		len;
	int		pos;

	while (nb-- > 0)
	{
		ft_get_up_dw(*b, *a, up_dw);
		len = ft_pile_len(*a);
		pos = 0;
		if (best_rot_last(*a, up_dw))
			while (pos++ < len && ((up_dw[2]) ?
			(ft_get_last((*a)) != up_dw[3]) : ((*a)->content != up_dw[1])))
				ft_pile_rot(a, 1);
		else
			while (pos++ < len && ((up_dw[2]) ?
			(ft_get_last((*a)) != up_dw[3]) : ((*a)->content != up_dw[1])))
				ft_pile_rot_down(a, 1);
		ft_pile_push_to(b, a, 1);
	}
	ft_reorder_last(a, 1);
}

void	ft_simple_merge(t_pile **a, t_pile **b, int nb)
{
	int		up_dw[4];
	int		len;
	int		pos;

	while (nb-- > 0)
	{
		ft_get_up_dw(*a, *b, up_dw);
		len = ft_pile_len(*b);
		pos = 0;
		if (best_rot(*b, up_dw))
			while (pos++ < len && ((up_dw[2]) ?
			((*b)->content != up_dw[3]) : (ft_get_last((*b)) != up_dw[1])))
				ft_pile_rot(b, 2);
		else
			while (pos++ < len && ((up_dw[2]) ?
			((*b)->content != up_dw[3]) : (ft_get_last((*b)) != up_dw[1])))
				ft_pile_rot_down(b, 2);
		ft_pile_push_to(a, b, 2);
	}
	ft_reorder(b, 2);
}

void	ft_merge(t_pile **a, t_pile **b, int nb, char state)
{
	int	rb;
	int	rrb;

	if (!(rrb = 0) && (state == 2 || state == 4))
		ft_merge_a(a, b, nb);
	if (state == 2 || state == 4)
		return ;
	rb = nb / 2 + (nb % 2 != 0);
	nb = nb / 2;
	while ((*b)->content > (*a)->content && rb
	&& rb-- && ((++rrb) >= 0 || rrb < 0))
		ft_pile_rot(b, 2);
	while (nb-- > 0)
	{
		while (ft_get_last(*b) < (*a)->content && rrb
		&& rrb-- && ((++rb) >= 0 || rb < 0))
			ft_pile_rot_down(b, 2);
		ft_pile_push_to(a, b, 2);
		++rb;
	}
	while (rrb--)
		ft_pile_rot_down(b, 2);
}
