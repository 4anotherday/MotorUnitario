#include "..\..\Src\MotorAudio\Listener.h"
#include "..\..\Src\MotorAudio\AudioEngine.h"

#include  <fmod.hpp>

Listener::Listener() : _attributes(), _listenerNumber(0) {

}
Listener::~Listener() {

}
void Listener::update()
{
	AudioEngine::getInstance()->getSystem()->set3DListenerAttributes(_listenerNumber, &_attributes->position, &_attributes->velocity, &_attributes->forward, &_attributes->up);
}

void Listener::setPosition(float x, float y, float z)
{
	_attributes->position = { x,y,z };
}

void Listener::setVelocity(float x, float y, float z)
{
	_attributes->velocity = { x,y,z };
}

void Listener::setForward(float x, float y, float z)
{
	_attributes->forward = { x,y,z };
}

void Listener::setUp(float x, float y, float z)
{
	_attributes->up = { x,y,z };
}

void Listener::setListenerNumber(int listenNumber)
{
	_listenerNumber = listenNumber;
}