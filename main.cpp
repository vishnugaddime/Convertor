#include "Vertex.h"
#include "Normal.h"
#include "Face.h"
#include "OBJ_file.h"
#include "STL_file.h"
#include "Transform.h"
#include<iostream>
#include<string>


int main()
{
    Obj_File object1;
    STL_file stl_obj1;
    Transform transform_obj1;
    Transform transform_obj2;
    
    std::cout << "Enter the full path of a file " << "\n";
    std::string filepath;  //user input file path 
    std::cin >> filepath;

    std::string inputpath;  //storing filepath for saving file
    inputpath = filepath.substr(0, filepath.find("."));

    if (filepath.substr(filepath.find_last_of(".") + 1) == "obj")  //checking file extension
    {
        object1.read_obj_file(filepath);  //reading input file

        std::cout << "\n";
        std::cout << "Would you like to transform file(y/n)" << std::endl;
        char yes_no;   // user choice
        std::cin >> yes_no;

        if (yes_no == 'y' || yes_no == 'Y')
        {
            std::cout << "\n";
            std::cout << "Enter 1 to Translate " << std::endl;
            std::cout << "Enter 2 to Rotate " << std::endl;
            std::cout << "Enter 3 to translate and rotate" << std::endl;
            std::cout << "Enter 4 for multiple translatiion in circular form" << std::endl;
            std::cout << "Enter 5 for multiple translation in square form" << std::endl;

            int choice;
            std::cin >> choice; // to select user option

            if (choice == 1)  // for translation
            {
                std::cout << "\n";
                std::cout << "Enter 1 to translate along x-axis" << std::endl;
                std::cout << "Enter 2 to translate along y-axis" << std::endl;
                std::cout << "Enter 3 to translate along z-axis" << std::endl;
                std::cout << "Enter 4 to translate along x-axis, y-axis, z-axis with same distance " << std::endl;

                int translate_choice;   // translation choice
                std::cin >> translate_choice;

                std::cout << "\n";
                std::cout << "Enter the distance to transform" << std::endl;
                double translate_distance;   // translation distance
                std::cin >> translate_distance;

                transform_obj1.translate_file(object1.faces_of_triangles,translate_choice, translate_distance);  //translating original co-ordinates

                int view_option = 0;  //for writing choice
                std::cout << "\n";
                std::cout << "Enter 1 to generate new file for translate" << std::endl;
                std::cout << "Enter 2 to view translate and original object in same file" << std::endl;
                std::cin >> view_option;

                if (view_option == 1)
                {
                    object1.write_obj_file(inputpath, transform_obj1.transform_all_face, view_option);
                    std::cout << "Done" << std::endl;
                }

                else if (view_option == 2)
                {
                    object1.write_obj_file(inputpath);
                    object1.write_obj_file(inputpath, transform_obj1.transform_all_face, view_option);
                    std::cout << "Done" << std::endl;
                }
            }

            else if (choice == 2)  //for rotation option
            {
                std::cout << "\n";
                std::cout << "Enter 1 to rotate along x-axis" << std::endl;
                std::cout << "Enter 2 to rotate along y-axis" << std::endl;
                std::cout << "Enter 3 to rotate along z-axis" << std::endl;

                int rotate_choice;  // to select rotation along axixs
                std::cin >> rotate_choice;

                std::cout << "\n";
                std::cout << "Enter the angle to rotate" << std::endl;
                double input_angle;   // angle to rotate object
                std::cin >> input_angle;

                double rotate_angle = input_angle * 3.14 / 180;  

                transform_obj1.rotate_file(object1.faces_of_triangles , rotate_choice, rotate_angle); //rotating object

                int view_option = 0;  //to select writing choice
                std::cout << "\n";
                std::cout << "Enter 1 to generate new file for translate" << std::endl;
                std::cout << "Enter 2 to view translate and original object in same file" << std::endl;
                std::cin >> view_option;

                if (view_option == 1)
                {
                    object1.write_obj_file(inputpath, transform_obj1.transform_all_face, view_option);
                    std::cout << "Done" << std::endl;
                }

                else if (view_option == 2)
                {
                    object1.write_obj_file(inputpath);
                    object1.write_obj_file(inputpath, transform_obj1.transform_all_face, view_option);
                    std::cout << "Done" << std::endl;
                }
            } 

            else if (choice == 3)  // for translation and rotation 
            {
                std::cout << "\n";
                std::cout << "Enter 1 to translate along x-axis" << std::endl;
                std::cout << "Enter 2 to translate along y-axis" << std::endl;
                std::cout << "Enter 3 to translate along z-axis" << std::endl;
                std::cout << "Enter 4 to translate along x-axis, y-axis, z-axis with same distance " << std::endl;

                int translate_choice; // to select translation along axis
                std::cin >> translate_choice;

                std::cout << "\n";
                std::cout << "Enter the distance to transform" << std::endl;
                double translate_distance;
                std::cin >> translate_distance;

                transform_obj1.translate_file(object1.faces_of_triangles ,translate_choice, translate_distance);  //translating object

                std::cout << "\n";
                std::cout << "Enter 1 to rotate along x-axis" << std::endl;
                std::cout << "Enter 2 to rotate along y-axis" << std::endl;
                std::cout << "Enter 3 to rotate along z-axis" << std::endl;

                int rotate_choice;
                std::cin >> rotate_choice;
                
                std::cout << "\n";
                std::cout << "Enter the angle to rotate" << std::endl;
                double input_angle;
                std::cin >> input_angle;

                double rotate_angle = input_angle * 3.14 / 180;

                transform_obj2.rotate_file(transform_obj1.transform_all_face, rotate_choice, rotate_angle);  //rotating object

                int view_option = 0; //to select writing option
                std::cout << "\n";
                std::cout << "Enter 1 to generate new file for translate" << std::endl;
                std::cout << "Enter 2 to view translate and original object in same file" << std::endl;
                std::cin >> view_option;

                if (view_option == 1)
                {
                    object1.write_obj_file(inputpath, transform_obj2.transform_all_face, view_option);
                    std::cout << "Done" << std::endl;
                }

                else if (view_option == 2)
                {
                    object1.write_obj_file(inputpath);
                    object1.write_obj_file(inputpath, transform_obj2.transform_all_face, view_option);
                    std::cout << "Done" << std::endl;
                }
            }

            else if (choice == 4)
            {
                std::cout << "\n";
                std::cout << "Enter 1 to translate along x-axis" << std::endl;
                std::cout << "Enter 2 to translate along y-axis" << std::endl;
                std::cout << "Enter 3 to translate along z-axis" << std::endl;
                std::cout << "Enter 4 to translate along x-axis, y-axis, z-axis with same distance " << std::endl;

                int translate_choice; // to select translation along axis
                std::cin >> translate_choice;

                std::cout << "\n";
                std::cout << "Enter the distance to transform" << std::endl;
                double translate_distance;
                std::cin >> translate_distance;

                transform_obj1.translate_file(object1.faces_of_triangles, translate_choice, translate_distance);  //translating object

                std::cout << "\n";
                std::cout << "Enter 1 to rotate along x-axis" << std::endl;
                std::cout << "Enter 2 to rotate along y-axis" << std::endl;
                std::cout << "Enter 3 to rotate along z-axis" << std::endl;

                int rotate_choice;
                std::cin >> rotate_choice;

                std::cout << "\n";
                std::cout << "Enter the number of times you want to multiply" << std::endl;
                int n;
                std::cin >> n;

                transform_obj2.circular_pattern(transform_obj1.transform_all_face, object1.faces_of_triangles, rotate_choice, n);  //rotating object

                int view_option = 0; //to select writing option
                std::cout << "\n";
                std::cout << "Enter 1 to generate new file for translate" << std::endl;
                std::cout << "Enter 2 to view translate and original object in same file" << std::endl;
                std::cin >> view_option;

                if (view_option == 1)
                {
                    object1.write_obj_file(inputpath, transform_obj2.transform_all_face, view_option);
                    std::cout << "Done" << std::endl;
                }

                else if (view_option == 2)
                {
                    object1.write_obj_file(inputpath);
                    object1.write_obj_file(inputpath, transform_obj2.transform_all_face, view_option);
                    std::cout << "Done" << std::endl;
                }
            }

            else if (choice == 5)
            {
                std::cout << "\n";
                std::cout << "Enter 1 to view along x-axis" << std::endl;
                std::cout << "Enter 2 to view along y-axis" << std::endl;
                std::cout << "Enter 3 to view along z-axis" << std::endl;

                int translate_choice; // to select translation along axis
                std::cin >> translate_choice;

                std::cout << "\n";
                std::cout << "Enter the side of square" << std::endl;
                double translate_distance, square_side;
                std::cin >> square_side;

                translate_distance = square_side / 2;

                if (translate_choice == 1)
                {
                    transform_obj1.translate_file(object1.faces_of_triangles, 2, translate_distance);  //translating object
                }

                else if (translate_choice == 2)
                {
                    transform_obj1.translate_file(object1.faces_of_triangles, 1, translate_distance);  //translating object
                }

                else if (translate_choice == 3)
                {
                    transform_obj1.translate_file(object1.faces_of_triangles, 1, translate_distance);  //translating object
                }

                std::cout << "\n";

                std::cout << "\n";
                std::cout << "Enter the number of object you want in square form" << std::endl;
                int no_of_object;
                std::cin >> no_of_object;

                transform_obj2.square_pattern(transform_obj1.transform_all_face, object1.faces_of_triangles, translate_choice, no_of_object, square_side);  //rotating object

                int view_option = 0; //to select writing option
                std::cout << "\n";
                std::cout << "Enter 1 to generate new file for translate" << std::endl;
                std::cout << "Enter 2 to view translate and original object in same file" << std::endl;
                std::cin >> view_option;

                if (view_option == 1)
                {
                    object1.write_obj_file(inputpath, transform_obj2.transform_all_face, view_option);
                    std::cout << "Done" << std::endl;
                }

                else if (view_option == 2)
                {
                    object1.write_obj_file(inputpath);
                    object1.write_obj_file(inputpath, transform_obj2.transform_all_face, view_option);
                    std::cout << "Done" << std::endl;
                }
            }

            else
            {
                std::cout << "choose correct option" << std::endl;
            }
        }

        else if (yes_no == 'n' || yes_no == 'N')
        {
            std::cout << "\n";
            std::cout << "Enter 1 to convert file to .obj format" << std::endl;
            std::cout << "Enter 2 to convert file to .stl format" << std::endl;
            std::cout << "Enter 0 to exit" << std::endl;

            int convert_option;
            std::cin >> convert_option;

            if (convert_option == 1)
            {
                object1.write_obj_file(inputpath);  //converting into .obj format
                std::cout << "Done" << std::endl;
            }

            else if (convert_option == 2)
            {
                stl_obj1.write_stl_file(inputpath, object1.faces_of_triangles); //converting into .stl file
                std::cout << "Done" << std::endl;
            }

            else if (convert_option == 0)
            {
                std::cout << "Thank you" << std::endl;
            }

            else
            {
                std::cout << "Choose correct option" << std::endl;
            }
        }

        else
        {
            std::cout << "choose correct option" << std::endl;
        }
    }


    else if (filepath.substr(filepath.find_last_of(".") + 1) == "stl") //checking file extension
    {
        stl_obj1.read_stl_file(filepath);  //reading file

        std::cout << "\n";
        std::cout << "Would you like to transform file(y/n)" << std::endl;
        char yes_no;
        std::cin >> yes_no;

        if (yes_no == 'y' || yes_no == 'Y')
        {
            std::cout << "\n";
            std::cout << "Enter 1 to Translate " << std::endl;
            std::cout << "Enter 2 to Rotate " << std::endl;
            std::cout << "Enter 3 to translate and rotate" << std::endl;
            std::cout << "Enter 4 for multiple translation" << std::endl;
            std::cout << "Enter 5 to translate in square form" << std::endl;

            int choice;
            std::cin >> choice; // to select transform option

            if (choice == 1)  // for translation
            {
                std::cout << "\n";
                std::cout << "Enter 1 to translate along x-axis" << std::endl;
                std::cout << "Enter 2 to translate along y-axis" << std::endl;
                std::cout << "Enter 3 to translate along y-axis" << std::endl;
                std::cout << "Enter 4 to translate along x-axis, y-axis, z-axis" << std::endl;

                int translate_choice;  // to select translate choice
                std::cin >> translate_choice;

                std::cout << "\n";
                std::cout << "Enter the distance to transform" << std::endl;
                double translate_distance;
                std::cin >> translate_distance;

                transform_obj1.translate_file(stl_obj1.all_triangle_data, translate_choice, translate_distance);  //translating object

                int view_option = 0;
                std::cout << "\n";
                std::cout << "Enter 1 to generate new file for translate" << std::endl;
                std::cout << "Enter 2 to view translate and original object in same file" << std::endl;
                std::cin >> view_option;

                if (view_option == 1)
                {
                    stl_obj1.write_stl_file(inputpath, transform_obj1.transform_all_face);
                    std::cout << "Done" << std::endl;
                }

                else if (view_option == 2)
                {
                    stl_obj1.write_stl_file(inputpath);
                    stl_obj1.write_stl_file(inputpath, transform_obj1.transform_all_face);
                    std::cout << "Done" << std::endl;
                }

            }

            else if (choice == 2)  // for rotation
            {

                std::cout << "\n";
                std::cout << "Enter 1 to rotate along x-axis" << std::endl;
                std::cout << "Enter 2 to rotate along y-axis" << std::endl;
                std::cout << "Enter 3 to rotate along z-axis" << std::endl;

                int rotate_choice;  // to select rotation choice
                std::cin >> rotate_choice;

                std::cout << "\n";
                std::cout << "Enter the angle to rotate" << std::endl;
                double input_angle;
                std::cin >> input_angle;

                double rotate_angle = input_angle * 3.14 / 180;

                transform_obj1.rotate_file(stl_obj1.all_triangle_data, rotate_choice, rotate_angle);

                int view_option = 0;
                std::cout << "\n";
                std::cout << "Enter 1 to generate new file for translate" << std::endl;
                std::cout << "Enter 2 to view translate and original object in same file" << std::endl;
                std::cin >> view_option;


                if (view_option == 1)
                {
                    stl_obj1.write_stl_file(inputpath, transform_obj1.transform_all_face);
                    std::cout << "Done" << std::endl;
                }

                else if (view_option == 2)
                {
                    stl_obj1.write_stl_file(inputpath);
                    stl_obj1.write_stl_file(inputpath, transform_obj1.transform_all_face);
                    std::cout << "Done" << std::endl;
                }
            }

            else if (choice == 3)  // for translation and rotation
            {

                std::cout << "\n";
                std::cout << "Enter 1 to translate along x-axis" << std::endl;
                std::cout << "Enter 2 to translate along y-axis" << std::endl;
                std::cout << "Enter 3 to translate along z-axis" << std::endl;
                std::cout << "Enter 4 to translate along x-axis, y-axis, z-axis with same distance " << std::endl;

                int translate_choice;  // translation choice
                std::cin >> translate_choice;

                std::cout << "\n";
                std::cout << "Enter the distance to transform" << std::endl;
                double translate_distance;
                std::cin >> translate_distance;

                transform_obj1.translate_file(stl_obj1.all_triangle_data, 1, translate_distance); // translating object

                std::cout << "\n";
                std::cout << "Enter 1 to rotate along x-axis" << std::endl;
                std::cout << "Enter 2 to rotate along y-axis" << std::endl;
                std::cout << "Enter 3 to rotate along z-axis" << std::endl;

                int rotate_choice;  // rotation choice 
                std::cin >> rotate_choice;

                std::cout << "\n";
                std::cout << "Enter the angle to rotate" << std::endl;
                double input_angle;
                std::cin >> input_angle;

                double rotate_angle = input_angle * 3.14 / 180;

                transform_obj2.rotate_file(transform_obj1.transform_all_face, rotate_choice, rotate_angle);  //rotating object

                int view_option = 0;
                std::cout << "\n";
                std::cout << "Enter 1 to generate new file for translate" << std::endl;
                std::cout << "Enter 2 to view translate and original object in same file" << std::endl;
                std::cin >> view_option;

                if (view_option == 1)
                {
                    stl_obj1.write_stl_file(inputpath, transform_obj1.transform_all_face);
                    std::cout << "Done" << std::endl;
                }

                else if (view_option == 2)
                {
                    stl_obj1.write_stl_file(inputpath);
                    stl_obj1.write_stl_file(inputpath, transform_obj2.transform_all_face);
                    std::cout << "Done" << std::endl;
                }
            }

            else if (choice == 4)
            {
                std::cout << "\n";
                std::cout << "Enter 1 to translate along x-axis" << std::endl;
                std::cout << "Enter 2 to translate along y-axis" << std::endl;
                std::cout << "Enter 3 to translate along z-axis" << std::endl;
                std::cout << "Enter 4 to translate along x-axis, y-axis, z-axis with same distance " << std::endl;

                int translate_choice; // to select translation along axis
                std::cin >> translate_choice;

                std::cout << "\n";
                std::cout << "Enter the distance to transform" << std::endl;
                double translate_distance;
                std::cin >> translate_distance;

                transform_obj1.translate_file(stl_obj1.all_triangle_data, translate_choice, translate_distance);  //translating object

                std::cout << "\n";
                std::cout << "Enter 1 to rotate along x-axis" << std::endl;
                std::cout << "Enter 2 to rotate along y-axis" << std::endl;
                std::cout << "Enter 3 to rotate along z-axis" << std::endl;

                int rotate_choice;
                std::cin >> rotate_choice;

                std::cout << "\n";
                std::cout << "Enter the number of times you want to multiply" << std::endl;
                int n;
                std::cin >> n;

                transform_obj2.circular_pattern(transform_obj1.transform_all_face, stl_obj1.all_triangle_data, rotate_choice, n);  //rotating object

                int view_option = 0; //to select writing option
                std::cout << "\n";
                std::cout << "Enter 1 to generate new file for translate" << std::endl;
                std::cout << "Enter 2 to view translate and original object in same file" << std::endl;
                std::cin >> view_option;

                if (view_option == 1)
                {
                    stl_obj1.write_stl_file(inputpath, transform_obj2.transform_all_face);
                    std::cout << "Done" << std::endl;
                }

                else if (view_option == 2)
                {
                    stl_obj1.write_stl_file(inputpath);
                    stl_obj1.write_stl_file(inputpath, transform_obj2.transform_all_face);
                    std::cout << "Done" << std::endl;
                }
            }

            else if (choice == 5)
            {
                std::cout << "\n";
                std::cout << "Enter 1 to view along x-axis" << std::endl;
                std::cout << "Enter 2 to view along y-axis" << std::endl;
                std::cout << "Enter 3 to view along z-axis" << std::endl;

                int translate_choice; // to select translation along axis
                std::cin >> translate_choice;

                std::cout << "\n";
                std::cout << "Enter the side of square" << std::endl;
                double translate_distance, square_side;
                std::cin >> square_side;

                translate_distance = square_side / 2;

                if (translate_choice == 1)
                {
                    transform_obj1.translate_file(stl_obj1.all_triangle_data, 2, translate_distance);  //translating object
                }

                else if (translate_choice == 2)
                {
                    transform_obj1.translate_file(stl_obj1.all_triangle_data, 1, translate_distance);  //translating object
                }

                else if (translate_choice == 3)
                {
                    transform_obj1.translate_file(stl_obj1.all_triangle_data, 1, translate_distance);  //translating object
                }

                std::cout << "\n";

                std::cout << "\n";
                std::cout << "Enter the number of times you want to multiply" << std::endl;
                int n;
                std::cin >> n;

                transform_obj2.square_pattern(transform_obj1.transform_all_face, stl_obj1.all_triangle_data, translate_choice, n, square_side);  //rotating object

                int view_option = 0; //to select writing option
                std::cout << "\n";
                std::cout << "Enter 1 to generate new file for translate" << std::endl;
                std::cout << "Enter 2 to view translate and original object in same file" << std::endl;
                std::cin >> view_option;

                if (view_option == 1)
                {
                    stl_obj1.write_stl_file(inputpath, transform_obj2.transform_all_face);
                    std::cout << "Done" << std::endl;
                }

                else if (view_option == 2)
                {
                    stl_obj1.write_stl_file(inputpath);
                    stl_obj1.write_stl_file(inputpath, transform_obj2.transform_all_face);
                    std::cout << "Done" << std::endl;
                }
            }

        }            

        else if (yes_no == 'n' || yes_no == 'N')
        {
            std::cout << "\n";
            std::cout << "Enter 1 to convert file to .obj format" << std::endl;
            std::cout << "Enter 2 to convert file to .stl format" << std::endl;
            std::cout << "Enter 0 to exit" << std::endl;

            int convert_option;
            std::cin >> convert_option;

            if (convert_option == 1)
            {
                object1.write_obj_file(inputpath, stl_obj1.all_triangle_data, 0);  // converting into .obj format
                std::cout << "Done" << std::endl;
            }

            else if (convert_option == 2)
            {
                stl_obj1.write_stl_file(inputpath);  // converting into .stl format
                std::cout << "Done" << std::endl;
            }

            else if (convert_option == 0)
            {
                std::cout << "Thank you" << std::endl;
            }

            else
            {
                std::cout << "Choose correct option" << std::endl;
            }
        }

        else
        {
            std::cout << "choose correct option" << std::endl;
        }
    }

    else
    {
        std::cout << "Enter correct file format" << std::endl;
    }

}