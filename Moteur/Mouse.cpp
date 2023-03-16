//#include "Mouse.h"
//
//std::pair<int, int> Mouse::GetPos() const noexcept
//{
//	return{ x,y };
//}
//
//int Mouse::GetPosX() const noexcept
//{
//	return x;
//}
//
//int Mouse::GetPosY() const noexcept
//{
//	return y;
//}
//
//bool Mouse::IsInWindow() const noexcept
//{
//	return isInWindow;
//}
//bool Mouse::LeftIsPressed() const noexcept
//{
//	return leftIsPressed;
//}
//
//bool Mouse::RightIsPressed() const noexcept
//{
//	return rightIsPressed;
//}
//
//void Mouse::OnMouseLeave() noexcept
//{
//	isInWindow = false;
//	buffer.push(Mouse::Event(Mouse::Event::Type::Leave, *this));
//	TrimBuffer();
//}
//
//void Mouse::OnLeftPressed(int x, int y) noexcept
//{
//	isInWindow = false;
//	buffer.push(Mouse::Event(Mouse::Event::Type::Leave, *this));
//	TrimBuffer();
//}
//
//void Mouse::TrimBuffer() noexcept
//{
//	while (buffer.size() > bufferSize)
//	{
//		buffer.pop();
//	}
//}
//
//void Mouse::OnWheelDelta(int x, int y, int delta) noexcept
//{
//	wheelDeltaCarry += delta;
//
//	while (wheelDeltaCarry >= WHEEL_DELTA)
//	{
//		wheelDeltaCarry -= WHEEL_DELTA;
//		OnWheelUp(x, y);
//	}
//	while (wheelDeltaCarry <= WHEEL_DELTA)
//	{
//		wheelDeltaCarry += WHEEL_DELTA;
//		OnWheelUp(x, y);
//	}
//
//}
