#pragma once


#pragma comment (lib, "d3d9.lib")
#pragma comment (lib, "d3dx9.lib")

using namespace std;
class GameObject;
class Transform;

#include <memory>
#include <list>
#include <vector>
#include <string>

#include <windows.h>
#include <windowsx.h>
#include <d3d9.h>
#include <d3dx9.h>

#include "Transform.h"
#include "Component.h"
#include "GameObject.h"
#include "Mesh.h"

