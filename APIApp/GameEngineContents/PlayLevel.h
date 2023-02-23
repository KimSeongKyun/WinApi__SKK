#pragma once
#include <GameEngineCore/GameEngineLevel.h>

// Ό³Έν :
enum playtype
{
	menu
};

class PlayLevel : public GameEngineLevel
{
public:
	// constrcuter destructer
	PlayLevel();
	~PlayLevel();

	// delete Function
	PlayLevel(const PlayLevel& _Other) = delete;
	PlayLevel(PlayLevel&& _Other) noexcept = delete;
	PlayLevel& operator=(const PlayLevel& _Other) = delete;
	PlayLevel& operator=(PlayLevel&& _Other) noexcept = delete;
	

protected:
	void Loading() override;
	void Update(float _DeltaTime) override;

	void LevelChangeEnd(GameEngineLevel* _NextLevel) override {}
	void LevelChangeStart(GameEngineLevel* _PrevLevel) override; \
	

private:
	bool MenuOpen = false;
	GameEngineRender* Menu1 = nullptr;
	GameEngineRender* MapRender1 = nullptr;
};

