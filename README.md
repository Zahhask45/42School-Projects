*This project has been created as part of the 42 curriculum by jodos-sa.*

# libft - 42School Project

## Description

**libft** is a custom C library that reimplements essential functions from the C standard library, along with additional utility functions. This project serves as the foundation for many subsequent 42 projects, providing a personal collection of commonly used functions.

The goal of this project is to:
- Gain a deeper understanding of standard C library functions by reimplementing them from scratch
- Create a reusable library for future 42 projects
- Master memory management, pointer manipulation, and basic data structures in C
- Learn proper code organization and library creation using Makefiles

This library includes string manipulation, memory operations, character checks, linked list utilities, and file descriptor operations.

## Instructions

### Compilation

The library can be compiled using the provided Makefile:

```bash
# Compile the library
make

# This will generate libft.a, a static library file
```

### Makefile Targets

- `make` or `make all` - Compiles the library and creates `libft.a`
- `make clean` - Removes object files
- `make fclean` - Removes object files and the library archive
- `make re` - Recompiles the entire library from scratch

### Installation & Usage

1. Clone the repository:
```bash
git clone <repository-url>
cd 42School-Projects
git switch libft
```

2. Compile the library:
```bash
make
```

3. Include the library in your project:
```c
#include "inc/libft.h"
```

4. Compile your program with the library:
```bash
cc your_program.c -L. -lft -I./inc -o your_program
```

### Requirements

- C compiler (gcc or clang)
- Make

## Library Documentation

### Function Categories

#### Character Check Functions
- `ft_isalpha` - Check if character is alphabetic
- `ft_isdigit` - Check if character is a digit
- `ft_isalnum` - Check if character is alphanumeric
- `ft_isascii` - Check if character is ASCII
- `ft_isprint` - Check if character is printable
- `ft_toupper` - Convert character to uppercase
- `ft_tolower` - Convert character to lowercase

#### String Manipulation Functions
- `ft_strlen` - Calculate string length
- `ft_strlcpy` - Size-bounded string copy
- `ft_strlcat` - Size-bounded string concatenation
- `ft_strchr` - Locate first occurrence of character in string
- `ft_strrchr` - Locate last occurrence of character in string
- `ft_strncmp` - Compare strings up to n characters
- `ft_strnstr` - Locate substring in string with size limit
- `ft_strdup` - Duplicate string
- `ft_substr` - Extract substring from string
- `ft_strjoin` - Concatenate two strings
- `ft_strtrim` - Trim characters from beginning and end of string
- `ft_split` - Split string by delimiter into array
- `ft_strmapi` - Apply function to each character of string
- `ft_striteri` - Apply function to each character with index

#### Memory Functions
- `ft_memset` - Fill memory with constant byte
- `ft_memcpy` - Copy memory area
- `ft_memmove` - Copy memory area (overlap-safe)
- `ft_memchr` - Scan memory for character
- `ft_memcmp` - Compare memory areas
- `ft_bzero` - Zero a byte string
- `ft_calloc` - Allocate and zero-initialize memory

#### Conversion Functions
- `ft_atoi` - Convert string to integer
- `ft_itoa` - Convert integer to string

#### File Descriptor Functions
- `ft_putchar_fd` - Output character to file descriptor
- `ft_putstr_fd` - Output string to file descriptor
- `ft_putendl_fd` - Output string with newline to file descriptor
- `ft_putnbr_fd` - Output integer to file descriptor

#### Linked List Functions
The library includes a complete linked list implementation using the `t_list` structure:

```c
typedef struct s_list {
    void            *content;
    struct s_list   *next;
} t_list;
```

Functions:
- `ft_lstnew` - Create new list element
- `ft_lstadd_front` - Add element at beginning of list
- `ft_lstadd_back` - Add element at end of list
- `ft_lstsize` - Count elements in list
- `ft_lstlast` - Get last element of list
- `ft_lstdelone` - Delete single element
- `ft_lstclear` - Delete and free all elements
- `ft_lstiter` - Iterate through list and apply function
- `ft_lstmap` - Create new list by applying function to each element

### Technical Details

- **Compilation**: Uses `-Wall -Wextra -Werror` flags for strict error checking
- **Norminette**: All code follows the 42 Norm coding standard
- **Memory Safety**: All functions handle edge cases and prevent memory leaks
- **No Global Variables**: Pure functions without side effects (except I/O functions)

## Resources

### Official Documentation
- [C Standard Library Reference](https://en.cppreference.com/w/c)
- [GNU C Library Manual](https://www.gnu.org/software/libc/manual/)
- [man pages](https://man7.org/linux/man-pages/) - Unix manual pages for standard functions

### Tutorials & Articles
- [42 Intra Resources](https://intra.42.fr/) - Internal 42 documentation and peer discussions

### Tools
- [GDB Debugging Guide](https://www.sourceware.org/gdb/documentation/)
- [Valgrind Memory Checker](https://valgrind.org/)

### AI Usage

**No AI tools were used in this project.** This project was completed in 2022 as part of the 42 curriculum, written entirely from scratch using traditional learning resources including manual pages, C documentation, peer collaboration, and debugging tools.

---

[//]: <> (Banana by jodos-sa)
