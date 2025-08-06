#include <stdarg.h>
#include <unistd.h>

void print_char(char c)
{
    write(1, &c, 1);
}

void print_str(const char *s)
{
    while (*s)
    {
        print_char(*s++);
    }
}

void print_int(int n)
{
    char buffer[12];
    int i = 0;
    int negativo = 0;

    if (n == 0)
    {
        print_char('0');
        return;
    }

    if (n < 0)
    {
        negativo = 1;
        n = -n;
    }

    while (n > 0)
    {
        buffer[i++] = (n % 10) + '0';
        n /= 10;
    }

    if (negativo)
    {
        buffer[i++] = '-';
    }

    while (i--)
    {
        print_char(buffer[i]);
    }
}

void my_printf(const char *format, ...)
{
    va_list args;
    va_start(args, format);

    for (const char *p = format; *p != '\0'; p++)
    {
        if (*p == '%' && *(p + 1))
        {
            p++; // pula o %
            if (*p == 's')
            {
                const char *str = va_arg(args, const char *);
                print_str(str);
            }
            else if (*p == 'd')
            {
                int num = va_arg(args, int);
                print_int(num);
            }
            else
            {
                print_char('%');
                print_char(*p);
            }
        }
        else
        {
            print_char(*p);
        }
    }

    va_end(args);
}

int main()
{
    my_printf("Meu printf: %s - numero: %d\n", "teste", 12345);
    my_printf("Negativo: %d, Zero: %d\n", -42, 0);
    return 0;
}
