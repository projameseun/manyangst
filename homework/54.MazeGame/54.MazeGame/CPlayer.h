#pragma once
#include "GameInfo.h"

class CPlayer
{
private:
    int m_x; // 플레이어의 X 좌표
    int m_y; // 플레이어의 Y 좌표
    int m_health; // 플레이어의 체력 (예시로 추가)

public:
    CPlayer(); // 생성자

    // 플레이어의 위치 이동
    void MoveUp();
    void MoveDown();
    void MoveLeft();
    void MoveRight();

    // 플레이어의 상태 출력 (예: 체력)
    void Render() const;

   
};
