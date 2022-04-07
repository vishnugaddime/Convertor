#include"Normal.h"

void Normal:: read_normals(double a, double b, double c)
{
    i = a;
    j = b;
    k = c;
}

bool Normal:: operator== (Normal temp)
{
    return i == temp.i && j == temp.j && k == temp.k;
}
