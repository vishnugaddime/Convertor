#include "Vertex.h"
#include "Normal.h"
#include "Face.h"
#include "OBJ_file.h"
#include "STL_file.h"
#include "OBJ_file.h"
#include "Transform.h"

void Transform::translate_file(std::vector<Face> triangle_data,int option , double distance)
{
	if (option == 1) // translate along x-axis
	{
		int count =0;
		Face face_obj;  
		Vertex vertex_obj;

		for (int i = 0; i < triangle_data.size(); i++)
		{
			//push back normals

			face_obj.face_normals.i = triangle_data[i].face_normals.i;
			face_obj.face_normals.j = triangle_data[i].face_normals.j;
			face_obj.face_normals.k = triangle_data[i].face_normals.k;

			for (int j = 0; j < triangle_data[i].vertices.size(); j++)
			{
				//push back vertices

				vertex_obj.x = triangle_data[i].vertices[j].x + distance;
				vertex_obj.y = triangle_data[i].vertices[j].y;
				vertex_obj.z = triangle_data[i].vertices[j].z;
				
				if (count == triangle_data[i].vertices.size()-1)
				{
					face_obj.vertices.push_back(vertex_obj);
					count = 0;
					transform_all_face.push_back(face_obj);
					face_obj.vertices.clear();
				}

				else
				{
					face_obj.vertices.push_back(vertex_obj);
					count++;
				}
			}

		}
	}

	else if (option == 2)  // for translate along y- axis
	{
		int count = 0;
		Face face_obj;
		Vertex vertex_obj;

		for (int i = 0; i < triangle_data.size(); i++)
		{
			face_obj.face_normals.i = triangle_data[i].face_normals.i;
			face_obj.face_normals.j = triangle_data[i].face_normals.j;
			face_obj.face_normals.k = triangle_data[i].face_normals.k;

			for (int j = 0; j < triangle_data[i].vertices.size(); j++)
			{
				vertex_obj.x = triangle_data[i].vertices[j].x;
				vertex_obj.y = triangle_data[i].vertices[j].y + distance;
				vertex_obj.z = triangle_data[i].vertices[j].z;

				if (count == triangle_data[i].vertices.size() - 1)
				{
					face_obj.vertices.push_back(vertex_obj);
					count = 0;
					transform_all_face.push_back(face_obj);
					face_obj.vertices.clear();
				}

				else
				{
					face_obj.vertices.push_back(vertex_obj);
					count++;
				}
			}

		}
	}

	else if (option == 3)  // translate along z-axis
	{
		int count = 0;
		Face face_obj;
		Vertex vertex_obj;

		for (int i = 0; i < triangle_data.size(); i++)
		{
			face_obj.face_normals.i = triangle_data[i].face_normals.i;
			face_obj.face_normals.j = triangle_data[i].face_normals.j;
			face_obj.face_normals.k = triangle_data[i].face_normals.k;

			for (int j = 0; j < triangle_data[i].vertices.size(); j++)
			{
				vertex_obj.x = triangle_data[i].vertices[j].x;
				vertex_obj.y = triangle_data[i].vertices[j].y;
				vertex_obj.z = triangle_data[i].vertices[j].z + distance;

				if (count == triangle_data[i].vertices.size() - 1)
				{
					face_obj.vertices.push_back(vertex_obj);
					count = 0;
					transform_all_face.push_back(face_obj);
					face_obj.vertices.clear();
				}

				else
				{
					face_obj.vertices.push_back(vertex_obj);
					count++;
				}
			}

		}
	}

	else if (option == 4)  //translate along x, y and z-axis
	{
		int count = 0;
		Face face_obj;
		Vertex vertex_obj;

		for (int i = 0; i < triangle_data.size(); i++)
		{
			face_obj.face_normals.i = triangle_data[i].face_normals.i;
			face_obj.face_normals.j = triangle_data[i].face_normals.j;
			face_obj.face_normals.k = triangle_data[i].face_normals.k;

			for (int j = 0; j < triangle_data[i].vertices.size(); j++)
			{
				vertex_obj.x = triangle_data[i].vertices[j].x + distance;
				vertex_obj.y = triangle_data[i].vertices[j].y + distance;
				vertex_obj.z = triangle_data[i].vertices[j].z + distance;

				if (count == triangle_data[i].vertices.size() - 1)
				{
					face_obj.vertices.push_back(vertex_obj);
					count = 0;
					transform_all_face.push_back(face_obj);
					face_obj.vertices.clear();
				}

				else
				{
					face_obj.vertices.push_back(vertex_obj);
					count++;
				}
			}

		}
	}

	else if (option == 5)
	{
		int count = 0;
		Face face_obj;
		Vertex vertex_obj;

		for (int i = 0; i < triangle_data.size(); i++)
		{
			face_obj.face_normals.i = triangle_data[i].face_normals.i;
			face_obj.face_normals.j = triangle_data[i].face_normals.j;
			face_obj.face_normals.k = triangle_data[i].face_normals.k;

			for (int j = 0; j < triangle_data[i].vertices.size(); j++)
			{
				vertex_obj.x = triangle_data[i].vertices[j].x - distance;
				vertex_obj.y = triangle_data[i].vertices[j].y;
				vertex_obj.z = triangle_data[i].vertices[j].z;

				if (count == triangle_data[i].vertices.size() - 1)
				{
					face_obj.vertices.push_back(vertex_obj);
					count = 0;
					transform_all_face.push_back(face_obj);
					face_obj.vertices.clear();
				}

				else
				{
					face_obj.vertices.push_back(vertex_obj);
					count++;
				}
			}

		}
	}
}

