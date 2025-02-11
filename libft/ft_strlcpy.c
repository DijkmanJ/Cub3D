/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strlcpy.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: jdijkman <jdijkman@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/10/04 13:20:00 by jdijkman      #+#    #+#                 */
/*   Updated: 2023/10/23 17:12:45 by jdijkman      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
//#include <bsd/string.h>

size_t	ft_strlcpy(char *dst, const char *src, size_t size)
{
	size_t	i;

	i = 0;
	if (size < 1)
		return (ft_strlen(src));
	while (i + 1 < size && src[i] != '\0')
	{
		dst[i] = src[i];
		i++;
	}
	dst[i] = '\0';
	return (ft_strlen(src));
}

// int main(void)
// {
// 	char src[] = "coucou";
// 	char dest[10] = "AAAAAAAAAA";
// 	// memset(dest, 'A', 10);
// 	size_t size = -1;
// 	printf("%zu\n", ft_strlcpy(dest, src, size));
// 	// int a;
// 	// a = strlcpy(dest, src, size);
// 	// printf("%d\n", a);
// 	// printf("%d", (char)dest[0]);
// }