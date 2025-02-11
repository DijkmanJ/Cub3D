/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_memmove.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: jdijkman <jdijkman@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/10/04 13:07:14 by jdijkman      #+#    #+#                 */
/*   Updated: 2023/10/27 16:35:53 by jdijkman      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*ft_moveit(char *d, const char *s, size_t n)
{
	int	i;

	i = 0;
	if (d < s)
	{
		while (n > 0)
		{
			d[i] = s[i];
			i++;
			n--;
		}
	}
	else if (d > s)
	{
		while (n > 0)
		{
			d[n - 1] = s[n - 1];
			n--;
		}
	}
	return (d);
}

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	char		*d;
	const char	*s;

	d = (char *)dest;
	s = (char *)src;
	dest = (void *)ft_moveit(d, s, n);
	return (dest);
}

// int main(void)
// {
// 	// void *dest;
// 	// const void *src;
// 	// size_t n = 8;
// 	//ft_memmove(dest, src, n);
// 	memmove("", "", 5);
// }