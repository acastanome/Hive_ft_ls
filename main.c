
#include "./ft_ls.h"
#include <stdio.h>//printf
#include <stdlib.h>
#include <sys/stat.h>//lstat

//test what opendir returns for file as arg: returns NULL
/*int	main(int argc, char **argv)
{
	const char	*filename;
	DIR	*dp = NULL;

	if (argc < 2)
		return (0);
	filename = argv[1];
	dp = opendir(filename);
	if (dp == NULL)
	{
		printf("dp returned NULL\n");
		return (0);
	}
	else
		printf("dp returned a pointer\n");
	closedir(dp);
	return (0);
}
*/

//int	list_dir_contents(void)
int	basic_ls_a(void)
{
	const char	*filename;
	DIR	*dirp = NULL;
	struct dirent	*dp = NULL;

	filename = "./";
	dirp = opendir(filename);
	if (dirp == NULL)
	{
		printf("DEBUG: dirp returned NULL\n");
		return (0);
	}
	else
	{

		printf("DEBUG: dirp returned a pointer\n");
//		dp = readdir(dirp);
//		if (dp == NULL)
//			printf("DEBUG: dp returned NULL\n");
		while ((dp = readdir(dirp)) != NULL)
		{
			printf("%s\n", dp->d_name);
		}
	}
	closedir(dirp);
	return (0);
}

//int	list_dir_contents_no_dot(void)
int	basic_ls(const char *filename)
{
//	const char	*filename;
	DIR	*dirp = NULL;
	struct dirent	*dp = NULL;

//	filename = "./";
	dirp = opendir(filename);
	if (dirp == NULL)
	{
//		printf("DEBUG: dirp returned NULL\n");
		return (0);
	}
	else
	{
//		printf("DEBUG: dirp returned a pointer\n");
//		dp = readdir(dirp);
//		if (dp == NULL)
//			printf("DEBUG: dp returned NULL\n");
		while ((dp = readdir(dirp)) != NULL)
		{
			if (dp->d_name[0] != '.')
				printf("%s\n", dp->d_name);
		}
	}
	closedir(dirp);
	return (0);
}

//ascii decimal values: l 108, R 82, a 97, r 114, t 116
//Original message:
//printf("ft_ls: illegal option -- %c\nusage: ./ft_ls [-ABCFGHLOPRSTUWabcdefghiklmnopqrstuwx1] [file ...]\n", arg[i]);
int	set_options(int options, char *arg)
{
	int	i;

	i = 1;
	while (arg[i])
	{
		if (arg[i] == 'l')
			options = ((options) | o_l);
		else if (arg[i] == 'R')
			options = ((options) | o_R);
		else if (arg[i] == 'a')
			options = ((options) | o_a);
		else if (arg[i] == 'r')
			options = ((options) | o_r);
		else if (arg[i] == 't')
			options = ((options) | o_t);
		else
		{
			printf("ft_ls: illegal option -- %c\nusage: ./ft_ls [-Ralrt] [file ...]\n", arg[i]);
			exit(1);
		}
		i++;
	}
	return (options);
}

//check_args
void	process_input(int argc, char **argv, t_data *data)
{
	int	i;
	int	j;

	i = 1;
	while (i < argc)
	{
		if (argv[i][0] == '-')
		{
			if ((data->arg_file_count == 0) && argv[i][1])//to catch ls -
				data->options = set_options(data->options, argv[i]);
			else
			{
				printf("ft_ls: %s: No such file or directory\n", argv[i]);
				data->ret = 1;
			}
		}
		else
			data->arg_file_count++;
		i++;
	}
	if (data->arg_file_count != 0)
	{
		data->arg_names = (char **)malloc(sizeof(char *) * (data->arg_file_count + 1));
//		printf("process_input(): data->arg_names is size %d + 1\n", data->arg_file_count);
		if (!(data->arg_names))
		{
			printf("process_input(): FAILED TO ALLOCATE data->arg_names\n");
			exit(1);
		}
		i = 1;
		j = 0;
		while (i < argc)
		{
			if (argv[i][0] != '-')
			{
				data->arg_names[j] = ft_strdup(argv[i]);
//				printf("process_input(): data->arg_names has one more item\n");
				if (!(data->arg_names[j]))
				{
					printf("process_input(): FAILED TO ALLOCATE data->arg_names[j]\n");
					exit(1);
				}
				j++;
			}
			i++;
		}
		data->arg_names[j] = NULL;
		//TESTPRINT
		int x = 0;
		while (x < data->arg_file_count)
		{
			printf("ARG LIST:\n");
			printf("%s\n", *(data->arg_names + x));
			x++;
		}
	}
}

/*
void	sort_list(t_data *data, char *list)
{}
*/

int	main(int argc, char **argv)
{
  //	const char	*filename;
	t_data	data;

	data.ret = 0;
	data.options = 0;
	data.arg_file_count = 0;
	data.arg_names = NULL;
	process_input(argc, argv, &data);
	printf("OPTIONS: %d\n", data.options);//TESTPRINT
//SORT ARG LIST depending on options
	if (data.arg_names)
	{
		basic_ls(data.arg_names[0]);
		printf("\nlstat\n");
//		file_info(data.arg_names[0]);
		file_permissions(data.arg_names[0]);
//		sort_list(&data);
//		basic_ls(data.arg_names[0]);
	}
	/*	if (options == 0)
		basic_ls();
	if (options == 4)
	basic_ls_a();*/
//		file_info(argv[1]);
//	printf("options are %d\n", options);
//		check_args(argc, argv);
/*	filename = argv[1];
	dp = opendir(filename);
	if (dp == NULL)
	{
		printf("DEBUG: dp returned NULL\n");
		return (0);
	}
	else
		printf("DEBUG: dp returned a pointer\n");
	closedir(dp);
*/
	exit(0);
//	return (0);
}
