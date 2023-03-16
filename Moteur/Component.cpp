#include "component.h"
#include "gameobject.h"

Component::Component(GameObject* gameObject)
    : m_gameObject(gameObject) {
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