void Transform::rotate_file(std::vector<Face> triangle_data ,int option, double angle)
{

	double x_center, y_center, z_center, average_x = 0, average_y = 0, average_z = 0;

	for (int q = 0; q < triangle_data.size(); q++)
	{
		for (int r = 0; r < triangle_data[q].vertices.size(); r++)
		{
			average_x = average_x + triangle_data[q].vertices[r].x;
		}
	}

	for (int q = 0; q < triangle_data.size(); q++)
	{
		for (int r = 0; r < triangle_data[q].vertices.size(); r++)
		{
			average_y = average_x + triangle_data[q].vertices[r].y;
		}
	}

	for (int q = 0; q < triangle_data.size(); q++)
	{
		for (int r = 0; r < triangle_data[q].vertices.size(); r++)
		{
			average_z = average_x + triangle_data[q].vertices[r].z;
		}
	}

	x_center = average_x / 36;
	y_center = average_y / 36;
	z_center = average_z / 36;


	if (option == 1) //rotate along x-axis
	{
		int count = 0;
		Face face_obj;
		Vertex vertex_obj;

		for (int i = 0; i < triangle_data.size(); i++)
		{
			double temp_j = triangle_data[i].face_normals.j;
			double temp_k = triangle_data[i].face_normals.k;

			face_obj.face_normals.i = triangle_data[i].face_normals.i;
			face_obj.face_normals.j = (temp_j - y_center) * cos(angle) - (temp_k - z_center) * sin(angle);
			face_obj.face_normals.k = (temp_j - y_center) * sin(angle) + (temp_k - z_center) * cos(angle);

			for (int j = 0; j < triangle_data[i].vertices.size(); j++)
			{
				double temp_y = triangle_data[i].vertices[j].y;
				double temp_z = triangle_data[i].vertices[j].z;

				vertex_obj.x = triangle_data[i].vertices[j].x;
				vertex_obj.y = (temp_y - y_center) * cos(angle) - (temp_z - z_center) * sin(angle);
				vertex_obj.z = (temp_y - y_center) * sin(angle) + (temp_z - z_center) * cos(angle);

				if (count == triangle_data[i].vertices.size() - 1)
				{
					face_obj.vertices.push_back(vertex_obj);
					count = 0;
					transform_all_face.push_back(face_obj);
					face_obj.vertices.clear();
				}

				else
				{
					face_obj.vertices.push_back(vertex_obj);
					count++;
				}
			}

		}
	}

	else if (option == 2)  //rotate along y-axis
	{

		int count = 0;
		Face face_obj;
		Vertex vertex_obj;

		/*for (int i = 0; i < triangle_data.size(); i++)
		{
			double temp_i = triangle_data[i].face_normals.i;
			double temp_k = triangle_data[i].face_normals.k;

			face_obj.face_normals.i = temp_k * sin(angle) + temp_i * cos(angle);
			face_obj.face_normals.j = triangle_data[i].face_normals.j;
			face_obj.face_normals.k = temp_k  * cos(angle) - temp_i  * sin(angle);

			for (int j = 0; j < triangle_data[i].vertices.size(); j++)
			{
				double temp_x = triangle_data[i].vertices[j].x;
				double temp_z = triangle_data[i].vertices[j].z;

				vertex_obj.x = temp_z * sin(angle) + temp_x * cos(angle);
				vertex_obj.y = triangle_data[i].vertices[j].y;
				vertex_obj.z = temp_z * cos(angle) - temp_x * sin(angle);

				if (count == triangle_data[i].vertices.size() - 1)
				{
					face_obj.vertices.push_back(vertex_obj);
					count = 0;
					transform_all_face.push_back(face_obj);
					face_obj.vertices.clear();
				}

				else
				{
					face_obj.vertices.push_back(vertex_obj);
					count++;
				}
			}

		}*/

		for (int i = 0; i < triangle_data.size(); i++)
		{
			double temp_i = triangle_data[i].face_normals.i;
			double temp_k = triangle_data[i].face_normals.k;

			face_obj.face_normals.i = ((temp_k - z_center) * sin(angle) + (temp_i - x_center) * cos(angle)) + x_center;
			face_obj.face_normals.j = triangle_data[i].face_normals.j;
			face_obj.face_normals.k = ((temp_k - z_center) * cos(angle) - (temp_i - x_center) * sin(angle)) + z_center;

			for (int j = 0; j < triangle_data[i].vertices.size(); j++)
			{
				double temp_x = triangle_data[i].vertices[j].x;
				double temp_z = triangle_data[i].vertices[j].z;

				vertex_obj.x = ((temp_z - z_center) * sin(angle) + (temp_x + x_center) * cos(angle)) + x_center;
				vertex_obj.y = triangle_data[i].vertices[j].y;
				vertex_obj.z = ((temp_z - z_center) * cos(angle) - (temp_x + x_center) * sin(angle)) + z_center;

				if (count == triangle_data[i].vertices.size() - 1)
				{
					face_obj.vertices.push_back(vertex_obj);
					count = 0;
					transform_all_face.push_back(face_obj);
					face_obj.vertices.clear();
				}

				else
				{
					face_obj.vertices.push_back(vertex_obj);
					count++;
				}
			}
		}



	
	}
	
	else if (option == 3) //rotate along z-axis
	{	
		int count = 0;
		Face face_obj;
		Vertex vertex_obj;

		for (int i = 0; i < triangle_data.size(); i++)
		{
			double temp_i = triangle_data[i].face_normals.i;
			double temp_j = triangle_data[i].face_normals.j;

			face_obj.face_normals.i = (temp_i - x_center) * cos(angle) - (temp_j - y_center) * sin(angle);
			face_obj.face_normals.j = (temp_i - x_center) * sin(angle) + (temp_j - y_center) * cos(angle);
			face_obj.face_normals.k = triangle_data[i].face_normals.k;

			for (int j = 0; j < triangle_data[i].vertices.size(); j++)
			{
				double temp_x = triangle_data[i].vertices[j].x;
				double temp_y = triangle_data[i].vertices[j].y;

				vertex_obj.x = (temp_x - x_center) * cos(angle) - (temp_y - y_center) * sin(angle);
				vertex_obj.y = (temp_x - x_center) * sin(angle) + (temp_y - y_center) * cos(angle);
				vertex_obj.z = triangle_data[i].vertices[j].z;

				if (count == triangle_data[i].vertices.size() - 1)
				{
					face_obj.vertices.push_back(vertex_obj);
					count = 0;
					transform_all_face.push_back(face_obj);
					face_obj.vertices.clear();
				}

				else
				{
					face_obj.vertices.push_back(vertex_obj);
					count++;
				}
			}

		}		
	}

	else
	{
		std::cout << "wrong selection" << std::endl;
	}
}


