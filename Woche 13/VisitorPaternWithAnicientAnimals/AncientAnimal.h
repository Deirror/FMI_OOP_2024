#pragma once

class Minotavier;
class Centavier;
class Sfincs;

class AncientAnimal
{
public:
	virtual bool fightWith(const AncientAnimal* obj) const = 0;

	virtual bool figthWithMinotavier(const Minotavier* obj) const = 0;
	virtual bool figthWithCentavier(const Centavier* obj) const  = 0;
	virtual bool figthWithSfincs(const Sfincs* obj) const = 0;

	virtual ~AncientAnimal() = default;
};

