#include "Animation.hpp"

Animation::Animation() :
frames(0), curFrameIndex(0), curFrameTime(0.f) {}

void Animation::addFrame(int textureID, int x, int y, int width, int height, float frameTime)
{
    FrameData data;
    data.id = textureID;
    data.x = x;
    data.y = y;
    data.width = width;
    data.height = height;
    data.displayTimeSeconds = frameTime;
    frames.push_back(data);
}

const FrameData* Animation::getCurFrame() const
{
    if (frames.size() > 0)
    {
        return &frames[curFrameIndex];
    }
    return nullptr;
}

bool Animation::updateFrame(float deltaTime)
{
    if (frames.size() > 0)
    {
        curFrameTime += deltaTime;
        if (curFrameTime >= frames[curFrameIndex].displayTimeSeconds)
        {
            curFrameTime = 0.f;
            incrementFrame();
            return true;
        }
    }
    return false;
}

void Animation::incrementFrame()
{
    curFrameIndex = (curFrameIndex + 1) % frames.size();
}

void Animation::reset()
{
    curFrameIndex = 0;
    curFrameTime = 0.f;
}
