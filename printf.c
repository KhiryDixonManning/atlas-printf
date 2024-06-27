#include <stdio.h>
#include <stdarg.h>

/**
 * _printf - Custom printf function that formats and prints data to stdout.
 * @format: Character string composed of zero or more directives.
 *
 * Return: Number of characters printed (excluding the null byte).
 */
int _printf(const char *format, ...)
{
    if (format == NULL)
    {
        return (-1);
    }

    int count = 0;  // Character count
    va_list args;   // Argument list

    // Initialize the argument list
    va_start(args, format);

    // Process the format string
    for (const char *p = format; *p != '\0'; p++)
    {
        // If the current character is not '%', print it as is
        if (*p != '%')
        {
            putchar(*p);
            count++;
            continue;
        }

        // Move to the next character after '%'
        p++;

        // Handle the conversion specifier
        switch (*p)
        {
            case 'c':
            {
                // Print a character
                char c = (char) va_arg(args, int);
                putchar(c);
                count++;
                break;
            }
            case 's':
            {
                // Print a string
                const char *s = va_arg(args, const char *);
                while (*s)
                {
                    putchar(*s);
                    count++;
                    s++;
                }
                break;
            }
            case '%':
            {
                // Print a percent symbol
                putchar('%');
                count++;
                break;
            }
            default:
            {
                // Print unknown specifier as is
                putchar('%');
                putchar(*p);
                count += 2;
                break;
            }
        }
    }

    // Clean up the argument list
    va_end(args);

    return count;  // Return the number of characters printed
}

int main()
{
    int chars_printed = _printf("Character: %c\n" "String: %s\n" "Percent: %%\n", 'A', "Hello, World!");
    printf("Characters printed: %d\n", chars_printed);
    return 0;
}
