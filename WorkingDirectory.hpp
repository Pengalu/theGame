#ifndef Working_Directory_hpp
#define Working_Directory_hpp
#include <string>

class WorkingDirectory
{
public:
    WorkingDirectory();
    inline const std::string& get()
    {
        return path;
    }
private:
    std::string path;
};



#endif