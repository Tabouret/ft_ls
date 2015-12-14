/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pollier <pollier@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/05 20:54:42 by pollier           #+#    #+#             */
/*   Updated: 2015/12/14 04:46:30 by pollier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_LS_H
# define FT_LS_H
# include "libft/libft.h"
# include <dirent.h>
# include <sys/param.h>
# include <sys/stat.h>
# include <time.h>
# include <sys/types.h>
# include <pwd.h>
# include <grp.h>

typedef struct			s_params
{
	int					a_dot;
	int					r_rec;
	int					l_lst;
	int					r_rev;
	int					h_human;
	int					t_time_sort;
}						t_params;

typedef struct			s_target
{
	char				*name;
	struct stat			*stats;
	s_target			*next;
}						t_target;

t_target			*ft_last_target(t_target *start);
t_target			*ft_get_targets(int argc, char const *argv[]);


#endif
