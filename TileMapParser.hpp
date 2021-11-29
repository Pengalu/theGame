#ifndef TileMapParser_hpp
#define TileMapParser_hpp
#include <SFML/Graphics.hpp>
#include <unordered_map>
#include <sstream>
#include "XML_Parser/rapidxml.hpp"
#include "XML_Parser/rapidxml_iterators.hpp"
#include "XML_Parser/rapidxml_print.hpp"
#include "XML_Parser/rapidxml_utils.hpp"
#include "Tile.h"
// #include "Utilities.h"
#include "Object.hpp"
#include "C_Sprite.hpp"

using Layer = std::vector<std::shared_ptr<Tile>>;
using MapTiles = std::map<std::string, std::shared_ptr<Layer>>;
using TileSet = std::unordered_map<unsigned int, std::shared_ptr<TileInfo>>;

struct TileSheetData
{
    int textureID;
    sf::Vector2u imageSize;
    int columns;
    int rows;
    sf::Vector2u tileSize;
};

class TileMapParser
{
public:
    TileMapParser(ResourceAllocator<sf::Texture>& textureAllocator);
    std::vector<std::shared_ptr<Object>>
    Parse(const std::string& file, sf::Vector2i offset);
private:
    std::shared_ptr<TileSheetData> buildTileSheetData(rapidxml::xml_node<>* rootNode);
    std::shared_ptr<MapTiles> buildMapTiles(rapidxml::xml_node<>* rootNode);
    std::pair<std::string, std::shared_ptr<Layer>> buildLayer(rapidxml::xml_node<>* layerNode, std::shared_ptr<TileSheetData> tileSheetData);
    ResourceAllocator<sf::Texture>& textureAllocator;
};

#endif