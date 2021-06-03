typedef struct s_pipeline
{
	t_scmd				*scmd;
	struct s_pipeline	*next;
	char				cntrl_operator;
}						t_pipeline;

typedef struct s_scmd
{
	t_token			*tokens;
	char			**args;
	struct s_scmd	*next;
}					t_scmd;

typedef struct s_token
{
	char			*str;
	char			*quotes;
	struct s_token	*next;
	char			type;
}					t_token;

