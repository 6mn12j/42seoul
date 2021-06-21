/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minjupar <minjupar@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/16 13:40:15 by minjupar          #+#    #+#             */
/*   Updated: 2021/06/21 21:39:14 by minjupar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

 #ifndef FT_PRINTF_H
 # define FT_PRINTF_H

 #include <unistd.h>
 #include <stdarg.h>
 #include <stdlib.h>
 #include <stdio.h>

typedef struct s_flag
{
	 int zero;
	 int minus;
	 int width;
	 int precision;
	 int precision_value;
	 int return_value;
	 char spec;
}			t_flag;
#endif