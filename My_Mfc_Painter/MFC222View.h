
// MFC222View.h: CMFC222View 类的接口
//

#pragma once
#include"CLayer.h"

class CMFC222View : public CView
{

protected: // 仅从序列化创建
	CArray<CLayer*> m_ls;
	vector<HINSTANCE> modules;
	vector<string> name_list;
	size_t total_shapes = 0;
	size_t flowing_shapes = 1;
	CMFC222View();// noexcept;
	DECLARE_DYNCREATE(CMFC222View)
	UINT m_nIndex;
	void SelectLayer(UINT nFlags, CPoint point);
	void SelectEnd(UINT nFlags, CPoint point);

// 特性
public:
	CMFC222Doc* GetDocument() const;

// 操作
public:

// 重写
public:
	virtual void OnDraw(CDC* pDC);  // 重写以绘制该视图
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
protected:
	virtual BOOL OnPreparePrinting(CPrintInfo* pInfo);
	virtual void OnBeginPrinting(CDC* pDC, CPrintInfo* pInfo);
	virtual void OnEndPrinting(CDC* pDC, CPrintInfo* pInfo);

// 实现
public:
	virtual ~CMFC222View();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// 生成的消息映射函数
protected:
	DECLARE_MESSAGE_MAP()

public:
	afx_msg void OnLButtonDown(UINT nFlags, CPoint point);
	afx_msg void OnLButtonUp(UINT nFlags, CPoint point);
	afx_msg void OnMouseMove(UINT nFlags, CPoint point);
	afx_msg void OnDrawArrow();
	afx_msg void OnUpdateDrawArrow(CCmdUI* pCmdUI);
	afx_msg void OnGetPlugins();
	afx_msg void OnUpdateGetPlugins(CCmdUI* pCmdUI);
	void getplugins();
	CLayer* getobject(size_t n);
	afx_msg void OnNext();
	afx_msg void OnUpdateNext(CCmdUI* pCmdUI);
	afx_msg void OnDrawing1();
	afx_msg void OnUpdateDrawing1(CCmdUI* pCmdUI);
};

#ifndef _DEBUG  // MFC222View.cpp 中的调试版本
inline CMFC222Doc* CMFC222View::GetDocument() const
   { return reinterpret_cast<CMFC222Doc*>(m_pDocument); }
#endif

