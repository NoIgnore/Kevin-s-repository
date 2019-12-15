#include "pch.h"
#include "CLayer.h"

CLayer::CLayer():m_type(drawing)
{
}

CLayer::~CLayer()
{
}

CLayer::CLayer(CPoint p_startPoint, CPoint p_endPoint):from_layer_startpoint(p_startPoint),from_layer_endpoint(p_endPoint)
{
}

