/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_split.c                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: jdijkman <jdijkman@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/10/11 13:15:45 by jdijkman      #+#    #+#                 */
/*   Updated: 2023/10/31 15:06:11 by jdijkman      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	**ft_freeall(char **pointer_arr, int j)
{
	j --;
	while (j >= 0)
	{
		free(pointer_arr[j]);
		j--;
	}
	free(pointer_arr);
	return (NULL);
}

static int	count_str(const char *str, char c)
{
	int	i;
	int	count;
	int	true;

	i = 0;
	count = 0;
	true = 0;
	while (str[i])
	{
		if (str[i] != c && true == 0)
		{
			true = 1;
			count++;
		}
		else if (str[i] == c)
			true = 0;
		i ++;
	}
	return (count);
}

static char	*ft_suballoc(const char *str, int start, int finish)
{
	char	*substr;
	int		i;

	i = 0;
	substr = malloc((finish - start + 1) * sizeof(char));
	if (substr == NULL)
		return (NULL);
	while (start < finish)
	{
		substr[i] = str[start];
		i ++;
		start ++;
	}
	substr[i] = '\0';
	return (substr);
}

static char	**ft_fucknorminette(const char *s, char c)
{
	char	**pointer_arr;

	if (s == NULL)
		return (NULL);
	pointer_arr = ft_calloc((count_str(s, c) + 1), sizeof(char *));
	if (pointer_arr == NULL)
		return (NULL);
	return (pointer_arr);
}

char	**ft_split(char const *s, char c)
{
	size_t	i;
	size_t	j;
	int		index;
	char	**pointer_arr;

	i = 0;
	j = 0;
	index = -1;
	pointer_arr = ft_fucknorminette(s, c);
	if (pointer_arr == NULL)
		return (NULL);
	while (i <= ft_strlen(s))
	{
		if (s[i] != c && index < 0)
			index = i;
		else if ((s[i] == c || i == ft_strlen(s)) && index >= 0)
		{
			pointer_arr[j] = ft_suballoc(s, index, i);
			if (pointer_arr[j++] == NULL)
				return (ft_freeall(pointer_arr, j - 1));
			index = -1;
		}
		i ++;
	}
	return (pointer_arr);
}

// int main(void)
// {
// 	ft_split("..aaa      aa  a", ' ');
// }