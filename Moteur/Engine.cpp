#include "moteur.h"
Input input;

Time* time;

LRESULT CALLBACK WindowProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam)
{
	switch (message)
	{
	case WM_DESTROY:
	{
		PostQuitMessage(0);
		return 0;
	} break;
	}

	return DefWindowProc(hWnd, message, wParam, lParam);
}


void Engine::Init(HINSTANCE hInstance,
	HINSTANCE hPrevInstance,
	LPSTR lpCmdLine,
	int nCmdShow)
{

	HWND hWnd;
	WNDCLASSEX wc;

	ZeroMemory(&wc, sizeof(WNDCLASSEX));

	wc.cbSize = sizeof(WNDCLASSEX);
	wc.style = CS_HREDRAW | CS_VREDRAW;
	wc.lpfnWndProc = WindowProc;
	wc.hInstance = hInstance;
	wc.hCursor = LoadCursor(NULL, IDC_ARROW);
	wc.lpszClassName = L"WindowClass";

	RegisterClassEx(&wc);

	hWnd = CreateWindowEx(NULL, L"WindowClass", L"Our Direct3D Program",
		WS_OVERLAPPEDWINDOW, 0, 0, SCREEN_WIDTH, SCREEN_HEIGHT,
		NULL, NULL, hInstance, NULL);

	initD3D(&hWnd);
	initInput();
	time->InitSystemTime();
	/*
	cam.m_transform.setPosition(D3DXVECTOR3(0, -5, 0));
	cam.m_transform.rotate(-90.0f, 0.0f, 0.0f);
	input.cam = &cam;
	*/
	camera = new Camera();
	camera->m_transform.setPosition(D3DXVECTOR3(0.0f, 2.0f, 0.0f));
	camera->SetProjectionValues(D3DXToRadian(60),
		(FLOAT)SCREEN_WIDTH / (FLOAT)SCREEN_HEIGHT,
		1.0f,
		1000.0f);
	camera->m_transform.rotate(0.0f, 0.0f, 0.0f);

	input.cam = camera;

	D3DXCreateBox(d3ddev, 1.0f, 1.0f, 1.0f, &mm, 0);


	ShowWindow(hWnd, nCmdShow);

}


void Engine::initD3D(HWND* hWnd)
{
	d3d = Direct3DCreate9(D3D_SDK_VERSION);

	D3DPRESENT_PARAMETERS d3dpp;

	ZeroMemory(&d3dpp, sizeof(d3dpp));
	d3dpp.Windowed = TRUE;
	d3dpp.SwapEffect = D3DSWAPEFFECT_DISCARD;
	d3dpp.hDeviceWindow = *hWnd;
	d3dpp.BackBufferFormat = D3DFMT_X8R8G8B8;
	d3dpp.BackBufferWidth = SCREEN_WIDTH;
	d3dpp.BackBufferHeight = SCREEN_HEIGHT;
	d3dpp.EnableAutoDepthStencil = TRUE;
	d3dpp.AutoDepthStencilFormat = D3DFMT_D16;

	d3d->CreateDevice(D3DADAPTER_DEFAULT,
		D3DDEVTYPE_HAL,
		*hWnd,
		D3DCREATE_HARDWARE_VERTEXPROCESSING | D3DCREATE_PUREDEVICE,
		&d3dpp,
		&d3ddev);

	init_light();

	d3ddev->SetRenderState(D3DRS_LIGHTING, TRUE);
	d3ddev->SetRenderState(D3DRS_ZENABLE, TRUE);
	d3ddev->SetRenderState(D3DRS_AMBIENT, D3DCOLOR_XRGB(50, 50, 50));
}

void Engine::initInput(){
	keyboard.EnableAutoRepeatChars();
}


void Engine::init_light(void)
{
	D3DLIGHT9 light;
	D3DMATERIAL9 material;

	ZeroMemory(&light, sizeof(light));
	light.Type = D3DLIGHT_DIRECTIONAL;
	light.Diffuse = D3DXCOLOR(5,5, 5, 5);
	light.Direction = D3DXVECTOR3(-1.0f, -0.3f, -1.0f);

	d3ddev->SetLight(0, &light);
	d3ddev->LightEnable(0, TRUE);

	ZeroMemory(&material, sizeof(D3DMATERIAL9));
	material.Diffuse = D3DXCOLOR(5.0f, 5.0f, 5.0f, 5.0f);
	material.Ambient = D3DXCOLOR(5.0f, 5.0f, 5.0f, 5.0f);

	d3ddev->SetMaterial(&material);
}

