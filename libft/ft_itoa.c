/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: masali <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/31 18:58:55 by masali            #+#    #+#             */
/*   Updated: 2018/10/31 18:59:42 by masali           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	count_bytes_nb(int n)
{
	int		i;
	long	nb;

	i = 0;
	nb = (long)n;
	if (nb < 0)
	{
		i++;
		nb = nb * -1;
	}
	while (nb > 9)
	{
		nb = nb / 10;
		i++;
	}
	i++;
	return (i);
}

char		*ft_itoa(int n)
{
	char	*str;
	int		nb_bt;
	long	nb;

	nb_bt = count_bytes_nb(n);
	str = (char *)malloc(sizeof(char) * (nb_bt + 1));
	if (!str)
		return (NULL);
	nb = (long)n;
	if (n < 0)
		nb = nb * -1;
	str[nb_bt] = '\0';
	nb_bt--;
	while (nb >= 0)
	{
		str[nb_bt] = (nb % 10) + '0';
		nb = nb / 10;
		nb_bt--;
		if (nb_bt == -1)
			break ;
	}
	if (n < 0)
		str[0] = '-';
	return (str);
}
