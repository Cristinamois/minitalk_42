/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmois <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/28 09:54:06 by cmois             #+#    #+#             */
/*   Updated: 2021/10/28 11:13:51 by cmois            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINITALK_H
# define MINITALK_H

# include <signal.h>
# include <unistd.h>
# include <sys/types.h>
# include <stdio.h>

typedef struct s_char
{
	char		c;
	size_t		bits;
}			t_char;

void	ft_putchar(char c);

#endif
