#pragma once

enum class PoketMonRenderOrder
{
	BackGround,
	Map,
	Player,
	Monster,
	Menu
};

enum class PoketMonCollisionOrder
{
	Player,
	Monster,
	PlayerAttack,
	MonsterAttack,
};