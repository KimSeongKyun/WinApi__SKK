#include "BattleLevel.h"
#include <GameEngineBase/GameEngineDirectory.h>
#include <GameEngineCore/GameEngineResources.h>



BattleLevel::BattleLevel()
{
}

BattleLevel::~BattleLevel()
{
}

void BattleLevel::SoundLoading()
{
}

void BattleLevel::Loading()
{
	GameEngineDirectory Dir;
	Dir.MoveParentToDirectory("ContentsResources");
	Dir.Move("ContentsResources");
	Dir.Move("Image");
	Dir.Move("Battle");


	GameEngineImage* Battle1 = GameEngineResources::GetInst().ImageLoad(Dir.GetPlusFileName("Battle1.BMP"));
	GameEngineImage* Battle2 = GameEngineResources::GetInst().ImageLoad(Dir.GetPlusFileName("Battle2.BMP"));
}

void BattleLevel::Update(float _DeltaTime)
{
}

void BattleLevel::LevelChangeStart(GameEngineLevel* _PrevLevel)
{
}
