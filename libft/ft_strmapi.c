/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strmapi.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: jdijkman <jdijkman@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/10/11 15:04:42 by jdijkman      #+#    #+#                 */
/*   Updated: 2023/10/23 17:14:07 by jdijkman      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	int		i;
	char	*str;

	i = 0;
	if (!s)
		return (NULL);
	str = (char *) malloc (ft_strlen(s) * sizeof(char) + 1);
	if (str == NULL)
		return (NULL);
	while (s[i] != '\0')
	{
		str[i] = f(i, s[i]);
		i ++;
	}
	str[i] = '\0';
	return (str);
}

// char upper(unsigned int i, char c)
// {
// 	printf("%d\n", i);
// 	return (c - 32);
// }
// int main(void)
// {
// 	char const *s = "";
// 	printf("%s\n", ft_strmapi(s, upper));
// }