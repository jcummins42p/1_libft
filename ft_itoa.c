/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcummins <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/25 12:07:45 by jcummins          #+#    #+#             */
/*   Updated: 2023/10/25 14:14:19 by jcummins         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

int	n_digits(int n)
{
	unsigned int	digits;

	digits = 1;
	while (n > 10)
	{
		n /= 10;
		digits++;
	}
	return (digits);
}

char	*p_digits(char *s, int n, int neg)
{
	int	i;

	i = n_digits(n);
	while ((i + neg) >= 0)
	{
		s[--i + neg] = "0123456789"[n % 10];
		n /= 10;
	}
	if (neg)
		s[0] = '-';
	return (s);
}

char	*ft_itoa(int n)
{
	char	*str;
	int		neg;

	neg = 0;
	if (n == INT_MIN)
	{
		str = "-2147483648";
		return (str);
	}
	if (n < 0)
	{
		neg = 1;
		n = -n;
	}
	str = (char *)malloc((n_digits(n) + neg) * sizeof(char));
	if (!str)
		return (NULL);
	p_digits(str, n, neg);
	return (str);
}

int	main(void)
{
	int	i;

	i = 2147483647;
	printf("The number %d as a string is %s\n", i, ft_itoa(i));
	return (0);
}
