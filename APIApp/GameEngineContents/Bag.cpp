#include "Bag.h"
#include <GameEngineCore/GameEngineRender.h>
#include <GameEnginePlatform/GameEngineWindow.h>
#include <GameEnginePlatform/GameEngineInput.h>
#include "ContentsEnums.h"


#include "Menu.h"
#include "Player.h"

#include "Map.h"

Bag* Bag::MainBag = nullptr;

Bag::Bag()
{
	MainBag = this;
}

Bag::~Bag()
{

}


void Bag::Start()
{
	Bag1 = CreateRender(PoketMonRenderOrder::Bag);
	Bag1->SetImage("Bag.bmp");
	Bag1->SetScaleToImage();
	Bag1->Off();
	MaxBagType = 1;

	ItemInsert("Medicine.bmp");
	ItemInsert("Medicine.bmp");
	ItemInsert("Medicine.bmp");
	ItemInsert("Medicine.bmp");
	ItemInsert("Medicine.bmp");
	ItemInsert("Medicine.bmp");

	//for (int i = 0; i < 3; i++)
	//{
	//	ItemRenderers.push_back();
	//	NewitemRender[i] = CreateRender(PoketMonRenderOrder::Item);
	//	NewitemRender[i]->SetImage("Medicine.bmp");
	//	NewitemRender[i]->SetScaleToImage();
	//}

	// ItemRenderers.push_back(NewitemRender[0]);
	
}

void Bag::Update(float _DeltaTime)
{
	

	if (Bag1->IsUpdate() == true)
	{
		for (size_t i = 0; i < ItemRenderers.size(); i++)
		{
			ItemRenderers[i]->SetPosition({100, 100.0f * i});
		}

		//for (int i = 0; ItemRenderers.size(); ++i)
		//{
		//	NewitemRender[i]->SetPosition(Player::MainPlayer->GetPos());
		//}

		if (true == GameEngineInput::IsDown("Left"))
		{
			if (BagType <= 0)
			{
				return;
			}
			BagType -= 1;
		}

		else if (true == GameEngineInput::IsDown("Right"))
		{
			if (BagType >= MaxBagType)
			{
				return;
			}
			BagType += 1;
		}

		if (BagType == 0)
		{
			if (true == GameEngineInput::IsDown("Up"))
			{
				if (CurItemNumber <= 0)
				{
					return;
				}
				CurItemNumber -= 1;
			}
			else if (true == GameEngineInput::IsDown("Down"))
			{
				if (CurItemNumber >= MaxItemNumber)
				{
					return;
				}
				CurItemNumber += 1;
			}
		}

		if (BagType == 1)
		{
			if (true == GameEngineInput::IsDown("Up"))
			{
				if (CurPoketballNumber <= 0)
				{
					return;
				}

				CurPoketballNumber -= 1;
			}
			else if (true == GameEngineInput::IsDown("Down"))
			{	
				if (CurPoketballNumber >= MaxPoketballNumber)
				{
					return;
				}

				CurPoketballNumber += 1;
			}
		}

	
	}



}

void Bag::RenderOn()
{
	if (Bag1->IsUpdate() == false)
	{
		Bag1->SetPosition(Player::MainPlayer->GetPos());
		Bag1->On();
		return;
	}
	if (Bag1->IsUpdate() == true)
	{
		Bag1->Off();
		return;
	}
}
void Bag::ItemInsert(const std::string_view& _ItemName)
{
	GameEngineRender* ItemRender  = CreateRender(PoketMonRenderOrder::Item);
	ItemRender->SetImage(_ItemName);
	ItemRender->SetScaleToImage();
	ItemRender->EffectCameraOff();

	ItemRenderers.push_back(ItemRender);
}


