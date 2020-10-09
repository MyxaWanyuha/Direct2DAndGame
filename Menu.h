#pragma once
#include "GameLevel.h"
class Menu : public GameLevel
{
private:
	virtual void Load() override;
	virtual void Unload() override;
	virtual void Render() override;
	virtual void Update(long long timeTotal, long long timeDelta) override;
};

