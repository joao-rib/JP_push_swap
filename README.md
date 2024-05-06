# JP_push_swap
This function takes an array of integers as an argument, and sorts them in ascending order. Only a handful of predefined operations may be used.

## Main Functions

### Operations

Function | Format | Prints | Description
--- | --- | --- | ---
swap | `void	swap(t_stack **stack, char stack_name)` | sa or sb | Swaps the positions of the first two nodes in a stack
push | `void	push(t_stack **stack_src, t_stack **stack_dst, char name_dst)` | pa or pb | Pushes the first node from stack_src to the top of stack_dst
rotate | `void	rotate(t_stack **stack, char stack_name)` | ra or rb | Moves the top node in a stack to the bottom of the same stack
reverse rotate | `void	rev_rotate(t_stack **stack, char stack_name)` | rra or rrb | Moves the bottom node in a stack to the top of the same stack
rotate both | `void	rotate_rr(t_stack **stack_a, t_stack **stack_b)` | rr | Applies 'rotate' to both stacks
reverse rotate both | `void	rev_rotate_rr(t_stack **stack_a, t_stack **stack_b)` | rrr | Applies 'reverse rotate' to both stacks
[UNUSED] swap both | `void	swap_ss(t_stack **stack_a, t_stack **stack_b)` | ss | Applies 'swap' to both stacks

### Utilities

Type | Function | Format | Description
--- | --- | --- | ---
Error handling | error_exit | `void	error_exit(t_stack **stack)` | Frees the memory in stack, prints an error message, then exits the program
Error handling | int_errors | `bool	int_errors(char *str)` | Checks if the content of str is valid as a number. Returns 'false', if so.
Sorting | check_sort | `bool	check_sort(t_stack *stack)` | Checks if the nodes in stack are sorted according to stack->num. Returns 'true' if so.
Sorting | min_to_top | `void	min_to_top(t_stack **stack, char stack_name, int l)` | Brings the node with the smallest number to the top of the stack (with l nodes), through mutliple 'rotate' or 'reverse rotate' operations in a row.
Sorting | sort_three | `void	sort_three(t_stack **stack, char stack_name)` | Sorts a stack of 3 nodes using a simple algorithm.
Sorting | sort_all | `void	sort_all(t_stack **stack_a, t_stack **stack_b)` | Complex function that sorts stack_a according to stack_a->num, utilising an empty stack_b for support.
Finding | findmax_int | `t_stack	*findmax_int(t_stack *stack)` | Finds and returns the node in stack with the highest stack->num value
Finding | findmin_int | `t_stack	*findmin_int(t_stack *stack)` | Finds and returns the node in stack with the lowest stack->num value
Finding | find_cheapest | `t_stack	*find_cheapest(t_stack *stack)` | Finds and returns the node in stack with the lowest stack->cost_total value
Finding | find_node_order | `t_stack	*find_node_order(t_stack *stack, int order)` | Finds and returns a specific node in stack, according to stack->order
Cataloguing | fill_the_order | `void	fill_the_order(t_stack *stack)` | Fills out the stack->order value for every node in stack, according to its current order
Cataloguing | fill_desired_order | `void	fill_desired_order(t_stack *stack, int l)` | Fills out the stack->final_order value for every node in stack, according to its intended final sorted order
Cataloguing | reset_cost | `void	reset_cost(t_stack *stack)` | Fills out the various stack->cost* values for every node in stack, with standard neutral values
Cataloguing | total_cost | `void	total_cost(t_stack *stack)` | Fills out the stack->cost_total value for a single node in stack, calculated with a sum of all other stack->cost* values
Pushing | push_it_bro | `void	push_it_bro(t_stack **stack_a, t_stack **stack_b, int len_a, int limit)` | Pushes several nodes from stack_a to stack_b, in the most efficient way possible.
Pushing | push_it_again | `void	push_it_again(t_stack **stack_a, t_stack **stack_b)` | Pushes several nodes from stack_b back to stack_a, in the most efficient way possible.

## Support Functions

### libft functions

Function | Format | Modified?
--- | --- | ---
ft_calloc | `void	*ft_calloc(size_t nmemb, size_t size)` | Same as libft
ft_memset | `void	*ft_memset(void *s, int c, size_t n)` | Same as libft
ft_strchr | `char	*ft_strchr(const char *str, int c)` | Improved efficiency
ft_substr | `char	*ft_substr(const char *str, unsigned int start, size_t len)` | Same as libft
ft_split | `char	**ft_split(const char *s, char c)` | Same as libft
ft_isdigit | `bool	ft_isdigit(int c)` | Function now returns a boolean value

### libft functions (struct)
Every function involving structures has been tweaked to work with the t_stack structure. Any previous reference to "content" now involves specific variables in t_stack.

Function | Format | Modified?
--- | --- | ---
ft_lstnew_int | `t_stack	*ft_lstnew_int(int num)` | Same as libft (ft_lstnew)
ft_lstsize | `int		ft_lstsize(t_stack *lst)` | Same as libft
ft_lstlast | `t_stack	*ft_lstlast(t_stack *lst)` | Same as libft
ft_lstadd_back | `void	ft_lstadd_back(t_stack **lst, t_stack *new)` | Function now considers a 'prev' pointer
ft_lstdelone | `void	ft_lstdelone(t_stack *lst)` | The 'del' argument has been removed.
ft_lstclear | `void	ft_lstclear(t_stack **lst)` | The 'del' argument has been removed.

### new libft functions

Function | Format | Description
--- | --- | ---
ft_atol | `long	ft_atol(const char *str)`  | Converts written number from a string str into long format, or 0 if there is none
ft_str_cmp | `bool	ft_str_cmp(const char *s1, const char *s2)` | Compare two strings s1 and s2. If they are the same, returns 'true'
ft_rptcheck_str | `bool	ft_rptcheck_str(char **str)` | Checks an array of strings str. If there is a repeated string, returns 'true'
ft_smaller_int | `int	ft_smaller_int(int n1, int n2)` | Returns the smaller value between n1 and n2

### ft_printf functions

Function | Format | Modified?
--- | --- | ---
ft_printf | `int	ft_printf(const char *string, ...)` | Same as ft_printf
ft_putchar_fd | `int	ft_putchar_fd(char c, int fd)` | Same as ft_printf
ft_putstr_fd | `int	ft_putstr_fd(char *str, int fd)` | Same as ft_printf
ft_putnbr_fd | `int	ft_putnbr_fd(long n, int fd)` | Same as ft_printf
ft_strlen | `size_t	ft_strlen(const char *str)` | Same as libft
ft_putnbr_ubase_fd | `int	ft_putnbr_ubase_fd(unsigned int nbr, char *base, int fd)` | Same as ft_printf
ft_putnbr_lbase_fd | `int	ft_putnbr_lbase_fd(unsigned long nbr, char *base, int fd)` | Same as ft_printf
ft_strchr | `char	*ft_strchr(const char *str, int c)` | Same as libft
