#pragma once
#include <GameEngineCore/GameEngineActor.h>


enum class PoketMonMenu
{
	Bag,
	Player,
	Report,
	Option,
	Close
};

class Menu : public GameEngineActor
{
public:
	static Menu* MainMenu;


public:
	// constrcuter destructer
	Menu();
	~Menu();

	// delete Function
	Menu(const Menu& _Other) = delete;
	Menu(Menu&& _Other) noexcept = delete;
	Menu& operator=(const Menu& _Other) = delete;
	Menu& operator=(Menu&& _Other) noexcept = delete;

public:
	void RenderOn();
	void MenuSelect(PoketMonMenu _Menu);

protected:
	void Start() override;
	void Update(float _DeltaTime) override;

private:
	GameEngineRender* Menu1 = nullptr; 
	GameEngineRender* Button1 = nullptr;
	GameEngineRender* Bag1 = nullptr;
	bool MenuOpen = false;
	float4 length = { 0.0f, 80.0f };
	float4	width = { 75.0f, 0.0f };
	int MenuNumber = 0;
	int MaxNumber = 0;
};