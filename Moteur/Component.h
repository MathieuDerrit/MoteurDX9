#pragma once // Pour éviter des inclusions multiples du fichier
#include "GameObject.h"

class Component {
public:
    Component(GameObject* GameObject);
    virtual ~Component();
    virtual void Update();
protected:
    GameObject* m_gameObject;
};

