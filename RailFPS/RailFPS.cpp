#include "../Moteur/moteur.h"
#include "Game.h"

GameObject* go;
GameObject* go2;
Target* target;
Weapon* weapon;
Mesh* mesh;
Collider* collider;

int railCount = 30;
int railWidth = 3;
int goOutScreen = 14;
float cameraSpeed = 0.1f;

boolean goTop = true;

Engine* Eng;
float xRotate = 0.0f;

void railsForward() {

   /* for (auto go : Eng->gameobjectlist)
    {
        if (go->m_tag != "weapon") {
            go->m_transform.setPosition(D3DXVECTOR3(go->m_transform.m_position.x, go->m_transform.m_position.y, go->m_transform.m_position.z + cameraSpeed));
            if (go->m_transform.m_position.z > goOutScreen + railWidth && go->m_tag == "rail") {
                go->m_transform.setPosition(D3DXVECTOR3(go->m_transform.m_position.x, go->m_transform.m_position.y, go->m_transform.m_position.z - railWidth * (railCount - 1)));
                go->m_transform.rotate(0.0f, 0.0f, 0.0f);
                go->m_transform.rotate(0.0f, 0.0f, 0.0f);
            }
        }
    }*/
}

void railsTurn(bool isRightDirection) {
    int u = 0;
    int direction = -1;
    if (isRightDirection) {
        direction = 1;
    }
    /*for (auto go : Eng->gameobjectlist)
    {
        u++;
        if (go->m_tag != "weapon") {
            go->m_transform.setPosition(D3DXVECTOR3(go->m_transform.m_position.x, go->m_transform.m_position.y, go->m_transform.m_position.z + cameraSpeed));
            if (go->m_transform.m_position.z > goOutScreen + railWidth && go->m_tag == "rail") {
                go->m_transform.setPosition(D3DXVECTOR3(direction * (go->m_transform.m_position.x - (u * xRotate)), go->m_transform.m_position.y, (go->m_transform.m_position.z - railWidth * (railCount - 1)) - (-u * xRotate)));
                go->m_transform.rotate(0.0f, 0.0f, 0.0f);
                go->m_transform.rotate(direction * xRotate, 0.0f, 0.0f);
                xRotate += 0.05f;
            }
        }
    }*/
    if (xRotate >= 15.0f)
        xRotate = 0.0f;
}

void Update() {

    //weapon->m_transform.setPosition(Eng->cam->m_transform->m_position);
    //weapon->m_transform.rotate(.01f, 0.0f, 0.0f);
    D3DXVECTOR3 pos = target->m_transform.m_position;

    if (goTop) {
        pos.y += 0.05f;

        if (target->m_transform.m_position.y >= 3.0f) {
            goTop = false;
        }

    }
    else {
        pos.y -= 0.05f;
        if (target->m_transform.m_position.y <= -3.0f) {
            goTop = true;
        }
    }


    target->m_transform.setPosition(pos);

    //railsForward();
    railsTurn(true);



    // Cr�ez une instance de l'interface ID3DXLine
    ID3DXLine* pLine;
    D3DXCreateLine(Eng->d3ddev, &pLine);

    // Calculez la direction du rayon en soustrayant la position de la souris de la position de la cam�ra
    D3DXVECTOR3 vOrigin = D3DXVECTOR3(0.0f, 0.0f, 0.0f);
    D3DXVECTOR3 vDirection = D3DXVECTOR3(.0f, .0f, -5.0f);

    // Cr�ez un tableau de deux points qui repr�sentent l'origine et l'extr�mit� du rayon
    D3DXVECTOR3 points[2] = { vOrigin, vOrigin + (vDirection * 1500) };

    // D�finissez la couleur de la ligne en utilisant un vecteur de couleur RGBA
    D3DCOLOR color = D3DCOLOR_RGBA(255, 255, 0, 255); // Jaune

    Camera camera;
    camera.SetProjectionValues(
        D3DXToRadian(45),
        (FLOAT)SCREEN_WIDTH / (FLOAT)SCREEN_HEIGHT,
        1.0f,
        100.0f);
    camera.UpdateViewMatrix();
    XMMATRIX view = camera.GetViewMatrix();


    XMMATRIX proj = camera.GetProjectionMatrix();
    D3DXMATRIX matView = *reinterpret_cast<D3DXMATRIX*>(&view);
    D3DXMATRIX matProj = *reinterpret_cast<D3DXMATRIX*>(&proj);

    D3DXMATRIX tempFinal = matView * matProj;

    // Appelez la fonction DrawLine pour dessiner la ligne de rayon
    pLine->SetWidth(15.0f); // D�finissez la largeur de la ligne
    pLine->Begin();
    pLine->DrawTransform(points, 2, &tempFinal, color);
    pLine->End();

    // Ne pas oublier de lib�rer l'interface ID3DXLine lorsque vous n'en avez plus besoin
    pLine->Release();

}

