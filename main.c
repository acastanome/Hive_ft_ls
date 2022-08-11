
#include "./ft_ls.h"
#include <stdio.h>//printf

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
int	set_options(int *this_options, char *arg)
{
	int	i;

	i = 1;
	if (arg[0] != '-')
	{
		printf("ls: %c: No such file or directory", arg[0]);
		return (1);
	}
	while (arg[i])
	{
		switch(arg[i])
		{
		case 'l':
			*this_options = ((*this_options) | o_l);
			break;
		case 'R':
			*this_options = ((*this_options) | o_R);
			break;
		case 'a':
			*this_options = ((*this_options) | o_a);
			break;
		case 'r':
			*this_options = ((*this_options) | o_r);
			break;
		case 't':
			*this_options = ((*this_options) | o_t);
			break;
		default:
			printf("ls: illegal option -- %c\nusage: ls [-ABCFGHLOPRSTUWabcdefghiklmnopqrstuwx1] [file ...]\n", arg[i]);
			return (1);
		}
		i++;
	}
	return (0);
}

int	check_args(int argc, char **argv, int *this_options)
{
	int	i;

	i = 1;
//check argv[0] separately
//	if (ft_strcmp("./ft_ls", argv[0]) != 0)
//	{
//		printf("zsh: command not found: %s\n", argv[0]);
//	}
	while (i < argc)
	{
		if (set_options(this_options, argv[i]) == 1)
			return (1);
		i++;
	}
	return (0);//(this_options);
}

int	main(int argc, char **argv)
{
/*	const char	*filename;
	DIR	*dp = NULL;
*/
//	if (argc < 2)
//		return (0);

/*	if ((argc == 1) && argv)
	{
		list_dir_contents();
		printf("\nDEBUG: now without dot files\n");
		list_dir_contents_no_dot();
		}*/

	int	this_options = 0;
//more checks to add:  IS okay: ls filename && ls -l filename
//more checks to add: NOT okay: ls filename -l && ls -l filename -l BEWARE!!!!! NOTE: both produce outputs, no such file or directory and then the ls filename output, other ls -l filename output
//	int	more_dirs = 0;
	if (check_args(argc, argv, &this_options) == 1)
	{
		printf("MAIN: Invalid options\n");
		return (1);
	}
	if (this_options == 0)
		basic_ls();
	if (this_options == 4)
		basic_ls_a();
//		file_info(argv[1]);
//	printf("options are %d\n", this_options);
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
