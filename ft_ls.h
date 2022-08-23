
#ifndef	FT_LS_H
# define	FT_LS_H

#include <unistd.h>//write
#include <dirent.h>//opendir
#include "libft/libft.h"

typedef struct s_data
{
  int options;
  char	*arg_names;
  char	*dir_files;
}	t_data;

//enum for the options of ls, with values 1, 2, 4, 8, 16
enum options
{
	o_l = 1 << 0,
	o_R = 1 << 1,
	o_a = 1 << 2,
	o_r = 1 << 3,
	o_t = 1 << 4,
};

//DIR *opendir(const char *filename);		ret: pointer or NULL
//struct dirent *readdir(DIR *dirp);		ret: p to next dir entry, NULL when endofdir or error (then sets errno)
//												errno may be set to any of the values documented for the getdirentries(2) system call
//												NOTE: order of dirs is not specified, lexicogr or not
//int closedir(DIR *dirp);					ret: 0 success, failure -1 and sets errno

//stat	displays info about file. permissions for file not required, but all dirs listed in path must be searchable.
//		int	stat(const char *restrict path, struct stat *restrict buf);
//		if no arg: info about stdin fd
//		stat [-FLnq] [-f format | -l | -r | -s | -x] [-t timefmt] [file ...]
//		ret: 0 success, >0 if error
//		SHITLOADS OF USEFULL OPTIONS AND FORMATS :D

//readlink		way of invoking stat
//		readlink [-n] [file ...]
//		only the target of the symbolic link is printed.
//		If the given argument is not a symbolic link, readlink will print nothing and exit with an error.



//lstat
//		#include <sys/stat.h>
//		int	lstat(const char *restrict path, struct stat *restrict buf);
//	function is like stat() except if file is a symbolic link;
//	return values:	lstat(): link info,
//					stat(): info about file the link references.
//	For symbolic links, the st_mode member contains meaningful information when used with the file type macros,
//	and the st_size member contains the length of the pathname contained in the symbolic link.
//	File mode bits and the contents of the remaining members of the stat structure are unspecified.
//	The value returned in the st_size member is the length of the contents of the symbolic link, and does not count any trailing null.


//getpwuid		password database operations
//		#include <sys/types.h>
//		#include <pwd.h>
//		#include <uuid/uuid.h>
//		struct passwd *getpwuid(uid_t uid);
//USE NOT RECOMMENDED


//getgrgid		group database operations
//USE NOT RECOMMENDED

//listxattr		list extended attribute names
//		#include <sys/xattr.h>
//		ssize_t listxattr(const char *path, char *namebuf, size_t size, int options);
//sthg about data pairs
//		Return values: Success size of the extended attribute name list.
//						0 If no accessible extended attributes are associated with the given path or fd.
//						Failure -1 and errno is set (man explains how).


//getxattr		get an extended attribute value
//		#include <sys/xattr.h>
//		ssize_t getxattr(const char *path, const char *name, void *value, size_t size, u_int32_t position, int options);


//time		time command execution
//		time [-lp] utility
//		NOT SURE WHY WOULD NEED THIS
//		
//		
//		


//ctime		transform binary date and time values
//		#include <time.h>
//		char	*ctime(const time_t *clock);
//		take as an argument a time value representing the time in seconds since
//		the Epoch (00:00:00 UTC, January 1, 1970; see time(3)).
//		
//		adjusts the time value for the current time zone, in the same manner as localtime().
//		Return values: Success: pointer to a 26-character string of the form:
//								Thu Nov 24 18:22:48 1986\n\0		All of the fields have constant width.
//						Error: NULL and set errno to an appropriate value.


//write
//malloc
//free

//perror and strerror		system error messages
//		#include <stdio.h> for perror
//		#include <string.h> for strerror
//		both look up the error message string corresponding to an error number.
//		strerror() accepts an error number argument errnum and returns a pointer to the corresponding message string.
//		perror() finds the error message corresponding to the current value of the global variable errno (intro(2)) and
//			writes it, followed by a newline, to the standard error file descriptor.
//			If the argument s is non-NULL and does not point to the null character, this string is prepended to
//			the message string and separated from it by a colon and space (``: '');
//			otherwise, only the error message string is printed.
//		
//		sthg about errors returned when errno not recognized and their range, and if insufficient storage in strerrbuf

//exit


//bonus example maybe tcgetattr (for what)

# endif
