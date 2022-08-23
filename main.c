
#include "./ft_ls.h"
#include <stdio.h>//printf
#include <stdlib.h>

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
int	basic_ls(void)
{
	const char	*filename;
	DIR	*dirp = NULL;
	struct dirent	*dp = NULL;

	filename = "./";
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

int	file_info(char *filename)
{
	printf("The passed file is: %s\n", filename);
	printf("Name: \n");// a_crazy_file
	printf("Type: \n");//File
	printf("Modes: \n");//rwxr-xr-x
	printf("Number of links: \n");//1
	printf("Owner: \n");//zaz
	printf("Group: \n");//staff
	printf("Size: \n");//2142 octets
	printf("Last modification date: \n");//Sep 17 23:42
	return (0);
}

//ascii decimal values: l 108, R 82, a 97, r 114, t 116
int	get_arg_names(char *list, char *arg)
{
  char	*name;

  name = ft_strdup(arg);
  if (!name)
    exit(1);
  int	i;

	i = 1;
	if (arg[0] != '-')
	{
	  //add to list of arg_names
		printf("ls: %c: No such file or directory", arg[0]);
		return (1);
	}
	while (arg[i])
	{
		switch(arg[i])
		{
		case 'l':
			options = ((options) | o_l);
			break;
		case 'R':
			options = ((options) | o_R);
			break;
		case 'a':
			options = ((options) | o_a);
			break;
		case 'r':
			options = ((options) | o_r);
			break;
		case 't':
			options = ((options) | o_t);
			break;
		default:
			printf("ls: illegal option -- %c\nusage: ls [-ABCFGHLOPRSTUWabcdefghiklmnopqrstuwx1] [file ...]\n", arg[i]);
			exit(1);
		}
		i++;
	}
	return (options);
}

//ascii decimal values: l 108, R 82, a 97, r 114, t 116
int	get_options(int options, char *arg)
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
			printf("ls: illegal option -- %c\nusage: ls [-ABCFGHLOPRSTUWabcdefghiklmnopqrstuwx1] [file ...]\n", arg[i]);
			exit(1);
		i++;
	}
	return (options);
}

//check_args
int	process_input(int argc, char **argv, t_data *data)
{
	int	i;

	i = 1;
	while (i < argc)
	{
		if (argv[i][0] == '-')
		{
			if ((data->arg_file_count == 0) && argv[i][1])//to catch ls -
				data->options = get_options(data->options, argv[i]);
			else
			{
				printf("ls: %s: No such file or directory", argv[i]);
				data->ret = 1;
			}
		}
		else
		{
			get_arg_names(argv[i]);
			data->arg_file_count++:
		}
		i++;
	}
	return (0);
}

int	main(int argc, char **argv)
{
  //	const char	*filename;
	t_data	data;

	data.ret = 0;
	data.options = 0;
	data.arg_file_count = 0;
	//	data.arg_names = NULL;
	//	data.dir_files = NULL;
	//		int	options = 0;
//more checks to add:  IS okay: ls filename && ls -l filename
//more checks to add: NOT okay: ls filename -l && ls -l filename -l BEWARE!!!!! NOTE: both produce outputs, no such file or directory and then the ls filename output, other ls -l filename output
//	int	more_dirs = 0;
	process_input(argc, argv, &data);
	printf("OPTIONS: %d\n", data.options);
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
	return (0);
}
