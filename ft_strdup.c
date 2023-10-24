/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcummins <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/23 13:24:21 by jcummins          #+#    #+#             */
/*   Updated: 2023/10/24 15:18:47 by jcummins         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include <stdio.h>
#include <stdlib.h>

char	*ft_strdup(const char *s)
{
	char *dup;
	unsigned int len;
	unsigned int i;

	len = 0;
	while (s[len])
		len++;
	dup = (char *)malloc(len * sizeof(char));
	i = 0;
	while (i < len)
	{
		dup[i] = s[i];
		i++;
	}
	return (dup);
}

int	main(void)
{
	const char	*src = "Original String to be duplicated";
	printf("%s\n", ft_strdup(src));
	return (0);
}