int a = 0;
void Engine::Update()
{
	time->UpdateTime();
	a += 50;
	//cam->m_transform.setPosition(D3DXVECTOR3(a, a, 0.0f));

	//OutputDebugStringA(std::to_string(time->deltaTime).append("\n").c_str());
	input.ReadInputs();

	//camera->m_transform.rotate(0.01, 0.0f, 0.0f);
	camera->UpdateViewMatrix();
	render_frame();

	if (gameobjectlist.size() > 0)
	{
		for (auto go : gameobjectlist)
		{
			if (go->GetComponent<Mesh>())
			{
				go->GetComponent<Mesh>()->Update();
			}
		}
	}
	
}
float test = 0.0f;
void Engine::render_frame(void)
{
	d3ddev->Clear(0, NULL, D3DCLEAR_TARGET, D3DCOLOR_XRGB(200, 200, 200), 1.0f, 0);
	d3ddev->Clear(0, NULL, D3DCLEAR_ZBUFFER, D3DCOLOR_XRGB(0, 0, 0), 1.0f, 0);

	d3ddev->BeginScene();
	test++;
	//camera->m_transform.setPosition(D3DXVECTOR3(0.0f, 0.0f, test));
	d3ddev->SetFVF(CUSTOMFVF);

	D3DXMATRIX matProj = camera->GetProjectionMatrix();
	D3DXMATRIX matView = camera->GetViewMatrix();

	//D3DXMATRIX matView;
	D3DXVECTOR3 forward = D3DXVECTOR3(0.0f, 0.0f, 1.0f);
	D3DXVECTOR3 up = D3DXVECTOR3(0.0f, 1.0f, 0.0f);
	//D3DXMatrixLookAtLH(&matView, &camera->m_transform.m_position, &forward, &up);

	d3ddev->SetTransform(D3DTS_VIEW, &matView);
	d3ddev->SetTransform(D3DTS_PROJECTION, &matProj);

	//DRAW gameobjet


	d3ddev->SetStreamSource(0, v_buffer, 0, sizeof(CUSTOMVERTEX));
	d3ddev->SetIndices(i_buffer);

	d3ddev->DrawIndexedPrimitive(D3DPT_TRIANGLELIST, 0, 0, 24, 0, 12);

	if (gameobjectlist.size() > 0)
	{
		for (auto go : gameobjectlist)
		{

			// Cr�ez une instance de l'interface ID3DXLine
			ID3DXLine* pLine;
			D3DXCreateLine(d3ddev, &pLine);

			// Calculez la direction du rayon en soustrayant la position de la souris de la position de la cam�ra
			D3DXVECTOR3 vOrigin = camera->m_transform.m_position;

			D3DXVECTOR3 vDirection2 = camera->m_transform.m_dir;

			// Cr�ez un tableau de deux points qui repr�sentent l'origine et l'extr�mit� du rayon
			D3DXVECTOR3 points[2] = { vOrigin, vOrigin + (vDirection2 * 15) };

			// D�finissez la couleur de la ligne en utilisant un vecteur de couleur RGBA
			D3DCOLOR color = D3DCOLOR_RGBA(255, 0, 0, 255); // Jaune

			//D3DXMATRIX matProj = camera->GetProjectionMatrix();
			//D3DXMATRIX matView = camera->GetViewMatrix();

			D3DXMATRIX tempFinal = camera->m_transform.m_matrix * matProj;

			// Appelez la fonction DrawLine pour dessiner la ligne de rayon
			pLine->SetWidth(10.0f); // D�finissez la largeur de la ligne
			pLine->Begin();
			pLine->DrawTransform(points, 2, &tempFinal, color);
			pLine->End();

			// Ne pas oublier de lib�rer l'interface ID3DXLine lorsque vous n'en avez plus besoin
			pLine->Release();




			if (go->GetComponent<Mesh>()) 
			{
				go->GetComponent<Mesh>()->Update();
				go->GetComponent<Mesh>()->draw(d3ddev);

				if (go->m_tag == "weapon") {

					D3DXVECTOR3 vDirection = camera->m_transform.m_dir;

					// R�cup�ration des coordonn�es de d�but et de fin de la ligne
					D3DXVECTOR3 vStart = camera->m_transform.m_position;
					//D3DXVECTOR3 vStart = go->m_transform.m_position;
					//vStart.z -= 4.0f;

					D3DXVECTOR3 ah = D3DXVECTOR3(0.0f, 0.0f, 1.0f);
					//D3DXVec3Normalize(&vDirection, &vDirection);

					// Test d'intersection entre la ligne et le mesh
					DWORD dwFaceIndex;
					float fU, fV, fDistance;

					// Boucle sur tous les meshes de la sc�ne pour tester l'intersection
					BOOL isCollide = false;
					
					Mesh* testMesh = new Mesh();
					testMesh->Init(d3ddev, Box);
					testMesh->meshTransform.setPosition(D3DXVECTOR3(0.0f, 2.0f, 2.0f));
					testMesh->meshTransform.setScale(D3DXVECTOR3(1.0f, 1.0f, 1.0f));
					testMesh->draw(d3ddev);

					D3DXVECTOR3 meshWorld = testMesh->meshTransform.m_position;
					
					/*
					vStart -= meshWorld;
					meshWorld = testMesh->meshTransform.m_scale;
					vStart.x = 1.0f / meshWorld.x;
					vStart.y = 1.0f / meshWorld.y;
					vStart.z = 1.0f / meshWorld.z;


*/

					//D3DXMATRIX matRotateY;
		
					//d3ddev->SetTransform(D3DTS_WORLD, &matRotateY);
					//mm->DrawSubset(0);



					D3DXIntersect(testMesh->m_mesh, &vStart, &camera->m_transform.m_dir, &isCollide, NULL, NULL, NULL, NULL, NULL, NULL);

					// OutputDebugStringA(std::to_string(vDirection.x).c_str());

					if (isCollide) {
						OutputDebugStringA("CCCCCOOOOLLLLIIIIDDDDEEEEE");
					}


					for (auto go2 : gameobjectlist) {
						LPD3DXMESH pMesh = go2->GetComponent<Mesh>()->m_mesh;

						BOOL test = false;

						// Test d'intersection entre la ligne et le mesh

						//IF A SUPPR
						if (go->m_tag == "target") {

							//D3DXVECTOR3 meshWorld = go2->GetComponent<Mesh>()->meshTransform.m_position;
							//vStart -= meshWorld;
							//meshWorld = go2->GetComponent<Mesh>()->meshTransform.m_scale;
							//vStart.x = 1.0f / meshWorld.x;
							//vStart.y = 1.0f / meshWorld.y;
							//vStart.z = 1.0f / meshWorld.z;

							if (SUCCEEDED(D3DXIntersect(pMesh, &vStart, &vDirection, &test, &dwFaceIndex, &fU, &fV, &fDistance, NULL, NULL))) {




								if (test) {
									OutputDebugStringA("TOUCHER :::");
									OutputDebugStringA((go2->m_tag).c_str());

									// Cr�ez une instance de l'interface ID3DXLine
									ID3DXLine* pLine;
									D3DXCreateLine(d3ddev, &pLine);

									// Calculez la direction du rayon en soustrayant la position de la souris de la position de la cam�ra
									D3DXVECTOR3 vOrigin = vStart;


									// Cr�ez un tableau de deux points qui repr�sentent l'origine et l'extr�mit� du rayon
									D3DXVECTOR3 points[2] = { vOrigin, vOrigin + (vDirection * 100000) };

									// D�finissez la couleur de la ligne en utilisant un vecteur de couleur RGBA
									D3DCOLOR color = D3DCOLOR_RGBA(255, 255, 0, 255); // Jaune

									//D3DXMATRIX matProj = camera->GetProjectionMatrix();
									//D3DXMATRIX matView = camera->GetViewMatrix();

									D3DXMATRIX tempFinal = camera->m_transform.m_matrix * matProj;

									// Appelez la fonction DrawLine pour dessiner la ligne de rayon
									pLine->SetWidth(10.0f); // D�finissez la largeur de la ligne
									pLine->Begin();
									pLine->DrawTransform(points, 2, &tempFinal, color);
									pLine->End();

									// Ne pas oublier de lib�rer l'interface ID3DXLine lorsque vous n'en avez plus besoin
									pLine->Release();

								}
								else if (go2->m_tag == "target") {
									//OutputDebugStringA("NON :::");

								}
							}



						}
					}


				}
			}
		}
	}


	d3ddev->EndScene();

	d3ddev->Present(NULL, NULL, NULL, NULL);
}


void Engine::cleanD3D(void)
{
	if (v_buffer)
		v_buffer->Release();
	if (i_buffer)
		i_buffer->Release();
	if (d3ddev)
		d3ddev->Release();
	if (d3d)
		d3d->Release();
}