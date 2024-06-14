#include "EnemyAttack.hpp"
#include "Instance.hpp"
#include "Physics.hpp"

#include "Object/EnemyBullet.hpp"
#include "Object/EnemySpreadBullet.hpp"
#include "Object/EnemyMissile.hpp"

void Attack::SetAttackType(AttackType attackType_)
{
	attackType = attackType_;
}

void Attack::SetDelayVariables(float delayMax_)
{
	delayMax = delayMax_;
}

void Attack::SetShootDelayVariables(float shootDelayMax_)
{
	shootDelayMax = shootDelayMax_;
}

void Attack::SetAttackVariables(AttackType attackType_, float bulletSpeedX, float bulletSpeedY, float delayMax_, float shootDelayMax_, int times, float angle_,glm::vec2 bulletPosition_)
{
	SetAttackType(attackType_);
	SetDelayVariables(delayMax_);
	SetShootDelayVariables(shootDelayMax_);
	SetShootMaxTimes(times);
	SetNBuletSpeed(bulletSpeedX, bulletSpeedY);
	shootDelay = shootDelayMax_;
	shootAngle = angle_;
	bulletPosition = bulletPosition_;
};

void EnemyAttack::AddAttack(AttackType attackType_, float bulletSpeedX, float bulletSpeedY, float delayMax_,glm::vec2 bulletPosition_, bool isAttackOnce_, int nWayBuletAmount_, float angle_, float shootDelayMax_, int times)
{
	Attack temp;
	temp.SetAttackVariables(attackType_, bulletSpeedX, bulletSpeedY, delayMax_, shootDelayMax_, times, angle_, bulletPosition_);
	temp.SetNWayBuletAmount(nWayBuletAmount_);
	temp.SetIsAttackOnce(isAttackOnce_);

	attackList.push_back(temp);
}

void EnemyAttack::AddAttackByAngle(float bulletSpeed, float delayMax_,glm::vec2 bulletPosition_, bool isAttackOnce_, float angle_, float shootDelayMax_, int times)
{
	Attack temp;
	temp.SetAttackVariables(ANGLE, bulletSpeed, bulletSpeed, delayMax_, shootDelayMax_, times, angle_, bulletPosition_);
	temp.SetIsAttackOnce(isAttackOnce_);

	attackList.push_back(temp);
}

void EnemyAttack::Update(float dt)
{
	if (isCanAttack == true)
	{
		for (auto& attack : attackList)
		{
			if (attack.isAttackEnd != true)
			{
				attack.delay += dt;
				if (attack.delay > attack.delayMax)
				{
					attack.shootDelay += dt;
					if (attack.shootDelay > attack.shootDelayMax)
					{
						attack.shootDelay = 0.f;
						attack.shootTimes++;
						switch (attack.attackType)
						{
						case AttackType::NORMALSHOT:
							Normal(attack);
							break;
						case AttackType::TOWARD_PLAYER:
							TowardPlayer(attack);
							break;
						case AttackType::TOWARD_PLAYER_NWAY:
							TowardPlayerNWay(attack);
							break;
						case AttackType::MISSILE:
							Missile(attack);
							break;
						case AttackType::ANGLE:
							Angle(attack);
							break;
						case AttackType::SPREAD360:
							Spread360(attack);
							break;
						case AttackType::TOWARD_PLAYER_SPREAD360:
							TowardPlayerSpread360(attack);
							break;
						}

						if (attack.shootTimes == attack.shootMaxTimes)
						{
							attack.shootTimes = 0;
							attack.delay = 0;
							
							if (attack.isAttackOnce == true)
							{
								attack.isAttackEnd = true;
							}
						}
					}

				}
			}
		}
	}
}

void EnemyAttack::Normal(Attack& attack)
{
	Instance::GetObjectManager()->AddObject<EnemyBullet>(attack.bulletPosition.x + GetOwner()->GetPosition().x, attack.bulletPosition.y + GetOwner()->GetPosition().y,
		attack.bulletSpeed.x, attack.bulletSpeed.y, 8.f, 8.f, DrawType::RECTANGLE, "EnemyBullet");
}

void EnemyAttack::TowardPlayer(Attack& attack)
{
	Object* target = Instance::GetObjectManager()->FindObjectWithName("Player");
	if (target != nullptr)
	{
		float targetX = target->GetPosition().x;
		float targetY = target->GetPosition().y;

		float dx = targetX - GetOwner()->GetPosition().x;
		float dy = targetY - GetOwner()->GetPosition().y;

		float tempAngle = atan2(dy, dx);

		glm::vec2 tempSpeed = { cos(tempAngle) * attack.bulletSpeed.x,
			sin(tempAngle) * attack.bulletSpeed.y };

		Instance::GetObjectManager()->AddObject<EnemyBullet>(attack.bulletPosition.x + GetOwner()->GetPosition().x, attack.bulletPosition.y + GetOwner()->GetPosition().y,
			tempSpeed.x, tempSpeed.y, 8.f, 8.f, DrawType::RECTANGLE, "EnemyBullet");
	}
}

