#ifndef		LIBSTACK_H
# define	LIBSTACK_H

# include <stdio.h>
# include <stdlib.h>

typedef struct		s_stack
{
	int				content;
	struct s_stack	*prev;
	struct s_stack	*next;
}					t_stack;

int					top(t_stack **tail);
int					size(t_stack **head);
int					empty(t_stack **head);
void				clear(t_stack **head);
void				pop(t_stack **head, t_stack **tail);
t_stack				*push(t_stack **head, t_stack **tail, int content);
t_stack				*new(int content);

#endif
