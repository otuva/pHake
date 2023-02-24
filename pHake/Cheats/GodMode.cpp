#include "../pLib/pUi/pOverlay.hpp"
#include "../SDK/World.hpp"

#include "GodMode.hpp"


GodMode::GodMode(std::shared_ptr<pOverlay> ui, std::shared_ptr<World> world, std::shared_ptr<Settings> settings)
{
	this->ui = ui;
	this->world = world;
	active = &settings->godmode;

	name_ = "GodMode";
	thread_intervals_ = 100;
}

void GodMode::Execute()
{
	if (*active)
	{
		if (!world->localplayer.god())
			world->localplayer.god(1);

		if (!world->localplayer.vehicle.god())
			world->localplayer.vehicle.god(1);
	}
	else
	{
		if (world->localplayer.god())
			world->localplayer.god(0);
		

		if (world->localplayer.vehicle.god())
			world->localplayer.vehicle.god(0);
	}
}

void GodMode::Restore()
{
	if (world->localplayer.god())
		world->localplayer.god(false);
}