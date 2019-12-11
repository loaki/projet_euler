/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_decouper.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jfeuilla <jfeuilla@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/11 17:20:17 by jfeuilla          #+#    #+#             */
/*   Updated: 2019/12/11 18:35:16 by jfeuilla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>
#include <fcntl.h>

int main()
{
	char *str;
	int fd;
	int i = 0;
	int i1 = 0;
	int i2 = 0;
	int i3 = 0;
	int ret = 0;
	int ret2 = 0;
	int ret3 = 0;
	char str1[4096];
	char str2[4096];
	char str3[4096];
	char tmp[3];
	int f1[100] = {0};
	int f2[100] = {0};
	int f3[100] = {0};

	fd = open("xor.txt", O_RDONLY);
	get_next_line(fd, &str);
	while (str[i])
	{
		while (str[i] != ',' && str[i])
		{
			str1[i1] = str[i];
			i1++;
			i++;
		}
		if (str1[i1 - 2] != ',')
			tmp[0] = str1[i1 - 2];
		else
			tmp[0] = '0';
		tmp[1] = str1[i1 - 1];
		tmp[2] = 0;
		f1[atoi(tmp)] += 1;
		if (str[i])
		{
			str1[i1] = str[i];
			i1++;
			i++;
		}
		while (str[i] != ',' && str[i])
		{
			str2[i2] = str[i];
			i2++;
			i++;
		}
		if (str2[i2 - 2] != ',')
			tmp[0] = str2[i2 - 2];
		else
			tmp[0] = '0';
		tmp[1] = str2[i2 - 1];
		tmp[2] = 0;
		f2[atoi(tmp)] += 1;

		if (str[i])
		{
			str2[i2] = str[i];
			i2++;
			i++;
		}
		while (str[i] != ',' && str[i])
		{
			str3[i3] = str[i];
			i3++;
			i++;
		}
		if (str3[i3 - 2] != ',')
			tmp[0] = str3[i3 - 2];
		else
			tmp[0] = '0';
		tmp[1] = str3[i3 - 1];
		tmp[2] = 0;
		f3[atoi(tmp)] += 1;
		if (str[i])
		{
			str3[i3] = str[i];
			i3++;
			i++;
		}
	}
	str1[i1] = 0;
	str2[i2] = 0;
	str3[i3] = 0;
	i = 0;
	while (i < 100)
	{
		if (f1[i] > f1[ret])
			ret = i;
		if (f1[i] > f1[ret2] && f3[ret] > f3[i])
			ret2 = i;
		if (f1[i] > f1[ret3] && f3[ret2] > f3[i])
			ret3 = i;
		i++;
	}
	printf("max str1 :\n%i\n%i\n%i\n", ret, ret2, ret3);
	i = 0;
	ret = 0;
	ret2 = 0;
	ret3 = 0;
	while (i < 100)
	{
		if (f2[i] > f2[ret])
			ret = i;
		if (f2[i] > f2[ret2] && f3[ret] > f3[i])
			ret2 = i;
		if (f2[i] > f2[ret3] && f3[ret2] > f3[i])
			ret3 = i;
		i++;
	}
	printf("max str2 :\n%i\n%i\n%i\n", ret, ret2, ret3);
	i = 0;
	ret = 0;
	ret2 = 0;
	ret3 = 0;
	while (i < 100)
	{
		if (f3[i] > f3[ret])
			ret = i;
		if (f3[i] > f3[ret2] && f3[ret] > f3[i])
			ret2 = i;
		if (f3[i] > f3[ret3] && f3[ret2] > f3[i])
			ret3 = i;
		i++;
	}
	printf("max str3 :\n%i\n%i\n%i\n", ret, ret2, ret3);
	return (0);
}
