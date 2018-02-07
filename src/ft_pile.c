/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pile.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emarin <emarin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/12 12:17:06 by emarin            #+#    #+#             */
/*   Updated: 2018/01/30 14:37:13 by emarin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_push_swap.h"

void	ft_pile_free(t_pile *pile)
{
	t_pile	*tmp;

	while (pile)
	{
		tmp = pile->next;
		free(pile);
		pile = tmp;
	}
}

t_pile	*ft_pile_new(int content)
{
	t_pile	*new_pile;

	if (!(new_pile = (t_pile *)malloc(sizeof(t_pile))))
		return (NULL);
	new_pile->content = content;
	new_pile->next = NULL;
	return (new_pile);
}

void	ft_pile_push(t_pile **pile, t_pile *new)
{
	if (new != NULL)
	{
		if (pile != NULL)
			new->next = *pile;
		*pile = new;
	}
}

void	ft_pile_pushback(t_pile **pile, t_pile *new)
{
	t_pile *tmp;

	tmp = *pile;
	if (tmp)
	{
		while (tmp->next)
			tmp = tmp->next;
		tmp->next = new;
	}
}

int		ft_pile_cop_to(t_pile **a, t_pile **b)
{
	t_pile *tmp;

	if (*a)
	{
		if (*b)
		{
			if (!(tmp = ft_pile_new((*a)->content)))
				return (-1);
			ft_pile_pushback(b, tmp);
		}
		else if (!(*b = ft_pile_new((*a)->content)))
			return (ft_er());
	}
	return (0);
}
