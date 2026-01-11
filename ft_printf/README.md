*This project has been created as part of the 42 curriculum by jodos-sa.*

# ft_printf

## Description

This project is a reimplementation of the C standard library `printf` function. The primary objective is to gain a deep understanding of variadic functions (`va_args`) and formatted output, while following strict coding standards and memory management practices.

### Features
- Implementation of core conversion specifiers: `c`, `s`, `p`, `d`, `i`, `u`, `x`, `X`, `%`
- Implemetation of the bonus flags: `-`, `0`, `.`, `#`, ` `, `+`, `*` (Yes, one of them is a space)
- Custom format string parsing
- Variadic argument handling
- Memory-safe implementation with proper error handling

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
    ft_printf("Hello, %s!\n", "world");
    ft_printf("Number: %d, Hex: %x\n", 42, 42);
    return (0);
}
```

Compile with:
```bash
cc <your_file.c> -Iinc -L. -lftprintf -o <your_program>
```

## Resources

### Documentation
- `man 3 printf` - Standard printf function documentation
- Previous implementation of printf (used as reference)

### AI Usage
No AI tools were used in the development of this project's core functionality. The implementation is based on manual research, documentation reading, and personal coding effort.

[//]: <> (BANANA by jodos-sa)
