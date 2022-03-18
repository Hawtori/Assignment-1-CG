#include "Gameplay/Components/monkeyMovement.h"

#include "Gameplay/GameObject.h"

#include "Utils/ImGuiHelper.h"
#include "Utils/JsonGlmHelpers.h"

void monkeyMovement::Update(float deltaTime) {
	if (timer < maxTime) {
		//move around
		GetGameObject()->SetPostion(glm::vec3(GetGameObject()->GetPosition().x + (MoveSpeed * deltaTime), GetGameObject()->GetPosition().y, GetGameObject()->GetPosition().z));
		
		timer += deltaTime;
	}
	else {
		timer = 0;
		MoveSpeed = -MoveSpeed;
	}
}

void monkeyMovement::RenderImGui() {
	LABEL_LEFT(ImGui::DragFloat3, "Speed", &MoveSpeed);
}

nlohmann::json monkeyMovement::ToJson() const {
	return {
		{ "speed", MoveSpeed }
	};
}

monkeyMovement::Sptr monkeyMovement::FromJson(const nlohmann::json& data) {
	monkeyMovement::Sptr result = std::make_shared<monkeyMovement>();
	result->MoveSpeed = JsonGet(data, "speed", result->MoveSpeed);
	return result;
}