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
	if (Level == EvoluLv)
	{
		Evolution();
	}
}

void pokemon::Setpokemon(int _Att, int _Def, int _Speed, int _MaxHP, int _EvoluLv)
{
	First_Att = _Att;
	First_Def = _Def;
	First_Speed = _Speed;
	First_HPMax = _MaxHP;
	EvoluLv = _EvoluLv;
}
void pokemon::SetLevel(int _Level)
{
	Level = _Level;
}
void pokemon::SetExp(int _Exp)
{
	Exp += _Exp;
	if (Exp >= MaxExp)
	{
		Levelup();
		Exp = 0;
	}
}


void pokemon::SetPokemonImage(const std::string_view& _idleImage , const std::string_view& _battleImage)
{
	Pokemon->ChangeAnimation(_idleImage);
	PokemonBattle->ChangeAnimation(_battleImage);
}

void pokemon::ChangePokemonType(PokemonType Pokename)
{
	type = Pokename;

	switch (Pokename)
	{
	case PokemonType::Bulbasaur:
		SetPokemonImage("Bulbasaur", "Bulbasaur_Battle");
		Setpokemon(49, 49, 45, 45,  16);	
		break;
	case PokemonType::lvysaur:
		SetPokemonImage("lvysaur", "lvysaur_Battle");
		Setpokemon(62, 63, 60, 60,  32);
		
		break;
	case PokemonType::Venusaur:
		SetPokemonImage("Venusaur", "Venusaur_Battle");
		Setpokemon(82, 83, 80, 80,  100);
		
		break;
	case PokemonType::Charmander:
		SetPokemonImage("Charmander", "Charmander_Battle");
		Setpokemon(52, 43, 65, 39,  16);
		
		break;
	case PokemonType::Charmeleon:
		SetPokemonImage("Charmeleon", "Charmeleon_Battle");
		Setpokemon(64, 58, 80, 59,  36);
	
		break;
	case PokemonType::Charizard:
		SetPokemonImage("Charizard", "Charizard_Battle");
		Setpokemon(84, 78, 100, 78,  100);
		
		break;
	case PokemonType::Squirtle:
		SetPokemonImage("Squirtle", "Squirtle_Battle");
		Setpokemon(48, 65, 43, 44,  100);
		
		break;
	case PokemonType::Wartotle:
		SetPokemonImage("Wartotle", "Wartotle_Battle");
		Setpokemon(63, 80, 58, 59,  36);
		
		break;
	case PokemonType::Blastoise:
		SetPokemonImage("Blastoise", "Blastoise_Battle");
		Setpokemon(83, 100, 78, 79,  100);
		
		break;
	case PokemonType::Caterpie:
		SetPokemonImage("Caterpie", "Caterpie_Battle");
		Setpokemon(30, 35, 45, 45,  7);
		
		break;
	case PokemonType::Metapod:
		SetPokemonImage("Metapod", "Metapod_Battle");
		Setpokemon(20, 55, 30, 50,  10);
		
		break;
	case PokemonType::Butterfree:
		SetPokemonImage("Butterfree", "Butterfree_Battle");
		Setpokemon(45, 50, 70, 60,  100);
		
		break;
	case PokemonType::Bellsprout:
		SetPokemonImage("Bellsprout", "Bellsprout_Battle");
		Setpokemon(75, 35, 40, 50,  21);
		
		break;
	case PokemonType::Weepinbell:
		SetPokemonImage("Weepinbell", "Weepinbell_Battle");
		Setpokemon(90, 50, 55, 65,  40);
	
		break;
	case PokemonType::Victreebel:
		SetPokemonImage("Victreebel", "Victreebel_Battle");
		Setpokemon(105, 65, 70, 80,  100);
		
		break;
	case PokemonType::Pidgey:
		SetPokemonImage("Pidgey", "Pidgey_Battle");
		Setpokemon(45, 40, 56, 40,  18);
		
		break;
	case PokemonType::Pidgeotto:
		SetPokemonImage("Pidgeotto", "Pidgeotto_Battle");
		Setpokemon(60, 55, 71, 63,  100);
		
		break;
	case PokemonType::Spearow:
		SetPokemonImage("Spearow", "Spearow_Battle");
		Setpokemon(60, 30, 70, 40,  20);
		
		break;
	case PokemonType::Fearow:
		SetPokemonImage("Fearow", "Fearow_Battle");
		Setpokemon(90, 65, 100, 65,  100);
		
		break;
	default:
		break;
	}
}

void pokemon::Levelup()
{
	++Level;
	Refresh();
}

void pokemon::Refresh()
{
	HPMax = First_HPMax * Level;
	Att = First_Att * Level;
	Def = First_Def * Level;
	Speed = First_Speed * Level;
	MaxExp = First_MaxExp * Level;

}

void pokemon::Evolution()
{
	switch (type)
	{
	case PokemonType::Bulbasaur:
		ChangePokemonType(PokemonType::lvysaur);
		Refresh();
		break;
	case PokemonType::lvysaur:
		ChangePokemonType(PokemonType::Venusaur);
		Refresh();
		break;

	case PokemonType::Charmander:
		ChangePokemonType(PokemonType::Charmander);
		Refresh();
		break;
	case PokemonType::Charmeleon:
		ChangePokemonType(PokemonType::Charizard);
		Refresh();
		break;

	case PokemonType::Squirtle:
		ChangePokemonType(PokemonType::Wartotle);
		Refresh();
		break;
	case PokemonType::Wartotle:
		ChangePokemonType(PokemonType::Blastoise);
		Refresh();
		break;

	case PokemonType::Caterpie:
		ChangePokemonType(PokemonType::Metapod);
		Refresh();
		break;
	case PokemonType::Metapod:
		ChangePokemonType(PokemonType::Butterfree);
		Refresh();
		break;

	case PokemonType::Bellsprout:
		ChangePokemonType(PokemonType::Weepinbell);
		Refresh();
		break;
	case PokemonType::Weepinbell:
		ChangePokemonType(PokemonType::Victreebel);
		Refresh();
		break;

	case PokemonType::Pidgey:
		ChangePokemonType(PokemonType::Pidgeotto);
		Refresh();
		break;

	case PokemonType::Spearow:
		ChangePokemonType(PokemonType::Fearow);
		Refresh();
		break;

	default:
		break;
	}
}


