*This project has been created as part of the 42 curriculum by thdeglos.*

# ft_printf

## Description

**ft_printf** is a re-implementation of the C standard library function `printf()`.
The goal is to learn how to write **variadic functions** (`va_list`, `va_start`,
`va_arg`, `va_copy`, `va_end`) and to structure code so that it stays easy to extend.

The library produced is `libftprintf.a`, exposing:

```c
int ft_printf(const char *, ...);
```

It returns the number of characters printed, like the original `printf()`.

### Supported conversions

| Conversion | Output                                         |
|------------|------------------------------------------------|
| `%c`       | A single character                             |
| `%s`       | A string (`(null)` if the pointer is NULL)     |
| `%p`       | A `void *` pointer in hexadecimal (`0x...`)    |
| `%d`       | A signed decimal integer                       |
| `%i`       | A signed integer in base 10                    |
| `%u`       | An unsigned decimal integer                    |
| `%x`       | An unsigned integer in lowercase hexadecimal   |
| `%X`       | An unsigned integer in uppercase hexadecimal   |
| `%%`       | A percent sign                                 |

The original `printf()` buffer management is intentionally **not** reimplemented:
output goes directly through `write()`. Only the mandatory part is implemented
(no bonus flags or field width).

### Algorithm and data structures

No complex data structure is needed. The design is a simple dispatcher:

1. **Parsing**: `ft_printf` walks the format string once. Regular characters are
   written as-is. When a `%` is found, the next character selects the conversion.
2. **Dispatch**: a single function (`ft_dispatch`) maps the conversion character to a
   dedicated handler (`ft_print_char`, `ft_print_str`, `ft_print_nbr`, `ft_print_hex`,
   `ft_print_ptr`...). Adding a new conversion only means adding one handler and one
   case, which keeps the code easy to extend.
3. **Argument access**: the `va_list` is created once and passed by reference to the
   dispatcher, so each handler consumes exactly the argument it needs with `va_arg`.
4. **Number conversion**: numbers are printed with a recursive base conversion
   (divide by the base, print the higher digits first, then the current digit). This
   avoids any `malloc`, so there is no risk of memory leaks, and handles `INT_MIN`
   and `UINT_MAX` by working on `long`/`unsigned long` values. `%p` reuses the
   hexadecimal handler and prints `(nil)` for a NULL pointer, like the original
   `printf()` on Linux.
5. **Return value**: every handler returns the number of bytes written (or `-1` if
   `write` fails), and `ft_printf` accumulates them into the final return value.

## Instructions

### Compilation

```sh
make          # builds libftprintf.a at the root of the repository
make clean    # removes object files
make fclean   # removes object files and libftprintf.a
make re       # fclean + all
```

The project is compiled with `cc -Wall -Wextra -Werror` and uses the `libft` folder
(built through its own Makefile). The archive is created with `ar`, and a banner is
displayed once the library is built.

### Usage

Include the header and link against the library:

```c
#include "ft_printf.h"

int main(void)
{
	ft_printf("Hello %s, you are %d years old (%x)\n", "42", 42, 42);
	return (0);
}
```

```sh
cc -Wall -Wextra -Werror main.c -L. -lftprintf -o test
./test
```

You can compare the output and the return value with the original `printf()`.

## Resources

- `man 3 printf`, `man 3 stdarg`, `man 2 write`
- [GNU C Library: Variadic Functions](https://www.gnu.org/software/libc/manual/html_node/Variadic-Functions.html)
- [cppreference: printf, format specifiers](https://en.cppreference.com/w/c/io/fprintf)
- [cppreference: var iadic arguments](https://en.cppreference.com/w/c/variadic)

### Use of AI

AI (Claude) was used as a reviewer and tutor: explaining concepts, reviewing functions I had written myself and pointing out bugs or Norm issues, suggesting simplifications that I chose to apply or not, and helping write the Makefile and this README.