/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_atoi.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: jdijkman <jdijkman@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/10/09 17:33:02 by jdijkman      #+#    #+#                 */
/*   Updated: 2023/10/23 16:09:46 by jdijkman      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_intlen(const char *nptr)
{
	int	i;

	i = 0;
	while (nptr[i] == ' ' || (nptr[i] >= 9 && nptr[i] <= 13))
		i++;
	while (nptr[i] >= '0' && nptr[i] <= '9')
		i++;
	return (i);
}

static int	ft_num(int i, const char *nptr)
{
	int	num;

	num = 0;
	while (nptr[i] != '\0' && nptr[i] >= '0' && nptr[i] <= '9')
	{
		num = num * 10 + nptr[i] - '0';
		i++;
	}
	return (num);
}

int	ft_atoi(const char *nptr)
{
	int	i;
	int	neg;

	i = 0;
	neg = 0;
	while (nptr[i] == ' ' || (nptr[i] >= 9 && nptr[i] <= 13))
		i++;
	if (nptr[i] == '-' || nptr[i] == '+')
	{
		if (nptr[i + 1] < '0' || nptr[i + 1] > '9')
			return (0);
		else if (nptr[i] == '-')
			neg++;
		i++;
	}
	if (ft_intlen(nptr) - i >= 20)
	{
		if (neg > 0)
			return (0);
		return (-1);
	}
	if (neg > 0)
		return (-ft_num(i, nptr));
	return (ft_num(i, nptr));
}

// int main(void)
// {
// 	const char *nptr = " +123a45678901234567890";
// 	printf("%d\n", atoi(nptr));
// 	printf("%d", ft_atoi(nptr));
// }