#include <iostream>
#include <list>
#include <filesystem>


int main(int, char**){
    std::cout << "Hello, from 35_3_search_by_extension!\n";

    std::list<std::string> list; //doubly-linked list

    auto recursiveGetFileNamesByExtension =
            [&list](std::filesystem::path path, const std::string extension){
                for(auto& p: std::filesystem::recursive_directory_iterator(path)){
                    if(p.is_regular_file() && !p.path().extension().compare(extension))
                        list.push_back(p.path().filename());      
                }     
            };

    
    std::filesystem::path path = "/home/kate/skillbox/35_3_search_by_extension/";
    std::string extention = ".cpp";

    recursiveGetFileNamesByExtension(path, extention);

    for (const auto &i : list)
        std::cout << i << std::endl;

}
