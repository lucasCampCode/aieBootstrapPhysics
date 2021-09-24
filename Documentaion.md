Lucas Campbell |
:------ |
year 2 - Game programmer |
s208055 |

# Documentation
## PhysicsScene.h
### Functions
1. Public
   - void addActor(PhysicsObject* actor)
     - adds an object/ actor to the scene 
   - void removeActor(PhysicsObject* actor)
     - removes an object/actor from the scene
   - void checkCollisions()
      - checks the collisions of all objects in the scene
   - void SetGravity(const glm::vec2 gravity)
     - sets Scenes gravity
   - glm::vec2 getGravity()
     - gets the gravity direction from the scene
   - void setTimeStep(const float timeStep) 
     - sets how many time the scenes physics get updated
   - float getTimeStep()
     - gets what the time step is in the scene
   - static bool planeToPlane(PhysicsObject* obj1, PhysicsObject* obj2)
     - the collision check for a plane to plane
   - static bool planeToSphere(PhysicsObject* obj1, PhysicsObject* obj2)
     - the collision check for a plane to Sphere
   - static bool planeToBox(PhysicsObject* obj1, PhysicsObject* obj2)
     - the collision check for a plane to box(not implemented)
   - static bool sphereToPlane(PhysicsObject* obj1, PhysicsObject* obj2)
     - the collision check between a sphere to plane(inversed of planeToSphere)
   - static bool sphereToSphere(PhysicsObject* obj1, PhysicsObject* obj2)
     - the collision check between a sphere to sphere
   - static bool sphereToBox(PhysicsObject* obj1, PhysicsObject* obj2)
     - the collision check between a sphere to box(not implemented)
   - static bool boxToPlane(PhysicsObject* obj1, PhysicsObject* obj2)
     - the collision check between a box to plane(not implemented)
   - static bool boxToSphere(PhysicsObject* obj1, PhysicsObject* obj2)
     - the collision check between a box to sphere(not implemented)
   - static bool boxToBox(PhysicsObject* obj1, PhysicsObject* obj2)
     - the collision between a box to box(not implemented)
### Variables
1. Private
   - glm::vec2 m_gravity
     - the gravity of the scene
   - float m_timeStep
      - the time step of the scene
   - std::set<PhysicsObject*> m_actors
      - list of objects/actors in the scene

## PhysicsGame.h
- came with bootstrap setup

## PhysicsObject.h
- enum ShapeType
  - contains each shape type used for objects

### Funcions
1. Protected
   - PhysicsObject(ShapeType shapeID)
     - constructor for physics objects
2. Public 
   - virtual void fixedUpdate(glm::vec2 gravity, float timeStep) = 0
     - abstract update for all objects
   - virtual void draw() = 0
     - abstract draw for all objects
   - virtual void resetPosition()
     - reset the position of the object
   - ShapeType getShapeID()
     - get the shapetype of this object
### Variables
1. private
   - ShapeType m_shapeID
     - is the shape of this object
## RigidBody.h
### Functions
1. Public
   - RigidBody(ShapeType shapeID, glm::vec2 position, glm::vec2 velocity, float orientaion, float mass)
     - contructor for a rigidBody
   - ~RigidBody()
     - decontructor for a rigidbody
   - void applyForce(glm::vec2 force)
     - adds a force to the object 
   - void applyForceToOther(RigidBody* other, glm::vec2 force)
     - add a force a object and the inverse to this object
   - void resolveCollision(RigidBody* other)
     - what happens when an plane RigidBody when an other object collides with it
   - void setPosition(glm::vec2 position)
     - set the Position of the object
   - glm::vec2 getPosition()
     - returns the position of the object
   - float getOrientation()
     - returns the orientation of the object
   - void SetVelocity(glm::vec2 velocity)
     - sets the object velocity
   - glm::vec2 getVelocity()
     - returns the objects velocity
   - float getMass()
     - returns the mass of the object

### Variables
1. Private
   - glm::vec2 m_position
     - the position of the object
   - glm::vec2 m_velocity
     - the velocity of the object
   - float m_mass
     - the mass of the object(used mainly in aplling forces)
   - float m_orientation 
     - the oriantation of the object
## Sphere.h
### Functions
1. Public
   - Sphere(glm::vec2 position, glm::vec2 velocity, float mass, float radius, glm::vec4 color)
     - contructor for aSphere
   - ~Sphere()
     - deconstructor for a sphere
   - float getRadius()
     - get the radius of this sphere
   - glm::vec4 getColor()
     - get the color of this sphere

### Variables
1. Private
   - float m_radius
     - the radius of this sphere
   - glm::vec4 m_Color
     - the color of this sphere
## Plane.h
### Functions
1. Public
   - Plane(glm::vec2 normal, float distance,glm::vec4 color)
     - constructor for a plane
   - ~Plane()
     - deconstructor for a plane
   - virtual void fixedUpdate(glm::vec2 gravity, float deltaTime)
     - override so plane can update itself
   - virtual void draw()
     - override of physicsObject draw so it can draw itself
   - void resolveCollision(RigidBody* other)
     - what happens when an plane acts when an other object collides with it
   - glm::vec2 getNormal()
     - returns the normal of the plane
   - float getDistance()
     - returns the distance from origin for the plane
   - glm::vec4 getColor()
     - returns the color of the plane

### Variables
1. Private
   - glm::vec2 m_normal
     - the direction the plane is facing
   - float m_distance
     -  the distance the plane is form origin
   - glm::vec4 m_color
     - the color of the plane