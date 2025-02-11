/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_isalpha.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: jdijkman <jdijkman@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/10/03 16:52:34 by jdijkman      #+#    #+#                 */
/*   Updated: 2023/10/23 16:15:24 by jdijkman      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isalpha(int c)
{
	if ((c >= 'A' && c <= 'Z') || (c >= 'a' && c <= 'z'))
		return (1024);
	else
		return (0);
}

// int main(void)
// {
// 	for (int i = 0; i < 256; i++)
// 	{
// 		if (ft_isalpha(i) != isalpha(i))
// 		{
// 			printf("\nERROR at %i:\n", i);
// 			printf("%i\n", ft_isalpha(i));
// 			printf("%i\n", isalpha(i));
// 			continue;
// 		}
// 	printf("ok ");
// 	}
// }