#include "pokemon.h"
#include "ContentsEnums.h"
#include <GameEngineCore/GameEngineRender.h>

pokemon::pokemon()
{
}

pokemon::~pokemon()
{
}

void pokemon::Start()
{
	Pokemon = CreateRender(PoketMonRenderOrder::Pokemon);
	Pokemon->CreateAnimation({ .AnimationName = "Bulbasaur",  .ImageName = "PokeMonIdle.bmp", .Start = 0, .End = 0 });
	Pokemon->CreateAnimation({ .AnimationName = "lvysaur",  .ImageName = "PokeMonIdle.bmp", .Start = 1, .End = 1 });
	Pokemon->CreateAnimation({ .AnimationName = "Venusaur",  .ImageName = "PokeMonIdle.bmp", .Start = 2, .End = 2 });
	Pokemon->CreateAnimation({ .AnimationName = "Charmander",  .ImageName = "PokeMonIdle.bmp", .Start = 3, .End = 3 });
	Pokemon->CreateAnimation({ .AnimationName = "Charmeleon",  .ImageName = "PokeMonIdle.bmp", .Start = 4, .End = 4 });
	Pokemon->CreateAnimation({ .AnimationName = "Charizard",  .ImageName = "PokeMonIdle.bmp", .Start = 5, .End = 5 });
	Pokemon->CreateAnimation({ .AnimationName = "Squirtle",  .ImageName = "PokeMonIdle.bmp", .Start = 6, .End = 6 });
	Pokemon->CreateAnimation({ .AnimationName = "Wartotle",  .ImageName = "PokeMonIdle.bmp", .Start = 7, .End = 7 });
	Pokemon->CreateAnimation({ .AnimationName = "Blastoise",  .ImageName = "PokeMonIdle.bmp", .Start = 8, .End = 8 });
	Pokemon->CreateAnimation({ .AnimationName = "Caterpie",  .ImageName = "PokeMonIdle.bmp", .Start = 9, .End = 9 });
	Pokemon->CreateAnimation({ .AnimationName = "Metapod",  .ImageName = "PokeMonIdle.bmp", .Start = 10, .End = 10 });
	Pokemon->CreateAnimation({ .AnimationName = "Butterfree",  .ImageName = "PokeMonIdle.bmp", .Start = 11, .End = 11 });
	Pokemon->CreateAnimation({ .AnimationName = "Bellsprout",  .ImageName = "PokeMonIdle.bmp", .Start = 12, .End = 12 });
	Pokemon->CreateAnimation({ .AnimationName = "Weepinbell",  .ImageName = "PokeMonIdle.bmp", .Start = 13, .End = 13 });
	Pokemon->CreateAnimation({ .AnimationName = "Victreebel",  .ImageName = "PokeMonIdle.bmp", .Start = 14, .End = 14 });
	Pokemon->CreateAnimation({ .AnimationName = "Pidgey",  .ImageName = "PokeMonIdle.bmp", .Start = 15, .End = 15 });
	Pokemon->CreateAnimation({ .AnimationName = "Pidgeotto",  .ImageName = "PokeMonIdle.bmp", .Start = 16, .End = 16 });
	Pokemon->CreateAnimation({ .AnimationName = "Spearow",  .ImageName = "PokeMonIdle.bmp", .Start = 17, .End = 17 });
	Pokemon->CreateAnimation({ .AnimationName = "Fearow",  .ImageName = "PokeMonIdle.bmp", .Start = 18, .End = 18 });
	Pokemon->ChangeAnimation("Bulbasaur");
	Pokemon->SetScaleToImage();
	PokemonBattle = CreateRender(PoketMonRenderOrder::Pokemon);
	PokemonBattle->CreateAnimation({ .AnimationName = "Bulbasaur_Battle",  .ImageName = "PokeMonBattle.bmp", .Start = 0, .End = 0 });
	PokemonBattle->CreateAnimation({ .AnimationName = "lvysaur_Battle",  .ImageName = "PokeMonBattle.bmp", .Start = 1, .End = 1 });
	PokemonBattle->CreateAnimation({ .AnimationName = "Venusaur_Battle",  .ImageName = "PokeMonBattle.bmp", .Start = 2, .End = 2 });
	PokemonBattle->CreateAnimation({ .AnimationName = "Charmander_Battle",  .ImageName = "PokeMonBattle.bmp", .Start = 3, .End = 3 });
	PokemonBattle->CreateAnimation({ .AnimationName = "Charmeleon_Battle",  .ImageName = "PokeMonBattle.bmp", .Start = 4, .End = 4 });
	PokemonBattle->CreateAnimation({ .AnimationName = "Charizard_Battle",  .ImageName = "PokeMonBattle.bmp", .Start = 5, .End = 5 });
	PokemonBattle->CreateAnimation({ .AnimationName = "Squirtle_Battle",  .ImageName = "PokeMonBattle.bmp", .Start = 6, .End = 6 });
	PokemonBattle->CreateAnimation({ .AnimationName = "Wartotle_Battle",  .ImageName = "PokeMonBattle.bmp", .Start = 7, .End = 7 });
	PokemonBattle->CreateAnimation({ .AnimationName = "Blastoise_Battle",  .ImageName = "PokeMonBattle.bmp", .Start = 8, .End = 8 });
	PokemonBattle->CreateAnimation({ .AnimationName = "Caterpie_Battle",  .ImageName = "PokeMonBattle.bmp", .Start = 9, .End = 9 });
	PokemonBattle->CreateAnimation({ .AnimationName = "Metapod_Battle",  .ImageName = "PokeMonBattle.bmp", .Start = 10, .End = 10 });
	PokemonBattle->CreateAnimation({ .AnimationName = "Butterfree_Battle",  .ImageName = "PokeMonBattle.bmp", .Start = 11, .End = 11 });
	PokemonBattle->CreateAnimation({ .AnimationName = "Bellsprout_Battle",  .ImageName = "PokeMonBattle.bmp", .Start = 12, .End = 12 });
	PokemonBattle->CreateAnimation({ .AnimationName = "Weepinbell_Battle",  .ImageName = "PokeMonBattle.bmp", .Start = 13, .End = 13 });
	PokemonBattle->CreateAnimation({ .AnimationName = "Victreebel_Battle",  .ImageName = "PokeMonBattle.bmp", .Start = 14, .End = 14 });
	PokemonBattle->CreateAnimation({ .AnimationName = "Pidgey_Battle",  .ImageName = "PokeMonBattle.bmp", .Start = 15, .End = 15 });
	PokemonBattle->CreateAnimation({ .AnimationName = "Pidgeotto_Battle",  .ImageName = "PokeMonBattle.bmp", .Start = 16, .End = 16 });
	PokemonBattle->CreateAnimation({ .AnimationName = "Spearow_Battle",  .ImageName = "PokeMonBattle.bmp", .Start = 17, .End = 17 });
	PokemonBattle->CreateAnimation({ .AnimationName = "Fearow_Battle",  .ImageName = "PokeMonBattle.bmp", .Start = 18, .End = 18 });
	PokemonBattle->ChangeAnimation("Bulbasaur_Battle");
	PokemonBattle->SetScaleToImage();
}

void pokemon::Update(float _DeltaTime)
{
}

void pokemon::Setpokemon(int _Att, int _Def, int _Speed, int _MaxExp, int _EvoluLv)
{
	Att = _Att * Level;
	Def = _Def * Level;
	Speed = _Speed * Level;
	MaxExp = Level * MaxExp;
	EvoluLv = _EvoluLv;
	

}
void pokemon::SetLevel(int _Level)
{
	int Level = _Level;
}
void pokemon::SetExp(int _Exp)
{
	Exp += _Exp;
	if (Exp >= MaxExp)
	{
		++Level;
		Exp = 0;
		MaxExp += MaxExp;
	}
}


void pokemon::SetPokemonImage(const std::string_view& _idleImage , const std::string_view& _battleImage)
{
	Pokemon->ChangeAnimation(_idleImage);
	PokemonBattle->ChangeAnimation(_battleImage);
}


