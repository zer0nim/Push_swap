/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emarin <emarin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/16 12:07:45 by emarin            #+#    #+#             */
/*   Updated: 2018/01/19 19:03:05 by emarin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_push_swap.h"

static	void	ft_need_swap_2_3(t_pile **a, t_pile **b, char state)
{
	ft_pile_push_to(a, b, 2);
	ft_pile_swp(a, 1);
	if (state == 1)
	{
		if ((*b)->content > (*a)->content)
		{
			ft_pile_push_to(b, a, 1);
			ft_pile_swp(a, 1);
			ft_pile_push_to(a, b, 2);
		}
		ft_pile_push_to(a, b, 2);
		ft_pile_push_to(a, b, 2);
	}
	else
	{
		ft_pile_push_to(b, a, 1);
		if ((*a)->content > ((*a)->next)->content)
			ft_pile_swp(a, 1);
	}
}

void			ft_sort(t_pile **a, t_pile **b, int nb, char state)
{
	if (nb != 1)
	{
		if ((*a)->content > ((*a)->next)->content)
			ft_pile_swp(a, 1);
		if (nb > 2
		&& ((*a)->next)->content > (((*a)->next)->next)->content)
			ft_need_swap_2_3(a, b, state);
		else if (state == 1)
		{
			ft_pile_push_to(a, b, 2);
			ft_pile_push_to(a, b, 2);
			if (nb == 3)
				ft_pile_push_to(a, b, 2);
		}
	}
	else if (state == 1)
		ft_pile_push_to(a, b, 2);
}

void			ft_lonely_sort(t_pile **p, int len)
{
	if (len == 2)
	{
		if ((*p)->content > ((*p)->next)->content)
			ft_pile_swp(p, 1);
	}
	else if (len == 3)
	{
		while (!((*p)->content < ((*p)->next)->content
		&& ((*p)->next)->content < (((*p)->next)->next)->content))
			if (((*p)->content > ((*p)->next)->content
			&& (*p)->content < (((*p)->next)->next)->content)
			|| ((*p)->content < ((*p)->next)->content
			&& ((*p)->next)->content > (((*p)->next)->next)->content))
				ft_pile_swp(p, 1);
			else if ((*p)->content > ((*p)->next)->content
			&& ((*p)->next)->content > (((*p)->next)->next)->content)
				ft_pile_rot(p, 1);
			else if ((*p)->content < ((*p)->next)->content)
				ft_pile_rot_down(p, 1);
			else
				ft_pile_rot(p, 1);
	}
}

void			ft_lonely_sort2(t_pile **p, int len)
{
	if (len == 2)
	{
		if ((*p)->content > ((*p)->next)->content)
			ft_pile_swp(p, 2);
	}
	else if (len == 3)
	{
		while (!((*p)->content > ((*p)->next)->content
		&& ((*p)->next)->content > (((*p)->next)->next)->content))
			if (((*p)->content < ((*p)->next)->content
			&& (*p)->content > (((*p)->next)->next)->content)
			|| ((*p)->content > ((*p)->next)->content
			&& ((*p)->next)->content < (((*p)->next)->next)->content))
				ft_pile_swp(p, 2);
			else if ((*p)->content < ((*p)->next)->content
			&& ((*p)->next)->content < (((*p)->next)->next)->content)
				ft_pile_rot(p, 2);
			else if ((*p)->content > ((*p)->next)->content)
				ft_pile_rot_down(p, 2);
			else
				ft_pile_rot(p, 2);
	}
}

void			ft_get_up_dw(t_pile *a, t_pile *b, int *up_dw)
{
	up_dw[0] = 0;
	up_dw[2] = 0;
	while (b)
	{
		if (b->content > a->content && (!up_dw[0] || b->content < up_dw[1]))
		{
			up_dw[1] = b->content;
			up_dw[0] = 1;
		}
		if (b->content < a->content && (!up_dw[2] || b->content > up_dw[3]))
		{
			up_dw[3] = b->content;
			up_dw[2] = 1;
		}
		b = b->next;
	}
}
