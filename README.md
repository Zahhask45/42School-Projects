# 42 School Projects 🎓

A collection of projects completed as part of the 42 School curriculum. Each project demonstrates proficiency in systems programming, algorithms, and software engineering principles.

## 📚 Repository Structure

This repository follows a specific branching strategy:
- **`main` branch**: Contains all projects in one place
- **Project-specific branches**: Each project has its own dedicated branch (e.g., `libft`, `ft_printf`, `philo`) containing only that specific project

## 🚀 Projects

### [Libft](../../tree/libft)
Your first C library implementation - a collection of standard functions recreated from scratch.
- **Branch**: `libft`
- **Topics**: C programming, memory management, string manipulation, linked lists
- **Skills**: Understanding of standard library functions, memory allocation

### [ft_printf](../../tree/ft_printf)
Recreation of the famous printf function from the C standard library.
- **Branch**: `ft_printf`
- **Topics**: Variadic functions, parsing, formatted output
- **Skills**: Format specifiers, type conversion, buffer management

### [Push_Swap](../../tree/main)
A sorting algorithm project using two stacks with a limited set of operations.
- **Branch**: `main` (also available individually)
- **Topics**: Algorithm optimization, sorting, complexity analysis
- **Skills**: Stack operations, algorithm design, efficiency optimization

### [Pipex](../../tree/main)
Recreation of shell pipe mechanism and process handling.
- **Branch**: `main` (also available individually)
- **Topics**: Process creation, pipes, file descriptors
- **Skills**: System calls (fork, pipe, dup2), inter-process communication

### [Philosophers](../../tree/philo)
The classic dining philosophers problem - a multithreading synchronization exercise.
- **Branch**: `philo`
- **Topics**: Multithreading, mutexes, deadlock prevention
- **Skills**: Thread synchronization, race condition handling, resource sharing

### [Fract'ol](../../tree/main)
A fractal exploration program with real-time rendering.
- **Branch**: `main` (also available individually)
- **Topics**: Computer graphics, mathematical visualization, event handling
- **Skills**: MLX library, fractal algorithms (Mandelbrot, Julia), color mapping

## 🔧 How to Use

### Clone the entire repository:
```bash
git clone <repository-url>
cd 42School-Projects
```

### Access a specific project:
```bash
# Option 1: Switch to the project-specific branch
git switch libft

# Option 2: Navigate to project folder on main branch
cd Fract\'ol
```

### Build and run (example for projects with Makefiles):
```bash
make
./program_name
```

## 📖 About 42 School

42 is a private, nonprofit, tuition-free computer programming school. The curriculum is project-based and peer-evaluated, focusing on practical skills development without traditional lectures or teachers.

## 🛠️ Technologies & Concepts

- **Languages**: C
- **Core Concepts**: 
  - Memory management
  - Algorithm design and optimization
  - Unix system programming
  - Multithreading and synchronization
  - Graphics programming
  - Process and inter-process communication

## 📝 Notes

- Each project includes its own Makefile for compilation
- Projects follow the 42 School Norm (coding standards)
- All code is written in C (C99 standard or later)

## 📬 Contact

For questions or collaboration opportunities, feel free to reach out!

---

*"The best way to predict the future is to invent it."* - Alan Kay
