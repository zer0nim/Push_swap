/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_op.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emarin <emarin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/12 19:24:17 by emarin            #+#    #+#             */
/*   Updated: 2018/01/18 17:47:11 by emarin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_push_swap.h"

void	ft_pile_swp(t_pile **pile, char state)
{
	t_pile *tmp;

	if ((*pile) && (*pile)->next)
	{
		tmp = (*pile)->next;
		(*pile)->next = tmp->next;
		tmp->next = (*pile);
		(*pile) = tmp;
	}
	if (state == 3)
		ft_printf("ss\n");
	else if (state)
		ft_printf("%s\n", ((state == 1) ? "sa" : "sb"));
}

int		ft_pile_push_to(t_pile **a, t_pile **b, char state)
{
	t_pile *tmp;

	if (*a)
	{
		if (*b)
		{
			if (!(tmp = ft_pile_new((*a)->content)))
				return (-1);
			ft_pile_push(b, tmp);
		}
		else if (!(*b = ft_pile_new((*a)->content)))
			return (ft_er());
		ft_pile_pop(a);
	}
	if (state)
		ft_printf("%s\n", ((state == 1) ? "pa" : "pb"));
	return (0);
}

void	ft_pile_pop(t_pile **pile)
{
	t_pile *tmp;

	tmp = NULL;
	if ((*pile)->next)
		tmp = (*pile)->next;
	free(*pile);
	if (tmp)
		*pile = tmp;
	else
		*pile = NULL;
}

void	ft_pile_rot(t_pile **pile, char state)
{
	t_pile *tmp;

	if (*pile && (*pile)->next)
	{
		tmp = *pile;
		*pile = (*pile)->next;
		tmp->next = NULL;
		ft_pile_pushback(pile, tmp);
	}
	if (state == 3)
		ft_printf("rr\n");
	else if (state)
		ft_printf("%s\n", ((state == 1) ? "ra" : "rb"));
}

void	ft_pile_rot_down(t_pile **pile, char state)
{
	t_pile *tmp;

	if (*pile && (*pile)->next)
	{
		tmp = *pile;
		while (tmp->next && (tmp->next)->next)
			tmp = tmp->next;
		(tmp->next)->next = *pile;
		*pile = tmp->next;
		tmp->next = NULL;
	}
	if (state == 3)
		ft_printf("rrr\n");
	else if (state)
		ft_printf("%s\n", ((state == 1) ? "rra" : "rrb"));
}
