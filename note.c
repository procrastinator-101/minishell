#include "ft_lexer/ft_lexer.h"
#include <fcntl.h>

typedef struct s_pipeline
{
	t_scmd				*scmd;
	struct s_pipeline	*next;
	char				cntrl_operator;
}						t_pipeline;

typedef struct s_scmd
{
	t_token			*tokens;
	char			**args;  // args
	struct s_scmd	*next;
}					t_scmd;

typedef struct s_token
{
	char			*str;
	char			*quotes;
	struct s_token	*next;
	char			type;
}					t_token;


// unset PWD OLDPWD 

// cd -
// bash: cd: OLDPWD not set



typedef struct s_envp
{
	char			*name;
	char			*value;
	int				isenv;	// to check
	struct s_envp	*next;
	struct s_envp	*previous;
}					t_envp;

// cd || env HOME
			// cd - || env OLDPWD (carful -asfvjb)
// path || chdir
// test with open first // fd = open("", O_RDONLY); close fd

// APPEND: open("our", O_CREAT | O_APPEND | O_WRONLY); >>
// READ: open ("our", O_RDONLY) <
// WRITE: open ("our", O_CREAT | O_WRONLY | O_TRUNC, 0644) >

int main ()
{
	char *file;
	int fd = open("our", O_CREAT | O_WRONLY, 0644);
	write(fd, "hello", 5);
	close(fd);
	return (0);
}

// open(name, )
// < sdg < sdg
