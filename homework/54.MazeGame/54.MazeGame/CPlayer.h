#pragma once
#include "GameInfo.h"

class CPlayer
{
private:
    int m_x; // �÷��̾��� X ��ǥ
    int m_y; // �÷��̾��� Y ��ǥ
    int m_health; // �÷��̾��� ü�� (���÷� �߰�)

public:
    CPlayer(); // ������

    // �÷��̾��� ��ġ �̵�
    void MoveUp();
    void MoveDown();
    void MoveLeft();
    void MoveRight();

    // �÷��̾��� ���� ��� (��: ü��)
    void Render() const;

   
};
