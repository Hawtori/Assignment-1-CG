#pragma once
#include "IComponent.h"


class UIControls : public Gameplay::IComponent {
private:
	void resetButtons();
public:
	typedef std::shared_ptr<UIControls> Sptr;

	UIControls();
	bool buttons[10];

	virtual void Update(float deltaTime) override;

	virtual void RenderImGui() override;

	MAKE_TYPENAME(UIControls);
};

