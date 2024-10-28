/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsindres <dsindres@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/27 13:25:05 by artberna          #+#    #+#             */
/*   Updated: 2024/10/28 09:40:53 by dsindres         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

# include "my_library/my_library.h"

/******************************************************************************
#                                    ARTHUR                                   *
#*****************************************************************************/


// valeur de retour des <<
// CTRL D
// bash-5.1$ echo $?
// 0

// CTRL C
// bash-5.1$ echo $?
// 130

// a corriger / implementer
// exit code pour $? instead of sig_code et si C D ou \ exit code = sig code

// "CTRL C" SIGINT
// TERMINAL : OK
// CHILD PROCESS : OK
// HDOC : OK

// "CTRL \" SIGQUIT
// TERMINAL : OK
// CHILD PROCESS: OK
// HDOC : OK

// "CTRL D"
// TERMINAL : OK
// CHILD PROCESS: Ok
// HDOC : OK

typedef struct s_cmds	t_cmds;

# define IS_TOKEN "<>|\'\""
# define PIPE_ERROR "minishell: syntax error near unexpected token \'|\'\n"
# define NL_ERROR "minishell: syntax error near unexpected token 'new_line'\n"
# define OR_ERROR "minishell: syntax error near unexpected token '>'\n"
# define IR_ERROR "minishell: syntax error near unexpected token '<'\n"
# define APP_ERROR "minishell: syntax error near unexpected token '>>'\n"
# define HDOC_ERROR "minishell: syntax error near unexpected token '<<'\n"
# define QUOTE_ERROR "minishell: syntax error near unexpected token 'quote'\n"
# define SIGOFFSET 128

extern int	g_sig_code;

typedef struct s_env
{
	char	**tab_env;
	int		len;
	char	*oldpwd;
}				t_env;

typedef enum e_token_type
{
	TOK_SPC,
	TOK_STR,
	TOK_S_Q,
	TOK_D_Q,
	TOK_IR,
	TOK_OR,
	TOK_APP,
	TOK_HDOC,
	TOK_PIPE,
}	t_token_type;

typedef struct s_token
{
	t_token_type	type;
	int				index;
	char			*token;
	struct s_token	*next;
	struct s_token	*prev;
}					t_token;

typedef struct s_gdata
{
	unsigned int	nb_command;
	char			*input;
	int				exit_code;
	int				heredoc;
	t_token			*s_tok;
	t_cmds			*s_cmds;
	t_env			s_env;
}					t_gdata;

typedef struct s_cmds
{
	unsigned int	index;
	unsigned int	nb_redir;
	char			**cmd;
	int				flag_error;
	const char		*hdoc;
	struct s_token	*redir;
	struct s_gdata	*g_data;
	struct s_cmds	*next;
	struct s_cmds	*prev;
	int				saved_stdout;
	int				saved_stdin;
}					t_cmds;

// Main
void		free_minishell(t_cmds *cmd, t_token *tok, char *input);

// Utils Parsing
void		exit_error(const char *s);
void		free_double(char **tab);

// Lexer
t_token		*lexer(t_gdata *data);

// Lexer Handler
t_token		*tokenize(char *s);

// Lexer Utils
t_token		*create_token(const char *s, int len, t_token_type type);
void		add_token(t_token **tok, t_token *new_node);
void		free_token(t_token *tok);
void		print_token(t_token *tok); //debug

// Error Input Handler
int			error_handler(t_token **tok, t_gdata *data);

// Parser
t_cmds		*parser(t_token *tok, t_gdata *data);

// Parser Handler
void		parsenize(t_cmds *cmd, t_token *tok, t_gdata *data);

// Parser Utils
void		extend_cmd(t_cmds **cmd, t_gdata *data);
int			is_redir(t_token_type type);
int			is_cmd(t_token_type type);
void		free_cmd(t_cmds *cmd);
void		print_cmd(t_cmds *cmd); //debug

// Handle Dollar
void		handle_dollar(t_token *tok, t_gdata *data);

//Handle Redir
void		handle_redir(t_cmds *cmd, t_token **tok);

//Handle Signal
void		init_signal(int option, t_gdata *data);

//Handle Exit Code
int			get_exit_code(int status);

/******************************************************************************
#                                    DIEGO                                    *
#*****************************************************************************/

//Minishell_exec
void		minishell_exec(t_cmds *cmds, t_gdata *data);
void		multiple_commands(t_cmds *cmds, t_env *struct_env, pid_t *pid);
void		parent_process(int *fd, int *infile);
void		child_process(t_cmds *temp, int infile, int *fd, t_env *struct_env);

