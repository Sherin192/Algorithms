#define _OPEN_SYS_ITOA_EXT
#include <iostream>
#include <stack>
#include <string>
#include <utility>
#include <vector>
#include <fstream>
#include <cstring>
#include <cassert>
#include <cstdlib>
struct Bracket
{
    Bracket(char type, int position) : type(type),
                                       position(position)
    {
    }

    bool Matchc(char c)
    {
        if (type == '[' && c == ']')
            return true;
        if (type == '{' && c == '}')
            return true;
        if (type == '(' && c == ')')
            return true;
        return false;
    }

    char type;
    int position;
};

// char* getFilePath(int i, char *extension)
// {
//     char* str = (char*)malloc(20);    
 
//     if (i < 10)
//     {
//         char buffer [64];
//         itoa (i, buffer, 10);
//         strcpy(str, "tests/0");
        
//         strcat(str, buffer);
//         strcat(str, extension);
//     }
//     else
//     {
//         char buffer[8];
//         itoa(i, buffer, 10);
//         strcpy(str, "tests/");
//         strcat(str, buffer);
//         strcat(str, extension);
//     }
//     return str;
// }

// std::vector<std::pair<std::string, std::string>> tests;

// void test_solution()
// {
//     std::cout << "Start" << std::endl;
//     std::ifstream in;
//     std::pair<std::string, std::string> test;
//     char extension[] = ".a";
//     char no_extension[] = "";

//     for (int i = 1; i < 55; i++)
//     {
//         char* r = getFilePath(i, no_extension);
//         std::cout << r << std::endl;

//         in.open(r);

//         if (!in.good())
//         {
//             std::cout << "File could not be loaded. Check if the correct dirrectory was passed." << std::endl;
//         }

//         std::string line;
//         std::getline(in, line);
//         //std::cout << "line: " << line << std::endl;

//         in.close();
//         //std::cout <<  "Next" << std::endl;
        
//         char *r2 = getFilePath(i, extension);
//         //std::cout <<  "Next" << std::endl;
        
//         std::cout <<  r2 << std::endl;
//         in.open(r2);
        
//         if (!in.good())
//         {
//             std::cerr << "File could not be loaded. Check if the correct dirrectory was passed. \n";
//             return;
//         }
//         std::string result;
//         std::getline(in, result);
//         //std::cout << "result " << result << std::endl;
//         in.close();
//         test = std::make_pair(line, result);
//         tests.push_back(test);
//     }
// }

int main()
{

    //test_solution();

    std::string text;
    getline(std::cin, text);

    std::stack<Bracket> opening_brackets_stack;
    
    //for (int i = 0; i < 55; i++)
    //{
        // text = tests[i].first;
        // closed_brackets = 0;
        // error_pos = 0;
        // while(!opening_brackets_stack.empty())
        // {
        //     opening_brackets_stack.pop();
        // }
        
        //std::cout << text << std::endl;
        for (int position = 0; position < text.length(); ++position)
        {
            char next = text[position];
            if (next == '(' || next == '[' || next == '{')
            {
                opening_brackets_stack.emplace(Bracket(next, position));
            }
            else if (next == ')' || next == ']' || next == '}')
            {
                
                if (opening_brackets_stack.empty())
                {   
                    opening_brackets_stack.push(Bracket(next, position));                    
                    break;                    
                }
                else if (opening_brackets_stack.top().Matchc(next))
                {
                    opening_brackets_stack.pop();
                }
                else 
                {
                    opening_brackets_stack.push(Bracket(next, position));                                        
                    break;
                }
            }
            else
                continue;
        }

        if (opening_brackets_stack.empty())
            std::cout << "Success" << std::endl;
        else
            std::cout << opening_brackets_stack.top().position + 1 << std::endl;
        
    
    return 0;
}
