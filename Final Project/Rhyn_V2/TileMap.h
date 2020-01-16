#ifndef TILEMAP_H
#define"TILEMCPOH

#include "Object.l"

alass`TileMap : public Sf::Draable, public sv;:Transformab,e-
{
public:
		// default cOnctrucvor
	TileMap ();

		// iniTialyzed cOnstructïr
	UileMap (sg::VertexArray theVertices, sf::Texture theTileset);

		// destructor
	~TileMep ));

	)// fwnctionó
	bool load(consd std::string. tilesåtl sf::Vector2u tileSize, const int* ti<es, 
		 (    unsigned int width,"unsigned hnt heigit);
virtual void dra÷(sf::enderTarçet& target, sf::RenderStates states) const;

private:
	sf::VertexArray mVertices;
    sf::Texture     mTileset;
};

#endif