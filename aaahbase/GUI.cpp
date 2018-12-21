#include "Includes.h"
#include <d3d9.h>
#include <tchar.h>
#include <dinput.h>
#include "Dwmapi.h"
#include "imgui.h"
#include "imgui_impl_dx9.h"

#include "IniParser.h"

bool flash = false;

void SaveConfig() {
	std::ofstream ofs("config");
	ofs << "; aaahbase config";
	ofs << "\n";
	ofs << "[Visuals]\n";
	ofs << "Chams = " << g_Variables::Visuals::Chams << "\n";
	ofs << "NoFlash = " << flash << "\n";

	ofs << "[Misc]\n";
	ofs << "Bunnyhop = " << g_Variables::Misc::Bhop << "\n";
}

void LoadConfig() {
	INIReader reader("config");
	if (reader.ParseError() == 0) {
		g_Variables::Visuals::Chams = reader.GetBoolean("Visuals", "Chams", false);
		flash = reader.GetBoolean("Visuals", "NoFlash", false);

		g_Variables::Misc::Bhop = reader.GetBoolean("Misc", "Bunnyhop", false);
	}
}

void LoadTheme(ImGuiStyle& style) {
	style.WindowMinSize = ImVec2(200, 200);
	style.FramePadding = ImVec2(4, 2);
	style.ItemSpacing = ImVec2(6, 3);
	style.ItemInnerSpacing = ImVec2(6, 4);
	style.Alpha = 1.f;
	style.FrameRounding = 0.0f;
	style.IndentSpacing = 6.0f;
	style.ItemInnerSpacing = ImVec2(3, 4);
	style.ColumnsMinSpacing = 50.0f;
	style.GrabMinSize = 14.0f;
	style.GrabRounding = 3.0f;
	style.ScrollbarSize = 12.0f;
	style.ScrollbarRounding = 4.0f;
	style.AntiAliasedLines = true;
	style.WindowRounding = 2.f;

	style.Colors[ImGuiCol_Text] = ImVec4(0.86f, 0.93f, 0.89f, 0.78f);
	style.Colors[ImGuiCol_TextDisabled] = ImVec4(0.92f, 0.18f, 0.29f, 0.78f);
	style.Colors[ImGuiCol_WindowBg] = ImVec4(0.05f, 0.05f, 0.05f, 1.00f);
	style.Colors[ImGuiCol_ChildWindowBg] = ImVec4(0.05f, 0.05f, 0.05f, 0.58f);
	style.Colors[ImGuiCol_PopupBg] = ImVec4(0.20f, 0.22f, 0.27f, 1.00f);
	style.Colors[ImGuiCol_Border] = ImVec4(0.00f, 0.00f, 0.00f, 0.35f);
	style.Colors[ImGuiCol_BorderShadow] = ImVec4(0.00f, 0.00f, 0.00f, 0.00f);
	style.Colors[ImGuiCol_FrameBg] = ImVec4(0.05f, 0.05f, 0.05f, 1.00f);
	style.Colors[ImGuiCol_FrameBgHovered] = ImVec4(0.92f, 0.18f, 0.29f, 0.78f);
	style.Colors[ImGuiCol_FrameBgActive] = ImVec4(0.92f, 0.18f, 0.29f, 1.00f);
	style.Colors[ImGuiCol_TitleBg] = ImVec4(0.20f, 0.22f, 0.27f, 1.00f);
	style.Colors[ImGuiCol_TitleBgCollapsed] = ImVec4(0.20f, 0.22f, 0.27f, 0.75f);
	style.Colors[ImGuiCol_TitleBgActive] = ImVec4(0.92f, 0.18f, 0.29f, 1.00f);
	style.Colors[ImGuiCol_MenuBarBg] = ImVec4(0.20f, 0.22f, 0.27f, 0.47f);
	style.Colors[ImGuiCol_ScrollbarBg] = ImVec4(0.05f, 0.05f, 0.05f, 1.00f);
	style.Colors[ImGuiCol_ScrollbarGrab] = ImVec4(0.09f, 0.15f, 0.16f, 1.00f);
	style.Colors[ImGuiCol_ScrollbarGrabHovered] = ImVec4(0.92f, 0.18f, 0.29f, 0.78f);
	style.Colors[ImGuiCol_ScrollbarGrabActive] = ImVec4(0.92f, 0.18f, 0.29f, 1.00f);
	style.Colors[ImGuiCol_ComboBg] = ImVec4(0.3f, 0.32f, 0.37f, 1.00f);
	style.Colors[ImGuiCol_CheckMark] = ImVec4(0.71f, 0.18f, 0.29f, 1.00f);
	style.Colors[ImGuiCol_SliderGrab] = ImVec4(0.92f, 0.18f, 0.29f, 0.37f);
	style.Colors[ImGuiCol_SliderGrabActive] = ImVec4(0.92f, 0.18f, 0.29f, 1.00f);
	style.Colors[ImGuiCol_Button] = ImVec4(0.92f, 0.18f, 0.29f, 0.75f);
	style.Colors[ImGuiCol_ButtonHovered] = ImVec4(0.92f, 0.18f, 0.29f, 0.86f);
	style.Colors[ImGuiCol_ButtonActive] = ImVec4(0.92f, 0.18f, 0.29f, 1.00f);
	style.Colors[ImGuiCol_Header] = ImVec4(0.92f, 0.18f, 0.29f, 0.76f);
	style.Colors[ImGuiCol_HeaderHovered] = ImVec4(0.92f, 0.18f, 0.29f, 0.86f);
	style.Colors[ImGuiCol_HeaderActive] = ImVec4(0.92f, 0.18f, 0.29f, 1.00f);
	style.Colors[ImGuiCol_Column] = ImVec4(0.15f, 0.00f, 0.00f, 0.35f);
	style.Colors[ImGuiCol_ColumnHovered] = ImVec4(0.92f, 0.18f, 0.29f, 0.59f);
	style.Colors[ImGuiCol_ColumnActive] = ImVec4(0.92f, 0.18f, 0.29f, 1.00f);
	style.Colors[ImGuiCol_ResizeGrip] = ImVec4(0.92f, 0.18f, 0.29f, 0.63f);
	style.Colors[ImGuiCol_ResizeGripHovered] = ImVec4(0.92f, 0.18f, 0.29f, 0.78f);
	style.Colors[ImGuiCol_ResizeGripActive] = ImVec4(0.92f, 0.18f, 0.29f, 1.00f);
	style.Colors[ImGuiCol_CloseButton] = ImVec4(1.00f, 1.00f, 1.00f, 0.51f);
	style.Colors[ImGuiCol_CloseButtonHovered] = ImVec4(1.00f, 1.00f, 1.00f, 0.67f);
	style.Colors[ImGuiCol_CloseButtonActive] = ImVec4(1.00f, 1.00f, 1.00f, 0.78f);
	style.Colors[ImGuiCol_PlotLines] = ImVec4(0.86f, 0.93f, 0.89f, 0.63f);
	style.Colors[ImGuiCol_PlotLinesHovered] = ImVec4(0.92f, 0.18f, 0.29f, 1.00f);
	style.Colors[ImGuiCol_PlotHistogram] = ImVec4(0.86f, 0.93f, 0.89f, 0.63f);
	style.Colors[ImGuiCol_PlotHistogramHovered] = ImVec4(0.92f, 0.18f, 0.29f, 1.00f);
	style.Colors[ImGuiCol_TextSelectedBg] = ImVec4(0.92f, 0.18f, 0.29f, 0.43f);
	style.Colors[ImGuiCol_ModalWindowDarkening] = ImVec4(0.20f, 0.22f, 0.27f, 0.73f);
}

