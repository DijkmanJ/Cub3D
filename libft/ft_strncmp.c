/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strncmp.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: jdijkman <jdijkman@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/10/04 16:19:24 by jdijkman      #+#    #+#                 */
/*   Updated: 2023/10/24 14:49:56 by jdijkman      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	int	i;

	i = 0;
	while (n > 0 && (s1[i] != '\0' || s2[i] != '\0'))
	{
		if (s1[i] == s2[i])
			i ++;
		else
			return ((unsigned char)s1[i] - (unsigned char)s2[i]);
		n --;
	}
	return (0);
}

// int main(void)
// {
//     // const char *s1 = "hello";
//     // const char *s2 = "hellas";
//     // size_t n = 6;
//     // printf("%d\n", ft_strncmp(s1, s2, n));
//     // printf("%d", strncmp(s1, s2, n));
// 	printf("%d", ft_strncmp("test", "testss", 7));
// }