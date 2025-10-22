#include <unistd.h>
#include "ft_stock_str.h"

static void ft_putstr(char *s)
{
    if (!s)
        return ;
    while (*s)
        write(1, s++, 1);
}

static void ft_putnbr(int nb)
{
    char    c;
    
    c = (nb % 10) + '0';
    if (nb == -2147483648)
    {
        ft_putstr("-2147483648");
        return ;
    }
    if (nb < 0)
    {
        write(1, '-', 1);
        nb = -nb;
    }
    if (nb >= 10)
        ft_putnbr(nb / 10);
    ft_putchar(c);
}

void    ft_show_tab(struct s_stock_str *par)
{
    int i;

    if (!par)
        return ;
    i = 0;
    while (par[i].str)
    {
        ft_putstr(par[i].str);
        write(1, '\n', 1);
        ft_putnbr(par[i].size);
        write(1, '\n', 1);
        ft_putstr(par[i].copy);
        write(1, '\n', 1);
        i++;
    }
}