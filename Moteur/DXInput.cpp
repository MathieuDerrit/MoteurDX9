#include "DXInput.h"

DXInput::DXInput()
{
	this->isActive = 0;
}

bool DXInput::Initialize()
{
	for (int i = 0; i < 256; i++)
	{
		this->m_keys[i] = false;
	}

	return true;
}

bool DXInput::Cleanup()
{
	return true;
}

void DXInput::keyDown(unsigned int key)
{
	this->m_keys[key] = true;
}

void DXInput::keyUp(unsigned int key)
{
	this->m_keys[key] = false;
}

bool DXInput::isKeyDown(unsigned int key)
{
	return this->m_keys[key];
}
