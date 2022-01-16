# push_swap
A project that needs to sort an array of numbers in ascending order using only a certain set of commands
***
The following commands are allowed:

`sa` - swap a - swap the first 2 elements at the top of stack a. Do nothing if there
is only one or no elements)

`sb` - swap b - swap the first 2 elements at the top of stack b. Do nothing if there
is only one or no elements)

`ss` - sa and sb at the same time

`pa` - push a - take the first element at the top of b and put it at the top of a. Do
nothing if b is empty

`pb` - push b - take the first element at the top of a and put it at the top of b. Do
nothing if a is empty

`ra` - rotate a - shift up all elements of stack a by 1. The first element becomes
the last one

`rb` - rotate b - shift up all elements of stack b by 1. The first element becomes
the last one

`rr` - ra and rb at the same time

`rra` - reverse rotate a - shift down all elements of stack a by 1. The last element
becomes the first one

`rrb` - reverse rotate b - shift down all elements of stack b by 1. The last element
becomes the first one

`rrr` - rra and rrb at the same time
***
> ***Bonus***
> 
> There is also a special checker that checks if the list has been sorted or not
> 
> It takes an array of numbers as input. Then the commands to be applied are entered
> 
> The checker returns OK if the array is sorted, and KO if not
> 
> Example: `./checker 5 2 4 1 3` 
> 
> Next, you will need to enter the commands from the list above, which the checker will apply to the list and return the result
> 
> Also, the checker can be run in conjunction with the main program.
> 
> For example (in bash): `A='6 9 4 1 5 8 5 0 7'; ./push_swap $A | ./checker $A`


Compilation commands:

`make` - compilation

`make re` - recompilation (deleting everything and compiling again)

`make clean` - deleting object files (.o)

`make fclean` - deleting object files (.o) and executable file

`make bonus` - checker compilation
***
***Visually represented example of sorting***

<img src="https://media.giphy.com/media/XNQ98xTBVQV5b1Ns5r/giphy.gif" width="500" height="400" />