//Minishell_exec_2
void		one_command(t_cmds *cmds, t_env *struct_env);
void		child_process_one_command(t_cmds *cmds, t_env *struct_env);
void		redirection(t_cmds *cmds, t_env *struct_env);
pid_t		*init_pid(t_cmds *cmds);
void		all_waitpid(t_cmds *cmds, pid_t *pid);

//Manage_heredoc
void		manage_hdoc(t_cmds *cmds);
const char	*create_file_name(int i);
void		create_hdoc_file(t_cmds *cmds, const char *str);
int			input_heredoc(t_token *temp_tok, char *line, int fd);

//Manage_heredoc_2
void		affect_heredoc_name(t_cmds *cmds);
void		supp_all_hdoc_file(t_cmds *cmds);

//Execution
void		execution(t_cmds *cmds, t_env *struct_env);
int			is_it_builtins(t_cmds *cmds);
void		exec_command(t_cmds *cmds, t_env *struct_env);
void		exec_command_2(t_cmds *cmds, t_env *struct_env);
char		*find_command(char *command, t_env *struct_env);

//Change_redirection
int			change_in_stdout(t_cmds *cmds);
int			saved_stdout(t_cmds *cmds, int file_fd);
int			change_out_stdout(t_cmds *cmds);
int			change_in_stdin(t_cmds *cmds);
int			change_out_stdin(t_cmds *cmds);

//Change_redirection_utils
t_token		*last_token_node(t_cmds *cmds, int flag);
int			create_file(t_cmds *cmds);
int			create_file_2(t_token *temp);
int			verif_file(t_cmds *cmds);
int			verif_file_2(char *file);

//Builtins_fonctions
int			builtins_fonctions(t_cmds *t_cmds, t_env *struct_env);
void		my_env(t_env *struct_env);
void		my_pwd(void);
void		my_echo(char **cmd);
void		my_echo_2(char **cmd);

//Builtins_export
void		my_export(t_env *struct_env, t_cmds *t_cmds);
int			is_new_var_env(t_env *struct_env, t_cmds *t_cmds);
int			is_new_var_env_2(t_env *struct_env, t_cmds *t_cmds, int j);
int			good_input(t_cmds *cmds);
void		print_var(char **tab_var);

//Builtins_export_2
void		my_export_create(t_env *struct_env, t_cmds *t_cmds, int len);
void		my_export_create_2(t_env *struct_env, t_cmds *t_cmds,
				char **tab_var, int index);
void		my_export_replace(t_env *struct_env, t_cmds *t_cmds, int index);
void		my_export_replace2(t_env *struct_env, t_cmds *t_cmds, int index);

//Builtins_export_3
void		export_sort(t_env *struct_env);
int			ascii_order(char *str, char *str_2);
char		**export_copy_tab(char **tab_to_copy);

//Builtins_unset
void		my_unset(t_env *struct_env, t_cmds *t_cmds);
int			valide_value_env(char **env, char **cmd, int index);
void		my_unset_delete(t_env *struct_env, int index);

//Builtins_exit ARTHUR
int			my_exit(t_env *struct_env, t_cmds *t_cmds);

//Builtins_cd
void		my_cd(t_env *struct_env, t_cmds *t_cmds);
void		my_cd_2(t_env *struct_env, t_cmds *t_cmds, DIR *path);
void		cd_dir_env(t_env *struct_env, char *dir);
void		cd_dir_move_up(t_env *struct_env, char *dir);
void		cd_dir_path(t_env *struct_env, char *path);

//Builtins_cd_2
char		*display_dir(char *cmd, char *old_dir);
char		*ft_getenv(t_env *struct_env, char *dir, t_gdata *data);
void		replace_dir(t_env *struct_env, char *old_dir,
				char *new_dir, char *new_old_dir);
void		replace_dir_2(t_env *struct_env, char *new_old_dir);

//Utils
void		putstr(char *str);
char		**copy_tab(char **env, int len);
void		free_double_tab(char **tab, int i);
int			init_struct_env(char **env, t_env *struct_env);
void		ft_error(char *str, t_cmds *cmds);

//Utils_exec_2
void		my_error(char *command, char *message, t_cmds *cmds);
void		fork_error(t_cmds *temp, int *fd);
int			is_it_heredoc(t_cmds *cmds);
int			is_it_heredoc_2(t_cmds *cmds);
void		file_fd_value(t_token *in, int *file_fd, t_cmds *cmds);

#endif