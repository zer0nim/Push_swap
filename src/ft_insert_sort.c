/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_insert_sort.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emarin <emarin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/19 14:24:38 by emarin            #+#    #+#             */
/*   Updated: 2018/01/19 19:02:00 by emarin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_push_swap.h"

void	ft_insert_sort(t_pile **a, t_pile **b)
{
	int len;

	len = ft_pile_len(*a);
	if (len > 3)
	{
		while (--len > 0)
			ft_pile_push_to(a, b, 2);
		ft_last_merge(a, b, ft_pile_len(*b));
	}
	else
		ft_lonely_sort(a, len);
}
