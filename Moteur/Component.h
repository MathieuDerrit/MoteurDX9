#pragma once // Pour �viter des inclusions multiples du fichier
#include "GameObject.h"

class Component {
public:
    Component(GameObject* GameObject);
    virtual ~Component();
    virtual void Update();
protected:
    GameObject* m_gameObject;
};

