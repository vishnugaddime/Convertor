#pragma once
#include<iostream>
#include<algorithm>
#include <string>
#include <fstream>
#include <sstream>
#include <cstring>
#include <vector>
#include <math.h>

class Vertex
{
public:
    double x, y, z;

    void read_vertex(double a, double b, double c);
    bool operator== (Vertex temp);
};
