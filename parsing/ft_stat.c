/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_stat.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yarroubi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/14 11:03:46 by yarroubi          #+#    #+#             */
/*   Updated: 2021/04/14 14:34:54 by yarroubi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parse.h"

void	ft_print_other_permissions(int mode)
{
	if (mode & S_IROTH)
		printf("r");
	else
		printf("-");
	if (mode & S_IWOTH)
		printf("w");
	else
		printf("-");
	if (mode & S_IXOTH)
		printf("x");
	else
		printf("-");
}

void	ft_print_group_permissions(int mode)
{
	if (mode & S_IRGRP)
		printf("r");
	else
		printf("-");
	if (mode & S_IWGRP)
		printf("w");
	else
		printf("-");
	if (mode & S_IXGRP)
		printf("x");
	else if (mode & S_ISGID)
		printf("s");
	else
		printf("-");
}

void	ft_print_user_permissions(int mode)
{
	if (mode & S_IRUSR)
		printf("r");
	else
		printf("-");
	if (mode & S_IWUSR)
		printf("w");
	else
		printf("-");
	if (mode & S_IXUSR)
		printf("x");
	else if (mode & S_ISUID)
		printf("s");
	else
		printf("-");
}

void	ft_print_file_type(int mode)
{
	mode &= S_IFMT;
	if (mode == S_IFIFO)
		printf("p");
	else if (mode == S_IFCHR)
		printf("c");
	else if (mode == S_IFDIR)
		printf("d");
	else if (mode == S_IFBLK)
		printf("b");
	else if (mode == S_IFREG)
		printf("-");
	else if (mode == S_IFLNK)
		printf("l");
	else if (mode == S_IFSOCK)
		printf("s");
	else if (mode == S_IFWHT)
		printf("0");
}

void	ft_print_file_permissions(int mode)
{
	ft_print_user_permissions(mode);
	ft_print_group_permissions(mode);
	ft_print_other_permissions(mode);
	printf(" ");
}

void	ft_print_time(char *time_str)
{
	int	i;

	if (!time_str)
		return ;
	i = 0;
	while (time_str[i] && time_str[i] != ' ')
		i++;
	printf("\"");
	while (time_str[++i] && time_str[i] != '\n')
		printf("%c", time_str[i]);
	printf("\" ");
}

void	ft_print_user_name(uid_t uid)
{
	struct passwd	*user_passwd;

	user_passwd = getpwuid(uid);
	if (!user_passwd)
		return ;
	printf("%s ", user_passwd->pw_name);
}

void	ft_print_group_name(gid_t gid)
{
	struct group	*group_info;

	group_info = getgrgid(gid);
	if (!group_info)
		return ;
	printf("%s ", group_info->gr_name);
}

int	ft_stat(char *file_name)
{
	t_stat	file_stat;

	lstat(file_name, &file_stat);
	printf("%d ", file_stat.st_dev);
	printf("%llu ", file_stat.st_ino);
	ft_print_file_type(file_stat.st_mode);
	ft_print_file_permissions(file_stat.st_mode);
	printf("%d ", file_stat.st_nlink);
	ft_print_user_name(file_stat.st_uid);
	ft_print_group_name(file_stat.st_gid);
	printf("%d ", file_stat.st_rdev);
	printf("%lld ", file_stat.st_size);
	ft_print_time(ctime(&(file_stat.st_atimespec.tv_sec)));
	ft_print_time(ctime(&(file_stat.st_mtimespec.tv_sec)));
	ft_print_time(ctime(&(file_stat.st_ctimespec.tv_sec)));
	ft_print_time(ctime(&(file_stat.st_birthtimespec.tv_sec)));
	printf("%d ", file_stat.st_blksize);
	printf("%lld ", file_stat.st_blocks);
	printf("%u ", file_stat.st_flags);
	printf("%s", file_name);
	printf("\n");
	return (0);
}
