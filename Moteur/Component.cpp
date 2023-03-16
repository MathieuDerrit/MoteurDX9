#include "component.h"
#include "gameobject.h"

Component::Component()
{
}

void Component::SetGO(GameObject* gameObject)
{
m_gameObject = gameObject;
}

Component::~Component() 
{
}

void Component::Start()
{

}

void Component::Update() {
    // TODO
}
