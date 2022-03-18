#include "Gameplay/Components/SquareMovement.h"

#include "Gameplay/GameObject.h"

#include "Utils/ImGuiHelper.h"
#include "Utils/JsonGlmHelpers.h"

void SquareMovement::Update(float deltaTime) {
	if (timer < segmentTime) {
		//move around
		if(segmentIndex < 2)
			GetGameObject()->SetPostion(glm::vec3(GetGameObject()->GetPosition().x + (MoveSpeed * deltaTime * (segmentIndex % 2)), GetGameObject()->GetPosition().y + (MoveSpeed * deltaTime * !(segmentIndex % 2)), GetGameObject()->GetPosition().z));
		else
			GetGameObject()->SetPostion(glm::vec3(GetGameObject()->GetPosition().x - (MoveSpeed * deltaTime * (segmentIndex % 2)), GetGameObject()->GetPosition().y - (MoveSpeed * deltaTime * !(segmentIndex % 2)), GetGameObject()->GetPosition().z));
		timer += deltaTime;
	}
	else {
		timer = 0;
		segmentIndex++; segmentIndex %= 4;
	}
}

void SquareMovement::RenderImGui() {
	LABEL_LEFT(ImGui::DragFloat3, "Speed", &MoveSpeed);
}

nlohmann::json SquareMovement::ToJson() const {
	return {
		{ "speed", MoveSpeed }
	};
}

SquareMovement::Sptr SquareMovement::FromJson(const nlohmann::json& data) {
	SquareMovement::Sptr result = std::make_shared<SquareMovement>();
	result->MoveSpeed = JsonGet(data, "speed", result->MoveSpeed);
	return result;
}