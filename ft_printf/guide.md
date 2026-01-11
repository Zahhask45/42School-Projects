# ft_printf Guide (Based on man 3 printf)

This guide details the implementation of `ft_printf`, aligned with the behavior described in `man 3 printf`.

## I. Format Specifier Prototype

A format specifier has the following structure:
`%[flags][width][.precision]type`

---

## II. Conversion Specifiers (The `type`)

This determines the type of conversion to be applied.

| Specifier | Output Type | Description |
| :---: | :--- | :--- |
| `%c` | `int` | Prints a single character. |
| `%s` | `char *` | Prints a string of characters. |
| `%p` | `void *` | Prints the pointer address in a system-specific hexadecimal format (e.g., `0x...`). |
| `%d`, `%i` | `int` | Prints a signed decimal integer. |
| `%u` | `unsigned int` | Prints an unsigned decimal integer. |
| `%x` | `unsigned int` | Prints an unsigned hexadecimal integer (using `abcdef`). |
| `%X` | `unsigned int` | Prints an unsigned hexadecimal integer (using `ABCDEF`). |
| `%%` | N/A | Prints a literal percent sign (`%`). No other flags, width, or precision apply. |

---

## III. Flags

Flags modify the conversion's behavior. They can appear in any order.

| Flag | Applies to | Description |
| :---: | :--- | :--- |
| `-` | All | **Left-justifies** the output within the field width. Overrides the `0` flag. |
| `+` | `d`, `i` | **Forces a sign** (`+` or `-`) to be prepended, even for positive numbers. Overrides the ` ` (space) flag. |
| ` ` (space) | `d`, `i` | If the number is positive, a **leading space is prepended**. Ignored if the `+` flag is used. |
| `#` | `x`, `X` | **Alternate Form**. For `x`, prepends `0x`. For `X`, prepends `0X`. This only applies to non-zero values. |
| `0` | `d`, `i`, `u`, `x`, `X` | **Pads with leading zeros** instead of spaces. Ignored if the `-` flag is used or if a precision is specified for integer types. |

---

## IV. Field Width

- **Description**: A non-negative integer that specifies a *minimum* field width for the output.
- **Syntax**:
    - `[number]`: e.g., `%10s`
    - `*`: The width is not specified in the format string, but as an additional `int` argument preceding the one to be formatted. e.g., `printf("%*d", 10, 42);`
- **Behavior**:
    - If the output is shorter than the width, it is padded with spaces (or zeros if the `0` flag is used).
    - Padding is on the left by default (right-alignment). The `-` flag causes padding on the right (left-alignment).
    - If the output is longer than the width, the field is expanded to fit the content; the value is never truncated.

---

## V. Precision

- **Description**: A non-negative integer that specifies the number of digits or characters. Its meaning depends on the type, ignores `-`.
- **Syntax**:
    - `.[number]`: e.g., `%.5s`
    - `.*`: The precision is not specified in the format string, but as an additional `int` argument preceding the one to be formatted. e.g., `printf("%.*s", 3, "hello");`
- **Behavior by Type**:
    - **`d, i, u, x, X`**: Specifies the *minimum* number of digits to appear. If the number has fewer digits, it is padded with leading zeros. A precision of `0` for a value of `0` results in no output (an empty string). This overrides the `0` flag.
    - **`s`**: Specifies the *maximum* number of bytes to be printed from the string.
    - **`c`**: Has no effect.
    - **`p`**: Behavior is undefined in the standard, but often it has no effect.

---

## VI. Rules of Precedence & Interaction

1.  **`+` vs ` ` (space)**: The `+` flag overrides the ` ` flag. If both are present, `+` is applied.
2.  **`-` vs `0`**: The `-` flag (left-justification) overrides the `0` flag. If both are present, the output is padded with spaces, not zeros.
3.  **Precision vs `0` flag (for numbers)**: For numeric types (`d, i, u, x, X`), specifying a precision causes the `0` flag to be ignored. The padding to meet the precision is always with zeros, and the padding to meet the width is with spaces.
    - `printf("|%08.5d|", 42);` -> `|   00042|` (Padded to 5 digits with zeros, then to 8 width with spaces).

---

## VII. Bonus: Dynamic Width/Precision with `*`

The `width` and `precision` can be specified by an asterisk `*`. When `*` is used, the value is read from the function arguments.

- **Example (Width)**: `printf("%*d", 5, 10);` is equivalent to `printf("%5d", 10);`
- **Example (Precision)**: `printf("%.*s", 3, "hello");` is equivalent to `printf("%.3s", "hello");`
- **Example (Both)**: `printf("%*.*s", 10, 5, "hello");` is equivalent to `printf("%10.5s", "hello");`

The arguments for `*` appear in the order: `(width, precision, value)`.
A negative width value is treated as the `-` flag followed by a positive width. e.g., `printf("%*d", -5, 10);` is equivalent to `printf("%-5d", 10);`.
