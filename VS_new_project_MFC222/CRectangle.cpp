#include "pch.h"
#include "CRectangle.h"

void CRectangle::OnLButtonDown(UINT nFlags, CPoint point)
{
	m_rect.TopLeft() = point;
}

void CRectangle::OnLButtonUp(UINT nFlags, CPoint point)
{
	m_rect.BottomRight() = point;
	m_rect.NormalizeRect();
}

void CRectangle::OnMouseMove(UINT nFlags, CPoint point, CDC* pDC)
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

void CRectangle::OnDraw(CDC* pDC)
{
	pDC->Rectangle(m_rect);
}

CRectangle::CRectangle():m_rect(MAXLONG, MAXLONG, MAXLONG, MAXLONG)
{
}

CRectangle::~CRectangle()
{
}
