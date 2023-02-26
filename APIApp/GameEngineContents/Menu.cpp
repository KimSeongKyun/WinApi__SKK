#include "Menu.h"
#include <GameEngineCore/GameEngineRender.h>
#include <GameEnginePlatform/GameEngineWindow.h>
#include <GameEnginePlatform/GameEngineInput.h>
#include "ContentsEnums.h"


#include "Player.h"

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
	// �̹��� �ε�
	Menu1 = CreateRender(PoketMonRenderOrder::Menu);
	Menu1->SetImage("Menu.bmp");
	Menu1->SetScale(GameEngineWindow::GetScreenSize());
	Menu1->Off();
	Button1 = CreateRender(PoketMonRenderOrder::Menu);
	Button1->SetImage("Button.bmp");
	Button1->SetScaleToImage();
	Button1->Off();
	Bag1 = CreateRender(PoketMonRenderOrder::Menu);
	Bag1->SetImage("Bag.bmp");
	Bag1->SetScaleToImage();
	Bag1->Off();

	// Ű ����
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
			if (MenuNumber <= 0)
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
		Menu1->Off();
		Button1->Off();
		Bag1->SetPosition(Player::MainPlayer->GetPos());
		Bag1->On();
		break;
	case PoketMonMenu::Player:
		break;
	case PoketMonMenu::Report:
		break;
	case PoketMonMenu::Option:
		break;
	case PoketMonMenu::Close:
		break;
	default:
		break;
	}
}


