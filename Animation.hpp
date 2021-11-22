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

class Animation
{
public:
    Animation();
    void addFrame(int textureID, int x, int y, int width, int height, float frameTime);
    const FrameData* getCurFrame() const;
    bool updateFrame(float deltaTime);
    void reset();
private:
    void incrementFrame();
    std::vector<FrameData> frames;
    int curFrameIndex;
    float curFrameTime;
};

#endif