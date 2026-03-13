/*-------------------------------------------------------*/
//Author: Doyoung Lee (doyoung413@gmail.com)
//File: Main.cpp
//Description: Source file for main function
/*-------------------------------------------------------*/
#include "Application.hpp"

#include "Level/Title.hpp"
#include "Level/StageDemo.hpp"
#include "Level/Shop.hpp"
#include "Level/Option.hpp"

#include "FileManager.hpp"

#undef main

void LoadAssets()
{
	Instance::GetSoundManager()->LoadSoundFilesFromFolder("Assets/Sounds");

	Instance::GetSpriteManager()->LoadTexture("Assets/Sprites/player.png", "Player");
	Instance::GetSpriteManager()->LoadAnimatedTexture("Assets/Sprites/playerBoost.png", "PlayerBoost", 4, 1, 0.2f);

	Instance::GetSpriteManager()->LoadTexture("Assets/Sprites/bulletW.png", "BulletW");
	Instance::GetSpriteManager()->LoadTexture("Assets/Sprites/bulletWS.png", "BulletWS");
	Instance::GetSpriteManager()->LoadTexture("Assets/Sprites/bulletWFire.png", "BulletWFire");

	Instance::GetSpriteManager()->LoadTexture("Assets/Sprites/laser.png", "laser");
	Instance::GetSpriteManager()->LoadTexture("Assets/Sprites/laserHit.png", "laserHit");
	Instance::GetSpriteManager()->LoadAnimatedTexture("Assets/Sprites/laserPoint.png", "laserPoint", 4, 1, 0.4f);
	Instance::GetSpriteManager()->LoadAnimatedTexture("Assets/Sprites/laserReduce.png", "laserReduce", 6, 1, 0.8f, false);

	Instance::GetSpriteManager()->LoadTexture("Assets/Sprites/homingMissile.png", "HMissile");
	Instance::GetSpriteManager()->LoadAnimatedTexture("Assets/Sprites/homingMissileEffect-0.png", "HMissileE", 9, 1, 0.8f, false);

	Instance::GetSpriteManager()->LoadTexture("Assets/Sprites/hpBar.png", "HpBar");
	Instance::GetSpriteManager()->LoadTexture("Assets/Sprites/hpBar1.png", "HpBar1");

	Instance::GetSpriteManager()->LoadTexture("Assets/Sprites/enemyA.png", "EnemyA");
	Instance::GetSpriteManager()->LoadTexture("Assets/Sprites/enemyB.png", "EnemyB");
	Instance::GetSpriteManager()->LoadTexture("Assets/Sprites/enemyC.png", "EnemyC");
	Instance::GetSpriteManager()->LoadAnimatedTexture("Assets/Sprites/enemyItem.png", "EnemyItem", 4, 1, 0.5f);

	Instance::GetSpriteManager()->LoadAnimatedTexture("Assets/Sprites/enemyBulletS.png", "enemyBulletS", 4, 1, 0.5f);
	Instance::GetSpriteManager()->LoadTexture("Assets/Sprites/itemN.png", "itemN");
	Instance::GetSpriteManager()->LoadTexture("Assets/Sprites/itemH.png", "itemH");
	Instance::GetSpriteManager()->LoadTexture("Assets/Sprites/itemL.png", "itemL");

	Instance::GetSpriteManager()->LoadTexture("Assets/Sprites/protoTitle.png", "Title");

	Instance::GetSpriteManager()->LoadTexture("Assets/Sprites/EquipSelectionBarrier.png", "EquipSelectionBarrier");
	Instance::GetSpriteManager()->LoadTexture("Assets/Sprites/EquipSelectionHP.png", "EquipSelectionHP");
	Instance::GetSpriteManager()->LoadTexture("Assets/Sprites/EquipSelectionNone.png", "EquipSelectionNone");

	Instance::GetSpriteManager()->LoadTexture("Assets/Sprites/WeaponSelectionExit.png", "WeaponSelectionExit");
	Instance::GetSpriteManager()->LoadTexture("Assets/Sprites/WeaponSelectionLaser.png", "WeaponSelectionLaser");
	Instance::GetSpriteManager()->LoadTexture("Assets/Sprites/WeaponSelectionNone.png", "WeaponSelectionNone");
	Instance::GetSpriteManager()->LoadTexture("Assets/Sprites/WeaponSelectionHoming.png", "WeaponSelectionHoming");

	Instance::GetSpriteManager()->LoadTexture("Assets/Sprites/playerBarrier.png", "playerBarrier");
}

int main()
{
	Application application;

	application.Init("Arsenal Blaze (Tech Demo)", 640, 480, false, FrameRate::FPS_60);
	Instance::GetWindow()->SetScreenRatio({ 4,3 });
	Instance::GetSoundManager()->Initialize(8);
	LoadAssets();

	Instance::GetSpriteManager()->SetBackGroundColor({ 0.f,0.f,0.f,1.f });
	Instance::GetLevelManager()->AddLevel(new Title());
	Instance::GetLevelManager()->AddLevel(new Shop());
	Instance::GetLevelManager()->AddLevel(new StageDemo());
	Instance::GetLevelManager()->AddLevel(new Option());

	FileManager::LoadSetting("Setting.ini");
	application.Update();

	application.End();
	
	return 0;
}
