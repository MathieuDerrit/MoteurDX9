#include "component.h"
#include "gameobject.h"

Component::Component(GameObject* gameObject)
    : m_gameObject(gameObject) {
}

Component::~Component() 
{
}

void Component::Update() {
    // TODO
}
