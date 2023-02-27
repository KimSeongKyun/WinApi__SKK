#include "Menu.h"
#include <GameEngineCore/GameEngineRender.h>
#include <GameEnginePlatform/GameEngineWindow.h>
#include <GameEnginePlatform/GameEngineInput.h>
#include "ContentsEnums.h"


#include "Player.h"
#include "Bag.h"

Menu* Menu::MainMenu;

Menu::Menu()
{
	MainMenu = this;
}

Menu::~Menu()
{
}



void Menu::Start()
{
	// 이미지 로딩
	Menu1 = CreateRender(PoketMonRenderOrder::Menu);
	Menu1->SetImage("Menu.bmp");
	Menu1->SetScale(GameEngineWindow::GetScreenSize());
	Menu1->Off();
	Button1 = CreateRender(PoketMonRenderOrder::Menu);
	Button1->SetImage("Button.bmp");
	Button1->SetScaleToImage();
	Button1->Off();

	// 키 생성
	GameEngineInput::CreateKey("Up", 'W');
	GameEngineInput::CreateKey("Down", 'S');
	GameEngineInput::CreateKey("Left", 'A');
	GameEngineInput::CreateKey("Right", 'D');
	GameEngineInput::CreateKey("Ok", 'J');
	GameEngineInput::CreateKey("Cancel", 'K');

	
}


void Menu::Update(float _DeltaTime)
{
	if (Menu1->IsUpdate() == true)
	{
		if (true == GameEngineInput::IsDown("Up"))
		{
			if (MenuNumber <= MinNumber)
			{
				return;
			}
			float4 Pos = Button1->GetPosition() + length * float4::Up;
			Button1->SetPosition(Pos);
			MenuNumber -= 1;
		}

		else if (true == GameEngineInput::IsDown("Down"))
		{
			if (MenuNumber >= MaxNumber)
			{
				return;
			}
			float4 Pos = Button1->GetPosition() - length * float4::Up;
			Button1->SetPosition(Pos);
			MenuNumber += 1;
		}

		else if (true == GameEngineInput::IsDown("Left"))
		{
			float4 Pos = Button1->GetPosition() - width * float4::Up;
			Button1->SetPosition(Pos);
		}

		else if (true == GameEngineInput::IsDown("Right"))
		{
			float4 Pos = Button1->GetPosition() + width * float4::Up;
			Button1->SetPosition(Pos);
		}
		
		else if (true == GameEngineInput::IsDown("Ok"))
		{
			MenuSelect(static_cast<PoketMonMenu>(MenuNumber));
		}

		else if (true == GameEngineInput::IsDown("Cancel"))
		{
			float4 Pos = Button1->GetPosition() + width * float4::Up;
			Button1->SetPosition(Pos);
		}
	}
}

void Menu::RenderOn()
{
	if(Menu1->IsUpdate() == false)
	{
		Menu1->SetPosition(Player::MainPlayer->GetPos());
		Menu1->On();
		float4 ButtonLoca = { -135.0f ,270.0f };
		Button1->SetPosition(Player::MainPlayer->GetPos() - ButtonLoca);
		Button1->On();
		MaxNumber = 4;
		return;
	}
	if (Menu1->IsUpdate() == true)
	{
		Menu1->Off();
		Button1->Off();
		MenuNumber = 0;
		MaxNumber = 0;
		return;
	}
}

void Menu::MenuSelect(PoketMonMenu _Menu)
{
	switch (_Menu)
	{
	case PoketMonMenu::Bag:
		Bag::MainBag->RenderOn();
		Menu1->Off();
		Button1->Off();
		break;
	case PoketMonMenu::Player:
		break;
	case PoketMonMenu::Report:
		break;
	case PoketMonMenu::Option:
		break;
	case PoketMonMenu::Close:
		RenderOn();
		break;
	default:
		break;
	}
}


