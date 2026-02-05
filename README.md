*This project has been created as part of the 42 curriculum by kdiab*

# ft_printf

## Description
`ft_printf` is a custom implementation of the standard C `printf` function.
The goal of this project is to replicate the behavior of `printf` for the mandatory conversion specifiers:
- `%c` : character
- `%s` : string
- `%p` : pointer
- `%d` / `%i` : signed decimal integers
- `%u` : unsigned decimal integers
- `%x` / `%X` : hexadecimal numbers
- `%%` : percent sign

This project demonstrates understanding of:
- Variadic functions (`stdarg.h`)
- Recursive and iterative algorithms
- Handling edge cases, like `NULL` strings and `INT_MIN`
- Proper return values (number of printed characters)

## Instructions
### Compilation
The project provides a `Makefile`. To compile the static library:

```bash
make
````

This will produce:

```
libftprintf.a
```

### Usage

1. Include the header in your C file:

```c
#include "ft_printf.h"
```

2. Compile your program and link with the library:

```bash
cc main.c -L. -lftprintf -o my_program
```

> `-L.` tells the compiler to look for libraries in the current directory
> `-lftprintf` links `libftprintf.a`

3. Run your program:

```bash
./my_program
```

4. Optional Makefile commands:

```bash
make clean    # Removes object (.o) files
make fclean   # Removes object files and libftprintf.a
make re       # Rebuilds everything
```

### Sample `main.c`

```c
#include "ft_printf.h"

int main(void)
{
    char *str = "42 ft_printf";
    void *ptr = NULL;

    ft_printf("Hello, %s!\n", str);
    ft_printf("Character: %c\n", 'A');
    ft_printf("Pointer: %p\n", ptr);
    ft_printf("Decimal: %d, Unsigned: %u\n", -42, 42);
    ft_printf("Hex lower: %x, Hex upper: %X\n", 255, 255);
    ft_printf("Percent sign: %%\n");

    return 0;
}
```

## Resources
- [YouTube tutorial on Vardia Functions](https://www.youtube.com/watch?v=RDIGFsFpCfA)
- AI assistance: ChatGPT was used to edit and improve the README file for clarity, formatting, and completeness.
## Chosen Algorithm & Data Strucutre
### Algorithm

#### Variadic argument handling:
- ft_printf uses va_list to iterate through arguments.
- Each conversion specifier triggers the corresponding helper function.
#### Printing logic:
- Characters and strings: iterate through each character and write to stdout.
- Integers (signed/unsigned): printed recursively by dividing the number by 10 until the base case (single digit) is reached.
- Hexadecimal numbers: similar recursive division by 16.
- Pointers: cast to unsigned long and printed as hexadecimal prefixed with 0x. Special case: NULL pointers print (nil).
#### Edge cases handling:
- NULL strings → (null)
- INT_MIN → -2147483648
- % → prints a single %
- Return value always equals total number of printed characters.
### Data Structures
- No advanced data structures are required.
- Static variable not used here (no persistent state needed beyond recursion and va_list).
- Recursion acts as a stack for multi-digit number processing.