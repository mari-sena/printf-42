_This project has been created as part of the 42 curriculum by mariafer._

## Description

| Specifier | Description |
|----------|-------------|
| `%c` | Prints a single character |
| `%s` | Prints a string |
| `%p` | Prints a pointer address in hexadecimal |
| `%d` | Prints a signed decimal integer |
| `%i` | Prints a signed decimal integer |
| `%u` | Prints an unsigned decimal integer |
| `%x` | Prints an unsigned integer in lowercase hexadecimal |
| `%X` | Prints an unsigned integer in uppercase hexadecimal |
| `%%` | Prints a percent sign |

## Instructions
To compile the library:
```bash
make
```

Example of main to teste the program:
```c
#include "ft_printf.h"

int	main(void)
{
	ft_printf("Hello, %s!\n", "world");
	ft_printf("Number: %d\n", 42);
	ft_printf("Hex: %x\n", 255);
	return (0);
}
```

Compile with:
```bash
cc main.c libftprintf.a
```

Then run:
```bash
./a.out
```

## Resources
+ man printf
+ man stdarg
+ [What are variadic functions (va_list) in C? - CodeVault](https://www.youtube.com/watch?v=oDC208zvsdg)
+ Peer discussion and testing during the 42 learning process
+ Tripouille printfTester

## AI Usage
AI was used as a study assistant during the development of this project.

It helped with:
+ Reviewing edge cases
+ Understanding pointer printing
+ Improving the README structure

The code implementation and final decisions were written and validated by the author of the project.

## Algorithm and Data Structure Explanation
The main algorithm of _ft_printf_ works by iterating through the format string one character at a time. When the current character is not %, the function simply prints it and increments the character counter. And when the current character is %, the next character is checked to determine which conversion should be executed.

The function reads the string until it finds %d. Then it retrieves the next argument from the variadic argument list and prints it as a signed decimal integer.

The project uses the va_list structure from <stdarg.h> to handle a variable number of arguments.

The main variadic macros used are:

| Macro | Purpose |
|-------|---------|
| va_start		|	Initializes the argument list	|
| va_arg		|	Retrieves the next argument		|
| va_end		|	Cleans up the argument list		|

For number conversions, the algorithm uses recursive or iterative base conversion.

For example, to print a number in hexadecimal, the function repeatedly divides the number by the base length and uses the remainder to select the correct character from the base string:

````
"0123456789abcdef"
````

Pointer addresses are printed by converting the pointer value to an unsigned integer type and then printing it in hexadecimal format, usually preceded by 0x.

The project does not require complex data structures. The most important structure used is va_list, which allows the function to access arguments dynamically during execution.