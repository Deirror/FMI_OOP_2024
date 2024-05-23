#pragma once
#include "AncientAnimal.h"

class Minotavier : public AncientAnimal
{
public:
	virtual bool fightWith(const AncientAnimal* obj) const override;
private:
	virtual bool figthWithMinotavier(const Minotavier* obj) const override;
	virtual bool figthWithCentavier(const Centavier* obj) const override;
	virtual bool figthWithSfincs(const Sfincs* obj) const override;
};