void EnemyAttack::TowardPlayerNWay(Attack& attack)
{
	Object* target = Instance::GetObjectManager()->FindObjectWithName("Player");
	if (target != nullptr)
	{
		for (int i = 0; i < attack.nWayAmount; i++)
		{
			float targetX = target->GetPosition().x;
			float targetY = target->GetPosition().y;

			float dx = targetX - GetOwner()->GetPosition().x + static_cast<float>((i - attack.nWayAmount / 2.f) * 60.f);
			float dy = targetY - GetOwner()->GetPosition().y + static_cast<float>((i - attack.nWayAmount / 2.f) * 60.f);

			float tempAngle = atan2(dy, dx);

			glm::vec2 tempSpeed = { cos(tempAngle) * attack.bulletSpeed.x,
				sin(tempAngle) * attack.bulletSpeed.y };

			Instance::GetObjectManager()->AddObject<EnemyBullet>(attack.bulletPosition.x + GetOwner()->GetPosition().x, attack.bulletPosition.y + GetOwner()->GetPosition().y,
				tempSpeed.x, tempSpeed.y, 8.f, 8.f, DrawType::RECTANGLE, "EnemyBullet");
		}
	}
}

void EnemyAttack::Missile(Attack& attack)
{
	Instance::GetObjectManager()->AddObject<EnemyMissile>(attack.bulletPosition.x + GetOwner()->GetPosition().x, attack.bulletPosition.y + GetOwner()->GetPosition().y,
		attack.bulletSpeed.x, attack.bulletSpeed.y, 32.f, 7.f, DrawType::RECTANGLE, "EnemyBullet", ObjectType::ENEMYMISSILE);
	Instance::GetObjectManager()->GetObjectMap().at(Instance::GetObjectManager()->GetLastObjectID()).get()->SetRotate(90.f);
}

void EnemyAttack::Angle(Attack& attack)
{
	float tempAngle = attack.shootAngle;
	glm::vec2 tempSpeed = { cos(-tempAngle * 3.14f / 180.f) * attack.bulletSpeed.x,
		sin(-tempAngle * 3.14f / 180.f) * attack.bulletSpeed.y };

	Instance::GetObjectManager()->AddObject<EnemyBullet>(attack.bulletPosition.x + GetOwner()->GetPosition().x, attack.bulletPosition.y + GetOwner()->GetPosition().y,
		tempSpeed.x, tempSpeed.y, 8.f, 8.f, DrawType::RECTANGLE, "EnemyBullet");
}

void EnemyAttack::Spread360(Attack& attack)
{
	Instance::GetObjectManager()->AddObject<EnemySpreadBullet>(attack.bulletPosition.x + GetOwner()->GetPosition().x, attack.bulletPosition.y + GetOwner()->GetPosition().y,
		attack.bulletSpeed.x, attack.bulletSpeed.y, 16.f, 16.f, DrawType::RECTANGLE, "EnemyBullet", attack.shootDelayMax, attack.nWayAmount, attack.bulletSpeed.x);
}

void EnemyAttack::TowardPlayerSpread360(Attack& attack)
{
	Object* target = Instance::GetObjectManager()->FindObjectWithName("Player");
	if (target != nullptr)
	{
		float targetX = target->GetPosition().x;
		float targetY = target->GetPosition().y;

		float dx = targetX - GetOwner()->GetPosition().x;
		float dy = targetY - GetOwner()->GetPosition().y;

		float tempAngle = atan2(dy, dx);

		glm::vec2 tempSpeed = { cos(tempAngle) * attack.bulletSpeed.x,
			sin(tempAngle) * attack.bulletSpeed.y };

		Instance::GetObjectManager()->AddObject<EnemySpreadBullet>(attack.bulletPosition.x + GetOwner()->GetPosition().x, attack.bulletPosition.y + GetOwner()->GetPosition().y,
			tempSpeed.x, tempSpeed.y, 16.f, 16.f, DrawType::RECTANGLE, "EnemyBullet", attack.shootDelayMax, attack.nWayAmount, attack.bulletSpeed.x);
	}
}

void EnemyAttack::ResetAttack()
{
	for (auto& atk : attackList)
	{
		atk.isAttackEnd = false;
	}
}
