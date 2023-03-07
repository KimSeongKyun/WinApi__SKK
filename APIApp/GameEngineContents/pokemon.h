#include <GameEngineCore/GameEngineActor.h>

class pokemon : public GameEngineActor
{
public:


	// constrcuter destructer
	pokemon();
	~pokemon();

	// delete Function
	pokemon(const pokemon& _Other) = delete;
	pokemon(pokemon&& _Other) noexcept = delete;
	pokemon& operator=(const pokemon& _Other) = delete;
	pokemon& operator=(pokemon&& _Other) noexcept = delete;




protected:
	void Start() override;
	void Update(float _DeltaTime) override;

public:
	void Setpokemon(int _Att, int Def, int Speed,int _MaxExp, int _EvoluLv);
	void SetLevel(int _Level);
	void SetExp(int _Exp);
	void SetPokemonImage(const std::string_view& _IdleImage, const std::string_view& _BattleImage);

private:
	GameEngineRender* Pokemon		= nullptr;
	GameEngineRender* PokemonBattle = nullptr;
	int Att = 0;
	int Def = 0;
	int Speed = 0;
	int HP = 0;
	int Level = 0;
	int Exp = 0;
	int MaxExp = 0;
	int EvoluLv = 0;

};
