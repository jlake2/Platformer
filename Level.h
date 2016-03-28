#include "Tile.h"
#include "Graphics.h"
#include <vector>

class Level{
	public:
		Level();
		void setLevel();
		void update();
		void addTile(int,int,int);
		void setGraphics(Graphics*gr){g=gr;}
		void updateTilesOnScreen();

		std::vector<Tile *> getTiles(){return tiles;}
		
	private: 
		std::vector<Tile*> tiles;
		//std::vector<Tile*> tilesOnScreen;
		Graphics *g;
};
