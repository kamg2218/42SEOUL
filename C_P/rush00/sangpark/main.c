/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seokchoi <seochoi@student.42seoul.kr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/25 14:34:37 by seokchoi          #+#    #+#             */
/*   Updated: 2020/01/25 21:05:56 by sangpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "rush03.c"

/*본인 아이디 .c 로 만들기로 했던거 맞죠?*/
/*#include seochoi.c*/
/*#include hyoon.c*/
/*#include seyu.c*/
/*#include Sangpark.c*/

int		main(void)
{
	rush('a',3);
	write(1, "----------\n", 11);
/*	rush(5,1);
	write(1, "----------\n", 11);
	rush(1,1);
	write(1, "----------\n", 11);
	rush(1,5);
	write(1, "----------\n", 11);
	rush(4,4);
	write(1, "----------\n", 11);
*/
	return (0);
}
