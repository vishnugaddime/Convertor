#include "Vertex.h"
#include "Normal.h"
#include "Face.h"
#include "OBJ_file.h"
#include "STL_file.h"
#include "OBJ_file.h"
#include "Transform.h"

int size_vertex, size_normal;

void Obj_File::read_obj_file(std::string filename)
{
    
    std::ifstream file(filename); // open file for readindg

    if (file.is_open()) // checking if file is open to read
    {
        std::string line;
        
        std::vector<Vertex> vertices;
        std::vector<Normal> normals;

        while (std::getline(file, line)) // for reading each line
        {
            if (line == "") continue;
            std::istringstream in(line);
            std::vector<std::string> vec_line;

            while (in >> line)
            {
                vec_line.push_back(line);
            }

            if (vec_line[0] == "v") // reading vertices
            {

                Vertex v_obj1;
                Vertex v_obj2;
                v_obj1.read_vertex(stod(vec_line[1]), stod(vec_line[2]), stod(vec_line[3]));
                vertices.push_back(v_obj1); //storing vertices 
                
               /* if (option == 'y')
                {
                    double e;
                    std::cin >> e;
                    v_obj2.translate_x(stod(vec_line[1]), stod(vec_line[2]), stod(vec_line[3]),e);
                    vertices.push_back(v_obj2);
                }  */
            }

            else if (vec_line[0] == "vn") // reading normals
            {

                Normal vn_obj1;

                vn_obj1.read_normals(stod(vec_line[1]), stod(vec_line[2]), stod(vec_line[3]));
                normals.push_back(vn_obj1);  //storing normals
            }

            else if (vec_line[0] == "f") //reading faces
            {
                size_t slash_count = std::count(line.begin(), line.end(), '/'); // counting numbers of slash in part of line


                if ((line[line.find("/") + 1] != '/') && slash_count == 2) //for reading files with texture (f v/t/n)
                {

                    Face face1;
                    Vertex vert1;

                    for (int i = 1; i <= vec_line.size()-1; i++)  // f 1/2/3
                    {

                        size_t idx1 = vec_line[i].find("/");
                        unsigned int idx_face_vertex = std::stod(vec_line[i].substr(0, idx1));
                        size_t idx2 = vec_line[i].find("/", idx1 + 1);
                        unsigned int idx_ftc_1 = std::stod(vec_line[i].substr(idx1 + 1, idx2));
                        size_t idx7 = vec_line[i].find("/");
                        unsigned int idx_fvn_1 = std::stod(vec_line[i].substr(idx2 + 1, idx7));

                        face1.face_normals.i = normals[idx_fvn_1 - 1].i;
                        face1.face_normals.j = normals[idx_fvn_1 - 1].j;
                        face1.face_normals.k = normals[idx_fvn_1 - 1].k;

                        vert1.x = vertices[idx_face_vertex - 1].x;
                        vert1.y = vertices[idx_face_vertex - 1].y;
                        vert1.z = vertices[idx_face_vertex - 1].z;

                        face1.vertices.push_back(vert1);
                    }

                    faces_of_triangles.push_back(face1);

                }

                else if ((line[line.find("/") + 1] == '/') && slash_count == 2) // for reading files without texture (f v//n) 
                {
                    Face face1;
                    Vertex vert1;

                    for (int i = 1; i <= vec_line.size() - 1; i++)
                    {

                        size_t idx1 = vec_line[i].find("/");
                        unsigned int idx_face_vertex = std::stoi(vec_line[i].substr(0, idx1));
                        size_t idx2 = vec_line[i].find("/", idx1 + 2);
                        unsigned int idx_fvn_1 = std::stoi(vec_line[i].substr(idx1 + 2, idx2));

                        face1.face_normals.i = normals[idx_fvn_1 - 1].i;
                        face1.face_normals.j = normals[idx_fvn_1 - 1].j;
                        face1.face_normals.k = normals[idx_fvn_1 - 1].k;

                        vert1.x = vertices[idx_face_vertex - 1].x;
                        vert1.y = vertices[idx_face_vertex - 1].y;
                        vert1.z = vertices[idx_face_vertex - 1].z;

                        face1.vertices.push_back(vert1);
                    }

                    faces_of_triangles.push_back(face1);  //storing all faces data 
                }  

                else // for reading files without texture (f v/n) 
                {
                    Face face1;
                    Vertex vert1;

                    for (int i = 1; i <= vec_line.size() - 1; i++)
                    {

                        size_t idx1 = vec_line[i].find("/");
                        unsigned int idx_face_vertex = std::stoi(vec_line[i].substr(0,idx1));
                        size_t idx2 = vec_line[i].find("/", idx1 + 1);
                        unsigned int idx_fvn_1 = std::stoi(vec_line[i].substr(idx1 + 1, idx2));

                        face1.face_normals.i = normals[idx_fvn_1 - 1].i;
                        face1.face_normals.j = normals[idx_fvn_1 - 1].j;
                        face1.face_normals.k = normals[idx_fvn_1 - 1].k;

                        vert1.x = vertices[idx_face_vertex - 1].x;
                        vert1.y = vertices[idx_face_vertex - 1].y;
                        vert1.z = vertices[idx_face_vertex - 1].z;

                        face1.vertices.push_back(vert1);
                    }

                    faces_of_triangles.push_back(face1);  //storing all faces data 
                }

            }
    
        }

        file.close(); // closing file  

    }

    else
    {
        std::cout << "Unable to open file" << std::endl;
    }

}


