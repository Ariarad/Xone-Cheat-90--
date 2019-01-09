#include "Radar.h"
#include"../../GUI/Gui.h"

void CRadar::Menu()
{

	VectorEx<const char*> RadTraceStyleEng = { lolc("Line"), lolc("Fov"),lolc("Fov + Line") };
	VectorEx<const char*> RadTraceStyleRus = { lolc(u8"�����"),lolc(u8"���"), lolc(u8"��� + �����") };

	VectorEx<const char*> PointStyleEng = { lolc("Filled Box"), lolc("Box"),lolc("Filled Circle"),lolc("Circle"),lolc("None") };
	VectorEx<const char*> PointStyleRus = { lolc(u8"������� ����"),lolc(u8"����"), lolc(u8"������� ����"),lolc(u8"����"),lolc("None") };


	/*ColorEdit("ColorCT", u8"ColorCT", ColorCT);
	ColorEdit("ColorTT", u8"ColorCT", ColorTT);

	ColorEdit("ColorVisbleCT", u8"ColorVisbleCT", ColorVisbleCT);
	ColorEdit("ColorVisbleTT", u8"ColorVisbleTT", ColorVisbleTT);


	ColorEdit("ColorBackground", u8"ColorBackground", ColorBackground);

	ColorEdit("ColorLine", u8"ColorLine", ColorLine);

	ColorEdit("NameColor", u8"NameColor", NameColor);
*/

	X1Gui().PushItemWidth(360);

	DCheckBox("Radar In Game", u8"������������� �����", RadarInGame, u8"���������� ������� �� ������������� ������");
	X1Gui().Spacing();
	X1Gui().Separator();
	X1Gui().Spacing();
	DCheckBox("Radar", u8"�����", RadarActive, u8"���������� ����� ����");
	if (RadarActive)
	{
		X1Gui().SameLine();
		DCheckBox("With Map", u8"� ������", TexturedRadar, u8"���������� ����� �� ������ ����");
	}
	X1Gui().Spacing();
	X1Gui().Separator();
	X1Gui().Spacing();
	if (RadarActive)
	{
		DCheckBox("Enemy", u8"�����", Enemy, u8"���������� ������ �� ������ ����");

		X1Gui().SameLine();
		DCheckBox("Team", u8"�������", Team, u8"���������� ������� �� ������ ����");

		X1Gui().Spacing();
		X1Gui().Separator();
		X1Gui().Spacing();

		DColorEdit("Color CT", u8"���� ��", ColorCT);
		X1Gui().SameLine();
		DColorEdit("Visble Color CT", u8"������� ���� ��", ColorVisbleCT);


		DColorEdit("Color T", u8"���� �", ColorTT);
		X1Gui().SameLine();
		DColorEdit("Visble Color T", u8"������� ���� �", ColorVisbleTT);

		X1Gui().Spacing();
		X1Gui().Separator();
		X1Gui().Spacing();
		SliderInts("Zoom", u8"�����������", Range, 1, 4000, u8"");
		X1Gui().Spacing();

		SliderInts("Position X", u8"������� �� X", RadarPosX, 1, CGlobal::iScreenWidth, u8"");
		SliderInts("Position Y", u8"������� �� Y", RadarPosY, 1, CGlobal::iScreenHeight, u8"");


		X1Gui().Spacing();

		SliderInts("Size X", u8"������ �� X", RadarSizeX, 1, 900, u8"");
		SliderInts("Size Y", u8"������ �� Y", RadarSizeY, 1, 900, u8"");


		X1Gui().Spacing();

		SliderInts("Alpha", u8"������������", Alpha, 1, 255, u8"");

		X1Gui().Spacing();
		X1Gui().Separator();
		X1Gui().Spacing();

		DCheckBox("Fov", u8"���", Fov, u8"�������� ��� �� ������ ����");

		X1Gui().SameLine();
		DCheckBox("Line", u8"�����", Line, u8"�������� ����� �� ������ ����");
		X1Gui().SameLine();
		DCheckBox("OutLine", u8"�������", OutLine, u8"�������� ������� ������ ����");
		X1Gui().SameLine();
		DCheckBox("Only In Radar", u8"������  �� ������", OnlyInRadar, u8"���������� ������� ������ � ���� ����");
		X1Gui().Spacing();
		X1Gui().Separator();
		X1Gui().Spacing();

		DColorEdit("Color Background", u8"���� ����", ColorBackground);
		DColorEdit("Color Line", u8"���� �����", ColorLine);

		X1Gui().Spacing();
		X1Gui().Separator();
		X1Gui().Spacing();

		SliderInts("Size##point", u8"������##���", PointSize, 2, 50, u8"������ ����� �������");
		DComboBox("Style##point", u8"�����##���", PointStyle, PointStyleEng, PointStyleRus, "����� ����� �������");
		X1Gui().Spacing();
		X1Gui().Separator();
		X1Gui().Spacing();

		DCheckBox("Sound", u8"����", Sound, u8"���������� ���� �� ������ ����");
		if (Sound)
		{
			SliderInts("Size##soud", u8"������##��", SoundPointSize, 2, 50, u8"������ ����� �����");
			DComboBox("Style##soud", u8"�����##��", SoundPointStyle, PointStyleEng, PointStyleRus, "����� ����� �����");
			DColorEdit("Color##soud", u8"����##��", SoundColor);
		}

		X1Gui().Spacing();
		X1Gui().Separator();
		X1Gui().Spacing();

		DCheckBox("Trace", u8"����������� �������", Trace, u8"���������� ����������� �������� ������� �� ������ ����");

		if (Trace)
		{
			SliderInts("Lenght##trace", u8"�����##��", TraceLenght, 2, 300, u8"����� ����������� �������");
			DComboBox("Style##trace", u8"�����##��", TraceStyle, RadTraceStyleEng, RadTraceStyleRus, "����� ����������� �������");
		}

		X1Gui().Spacing();
		X1Gui().Separator();
		X1Gui().Spacing();

		DCheckBox("Name", u8"�����", Name, u8"���������� ����� ������� �� ������ ����");
		if (Name)
		{
			SliderInts("Text Size##name", u8"������ ������##��", TextNameSize, 9, MAX_FONT_SIZE, u8"");

			DColorEdit("Color##name", u8"����##��", NameColor);
		}

	}
}