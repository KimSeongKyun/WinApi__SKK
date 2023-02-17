#pragma once
#include <GameEngineCore/GameEngineCore.h>

// �̷��� Ŭ������ ����� ��� ����ü�� �̱����̶�� �մϴ�.

// ���� :
class PoketMonGoldCore : public GameEngineCore
{
public:
	// delete Function
	PoketMonGoldCore(const PoketMonGoldCore& _Other) = delete;
	PoketMonGoldCore(PoketMonGoldCore&& _Other) noexcept = delete;
	PoketMonGoldCore& operator=(const PoketMonGoldCore& _Other) = delete;
	PoketMonGoldCore& operator=(PoketMonGoldCore&& _Other) noexcept = delete;

	// �̱���
	static PoketMonGoldCore& GetInst()
	{
		return Core;
	}

	// �����ͷ� ����ÿ��� �߰��� ������ �����ϴٴ� ������ �ִ�.
	//static StudyGameCore& Destroy()
	//{
	//	delete Core;
	//}

protected:
	void Start() override;
	void Update() override;
	void End() override;


private:
	// �����ڸ� ����.
	// constrcuter destructer
	PoketMonGoldCore();
	~PoketMonGoldCore();

	// �ڱ⸦ �ڽ��� ������
	// ���α׷��� ��Ʋ� ���� 1���� ��ü�� ���������
	// static StudyGameCore* Core;
	static PoketMonGoldCore Core;

};

