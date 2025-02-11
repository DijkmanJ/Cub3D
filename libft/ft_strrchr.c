/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strrchr.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: jdijkman <jdijkman@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/10/04 16:08:18 by jdijkman      #+#    #+#                 */
/*   Updated: 2023/10/23 17:15:39 by jdijkman      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	int	i;

	i = 0;
	while (s[i])
		i ++;
	while (i >= 0)
	{
		if (s[i] == (unsigned char)c)
			return ((char *)s + i);
		i --;
	}
	return (0);
}

// int main(void)
// {
// 	const char *s = "hello world";
// 	int c = 'h';
// 	printf("%s", ft_strrchr(s, 0));
// }