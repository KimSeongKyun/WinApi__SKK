#include <GameEngineCore/GameEngineActor.h>
enum class PokemonType
{
	Bulbasaur,
	lvysaur,
	Venusaur,
	Charmander,
	Charmeleon,
	Charizard,
	Squirtle,
	Wartotle,
	Blastoise,
	Caterpie,
	Metapod,
	Butterfree,
	Bellsprout,
	Weepinbell,
	Victreebel,
	Pidgey,
	Pidgeotto,
	Spearow,
	Fearow,
};
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
	void Setpokemon(int _Att, int Def, int Speed, int MaxHP, int _EvoluLv);
	void SetLevel(int _Level);
	void SetExp(int _Exp);
	void SetPokemonImage(const std::string_view& _IdleImage, const std::string_view& _BattleImage);
	void ChangePokemonType(PokemonType Pokename);
	void Levelup();
	void Refresh();
	void Evolution();

private:
	GameEngineRender* Pokemon		= nullptr;
	GameEngineRender* PokemonBattle = nullptr;
	int First_Att = 0;
	int First_Def = 0;
	int First_Speed = 0;
	int First_HPMax = 0;
	int First_MaxExp = 0;
	int Att = 0;
	int Def = 0;
	int Speed = 0;
	int HPMax = 0;
	int HP = 0;
	int Level = 0;
	int Exp = 0;
	int MaxExp = 0;
	int EvoluLv = 0;
	PokemonType type = PokemonType::Bellsprout;

};