void Transform::circular_pattern(std::vector<Face>triangle_data, std::vector<Face> original_data, int option, int n)
{
	if (option == 1) //rotate along x-axis
	{
		int count = 0;
		double angle;
		Face face_obj;
		Vertex vertex_obj;

		for(int z=0; z < n; z++)
		{ 
			angle = z * (360/n)* 0.01744;
			for (int i = 0; i < triangle_data.size(); i++)
			{
				double temp_j = triangle_data[i].face_normals.j - original_data[i].face_normals.j;
				double temp_k = triangle_data[i].face_normals.k - original_data[i].face_normals.k;

				double j_new = temp_j * cos(angle) - temp_k * sin(angle);
				double z_new = temp_j * sin(angle) + temp_k * cos(angle);

				face_obj.face_normals.i = triangle_data[i].face_normals.i;
				face_obj.face_normals.j = j_new + original_data[i].face_normals.j;
				face_obj.face_normals.k = z_new + original_data[i].face_normals.k;

				for (int j = 0; j < triangle_data[i].vertices.size(); j++)
				{
					double temp_y = triangle_data[i].vertices[j].y - original_data[i].vertices[j].y;
					double temp_z = triangle_data[i].vertices[j].z - original_data[i].vertices[j].z;

					double y_new = temp_j * cos(angle) - temp_k * sin(angle);
					double z_new = temp_j * sin(angle) + temp_k * cos(angle);

					vertex_obj.x = triangle_data[i].vertices[j].x;
					vertex_obj.y = y_new + original_data[i].vertices[j].y;
					vertex_obj.z = z_new + original_data[i].vertices[j].z;

					if (count == triangle_data[i].vertices.size() - 1)
					{
						face_obj.vertices.push_back(vertex_obj);
						count = 0;
						transform_all_face.push_back(face_obj);
						face_obj.vertices.clear();
					}

					else
					{
						face_obj.vertices.push_back(vertex_obj);
						count++;
					}
				}
			}
		}
	}

	else if (option == 2)  //rotate along y-axis
	{

		int count = 0;
		double angle;
		Face face_obj;
		Vertex vertex_obj;

		for (int z = 0; z < n; z++)
		{
			angle = z * (360 / n) * 0.01744;
			for (int i = 0; i < triangle_data.size(); i++)
			{
				double temp_i = triangle_data[i].face_normals.i - original_data[i].face_normals.i;
				double temp_k = triangle_data[i].face_normals.k - original_data[i].face_normals.k;

				double i_new = temp_k * sin(angle) + temp_i * cos(angle);
				double k_new = temp_k * cos(angle) - temp_i * sin(angle);

				face_obj.face_normals.i = i_new + original_data[i].face_normals.i;
				face_obj.face_normals.j = triangle_data[i].face_normals.j;
				face_obj.face_normals.k = k_new + original_data[i].face_normals.k;

				for (int j = 0; j < triangle_data[i].vertices.size(); j++)
				{
					double temp_x = triangle_data[i].vertices[j].x - original_data[i].vertices[j].x;
					double temp_z = triangle_data[i].vertices[j].z - original_data[i].vertices[j].z;

					double x_new = temp_z * sin(angle) + temp_x * cos(angle);
					double z_new = temp_z * cos(angle) - temp_x * sin(angle);

					vertex_obj.x = x_new + original_data[i].vertices[j].x;
					vertex_obj.y = triangle_data[i].vertices[j].y;
					vertex_obj.z = z_new + original_data[i].vertices[j].z;

					if (count == triangle_data[i].vertices.size() - 1)
					{
						face_obj.vertices.push_back(vertex_obj);
						count = 0;
						transform_all_face.push_back(face_obj);
						face_obj.vertices.clear();
					}

					else
					{
						face_obj.vertices.push_back(vertex_obj);
						count++;
					}
				}
			}
		}
	}

	else if (option == 3) //rotate along z-axis
	{
		int count = 0;
		double angle;
		Face face_obj;
		Vertex vertex_obj;


		for (int z = 0; z < n; z++)
		{

			angle = z * (360 / n) * 0.01744;
			for (int i = 0; i < triangle_data.size(); i++)
			{
				double temp_i = triangle_data[i].face_normals.i - original_data[i].face_normals.i;
				double temp_j = triangle_data[i].face_normals.j - original_data[i].face_normals.j;

				double i_new = temp_i * cos(angle) - temp_j * sin(angle);
				double j_new = temp_i * sin(angle) + temp_j * cos(angle);

				face_obj.face_normals.i = i_new + original_data[i].face_normals.i;
				face_obj.face_normals.j = j_new + original_data[i].face_normals.j;
				face_obj.face_normals.k = triangle_data[i].face_normals.k;

				for (int j = 0; j < triangle_data[i].vertices.size(); j++)
				{
					double temp_x = triangle_data[i].vertices[j].x - original_data[i].vertices[j].x;
					double temp_y = triangle_data[i].vertices[j].y - original_data[i].vertices[j].y;

					double x_new = temp_x * cos(angle) - temp_y * sin(angle);
					double y_new = temp_x * sin(angle) + temp_y * cos(angle);

					vertex_obj.x = x_new + original_data[i].vertices[j].x;
					vertex_obj.y = y_new + original_data[i].vertices[j].y;
					vertex_obj.z = triangle_data[i].vertices[j].z;

					if (count == triangle_data[i].vertices.size() - 1)
					{
						face_obj.vertices.push_back(vertex_obj);
						count = 0;
						transform_all_face.push_back(face_obj);
						face_obj.vertices.clear();
					}

					else
					{
						face_obj.vertices.push_back(vertex_obj);
						count++;
					}
				}
			}
		}
	}

	else
	{
		std::cout << "wrong selection" << std::endl;
	}
}

