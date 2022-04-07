#pragma once
#include<iostream>
#include<algorithm>
#include <string>
#include <fstream>
#include <sstream>
#include <cstring>
#include <vector>
#include <math.h>

class Transform
{
public:

	std::vector<Face> transform_all_face;

	void translate_file(std::vector<Face> triangle_data, int option, double distance);
	void rotate_file(std::vector<Face> triangle_data , int option, double angle);
	void circular_pattern(std::vector<Face> triangle_data, std::vector<Face> original_data, int option, int n);
	void square_pattern(std::vector<Face> triangle_data, std::vector<Face> original_data, int option, int total_cubes, double side);
};