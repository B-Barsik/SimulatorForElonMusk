#pragma once
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>

using namespace sf;

class Object {
protected:
	Vector2f position;
	float height, width, angle;
	bool exist = true;

	String file;
	Image image;
	Texture texture;
	Sprite sprite;

	SoundBuffer buffer;
	Sound sound;
public:
	Object() : height(0), width(0), angle(0) {}
	Object(const String& f, const Vector2f new_position,
		const float& w, const float& h, const float& start_angle); //����� � �����!!!

	bool Exist() const;
	Vector2f GetPosition() const;
	float GetHeight() const;
	float GetWidth() const;
	float GetAngle() const;

	void SetHeight(const float& new_height);
	void SetWidth(const float& new_width);

	void SetPosition(const Vector2f& new_position, const float& new_angle);
	void Draw(RenderWindow& window) const;
	void Rotate(const float& new_angle);
};