/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmois <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/28 09:51:43 by cmois             #+#    #+#             */
/*   Updated: 2021/10/28 11:13:55 by cmois            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

static t_char	g_character;

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_putstr(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		write(1, &str[i], 1);
		i++;
	}
}

void	receive_bits(int bit)
{
	g_character.c += ((bit & 1) << g_character.bits);
	g_character.bits++;
	if (g_character.bits == 7)
	{
		ft_putchar(g_character.c);
		if (!g_character.c)
			ft_putchar('\n');
		g_character.c = 0;
		g_character.bits = 0;
	}
}

void	ft_putnbr(int nbr)
{
	if (nbr < 0)
	{
		ft_putchar('-');
		nbr = -nbr;
	}
	if (nbr > 9)
	{
		ft_putnbr(nbr / 10);
		ft_putnbr(nbr % 10);
	}
	else
	{
		ft_putchar(nbr + 48);
	}
}

int	main(void)
{
	g_character.c = 0;
	g_character.bits = 0;
	ft_putstr("server pid : ");
	ft_putnbr(getpid());
	ft_putchar('\n');
	while (1)
	{
		signal(SIGUSR2, receive_bits);
		signal(SIGUSR1, receive_bits);
		pause();
	}
}