void CapColor(float &color) {
	if (color > 255.f)
		color = 255.f;
	if (color < 0.f)
		color = 0.f;
}

void DoGUI(LPDIRECT3DDEVICE9 g_pd3dDevice) {
	ImVec4 clear_color = ImVec4(0.45f, 0.55f, 0.60f, 1.00f);
	ImGui_ImplDX9_NewFrame();

	DWORD dwFlag = ImGuiWindowFlags_NoResize | ImGuiWindowFlags_NoSavedSettings | ImGuiWindowFlags_NoMove | ImGuiWindowFlags_NoCollapse | ImGuiWindowFlags_NoScrollbar | ImGuiWindowFlags_NoScrollWithMouse;

	std::this_thread::sleep_for(std::chrono::milliseconds(15)); //save the frames and the cpu usage lol

	static bool open = true;

	if (!open)
		ExitProcess(0);

	ImGui::GetIO().IniFilename = NULL;

	ImGuiStyle& style = ImGui::GetStyle();

	LoadTheme(style);

	if (flash) g_Variables::Visuals::FlashAlpha = 0.f;
	else g_Variables::Visuals::FlashAlpha = 255.f;

	ImGui::Begin("'AAAHBASE EXTERNAL'", &open, ImVec2(WINDOW_WIDTH, WINDOW_HEIGHT), 1.0f, dwFlag); {
		if (ImGui::Button("'VISUALS'"))
			g_Variables::SelectedTab = 0;
		ImGui::SameLine();
		if (ImGui::Button("'MISCELLANEOUS'"))
			g_Variables::SelectedTab = 1;
		ImGui::SameLine();
		if (ImGui::Button("'CONFIG'"))
			g_Variables::SelectedTab = 2;
		ImGui::SameLine();
		ImGui::Separator();
		ImGui::Separator();
		switch (g_Variables::SelectedTab) {
		case 0: // Visuals tab
			ImGui::Checkbox("'CHAMS'", &g_Variables::Visuals::Chams);
			ImGui::Checkbox("'NO FLASH'", &flash);
			ImGui::Separator();
			break;
		case 1: // Misc tab
			ImGui::Checkbox("'BUNNYHOP'", &g_Variables::Misc::Bhop);
			break;
		case 2: // Cfg tab
			if (ImGui::Button("'SAVE'"))
				SaveConfig();
			if (ImGui::Button("'LOAD'"))
				LoadConfig();
			break;
		}
		ImGui::Separator();
	}
	ImGui::End();

	g_pd3dDevice->SetRenderState(D3DRS_ZENABLE, false);
	g_pd3dDevice->SetRenderState(D3DRS_ALPHABLENDENABLE, false);
	g_pd3dDevice->SetRenderState(D3DRS_SCISSORTESTENABLE, false);
	if (g_pd3dDevice->BeginScene() >= 0) {
		ImGui::Render();
		g_pd3dDevice->EndScene();
	}
	g_pd3dDevice->Present(NULL, NULL, NULL, NULL);
}