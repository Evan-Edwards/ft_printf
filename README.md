# ft_printf

## Description
This project is a custom implementation of the printf function in C. ft_printf replicates the behavior of the original printf function from the C standard library, handling various format specifiers and converting input into formatted output. This implementation provides a deep understanding of variadic functions in C and string formatting mechanisms.

## Installation
Clone the repository and compile the library:

```bash
git clone https://github.com/Evan-Edwards/ft_printf.git
cd ft_printf
make
```

This will create the `libftprintf.a` static library.

## Usage
To use ft_printf in your project:

1. Include the header in your C files:
```c
#include "ft_printf.h"
```

2. Compile your project with the library:
```bash
gcc your_file.c -L. -lftprintf
```

3. Basic usage example:
```c
#include "ft_printf.h"

int main(void)
{
    ft_printf("Hello, %s!\n", "world");
    ft_printf("Number: %d\n", 42);
    return (0);
}
```

## Supported Format Specifiers

### Basic Specifiers
- `%c` - Single character
- `%s` - String of characters
- `%p` - Pointer address in hexadecimal
- `%d` - Decimal (base 10) number
- `%i` - Integer in base 10
- `%u` - Unsigned decimal number
- `%x` - Hexadecimal (base 16) number in lowercase
- `%X` - Hexadecimal (base 16) number in uppercase
- `%%` - Prints the % character

### Return Value
- Returns the number of characters printed
- Returns -1 if an error occurs

## Error Handling
- Null string handling for %s
- Invalid format specifier handling
- Memory allocation failure handling

## Limitations
- Does not handle float/double types
- Does not implement length modifiers (h, l, ll, etc.)
- Does not handle precision and field width

Created as part of the 42 curriculum.