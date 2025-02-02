#pragma once

#ifndef RIGIDBODY_H
#define RIGIDBODY_H

#include <list>
#include <tuple>
#include <string>
#include "CollisionBody.h"

class GameObject;

#define TUPLE_TO_PHYSXVEC3(tuple) physx::PxVec3(std::get<0>(tuple), std::get<1>(tuple), std::get<2>(tuple))
#define PHYSXVEC3_TO_TUPLE(vec) std::tuple<float,float,float>(vec.x,vec.y,vec.z)

namespace physx {
	class PxPhysics;
	class PxRigidBody;
	class PxRigidDynamic;
	class PxRigidStatic;
	class PxShape;
	class PxPhysicsAPI;
	class PxTransform;
	class PxMaterial;
	class PxScene;
	class PxQuat;
	class PxVec3;
};

class RigidBody : public CollisionBody
{
public:
	/// <summary>
	/// creates a dynamic spherical rigidBody
	/// </summary>
	/// <param name="radious">The radious of the sphere</param>
	/// <param name="gameObject">Pointer to the GameObject owning the component, used for collision callbacks</param>
	/// <param name="collisionCallback">Pointer to the function called on collision</param>
	/// <param name="isStatic">Set true if a static rigid body needed; false if dynamic rigid body needed</param>
	/// <param name="position">The object initial position</param>
	/// <param name="isKinematic">Set true if a kinematic rigid body needed</param>
	/// <param name="linearDamping">The linear damping of the body</param>
	/// <param name="angularDamping">The angular damping  of the body</param>
	/// <param name="staticFriction">The static friction, between 0 and 3.4 e 38.
	/// Static friction defines the amount of friction that is applied between surfaces that are not moving lateral to each-other</param>
	/// <param name="dynamicFriction">The dynamic friction, between 0 and 3.4 e 38.
	/// Dynamic friction defines the amount of friction applied between surfaces that are moving relative to each-other</param>
	/// <param name="restitution">The bounciness, between 0 and 1</param>
	/// <param name="mass">The mass of the sphere</param>
	RigidBody(float radious, GameObject* gameObject, const std::string& gameObjectName, ContactCallback* collisionCallback, bool isStatic = false, const std::tuple<float, float, float>& position = std::tuple<float, float, float>(0, 0, 0),
		bool isKinematic = false, float linearDamping = 0, float angularDamping = 0, float staticFriction = 1.0f,
		float dynamicFriction = 1.0f, float restitution = 1.0f, float mass = 1000.0f);

	/// <summary>
	/// creates a dynamic box rigidBody
	/// </summary>
	/// <param name="width">The width of the box</param>
	/// <param name="height">The height of the box</param>
	/// <param name="depth">The depth of the box</param>
	/// <param name="gameObject">Pointer to the GameObject owning the component, used for collision callbacks</param>
	/// <param name="collisionCallback">Pointer to the function called on collision</param>
	/// <param name="isStatic">Set true if a static rigid body needed; false if dynamic rigid body needed</param>
	/// <param name="position">The object initial position</param>
	/// <param name="isKinematic">Set true if a kinematic rigid body needed</param>
	/// <param name="linearDamping">The linear damping of the body</param>
	/// <param name="angularDamping">The angular damping  of the body</param>
	/// <param name="staticFriction">The static friction, between 0 and 3.4 e 38.
	/// Static friction defines the amount of friction that is applied between surfaces that are not moving lateral to each-other</param>
	/// <param name="dynamicFriction">The dynamic friction, between 0 and 3.4 e 38.
	/// Dynamic friction defines the amount of friction applied between surfaces that are moving relative to each-other</param>
	/// <param name="restitution">The bounciness, between 0 and 1</param>
	/// <param name="mass">The mass of the sphere</param>
	RigidBody(float width, float height, float depth, GameObject* gameObject, const std::string& gameObjectName, ContactCallback* collisionCallback, bool isStatic = false,
		const std::tuple<float, float, float>& position = std::tuple<float, float, float>(0, 0, 0), bool isKinematic = false,
		float linearDamping = 0, float angularDamping = 0, float staticFriction = 1.0f, float dynamicFriction = 1.0f,
		float restitution = 1.0f, float mass = 1000.0f);

