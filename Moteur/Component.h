#pragma once // Pour éviter des inclusions multiples du fichier
#include "Gameobject.h"

class Component {
public:
    Component(GameObject* gameObject);
    virtual ~Component();
    virtual void Update();
protected:
    GameObject* m_gameObject;
};

