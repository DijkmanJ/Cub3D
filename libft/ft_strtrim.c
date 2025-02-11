/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strtrim.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: jdijkman <jdijkman@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/10/10 14:44:09 by jdijkman      #+#    #+#                 */
/*   Updated: 2023/10/27 16:19:32 by jdijkman      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_inset(const char *s1, const char *set, int num)
{
	int	i;
	int	check;

	i = 0;
	check = 0;
	while (set[i] && s1[num] != set[i])
	{
		i ++;
	}
	if (set[i] == s1[num])
		check = 1;
	return (check);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	unsigned int	start;
	unsigned int	end;
	char			*str;

	start = 0;
	end = 0;
	if (s1[0] == '\0')
		return (ft_strdup("\0"));
	if (set[0] == '\0')
		return (ft_strdup(s1));
	while (ft_inset(s1, set, start) == 1 && s1)
		start ++;
	while (ft_inset(s1, set, ft_strlen(s1) - end - 1) == 1)
		end ++;
	if (start + end >= ft_strlen(s1))
	{
		str = (char *) malloc (1 * sizeof(char));
		str[0] = '\0';
		return (str);
	}
	str = ft_substr(s1, start, ft_strlen(s1) - start - end);
	return (str);
}

// int main(void)
// {
// 	// char const *s1 = "     1234596789\0\0\0";
// 	// char const *set = "1 859\0";
// 	printf("%s\n", ft_strtrim("", ""));
// }