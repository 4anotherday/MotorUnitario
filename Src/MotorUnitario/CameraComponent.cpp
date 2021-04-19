#include "CameraComponent.h"
#include "MotorGrafico/Camera.h"
#include "ComponentIDs.h"
#include "Transform.h"
#include "GameObject.h"

CameraComponent::CameraComponent() : Component(ComponentId::Camera), _camera(nullptr)
{
}

CameraComponent::CameraComponent(std::string const& route, int zOrder, GameObject* gameObject) : Component(ComponentId::Camera, gameObject), _camera(nullptr)
{
	_camera = new Camera(route, zOrder);
}

CameraComponent::CameraComponent(GameObject* gameObject) : Component(ComponentId::Camera, gameObject), _camera(nullptr)
{
	_camera = new Camera();
}

CameraComponent::~CameraComponent()
{
	delete _camera; _camera == nullptr;
}

void CameraComponent::start()
{
	_tr = static_cast<Transform*>(_gameObject->getComponent(ComponentId::Transform));
}

void CameraComponent::update()
{
	float x = static_cast<float>(_tr->getPosition().getX());
	float y = static_cast<float>(_tr->getPosition().getY());
	float z = static_cast<float>(_tr->getPosition().getZ());
	_camera->setPosition(x, y, z);
}

void CameraComponent::lateUpdate()
{
}

void CameraComponent::lookAt(float x, float y, float z)
{
	_camera->lookAt(x, y, z);
}

void CameraComponent::pitchDegrees(float degrees)
{
	_camera->pitchDegrees(degrees);
}

void CameraComponent::pitchRadians(float radians)
{
	_camera->pitchRadians(radians);
}

void CameraComponent::yawDegrees(float degrees)
{
	_camera->yawDegrees(degrees);
}

void CameraComponent::yawRadians(float radians)
{
	_camera->yawRadians(radians);
}

void CameraComponent::rollDegrees(float degrees)
{
	_camera->rollDegrees(degrees);
}

void CameraComponent::rollRadians(float radians)
{
	_camera->rollRadians(radians);
}

void CameraComponent::setOrientation(float w, float x, float y, float z)
{
	_camera->setOrientation(w, x, y, z);
}

void CameraComponent::setPosition(float x, float y, float z)
{
	_camera->setPosition(x, y, z);
}

void CameraComponent::translate(float x, float y, float z)
{
	_camera->translate(x, y, z);
}

void CameraComponent::setPlanes(float near, float far)
{
	_camera->setPlanes(near, far);
}

void CameraComponent::setProjection(bool ortho)
{
	_camera->setProjection(ortho);
}

void CameraComponent::setFovY(float fovy)
{
	_camera->setFovY(fovy);
}

void CameraComponent::setFrustrumDimensions(float left, float right, float top, float bot)
{
	_camera->setFrustrumDimensions(left, right, top, bot);
}

void CameraComponent::setOrthoWindowDimensions(float w, float h)
{
	_camera->setOrthoWindowDimensions(w, h);
}

void CameraComponent::setViewportDimensions(float left, float top, float w, float h)
{
	_camera->setViewportDimensions(left, top, w, h);
}