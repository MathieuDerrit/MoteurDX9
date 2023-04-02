#include "../Moteur/moteur.h"
#include "Game.h"

GameObject* go;
GameObject* go2;
<<<<<<< HEAD

GameObject* textCanvas;
GameObject* buttonParent;
GameObject* buttonPlay;

Shader* shader;

=======
>>>>>>> fix
Target* target;
Weapon* weapon;
Raycast* shootRay;
Mesh* mesh;
Collider* collider;

int railCount = 30;
int railWidth = 3;
int goOutScreen = 14;
float offset = 0.0f;
float cameraSpeed = 0.1f;
int actualRail = 0;
float t;

vector<GameObject*> targetList;

D3DXVECTOR3 camPosUpdate;

vector<GameObject*> railList;

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
    /*
    int u = 1;*/
    xRotate = 0;
    int direction = -1;
    if (isRightDirection) {
        direction = 1;
    }
    for (int i = 0; i < railCount; i++)
    {
        go = new GameObject();
        go->m_transform.setPosition(D3DXVECTOR3(go->m_transform.m_position.x, go->m_transform.m_position.y, go->m_transform.m_position.z + goOutScreen - railWidth * i + cameraSpeed));
        go->m_transform.setPosition(D3DXVECTOR3(direction * (go->m_transform.m_position.x - (i * xRotate)), go->m_transform.m_position.y, (go->m_transform.m_position.z - railWidth * (railCount - 1)) - (-i * xRotate)));
        go->m_transform.rotate(direction * xRotate, 0.0f, 0.0f);
        xRotate += 0.05f;
        go->AddComponent<Mesh>();
        go->m_tag = "rail";
        mesh = go->GetComponent<Mesh>();
        mesh->Init(Eng->d3ddev, Custom, "rail.x");
        railList.push_back(go);
        Eng->gameobjectlist.push_back(go);
        if (xRotate >= 15.0f)
            break;
    }
}

