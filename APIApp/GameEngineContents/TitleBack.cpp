#include "TitleBack.h"
#include "ContentsEnums.h"
#include <GameEngineCore/GameEngineRender.h>
#include <GameEnginePlatform/GameEngineWindow.h>

TitleBack::TitleBack() 
{
}

TitleBack::~TitleBack() 
{
}


void TitleBack::Start()
{
	float4 Size = GameEngineWindow::GetScreenSize();
	float4 Anipos = { 400, 450 };


	GameEngineRender* Render = CreateRender("backgroud_title.bmp", PoketMonRenderOrder::BackGround);
	Render->SetPosition(GameEngineWindow::GetScreenSize().half());
	Render->SetScale(GameEngineWindow::GetScreenSize());
	GameEngineRender* Render1 = CreateRender("title_ani1.bmp", PoketMonRenderOrder::BackGround);
	Render1->SetPosition(Anipos);
	Render1->SetScale({330, 250});
	Render1->CreateAnimation({ .AnimationName = "title_ani",  .ImageName = "title_ani1.bmp", .Start = 0, .End = 4, .InterTime = 0.18f });
	Render1->ChangeAnimation("title_ani");
}