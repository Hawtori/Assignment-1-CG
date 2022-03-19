#include "Gameplay/Components/UIControls.h"

#include "Gameplay/GameObject.h"


#include "Gameplay/InputEngine.h"
#include "Utils/ImGuiHelper.h"
#include "Utils/JsonGlmHelpers.h"

UIControls::UIControls() {
	for (int i = 0; i < 10; i++)buttons[i] = 0;
}

void UIControls::Update(float deltaTime) {
	if (InputEngine::IsKeyDown(GLFW_KEY_1)) {
		resetButtons();
		buttons[0] = 1;
	}
	if (InputEngine::IsKeyDown(GLFW_KEY_2)) {
		resetButtons();
		buttons[1] = 1;
	}
	if (InputEngine::IsKeyDown(GLFW_KEY_3)) {
		resetButtons();
		buttons[2] = 1;
	}
	if (InputEngine::IsKeyDown(GLFW_KEY_4)) {
		resetButtons();
		buttons[3] = 1;
	}
	if (InputEngine::IsKeyDown(GLFW_KEY_5)) {
		resetButtons();
		buttons[4] = 1;
	}
	if (InputEngine::IsKeyDown(GLFW_KEY_6)) {
		buttons[5] = !buttons[5];
	}
	if (InputEngine::IsKeyDown(GLFW_KEY_6)) {
		buttons[6] = !buttons[6];
	}
	if (InputEngine::IsKeyDown(GLFW_KEY_6)) {
		buttons[7] = !buttons[7];
	}
	if (InputEngine::IsKeyDown(GLFW_KEY_6)) {
		buttons[8] = !buttons[8];
	}
	if (InputEngine::IsKeyDown(GLFW_KEY_6)) {
		buttons[9] = !buttons[9];
	}
}

void UIControls::resetButtons() {
	for (int i = 0; i < 5; i++) buttons[i] = 0;
}

void UIControls::RenderImGui() {
	if(buttons[0])
	LABEL_LEFT(ImGui::Text, "Current setting: No Lighting");	
	if(buttons[1])
	LABEL_LEFT(ImGui::Text, "Current setting: Ambient Lighting");
	if(buttons[2])
	LABEL_LEFT(ImGui::Text, "Current setting: Specular Lighting");
	if(buttons[3])
	LABEL_LEFT(ImGui::Text, "Current setting: Ambient + specular Lighting");
	if(buttons[4])
	LABEL_LEFT(ImGui::Text, "Current setting: Ambient + specular + custom Lighting");
	if(buttons[5])
	LABEL_LEFT(ImGui::Text, "Current setting: Diffuse warp TOGGLED");
	if(buttons[6])
	LABEL_LEFT(ImGui::Text, "Current setting: Specular warp TOGGLED");
	if(buttons[7])
	LABEL_LEFT(ImGui::Text, "Current setting: Color Grading warm TOGGLED");
	if(buttons[8])
	LABEL_LEFT(ImGui::Text, "Current setting: Color Grading cool TOGGLED");
	if(buttons[9])
	LABEL_LEFT(ImGui::Text, "Current setting: Color Grading custom TOGGLED");

}
