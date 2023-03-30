#pragma once

#ifdef APSTUDIO_INVOKED
#ifndef APSTUDIO_READONLY_SYMBOLS
#define _APS_NEXT_RESOURCE_VALUE        101
#define _APS_NEXT_COMMAND_VALUE         40001
#define _APS_NEXT_CONTROL_VALUE         1001
#define _APS_NEXT_SYMED_VALUE           101
#endif
#endif


#include <windows.h>
#include <windowsx.h>
#include <d3d9.h>
#include <d3dx9.h>
#include <memory>
#include <queue>
#include <list>
#include <vector>
#include <string>
#include <tchar.h>
#include <sstream>
#include <cstring>

#include <DirectXMath.h>
#include <DxErr.h>


#pragma comment (lib, "d3d9.lib")
#pragma comment (lib, "d3dx9.lib")
#pragma comment (lib, "winmm.lib")
#pragma comment(lib, "dmoguids.lib")
#pragma comment(lib, "dxerr.lib")

#define SCREEN_WIDTH 1200
#define SCREEN_HEIGHT 900

#define CUSTOMFVF (D3DFVF_XYZ | D3DFVF_NORMAL)
#define TEXTUREFVF (D3DFVF_XYZ | D3DFVF_DIFFUSE | D3DFVF_TEX1)

#define HR(x)										\
{													\
	HRESULT hr = x;									\
/*	if (FAILED(hr))									\
	{												\
		DXTraceA(__FILE__, __LINE__, hr, #x, FALSE);\
	}	*/											\
}

struct CUSTOMVERTEX { FLOAT X, Y, Z; D3DVECTOR NORMAL; };


using namespace std;

class Component;
class Transform;
class StringConverter;
class MouseEvent;
class MouseClass;
class Mesh;
class Collider;
class BoxCollider;
class KeyboardEvent;
class KeyboardClass;
class GameObject;
class ErrorLogger;
class Engine;
class DXTexture;
class DXModels;
class DXManager;
class DXLights;
class DXInput;
class DXGraphics;
class DXEngine;
class DXCamera;
class AABB;
class Camera;
class Input;
class STimer;
class Shader;


#include "Component.h"
#include "Transform.h"
#include "StringConverter.h"
#include "Mesh.h"
#include "Collider.h"
#include "Fieldtext.h"
#include "Mouse/MouseEvent.h"
#include "Mouse/MouseClass.h"
#include "Keyboard/KeyboardEvent.h"
#include "Keyboard/KeyboardClass.h"
#include "GameObject.h"
#include "ErrorLogger.h"
#include "Engine.h"
#include "Camera.h"
#include "Input.h"
#include "STimer.h"
#include "Shader.h"



