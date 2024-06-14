#pragma once
#include "Object.hpp"

enum class ItemType
{
	N, H, L
};

class Item : public Object
{
public:
	Item() = default;
	Item(float positionX, float positionY, float speedX, float speedY, float width, float height,
           DrawType drawType, std::string name, ObjectType objectType);
	~Item() {};

	void Init() override;
	void Update(float dt) override;
	
	ItemType GetCurrentItemType() { return currentItem; }
protected:
	float moveDelay = 0.f;
	float changeDelay = 0.f;
	float direction = -1.f;

	int currentItemNumber = 1;
	ItemType currentItem = ItemType::H;
};