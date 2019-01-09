#include  "Gui.h"
#include "../Hacks/Setup.h"
#include "../Hacks/Settings.h"

#define WINDOW1_SIZE_X 160
#define WINDOW1_SIZE_Y 325

#define WINDOW2_SIZE_X 470
#define WINDOW2_SIZE_Y 665

#define LABEL_WIN_SPEED_DELTA  310.f
#define LABEL_WIN_SPEED  0.006079f

#define MAIN_WIN_SPEED_DELTA  330.f
#define MAIN_WIN_SPEED  0.006239f

#define PREW_WIN_SPEED_DELTA  360.f
#define PREW_WIN_SPEED  0.006279f

class CMenu
{
private:
	int SelectedTab = -1;

	void SettingsMenu()
	{
		static int SelectedSettings = 0;

		VectorEx<const char*>tabs_eng = { ("Config"), ("Menu") };
		VectorEx<const char*>tabs_rus = { (u8"������"),(u8"����") };

		TabsLabels(SelectedSettings, tabs_eng, tabs_rus, Vec2(X1Gui().GetCurWindowSize().x - (X1Gui().GetStyle().wndPadding.x * 2), 0), false);

		X1Gui().Spacing();
		X1Gui().Separator();
		X1Gui().Spacing();

		if (SelectedSettings == 0)
		{
			CGSettings::G().Menu();
			MainSettings().SetMenuColors();
		}
		else if (SelectedSettings == 1)
		{
			HotsKey("Open Menu Button", u8"������ �������� ����", MainSettings().MenuButton, u8"������ ������ �������� ����");
			X1Gui().Spacing();
			X1Gui().Separator();
			X1Gui().Spacing();
			DCheckBox("Menu Animation", u8"�������� ����", X1Gui().GetStyle().AnimationEnable, "");
			X1Gui().Spacing();
			X1Gui().Separator();
			X1Gui().Spacing();
			X1Gui().CheckBox(u8"������� ����", &MainSettings().Russian);
			X1Gui().Spacing();
			X1Gui().Separator();
			X1Gui().Spacing();
			DCheckBox(u8"Watermark", u8"�������", MainSettings().Watermark, u8"");
			X1Gui().Spacing();
			X1Gui().Separator();
			X1Gui().Spacing();
			DCheckBox(u8"3D Menu", u8"3� ����", GP_Enable3DMenu->Enable, u8"");
			if (GP_Enable3DMenu->Enable)
			{
				X1Gui().SameLine();
				X1Gui().PushItemWidth(200);
				HotsKey("Button##3dm", u8"������##3��", GP_Enable3DMenu->Button, u8"");
			}
			X1Gui().Spacing();
			X1Gui().Separator();
			X1Gui().Spacing(); 
			DColorEdit("Color Background", u8"���� ����", MainSettings().BackgroundColor);
			DColorEdit("Color Title", u8"���� ���� ���������", MainSettings().TitleColor);
			DColorEdit("Color Text", u8"���� ������", MainSettings().TextColor);
			DColorEdit("Color Frame", u8"���� ������", MainSettings().FrameColor);
			DColorEdit("Color Button", u8"���� ������", MainSettings().ButtonColor);
			X1Gui().SameLine();
			DColorEdit("Color DisableButton", u8"���� ����������� ������", MainSettings().DisableButtonColor);
			DColorEdit("Color Line", u8"���� �����", MainSettings().LineColor);
			X1Gui().Spacing();
			X1Gui().Separator();
			X1Gui().Spacing();
			if (X1Gui().Button(!MainSettings().Russian ? XorStr("Reset Color") : XorStr(u8"�������� �����")))
			{
				MainSettings().BackgroundColor = Color(18, 18, 22, 255);
				MainSettings().TitleColor = Color(112, 112, 116, 255);
				MainSettings().TextColor = Color(255, 255, 255, 255);
				MainSettings().FrameColor = Color(34, 35, 37, 255);
				MainSettings().ButtonColor = Color(128, 135, 140, 255);
				MainSettings().DisableButtonColor = Color(225, 0, 0, 255);
				MainSettings().LineColor = Color(120, 121, 123, 255);
			}

			MainSettings().SetMenuColors();
		}
	}

public:

