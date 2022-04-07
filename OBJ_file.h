#pragma once
#include<iostream>
#include<algorithm>
#include <string>
#include <fstream>
#include <sstream>
#include <cstring>
#include <vector>
#include <math.h>

class Obj_File
{
public:
    std::vector<Face> faces_of_triangles;
   // static int size_vertex;       // to store size of vector containing unique vertex
   // static int size_normal;      // to store size of vector containing unique normal

    void read_obj_file(std::string filename);  //function to read input obj file
  //  void write_obj_file(std::string inputpath, class Transform transform_object, int view_option);  // function to write into output obj file

    void write_obj_file(std::string inputpath);

    void write_obj_file(std::string inputpath, std::vector<Face> all_faces_data, int view_option);
};
