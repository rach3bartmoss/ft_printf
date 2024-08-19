# ft_printf
This is my implementation of standard printf function in C language, this project is part of the Common Core Projects at 42porto curriculum

A quick walkthrough inside the project:

-> It works with the following format specifiers: % d i s c p u x X

-> Handle the following flags: # + (space)

-> Accept the following options: width 0 - .(precision)

The main goal is of this project is to learn some interesting concepts in C, such as variadic functions and make a deep look into the original printf itself,
my implementation involves the use of two structs to store the values of flags, and a struct to keep track of the argument, a custom function called 
parse_flags.c its reponsible to fill the structure with the values passed as argument into the function.  Then the ft_printf function will begin to explore the many possibilities based on the flags and the arguments.

I invite you to git clone this repository and apply into your projects.

instructions:

git@github.com:rach3bartmoss/ft_printf.git

make (to compile and create the static library)

Any suggestion dont hesitate to reach out
