/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractals.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmartine <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/12 16:35:56 by pmartine          #+#    #+#             */
/*   Updated: 2016/05/18 16:49:33 by pmartine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

int		mandelbrot(t_env env, int x, int y)
{
	int		i;
	double	zr;
	double	zi;

	i = -1;
	env.f.pi = env.mod.ymax - (long double)y * env.zy;
	env.f.pr = env.mod.xmin + (long double)x * env.zx;
	env.f.ni = 0;
	env.f.nrl = 0;
	zr = SQUARE(env.f.nrl);
	zi = SQUARE(env.f.ni);
	while (++i < env.iter && (zr + zi) < 4)
	{
		env.f.ni *= env.f.nrl;
		env.f.ni += env.f.ni + env.f.pi;
		env.f.nrl = zr - zi + env.f.pr;
		zr = SQUARE(env.f.nrl);
		zi = SQUARE(env.f.ni);
	}
	return (i);
}

int		julia(t_env env, int x, int y)
{
	int				i;
	long double		zr;
	long double		zi;

	env.f.ni = env.mod.ymax - (long double)y * env.zy;
	env.f.nrl = env.mod.xmin + (long double)x * env.zx;
	zr = SQUARE(env.f.nrl);
	zi = SQUARE(env.f.ni);
	i = -1;
	while (++i < env.iter && (zr + zi) < 4)
	{
		env.f.ni *= env.f.nrl;
		env.f.ni += env.f.ni + env.f.ci;
		env.f.nrl = zr - zi + env.f.cr;
		zr = SQUARE(env.f.nrl);
		zi = SQUARE(env.f.ni);
	}
	return (i);
}