void Update() {
<<<<<<< HEAD

=======
    D3DXVECTOR3 vOrigin;
    D3DXVECTOR3 vDirection = Eng->camera->m_transform.m_dir;

    D3DXVECTOR3 posWeapon = Eng->camera->m_transform.m_position;
    posWeapon.x += 3;
    posWeapon.z -= 4;
    posWeapon.y += 2;
    weapon->m_transform.setPosition(posWeapon);
>>>>>>> fix
    D3DXVECTOR3 pos = target->m_transform.m_position;
    int j = 10;
    for (auto go : Eng->gameobjectlist) {
        if (go->m_tag == "weapon") {
            vOrigin = go->m_transform.m_position;
            shootRay->Init(vOrigin, vDirection, 150.0f);
        }
        if (go->m_tag == "target") {
            j += 2;
            float y = go->m_transform.m_position.y;
            D3DXVECTOR3 pos = Eng->gameobjectlist[j]->m_transform.m_position;
   
            if (j%6 == 0) {
                pos.x += 4;
            }
            else {
                pos.x -= 4;
            }
            pos.y = y;

            if (goTop) {
                pos.y += 0.05f;

                if (go->m_transform.m_position.y >= 3.0f) {
                    goTop = false;
                }

            }
            else {
                pos.y -= 0.05f;
                if (go->m_transform.m_position.y <= -3.0f) {
                    goTop = true;
                }
            }


            go->m_transform.setPosition(pos);


        }
    }
    
    //AABB* box1 = go->GetComponent<AABB>();
    //AABB* box2 = go2->GetComponent<AABB>();

<<<<<<< HEAD
    //if (AABB::Get()->AABBvsAABB(go->GetComponent<AABB>(), go2->GetComponent<AABB>())) {
    //    
    //    OutputDebugStringA("explosion");
    //}
    //else
    //{
    //    OutputDebugStringA("MEURS");
    //}



    //Button
    if (buttonParent->GetComponent<Button>()->ClickAction("Quit")) {}
    if (buttonPlay->GetComponent<Button>()->ClickAction("Play")) {
        buttonParent->GetComponent<Button>()->drawBox = false;
=======
    offset += cameraSpeed;//* time.deladime;

    t = offset / railWidth;
    if (t < 0.0f)
        t = 0.0f;
    if (t > 1.0f)
        t = 1.0f;
    

    D3DXVec3Lerp(&camPosUpdate, &railList[actualRail]->m_transform.m_position, &railList[actualRail+1]->m_transform.m_position, t);
    camPosUpdate += railList[actualRail]->m_transform.m_up * -4.0f;
    Eng->camera->m_transform.setPosition(camPosUpdate);

    if (t >= 1) {
        actualRail++;
        offset = 0;

        railList[actualRail - 1]->m_transform.m_position = railList.back()->m_transform.m_position + (railList.back()->m_transform.m_dir * -3);
        railList[actualRail - 1]->m_transform.setPosition(railList[actualRail - 1]->m_transform.m_position);
        railList.push_back(railList[actualRail - 1]);
        railList.erase(railList.begin() + (actualRail - 1));
        actualRail--;
>>>>>>> fix
    }

    target->m_transform.setPosition(pos);

<<<<<<< HEAD
    for (auto go : Eng->gameobjectlist)
    {

        if (go->m_tag != "weapon") {
            go->m_transform.setPosition(D3DXVECTOR3(go->m_transform.m_position.x, go->m_transform.m_position.y, go->m_transform.m_position.z + cameraSpeed));
            if (go->m_transform.m_position.z > goOutScreen + railWidth && go->m_tag == "rail") {
                go->m_transform.setPosition(D3DXVECTOR3(go->m_transform.m_position.x, go->m_transform.m_position.y, go->m_transform.m_position.z - railWidth * (railCount - 1)));
                go->m_transform.rotate(0.0f, 0.0f, 0.0f);
                go->m_transform.rotate(i, 0.0f, 0.0f);
                i += 0.05f;
            }
        }
    }
}


#ifdef _DEBUG
#include <crtdbg.h>
#endif

int APIENTRY WinMain(_In_ HINSTANCE hInstance, _In_opt_ HINSTANCE hPrevInstance, _In_ LPSTR lpCmdLine, _In_ int nCmdShow)
{
#ifdef _DEBUG
    _CrtMemState memStateInit;
    _CrtMemCheckpoint(&memStateInit);
#endif

=======

    if (Eng->input.IsPressed(LMB)) {
        for (auto go : Eng->gameobjectlist) {
            if (go->m_tag == "target") {
                BOOL isCollide = false;
                shootRay->CreateRaycast(go->GetComponent<Mesh>()->getMesh(), vOrigin, vDirection, &isCollide);
                if (isCollide) {
                    //Destroy target and add points
                    //
                    //
                }
            }
        }
    }

}

int WINAPI WinMain(HINSTANCE hInstance,
    HINSTANCE hPrevInstance,
    LPSTR lpCmdLine,
    int nCmdShow)
{
>>>>>>> fix
    Eng = new Engine();
    Eng->Init(hInstance,
        hPrevInstance,
        lpCmdLine,
        nCmdShow);
<<<<<<< HEAD


    go = new GameObject();
    auto pos = D3DXVECTOR3(2.0f, 2.0f, 0.0f);
    go->m_transform.setPosition(pos);
    go->m_transform.setScale(D3DXVECTOR3(1, 1, 1));
    go->AddComponent<AABB>();
    go->AddComponent<Mesh>();
    go->AddComponent<Collider>();
    Mesh* mesh = go->GetComponent<Mesh>();
    AABB* co = go->GetComponent<AABB>();
    co->GetPosition(pos);
    pos = go->GetComponent<Collider>()->m_pos;
    mesh->Init(Eng->d3ddev, Box);
    Eng->gameobjectlist.push_back(go);

    go2 = new GameObject();
    auto pos2 = D3DXVECTOR3(2.0f, 1.0f, 0.0f);
    go2->m_transform.setPosition(pos2);
    go2->m_transform.setScale(D3DXVECTOR3(1, 1, 1));
    go2->AddComponent<AABB>();
    go2->AddComponent<Mesh>();
    go2->AddComponent<Collider>();
    Mesh* mesh2 = go2->GetComponent<Mesh>();
    AABB* co2 = go2->GetComponent<AABB>();
    co2->GetPosition(pos2);
    pos2 = go2->GetComponent<Collider>()->m_pos;
    mesh2->Init(Eng->d3ddev, Box);
    Eng->gameobjectlist.push_back(go2);
=======
>>>>>>> fix

    textCanvas = new GameObject();
    auto text = textCanvas->AddComponent<FieldText>();
    text->Init(Eng->d3ddev);
    text->text = "RailFPS";
    text->fontHeight = 100;
    text->textColor = D3DCOLOR_ARGB(120, 120, 255, 60);
    text->size = D3DXVECTOR2(300, 100);
    text->Draw();
    Eng->gameobjectlist.push_back(textCanvas);

<<<<<<< HEAD
    buttonParent = new GameObject();
    auto buttonTest = buttonParent->AddComponent<Button>();
    buttonTest->Init(Eng->d3ddev);
    buttonTest->message = "QUIT";
    //buttonTest->buttonFormat = DT_RIGHT;
    buttonTest->Draw();
    Eng->gameobjectlist.push_back(buttonParent);  
    
    buttonPlay = new GameObject();
    auto Play = buttonPlay->AddComponent<Button>();
    Play->Init(Eng->d3ddev);
    Play->message = "PLAY";
    //Play->buttonFormat = DT_BOTTOM;
    Play->position = D3DXVECTOR2(200, 50);
    Play->Draw();
    Eng->gameobjectlist.push_back(buttonPlay);

    
    for (int i = 0; i < railCount; i++)
    {
        go = new GameObject();
        go->m_transform.setPosition(D3DXVECTOR3(go->m_transform.m_position.x, go->m_transform.m_position.y, go->m_transform.m_position.x + goOutScreen - railWidth * i));
        go->AddComponent<Mesh>();
        go->m_tag = "rail";
        if (i % 2 == 0) {
            go->AddComponent<Shader>();
            go->GetComponent<Shader>()->Init(Eng->d3ddev, LPSTR("Color.hlsl"));
        }
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
=======
    for (int i = 0; i < railCount; i++)
    {
        go = new GameObject();
        go->m_transform.setPosition(D3DXVECTOR3(go->m_transform.m_position.x, go->m_transform.m_position.y, go->m_transform.m_position.z + goOutScreen - railWidth * i));
        go->AddComponent<Mesh>();
        go->m_tag = "rail";
        mesh = go->GetComponent<Mesh>();
        mesh->Init(Eng->d3ddev, Custom, "rail.x");
        railList.push_back(go);
        Eng->gameobjectlist.push_back(go);
    }
    //railsTurn(false);

    Eng->camera->m_transform = railList[actualRail]->m_transform;
    Eng->camera->m_transform.setPosition(Eng->camera->m_transform.m_position);
    Eng->camera->m_transform.rotate(D3DX_PI, 0.0f, D3DX_PI);


    for (int i = 0; i < 6; i++) {
        target = new Target();
        target->Init(Eng->d3ddev, Balloon);
        target->m_transform.setPosition(D3DXVECTOR3(-5.0f, 0.0f, -10.0f));
        target->m_transform.setScale(D3DXVECTOR3(1.0f, 1.0f, 1.0f));
        target->m_transform.rotate(0.0f, 0.0f, 66.0f);
        target->m_tag = "target";

        Eng->gameobjectlist.push_back(target);
    }
>>>>>>> fix

    weapon = new Weapon();
    weapon->Init(Eng->d3ddev, Pistol);
    weapon->m_transform.setPosition(D3DXVECTOR3(0.0f, 0.0f, 0.0f));
    weapon->m_transform.setScale(D3DXVECTOR3(10.0f, 10.0f, 10.0f));
    weapon->m_transform.rotate(66.0f, 0.0f, 66.0f);
    weapon->m_tag = "weapon";
<<<<<<< HEAD


    Eng->gameobjectlist.push_back(weapon);

=======
    Eng->gameobjectlist.push_back(weapon);

    shootRay = new Raycast();
    Eng->raycastlist.push_back(shootRay);

>>>>>>> fix

    railsTurn(true);

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
    delete go;
    delete go2;
    delete Eng;
    delete target;
    delete weapon;


    #ifdef _DEBUG
        _CrtMemState memStateEnd, memStateDiff;
        _CrtMemCheckpoint(&memStateEnd);
        if (_CrtMemDifference(&memStateDiff, &memStateInit, &memStateEnd))
        {
            MessageBoxA(NULL, "MEMORY LEAKS", "DISCLAIMER", 0);
        }
    #endif 
    return msg.wParam;
<<<<<<< HEAD
}
=======
}
>>>>>>> fix
