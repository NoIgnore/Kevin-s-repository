#include "pch.h"
#include "CEllipse.h"

void CEllipse::OnDraw(CDC* pDC)
{
	pDC->Ellipse(m_rect);
}

void CEllipse::OnLButtonUp(UINT nFlags, CPoint point)
{
	m_rect.BottomRight() = point;
	m_rect.NormalizeRect();
}

void CEllipse::OnLButtonDown(UINT nFlags, CPoint point)
{
	m_rect.TopLeft() = point;
}

void CEllipse::OnMouseMove(UINT nFlags, CPoint point, CDC* pDC)
{
	if (nFlags & MK_LBUTTON)
	{
		HBRUSH hbr = (HBRUSH)GetStockObject(NULL_BRUSH);
		pDC->SelectObject(hbr);
		pDC->SetROP2(R2_NOT);

		if (m_rect.right != MAXLONG)
		{
			pDC->Rectangle(m_rect);
		}
		m_rect.BottomRight() = point;
		pDC->Rectangle(m_rect);
	}
}

CEllipse::CEllipse():m_rect(MAXLONG, MAXLONG, MAXLONG, MAXLONG)
{
}

CEllipse::~CEllipse()
{
}
