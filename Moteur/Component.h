#pragma once

class GameObject;

class Component {
public:
    Component();
    //Component(GameObject* gameObject);
    virtual ~Component();
    void SetGO(GameObject* gameObject);
    virtual void Start();
    virtual void Update();
    GameObject* m_gameObject;
};