	int ChangerMode = 0;

	void Changers()
	{
		vector<string> Kostil_eng = { lolc("Skins"), lolc("Inventory") };
		vector<string> Kostil_rus = { lolc(u8"�����"),lolc(u8"���������") };
		VectorEx<const char*> ChaArrEng = { Kostil_eng[0].c_str(),Kostil_eng[1].c_str() };
		VectorEx<const char*> ChaArrRus = { Kostil_rus[0].c_str(),Kostil_rus[1].c_str() };

		TabsLabels(ChangerMode, ChaArrEng, ChaArrRus, Vec2(328, 20), false);

		X1Gui().SameLine(331);

		if (ChangerMode == 0)
		{
			if (X1Gui().Button(GP_Skins->ShowSkinPreview ? XorStr("Preview <<<") : XorStr("Preview >>>"), Vec2(129, 20)))
				GP_Skins->ShowSkinPreview = !GP_Skins->ShowSkinPreview;
		}
		else if (ChangerMode == 1)
		{
			if (X1Gui().Button(GP_Inventory->ShowInventoryList ? XorStr("Inv. list <<<") : XorStr("Inv. list >>>"), Vec2(129, 20)))
				GP_Inventory->ShowInventoryList = !GP_Inventory->ShowInventoryList;
		}

		X1Gui().Spacing();
		X1Gui().Separator();
		X1Gui().Spacing();

		if (ChangerMode == 0)
		{
			DCheckBox("Enable Skins", u8"��������� ������", GP_Skins->SkinsEnable, u8"");
		}
		else if (ChangerMode == 1)
		{
			DCheckBox("Synchronization Inventory", u8"������������� ���������", GP_Inventory->SkinsSyncEnable, u8"");
		}

		X1Gui().Spacing();
		X1Gui().Separator();
		X1Gui().Spacing();

		if (ChangerMode == 0)
		{
			GP_Skins->Menu();
		}
		else if (ChangerMode == 1)
		{
			GP_Inventory->Menu();
		}
	}

	void SelectWindow()
	{
		string name = MainSettings().UserName;
		string end_data = MainSettings().EndDate;
		string days = MainSettings().Days;
#ifdef MULTIHACK_VERSION
		VectorEx<const char*>tabs_eng = { "Aimbot", "Visuals", "Misc",  "Radar", "Grenade Helper", "Changers", "Settings" };
		VectorEx<const char*>tabs_rus = { u8"������", u8"�������",u8"�������������",  u8"�����", "Grenade Helper", u8"�������", u8"���������" };
#else
		VectorEx<const char*>tabs_eng = {"Visuals", "Misc",  "Radar", "Grenade Helper", "Changers", "Settings" };
		VectorEx<const char*>tabs_rus = { u8"�������",u8"�������������",  u8"�����", "Grenade Helper", u8"�������", u8"���������" };
#endif 
		TabsLabels(SelectedTab, tabs_eng, tabs_rus, Vec2(X1Gui().GetCurWindowSize().x - (X1Gui().GetStyle().wndPadding.x * 2), 220), true);
		X1Gui().Spacing();

		X1Gui().SameLine(5);
		X1Gui().Text(XorStr("Name:"));

		X1Gui().Spacing();

		X1Gui().SameLine(5);
		X1Gui().Text(name.c_str());

		X1Gui().Spacing();
		X1Gui().Separator();
		X1Gui().Spacing();

		if (end_data == XorStr("LifeTime"))
		{
			X1Gui().SameLine(5);
			X1Gui().Text(XorStr(""));
			X1Gui().Spacing();
			X1Gui().SameLine(5);
			X1Gui().Text(end_data.c_str());
		}
		else
		{
			X1Gui().SameLine(5);
			X1Gui().Text("Enjoy");
			X1Gui().Spacing();
			X1Gui().SameLine(5);
			X1Gui().Text(end_data.c_str());
		}	
	}

