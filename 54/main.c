#include "get_next_line.h"
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>

void ft_format(char *str)
{
	int i = 0;
	char temp;

	while (i < 13)
	{
		if (str[i] == 'A')
			str[i] = 14;
		else if (str[i] == 'K')
			str[i] = 13;
		else if (str[i] == 'Q')
			str[i] = 12;
		else if (str[i] == 'J')
			str[i] = 11;
		else if (str[i] == 'T')
			str[i] = 10;
		else 
			str[i] = str[i] - 48;
		i += 3;
	}
	i = 0;
	while (i <= 9)
	{
		if ((int)str[i] < (int)str[i + 3])
		{
			temp = str[i];
			str[i] = str[i + 3];
			str[i + 3] = temp;
			i = 0;
		}
		i += 3;
	}
	i = 0;
	while (str[i])
	{
		printf("%d", str[i]);
		i++;
	}
	printf("\n");
}

int ft_color(char *str)
{
	if (str[1] == str[4] && str[1] == str[7] && str[1] == str[10] && str[1] == str[13])
		return (1);
	return (0);
}

int ft_max(char *str1, char *str2)
{
	int i = 0;	

	while (i < 13)
	{
		if (str1[i] > str2[i])
			return (1);
		if (str1[i] < str2[i])
			return (0);
		i += 3;
	}
	return (0);
}

int	ft_pair(char *str)
{
	int i = 0;
	int j = 0;
	int ret = 0;

	while (i < 13)
	{
		j = 0;
		while (j < 13)
		{
			if (j != i && (str[i] == str[j]))
				ret = ret + 200 + str[i];
			j += 3;
		}
		if (ret > 0 && ret < 300)
			return (ret);
		ret = 0;
		i += 3;
	}
	return (0);
}

int	ft_doublepair(char *str)
{
	int i = 0;
	int j = 0;
	int ret = 0;
	int reto = 0;

	while (i < 13)
	{
		j = 0;
		while (j < 13)
		{
			if (j != i && (str[i] == str[j]))
				ret = ret + 200 + str[i];
			j += 3;
		}
		if (reto != 0 && ret > 0 && ret < 300)
		{
			if (reto > ret)
				return ((reto - 200) * 100 + ret - 200);
			else
				return ((ret - 200) * 100 + reto - 200);
		}
		if (ret > 0 && ret < 300)
			reto = ret;
		else
			ret = 0;
		i += 3;
	}
	return (0);
}

int ft_brelan(char *str)
{
	int i = 0;
	int j = 0;
	int ret = 0;

	while (i < 13)
	{
		j = 0;
		while (j < 13)
		{
			if (j != i && (str[i] == str[j]))
				ret = ret + 100;
			j += 3;
		}
		if (ret == 300)
			return (ret + str[i]);
		ret = 0;
		i += 3;
	}
	return (0);
}

int ft_carre(char *str)
{
	int i = 0;
	int j = 0;
	int ret = 0;

	while (i < 13)
	{
		j = 0;
		while (j < 13)
		{
			if (j != i && (str[i] == str[j]))
				ret = ret + 100;
			j += 3;
		}
		if (ret == 400)
			return (ret + str[i]);
		ret = 0;
		i += 3;
	}
	return (0);
}

int ft_quinte(char *str)
{
	if (str[0] == str[3] + 1 && str[0] == str[6] + 2 && str[0] == str[9] + 3 && str[0] == str[12] + 4)
		return (1);
	if (str[12] == 14)
		if (str[0] == str[3] + 1 && str[0] == str[6] + 2 && str[0] == str[9] + 3 && str[0] == 5)
			return (1);
	return (0);
}

int	ft_winner(char *str)
{
	char *str1;
	char *str2;
	int i = 0;

	str1 = malloc(15);
	str2 = malloc(15);	
	while (i < 14)
	{
		str1[i] = str[i];
		i++;
	}
	str1[i] = 0;
	i = 0;
	while (i < 14)
	{
		str2[i] = str[i + 15];
		i++;
	}
	str2[i] = 0;
	ft_format(str1);
	ft_format(str2);
	if ((ft_quinte(str1) == 1 && ft_color(str1) == 1))
	{
		if ((ft_quinte(str2) == 1 && ft_color(str2) == 1))
			if (ft_max(str1, str2) == 0)
				return (0);
		return (1);
	}
	if (ft_carre(str1) > 400)
	{
		if (ft_carre(str1) < ft_carre(str2))
			return (0);
		if (ft_carre(str1) == ft_carre(str2))
			if (ft_max(str1, str2) == 0)
				return (0);
		return (1);
	}
	if (ft_brelan(str1) > 300 && ft_pair(str1) > 200)
	{
		if (ft_brelan(str1) < ft_brelan(str2))
			return (0);
		if (ft_brelan(str1) == ft_brelan(str2))
			if (ft_pair(str1) <= ft_pair(str2))
				return (0);
		return (1);
	}
	if (ft_color(str1) == 1)
	{
		if (ft_color(str2) == 1)
			if (ft_max(str1, str2) == 0)
				return (0);
		return (1);
	}
	if (ft_quinte(str1) == 1)
	{
		if (ft_color(str2) == 1)
			if (ft_max(str1, str2) == 0)
				return (0);
		return (1);
	}
	if (ft_brelan(str1) > 300)
	{
		if (ft_brelan(str1) < ft_brelan(str2))
			return (0);
		if (ft_brelan(str1) == ft_brelan(str2))
			if (ft_max(str1, str2) == 0)
				return (0);
		return (1);
	}
	if (ft_doublepair(str1) > 1)
	{
		if (ft_doublepair(str1) < ft_doublepair(str2))
			return (0);
		if (ft_doublepair(str1) == ft_doublepair(str2))
			if (ft_max(str1, str2) == 0)
				return (0);
		return (1);
	}
	if (ft_pair(str1) > 200)
	{
		if (ft_pair(str1) < ft_pair(str2))
			return (0);
		if (ft_pair(str1) == ft_pair(str2))
			if (ft_max(str1, str2) == 0)
				return (0);
		return (1);
	}
	if (ft_max(str1, str2) != 0)
		return (1);
	return (0);
}

int main()
{
	char *line;
	int ret;
	int fd;
	int wins = 0;

	fd = open("poker.txt", O_RDONLY);
	while ((ret = get_next_line(fd, &line) > 0))
	{
		if (ft_winner(line) == 1)
			wins++;
		free(line);
	}
	printf("player 1 = %d wins\n", wins);
}
