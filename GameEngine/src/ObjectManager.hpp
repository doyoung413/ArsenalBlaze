/*-------------------------------------------------------*/
//Author: Doyoung Lee (doyoung413@gmail.com)
//File: ObjectManager.hpp
//Description: Header file for class which manage for objects
/*-------------------------------------------------------*/
#pragma once
#include "Object.hpp"

#include <algorithm>
#include <map>
#include <memory>
#include <vector>
#include <iostream>

class ObjectManager
{
public:
    ObjectManager()  = default;
    ~ObjectManager() = default;

	void Update(float dt);
    void End();

    ObjectManager* GetObjectManager()
    {
	    static ObjectManager* Scene_manager = new ObjectManager();
	    return Scene_manager;
    }

    template <typename T, typename... Args>
    void AddObject(Args... args)
    {
        objectMap[lastObjectID] = std::unique_ptr<T>(std::make_unique<T>(std::forward<Args>(args)...));;
        objectMap[lastObjectID].get()->SetId(lastObjectID);
        ++lastObjectID;
    }

    void Destroy(int id);
    void DestroyAllObjects();

    int GetLastObjectID() { return (lastObjectID - 1); }
    std::map<int, std::unique_ptr<Object>>& GetObjectMap() { return objectMap; }

    Object* FindObjectWithName(std::string name);
    Object* FindObjectWithId(int id) { return objectMap.at(id).get(); }
    Object* GetLastObject() { return objectMap.at(lastObjectID - 1).get(); }

    void CollideObjects();
private:
    int                                    lastObjectID = 0;
    std::map<int, std::unique_ptr<Object>> objectMap;
    std::vector<int>                       objectsToBeDeleted;
};