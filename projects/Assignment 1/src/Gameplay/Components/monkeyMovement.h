#pragma once
#include "IComponent.h"


class monkeyMovement : public Gameplay::IComponent {
private:
	float timer = 0;
	float maxTime = 1.f;
public:
	typedef std::shared_ptr<monkeyMovement> Sptr;

	monkeyMovement() = default;
	float MoveSpeed;

	virtual void Update(float deltaTime) override;

	virtual void RenderImGui() override;

	virtual nlohmann::json ToJson() const override;
	static monkeyMovement::Sptr FromJson(const nlohmann::json& data);

	MAKE_TYPENAME(monkeyMovement);
};

