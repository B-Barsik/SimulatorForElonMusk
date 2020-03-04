#include <SFML/Graphics.hpp>
#include <time.h>
#include <iostream>

using namespace sf;

class Surface {
protected:
	VertexArray surface;
	Vector2f center_position = { 0, 600 };
	float x_spacing = 10;
	size_t pixel_size;
	size_t vertex_count;
	Texture texture;
	String file = "surface.png";
	Image image;
public:
	Surface();
	void Draw(RenderWindow& window) const;
};