void Obj_File::write_obj_file(std::string inputpath)
{
    std::string savepath = inputpath + "_new.obj"; //saving file at same path as input file

    std::ofstream export_file;
    export_file.open(savepath); //opening file to write

    if (!export_file) // file couldn't be opened
    {
        std::cout << "Error: file could not be opened" << std::endl;
        exit(1);
    }

    std::vector<Normal> unique_normal;  //for storing unique normals
    std::vector<Vertex> unique_vertex;  //for storing unique vertices

    for (int i = 0; i < faces_of_triangles.size(); i++)
    {
        Vertex vert;

        for (int j = 0; j < faces_of_triangles[i].vertices.size(); j++)  //finding unique vertices
        {
            vert = faces_of_triangles[i].vertices[j];

            for (int k = 0; k < unique_vertex.size(); k++)
            {
                if (vert == unique_vertex[k])
                {
                    break;
                }

                if (k == (unique_vertex.size() - 1))
                {
                    unique_vertex.push_back(vert);
                    break;
                }
            }

            if (i == 0 && j == 0)  //pushing first vertex
            {
                unique_vertex.push_back(vert);
            }
        }
    }


    for (int a = 0; a < faces_of_triangles.size(); a++) // finding unique normals
    {
        Normal norm;

        norm = faces_of_triangles[a].face_normals;

        for (int b = 0; b < unique_normal.size(); b++)
        {
            if (norm == unique_normal[b])
            {
                break;
            }

            if (b == unique_normal.size() - 1)
            {
                unique_normal.push_back(norm);
                break;
            }
        }

        if (a == 0) //pushing first normal
        {
            unique_normal.push_back(norm);
        }
    }

    size_normal = unique_normal.size();
    size_vertex = unique_vertex.size();

    for (int a = 0; a < unique_vertex.size(); a++)  // writing unique vertices into file
    {
        export_file << "v" << " " << unique_vertex[a].x << " " << unique_vertex[a].y << " " << unique_vertex[a].z << "\n";
    }

    for (int a = 0; a < unique_normal.size(); a++)  // writing unique normals into file
    {
        export_file << "vn" << " " << unique_normal[a].i << " " << unique_normal[a].j << " " << unique_normal[a].k << "\n";
    }

    for (int i = 0; i < faces_of_triangles.size(); i++)
    {
        for (int j = 0; j < unique_normal.size(); j++)
        {
            if (unique_normal[j] == faces_of_triangles[i].face_normals)
            {
                export_file << "f ";

                for (int k = 0; k < faces_of_triangles[i].vertices.size(); k++)
                {
                    for (int x = 0; x < unique_vertex.size(); x++)
                    {
                        if (unique_vertex[x] == faces_of_triangles[i].vertices[k])
                        {
                            export_file << x + 1 << "//" << j + 1 << " ";
                            break;
                        }
                    }
                }

                export_file << std::endl;
            }
        }
    }

    export_file.close();
}


