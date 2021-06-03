/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fil_stats.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yarroubi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/07 18:43:49 by yarroubi          #+#    #+#             */
/*   Updated: 2021/04/14 14:32:49 by yarroubi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parse.h"

int main(int argc, char **argv)
{
	int			fd;
	struct stat	buf;
   
	//lstat(argv[1], &buf);
	stat(argv[1], &buf);
	ft_stat(argv[1]);


	printf("\n\n");
	printf("dev = %d / %d\n", major(buf.st_dev), minor(buf.st_dev));
	printf("rdev = %d / %d\n", major(buf.st_rdev), minor(buf.st_rdev));

	printf("uid = %u\n", buf.st_uid);
	printf("gid = %u\n", buf.st_gid);

	printf("user flags = %u\n", buf.st_flags);
	printf("file generation number = %d\n", buf.st_gen);

}
