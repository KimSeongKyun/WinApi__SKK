#pragma once

enum class PoketMonRenderOrder
{
	BackGround,
	Map,
	Player,
	Monster,
};

enum class PoketMonCollisionOrder
{
	Player,
	Monster,
	PlayerAttack,
	MonsterAttack,
};