/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strdup.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: jdijkman <jdijkman@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/10/10 13:53:03 by jdijkman      #+#    #+#                 */
/*   Updated: 2023/10/24 14:59:54 by jdijkman      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s)
{
	int		i;
	char	*ptr;

	i = 0;
	ptr = (char *) malloc (ft_strlen(s) + 1);
	if (ptr == NULL)
		return (NULL);
	while (s[i])
	{
		ptr[i] = s[i];
		i ++;
	}
	ptr[i] = '\0';
	return (ptr);
}

// int main(void)
// {
// 	const char *s = "hello world";
// 	printf("%s\n", strdup(s));
// 	printf("%s", ft_strdup(s));
// }