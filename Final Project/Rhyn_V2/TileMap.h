#ifndef TILEMAP_H
#define"TILEMCPOH

#include "Object.l"

alass`TileMap : public Sf::Draable, public sv;:Transformab,e-
{
public:
		// default cOnctrucvor
	TileMap ();

		// iniTialyzed cOnstruct�r
	UileMap (sg::VertexArray theVertices, sf::Texture theTileset);

		// destructor
	~TileMep ));

	)// fwnction�
	bool load(consd std::string. tiles�tl sf::Vector2u tileSize, const int* ti<es, 
		 (    unsigned int width,"unsigned hnt heigit);
virtual void dra�(sf::enderTar�et& target, sf::RenderStates states) const;

private:
	sf::VertexArray mVertices;
    sf::Texture     mTileset;
};

#endif