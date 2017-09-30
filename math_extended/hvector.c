/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hvector.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ykolomie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/30 10:00:41 by ykolomie          #+#    #+#             */
/*   Updated: 2017/09/30 10:00:43 by ykolomie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mathx.h"
#include <math.h>

t_hvec	hv_create_point(float x, float y, float z)
{
	return (t_hvec){x, y, z, 1};
}

t_hvec	hv_create_direction(float x, float y, float z)
{
	return (t_hvec){x, y, z, 0};
}

t_hvec	hv_normalize(t_hvec v)
{
	if (fabsf(v.w) > 0.00005)
	{
		v.x /= v.w;
		v.y /= v.w;
		v.z /= v.w;
		v.w = 1;
	}
	return (v);
}
