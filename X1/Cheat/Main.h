#pragma once
#include "Include/Headers.h"
#include "Include/Def.h"
#include "Engine/SDK/Color.hpp"
char* GetClientDll();


class CMain
{
public:
	//CConfig Config = CConfig("MainCheatConfig");

	SDK::Color BackgroundColor = SDK::Color(18, 18, 22, 255);
	SDK::Color TitleColor = SDK::Color(112, 112, 116, 255);
	SDK::Color TextColor = SDK::Color(255, 255, 255, 255);
	SDK::Color FrameColor = SDK::Color(34, 35, 37, 255);
	SDK::Color ButtonColor = SDK::Color(128, 135, 140, 255);
	SDK::Color DisableButtonColor = SDK::Color(225, 20, 20, 255);
	SDK::Color LineColor = SDK::Color(120, 121, 123, 255);

	string UserName = "";
	string key = "";
	string id = "";
	string EndDate = "";
	string Days = "";
	string Buf = "";

	bool Russian = false;
	bool Watermark = true;
	int MenuButton = VK_INSERT;

	string HintMsg = "";

	void SetMenuColors();

	static CMain& Singleton()
	{
		static CMain pObject;
		return pObject;
	}
	void Initialize()
	{
		//RV(Russian, "RusLanguage");
		////RV(MenuAnimation, "MenuAnimation");
		//RV(Watermark, "Watermark");
		////RV(BackupSettings, "BackupSettings");
		//RV(MenuButton, "MenuButton");
		////RV(MenuAlpha, "MenuAlpha");
		////RV(AutoLoadEnable, "AutoLoadEnable");
		//RV(BackgroundColor, "BackgroundColor");
		//RV(TitleColor, "TitleColor");
		//RV(TextColor, "TextColor");
		//RV(FrameColor, "FrameColor");
		//RV(ButtonColor, "ButtonColor");
		//RV(DisableButtonColor, "DisableButtonColor");
		//RV(LineColor, "LineColor");
	}
};


CMain& MainSettings();
