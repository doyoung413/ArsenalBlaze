/*-------------------------------------------------------*/
//Author: Doyoung Lee (doyoung413@gmail.com)
//File: ObjectManager.cpp
//Description: Source file for class which manage for objects
/*-------------------------------------------------------*/
#include "ObjectManager.hpp"

#include <iostream>
void ObjectManager::Update(float dt)
{
	std::for_each(objectMap.begin(), objectMap.end(), [&](auto& obj) { obj.second->Update(dt); });
	std::for_each(objectsToBeDeleted.begin(), objectsToBeDeleted.end(), [&](int id) { objectMap.erase(id); });
	objectsToBeDeleted.clear();
}

void ObjectManager::End()
{
	DestroyAllObjects();
}

void ObjectManager::Destroy(int id)
{
	objectsToBeDeleted.push_back(id);
}

void ObjectManager::DestroyAllObjects()
{
	lastObjectID = 0;
	for (auto& obj : objectMap)
	{
		obj.second.reset();
	}
	objectsToBeDeleted.clear();
	objectMap.clear();
}

Object* ObjectManager::FindObjectWithName(std::string name)
{
	for (auto& obj : objectMap)
	{
		if (obj.second.get()->GetName() == name)
		{
			return obj.second.get();
		}
	}
	return nullptr;
}

void ObjectManager::CollideObjects()
{
	for (auto& target : objectMap)
	{
		for (auto& object : objectMap)
		{
			if (target.second != nullptr && object.second != nullptr && target.second != object.second)
			{
				target.second->CollideObject(object.second.get());
			}
		}
	}
}
