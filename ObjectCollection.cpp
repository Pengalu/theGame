#include "ObjectCollection.hpp"

void ObjectCollection::add(std::shared_ptr<Object> object)
{
    newObjects.push_back(object);
}

void ObjectCollection::update(float deltaTime)
{
    for (const auto& o : objects)
    {
        o->update(deltaTime);
    }
}

void ObjectCollection::lateUpdate(float deltaTime)
{
    for (const auto& o : objects)
    {
        o->lateUpdate(deltaTime);
    }
}

void ObjectCollection::draw(Window& window)
{
    for (const auto& o : objects)
    {
        o->draw(window);
    }
}

void ObjectCollection::processNewObjects()
{
    if (newObjects.size() > 0)
    {
        for (const auto& o : newObjects)
        {
            o->awake();
        }

        for (const auto& o : newObjects)
        {
            o->start();
        }

        objects.assign(newObjects.begin(), newObjects.end());
        newObjects.clear();
    }
}

void ObjectCollection::processRemovals()
{
    auto objectIterator = objects.begin();
    while (objectIterator != objects.end())
    {
        auto obj = **objectIterator;
        if (obj.isQueuedForRemoval())
        {
            objectIterator = objects.erase(objectIterator);
        }
        else
        {
            ++objectIterator;
        }
    }
}