	/// <summary>
	/// creates a dynamic capsule rigidBody
	/// </summary>
	/// <param name="radious">The radious of the capsule</param>
	/// <param name="height">The height of the capsule</param>
	/// <param name="gameObject">Pointer to the GameObject owning the component, used for collision callbacks</param>
	/// <param name="collisionCallback">Pointer to the function called on collision</param>
	/// <param name="isStatic">Set true if a static rigid body needed; false if dynamic rigid body needed</param>
	/// <param name="position">The object initial position</param>
	/// <param name="isKinematic">Set true if a kinematic rigid body needed</param>
	/// <param name="staticFriction">The static friction, between 0 and 3.4 e 38.
	/// Static friction defines the amount of friction that is applied between surfaces that are not moving lateral to each-other</param>
	/// <param name="dynamicFriction">The dynamic friction, between 0 and 3.4 e 38.
	/// Dynamic friction defines the amount of friction applied between surfaces that are moving relative to each-other</param>
	/// <param name="restitution">The bounciness, between 0 and 1</param>
	/// <param name="mass">The mass of the sphere</param>
	RigidBody(float radious, float height, GameObject* gameObject, const std::string& gameObjectName, ContactCallback* collisionCallback, bool isStatic = false,
		const std::tuple<float, float, float>& position = std::tuple<float, float, float>(0, 0, 0), bool isKinematic = false, float linearDamping = 0,
		float AngularDamping = 0, float staticFriction = 1.0f, float dynamicFriction = 1.0f, float restitution = 1.0f, float mass = 1000.0f);

	~RigidBody();

	void enable();

	void disable();

	/// <summary>
	/// Adds a force if it's a dynamic rigid body
	/// </summary>
	/// <param name="force">The force to add</param>
	bool addForce(std::tuple<float, float, float>& force);

	/// <summary>
	/// Adds an impulse if it's a dynamic rigid body
	/// </summary>
	/// <param name="impulse">The impulse to add</param>
	bool addImpulse(std::tuple<float, float, float>& impulse);

	/// <summary>
	/// Adds a torque if it's a dynamic rigid body
	/// </summary>
	/// <param name="torque">The torque to add</param>
	/// <returns>The new rotation of the object and if it's valid</returns>
	bool  addTorque(const std::tuple<float, float, float>& torque);

	/// <summary>
	/// Moves the rigidBody to a point, (only if Kinematic)
	/// </summary>
	/// <param name="dest">The point where the rigidBody will be moved</param>
	/// <returns>The new position of the object and if it's valid</returns>
	bool  moveTo(std::tuple<float, float, float>& dest);

	/// <summary>
	/// Enables or disables the constraint in the rigid body x axis
	/// </summary>
	/// <param name="constrain">True to enable the constraint</param>
	/// <param name="linear">True to constrain the movement, false to constrain the rotation</param>
	bool constrainX(bool constrain, bool linear = true);

	/// <summary>
	/// Enables or disables the constraint in the rigid body y axis
	/// </summary>
	/// <param name="constrain">True to enable the constraint</param>
	/// <param name="linear">True to constrain the movement, false to constrain the rotation</param>
	bool constrainY(bool constrain, bool linear = true);

	/// <summary>
	/// Enables or disables the constraint in the rigid body z axis
	/// </summary>
	/// <param name="constrain">True to enable the constraint</param>
	/// <param name="linear">True to constrain the movement, false to constrain the rotation</param>
	bool constrainZ(bool constrain, bool linear = true);

	/// <summary>
	/// Sets the transform position to a specified one
	/// </summary>
	/// <param name="position">Set of values that determine the position</param>
	bool setPosition(const std::tuple<float, float, float>& position);

	/// <summary>
	/// rotate the object by a vector
	/// </summary>
	/// <param name="position">Set of values that determine the rotation</param>
	bool rotate(const std::tuple<float, float, float>& rotation);

	/// <summary>
	/// Sets the transform rotation to a specified one
	/// </summary>
	/// <param name="angle">angle in degrees to rotate</param>
	/// <param name="axis">axis to rotate</param>
	/// <returns></returns>
	bool setRotation(const std::tuple<float, float, float>& rotation);

	/// <summary>
	/// Sets the rigidbodys scale to a specified one
	/// </summary>
	/// <param name="scale">Set of values that determine the scale</param>
	bool setScale(const std::tuple<float, float, float>& scale);

	/// <summary>
	/// Sets the body static friction if it's a dynamic rigid body
	/// </summary>
	/// <param name="f">The new static friction</param>
	bool setStaticFriction(float f);

	/// <summary>
	/// Sets the body dynamic friction if it's a dynamic rigid body
	/// </summary>
	/// <param name="f">The new dynamic friction</param>
	bool setDynamicFriction(float f);

