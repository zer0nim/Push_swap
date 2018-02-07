/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_push_swap.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emarin <emarin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/12 10:53:33 by emarin            #+#    #+#             */
/*   Updated: 2018/01/19 19:07:18 by emarin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PUSH_SWAP_H
# define FT_PUSH_SWAP_H

# include "libft/ft_printf.h"
# include <unistd.h>

typedef struct		s_pile
{
	int				content;
	struct s_pile	*next;
}					t_pile;

void				ft_pile_print(t_pile *pile);
t_pile				*ft_pile_new(int content);
void				ft_pile_push(t_pile **pile, t_pile *new);
void				ft_pile_pushback(t_pile **pile, t_pile *new);
void				ft_pile_swp(t_pile **pile, char state);
void				ft_pile_free(t_pile *pile);
int					ft_pile_push_to(t_pile **a, t_pile **b, char state);
void				ft_pile_pop(t_pile **pile);
void				ft_pile_rot(t_pile **pile, char state);
void				ft_pile_rot_down(t_pile **pile, char state);
int					ft_er();
char				ft_bad_arg(char *str);
int					init_pile(t_pile **a, int argc, char **argv);
int					ft_pile_len(t_pile *pile);
void				ft_sort(t_pile **a, t_pile **b, int nb, char state);
char				best_path(t_pile *pile, int min);

int					ft_pile_cop_to(t_pile **a, t_pile **b);
void				ft_simple_merge(t_pile **a, t_pile **b, int nb);
void				ft_get_up_dw(t_pile *a, t_pile *b, int *up_dw);
char				best_rot(t_pile *pile, int *up_dw);
char				best_rot_last(t_pile *pile, int *up_dw);
int					ft_get_last(t_pile *pile);
void				ft_reorder(t_pile **pile, char state);
void				ft_reorder_last(t_pile **pile, char state);
void				ft_last_merge(t_pile **a, t_pile **b, int nb);
void				ft_get_min(t_pile *pile, int *min);
void				ft_get_max(t_pile *pile, int *max);
void				ft_merge_a(t_pile **a, t_pile **b, int nb);
void				ft_last_merge(t_pile **a, t_pile **b, int nb);
void				ft_simple_merge(t_pile **a, t_pile **b, int nb);
void				ft_merge(t_pile **a, t_pile **b, int nb, char state);
void				ft_insert_sort(t_pile **a, t_pile **b);
int					ft_min_sort(t_pile **a, t_pile **b, int start_len);
void				ft_merge_sort(t_pile **a, t_pile **b, int nb, char state);
void				ft_lonely_sort(t_pile **p, int len);
void				ft_lonely_sort2(t_pile **p, int len);

#endif
