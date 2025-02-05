#include "CPlayer.h"

CPlayer::CPlayer() : m_x(0), m_y(0), m_health(100) {}

void CPlayer::MoveUp() { m_y--; }
void CPlayer::MoveDown() { m_y++; }
void CPlayer::MoveLeft() { m_x--; }
void CPlayer::MoveRight() { m_x++; }

void CPlayer::Render() const
{
    // 예시로 콘솔에 위치와 체력 출력
    std::cout << "Player Position: (" << m_x << ", " << m_y << ")\n";
    std::cout << "Health: " << m_health << std::endl;
}
