
#include "icommand.h"

class CMakeFish : public ICommand
{
public:
	void Execute() override;
};

class CMakeBBQ : public ICommand
{
public:
	void Execute() override;
};

class CMakeDesert : public ICommand
{
public:
	void Execute() override;
};