void Obj_File::write_obj_file(std::string inputpath, std::vector<Face> all_faces_data, int view_option)
{
    std::string savepath = inputpath + "_new.obj"; //saving file at same path as input file

    std::ofstream export_file;
    export_file.open(savepath, std::ios_base::app); //opening file to write

    if (!export_file) // file couldn't be opened
    {
        std::cout << "Error: file could not be opened" << std::endl;
        exit(1);
    }

    std::vector<Normal> unique_normal_temp;  //for storing unique normals
    std::vector<Vertex> unique_vertex_temp;  //for storing unique vertices

    for (int i = 0; i < all_faces_data.size(); i++)
    {
        Vertex vert;

        for (int j = 0; j < all_faces_data[i].vertices.size(); j++)  //finding unique vertices
        {
            vert = all_faces_data[i].vertices[j];

            for (int k = 0; k < unique_vertex_temp.size(); k++)
            {
                if (vert == unique_vertex_temp[k])
                {
                    break;
                }

                if (k == (unique_vertex_temp.size() - 1))
                {
                    unique_vertex_temp.push_back(vert);
                    break;
                }
            }

            if (i == 0 && j == 0)  //pushing first vertex
            {
                unique_vertex_temp.push_back(vert);
            }
        }
    }


    for (int a = 0; a < all_faces_data.size(); a++) // finding unique normals
    {
        Normal norm;

        norm = all_faces_data[a].face_normals;

        for (int b = 0; b < unique_normal_temp.size(); b++)
        {
            if (norm == unique_normal_temp[b])
            {
                break;
            }

            if (b == unique_normal_temp.size() - 1)
            {
                unique_normal_temp.push_back(norm);
                break;
            }
        }

        if (a == 0) //pushing first normal
        {
            unique_normal_temp.push_back(norm);
        }
    }

    for (int a = 0; a < unique_vertex_temp.size(); a++)  // writing unique vertices into file
    {
        export_file << "v" << " " << unique_vertex_temp[a].x << " " << unique_vertex_temp[a].y << " " << unique_vertex_temp[a].z << "\n";
    }

    for (int a = 0; a < unique_normal_temp.size(); a++)  // writing unique normals into file
    {
        export_file << "vn" << " " << unique_normal_temp[a].i << " " << unique_normal_temp[a].j << " " << unique_normal_temp[a].k << "\n";
    }

    if (view_option == 1 || view_option == 0)  //writing faces into file
    {
        for (int i = 0; i < all_faces_data.size(); i++)
        {
            for (int j = 0; j < unique_normal_temp.size(); j++)
            {
                if (unique_normal_temp[j] == all_faces_data[i].face_normals)
                {
                    export_file << "f ";

                    for (int k = 0; k < all_faces_data[i].vertices.size(); k++)
                    {
                        for (int x = 0; x < unique_vertex_temp.size(); x++)
                        {
                            if (unique_vertex_temp[x] == all_faces_data[i].vertices[k])
                            {
                                export_file << x + 1 << "//" << j + 1 << " ";
                                break;
                            }
                        }
                    }

                    export_file << std::endl;
                }
            }
        }
    }

    else if (view_option == 2) // for writing faces into file with original data
    {
        for (int i = 0; i < all_faces_data.size(); i++)
        {
            for (int j = 0; j < unique_normal_temp.size(); j++)
            {
                if (unique_normal_temp[j] == all_faces_data[i].face_normals)
                {
                    export_file << "f ";

                    for (int k = 0; k < all_faces_data[i].vertices.size(); k++)
                    {
                        for (int x = 0; x < unique_vertex_temp.size(); x++)
                        {
                            if (unique_vertex_temp[x] == all_faces_data[i].vertices[k])
                            {
                                export_file << size_vertex + x + 1 << "//"<< size_normal + j + 1 << " ";
                                break;
                            }
                        }
                    }

                    export_file << std::endl;
                }
            }
        }
    }

    export_file.close();
}
