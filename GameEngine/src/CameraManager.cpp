/*-------------------------------------------------------*/
//Author: Doyoung Lee (doyoung413@gmail.com)
//File: CameraManager.cpp
//Description: Source file for camera class
/*-------------------------------------------------------*/
#include "CameraManager.hpp"

void CameraManager::Init(glm::vec2 viewSize, float zoom, float angle)
{
	camera.SetViewSize(static_cast<int>(viewSize.x), static_cast<int>(viewSize.y));
	camera.SetZoom(zoom);
	camera.Rotate(angle);
}

void CameraManager::Update()
{
	camera.Update();
}

void CameraManager::TargetAt(glm::vec3 targetLocation)
{
	camera.SetCenter(targetLocation);
}

void CameraManager::Reset()
{
	camera.ResetUp({ 0.f,1.f,0.1f });
	camera.SetCenter({ 0.f,0.f,0.f });
	camera.SetZoom(1.f);
}