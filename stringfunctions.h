#ifndef STRINGFUNCTIONS_H
#define STRINGFUNCTIONS_H

#include <string>
#include <vector>

class StringFunctions
{
public:
    StringFunctions();

    static std::vector<std::string> split(const std::string &string, const std::string &delim);
};

#endif // STRINGFUNCTIONS_H
