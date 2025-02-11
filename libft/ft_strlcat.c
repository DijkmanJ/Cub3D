/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strlcat.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: jdijkman <jdijkman@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/10/04 14:27:26 by jdijkman      #+#    #+#                 */
/*   Updated: 2023/10/25 16:50:05 by jdijkman      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
//#include <bsd/string.h>

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	i;
	int		j;
	int		dlen;

	j = 0;
	i = 0;
	dlen = 0;
	if (size == 0)
		return (ft_strlen(src));
	while (dst[i] != '\0')
		i ++;
	dlen = i;
	while (src[j] != '\0' && i + 1 < size)
	{
		dst[i] = src[j];
		j ++;
		i ++;
	}
	dst[i] = '\0';
	if ((unsigned int)size < (unsigned int)dlen && (unsigned int)size > 0)
		return (ft_strlen(src) + size);
	return (dlen + ft_strlen(src));
}

// int main(void)
// {
// 	char dest[15] = "rrrrrrrrrrrrrrr"; 

// 	//dest[0] = 'B';
// 	// char * src2 = (char *)"AAAAAAAAA";
// 	// memset(dest2, 'B', 4);

// 	printf("%zu\n", ft_strlcat(dest, "lorem ipsum dolor sit amet", 5));
// 	printf("%s\n", dest);
// 	//printf("%lu\n", strlen("lorem ipsum dolor sit amet"));
// 	//printf("%lu", ft_strlen(src));
// 	//printf("%zu", strlcat(dest2, src2, 3));
// 	//printf("ndest %s", dest);    
// }