#include <SFML/Graphics.hpp>
#include <vector>
#include <string>
#include <iostream>
#include "Personnages.h"
#include "Window.h"

int main()
{
	Personnage persoprincipal("tiles/principal1.png");
	Window window(persoprincipal);

	for (auto last_five_seconds = int(window.elapsed());
		window.step(); )
	{
		const auto second = int(window.elapsed());
		if (second >= last_five_seconds + 5)
		{
			std::cout << second << " seconds elapsed\n";
			last_five_seconds = second;
		}
	}

	

	return 0;
}
