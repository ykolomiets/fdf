/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ykolomie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/30 11:18:48 by ykolomie          #+#    #+#             */
/*   Updated: 2017/09/30 12:50:38 by ykolomie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HOOKS_H
# define HOOKS_H

# include "base_structures.h"

int			mouse_hook(int button, int x, int y, t_fdf *all);
int			pressed_hook(int keycode, t_fdf *all);
void		pressed_hook2(int keycode, t_fdf *all);
int			keys_hook(int keycode, t_fdf *all);
int			expose_hook(t_fdf *all);

#endif
