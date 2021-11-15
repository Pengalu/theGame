#ifndef ResourceAllocator_hpp
#define ResourceAllocator_hpp

#include <map>
#include <memory>

template<typename T>
class ResourceAllocator
{
public:
    int add(const std::string& path)
    {
        auto it = resources.find(path);
        if (it != resources.end())
        {
            return it->second.first;
        }
        std::shared_ptr<T> resource = std::make_shared<T>();
        if (!resource->loadFromFile(path))
        {
            return -1;
        }
        resources.insert(std::make_pair(path, std::make_pair(currentID, resource)));
        return currentID++;
    }

    void remove(int id)
    {
        for (auto it = resources.begin(); it != resources.end(); ++it)
        {
            if (it->second.first == id)
            {
                resources.erase(it->first);
            }
        }
    }

    std::shared_ptr<T> get(int id)
    {
        for (auto it = resources.begin(); it != resources.end(); ++it)
        {
            if (it->second.first == id)
            {
                return it->second.second;
            }
        }
        return nullptr;
    }

    bool has(int id)
    {
        return (get(id) != nullptr);
    }
private:
    int currentID;
    std::map<std::string, std::pair<int, std::shared_ptr<T>>> resources;
};

#endif