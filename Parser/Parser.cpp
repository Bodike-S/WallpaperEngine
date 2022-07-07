#include <iostream>
#include<fstream>
#include<string>
#include<vector>

void Parser(const std::string &file_name_r, const std::string &file_name_w)
{
    std::fstream fs;
    std::fstream f;
    std::string buffer;
    std::vector<std::string> list;

    fs.open(file_name_r, std::ios::out);//::app - дозапис, ::in - перезапис файлу, ::out - читання з файлу  
    if (fs.is_open())
    {
        while (!fs.eof())
        {
            for (int i = 0; i < list.size(); ++i) {
                fs << i << " " << list[i] << std::endl;
            }
            f.open(file_name_w, std::ios::app);
            if (f.is_open())
            {
                for (int i = 0; i < list.size(); ++i) {
                    f << list.at(i) << std::endl;
                }
                f.close();
            }
            else
                std::cout << "Not found file :" << file_name_w << std::endl;
        }
        fs.close();
    }
    else
        std::cout << "Not found file: " << file_name_r<<std::endl;
}

std::string Get_Extension(const std::string &file_name, const std::string &extension)
{
    return file_name+extension;
}


int main()
{
    std::string reader;
    std::string write;

    std::cout << "Enter name reader file: ";
    std::cin >> reader;
    std::cout << std::endl;
    std::cout << "Enter name file for write: ";
    std::cin >> write;
    std::cout << std::endl;

    const std::string extension = ".txt";
    
    reader = Get_Extension(reader, extension);
    write = Get_Extension(write, extension);

    Parser(reader, write);

    //std::cout << reader << std::endl;
    //std::cout << write << std::endl;
    
    return 0;
}
