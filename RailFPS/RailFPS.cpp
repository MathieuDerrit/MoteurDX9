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
    D3DXVECTOR3 posWeapon = Eng->camera->m_transform.m_position;
    posWeapon.x += 3;
    posWeapon.z -= 4;
    posWeapon.y += 2;
    weapon->m_transform.setPosition(posWeapon);
    D3DXVECTOR3 pos = target->m_transform.m_position;
    int j = 10;
    for (auto go : Eng->gameobjectlist) {
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
    }

    target->m_transform.setPosition(pos);

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

    weapon = new Weapon();
    weapon->Init(Eng->d3ddev, Pistol);
    weapon->m_transform.setPosition(D3DXVECTOR3(0.0f, 0.0f, 0.0f));
    weapon->m_transform.setScale(D3DXVECTOR3(10.0f, 10.0f, 10.0f));
    weapon->m_transform.rotate(66.0f, 0.0f, 66.0f);
    weapon->m_tag = "weapon";


    Eng->gameobjectlist.push_back(weapon);


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

    return msg.wParam;
}