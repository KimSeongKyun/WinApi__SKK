#include "Menu.h"
#include <GameEngineCore/GameEngineRender.h>
#include <GameEnginePlatform/GameEngineWindow.h>
#include "ContentsEnums.h"


#include "Player.h"

Menu::Menu()
{
}

Menu::~Menu()
{
}

void Menu::Start()
{
	Menu1 = CreateRender(PoketMonRenderOrder::Menu);
	Menu1->SetImage("Menu.bmp");
	Menu1->SetScale(GameEngineWindow::GetScreenSize());
}

void Menu::Update(float _DeltaTime)
{
}
