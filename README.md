*This project has been created as part of the 42 curriculum by jodos-sa.*

# ft_printf

## Description

This project is a reimplementation of the C standard library `printf` function. The primary objective is to gain a deep understanding of variadic functions (`va_args`) and formatted output, while following strict coding standards and memory management practices.

### Features
- **Core conversion specifiers**: `c`, `s`, `p`, `d`, `i`, `u`, `x`, `X`, `%`
- **Bonus flags**: `-`, `0`, `.`, `#`, ` `, `+`, `*` (yes, one of them is space)
  - `-`: Left-justify the output within the field width
  - `0`: Zero-padding for numeric values
  - `.`: Precision specifier for strings and numbers
  - `#`: Alternative form (0x prefix for hex)
  - ` `: Space before positive numbers
  - `+`: Force sign display for numbers
  - `*`: Dynamic width/precision from arguments
- Custom format string parsing engine
- Variadic argument handling with `va_list`
- Memory-safe implementation with proper error handling
- Modular architecture with separated parsing, formatting, and printing logic

## Instructions

### Compilation

Build the library:
```bash
make
```

This creates `libftprintf.a`, which can be linked to your projects.

### Testing

Build and run the included test suite:
```bash
make run
```

Or just compile the tester:
```bash
make test
```

### Cleaning

Remove object files:
```bash
make clean
```

Remove all generated files:
```bash
make fclean
```

Rebuild from scratch:
```bash
make re
```

### Usage Example

```c
#include "ft_printf.h"

int main(void)
{
    // Basic string and character printing
    ft_printf("Hello, %s!\n", "world");
    
    // Integer formatting with various flags
    ft_printf("Number: %d, Hex: %x, HEX: %X\n", 42, 42, 42);
    ft_printf("With sign: %+d, With space: % d\n", 42, 42);
    ft_printf("Zero-padded: %05d, Left-aligned: %-5d|\n", 42, 42);
    
    // Pointer and hex with alternative form
    void *ptr = &main;
    ft_printf("Pointer: %p, Hex with prefix: %#x\n", ptr, 255);
    
    // Precision control
    ft_printf("String precision: %.5s\n", "Hello, World!");
    ft_printf("Number precision: %.5d\n", 42);
    
    // Dynamic width with asterisk
    ft_printf("Dynamic width: %*d\n", 10, 42);
    
    return (0);
}
```

Compile with:
```bash
cc <your_file.c> -Iinc -L. -lftprintf -o <your_program>
```

## Project Structure

```
ft_printf_bonus/
├── inc/
│   └── ft_printf.h       # Main header with prototypes and structures
├── src/
│   ├── ft_printf.c       # Main entry point and format processing
│   ├── parser.c          # Format specifier parsing logic
│   ├── format.c          # Format structure initialization and validation
│   ├── flags.c           # Flag handling and application
│   ├── prints.c          # Basic type printing functions
│   ├── convert.c         # Type conversion utilities
│   ├── prepend.c         # Prefix handling (signs, 0x, padding)
│   ├── utils.c           # Numeric conversion utilities
│   └── string_utils.c    # String manipulation helpers
├── Makefile              # Build configuration
└── README.md             # This file
```

## Resources

### Documentation
- `man 3 printf` - Standard printf function documentation
- Previous implementation of printf (used as reference)

### AI Usage
No AI tools were used in the development of this project's core functionality. The implementation is based on manual research, documentation reading, and personal coding effort.

[//]: <> (BANANA by jodos-sa)