	void DrawCurTab(int tab)
	{
		switch (tab)
		{
#ifdef MULTIHACK_VERSION
			case 0: if (GP_LegitAim) GP_LegitAim->Menu(); break;
			case 1: if (GP_Esp) GP_Esp->Menu(); break;
			case 2: if (GP_Misc) GP_Misc->Menu(); break;
			case 3: if (GP_Radar) GP_Radar->Menu(); break;
			case 4: if (GP_GHelper) { GP_GHelper->Menu(); } break;
			case 5: Changers(); break;
			case 6: SettingsMenu(); break;
#else
			case 0: if (GP_Esp) GP_Esp->Menu(); break;
			case 1: if (GP_Misc) GP_Misc->Menu(); break;
			case 2: if (GP_Radar) GP_Radar->Menu(); break;
			case 3: if (GP_GHelper) { GP_GHelper->Menu(); } break;
			case 4: Changers(); break;
			case 5: SettingsMenu(); break;
#endif
			default: break;
		}
	}

	CAnimController AnimLabelsWin;
	CAnimController AnimMainWin;
	CAnimController AnimPrewWin;

	Vec2 LabelWinSize;
	Vec2 MainWinSize;
	Vec2 PrewWinSize;

	bool LabelWinEnd = false;
	bool MainWinEnd = false;
	bool PrewWinEnd = false;

	DWORD next_time_close = 0;

