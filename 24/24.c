/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fibo1000.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jfeuilla <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/02 11:08:35 by jfeuilla          #+#    #+#             */
/*   Updated: 2019/12/02 11:54:05 by jfeuilla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>

void	ft_bzero(char *str)
{
	int i;

	i = 0;
	while (i < 999)
	{
		str[i] = '0';
		i++;
	}
	str[i] = 0;
}

char	*ft_strdup(char *str)
{
	int		i;
	char	*res;

	i = 0;
	res = malloc(1001);
	while (i < 1000)
	{
		res[i] = str[i];
		i++;
	}
	return (res);
}

void	ft_addition(char *str1, char *str2, char *str3)
{
	int i;
	int ret;

	i = 999;
	ret = 0;
	while (i != -1)
	{
		ret = ret + str1[i] - '0' + str2[i] - '0';
		str3[i] = ret % 10 + '0';
		ret /= 10;
		i--;
	}
}

int		main(void)
{
	char *str1;
	char *str2;
	char *str3;
	int i;

	i = 2;
	str1 = malloc(1001);
	str2 = malloc(1001);
	str3 = malloc(1001);
	ft_bzero(str1);
	ft_bzero(str2);
	ft_bzero(str3);
	str1[999] = '1';
	str2[999] = '1';
	while (str3[0] == '0')
	{
		ft_addition(str1, str2, str3);
		free(str1);
		str1 = ft_strdup(str2);
		free(str2);
		str2 = ft_strdup(str3);
		i++;
	}
	printf("%i\n", i);
	free(str1);
	free(str2);
	free(str3);
	return (0);
}
