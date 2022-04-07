#include "Vertex.h"
#include "Normal.h"
#include "Face.h"
#include "OBJ_file.h"
#include "STL_file.h"
#include "Transform.h"


void STL_file::read_stl_file(std::string filename)
{
    std::ifstream import_File(filename); // open file for reading

    if (import_File.is_open()) // checking if file is open to read
    {
        std::string line;
        Face face_obj_1;
        int count = 0;  // counting number of vertex to push back

        while (std::getline(import_File, line)) // for reading each line
        {
            if (line == "") continue; //ignore blank lines in file
            std::istringstream in(line);
            std::vector<std::string> vec_line;

            while (in >> line)
            {
                vec_line.push_back(line);
            }

            if (vec_line[0] == "facet" && vec_line[1] == "normal") //checking for normals
            {
                face_obj_1.face_normals.read_normals(stod(vec_line[2]), stod(vec_line[3]), stod(vec_line[4]));
            }

            else if (vec_line[0] == "vertex") //checking for vertex
            {
                Vertex face_vert_obj_1;

                face_vert_obj_1.read_vertex(stod(vec_line[1]), stod(vec_line[2]), stod(vec_line[3]));

                if (count == 2)
                {
                    face_obj_1.vertices.push_back(face_vert_obj_1);
                    count = 0;
                    all_triangle_data.push_back(face_obj_1);
                    face_obj_1.vertices.clear();
                }

                else
                {
                    face_obj_1.vertices.push_back(face_vert_obj_1);
                    count++;
                }

            }

        }

        import_File.close();
    }

    else
    {
        std::cout << "Unable to open file" << std::endl;
    }
}

void STL_file::write_stl_file(std::string inputpath)
{
    std::string savepath = inputpath + "_new.stl";

    std::ofstream outfile;
    outfile.open(savepath); //opening file to write

    if (!outfile) // file couldn't be opened
    {
        std::cout << "Error: file could not be opened" << std::endl;
        exit(1);
    }

    outfile << "solid" << std::endl;

    
    for (int i = 0; i < all_triangle_data.size(); i++)
    {
    // Writiing facet normal

        outfile << "\tfacet normal " << all_triangle_data[i].face_normals.i << " " << all_triangle_data[i].face_normals.j << " " << all_triangle_data[i].face_normals.k << "\n";
        outfile << "\t\touter loop" << "\n";

        // Writing vertices for that facet normal
        //if (all_triangle_data[i].vertices.size() == 3)
        
        outfile << "\t\t\tvertex " << all_triangle_data[i].vertices[0].x << " " << all_triangle_data[i].vertices[0].y << " " << all_triangle_data[i].vertices[0].z << "\n";
        outfile << "\t\t\tvertex " << all_triangle_data[i].vertices[1].x << " " << all_triangle_data[i].vertices[1].y << " " << all_triangle_data[i].vertices[1].z << "\n";
        outfile << "\t\t\tvertex " << all_triangle_data[i].vertices[2].x << " " << all_triangle_data[i].vertices[2].y << " " << all_triangle_data[i].vertices[2].z << "\n";
        outfile << "\t\tendloop" << std::endl;
        outfile << "\tendfacet" << std::endl;
        
    }

        outfile << "endsolid" << std::endl;

    outfile.close();

}

void STL_file::write_stl_file(std::string inputpath, std::vector<Face> all_faces_data)
{
    std::string savepath = inputpath + "_new.stl";

    std::ofstream outfile;
    outfile.open(savepath, std::ios_base::app); //opening file to write

    if (!outfile) // file couldn't be opened
    {
        std::cout << "Error: file could not be opened" << std::endl;
        exit(1);
    }

    outfile << "solid" << std::endl;
    
    for (int i = 0; i < all_faces_data.size(); i++)
    {
            // Writiing facet normal

            outfile << "\tfacet normal " << all_faces_data[i].face_normals.i << " " << all_faces_data[i].face_normals.j << " " << all_faces_data[i].face_normals.k << "\n";
            outfile << "\t\touter loop" << "\n";

            // Writing vertices for that facet normal

            outfile << "\t\t\tvertex " << all_faces_data[i].vertices[0].x << " " << all_faces_data[i].vertices[0].y << " " << all_faces_data[i].vertices[0].z << "\n";
            outfile << "\t\t\tvertex " << all_faces_data[i].vertices[1].x << " " << all_faces_data[i].vertices[1].y << " " << all_faces_data[i].vertices[1].z << "\n";
            outfile << "\t\t\tvertex " << all_faces_data[i].vertices[2].x << " " << all_faces_data[i].vertices[2].y << " " << all_faces_data[i].vertices[2].z << "\n";
            outfile << "\t\tendloop" << std::endl;
            outfile << "\tendfacet" << std::endl;

    }

    outfile << "endsolid" << std::endl;

    outfile.close();
}