	void Draw(CFont *MenuFont)
	{
		auto LDraw = [&]()->void
		{
			auto ResetAnim = [&](bool reset)->void
			{
				AnimLabelsWin.Reset();
				AnimMainWin.Reset();
				AnimPrewWin.Reset();
				LabelWinEnd = reset;
				MainWinEnd = reset;
				PrewWinEnd = reset;
			};

			X1Gui().SetFont(MenuFont);

			bool AnimEnable = X1Gui().GetStyle().AnimationEnable;
			bool GuiEnable = CGlobal::IsGuiVisble;
				
		
			if (AnimEnable)
			{
				if (GuiEnable)
				{
					AnimLabelsWin.Update(true, LABEL_WIN_SPEED, LABEL_WIN_SPEED_DELTA);
					LabelWinSize = Vec2(WINDOW1_SIZE_X, 25 + AnimLabelsWin.Get(WINDOW1_SIZE_Y - 25));
					LabelWinEnd = AnimLabelsWin.IsEnd();
				}
				else
				{
					LabelWinSize = Vec2(WINDOW1_SIZE_X, 25);
					ResetAnim(false);
				}
			}
			else
			{
				LabelWinSize = Vec2(WINDOW1_SIZE_X, WINDOW1_SIZE_Y);
				ResetAnim(true);
			}


			//X1Gui().GetStyle().Alpha = 100;

			if (GuiEnable)
			{
				X1Gui().GetStyle().ScrollEnable = LabelWinEnd && MainWinEnd;

				MainSettings().HintMsg = "";

				Vec2 oldWinPadding = X1Gui().GetStyle().wndPadding;
				X1Gui().GetStyle().wndPadding = Vec2(2, 1);

				if (X1Gui().Begin(CHEAT_HEAD, GWF_Window, LabelWinSize, Vec2(500, 50)))
				{
					SelectWindow();

					next_time_close = GetTickCount64() + 15000;
				}
				X1Gui().End();

				X1Gui().GetStyle().wndPadding = oldWinPadding;

				if (LabelWinEnd && SelectedTab != -1)
				{
					if (AnimEnable)
					{
						AnimMainWin.Update(true, MAIN_WIN_SPEED, MAIN_WIN_SPEED_DELTA);
						MainWinSize = Vec2(WINDOW2_SIZE_X, AnimMainWin.Get(WINDOW2_SIZE_Y));
						MainWinEnd = AnimMainWin.IsEnd();
					}
					else
					{
						MainWinSize = Vec2(WINDOW2_SIZE_X, WINDOW2_SIZE_Y);
					}

					Vec2 LabelWinPos = X1Gui().GetPrevWindowPos();
					X1Gui().SetNextWindowPos(Vec2(LabelWinPos.x + WINDOW1_SIZE_X + 4, LabelWinPos.y));

					if (X1Gui().Begin(XorStr("Main"), GWF_NoTitleBar, MainWinSize, Vec2(600, 400)))
					{
						DrawCurTab(SelectedTab);
					}
					X1Gui().End();

					if (MainWinEnd)
					{
						Vec2 MainWinPos = X1Gui().GetPrevWindowPos();
#ifdef MULTIHACK_VERSION
#define VIS_TAB 1
#define LAIM_TAB 0
#define SKIN_TAB 5
#else
#define VIS_TAB 0
#define LAIM_TAB 999
#define SKIN_TAB 4
#endif 

						bool IsVisualsTab = SelectedTab == VIS_TAB && GP_Esp->ShowPreview;
						bool IsLegitAimTab = SelectedTab == LAIM_TAB && GP_LegitAim->ShowWeaponList;
						bool IsSkinsTab = SelectedTab == SKIN_TAB && ChangerMode == 0 && GP_Skins->ShowSkinPreview;
						bool IsInventTab = SelectedTab == SKIN_TAB && ChangerMode == 1 && GP_Inventory->ShowInventoryList;

						static Vec2 TargetSize = Vec2(100,100);
						static Vec2 CurSize = Vec2(100, 100);

						if (IsVisualsTab)
							TargetSize = Vec2(350 + (X1Gui().GetStyle().wndPadding.x * 2) + 1, WINDOW2_SIZE_Y);
						else if (IsSkinsTab)
							TargetSize = Vec2(320, 248);
						else if (IsInventTab)
							TargetSize = Vec2(365, WINDOW2_SIZE_Y);
						else if (IsLegitAimTab)
						{
							if(GP_LegitAim->WeaponCustomTypes == 0)
								TargetSize = Vec2(160, WINDOW2_SIZE_Y);
							else if(GP_LegitAim->WeaponCustomTypes == 1)
								TargetSize = Vec2(160, 135);
							else if (GP_LegitAim->WeaponCustomTypes == 2)
								TargetSize = Vec2(463, WINDOW2_SIZE_Y);
						}

									
						static bool ShowPrewWin = false;
						bool EnablePrewWin = IsVisualsTab || IsLegitAimTab || IsSkinsTab || IsInventTab;

						if (AnimEnable)
						{
							AnimPrewWin.Update(EnablePrewWin, PREW_WIN_SPEED, PREW_WIN_SPEED_DELTA);
							CurSize.x = AnimPrewWin.Get(TargetSize.x);
							CurSize.y = TargetSize.y;
							ShowPrewWin = !AnimPrewWin.IsStart();
						}
						else
						{
							CurSize = TargetSize;
							ShowPrewWin = EnablePrewWin;
						}

						if (ShowPrewWin)
						{
							if (AnimEnable)
								X1Gui().SetNextWindowPos(Vec2(MainWinPos.x + WINDOW2_SIZE_X + AnimPrewWin.Get(4), MainWinPos.y));
							else
								X1Gui().SetNextWindowPos(Vec2(MainWinPos.x + WINDOW2_SIZE_X + 4, MainWinPos.y));

							if (X1Gui().Begin(XorStr("prew"), GWF_NoTitleBar, CurSize, Vec2(1, 1)))
							{
								if (SelectedTab == LAIM_TAB && GP_LegitAim->WeaponCustomTypes != 3 && GP_LegitAim->ShowWeaponList)
									if (GP_LegitAim)
										GP_LegitAim->SubsectionsMenu();

								if (SelectedTab == VIS_TAB)
									if (GP_Esp)
										GP_Esp->VisualPreview();

								if (SelectedTab == SKIN_TAB)
								{
									if (ChangerMode == 0)
										GP_Skins->Preview();
									else if (ChangerMode == 1)
										GP_Inventory->InvListMenu();
								}
							}
							X1Gui().End();
						}

						if (MainSettings().HintMsg != "")
						{
							int HintSizeY = X1Gui().CalcTextSize(MainSettings().HintMsg).y + 9;
							X1Gui().SetNextWindowPos(Vec2(MainWinPos.x, MainWinPos.y - HintSizeY - 4));
							if (X1Gui().Begin(XorStr("Hint"), GWF_NoTitleBar, Vec2(WINDOW2_SIZE_X, HintSizeY), Vec2(1, 1)))
							{
								//X1Gui().Text(MainSettings().HintMsg.c_str());
							}
							X1Gui().End();
						}
					}
				}
			}	
			else
			{
				if(SelectedTab != -1 && next_time_close <= GetTickCount64())
					SelectedTab = -1;
			}	
		};
		LDraw();
	}
};