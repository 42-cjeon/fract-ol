/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cjeon <student.42seoul.kr>                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/07 13:30:43 by cjeon             #+#    #+#             */
/*   Updated: 2021/12/07 14:27:48 by cjeon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	circle_sub(int x, int y, int mod)
{
	x -= y;
	if (x < 0)
		x += mod;
	return (x);
}

int	circle_add(int x, int y, int mod)
{
	x += y;
	if (x >= mod)
		x -= mod;
	return (x);
}

double	fcircle_sub(double x, double y, double mod)
{
	x -= y;
	if (x < 0)
		x += mod;
	return (x);
}

double	fcircle_add(double x, double y, double mod)
{
	x += y;
	if (x >= mod)
		x -= mod;
	return (x);
}

int	ft_strcmp(const char *s1, const char *s2)
{
	unsigned int	i;

	i = 0;
	while (*s1 != '\0' && *s1 == *s2)
	{
		s1++;
		s2++;
		i++;
	}
	if (*(unsigned char *)s1 > *(unsigned char *)s2)
		return (1);
	else if (*(unsigned char *)s1 < *(unsigned char *)s2)
		return (-1);
	else
		return (0);
}
