#pragma once
#include "Component.hpp"
#include <vector>
#include "glm.hpp"

enum AttackType
{
    NORMALSHOT,
    TOWARD_PLAYER,
    TOWARD_PLAYER_NWAY,
    NWAY,
    ANGLE,
    SPREAD360,
    TOWARD_PLAYER_SPREAD360,
    MISSILE
};

struct Attack
{
public:
    void SetAttackVariables(AttackType attackType_, float bulletSpeedX, float bulletSpeedY, float delayMax_, float shootDelayMax_ = 1.f,  int times = 1, float angle_ = 0.f, glm::vec2 bulletPosition_ = { 0.f,0.f });
    void SetNWayBuletAmount(int amount) { nWayAmount = amount; };
    void SetIsAttackOnce(bool isAttackOnce_) { isAttackOnce = isAttackOnce_; }

    AttackType attackType = AttackType::NORMALSHOT;

    float delay = 0.0f;
    float delayMax = 0.0f;

    float shootDelay = 0.0f;
    float shootDelayMax = 0.0f;

    int shootTimes = 0;
    int shootMaxTimes = 0;

    int nWayAmount = 0;
    float shootAngle = 0.f;

    bool isAttackOnce = false;
    bool isAttackEnd = false;

    glm::vec2 bulletSpeed = { 0.f,0.f };
    glm::vec2 bulletPosition = { 0.f,0.f };

private:
    void SetAttackType(AttackType attackType_);
    void SetDelayVariables(float delayMax_);
    void SetShootDelayVariables(float shootDelayMax_);
    void SetShootMaxTimes(int times) { shootMaxTimes = times; };
    void SetNBuletSpeed(float x, float y) { bulletSpeed = { x, y }; };  
};

class EnemyAttack : public Component
{
public:
    EnemyAttack() : Component(ComponentTypes::ENEMYATTACK){};
    ~EnemyAttack() override { attackList.clear(); }

    void AddAttack(AttackType attackType_, float bulletSpeedX, float bulletSpeedY, float delayMax_, glm::vec2 bulletPosition_ = { 0.f,0.f }, bool isAttackOnce_ = false, int nWayBuletAmount_ = 0, float angle_ = 0.f, float shootDelayMax_ = 1.f, int times = 1);
    void AddAttackByAngle(float bulletSpeed, float delayMax_, glm::vec2 bulletPosition_ = { 0.f,0.f }, bool isAttackOnce_ = false, float angle_ = 0.f, float shootDelayMax_ = 1.f, int times = 1);

    void Init() override {};
    void Update(float dt) override;
    void End() override {};

    void Normal(Attack& attack);
    void TowardPlayer(Attack& attack);
    void TowardPlayerNWay(Attack& attack);
    void NWay(Attack& attack);
    void Missile(Attack& attack);
    void Angle(Attack& attack);
    void Spread360(Attack& attack);
    void TowardPlayerSpread360(Attack& attack);

    void SetIsCanAttack(bool state) { isCanAttack = state; }

    bool GetIsAttackEnd() const
    {
        for (auto atk : attackList)
        {
            if (atk.isAttackEnd == false)
            {
                return false;
            }
        }
        return true;
    }

    void ResetAttack();
private:
    bool isCanAttack = true;
    std::vector<Attack> attackList;
};