void Transform::square_pattern(std::vector<Face> triangle_data, std::vector<Face> original_data, int option, int total_cubes, double side)
{
	/*if (option == 1) // translate along x-axis
	{
		int count = 0;
		Face face_obj;
		Vertex vertex_obj;
		for (int z = 0; z < n; z++)
		{
			for (int i = 0; i < triangle_data.size(); i++)
			{
				face_obj.face_normals.i = triangle_data[i].face_normals.i;
				face_obj.face_normals.j = triangle_data[i].face_normals.j;
				face_obj.face_normals.k = triangle_data[i].face_normals.k;

				for (int j = 0; j < triangle_data[i].vertices.size(); j++)
				{
					if (z == 0)
					{
						vertex_obj.x = triangle_data[i].vertices[j].x;
						vertex_obj.y = triangle_data[i].vertices[j].y;
						vertex_obj.z = triangle_data[i].vertices[j].z + side;

						if (count == triangle_data[i].vertices.size() - 1)
						{
							face_obj.vertices.push_back(vertex_obj);
							count = 0;
							transform_all_face.push_back(face_obj);
							face_obj.vertices.clear();
						}

						else
						{
							face_obj.vertices.push_back(vertex_obj);
							count++;
						}
					}

					else if (z == 1)
					{
						vertex_obj.x = triangle_data[i].vertices[j].x;
						vertex_obj.y = triangle_data[i].vertices[j].y - (side * 2);
						vertex_obj.z = triangle_data[i].vertices[j].z + side;

						if (count == triangle_data[i].vertices.size() - 1)
						{
							face_obj.vertices.push_back(vertex_obj);
							count = 0;
							transform_all_face.push_back(face_obj);
							face_obj.vertices.clear();
						}

						else
						{
							face_obj.vertices.push_back(vertex_obj);
							count++;
						}
					}

					else if (z == 2)
					{
						vertex_obj.x = triangle_data[i].vertices[j].x;
						vertex_obj.y = triangle_data[i].vertices[j].y - (side * 2);
						vertex_obj.z = triangle_data[i].vertices[j].z - side;

						if (count == triangle_data[i].vertices.size() - 1)
						{
							face_obj.vertices.push_back(vertex_obj);
							count = 0;
							transform_all_face.push_back(face_obj);
							face_obj.vertices.clear();
						}

						else
						{
							face_obj.vertices.push_back(vertex_obj);
							count++;
						}
					}

					else if (z == 3)
					{
						vertex_obj.x = triangle_data[i].vertices[j].x;
						vertex_obj.y = triangle_data[i].vertices[j].y;
						vertex_obj.z = triangle_data[i].vertices[j].z - side;

						if (count == triangle_data[i].vertices.size() - 1)
						{
							face_obj.vertices.push_back(vertex_obj);
							count = 0;
							transform_all_face.push_back(face_obj);
							face_obj.vertices.clear();
						}

						else
						{
							face_obj.vertices.push_back(vertex_obj);
							count++;
						}
					}

					else if (z == 4)
					{
						vertex_obj.x = triangle_data[i].vertices[j].x;
						vertex_obj.y = triangle_data[i].vertices[j].y;
						vertex_obj.z = triangle_data[i].vertices[j].z;

						if (count == triangle_data[i].vertices.size() - 1)
						{
							face_obj.vertices.push_back(vertex_obj);
							count = 0;
							transform_all_face.push_back(face_obj);
							face_obj.vertices.clear();
						}

						else
						{
							face_obj.vertices.push_back(vertex_obj);
							count++;
						}
					}

					else if (z == 5)
					{
						vertex_obj.x = triangle_data[i].vertices[j].x;
						vertex_obj.y = triangle_data[i].vertices[j].y - side;
						vertex_obj.z = triangle_data[i].vertices[j].z + side;

						if (count == triangle_data[i].vertices.size() - 1)
						{
							face_obj.vertices.push_back(vertex_obj);
							count = 0;
							transform_all_face.push_back(face_obj);
							face_obj.vertices.clear();
						}

						else
						{
							face_obj.vertices.push_back(vertex_obj);
							count++;
						}
					}

					else if (z == 6)
					{
						vertex_obj.x = triangle_data[i].vertices[j].x;
						vertex_obj.y = triangle_data[i].vertices[j].y - (side * 2);
						vertex_obj.z = triangle_data[i].vertices[j].z;

						if (count == triangle_data[i].vertices.size() - 1)
						{
							face_obj.vertices.push_back(vertex_obj);
							count = 0;
							transform_all_face.push_back(face_obj);
							face_obj.vertices.clear();
						}

						else
						{
							face_obj.vertices.push_back(vertex_obj);
							count++;
						}
					}

					else if (z == 7)
					{
						vertex_obj.x = triangle_data[i].vertices[j].x;
						vertex_obj.y = triangle_data[i].vertices[j].y - side;
						vertex_obj.z = triangle_data[i].vertices[j].z - side;

						if (count == triangle_data[i].vertices.size() - 1)
						{
							face_obj.vertices.push_back(vertex_obj);
							count = 0;
							transform_all_face.push_back(face_obj);
							face_obj.vertices.clear();
						}

						else
						{
							face_obj.vertices.push_back(vertex_obj);
							count++;
						}
					}
				}
			}
		}
	}

	else if (option == 2)  // for translate along y- axis
	{
		int count = 0;
		Face face_obj;
		Vertex vertex_obj;
		for (int z = 0; z < n; z++)
		{
			for (int i = 0; i < triangle_data.size(); i++)
			{
				face_obj.face_normals.i = triangle_data[i].face_normals.i;
				face_obj.face_normals.j = triangle_data[i].face_normals.j;
				face_obj.face_normals.k = triangle_data[i].face_normals.k;

				for (int j = 0; j < triangle_data[i].vertices.size(); j++)
				{
					if (z == 0)
					{
						vertex_obj.x = triangle_data[i].vertices[j].x;
						vertex_obj.y = triangle_data[i].vertices[j].y;
						vertex_obj.z = triangle_data[i].vertices[j].z + side;

						if (count == triangle_data[i].vertices.size() - 1)
						{
							face_obj.vertices.push_back(vertex_obj);
							count = 0;
							transform_all_face.push_back(face_obj);
							face_obj.vertices.clear();
						}

						else
						{
							face_obj.vertices.push_back(vertex_obj);
							count++;
						}
					}

					else if (z == 1)
					{
						vertex_obj.x = triangle_data[i].vertices[j].x - (side * 2);
						vertex_obj.y = triangle_data[i].vertices[j].y;
						vertex_obj.z = triangle_data[i].vertices[j].z + side;

						if (count == triangle_data[i].vertices.size() - 1)
						{
							face_obj.vertices.push_back(vertex_obj);
							count = 0;
							transform_all_face.push_back(face_obj);
							face_obj.vertices.clear();
						}

						else
						{
							face_obj.vertices.push_back(vertex_obj);
							count++;
						}
					}

					else if (z == 2)
					{
						vertex_obj.x = triangle_data[i].vertices[j].x - (side * 2);
						vertex_obj.y = triangle_data[i].vertices[j].y;
						vertex_obj.z = triangle_data[i].vertices[j].z - side;

						if (count == triangle_data[i].vertices.size() - 1)
						{
							face_obj.vertices.push_back(vertex_obj);
							count = 0;
							transform_all_face.push_back(face_obj);
							face_obj.vertices.clear();
						}

						else
						{
							face_obj.vertices.push_back(vertex_obj);
							count++;
						}
					}

					else if (z == 3)
					{
						vertex_obj.x = triangle_data[i].vertices[j].x;
						vertex_obj.y = triangle_data[i].vertices[j].y;
						vertex_obj.z = triangle_data[i].vertices[j].z - side;

						if (count == triangle_data[i].vertices.size() - 1)
						{
							face_obj.vertices.push_back(vertex_obj);
							count = 0;
							transform_all_face.push_back(face_obj);
							face_obj.vertices.clear();
						}

						else
						{
							face_obj.vertices.push_back(vertex_obj);
							count++;
						}
					}

					else if (z == 4)
					{
						vertex_obj.x = triangle_data[i].vertices[j].x;
						vertex_obj.y = triangle_data[i].vertices[j].y;
						vertex_obj.z = triangle_data[i].vertices[j].z;

						if (count == triangle_data[i].vertices.size() - 1)
						{
							face_obj.vertices.push_back(vertex_obj);
							count = 0;
							transform_all_face.push_back(face_obj);
							face_obj.vertices.clear();
						}

						else
						{
							face_obj.vertices.push_back(vertex_obj);
							count++;
						}
					}

					else if (z == 5)
					{
						vertex_obj.x = triangle_data[i].vertices[j].x - side;
						vertex_obj.y = triangle_data[i].vertices[j].y;
						vertex_obj.z = triangle_data[i].vertices[j].z + side;

						if (count == triangle_data[i].vertices.size() - 1)
						{
							face_obj.vertices.push_back(vertex_obj);
							count = 0;
							transform_all_face.push_back(face_obj);
							face_obj.vertices.clear();
						}

						else
						{
							face_obj.vertices.push_back(vertex_obj);
							count++;
						}
					}

					else if (z == 6)
					{
						vertex_obj.x = triangle_data[i].vertices[j].x - (side * 2);
						vertex_obj.y = triangle_data[i].vertices[j].y;
						vertex_obj.z = triangle_data[i].vertices[j].z;

						if (count == triangle_data[i].vertices.size() - 1)
						{
							face_obj.vertices.push_back(vertex_obj);
							count = 0;
							transform_all_face.push_back(face_obj);
							face_obj.vertices.clear();
						}

						else
						{
							face_obj.vertices.push_back(vertex_obj);
							count++;
						}
					}

					else if (z == 7)
					{
						vertex_obj.x = triangle_data[i].vertices[j].x - side;
						vertex_obj.y = triangle_data[i].vertices[j].y;
						vertex_obj.z = triangle_data[i].vertices[j].z - side;

						if (count == triangle_data[i].vertices.size() - 1)
						{
							face_obj.vertices.push_back(vertex_obj);
							count = 0;
							transform_all_face.push_back(face_obj);
							face_obj.vertices.clear();
						}

						else
						{
							face_obj.vertices.push_back(vertex_obj);
							count++;
						}
					}
				}
			}
		}
	}

	else if (option == 3)  // translate along z-axis
	{
		int count = 0;
		Face face_obj;
		Vertex vertex_obj;
		for (int z = 0; z < n; z++)
		{
			for (int i = 0; i < triangle_data.size(); i++)
			{
				face_obj.face_normals.i = triangle_data[i].face_normals.i;
				face_obj.face_normals.j = triangle_data[i].face_normals.j;
				face_obj.face_normals.k = triangle_data[i].face_normals.k;

				for (int j = 0; j < triangle_data[i].vertices.size(); j++)
				{
					if (z == 0)
					{
						vertex_obj.x = triangle_data[i].vertices[j].x;
						vertex_obj.y = triangle_data[i].vertices[j].y + side;
						vertex_obj.z = triangle_data[i].vertices[j].z;

						if (count == triangle_data[i].vertices.size() - 1)
						{
							face_obj.vertices.push_back(vertex_obj);
							count = 0;
							transform_all_face.push_back(face_obj);
							face_obj.vertices.clear();
						}

						else
						{
							face_obj.vertices.push_back(vertex_obj);
							count++;
						}
					}

					else if (z == 1)
					{
						vertex_obj.x = triangle_data[i].vertices[j].x - (side * 2);
						vertex_obj.y = triangle_data[i].vertices[j].y + side;
						vertex_obj.z = triangle_data[i].vertices[j].z;

						if (count == triangle_data[i].vertices.size() - 1)
						{
							face_obj.vertices.push_back(vertex_obj);
							count = 0;
							transform_all_face.push_back(face_obj);
							face_obj.vertices.clear();
						}

						else
						{
							face_obj.vertices.push_back(vertex_obj);
							count++;
						}
					}

					else if (z == 2)
					{
						vertex_obj.x = triangle_data[i].vertices[j].x - (side * 2);
						vertex_obj.y = triangle_data[i].vertices[j].y - side;
						vertex_obj.z = triangle_data[i].vertices[j].z;

						if (count == triangle_data[i].vertices.size() - 1)
						{
							face_obj.vertices.push_back(vertex_obj);
							count = 0;
							transform_all_face.push_back(face_obj);
							face_obj.vertices.clear();
						}

						else
						{
							face_obj.vertices.push_back(vertex_obj);
							count++;
						}
					}

					else if (z == 3)
					{
						vertex_obj.x = triangle_data[i].vertices[j].x;
						vertex_obj.y = triangle_data[i].vertices[j].y - side;
						vertex_obj.z = triangle_data[i].vertices[j].z;

						if (count == triangle_data[i].vertices.size() - 1)
						{
							face_obj.vertices.push_back(vertex_obj);
							count = 0;
							transform_all_face.push_back(face_obj);
							face_obj.vertices.clear();
						}

						else
						{
							face_obj.vertices.push_back(vertex_obj);
							count++;
						}
					}

					else if (z == 4)
					{
						vertex_obj.x = triangle_data[i].vertices[j].x;
						vertex_obj.y = triangle_data[i].vertices[j].y;
						vertex_obj.z = triangle_data[i].vertices[j].z;

						if (count == triangle_data[i].vertices.size() - 1)
						{
							face_obj.vertices.push_back(vertex_obj);
							count = 0;
							transform_all_face.push_back(face_obj);
							face_obj.vertices.clear();
						}

						else
						{
							face_obj.vertices.push_back(vertex_obj);
							count++;
						}
					}

					else if (z == 5)
					{
						vertex_obj.x = triangle_data[i].vertices[j].x - side;
						vertex_obj.y = triangle_data[i].vertices[j].y + side;
						vertex_obj.z = triangle_data[i].vertices[j].z;

						if (count == triangle_data[i].vertices.size() - 1)
						{
							face_obj.vertices.push_back(vertex_obj);
							count = 0;
							transform_all_face.push_back(face_obj);
							face_obj.vertices.clear();
						}

						else
						{
							face_obj.vertices.push_back(vertex_obj);
							count++;
						}
					}

					else if (z == 6)
					{
						vertex_obj.x = triangle_data[i].vertices[j].x - (side * 2);
						vertex_obj.y = triangle_data[i].vertices[j].y;
						vertex_obj.z = triangle_data[i].vertices[j].z;

						if (count == triangle_data[i].vertices.size() - 1)
						{
							face_obj.vertices.push_back(vertex_obj);
							count = 0;
							transform_all_face.push_back(face_obj);
							face_obj.vertices.clear();
						}

						else
						{
							face_obj.vertices.push_back(vertex_obj);
							count++;
						}
					}

					else if (z == 7)
					{
						vertex_obj.x = triangle_data[i].vertices[j].x - side;
						vertex_obj.y = triangle_data[i].vertices[j].y - side;
						vertex_obj.z = triangle_data[i].vertices[j].z;

						if (count == triangle_data[i].vertices.size() - 1)
						{
							face_obj.vertices.push_back(vertex_obj);
							count = 0;
							transform_all_face.push_back(face_obj);
							face_obj.vertices.clear();
						}

						else
						{
							face_obj.vertices.push_back(vertex_obj);
							count++;
						}
					}
				}
			}
		}
	}*/


	std::vector<Face> cube_1;
	std::vector<Face> cube_2;
	std::vector<Face> cube_3;
	std::vector<Face> cube_4;

	if (option == 1) // translate along x-axis
	{
		int count = 0;
		int cube_count = 0;
		double equal_distance;

		Face face_obj;
		Vertex vertex_obj;

		double cubes_on_side = (total_cubes - 4) / 4;
		if (cubes_on_side == 1)
		{
			 equal_distance = side / (cubes_on_side + 1);
		}

		else
		{
			 equal_distance = side / (cubes_on_side + 2);
		}

		for (int no_of_cubes = 0; no_of_cubes < total_cubes; no_of_cubes++)
		{
			int side_count = 1;
			for (int i = 0; i < triangle_data.size(); i++)
			{
				face_obj.face_normals.i = triangle_data[i].face_normals.i;
				face_obj.face_normals.j = triangle_data[i].face_normals.j;
				face_obj.face_normals.k = triangle_data[i].face_normals.k;

				for (int j = 0; j < triangle_data[i].vertices.size(); j++)
				{
					if (no_of_cubes == 0)
					{
						vertex_obj.x = triangle_data[i].vertices[j].x;
						vertex_obj.y = triangle_data[i].vertices[j].y - side;
						vertex_obj.z = triangle_data[i].vertices[j].z + side / 2;

						if (count == triangle_data[i].vertices.size() - 1)
						{
							face_obj.vertices.push_back(vertex_obj);
							count = 0;
							transform_all_face.push_back(face_obj);
							cube_1.push_back(face_obj);
							face_obj.vertices.clear();
						}

						else
						{
							face_obj.vertices.push_back(vertex_obj);
							count++;
						}
					}

					else if (no_of_cubes == 1)
					{
						vertex_obj.x = triangle_data[i].vertices[j].x;
						vertex_obj.y = triangle_data[i].vertices[j].y;
						vertex_obj.z = triangle_data[i].vertices[j].z + side / 2;

						if (count == triangle_data[i].vertices.size() - 1)
						{
							face_obj.vertices.push_back(vertex_obj);
							count = 0;
							transform_all_face.push_back(face_obj);
							cube_2.push_back(face_obj);
							face_obj.vertices.clear();
						}

						else
						{
							face_obj.vertices.push_back(vertex_obj);
							count++;
						}
					}

					else if (no_of_cubes == 2)
					{
						vertex_obj.x = triangle_data[i].vertices[j].x;
						vertex_obj.y = triangle_data[i].vertices[j].y;
						vertex_obj.z = triangle_data[i].vertices[j].z - side / 2;

						if (count == triangle_data[i].vertices.size() - 1)
						{
							face_obj.vertices.push_back(vertex_obj);
							count = 0;
							transform_all_face.push_back(face_obj);
							cube_3.push_back(face_obj);
							face_obj.vertices.clear();
						}

						else
						{
							face_obj.vertices.push_back(vertex_obj);
							count++;
						}
					}

					else if (no_of_cubes == 3)
					{
						vertex_obj.x = triangle_data[i].vertices[j].x;
						vertex_obj.y = triangle_data[i].vertices[j].y - side;
						vertex_obj.z = triangle_data[i].vertices[j].z - side / 2;

						if (count == triangle_data[i].vertices.size() - 1)
						{
							face_obj.vertices.push_back(vertex_obj);
							count = 0;
							transform_all_face.push_back(face_obj);
							cube_4.push_back(face_obj);
							face_obj.vertices.clear();
						}

						else
						{
							face_obj.vertices.push_back(vertex_obj);
							count++;
						}
					}

					else if (no_of_cubes > 3)
					{
						if (z <= cubes_on_side + 3)
						{
							vertex_obj.x = cube_1[i].vertices[j].x;
							vertex_obj.y = cube_1[i].vertices[j].y + ((side_count * equal_distance));
							vertex_obj.z = cube_1[i].vertices[j].z;

							if (cube_count == cube_1[i].vertices.size() - 1)
							{
								face_obj.vertices.push_back(vertex_obj);
								cube_count = 0;
								transform_all_face.push_back(face_obj);
								face_obj.vertices.clear();
							}

							else
							{
								face_obj.vertices.push_back(vertex_obj);
								cube_count++;
							}
						}
						

						else if (no_of_cubes > cubes_on_side + 2 && no_of_cubes <= (cubes_on_side * 2) + 3)
						{
								
							vertex_obj.x = cube_2[i].vertices[j].x;
							vertex_obj.y = cube_2[i].vertices[j].y;
							vertex_obj.z = cube_2[i].vertices[j].z -((side_count * equal_distance));

							if (cube_count == cube_2[i].vertices.size() - 1)
							{
								face_obj.vertices.push_back(vertex_obj);
								cube_count = 0;
								transform_all_face.push_back(face_obj);
								face_obj.vertices.clear();
							}

							else
							{
								face_obj.vertices.push_back(vertex_obj);
								cube_count++;
							}
						}
						

						else if (no_of_cubes >  (cubes_on_side * 2) + 2 && no_of_cubes <= (cubes_on_side * 3) + 3)
						{
							
							vertex_obj.x = cube_3[i].vertices[j].x;
							vertex_obj.y = cube_3[i].vertices[j].y - ((side_count * equal_distance));
							vertex_obj.z = cube_3[i].vertices[j].z;

							if (cube_count == cube_3[i].vertices.size() - 1)
							{
								face_obj.vertices.push_back(vertex_obj);
								cube_count = 0;
								transform_all_face.push_back(face_obj);
								face_obj.vertices.clear();
							}

							else
							{
								face_obj.vertices.push_back(vertex_obj);
								cube_count++;
							}
						}

						else if (no_of_cubes > (cubes_on_side * 3) + 2 && no_of_cubes <= (cubes_on_side * 4) + 3)
						{
							
							vertex_obj.x = cube_4[i].vertices[j].x;
							vertex_obj.y = cube_4[i].vertices[j].y;
							vertex_obj.z = cube_4[i].vertices[j].z + ((side_count * equal_distance));

							if (cube_count == cube_4[i].vertices.size() - 1)
							{
								face_obj.vertices.push_back(vertex_obj);
								cube_count = 0;
								transform_all_face.push_back(face_obj);
								face_obj.vertices.clear();
							}

							else
							{
								face_obj.vertices.push_back(vertex_obj);
								cube_count++;
							}
						}

					}

				}

			}

			side_count++;
		}
	}
}