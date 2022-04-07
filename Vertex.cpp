#include "Vertex.h"

void Vertex::read_vertex(double a, double b, double c)
{
    x = a;
    y = b;
    z = c;
}  

bool Vertex:: operator== (Vertex temp)
{
    if (x == temp.x && y == temp.y && z == temp.z)
    {
        return true;
    }

    return false;
}