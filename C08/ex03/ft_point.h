#include "ft_point.h"

voidset_point(t_point *point) {
    point -> x = 42;
    point -> y = 21;
}

int main(void) {
    t_point point;
    set_point(&point);
    return 0;
}