int WINAPI WinMain(HINSTANCE hInstance,
    HINSTANCE hPrevInstance,
    LPSTR lpCmdLine,
    int nCmdShow)
{
    Eng = new Engine();
    Eng->Init(hInstance,
        hPrevInstance,
        lpCmdLine,
        nCmdShow);
    /*
    go = new GameObject();
    go->m_transform.setPosition(D3DXVECTOR3(6.0f, 2.0f, 4.0f));
    go->m_transform.setScale(D3DXVECTOR3(10, 5, 2));
    go->AddComponent<Mesh>();
    Mesh* mesh = go->GetComponent<Mesh>();
    mesh->Init(Eng->d3ddev, Box);
    */
    for (int i = 0; i < railCount; i++)
    {
        go = new GameObject();
        go->m_transform.setPosition(D3DXVECTOR3(go->m_transform.m_position.x, go->m_transform.m_position.y, go->m_transform.m_position.x + goOutScreen - railWidth * i));
        go->AddComponent<Mesh>();
        go->m_tag = "rail";
        mesh = go->GetComponent<Mesh>();
        mesh->Init(Eng->d3ddev, Custom, "rail.x");
        Eng->gameobjectlist.push_back(go);
    }

    target = new Target();
    target->Init(Eng->d3ddev, Balloon);
    target->m_transform.setPosition(D3DXVECTOR3(5.0f, 0.0f, 0.0f));
    target->m_transform.setScale(D3DXVECTOR3(1.0f, 1.0f, 1.0f));
    target->m_transform.rotate(0.0f, 0.0f, 0.0f);

    Eng->gameobjectlist.push_back(target);

    weapon = new Weapon();
    weapon->Init(Eng->d3ddev, Pistol);
    weapon->m_transform.setPosition(D3DXVECTOR3(10.0f, 0.0f, 0.0f));
    weapon->m_transform.setPosition(D3DXVECTOR3(-5.0f, 0.0f, 15.0f));
    weapon->m_transform.setScale(D3DXVECTOR3(10.0f, 10.0f, 10.0f));
    weapon->m_transform.rotate(0.0f, 0.0f, 0.0f);
    weapon->m_transform.rotate(66.0f, 0.0f, 0.0f);
    weapon->m_tag = "weapon";


    //target->Draw(Eng->d3ddev);
    Eng->gameobjectlist.push_back(weapon);

    //for (int i = 0; i < 50; i++)
    //target->Draw(Eng->d3ddev);
    //Eng->gameobjectlist.push_back(target);


    MSG msg;

    while (TRUE)
    {
        while (PeekMessage(&msg, NULL, 0, 0, PM_REMOVE))
        {
            TranslateMessage(&msg);
            DispatchMessage(&msg);
        }

        if (msg.message == WM_QUIT)
            break;
        Eng->Update();
        Update();
    }




    Eng->cleanD3D();

    return msg.wParam;
}