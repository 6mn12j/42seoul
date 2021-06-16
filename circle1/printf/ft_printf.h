/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minjupar <minjupar@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/16 13:40:15 by minjupar          #+#    #+#             */
/*   Updated: 2021/06/16 22:07:10 by minjupar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

 #ifdef FT_PRINTF_H
 # define FT_PRINTF_H

 #include <unistd.h>
 #include <stdarg.h>
 #include <stdio.h>

 typedef struct ft_flag
 {
	 int negative;
	 int width;
	 int precision;
	 int temp;
	 int zero_flag;

 }
 #endif