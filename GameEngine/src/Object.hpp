/*-------------------------------------------------------*/
//Author: Doyoung Lee (doyoung413@gmail.com)
//File: Object.hpp
//Description: Header file for basic object class
/*-------------------------------------------------------*/
#pragma once
#include <string>
#include <vector>

#include "Component.hpp"
#include "ObjectType.hpp"
#include "Color/Color4f.hpp"
#include "Texture/Animation.hpp"
#include "glm.hpp"

enum class DrawType
{
	NONE,
	RECTANGLE,
	RECTANGLELINE,
	SPRITE,
	SPRITEANIMATION,
};

class Object
{
public:
	Object() = default;
	Object(float positionX, float positionY, float speedX, float speedY, float width, float height,
		DrawType drawType, std::string name = "", ObjectType objectType = ObjectType::NONE);
	~Object() { DestroyAllComponents(); }
	
	virtual void Init();
	virtual void Update(float dt);
	virtual void Draw(float dt);
	virtual void CollideObject(Object* /*obj*/) {};

	int GetId() { return id; }
	glm::vec3 GetPosition() { return position; }
	glm::vec3 GetSize() { return size; }
	glm::vec3 GetSpeed() { return speed; }

	float GetRotate() { return angle; }
	Color4f GetColor() { return color; }
	float GetDepth() { return depth; }

	DrawType   GetDrawType() { return drawType; }
	ObjectType GetObjectType() { return objectType; }
	std::string GetName() { return objectName; }
	std::string GetSpriteName() { return spriteName; }

	void SetId(int value) { id = value; }
	void SetRotate(float value);
	void SetXPosition(float newX) { position.x = newX; }
	void SetYPosition(float newY) { position.y = newY; }
	void SetXSpeed(float newX) { speed.x = newX; }
	void SetYSpeed(float newY) { speed.y = newY; }
	void SetXSize(float newX) { size.x = newX; }
	void SetYSize(float newY) { size.y = newY; }
	void SetDepth(float value) { depth = value; }

	void SetName(std::string name) { objectName = name; }
	void SetSpriteName(std::string name);
	void SetDrawType(DrawType type) { drawType = type; }
	void SetObjectType(ObjectType type) { objectType = type; }
	void SetColor(Color4f color4) { color = color4; }

	bool isEdgeOfCamera() noexcept;
	bool isInOfCamera() noexcept;
	bool isOutOfCamera() noexcept;
	bool isOutOfWindowHigh() noexcept;

	Animation* GetAnimation() { return &individualAnimation; }

	template <typename ComponentTypes> bool HasComponent()
	{
		for (auto list : componentList)
		{
			if (typeid(*list).name() == typeid(ComponentTypes).name())
				return true;
		}
		return false;
	}

	template<typename ComponentTypes> constexpr void AddComponent()
	{
		if (HasComponent<ComponentTypes>())
		{
			return;
		}
		ComponentTypes* componentType = new ComponentTypes();
		dynamic_cast<Component*>(componentType)->SetOwner(this);
		this->componentList.push_back(componentType);
	}

	template<typename ComponentTypes> ComponentTypes* GetComponent()
	{
		for (auto list : componentList)
		{
			if (typeid(*list).name() == typeid(ComponentTypes).name())
				return dynamic_cast<ComponentTypes*>(list);
		}
		return nullptr;
	}

	void DestroyAllComponents();
protected:
	glm::vec3 position{ 0.f, 0.f, 0.f };
	glm::vec3 speed{ 0.f, 0.f, 0.f };
	glm::vec3 size{ 0.f, 0.f, 0.f };
	float depth = 0.f;
	float angle = 0.f;

	Color4f color = Color4f(1.f, 1.f, 1.f, 1.f);

	int        id = 0;
	DrawType   drawType = DrawType::NONE;
	ObjectType objectType = ObjectType::NONE;

	std::string objectName = "";
	std::string spriteName = "";
	std::vector<Component*> componentList;

	Animation individualAnimation;
};