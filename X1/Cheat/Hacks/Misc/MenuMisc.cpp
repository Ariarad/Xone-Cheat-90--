#include "Misc.h"
#include "../../GUI/Gui.h"

#define SAME_LINE_1 168

#define PUSH_1 200
#define PUSH_2 360
#define PUSH_3 240

void CMisc::Menu()
{
	DCheckBox("Bhop", u8"", BHop, u8"");
	if (BHop)
	{
		X1Gui().SameLine(SAME_LINE_1);
		DCheckBox("Auto Strafe", u8"", AutoStrafe, u8"");
	}
	X1Gui().Spacing();
	X1Gui().Separator();
	X1Gui().Spacing();
	DCheckBox("Auto Accept", u8"", AutoAccept, u8"");

	X1Gui().Spacing();
	X1Gui().Separator();
	X1Gui().Spacing();

	DCheckBox("Spectator List", u8"", SpectatorList, u8"");
	if (SpectatorList)
	{
		X1Gui().SameLine(SAME_LINE_1);
		X1Gui().PushItemWidth(PUSH_1);
		SliderInts("Alpha##spec", u8"", SpectatorListAlpha, 0, 255, u8"");
		X1Gui().PushItemWidth(PUSH_2);
		SliderInts("Pos X##spec", u8"", SpectatorListPosX, 0, CGlobal::iScreenWidth, u8"");
		X1Gui().PushItemWidth(PUSH_2);
		SliderInts("Pos Y##spec", u8"", SpectatorListPosY, 0, CGlobal::iScreenHeight, u8"");
		DCheckBox("Auto Hide", u8"", SpectatorListAutoHide, u8"");
	}

	X1Gui().Spacing();
	X1Gui().Separator();
	X1Gui().Spacing();
	DCheckBox("Fov Changer", u8"", FovChanger, u8"");
	if (FovChanger)
	{
		X1Gui().SameLine(SAME_LINE_1);
		X1Gui().PushItemWidth(PUSH_1);
		SliderInts("Fov View", u8"", FovView, 1, 180, u8"");
	}
	X1Gui().Spacing();
	X1Gui().Separator();
	X1Gui().Spacing();
	DCheckBox("Fov Model Changer", u8"", FovModelChanger, u8"");
	if (FovModelChanger)
	{
		X1Gui().SameLine(SAME_LINE_1);
		X1Gui().PushItemWidth(PUSH_1);
		SliderInts("Fov Model", u8"", FovModel, 1, 180, u8"");
	}
	X1Gui().Spacing();
	X1Gui().Separator();
	X1Gui().Spacing();
	DCheckBox("No Visual Recoil", u8"", NoVisualRecoil, u8"");
	X1Gui().Spacing();
	X1Gui().Separator();
	X1Gui().Spacing();
	DCheckBox("FreeCam", u8"", FreeCam, u8"");
	if (FreeCam)
	{
		X1Gui().SameLine(SAME_LINE_1);
		X1Gui().PushItemWidth(PUSH_1);
		SliderInts("Speed##frecam", u8"", FreeCamSpeed, 1, 40, u8"");

		HotsKey("Button##frcam", u8"", FreeCamBind.Button, u8"");
		X1Gui().SameLine();
		DCheckBox("Hold##frcam", u8"", FreeCamBind.Hold, u8"");
	}

	X1Gui().Spacing();
	X1Gui().Separator();
	X1Gui().Spacing();

	DCheckBox("Crosshair", u8"", Crosshair, u8"");
	if (Crosshair)
	{
		X1Gui().SameLine(SAME_LINE_1);
		X1Gui().PushItemWidth(PUSH_1);
		VectorEx<const char* >itemsCSSEng = { lolc("Type1") , lolc("Type2"), lolc("Type3") };
		VectorEx<const char* >itemsCSSRus = { lolc(u8"���1") , lolc(u8""), lolc(u8"") };
		DComboBox("Style##Crossh", u8"", CrosshairStyle, itemsCSSEng, itemsCSSRus, "");

		X1Gui().PushItemWidth(PUSH_2);
		SliderInts("Size##Crossh", u8"", CrosshairSize, 1, 100, u8"");

		DCheckBox("Recoil##Crossh", u8"", CrosshairRecoil, u8"");
		X1Gui().SameLine(SAME_LINE_1);
		DCheckBox("Outline##Crossh", u8"", CrosshairOutline, u8"");

		DColorEdit("Color##Crossh", u8"", CrosshairColor);
	}

	X1Gui().Spacing();
	X1Gui().Separator();
	X1Gui().Spacing();

	DCheckBox("Sniper Crosshair", u8"", SnipCrosshair, u8"");
	if (SnipCrosshair)
	{
		if (MainSettings().Russian)
			X1Gui().SameLine(SAME_LINE_1 + 10);
		else
			X1Gui().SameLine(SAME_LINE_1);
		X1Gui().PushItemWidth(PUSH_1);
		VectorEx<const char* >itemsCSSEng = { lolc("Type1") , lolc("Type2"), lolc("Type3") };
		VectorEx<const char* >itemsCSSRus = { lolc(u8"") , lolc(u8""), lolc(u8"") };
		DComboBox("Style##Crosshsnip", u8"", SnipCrosshairStyle, itemsCSSEng, itemsCSSRus, "");

		X1Gui().PushItemWidth(PUSH_2);
		SliderInts("Size##Crosshsnip", u8"", SnipCrosshairSize, 1, 100, u8"");

		DCheckBox("Recoil##Crosshsnip", u8"", SnipCrosshairRecoil, u8"");
		X1Gui().SameLine(SAME_LINE_1);
		DCheckBox("Outline##Crosshsnip", u8"", SnipCrosshairOutline, u8"");

		DColorEdit("Color##Crosshsnip", u8"", SnipCrosshairColor);
	}

	X1Gui().Spacing();
	X1Gui().Separator();
	X1Gui().Spacing();
	DCheckBox("Spread Circle", u8"", SpreadCircel, u8"");
	if (SpreadCircel)
	{
		X1Gui().SameLine(SAME_LINE_1);
		DColorEdit("Color##spread", u8"", SpreadColor);
	}
	X1Gui().Spacing();
	X1Gui().Separator();
	X1Gui().Spacing();
	DCheckBox("Hit Marker", u8"", HitMarker, u8"");
	if (HitMarker)
	{
		X1Gui().SameLine(SAME_LINE_1);
		X1Gui().PushItemWidth(PUSH_3);
		SliderInts("Size##Hits", u8"", HitMarkerSize, 1, 10, u8"");
		X1Gui().PushItemWidth(PUSH_2);
		SliderInts("Tickness##Hits", u8"", HitMarkerTickness, 1, 100, u8"");
		DColorEdit("Color##Hits", u8"", HitMarkerColor);
	}
	/*X1Gui().Spacing();
	X1Gui().Separator();
	X1Gui().Spacing();
	DCheckBox("Hit Trace", u8"����� ���������", HitTrace, u8"�������� ����������� ���������� ���������");
	if (HitTrace)
	{
		X1Gui().SameLine(SAME_LINE_1);
		DColorEdit("Color##Hitstrr", u8"����##�����", HitTraceColor);
	}*/


	X1Gui().Spacing();
	X1Gui().Separator();
	X1Gui().Spacing();

	DCheckBox("Hit Sound", u8"", HitSound, u8"");
	if (HitSound)
	{
		if (!SoundList.empty())
		{
			X1Gui().SameLine(SAME_LINE_1);
			X1Gui().PushItemWidth(PUSH_1);
		
			VectorEx<const char*> itemsHSS;
			for (size_t i(0); i < SoundList.size(); i++)
			{
				itemsHSS.push_back(SoundList[i].c_str());
			}
			X1Gui().ComboBox(!MainSettings().Russian ? XorStr("Style##Hts") : XorStr(u8""), &HitSoundStyle, itemsHSS);		
		}
	}

	X1Gui().Spacing();
	X1Gui().Separator();
	X1Gui().Spacing();
	DCheckBox("AntiFlash", u8"", AntiFlash, u8"");
	if (AntiFlash)
	{
		X1Gui().SameLine(SAME_LINE_1);
		X1Gui().PushItemWidth(PUSH_3);
		SliderInts("Alpha##flash", u8"", AntiFlashAlpha, 1, 255, u8"");
	}
	X1Gui().Spacing();
	X1Gui().Separator();
	X1Gui().Spacing();
	DCheckBox("Clan Tag", u8"", ClanTagChanger, u8"");
	if (ClanTagChanger)
	{
		X1Gui().SameLine(SAME_LINE_1);
		X1Gui().PushItemWidth(PUSH_1);
		VectorEx<const char* >itemsCSEng = { lolc("DRE > All"),lolc("VALVE"), lolc("Animation1"), lolc("Animation2"), lolc("Custom") };
		VectorEx<const char* >itemsCSRus = { lolc("XONE > All"),lolc("VALVE"),lolc(u8""), lolc(u8""), lolc(u8"") };
		DComboBox("Style##clan", u8"", ClanTagChangerStyle, itemsCSEng, itemsCSRus, "");

		if (ClanTagChangerStyle == 4)
		{
			static char ClanBuf[64] = { 0 };
			TextEdit("Text##clan", u8"", ClanTagChangerText, ClanBuf, 64);
		}
	}
	X1Gui().Spacing();
	X1Gui().Separator();
	X1Gui().Spacing();
	DCheckBox("Chat Spam", u8"", ChatSpam, u8"");
	if (ChatSpam)
	{
		X1Gui().SameLine(SAME_LINE_1);
		X1Gui().PushItemWidth(PUSH_1);
		VectorEx<const char* >itemsCSEng = { lolc("Standart"), lolc("Custom") };
		VectorEx<const char* >itemsCSRus = { lolc(u8""), lolc(u8"") };
		DComboBox("Style##spam", u8"", ChatSpamStyle, itemsCSEng, itemsCSRus, "");
		if (ChatSpamStyle == 1)
		{
			static char ChatBuf[64] = { 0 };
			TextEdit("Text##spam", u8"", ChatSpamText, ChatBuf, 64);
		}
		if (X1Gui().Button(ChatSpamStart ? (true ? XorStr("Stop") : XorStr(u8"")) : (true ? XorStr("Start") : XorStr(u8""))))
			ChatSpamStart = !ChatSpamStart;

	}
	X1Gui().Spacing();
	X1Gui().Separator();
	X1Gui().Spacing();
	DCheckBox("LegitAA", u8"", LegitAA, u8"");
	X1Gui().Spacing();
	X1Gui().Separator();
	X1Gui().Spacing();
	DCheckBox("Hand Chams", u8"", HandChams, u8"");
	if (HandChams)
	{
		X1Gui().SameLine(SAME_LINE_1);
		X1Gui().PushItemWidth(PUSH_1);
		VectorEx<const char* >itemsCSEng = { lolc("Textured"),lolc("Flat"), lolc("Wireframe"), lolc("Disable") };
		VectorEx<const char* >itemsCSRus = { lolc(u8""),lolc(u8""), lolc(u8""), lolc(u8"") };
		DComboBox("Style##hand", u8"", HandChamsStyle, itemsCSEng, itemsCSRus, "");
		DColorEdit("Color##hand", u8"", HandChamsColor);
	}

	X1Gui().Spacing();
	X1Gui().Separator();
	X1Gui().Spacing();
	DCheckBox("Damage Info", u8"", DamageInfo, u8"");
	if (DamageInfo)
	{
		if (MainSettings().Russian)
			X1Gui().SameLine(SAME_LINE_1 + 15);
		else
			X1Gui().SameLine(SAME_LINE_1);
		X1Gui().PushItemWidth(PUSH_1);
		X1Gui().PushItemWidth(PUSH_1);
		VectorEx<const char* >itemsCSEng = { lolc("On Screen") , lolc("In World") };
		VectorEx<const char* >itemsCSRus = { lolc(u8""), lolc(u8"") };
		DComboBox("Position##damage", u8"", DamageInfoPosition, itemsCSEng, itemsCSRus, "");
		X1Gui().Spacing();
		if (MainSettings().Russian)
			X1Gui().SameLine(SAME_LINE_1 + 15);
		else
			X1Gui().SameLine(SAME_LINE_1);
		X1Gui().PushItemWidth(PUSH_1);
		X1Gui().PushItemWidth(PUSH_1);
		VectorEx<const char* >itemsDSSEng = { lolc("Damage") , lolc("Health") };
		VectorEx<const char* >itemsDSSRus = { lolc(u8""), lolc(u8"") };
		DComboBox("Style##damage", u8"", DamageInfoStyle, itemsDSSEng, itemsDSSRus, "");
		X1Gui().PushItemWidth(PUSH_2);
		SliderInts("Text Size##damage", u8"", TextDamageInfo, 9, MAX_FONT_SIZE, u8"");
		if (DamageInfoPosition == 0)
		{
			SliderFloats("Show Time", u8"", DamageInfoShowTime, 0.1, 10, "");
			SliderInts("Position X", u8"", DamageInfoPosX, 1, CGlobal::iScreenWidth, u8"");
			SliderInts("Position Y", u8"", DamageInfoPosY, 1, CGlobal::iScreenHeight, u8"");
		}
		else if (DamageInfoPosition == 1)
		{
			SliderInts("Height", u8"", DamageInfoHeight, 1, 100, u8"");
			SliderInts("Speed", u8"", DamageInfoSpeed, 1, 100, u8"");
		}
		DColorEdit("Color##damage", u8"", DamageInfoColor);
	}
	X1Gui().Spacing();
	X1Gui().Separator();
	X1Gui().Spacing();
	DCheckBox("Night Mode", u8"", NightMode, u8"");

	X1Gui().Spacing();
	X1Gui().Separator();
	X1Gui().Spacing();

	DCheckBox("Fake Lag", u8"", FakeLag, u8"");
	if (FakeLag)
	{
		X1Gui().SameLine(SAME_LINE_1);
		X1Gui().PushItemWidth(PUSH_1);
		SliderInts("Factor", u8"", FakeLagFactor, 1, 50, u8"");
		DCheckBox("Bind##fake", u8"", FakeLagBind.Enable, u8"");
		if (FakeLagBind.Enable)
		{
			X1Gui().SameLine(SAME_LINE_1);
			DCheckBox("Hold##fake", u8"", FakeLagBind.Hold, u8"");
			X1Gui().PushItemWidth(PUSH_2);
			HotsKey("Button##fake", u8"", FakeLagBind.Button, u8"");
		}
	}
	X1Gui().Spacing();
	X1Gui().Separator();
	X1Gui().Spacing();
	DCheckBox("Colored Walls", u8"", ColoredWalls, u8"");
	if (ColoredWalls)
	{
		X1Gui().SameLine(SAME_LINE_1);
		X1Gui().PushItemWidth(PUSH_1);
		/*	VectorEx<const char* >itemsCSEng = { lolc("Standart") , lolc("Textured"), lolc("Flat") };
			VectorEx<const char* >itemsCSRus = { lolc(u8"��������"),lolc(u8"����������"),lolc(u8"�������") };
			DComboBox("Style##clrwall", u8"�����##����", ColoredWallsStyle, itemsCSEng, itemsCSRus, u8"������� � ���������� �� ������������");
	*/
		DColorEdit("Color##clrwall", u8"", ColoredWallsColor);
	}
	X1Gui().Spacing();
	X1Gui().Separator();
	X1Gui().Spacing();
	DCheckBox("Knife Bot", u8"", KnifeBot, u8"");

	if (KnifeBot)
	{
		X1Gui().SameLine(SAME_LINE_1);
		X1Gui().PushItemWidth(PUSH_1);
		SliderInts("Distance##knfb", u8"", KnifeBotDistance, 1, 100, u8"");
		X1Gui().Spacing();
		X1Gui().SameLine(SAME_LINE_1);
		X1Gui().PushItemWidth(PUSH_1);
		VectorEx<const char* >itemsKNFEng = { lolc("All"), lolc("Team"), lolc("Enemy") };
		VectorEx<const char* >itemsKNFRus = { lolc(u8""), lolc(u8""), lolc(u8"") };
		DComboBox("Attack##knfb", u8"", KnifeBotFilter, itemsKNFEng, itemsKNFRus, "");
		X1Gui().PushItemWidth(PUSH_2);
		VectorEx<const char* >itemsKNFMEng = { lolc("Auto"), lolc("Left, Right"), lolc("Right"), lolc("Left") };
		VectorEx<const char* >itemsKNFMRus = { lolc("Auto"), lolc("Left, Right"), lolc("Right"), lolc("Left") };
		DComboBox("Mode##knfb", u8"", KnifeBotMode, itemsKNFMEng, itemsKNFMRus, "");

		DCheckBox("Bind##knfb", u8"", KnifeBotBind.Enable, u8"");
		if (KnifeBotBind.Enable)
		{
			X1Gui().SameLine(SAME_LINE_1);
			DCheckBox("Hold##knfb", u8"", KnifeBotBind.Hold, u8"");
			X1Gui().PushItemWidth(PUSH_2);
			HotsKey("Button##knfb", u8"", KnifeBotBind.Button, u8"");
		}
	}
}