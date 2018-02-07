/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_util.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emarin <emarin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/12 14:38:18 by emarin            #+#    #+#             */
/*   Updated: 2018/01/30 13:58:21 by emarin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_push_swap.h"

int		ft_er(void)
{
	ft_putstr_fd("Error\n", STDERR_FILENO);
	return (0);
}

char	ft_bad_arg(char *str)
{
	int				i;

	i = 0;
	while (str[i] && (ft_isdigit(str[i])
	|| (i == 0 && (str[0] == '-' || str[0] == '+')
	&& ft_isdigit(str[1]) && str[1] != '0')))
		++i;
	if (str[i] || (!((long long)ft_atoi(str) == ft_atoi_l(str)))
	|| ft_strlen(str) > 11)
		return (1);
	return (0);
}
