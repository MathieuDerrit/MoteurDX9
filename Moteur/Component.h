#pragma once
class GameObject;

class Component {
public:
    Component(GameObject* gameObject);
    virtual ~Component();
    virtual void Update();
protected:
    GameObject* m_gameObject;
};
