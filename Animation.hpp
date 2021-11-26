#ifndef Animation_hpp
#define Animation_hpp

#include <vector>

struct FrameData
{
    int id;
    int x;
    int y;
    int width;
    int height;
    float displayTimeSeconds;
};

enum class FacingDirection
{
    None,
    Left,
    Right
};

class Animation
{
public:
    Animation(FacingDirection direction);
    void addFrame(int textureID, int x, int y, int width, int height, float frameTime);
    const FrameData* getCurFrame() const;
    bool updateFrame(float deltaTime);
    void reset();
    void setDirection(FacingDirection dir);
    FacingDirection getDirection() const;
private:
    void incrementFrame();
    std::vector<FrameData> frames;
    int curFrameIndex;
    float curFrameTime;
    FacingDirection direction;
};

#endif