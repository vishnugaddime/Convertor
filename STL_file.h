#pragma once
#include<iostream>
#include<algorithm>
#include <string>
#include <fstream>
#include <sstream>
#include <cstring>
#include <vector>
#include <math.h>

class STL_file
{
public:
    std::vector<Face> all_triangle_data;

    void read_stl_file(std::string filename);   // function to read stl file 
   // void write_stl_file(std::string inputpath,class Transform transform_object, int view_option);  // function to write into output stl file

    void write_stl_file(std::string inputpath);
    void write_stl_file(std::string inputpath, std::vector<Face> all_faces_data);
};
