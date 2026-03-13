#pragma once
#include "Level.hpp"
#include "Instance.hpp"

#ifdef _DEBUG
#include "MapEditor.hpp"
#endif

class StageDemo : public Level
{
public:
	StageDemo() = default;
	~StageDemo() {};

	void Init() override;
	void Update(float dt) override;
	void Restart() override;
	void End() override;

private:
#ifdef _DEBUG
	MapEditor mapEditor;
#endif
};