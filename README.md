# Custom printf Function (_printf)

This project introduces a custom printf function in C, designed with simplicity and basic functionality in mind.

## Function Overview

The `_printf` function aims to replicate core features of the standard `printf` function, albeit with a limited set of format specifiers for now. It currently supports:

- `%c`: Print a single character.
- `%s`: Print a null-terminated string.
- `%%`: Print a percent sign (%).

## Implementation Flow

```plaintext
+----------------------------------------+
|              Start                     |
+----------------------------------------+
    |
    v
+----------------------------------------+
|  Check if format is NULL               |
+----------------------------------------+
    |
+---+------------------------------------+
|   | [Yes]                              |
|   v                                    |
| Return -1                              |
|                                        |
+----------------------------------------+
|   | [No]                               |
|   v                                    |
| Initialize count = 0                   |
|                                        |
+----------------------------------------+
    |
+---v------------------------------------+
| Loop through format string             |
+---+------------------------------------+
    |
+---v------------------------------------+
| [End of string]                        |
| Return count                           |
+----------------------------------------+
    |
+---v------------------------------------+
| Check for '%' character                |
+---+------------------------------------+
    |
+---v------------------------------------+
| [Yes]                                  |
| Move to next character                 |
+---+------------------------------------+
    |
+---v------------------------------------+
| Check specifier ('c', 's', '%', ...)   |
+---+------------------------------------+
    |
+---v------------------------------------+
| [Process specifier]                    |
| Print corresponding argument           |
+---+------------------------------------+
    |
+---v------------------------------------+
| Update count                           |
+---+------------------------------------+
    |
    v
+---+------------------------------------+
| Continue loop                          |
+---+------------------------------------+    
```

## Example Usage

```c
#include <stdio.h>

int main() {
    // Example usage of _printf
    int chars_printed = _printf("Character: %c\nString: %s\nPercent: %%\n", 'A', "Hello, World!");
    printf("Characters printed: %d\n", chars_printed);
    return 0;
}
```

## Compilation Instructions

To compile the example program, use the following command:

```bash
gcc -o printf printf_example.c
```

This will output:

```
Character: A
String: Hello, World!
Percent: %
Characters printed: 26
```