	/// <summary>
	/// Sets the body bounciness if it's a dynamic rigid body
	/// </summary>
	/// <param name="b">The new bounciness</param>
	bool setBounciness(float b);

	/// <summary>
	/// Sets the body mass if it's a dynamic rigid body (static rigid bodies don't have mass)
	/// </summary>
	/// <param name="m">The new mass</param>
	bool setMass(float m);

	/// <summary>
	/// Sets the body linear velocity if it's a dynamic rigid body (static rigid bodies don't have mass)
	/// </summary>
	/// <param name="vel">The new velocity</param>
	bool setLinearVelocity(const std::tuple<float, float, float>& vel);

	/// <summary>
	/// Sets the body angular velocity if it's a dynamic rigid body (static rigid bodies don't have mass)
	/// </summary>
	/// <param name="vel">The new velocity</param>
	bool setAngularVelocity(const std::tuple<float, float, float>& vel);

	/// <summary>
	/// Enables or disables the gravity
	/// </summary>
	/// <param name="g">true if gravity enabled</param>
	bool setGravity(bool g);

	/// <summary>
	/// Gets the angular velocity of the body
	/// </summary>
	/// <returns>The angular velocity of the body</returns>
	const std::tuple<float, float, float> getAngularVelocity();

	/// <summary>
	/// Gets the linear velocity of the body
	/// </summary>
	/// <returns>The linear velocity of the body</returns>
	const std::tuple<float, float, float> getLinearVelocity();

	/// <summary>
	/// Gets the mass of the body
	/// </summary>
	/// <returns>The mass of the body</returns>
	float getMass();

	/// <summary>
	/// Get the GameObject owner of the component owning thre collider
	/// </summary>
	/// <returns>A pointer to the GameObject owner of the component owning thre collider</returns>
	inline GameObject* getGameObject() const override { return _gameObject; }

	/// <summary>
	/// Returns a pointer to the static function called on collision
	/// </summary>
	/// <returns>A pointer to the static function called on collision</returns>
	inline ContactCallback* getColliderCallback() const override { return _collisionCallback; }

	/// <summary>
	/// Returns rigidbody�s position
	/// </summary>
	/// <returns>Tuple of three floats (x, y, z)</returns>
	const std::tuple<float, float, float> getPosition();

	/// <summary>
	/// Returns rigidbody�s rotation
	/// </summary>
	/// <returns>Tuple of three floats (x, y, z)</returns>
	const std::tuple<float, float, float> getRotation();

	/// <summary>
	/// Returns whether the rigidbody is static or not
	/// </summary>
	/// <returns>true if yes, false either</returns>
	inline bool isStatic() const { return _isStatic; }

private:
	physx::PxQuat toQuaternion(const std::tuple<float, float, float>& rotation);
	physx::PxVec3 ToEulerAngles(physx::PxQuat q);

	/// <summary>
	/// Configures a shape to avoid collision detection and scene queries (raycasts, sweeps and overlays)
	/// </summary>
	/// <param name="shape">The shape to modify</param>
	void setFlags(physx::PxShape* shape);

	/// <summary>
	/// used for physic parameters initialization
	/// </summary>
	/// <param name="x">The x component of the position</param>
	/// <param name="y">The y component of the position</param>
	/// <param name="z">The z component of the position</param>
	/// <param name="mass">The mass of the body</param>
	/// <param name="linearDamping">The linear damping of the body</param>
	/// <param name="angularDamping">The angular damping  of the body</param>
	void initParams(const std::tuple<float, float, float>& pos, float mass, bool isKinematic, float linearDamping, float angularDamping);
	
	/// <summary>
	/// gets all materials from the dynamic rigidBody
	/// </summary>
	/// <returns></returns>
	std::list<physx::PxMaterial*> getAllMaterials();
	
	/// <summary>
	/// gets the greater component of one tuple
	/// </summary>
	/// <param name="tuple">the tuple to get the greater component</param>
	/// <returns></returns>
	float getGreater(std::tuple<float, float, float> tuple);

	physx::PxPhysics* _physx;
	physx::PxScene* _scene;
	physx::PxRigidDynamic* _dynamicBody;
	physx::PxRigidStatic* _staticBody;
	physx::PxShape* _shape;

	GameObject* _gameObject;
	ContactCallback* _collisionCallback;

	bool _isStatic;
};
#endif //!RIGIDBODY_H