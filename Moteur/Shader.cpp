#include "moteur.h"

Shader::Shader(){}

Shader::~Shader(){}

void Shader::Init(LPDIRECT3DDEVICE9 device, LPSTR path)
{
	HRESULT hr = D3DXCreateEffectFromFileA(
		device, // Pointeur vers l'interface du p�riph�rique Direct3D
		path, // Nom du fichier HLSL
		NULL, // Tableau des macros de pr�processeur (optionnel)
		NULL, // Interface de rappel pour les messages (optionnel)
		D3DXSHADER_PACKMATRIX_COLUMNMAJOR | D3DXSHADER_DEBUG, // Options de compilation
		NULL, // Interface de gestion de compilation (optionnel)
		&shaderEffect, // Pointeur vers l'effet cr��
		NULL // Pointeur vers le buffer d'erreur (optionnel)
	);
}


void Shader::CreateShader(LPDIRECT3DDEVICE9 device)
{
	UINT passCount;	
	shaderEffect->Begin(&passCount, NULL);

	for (int ipass = 0; ipass < passCount; ipass++)
	{
		shaderEffect->BeginPass(ipass); // S�lectionner la premi�re passe de la technique
		shaderEffect->CommitChanges();
		m_gameObject->GetComponent<Mesh>()->draw(device);
		shaderEffect->EndPass();
	}
	shaderEffect->End();
}

