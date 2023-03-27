#pragma once

class GameObject
{
public:
    GameObject();

    ~GameObject();

    //Faire des component à ajouter (ex: mesh renderer, collider, etc...)
    template<typename T>
    T* AddComponent();
    template<typename T>
    T* GetComponent();
    template<typename T>
    list<T*>& GetComponents();

    Transform m_transform;
    
    

    vector<Component*> m_components;
};

template<typename T>
T* GameObject::AddComponent()
{
    T* c = new T;
    c->SetGO(this);
    m_components.push_back(c);
    return c;
}

template<typename T>
T* GameObject::GetComponent()
{
    for (int i = 0; i < m_components.size(); i++)
    {
        if (dynamic_cast<T*>(m_components[i]) != nullptr)
        {
            return dynamic_cast<T*>(m_components[i]);
        }
    }
}

template <typename T>
list<T*>& GameObject::GetComponents()
{
    std::list<T*> components;
    for (int i = 0; i < m_components.size(); i++)
    {
        if (dynamic_cast<T*>(m_components[i]) != nullptr)
        {
            components.pushBack(dynamic_cast<T*>(m_components[i]));
        }
    }
    return components;
}
