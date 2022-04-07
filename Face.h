#pragma once
#include<iostream>
#include<algorithm>
#include <string>
#include <fstream>
#include <sstream>
#include <cstring>
#include <vector>
#include <math.h>

class Face
{
public:
    std::vector<Vertex> vertices;
    Normal face_normals;
};
