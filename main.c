
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

int	list_dir_contents(void)
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

int	list_dir_contents_no_dot(void)
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

int	main(int argc, char **argv)
{
/*	const char	*filename;
	DIR	*dp = NULL;
*/
//	if (argc < 2)
//		return (0);

	if ((argc == 1) && argv)
	{
		list_dir_contents();
		printf("\nDEBUG: now without dot files\n");
		list_dir_contents_no_dot();
	}
	if (argc == 2)
	{
		file_info(argv[1]);
	}
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
