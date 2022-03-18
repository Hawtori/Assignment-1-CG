#pragma once
#include "IComponent.h"


class SquareMovement : public Gameplay::IComponent {
private:
	int segmentIndex = 0;
	float timer = 0, segmentTime = 1.75f;
public:
	typedef std::shared_ptr<SquareMovement> Sptr;

	SquareMovement() = default;
	float MoveSpeed;

	virtual void Update(float deltaTime) override;

	virtual void RenderImGui() override;

	virtual nlohmann::json ToJson() const override;
	static SquareMovement::Sptr FromJson(const nlohmann::json & data);

	MAKE_TYPENAME(SquareMovement);
};

