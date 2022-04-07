#pragma once
#include<iostream>
#include<algorithm>
#include <string>
#include <fstream>
#include <sstream>
#include <cstring>
#include <vector>
#include <math.h>

class Normal
{
public:
    double i, j, k;

    void read_normals(double a, double b, double c);
    bool operator== (Normal temp);
};
