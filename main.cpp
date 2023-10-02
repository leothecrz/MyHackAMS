
#include "main.hpp"
#include "HackParser.hpp"

int main(int charc , char** charv)
{
    
    if(charc > 0)
    {
        std::string input = std::string(charv[0]);
        HackParser parser(input);

        while(parser.hasMore())
        {
            parser.Next();
            std::cout << parser.type << std::endl
                << parser.symbol<< std::endl
                << parser.dest<< std::endl
                << parser.comp<< std::endl
                << parser.jump<< std::endl;
        }

    }

}
