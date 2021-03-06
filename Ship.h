#pragma once
#include "RigidBody.h"
#include "Engine.h"
#include <cmath>

class Ship : public RigidBody {
protected:
	bool isDestroyed = false;
	std::map<std::string, Engine> engines;
	float fuel;
public:
	Ship(const String& f, const RigidBodyParameters& parameters);

	float GetFuel() const; 
	void SetFuel(const float& new_fuel); 

	void AddMainForces(float gravity);

	void AddEngine(const Engine& new_engine, const std::string& name);
	void EngineOn(const std::string& name);
	void EngineOff(const std::string& name);
	void SetEngineThrust(const std::string& name, float new_thrust);
	void SetEngineThrustAngle(const std::string& name, float new_thrust_angle);

	void UpdateEngines(const std::string& name);
	void UpdateShipPosition(const float& dt);
	void UpdateEnginesPosition(const std::string& name, const sf::Vector2f& new_position);

	virtual void DrawShip(RenderWindow& window) const;
	void Destroy();
	void draw_all(RenderWindow& window, bool position, bool speed, bool way, bool forces, bool collision);

	virtual RigidBodyParameters download(sf::Vector2f position) = 0;
	virtual void assembly() = 0;
	virtual void control() = 0;

	void updateAirForce(float k);
};